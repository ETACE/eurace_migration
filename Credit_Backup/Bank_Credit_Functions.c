#include "../header.h"
#include "../Bank_agent_header.h"
#include "../my_library_header.h"


/** \fn Bank_read_policy_rate()
 * \brief Functions to read policy mesg from the ECB with the base rate.
 */
int Bank_read_policy_rate()
{

//4.2.2010: ECB_INTEREST_RATE is a constant
/*
      START_POLICY_RATE_MESSAGE_LOOP
            ECB_INTEREST_RATE = policy_rate_message->policy_rate_value;      
      FINISH_POLICY_RATE_MESSAGE_LOOP
*/      
    //16.9.2010: DEPOSIT_RATE is a markdown on the ECB_INTEREST_RATE (default 10%)
    DEPOSIT_INTEREST_RATE = (1-ECB_INTEREST_RATE_MARKDOWN) * ECB_INTEREST_RATE;

    #ifdef _DEBUG_MODE        
        if (PRINT_DEBUG_CREDIT)
        {
            printf("\n\n Bank_read_policy_rate ID: %d",ID); 
            printf("\n\t policy_rate_value: %f DEPOSITS_RATE: %f",ECB_INTEREST_RATE,DEPOSIT_INTEREST_RATE);
        }              
    #endif
        
     return 0;   
}


/** \fn Bank_communicate_identity()
 * \brief Fucntion to let all agents in the economy know which IDs are banks.
 */
int Bank_communicate_identity()
{
    add_bank_identity_message(ID);

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_CREDIT)
    {
        printf("\n\n Bank_communicate_identity ID: %d",ID);
    }      
    #endif
        
 return 0;   
}


/** \fn Bank_send_dividend_payment()
 * \brief Payment of dividends to the clearinghouse.
 */
int Bank_send_dividend_payment()
{
    /* total dividends are send to clearinghouse, to be distributed to households */
    //add_dividend_per_share_message(ID, DIVIDEND_PER_SHARE);
    add_dividend_info_message(ID, TOTAL_DIVIDEND_PAYMENT);
    
    EQUITY -=  TOTAL_DIVIDEND_PAYMENT;     
    CASH -=  TOTAL_DIVIDEND_PAYMENT;
      
    TOTAL_DIVIDENDS_IN_CALENDAR_MONTH = TOTAL_DIVIDEND_PAYMENT;
    BANK_OUTFLOWS_CALENDAR.dividend_payment += TOTAL_DIVIDEND_PAYMENT;
     

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_CREDIT)
    {
      printf("\n\n Bank_send_dividend_payment ID: %d",ID);
      printf("\n\t DIVIDEND_PER_SHARE %f",DIVIDEND_PER_SHARE);
    }
    #endif

	#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            fprintf(stderr, "\n\n IT %d ID %d Bank_send_dividend_payment: Checking consistency between CASH and balance sheet items", DAY, ID);
			fprintf(stderr, "\n\t Adding: TOTAL_DIVIDEND_PAYMENT=%f",TOTAL_DIVIDEND_PAYMENT);
            fprintf(stderr, "\n\t CASH=%f (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT)=%f Diff=%f", CASH, (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT), (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT) - CASH);
        }
        #endif
    
   return 0;
}


/** \fn Bank_set_quantities_zero()
 * \brief Monthly resetting.
 */
int Bank_set_quantities_zero()
{
    //Monthly resetting
    PROFITS[0]=0;  
    TOTAL_DIVIDEND_PAYMENT=0.0;
    TAXES=0.0;

	//Reset counters in case of inactive bank (equity<0)	
	if (ACTIVE==0)
	{
		SUM_NEW_INTEREST_RATES_IN_CALENDAR_MONTH = 0;
		NO_NEW_LOANS_IN_CALENDAR_MONTH = 0;
	}

    return 0;
}

/*
 * \fn Bank_send_account_interest()
 * \brief Send interest_info message and pay interest on deposits. Daily, at start of iteration.
 */   
