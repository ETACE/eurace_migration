    #include "../header.h"
    #include "../Firm_agent_header.h"
    #include "../my_library_header.h"
    

/*
 * \fn Iirm_receive_account_interest()
 * \brief Read account_interest message from Bank. Daily, at start of iteration.
 */
int Firm_receive_account_interest()
{
    double interest =0;
    double interest_rate =0;
    
    /*For validation check*/
    if(DAY%MONTH == 1)
    {
	RECEIVED_INTEREST_IN_CALENDAR_MONTH=0;
    }
        
    //Read message from bank, set risk-free rate.
    START_ACCOUNT_INTEREST_MESSAGE_LOOP
	if(account_interest_message->bank_id == BANK_ID)
	    interest_rate = account_interest_message->interest_rate;
    FINISH_ACCOUNT_INTEREST_MESSAGE_LOOP
    
    /*Add daily interest on deposits: (1/240) of the interest rate*/
    interest = (1/240.0)*interest_rate*PAYMENT_ACCOUNT;
    PAYMENT_ACCOUNT += interest;  
    
    /*For validation check*/
    RECEIVED_INTEREST_DAILY = interest;
    RECEIVED_INTEREST_IN_CALENDAR_MONTH += interest;
    FIRM_INFLOWS_CALENDAR.deposit_interest += interest; 

    return 0;	
}