int Bank_send_account_interest(void)
{
    double interest=0;
    double int_to_ecb=0.0;
    double int_from_ecb=0.0;
    
    ECB_INTEREST_PAYMENT=0.0;
     
     //Pay interests to ecb on ECB debt of day before
     int_to_ecb  = ECB_DEBT*ECB_INTEREST_RATE/240.0;

    //Receive interest on cash held at ECB
     int_from_ecb  = CASH*ECB_INTEREST_RATE/240.0;


     /*NOTE: The ECB_INTEREST_PAYMENT is the balance of interest paid to ECB on ECB debt
      * and the interest received by the bank from ECB on the deposits the bank has at the ECB.
      * ECB_INTEREST_PAYMENT < 0: the bank receives interest from ECB
      * ECB_INTEREST_PAYMENT > 0: the bank pays interest to ECB
      */
     //Flow accounting
     ECB_INTEREST_PAYMENT = int_to_ecb - int_from_ecb;
     BANK_OUTFLOWS_CALENDAR.ecb_interest_payment += int_to_ecb - int_from_ecb;

    //subtract interest paid to ECB on ECB debt
     PROFITS[0] -= int_to_ecb; 
     CASH 	-= int_to_ecb;
     EQUITY 	-= int_to_ecb;

    //add interest received from ECB on deposits
     PROFITS[0] += int_from_ecb; 
     CASH 	+= int_from_ecb;
     EQUITY 	+= int_from_ecb;

    //send interest to ECB
     add_bank_interest_payment_message(int_to_ecb - int_from_ecb);     

    #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_CREDIT)
        {
            printf("\n\n  IT %d ID: %d Bank_send_account_interest",DAY,ID);
	    printf("\n\t int_to_ecb=%f int_from_ecb=%f Net=%f", int_to_ecb, int_from_ecb, int_to_ecb-int_from_ecb);
        } 
    #endif

    /*Pay deposit interest on household and firm accounts
     * In the bank there is no separation of accounts, so all interest is added to total deposits.*/
    interest = (1/240.0)*DEPOSIT_INTEREST_RATE*DEPOSITS;
     
    //DEPOSITS 	+= interest;
    CASH 	-= interest;
    EQUITY 	-= interest;
    
    //Send interest
    add_account_interest_message(ID, DEPOSIT_INTEREST_RATE);
    
    
    /*For validation check*/
    if(DAY%MONTH == 1)
    {
    	PAID_INTEREST_IN_CALENDAR_MONTH=0;
    }

    /*For validation check*/
    PAID_INTEREST_DAILY = interest;
    PAID_INTEREST_IN_CALENDAR_MONTH += interest;

    BANK_OUTFLOWS_CALENDAR.deposit_interest_payment += interest;

    #ifdef _DEBUG_MODE   
    if (PRINT_DEBUG_CREDIT)
    {
        printf("\n\n Bank_send_account_interest ID: %d",ID);
        printf("\n\t DEPOSITS_RATE %f",DEPOSIT_INTEREST_RATE);
    }
    #endif
    
	#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            fprintf(stderr, "\n\n IT %d ID: %d Bank_send_account_interest: Checking consistency between CASH and balance sheet items", DAY, ID);
			fprintf(stderr, "\n\t Adding: Interest from ECB and interest on deposits=%f", -int_to_ecb + int_from_ecb - interest);
            fprintf(stderr, "\n\t CASH=%f (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT)=%f Diff=%f", CASH, (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT), (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT) - CASH);
        }
        #endif

   return 0;
}

/** \fn Bank_decide_credit_conditions()
 * \brief Function sets credit allowed for a firm.
 */
int Bank_decide_credit_conditions()
{
    double e=0.0;
	double c=0.0;
	double credit_requested=0.0;
	double d=0.0;
	double value_at_risk_request=0.0;
	double interest=0.0;
    double bankruptcy_prob=0.0;
    double multiplicator;
    double credit_allowed=0.0;
	double value_at_risk_of_loan =0.0;
            
	EXCESS_VAR = ALFA*EQUITY - VALUE_AT_RISK;
	EXCESS_LIQUIDITY = CASH - MIN_CASH_RESERVE_RATIO*DEPOSITS;

	#ifdef _DEBUG_MODE
	if (PRINT_DEBUG_CREDIT)
	{
		printf("\n\n Bank_decide_credit_conditions bank_id: %d ",ID);
		printf("\n\t Bank status before loan offer: EXCESS_VAR %f EXCESS_LIQUIDITY %f", EXCESS_VAR,EXCESS_LIQUIDITY);
	}
	#endif
	
	START_LOAN_REQUEST_MESSAGE_LOOP
            e = loan_request_message->equity;
            d = loan_request_message->total_debt;
            c = loan_request_message->external_financial_needs;
            credit_requested = c;

			if (e<0)
				printf("\n Error ! The equity of the firm is negative: %f",e); 

			//set probability of default
			multiplicator = 0.10;
            bankruptcy_prob = 1-exp(-multiplicator*(d+c)/e);



		value_at_risk_request = bankruptcy_prob*credit_requested;
            
           //if ( VALUE_AT_RISK+r <= ALFA*EQUITY )
			if ( value_at_risk_request <= EXCESS_VAR )
            {
				//VaR of requested loan is within available excess VaR of bank
                credit_allowed = credit_requested;
            }
            else 
            {
				//VaR of requested loan exceeds available excess VaR of bank
                credit_allowed = max(0,EXCESS_VAR/bankruptcy_prob);  
            }


		interest = ECB_INTEREST_RATE*(1+ LOAN_INTEREST_MARKUP*bankruptcy_prob);
            
           
            //interest = ECB_INTEREST_RATE + BANK_GAMMA[0]*value_at_risk_request*random_unif_interval(0.0,0.01);

			//Send response to firm with credit conditions
			//constrain credit offer to the excess liquidity still available
			if (EXCESS_LIQUIDITY>credit_allowed)
			{
				//credit_allowed = credit_allowed;
				EXCESS_LIQUIDITY -= credit_allowed;					
			}
			else
			{
				credit_allowed = EXCESS_LIQUIDITY;
				EXCESS_LIQUIDITY =0.0;					
			}

			//Only make loan offers for positive credit request
			if (credit_allowed > 1e-6)
			{
				//actual value_at_risk depends on final credit
				value_at_risk_of_loan = value_at_risk_request*(credit_allowed/credit_requested);

				//reduce excess var with var of actual loan offer				
				EXCESS_VAR -= value_at_risk_of_loan;

				add_loan_conditions_message(loan_request_message->firm_id, ID, interest, credit_allowed,  value_at_risk_of_loan);				
			}

        #ifdef _DEBUG_MODE
            if (PRINT_DEBUG_CREDIT)
            {
				printf("\n\n\t firm_id: %d firm EQUITY=%f TOTAL_DEBT=%f bankruptcy_prob =%f", loan_request_message->firm_id, e, d,bankruptcy_prob);
                printf("\n\t firm_id: %d credit_requested: %f credit_allowed: %f", loan_request_message->firm_id, credit_requested, credit_allowed);
                printf("\n\t ECB_INTEREST_RATE: %f interest: %f VaR: %f",ECB_INTEREST_RATE,interest,value_at_risk_of_loan);
				printf("\n\t Bank status after loan offer: EXCESS_VAR %f EXCESS_LIQUIDITY %f", EXCESS_VAR,EXCESS_LIQUIDITY);
            }  
        #endif              
         
            
	FINISH_LOAN_REQUEST_MESSAGE_LOOP
    
    return 0;
}


/** \fn Bank_give_loan()
 * \brief Function to give a loan.
 */
int Bank_give_loan()
{
    FIRM_LOAN_ISSUES=0.0;

    if(DAY%MONTH == 1)
    {
		SUM_NEW_INTEREST_RATES_IN_CALENDAR_MONTH = 0;
		NO_NEW_LOANS_IN_CALENDAR_MONTH = 0;
	}

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_CREDIT)
    {
        printf("\n\n Bank_give_loan ID: %d",ID); 
        printf("\n\t TOTAL_CREDIT before: %f",TOTAL_CREDIT);
    }        
    #endif
            
    START_LOAN_ACCEPTANCE_MESSAGE_LOOP
        if(loan_acceptance_message->bank_id==ID)
        {
            VALUE_AT_RISK	+= loan_acceptance_message->loan_total_var;
            TOTAL_CREDIT 	+= loan_acceptance_message->credit_amount_taken;
			CASH 		 	-= loan_acceptance_message->credit_amount_taken;
			
            //Flow accounting 
            FIRM_LOAN_ISSUES+=loan_acceptance_message->credit_amount_taken; 
            
            BANK_OUTFLOWS_CALENDAR.firm_loan_issues +=  
            loan_acceptance_message->credit_amount_taken; 

			SUM_NEW_INTEREST_RATES_IN_CALENDAR_MONTH += loan_acceptance_message->interest_rate;
			NO_NEW_LOANS_IN_CALENDAR_MONTH++;

            #ifdef _DEBUG_MODE
			if (PRINT_DEBUG_CREDIT) 
				printf("\n\t credit_amount_taken: %f loan_var: %f",loan_acceptance_message->credit_amount_taken, loan_acceptance_message->loan_total_var);     
            #endif
        }
    FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
    
	
	#ifdef _DEBUG_MODE       
	if (PRINT_DEBUG_CREDIT)
	{
		fprintf(stderr, "\n\n IT %d ID: %d Bank_give_loan: Checking consistency between CASH and balance sheet items", DAY, ID);
		fprintf(stderr, "\n\t Adding: New loans=%f", FIRM_LOAN_ISSUES);
		fprintf(stderr, "\n\t CASH=%f (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT)=%f Diff=%f", CASH, (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT), (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT) - CASH);
	}
	#endif


    #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_CREDIT) 
		printf("\n\t Adding: New loans=%f TOTAL_CREDIT after: %f",FIRM_LOAN_ISSUES, TOTAL_CREDIT);
    #endif
    
    return 0;
}