int Firm_ask_loan()
{
	int connected=0;
	int j=0;

    if (EXTERNAL_FINANCIAL_NEEDS>0.0)
    {
         
         //Delete the old set of lenders
         while(SET_OF_LENDERS.size>0)
         {
           remove_potential_lender(&SET_OF_LENDERS,SET_OF_LENDERS.size-1);         
         }
    
         NUMBER_OF_BANKS_ASKED=0;
         
        //Search for active banks' name
         START_BANK_IDENTITY_MESSAGE_LOOP
         
                 add_potential_lender(&SET_OF_LENDERS,bank_identity_message->bank_id,0);
                 NUMBER_OF_BANKS_ASKED++;
         
         FINISH_BANK_IDENTITY_MESSAGE_LOOP
    
        #ifdef _DEBUG_MODE
            if (PRINT_DEBUG_CREDIT)
            {
                printf("\n\n Firm_ask_loan ID: %d",ID);
                printf("\n\t Found NUMBER_OF_BANKS: %d, SET_OF_LENDERS.size=%d",NUMBER_OF_BANKS_ASKED, SET_OF_LENDERS.size);
            }
        #endif       
         
          
         connected=0; 
        
        
        //Create bank network for this firm
          while(connected<NUMBER_OF_BANKS_TO_APPLY)
          {
                j= rand() % NUMBER_OF_BANKS_ASKED ;// choose banks
                add_loan_request_message(ID, SET_OF_LENDERS.array[j].bank_name, EQUITY, TOTAL_DEBT, (EXTERNAL_FINANCIAL_NEEDS+1e-04));
                SET_OF_LENDERS.array[j].contacted=1;
                connected++;
          }
          
			//delete from the list not contacted banks
			for(j=SET_OF_LENDERS.size-1;j>=0;j--)
			{
				if (SET_OF_LENDERS.array[j].contacted==0)
				{
					remove_potential_lender(&SET_OF_LENDERS,j);    
				}     
			}
	}
                
        //NUMBER_OF_BANKS_ASKED=SET_OF_LENDERS.size;  //provvisorio

        #ifdef _DEBUG_MODE
            if (PRINT_DEBUG_CREDIT)
            {
                printf("\n\t NUMBER_OF_BANKS_ASKED: %d",NUMBER_OF_BANKS_ASKED);
				printf("\n\t SET_OF_LENDERS: [");
				for(j=0;j<SET_OF_LENDERS.size;j++) printf("%d ",SET_OF_LENDERS.array[j].bank_name);
				printf("]");
                printf("\n\t EQUITY: %f TOTAL_DEBT: %f EXTERNAL_FINANCIAL_NEEDS: %f",EQUITY,TOTAL_DEBT,EXTERNAL_FINANCIAL_NEEDS);
                
            }
        #endif       

        return 0;
    }
    
    
    int Firm_get_loan()
    {
        //#ifdef _DEBUG_MODE
        FILE * file1=NULL;
        char * filename="";
        //  #endif
        int n, n1, k, i, primo;
        n=0; n1=0; k=0; i=0; primo=0;
    
        int rate_order_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array: name of banks
        double interest_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array
        double credit_offer_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array
        double value_at_risk_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array
        
        
        double aux=0.0;
        double credit_demand=0.0;
        double credit_accepted=0.0;
        double total_credit_taken=0.0;
    
        int bank_id=0;
        double loan_value=0.0;
        double interest_rate=0.0;
        double interest_amount=0.0;
        double installment_amount=0.0;
        double var_per_installment=0.0;
        double residual_var=0.0;
        double bad_debt=0.0;
        int nr_periods_before_repayment=0;
        
         
        for (i=0; i<NUMBER_OF_BANKS_ASKED;i++)
        {
            rate_order_array[i]=-1;   //vettore lunghezza number_of_banks
            interest_array[i]=0.0;
            credit_offer_array[i]=0.0; //constant size static array
            value_at_risk_array[i]=0.0; 
        } 
    
        //Read messages from banks
        n=0;
    
        START_LOAN_CONDITIONS_MESSAGE_LOOP
          if (loan_conditions_message->firm_id==ID)
          {
                    
            interest_array[n] = loan_conditions_message->proposed_interest_rate;   
            credit_offer_array[n] = loan_conditions_message->amount_offered_credit;
            rate_order_array[n] = loan_conditions_message->bank_id;
            value_at_risk_array[n] = loan_conditions_message->value_at_risk;
        
            n += 1;
        
          }
                 
        FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
        
           
        //Sorting of the rate_order_array
        n1=0;
        
        //SORTING the set of  lenders according to their interest rates
        for(i=0;i<NUMBER_OF_BANKS_ASKED-1;i++)
        {
                for(k=i+1; k<NUMBER_OF_BANKS_ASKED; k++)
                {       
                    if (interest_array[i]>interest_array[k]) 
                    {
                     aux=interest_array[i];
                     interest_array[i]=interest_array[k];
                     interest_array[k]=aux;
                     
                     aux=credit_offer_array[i];
                     credit_offer_array[i]=credit_offer_array[k];
                     credit_offer_array[k]=aux;
                     
                     aux=value_at_risk_array[i];
                     value_at_risk_array[i]=value_at_risk_array[k];
                     value_at_risk_array[k]=aux;
                     
                     n1=rate_order_array[i];
                     rate_order_array[i]=rate_order_array[k];
                     rate_order_array[k]=n1;
                     
                    }
                    
                }
        }
        
        //Travers the banks according to the order in the rate_order_array,
        //obtain a loan if credit_demand >= credit_offer
        
                
        for(primo=0; primo<NUMBER_OF_BANKS_ASKED; primo++)
        {
                  
            if (rate_order_array[primo]!=-1)// && interest_array[primo]!=0.0)
             {
             
                credit_demand = EXTERNAL_FINANCIAL_NEEDS - total_credit_taken;
				
	
                if (credit_demand < 0.0)
                    printf("\n ERROR in function Firm_get_loan, line 132: credit_demand is NEGATIVE.\n ");
        
                if (credit_demand >= credit_offer_array[primo])
                {
                   credit_accepted = credit_offer_array[primo];
                }
                else
                {
                   credit_accepted=credit_demand;
                }
                
                
                total_credit_taken += credit_accepted;                  
                bank_id = rate_order_array[primo];
                loan_value = credit_accepted;
                interest_rate = interest_array[primo];
                installment_amount = credit_accepted/CONST_INSTALLMENT_PERIODS;
                interest_amount=interest_rate*installment_amount;
                    
                if (credit_accepted>0.0)
                {
                     residual_var = value_at_risk_array[primo]*
                        (credit_accepted/credit_offer_array[primo]); //RESIDUAL_VAR[rate_order_array[primo]].value[CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS; //rate_order_array[primo]][CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS;
                }
                else var_per_installment=0.0;
                
                var_per_installment = residual_var/CONST_INSTALLMENT_PERIODS;// value_at_risk_array[rate_order_array[primo]]*(credit_offer_array[rate_order_array[primo]]/credit_accepted);
                bad_debt = 0.0;
                nr_periods_before_repayment=CONST_INSTALLMENT_PERIODS+1;
                
                //ADD LOAN
                if(loan_value < 0.0)
                    printf("\n ERROR in function Firm_get_loan: loan_value is NEGATIVE.\n ");
    
             
             if (credit_accepted>0.0)
             {
                add_debt_item(&LOANS, bank_id, loan_value, interest_rate, installment_amount, var_per_installment, residual_var, bad_debt, nr_periods_before_repayment);         
                add_loan_acceptance_message(bank_id, credit_accepted, residual_var, interest_rate);  
				LAST_INTEREST_RATE_FOR_LOANS=interest_rate;   
             }
                //update the payment_account with the amount of credit obtained
                PAYMENT_ACCOUNT += credit_accepted;
                FIRM_INFLOWS_CALENDAR.new_loans += credit_accepted;


                TOTAL_EXTERNAL_FINANCING_OBTAINED = credit_accepted;

				

		#ifdef _DEBUG_MODE        
		if (PRINT_DEBUG_CREDIT)
		{
		    printf("\n\n Firm_get_loan ID: %d",ID); 
		    printf("\n\t Bank id: %d credit_accepted: %f interest_rate: %f", bank_id, credit_accepted,interest_rate);
		}                  
		#endif

          }
        }

        
        if (PRINT_DEBUG_FILE_EXP1)
            {
                filename = malloc(40*sizeof(char));
                filename[0]=0;
                strcpy(filename, "its/credit_rationing.txt");      
                file1 = fopen(filename,"a");
                fprintf(file1,"\n %d %d %f %f %d",DAY,ID,EXTERNAL_FINANCIAL_NEEDS,total_credit_taken,REGION_ID);
                fclose(file1);
                free(filename);
            }    
        
        
        if (PAYMENT_ACCOUNT >= TOTAL_FINANCIAL_NEEDS)
            {           
                //printf("Firm_financial_needs, External financing: case 1.");
                EXTERNAL_FINANCIAL_NEEDS = 0.0;                   
            }
            else
            {
                //external financing needed
                EXTERNAL_FINANCIAL_NEEDS = TOTAL_FINANCIAL_NEEDS - PAYMENT_ACCOUNT;
            }
        #ifdef _DEBUG_MODE        
        if (PRINT_DEBUG_CREDIT)
        {
            printf("\n\t total_credit_taken: %f", total_credit_taken);
            printf("\n\t PAYMENT_ACCOUNT: %f EXTERNAL_FINANCIAL_NEEDS: %f",PAYMENT_ACCOUNT,EXTERNAL_FINANCIAL_NEEDS);
        }                  
        #endif
        
        return 0;
    }
    
    int Firm_idle()
    {
        return 0;
    }
    