/** \fn Bank_receive_installment()
 * \brief Read installment msg: debt repayment and interest. Also read bankruptcy msg of firms.
 */
int Bank_receive_installment()
{
	double total_bad_debt=0.0;

    FIRM_LOAN_INSTALLMENTS=0.0;
    FIRM_INTEREST_PAYMENTS=0.0;
    
    /*For validation rules*/
    if(DAY%MONTH == 1)
    {
    	FIRM_LOAN_INSTALLMENTS_IN_CALENDAR_MONTH=0.0;
    	FIRM_INTEREST_PAYMENTS_IN_CALENDAR_MONTH=0.0;
	}

    #ifdef _DEBUG_MODE     
    if (PRINT_DEBUG_CREDIT) 
    {
        printf("\n\n IT %d ID: %d Bank_receive_installment ", DAY,ID);
        printf("\n\t PROFITS: %f TOTAL_CREDIT: %f",PROFITS[0],TOTAL_CREDIT);
    }
    #endif
        
    START_INSTALLMENT_MESSAGE_LOOP
        if(installment_message->bank_id==ID)
        {
            CASH 			+= installment_message->installment_amount;

			CASH 			+= installment_message->interest_amount;
            PROFITS[0] 		+= installment_message->interest_amount;
			EQUITY 			+= installment_message->interest_amount;

            TOTAL_CREDIT  	-= installment_message->installment_amount;
            VALUE_AT_RISK 	-= installment_message->var_per_installment;
    
            #ifdef _DEBUG_MODE        
            if (PRINT_DEBUG_CREDIT)
            {
				printf("\n\t INSTALLMENT_MESSAGE_LOOP");
                printf("\n\t interest_amount: %f installment_amount: %f",installment_message->interest_amount,installment_message->installment_amount);
                printf("\n\t PROFITS: %f TOTAL_CREDIT: %f EQUITY: %f",PROFITS[0],TOTAL_CREDIT,EQUITY);
            }
            #endif

            //Flow accounting
            FIRM_INTEREST_PAYMENTS += installment_message->interest_amount;
            FIRM_LOAN_INSTALLMENTS += installment_message->installment_amount;
            FIRM_LOAN_INSTALLMENTS_IN_CALENDAR_MONTH+=installment_message->installment_amount;
			FIRM_INTEREST_PAYMENTS_IN_CALENDAR_MONTH+=installment_message->interest_amount;
			BANK_INFLOWS_CALENDAR.firm_interest_payments += installment_message->interest_amount;
			BANK_INFLOWS_CALENDAR.firm_loan_installments += installment_message->installment_amount;
        }
    FINISH_INSTALLMENT_MESSAGE_LOOP

    START_BANKRUPTCY_MESSAGE_LOOP
    if(bankruptcy_message->bank_id==ID)
    {
       //CASH +=bankruptcy_message->credit_refunded;
	   total_bad_debt += bankruptcy_message->bad_debt;
       EQUITY -= bankruptcy_message->bad_debt;
       TOTAL_CREDIT -= bankruptcy_message->bad_debt;
       //PROFITS[0] -= bankruptcy_message->bad_debt;
       VALUE_AT_RISK -= bankruptcy_message->writeoff_var;
       
        #ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            printf("\n\t BANKRUPTCY_MESSAGE_LOOP");
            printf("\n\t bad_debt: %f",bankruptcy_message->bad_debt);
            printf("\n\t PROFITS: %f TOTAL_CREDIT: %f EQUITY: %f",PROFITS[0],TOTAL_CREDIT,EQUITY);
        }
        #endif
    }
    FINISH_BANKRUPTCY_MESSAGE_LOOP   

		#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            fprintf(stderr, "\n\n IT %d ID: %d Bank_receive_installment: Checking consistency between CASH and balance sheet items", DAY, ID);
			fprintf(stderr, "\n\t Adding: FIRM_LOAN_INSTALLMENTS=%f FIRM_INTEREST_PAYMENTS=%f total_bad_debt=%f", FIRM_LOAN_INSTALLMENTS, FIRM_INTEREST_PAYMENTS, total_bad_debt);
            fprintf(stderr, "\n\t CASH=%f (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT)=%f Diff=%f", CASH, (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT), (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT) - CASH);
        }
        #endif


      return 0;
}


/** \fn Bank_account_update_deposits()
 * \brief Update the bank accounts of households and firms.
 */
int Bank_account_update_deposits()
{
    double old_deposits = DEPOSITS ;

      DEPOSITS=0; //reset total deposits        
        
      START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP 
      if (bank_account_update_message->bank_id==ID)
      {
         DEPOSITS += bank_account_update_message->payment_account; //new deposits as sum of all payments accounts 
      }
      FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
      
      if(DEPOSITS - old_deposits >= 0)
      {
      		BANK_INFLOWS_CALENDAR.deposit_inflow += (DEPOSITS - old_deposits);
			//Add deposit mutation to cash
			CASH += (DEPOSITS - old_deposits);
      }
      else
      {
      		BANK_OUTFLOWS_CALENDAR.deposit_outflow += -(DEPOSITS - old_deposits);
			//Add deposit mutation to cash
			CASH += (DEPOSITS - old_deposits);
      }
    
    #ifdef _DEBUG_MODE   
    if (PRINT_DEBUG_CREDIT)
    {
        printf("\n\n IT %d ID: %d Bank_account_update_deposits",DAY,ID);
        printf("\n\t ECB_DEBT: %f DEPOSITS: %f EQUITY: %f",ECB_DEBT,DEPOSITS,EQUITY);
        printf("\n\t TOTAL_CREDIT: %f CASH: %f",TOTAL_CREDIT,CASH);
    }
    #endif   

	#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            fprintf(stderr, "\n\n IT %d ID: %d Bank_account_update_deposits: Checking consistency between CASH and balance sheet items", DAY, ID);
			fprintf(stderr, "\n\t Added: Net deposits=%f", DEPOSITS - old_deposits);
            fprintf(stderr, "\n\t CASH=%f (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT)=%f Diff=%f", CASH, (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT), (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT) - CASH);
        }
        #endif

    return 0;
}


/** \fn Bank_accounting()
 * \brief Function to compute the profits, set dividend payments, pay taxes.
 */
int Bank_accounting()
{

    // #ifdef _DEBUG_MODE  
        FILE *file1=NULL;
        char *filename="";
   // #endif
         
     double q, c, growth;  // total_dividends, dividend_per_share
     

     //PROFITS[1]: profits in period t-1
     if (PROFITS[1]>1e-6 || PROFITS[1]<-1e-6 )
     {
        growth = (PROFITS[0]-PROFITS[1])/PROFITS[1];
      } 
     else  
		growth=0;
 
     PROFITS[1]=PROFITS[0]; //update: set profits t-1
     q=BANK_GAMMA[0]; 
     c=BANK_GAMMA[1];
     BANK_GAMMA[1]= q;
     BANK_GAMMA[0]=(q+(BANK_LAMBDA*(q-c)*growth)+(((double)rand()/(double)RAND_MAX)*0.01));
 
     if (BANK_GAMMA[0]<0.02)
     {
         BANK_GAMMA[0]=0.02;
     }

    //Dividend rate
	/*Sander, 4.2.211: changed to normal dividend ratio */
	BANK_DIVIDEND_RATE = CONST_DIVIDEND_EARNINGS_RATIO;
/*
	if (EQUITY<VALUE_AT_RISK/(ALFA/2))
	     BANK_DIVIDEND_RATE = 0.0;
     else
    	 BANK_DIVIDEND_RATE = 1.0;
*/

     // Tax and dividend payment
     if (PROFITS[0]>0)
     {
         TAXES = TAX_RATE_CORPORATE*PROFITS[0];
         PROFITS[0] -= TAXES;
         EQUITY -= TAXES;  
         CASH -= TAXES; 
	 
         add_tax_payment_message(GOV_ID, TAXES);  
         BANK_OUTFLOWS_CALENDAR.tax_payment += TAXES;
	 
		TOTAL_DIVIDEND_PAYMENT = BANK_DIVIDEND_RATE*PROFITS[0];
        DIVIDEND_PER_SHARE = TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING; 
         
		if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/banks_tax_payments.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f",DAY,ID,PROFITS[0],TAX_RATE_CORPORATE,TAXES);
            fclose(file1);
            free(filename);
        }  
         
         //The dividend msg is send in the function Bank_send_dividend_payment (see below), monthly, 1st of month      
         //add_dividend_per_share_message(ID, DIVIDEND_PER_SHARE);                  
     }
      
    #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_CREDIT)
        {
            printf("\n\n IT %d ID: %d Bank_accounting",DAY,ID);
            printf("\n\t CASH: %f ECB_DEBT: %f PROFITS[0]: %f EQUITY: %f",CASH, ECB_DEBT, PROFITS[0],EQUITY);
            printf("\n\n Income statement ID: %d",ID);
	    printf("\n\t FIRM_INTEREST_PAYMENTS=%f PROFITS[0]=%f TAXES=%f BANK_DIVIDEND_RATE=%f REGION_ID=%d",FIRM_INTEREST_PAYMENTS,PROFITS[0],TAXES,BANK_DIVIDEND_RATE,REGION_ID);
        } 
    #endif

    /* Bank equity negative: not possible to increase ECB_DEBT since it will
     * add both assets (CASH) and liability side (ECB_DEBT).
     * Need a way to raise equity.
     */
     if (EQUITY < 0.0) //... and if is negative (if money is not enough), increase ECB debt
     {
			#ifdef _DEBUG_MODE    
			if (PRINT_DEBUG_CREDIT)
			{
				fprintf(stderr, "\n\n In function Bank_accounting: Bank %d has EQUITY<0, but we ignore this for now.\n", ID);
			}
			#endif
	
     }
    
		#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            fprintf(stderr, "\n\n IT %d ID: %d Bank_accounting: Checking consistency between CASH and balance sheet items", DAY, ID);
			fprintf(stderr, "\n\t Minus: TAXES=%f", TAXES);
            fprintf(stderr, "\n\t CASH=%f (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT)=%f Diff=%f", CASH, (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT), (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT) - CASH);
        }
        #endif
    
		#ifdef _DEBUG_MODE                         
		if (PRINT_DEBUG_FILE_EXP1)
		{                       
			filename = malloc(40*sizeof(char));
			filename[0]=0;
			strcpy(filename, "its/banks_monthly_income_statement.txt");      
			file1 = fopen(filename,"a");
			fprintf(file1,"\n %d %d",DAY,ID);
			fprintf(file1,"%f %f %f %f %d",FIRM_INTEREST_PAYMENTS,TAXES,PROFITS[0],BANK_DIVIDEND_RATE,REGION_ID);
			fclose(file1);
			free(filename);
		}                
		#endif

		#ifdef _DEBUG_MODE                         
		if (PRINT_DEBUG_FILE_EXP1)
		{                       
			filename = malloc(40*sizeof(char));
			filename[0]=0;
			strcpy(filename, "its/banks_monthly_balance_sheet.txt");      
			file1 = fopen(filename,"a");
			fprintf(file1,"\n %d %d %f %f %f %f %d",DAY,ID,DEPOSITS,ECB_DEBT,CASH,TOTAL_CREDIT,REGION_ID);
			fclose(file1);
			free(filename);
		}                
		#endif

      return 0;
}

int Bank_idle()
{
    return 0;
}


/** \fn Bank_update_ecb_account()
 * \brief Increase or reduce the bank's ECB debt, add bank_to_central_bank_account_update message for overnight deposits.
 */
int Bank_update_ecb_account()
{   
     //  #ifdef _DEBUG_MODE  
        FILE *file1=NULL;
        char * filename="";
  //  #endif

	double a,b;
	
	#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            fprintf(stderr, "\n\n IT %d ID: %d Bank_ecb_account: Checking consistency between CASH and balance sheet items", DAY, ID);
            fprintf(stderr, "\n\t CASH=%f (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT)=%f Diff=%f", CASH, (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT), (DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT) - CASH);
        }
        #endif


    //Just before ECB debt: Recompute new CASH
    //CASH=DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT;

    // Procedure to add ECB debt daily
	EXCESS_LIQUIDITY = CASH - MIN_CASH_RESERVE_RATIO*DEPOSITS;

	if (EXCESS_LIQUIDITY<0.0)
    {
		#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
            fprintf(stderr, "\n\n IT %d ID: %d Bank_account_update_deposits: Increasing ECB_DEBT", DAY, ID);
			fprintf(stderr, "\n\t Before: CASH=%f ECB_DEBT=%f EXCESS_LIQUIDITY %f", CASH, ECB_DEBT, EXCESS_LIQUIDITY);
        }
        #endif

		//Monetary base is increased  
		ECB_DEBT  	+=  -EXCESS_LIQUIDITY; 
		CASH		+=  -EXCESS_LIQUIDITY; 
        BANK_INFLOWS_CALENDAR.new_ecb_debt += -EXCESS_LIQUIDITY;
        EXCESS_LIQUIDITY=0.0;
    
		#ifdef _DEBUG_MODE       
        if (PRINT_DEBUG_CREDIT)
        {
			fprintf(stderr, "\n\t After: CASH=%f ECB_DEBT=%f EXCESS_LIQUIDITY %f", CASH, ECB_DEBT, EXCESS_LIQUIDITY);
		}
        #endif
    }
	// Procedure to reduce ECB debt
    else if ( (ECB_DEBT>0.0)&& (EXCESS_LIQUIDITY>0.0) ) 
	{
			#ifdef _DEBUG_MODE       
			if (PRINT_DEBUG_CREDIT)
			{
				fprintf(stderr, "\n\n IT %d ID: %d Bank_account_update_deposits: Decreasing ECB_DEBT", DAY, ID);
				fprintf(stderr, "\n\t Before: CASH=%f ECB_DEBT=%f EXCESS_LIQUIDITY %f", CASH, ECB_DEBT, EXCESS_LIQUIDITY);
			}
			#endif

			//Case 1: Sufficient excess liquidity to fully repay ECB debt
			//a: fraction of ECB debt that is repaid
			a=1.0;
			if(EXCESS_LIQUIDITY>=ECB_DEBT)
			{
					CASH 	-= a*ECB_DEBT;
					ECB_DEBT = (1-a)*ECB_DEBT;
					BANK_OUTFLOWS_CALENDAR.debt_installment_to_ecb += a*ECB_DEBT;
					EXCESS_LIQUIDITY = CASH - MIN_CASH_RESERVE_RATIO*DEPOSITS;			
					
					#ifdef _DEBUG_MODE       
					if (PRINT_DEBUG_CREDIT)
					{
						fprintf(stderr, "\n\t (EXCESS_LIQUIDITY>=ECB_DEBT) After: CASH=%f ECB_DEBT=%f EXCESS_LIQUIDITY=%f", CASH,ECB_DEBT,EXCESS_LIQUIDITY);
					}
					#endif
			}

			 //Case 2: Insufficient excess liquidity to fully repay: repay partly, deplete the excess liquidity
			//b: fraction of EXCESS_LIQUIDITY that is used to repay ECB debt, (1-b) remains for giving loans next day.
			b=1.0;
            if(EXCESS_LIQUIDITY<ECB_DEBT)
            {
                CASH 		-= b*EXCESS_LIQUIDITY;
				ECB_DEBT	-= b*EXCESS_LIQUIDITY;
                BANK_OUTFLOWS_CALENDAR.debt_installment_to_ecb += b*EXCESS_LIQUIDITY;
				EXCESS_LIQUIDITY = CASH - MIN_CASH_RESERVE_RATIO*DEPOSITS;
		
				#ifdef _DEBUG_MODE       
				if (PRINT_DEBUG_CREDIT)
				{
					fprintf(stderr, "\n\t (EXCESS_LIQUIDITY<ECB_DEBT) After: CASH=%f ECB_DEBT=%f EXCESS_LIQUIDITY=%f", CASH,ECB_DEBT,EXCESS_LIQUIDITY);
				}
				#endif
            }
	}
    //End of procedure


    //Inform ECB about bank's payment account
    add_bank_to_central_bank_account_update_message(ID, CASH, ECB_DEBT); 
   
    #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_CREDIT)
        {
            printf("\n\n  IT %d ID: %d Bank_update_ecb_account",DAY,ID);
			printf("\n\t Send to ECB: CASH=%f ECB_DEBT=%f", CASH, ECB_DEBT);
			printf("\n\t FIRM_INTEREST_PAYMENTS=%f PROFITS[0]=%f TAXES=%f BANK_DIVIDEND_RATE=%f REGION_ID=%d",FIRM_INTEREST_PAYMENTS,PROFITS[0],TAXES,BANK_DIVIDEND_RATE,REGION_ID);
        } 
    #endif

   
      // #ifdef _DEBUG_MODE                         
    if (PRINT_DEBUG_FILE_EXP1)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/banks_daily_balance_sheet.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f",DAY,ID,FIRM_LOAN_ISSUES,FIRM_LOAN_INSTALLMENTS);
        fprintf(file1," %f %f %f %f %f %d",TOTAL_CREDIT,CASH,DEPOSITS,ECB_DEBT,EQUITY,REGION_ID);
        fclose(file1);
        free(filename);
        
    }    
    
    if (PRINT_DEBUG_FILE_EXP1)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/banks_value_at_risk.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %d",DAY,ID,VALUE_AT_RISK,REGION_ID);
        fclose(file1);
        free(filename);
        
    }                 
   // #endif

    return 0;
}


/** \fn Bank_stocks_and_flows()
 * \brief Updating stocks and flows
 */
int Bank_stocks_and_flows()
{   

   BANK_STOCKS_CALENDAR.deposits=DEPOSITS;
   BANK_STOCKS_CALENDAR.ecb_debt=ECB_DEBT;
   BANK_STOCKS_CALENDAR.equity=EQUITY;
   BANK_STOCKS_CALENDAR.total_liabilities=DEPOSITS + ECB_DEBT+EQUITY;
   BANK_STOCKS_CALENDAR.cash=CASH;
   BANK_STOCKS_CALENDAR.total_credit=TOTAL_CREDIT;
   BANK_STOCKS_CALENDAR.total_assets=CASH + TOTAL_CREDIT;
   
   BANK_STOCKS_CALENDAR.current_shares_outstanding=CURRENT_SHARES_OUTSTANDING;
    
    BANK_STOCKS_CALENDAR.cash_day_20 = CASH;
   

	BANK_OUTFLOWS_CALENDAR.total_expenses =	
	BANK_OUTFLOWS_CALENDAR.firm_loan_issues +
	BANK_OUTFLOWS_CALENDAR.debt_installment_to_ecb+
	BANK_OUTFLOWS_CALENDAR.ecb_interest_payment +
	BANK_OUTFLOWS_CALENDAR.deposit_interest_payment +
	BANK_OUTFLOWS_CALENDAR.dividend_payment +
	BANK_OUTFLOWS_CALENDAR.deposit_outflow +
	BANK_OUTFLOWS_CALENDAR.tax_payment;
	
	BANK_INFLOWS_CALENDAR.total_income=
	BANK_INFLOWS_CALENDAR.firm_loan_installments +
	BANK_INFLOWS_CALENDAR.new_ecb_debt +
	BANK_INFLOWS_CALENDAR.deposit_inflow +
	BANK_INFLOWS_CALENDAR.firm_interest_payments;
	
	BANK_INFLOWS_CALENDAR.net_inflow =
	BANK_INFLOWS_CALENDAR.total_income -
	BANK_OUTFLOWS_CALENDAR.total_expenses;
	
	BANK_INFLOWS_CALENDAR.net_deposit_inflow =
	BANK_INFLOWS_CALENDAR.deposit_inflow -
	BANK_OUTFLOWS_CALENDAR.deposit_outflow;
	
	//Bank leverage ratio
	if (DEPOSITS>0.0)
	    LEVERAGE_RATIO = TOTAL_CREDIT/DEPOSITS;

	//Bank mean interest rate: sum of new interest rates/no of new loans this month:
	if (NO_NEW_LOANS_IN_CALENDAR_MONTH>0.0)
	    MEAN_INTEREST_RATE = 12*SUM_NEW_INTEREST_RATES_IN_CALENDAR_MONTH/NO_NEW_LOANS_IN_CALENDAR_MONTH;
	else MEAN_INTEREST_RATE = 0.0;

	//Bank set active to 0 if equity negative (for now: never resets active=1)
	if (EQUITY<0.0)
		ACTIVE=0;

    return 0;
}
	
