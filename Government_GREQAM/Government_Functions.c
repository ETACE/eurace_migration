//For trunk model
#include <math.h>
#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"
//For Isolated model
//#include <math.h>
//#include "header.h"
//#include "Government_agent_header.h"
//#include "../my_library_header.h"

//#define NO_REGIONS_PER_GOV 2 //number of regions per gov

/************Government Role: Finance********************************/
int Government_idle()
{
    return 0;
}


/* \fn: int Government_initialization()
 * \brief Function to initialize.
 */
int Government_initialization()
{   
    //add only the region_id of the government to its list_of_regions
    reset_int_array(&LIST_OF_REGIONS);
    add_int(&LIST_OF_REGIONS, REGION_ID);

    //Set tax rate to global constant
    TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE;
    TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE;


   // MINIMUM_WAGE_PCT = GOV_MINIMUM_WAGE_PCT;



    GDP_FRACTION_CONSUMPTION = GOV_POLICY_GDP_FRACTION_CONSUMPTION;


    if(GOV_REGIONAL_CONSUMPTION_SCENARIO==1 && REGION_ID ==2){


    	GDP_FRACTION_CONSUMPTION =   GOV_2_CONSUMPTION_RATIO;


    }



 if(EXP_FIRM_SUBSIDY_SCENARIO==1){

			FLAME_environment_variable_policy_exp_best_technology_subsidy = 0;
			FLAME_environment_variable_policy_exp_all_technologies_subsidy = 0;
}else if(EXP_FIRM_SUBSIDY_SCENARIO==2){

			FLAME_environment_variable_policy_exp_best_technology_subsidy = 1;
			FLAME_environment_variable_policy_exp_all_technologies_subsidy = 0;
			FLAME_environment_variable_best_technology_subsidy_pct = 0.1;

}else if(EXP_FIRM_SUBSIDY_SCENARIO==3){

			FLAME_environment_variable_policy_exp_best_technology_subsidy = 0;
			FLAME_environment_variable_policy_exp_all_technologies_subsidy = 1;
			FLAME_environment_variable_best_technology_subsidy_pct = 0.2;

}else if(EXP_FIRM_SUBSIDY_SCENARIO==4){

			FLAME_environment_variable_policy_exp_best_technology_subsidy = 1;
			FLAME_environment_variable_policy_exp_all_technologies_subsidy = 0;
			FLAME_environment_variable_best_technology_subsidy_pct = 0.05;

}else if(EXP_FIRM_SUBSIDY_SCENARIO==5){

			FLAME_environment_variable_policy_exp_best_technology_subsidy = 0;
			FLAME_environment_variable_policy_exp_all_technologies_subsidy = 1;
			FLAME_environment_variable_best_technology_subsidy_pct = 0.05;

}else if(TECH_POLICY_EFFECTIVENESS_SWITCH==1){


	FLAME_environment_variable_policy_exp_best_technology_subsidy = 0;
	FLAME_environment_variable_policy_exp_all_technologies_subsidy = 0;






}



 //Austerity policies





 if(FLEXIBILITY_POLICY && REGION_ID==2){


	 UNEMPLOYMENT_BENEFIT_PCT=0.55;


 }


SUBSIDY_REPORTED_TO_EUROSTAT = 0;

    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG_GOV)
        { 
                    printf("\n Government_initialization ID: %d",ID);
                    getchar();
        }
    #endif
    
    return 0;   
}

/* \fn: int Government_send_policy_announcements()
 * \brief Function to send yearly policy announcement message.
 */
int Government_send_policy_announcements()
{   
    FILE *file1=NULL;
    char *filename=NULL;

int i;
         
    HH_SUBSIDY_PCT=0.0;
    FIRM_SUBSIDY_PCT=0.0;
    //UNEMPLOYMENT_BENEFIT_PCT=GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT;




    /*Set the minimum wage and the basic security benefits as a pct of the current mean wage in the region*/

    MINIMUM_WAGE = MINIMUM_WAGE_PCT * COUNTRY_WIDE_MEAN_WAGE;
    BASIC_SECURITY_BENEFITS = BASIC_SECURITY_BENEFITS_PCT*COUNTRY_WIDE_MEAN_WAGE;



    if(REGION_ID==2){
    if(JOE_SCENARIO != 0 ){

    	/*As soon the debt gdp ratio is above 0.6, the government has to cover all expenditures by taxes */
    	if(DEBT_GDP_RATIO > 0.6){

    		FLAME_environment_variable_gov_2_expenditures_covered = 1.0;

			/*If scenario ==2 then the government receives a transfer from region 1*/
			if(JOE_SCENARIO==2){

				FLAME_environment_variable_subsidy_redistribution = 1;
				FLAME_environment_variable_gov_expenditures_and_unemp_benefits_redistributed = 1;

			}else if(JOE_SCENARIO==3){

				FLAME_environment_variable_subsidy_redistribution = 1;
				FLAME_environment_variable_gov_expenditures_and_unemp_benefits_redistributed = 1;

				GDP_FRACTION_CONSUMPTION = 0.1;

			}else if(JOE_SCENARIO==4){

				FLAME_environment_variable_subsidy_redistribution = 1;
				FLAME_environment_variable_gov_expenditures_and_unemp_benefits_redistributed = 1;

				FLAME_environment_variable_policy_exp_best_technology_subsidy = 1;
				FLAME_environment_variable_policy_exp_all_technologies_subsidy = 0;
				FLAME_environment_variable_best_technology_subsidy_pct = 0.1;

			}else if(JOE_SCENARIO==5){


				FLAME_environment_variable_subsidy_redistribution = 1;
				FLAME_environment_variable_gov_expenditures_and_unemp_benefits_redistributed = 1;

				FLAME_environment_variable_policy_exp_best_technology_subsidy = 0;
				FLAME_environment_variable_policy_exp_all_technologies_subsidy = 1;
				FLAME_environment_variable_best_technology_subsidy_pct = 0.2;

			}

    	}



    }
    }


    AV_CONSUMPTION_BUDGET_PER_CAPITA = 0.0;
    AV_CONSUMPTION_QUOTA_REL_TO_REG1 = 0.0;

    for(int i=0 ; i < CONSUMPTION_BUDGETS_PER_CAPITA.size;i++){



    	AV_CONSUMPTION_BUDGET_PER_CAPITA += CONSUMPTION_BUDGETS_PER_CAPITA.array[i];


    	AV_CONSUMPTION_QUOTA_REL_TO_REG1 += CONSUMPTION_QUOTAS_REL_TO_REG1.array[i];


    }

    if(CONSUMPTION_BUDGETS_PER_CAPITA.size>0){
    	AV_CONSUMPTION_BUDGET_PER_CAPITA = AV_CONSUMPTION_BUDGET_PER_CAPITA/(1.0*CONSUMPTION_BUDGETS_PER_CAPITA.size);
    	AV_CONSUMPTION_QUOTA_REL_TO_REG1 = AV_CONSUMPTION_QUOTA_REL_TO_REG1/(1.0*CONSUMPTION_BUDGETS_PER_CAPITA.size);

    }


    for(int i=0 ; i < CONSUMPTION_BUDGETS_PER_CAPITA.size;i++){
    remove_double(&CONSUMPTION_BUDGETS_PER_CAPITA,i);
    remove_double(&CONSUMPTION_QUOTAS_REL_TO_REG1,i);
    i--;

    }


    if(AUSTERITY_POLICY>0){


    	if(AUSTERITY_POLICY==1){


    		 FLAME_environment_variable_austerity_policy_scenario = 1;
    		 FLAME_environment_variable_austerity_repay_scenario = 2;

    	 }else if(AUSTERITY_POLICY==2){


    		 FLAME_environment_variable_austerity_policy_scenario = 2;
    		 FLAME_environment_variable_austerity_repay_scenario = 2;


    	 }else if(AUSTERITY_POLICY==3){


    		 FLAME_environment_variable_austerity_policy_scenario = 3;
    		 FLAME_environment_variable_austerity_repay_scenario = 2;


    	 }else if(AUSTERITY_POLICY==4){

    		 FLAME_environment_variable_austerity_policy_scenario = 1;
    		FLAME_environment_variable_austerity_repay_scenario = 1;


    	 }else if(AUSTERITY_POLICY==5){

    		 FLAME_environment_variable_austerity_policy_scenario = 2;
    		FLAME_environment_variable_austerity_repay_scenario = 1;


    	 }else if(AUSTERITY_POLICY==6){

    		 FLAME_environment_variable_austerity_policy_scenario = 3;
    		FLAME_environment_variable_austerity_repay_scenario = 1;


    	 }else if(AUSTERITY_POLICY==7){

    		 FLAME_environment_variable_austerity_policy_scenario = 4;
    		FLAME_environment_variable_austerity_repay_scenario = 1;


    	 }




     }



    double prev_hh_sub = HH_TRANSFER_PAYMENT;





    if(AUSTERITY_POLICY > 0 && DAY > TRANSITION_PHASE){


    	HH_TRANSFER_PAYMENT = 0.0;


    	if(REGION_ID == 2){










			//if(AUSTERITY_PHASE == 0 &&  AV_CONSUMPTION_QUOTA_REL_TO_REG1 < AUSTERITY_CONSUMPTION_THRESHOLD){

    		if(AUSTERITY_PHASE == 0 &&  DAY == 25921){

				AUSTERITY_PHASE = 1;

			}


			//if(AUSTERITY_PHASE == 1 &&  DEBT_GDP_RATIO > AUSTERITY_DEBT_THRESHOLD){

    		if(AUSTERITY_PHASE == 1 &&  DAY == 29281){


				AUSTERITY_PHASE = 2;




				// Scenario 1: Government in region 2h as to repay debts alone
				if(AUSTERITY_REPAY_SCENARIO==1){


					// No redistribution of subsidies
					FLAME_environment_variable_subsidy_redistribution = 0;

					FOREIGN_DEBT_INSTALLMENT = FOREIGN_DEBT / (12.0*AUSTERITY_REPAYMENT_PERIOD);


					// communitization of debts
				}else if(AUSTERITY_REPAY_SCENARIO==2){

					// Redistribution of subsidies
					FLAME_environment_variable_subsidy_redistribution = 1;
					FOREIGN_DEBT_INSTALLMENT = FOREIGN_DEBT / (12.0*AUSTERITY_REPAYMENT_PERIOD);



				}

				// Transfers stop
				if(AUSTERITY_POLICY_SCENARIO==1){



				// Transfer paid by both governments
				}else if(AUSTERITY_POLICY_SCENARIO==2){

					// Redistribution of subsidies
						FLAME_environment_variable_subsidy_redistribution = 1;
						HH_TRANSFER_PAYMENT = 0.1 * AV_CONSUMPTION_BUDGET_PER_CAPITA;


				// technology pol
				}else if(AUSTERITY_POLICY_SCENARIO==3){

					// No redistribution of subsidies
					FLAME_environment_variable_subsidy_redistribution = 1;

					FLAME_environment_variable_tech_policy_effectiveness_switch = 1;


				}else if(AUSTERITY_POLICY_SCENARIO==4){

					// No redistribution of subsidies
					FLAME_environment_variable_subsidy_redistribution = 1;

					FLAME_environment_variable_tech_policy_effectiveness_switch = 1;
					HH_TRANSFER_PAYMENT = 0.1 * AV_CONSUMPTION_BUDGET_PER_CAPITA;


				}


			}




    		if(AUSTERITY_PHASE==1 || (AUSTERITY_PHASE >1 && AUSTERITY_POLICY_SCENARIO== 2) || (AUSTERITY_PHASE >1 && AUSTERITY_POLICY_SCENARIO== 4)){


    				HH_TRANSFER_PAYMENT = 0.1 * (AV_CONSUMPTION_BUDGET_PER_CAPITA-prev_hh_sub);


    		}



    	}

    }


    if(FLEXIBILITY_POLICY && REGION_ID==2){


   	 UNEMPLOYMENT_BENEFIT_PCT=0.55;


    }


    if(POLICY_EXP_STABILIZATION_SUBSIDY && DAY >=POLICY_STARTING_AT_ITERATION)
    {
        //Set trigger function:
        if ((SUBSIDY_FLAG==0)&&(GDP_GROWTH<SUBSIDY_TRIGGER_ON))
        {
            SUBSIDY_FLAG=1;
            HH_SUBSIDY_PCT = -5*tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }

        //Release trigger function:
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH>SUBSIDY_TRIGGER_OFF))
        {
            SUBSIDY_FLAG=0;
            HH_SUBSIDY_PCT = 0.0;
        }

        //Subsidy regime
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH<SUBSIDY_TRIGGER_OFF))
        {
            HH_SUBSIDY_PCT = -5*tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }
       
        // #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_FILE_EXP2)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "Government.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"%f\n",HH_SUBSIDY_PCT);
            fclose(file1);
            free(filename);
        }
        // #endif 

        #ifdef _DEBUG_MODE
        if ((PRINT_DEBUG_GOV)&&(SUBSIDY_FLAG==1))
        { 
              printf("\n Stabilization: Government_send_policy_announcements ID: %d",ID);
              printf("\n SUBSIDY_FLAG: %d",SUBSIDY_FLAG);
              printf("\n CONST_INCOME_TAX_RATE: %f", CONST_INCOME_TAX_RATE);
              printf("\n GDP_GROWTH: %f", GDP_GROWTH);
              printf("\n fabs(GDP_GROWTH): %f", fabs(GDP_GROWTH));
              printf("\n SUBSIDY_TRIGGER_ON %f", SUBSIDY_TRIGGER_ON);
              printf("\n SUBSIDY_TRIGGER_OFF: %f", SUBSIDY_TRIGGER_OFF);
              printf("\n tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF): %f", tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF));
              printf("\n HH_SUBSIDY_PCT: %f*%f= %f", -tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF), fabs(GDP_GROWTH), HH_SUBSIDY_PCT);
              printf("\n \t TAX_RATE_HH_LABOUR: %f TAX_RATE_CORPORATE: %f TAX_RATE_HH_CAPITAL: %f TAX_RATE_VAT: %f",
                 TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
              printf("\n \t UNEMPLOYMENT_BENEFIT_PCT: %f HH_SUBSIDY_PCT: %f FIRM_SUBSIDY_PCT: %f HH_TRANSFER_PAYMENT: %f FIRM_TRANSFER_PAYMENT; %f",
                 UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);
              getchar();
        }
        #endif
    }

    if(POLICY_EXP_STABILIZATION_TAX && DAY >=POLICY_STARTING_AT_ITERATION)
    {
        //Set trigger function:
        if ((SUBSIDY_FLAG==0)&&(GDP_GROWTH<SUBSIDY_TRIGGER_ON))
        {
            SUBSIDY_FLAG=1;

            //Lower the income tax 
    	    TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE + 5*tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
	        TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE + 5*tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }

        //Release trigger function:
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH>SUBSIDY_TRIGGER_OFF))
        {
            SUBSIDY_FLAG=0;

            //Reset the income tax to its normal value
            TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE;
        	TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE;
        }

        //Subsidy regime
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH<SUBSIDY_TRIGGER_OFF))
        {
            //Lower the income tax 
	        TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE + 5*tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
    	    TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE + 5*tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }

        #ifdef _DEBUG_MODE
        if ((PRINT_DEBUG_GOV)&&(SUBSIDY_FLAG==1))
        { 
              printf("\n Stabilization: Government_send_policy_announcements ID: %d",ID);
              printf("\n SUBSIDY_FLAG: %d",SUBSIDY_FLAG);
              printf("\n CONST_INCOME_TAX_RATE: %f", CONST_INCOME_TAX_RATE);
              printf("\n GDP_GROWTH: %f", GDP_GROWTH);
              printf("\n fabs(GDP_GROWTH): %f", fabs(GDP_GROWTH));
              printf("\n SUBSIDY_TRIGGER_ON %f", SUBSIDY_TRIGGER_ON);
              printf("\n SUBSIDY_TRIGGER_OFF: %f", SUBSIDY_TRIGGER_OFF);
              printf("\n tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF): %f", tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF));
              printf("\n tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH): %f", tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH));
              printf("\n New Tax: %f %f = %f", CONST_INCOME_TAX_RATE, tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH), CONST_INCOME_TAX_RATE + tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH));
              printf("\n HH_SUBSIDY_PCT: %f", HH_SUBSIDY_PCT);
              printf("\n \t TAX_RATE_HH_LABOUR: %f TAX_RATE_CORPORATE: %f TAX_RATE_HH_CAPITAL: %f TAX_RATE_VAT: %f",
                 TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
              printf("\n \t UNEMPLOYMENT_BENEFIT_PCT: %f HH_SUBSIDY_PCT: %f FIRM_SUBSIDY_PCT: %f HH_TRANSFER_PAYMENT: %f FIRM_TRANSFER_PAYMENT; %f",
                 UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);
              getchar();
        }
        #endif
     }


	if ((POLICY_EXP_BEST_TECHNOLOGY_SUBSIDY==1 || POLICY_EXP_ALL_TECHNOLOGIES_SUBSIDY==1 || TECH_POLICY_EFFECTIVENESS_SWITCH) && DAY >=POLICY_STARTING_AT_ITERATION)
	{

			
			if( REGIONAL_POLICY_TECHNOLOGY_SUBSIDY== 1)
			{
				if(REGIONAL_FIRM_SUBSIDY==1)
					FIRM_SUBSIDY_PCT= BEST_TECHNOLOGY_SUBSIDY_PCT;
				else	
					FIRM_SUBSIDY_PCT= 0;
			}else
			{
				FIRM_SUBSIDY_PCT= BEST_TECHNOLOGY_SUBSIDY_PCT;
			}
		
	}

/*
    #ifdef _DEBUG_MODE
     if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Government_policies.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f %d",DAY,ID,TAX_RATE_HH_LABOUR,TAX_RATE_CORPORATE,TAX_RATE_HH_CAPITAL,REGION_ID);
            fclose(file1);
            free(filename);
        }
    #endif
    
    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG_GOV)
    { 
    printf("\n Government_send_policy_announcements ID: %d",ID);
    printf("\n \t TAX_RATE_HH_LABOUR: %f TAX_RATE_CORPORATE: %f TAX_RATE_HH_CAPITAL: %f TAX_RATE_VAT: %f",
         TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
       printf("\n \t UNEMPLOYMENT_BENEFIT_PCT: %f HH_SUBSIDY_PCT: %f FIRM_SUBSIDY_PCT: %f HH_TRANSFER_PAYMENT: %f FIRM_TRANSFER_PAYMENT: %f",
         UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);
        getchar();
    }
    #endif
*/



	/*Code added March 13th 2013: keep budget balanced*/

	if(ADAPTIVE_TAX_RATES==1){



		if(DAY>500){

		double sum_expenditures = 0;
		double sum_tax_basis = 0;
	
		for(i=0; i< GOV_INFLOWS_OUTFLOWS.size;i++){

			sum_expenditures += GOV_INFLOWS_OUTFLOWS.array[i].outflows;
			sum_tax_basis += GOV_INFLOWS_OUTFLOWS.array[i].tax_basis;

		}
	
	
		if(sum_tax_basis>0){

			double temp_tax = sum_expenditures/sum_tax_basis;


			if( temp_tax < 0.7){

				TAX_RATE_HH_LABOUR = temp_tax;
				TAX_RATE_CORPORATE =  temp_tax;
				TAX_RATE_HH_CAPITAL =  temp_tax;
			}else{


				TAX_RATE_HH_LABOUR = 0.7;
				TAX_RATE_CORPORATE =0.7;
				TAX_RATE_HH_CAPITAL = 0.7;
			}
		 }




		if(GOV_2_RELAXED_BUDGET_RULE ==1 ){

			if(REGION_ID==2){

			if(sum_tax_basis>0){

				double temp_tax = GOV_2_EXPENDITURES_COVERED*sum_expenditures/sum_tax_basis;

				if( temp_tax < 0.7){

					TAX_RATE_HH_LABOUR = temp_tax;
					TAX_RATE_CORPORATE =  temp_tax;
					TAX_RATE_HH_CAPITAL = temp_tax;

				}else{


					TAX_RATE_HH_LABOUR = 0.7;
					TAX_RATE_CORPORATE =0.7;
					TAX_RATE_HH_CAPITAL = 0.7;


				}
			 }

			}else{

				if(sum_tax_basis>0){

							double temp_tax = 0.97*sum_expenditures/sum_tax_basis;

							if( temp_tax < 0.7){

								TAX_RATE_HH_LABOUR = temp_tax;
								TAX_RATE_CORPORATE =  temp_tax;
								TAX_RATE_HH_CAPITAL = temp_tax;

							}else{


								TAX_RATE_HH_LABOUR = 0.7;
								TAX_RATE_CORPORATE =0.7;
								TAX_RATE_HH_CAPITAL = 0.7;


							}
						 }


			}


		}
}

	}
    //add announcement
    add_policy_announcement_message(ID, TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT, UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT, MINIMUM_WAGE, BASIC_SECURITY_BENEFITS);

	
	//HC policy
	if(GOV_POLICY_SWITCH_HUMAN_CAPITAL_IMPROVEMENT==1)
	{
		int year = DAY / 240;

		// Add announcement when human capital policy will be installed
		if(year==HUMAN_CAPITAL_POLICY_INSTALLATION_DATE_IN_YEARS)
		{
			add_human_capital_policy_announcement_message(ID,1);

			HUMAN_CAPITAL_POLICY_FLAG = 1;

		}
	}
    return 0;   
}

/* \fn: int Government_install_human_capital_policy()
 * \brief Function determijnes the consumption buget of the government.
 */
int Government_determine_consumption_budget()
{

	// in order to avoid pro-cyclical government spendings, we assume here that the government budget is the maximum of the last GDPs
	double temp_gdp = 0.0;
	double max_gdp = 0.0;
	for(int i=0; i < LAST_MONTHLY_GDPS.size;i++){

		if(LAST_MONTHLY_GDPS.array[i]>temp_gdp)
			max_gdp = LAST_MONTHLY_GDPS.array[i];


	}

	// The monthly government spending is assumed to be proportional to the local gdp.
	GOV_MONTHLY_CONSUMPTION_BUDGET = GDP_FRACTION_CONSUMPTION*max_gdp;


	return 0;
}


int Government_migration()
{

	//FLAME_environment_variable_migration_experiment =1 ;
	//FLAME_environment_variable_migration_date = 10079 ;
    //MIGRATION_DATE
    if(MIGRATION_EXPERIMENT!=0 && DAY == MIGRATION_DATE ){



    	if(MIGRATION_EXPERIMENT == 1){


    		FLAME_environment_variable_policy_migration_top_up_benefits  = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 0;
    		FLAME_environment_variable_migration_allocation_policy = 0;
    		FLAME_environment_variable_migration_region_id = 1;


    	}else if(MIGRATION_EXPERIMENT == 2){

    		FLAME_environment_variable_policy_migration_top_up_benefits  = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 0;
    		FLAME_environment_variable_migration_allocation_policy = 0;
    		FLAME_environment_variable_migration_region_id = 2;

    	}else if(MIGRATION_EXPERIMENT == 3){

    		FLAME_environment_variable_policy_migration_top_up_benefits  = 0;
			FLAME_environment_variable_policy_migration_wage_subsidies = 0;
			FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 0;
			FLAME_environment_variable_migration_region_id = 1;
			FLAME_environment_variable_migration_allocation_policy = 1;
			FLAME_environment_variable_migration_allocation_quota = 0.5;

    	}else if(MIGRATION_EXPERIMENT == 4){


    		FLAME_environment_variable_policy_migration_top_up_benefits  = 1;
    		FLAME_environment_variable_policy_migration_wage_subsidies = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 0;
    		FLAME_environment_variable_migration_region_id = 1;

    	}else if(MIGRATION_EXPERIMENT == 5){

    		FLAME_environment_variable_policy_migration_top_up_benefits  = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies = 1;
    		FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 0;
    		FLAME_environment_variable_migration_region_id = 1;

    	}else if(MIGRATION_EXPERIMENT == 6){

    		FLAME_environment_variable_policy_migration_top_up_benefits  = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies = 1;
    		FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 1;
    		FLAME_environment_variable_migration_region_id = 1;

    	}else if(MIGRATION_EXPERIMENT == 7){

    		FLAME_environment_variable_policy_migration_top_up_benefits  = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies = 1;
    		FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 0;
    		FLAME_environment_variable_minimum_wage_policy = 1;
    		FLAME_environment_variable_minimum_wage_policy_target_minimum_wage = 0.75;
    		FLAME_environment_variable_migration_region_id = 1;


    	}else if(MIGRATION_EXPERIMENT == 8){

    		FLAME_environment_variable_policy_migration_top_up_benefits  = 0;
    		FLAME_environment_variable_policy_migration_wage_subsidies = 1;
    		FLAME_environment_variable_policy_migration_wage_subsidies_targeted = 1;
    		FLAME_environment_variable_minimum_wage_policy = 1;
    		FLAME_environment_variable_minimum_wage_policy_target_minimum_wage = 0.75;
    		FLAME_environment_variable_migration_region_id = 1;

    	}


    	if(MIGRATION_REGION_ID == REGION_ID){


    	// Count the number of agents in order to assign a unique id
    	int number_agents = 0;

    	number_agents = Household_start_Household_state->count +
    	Firm_start_Firm_state->count+
    	Government_start_Government_state->count+
    	Eurostat_start_Eurostat_state->count+
    	Mall_start_Mall_state->count+
    	IGFirm_IGFirm_start_state->count+
    	Bank_start_Bank_state->count+
    	CentralBank_start_Central_Bank_state->count+
    	ClearingHouse_start_Clearinghouse_state->count;


    	int id = number_agents +1;

    	double cloud_data[6] = {0.0,0.0,0.0,0.0,0.0,0.0};

    	//Create new agents from the following xml file
    	readAgentXML("/home/pharting/Desktop/Migration//imi.xml",cloud_data,0,0,0,0,0);


    	double unemploy_ben_pct_other_region = 0.0;
    	double basic_security_other_region= 0.0;
    	double avrage_wage_other_region= 0.0;



    	if(current_xmachine_Government_holder->next){
    	unemploy_ben_pct_other_region = current_xmachine_Government_holder->next->agent->unemployment_benefit_pct;
    	    						avrage_wage_other_region = current_xmachine_Government_holder->next->agent->country_wide_mean_wage;
    	    						basic_security_other_region = current_xmachine_Government_holder->next->agent-> basic_security_benefits;
    	// Count new agents
    	}
    	int num_new_agents = 0;
    		current_xmachine_Household_holder = Household_start_Household_state->agents;

			while(current_xmachine_Household_holder)
			{

				if(current_xmachine_Household_holder->agent->new_agent==1){

					num_new_agents++;

				}

				current_xmachine_Household_holder = current_xmachine_Household_holder->next;

			}

			int other_gov_id = 0;
			int other_region_id = 0;

			for(int i=0; i < ALL_REGION_IDS.size;i++){

				if(ALL_GOV_IDS.array[i]!=ID){

					other_gov_id = ALL_GOV_IDS.array[i];
					other_region_id = ALL_REGION_IDS.array[i];

				}

			}


			int new_agents_in_this_region =  (int) floor(MIGRATION_ALLOCATION_QUOTA *num_new_agents);

    	// Assign correct id:
    	current_xmachine_Household_holder = Household_start_Household_state->agents;

    				int counter = 0;

    				while(current_xmachine_Household_holder)
    				{

    					int reg_id;
    					int go_id;

    					double u, w, bs;

    					if(MIGRATION_ALLOCATION_POLICY){

    						if(counter < new_agents_in_this_region){

    							go_id = ID;
    							reg_id= REGION_ID;
    							u=UNEMPLOYMENT_BENEFIT_PCT;
    							w= COUNTRY_WIDE_MEAN_WAGE;
    							bs = BASIC_SECURITY_BENEFITS;

    						}else{


    							go_id = other_gov_id;
    							reg_id= other_region_id;

    							u=unemploy_ben_pct_other_region;
    							w= avrage_wage_other_region;
    							bs =basic_security_other_region;

    						}
    						counter++;

    					}else{

    						go_id = ID;
    						reg_id= REGION_ID;
    						u=UNEMPLOYMENT_BENEFIT_PCT;
							w= COUNTRY_WIDE_MEAN_WAGE;
							bs = BASIC_SECURITY_BENEFITS;

    					}



    					if(current_xmachine_Household_holder->agent->new_agent==1){

    						printf("\n Additional household created in region %d with id: %d",reg_id,id);

    						current_xmachine_Household_holder->agent->region_id = reg_id;
    						current_xmachine_Household_holder->agent->id = id;
    						id ++;
						current_xmachine_Household_holder->agent->gov_id = go_id;
    						current_xmachine_Household_holder->agent->new_agent = 0;
    						current_xmachine_Household_holder->agent->region_wide_mean_wage =  w;
    						current_xmachine_Household_holder->agent->wage_reservation = bs;

    						current_xmachine_Household_holder->agent-> unemployment_benefit_pct =u;
    						current_xmachine_Household_holder->agent->specific_skill= 0.35;

    					}

    					current_xmachine_Household_holder = current_xmachine_Household_holder->next;


    				}


    		}

    }

    if(MINIMUM_WAGE_POLICY && REGION_ID==MIGRATION_REGION_ID){


    	if(MINIMUM_WAGE_POLICY_TARGET_MINIMUM_WAGE > MINIMUM_WAGE_PCT){

    		MINIMUM_WAGE_PCT += 0.005;

    	}

    }





	return 0;
}




int Government_rank_and_buy_goods_1()
{

	int day_in_month = DAY%20;
	double daily_budget = GOV_MONTHLY_CONSUMPTION_BUDGET/(20-day_in_month);





    //Logit model parameter:
    double sum_weighted_qual_pric_ratios = 0;
    int j=0;
    int i=0;
    double logit;


    mall_quality_price_info_array mall_quality_price_info_list;
    init_mall_quality_price_info_array(&mall_quality_price_info_list);



		for(i=0; i<ORDERED_QUANTITIES.size;i++)
		{
			remove_ordered_quantity(&ORDERED_QUANTITIES,i);
			i--;

		}



        /*Household reads quality price info mesasges sent by malls   */
        START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP

    	if( quality_price_info_1_message->available==1 && quality_price_info_1_message->firm_region_id==REGION_ID )
        {
        add_mall_quality_price_info(&mall_quality_price_info_list,  quality_price_info_1_message->mall_id, quality_price_info_1_message->firm_id,               quality_price_info_1_message->mall_region_id,                   quality_price_info_1_message->quality,                  quality_price_info_1_message->price,
        quality_price_info_1_message->available);
  		 }


        FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP



            logit_firm_id_array  logit_firm_id_list;
            init_logit_firm_id_array(&logit_firm_id_list);

			//+++++ Logit Model +++++++++:


			/*Sum of weighted exponents of quality price ratios*/
			for(i = 0; i < mall_quality_price_info_list.size;i++)
			{
				sum_weighted_qual_pric_ratios += (mall_quality_price_info_list.array[i]
				.available) * exp(GAMMA_GOV*(GAMMA_QUALITY*log(mall_quality_price_info_list.array[i].quality) -log(mall_quality_price_info_list.array[i].price)));


			}

			/* Compute logits and add on temporary logit array   */
			for(i = 0; i < mall_quality_price_info_list.size;i++)
			{
				logit = (mall_quality_price_info_list.array[i].available) *
				 exp(GAMMA_GOV*(GAMMA_QUALITY*log(mall_quality_price_info_list.array[i].quality) -log(mall_quality_price_info_list.array[i].price))) /
				sum_weighted_qual_pric_ratios;


				if(logit > 0)
				{
					add_logit_firm_id(&logit_firm_id_list, logit,
					mall_quality_price_info_list.array[i].firm_id);
				}

			}

			if(sum_weighted_qual_pric_ratios > 0)
			{

				for(j = 0; j < logit_firm_id_list.size;j++)
				{
					double quantity = daily_budget*logit_firm_id_list.array[j].logit/
							mall_quality_price_info_list.array[j].price;

					add_ordered_quantity(&ORDERED_QUANTITIES, mall_quality_price_info_list
								.array[j].firm_id, quantity,
								mall_quality_price_info_list.array[j].price, mall_quality_price_info_list.array[j].quality );

					 add_consumption_request_1_message(
					            mall_quality_price_info_list.array[j].mall_id,ID,REGION_ID,
					            mall_quality_price_info_list.array[j].firm_id,
					            quantity);

				}




        }

	free_logit_firm_id_array(&logit_firm_id_list);


    free_mall_quality_price_info_array(&mall_quality_price_info_list);


    return 0;

}

int Government_receive_goods_read_rationing(){




	for(int i=0; i<GOV_RECEIVED_QUANTITIES.size;i++)
	{
		remove_received_quantities(&GOV_RECEIVED_QUANTITIES,i);
		i--;

	}


	START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP


		for(int i=0; i < ORDERED_QUANTITIES.size; i++ ){

				if(ORDERED_QUANTITIES.array[i].firm_id==accepted_consumption_1_message->firm_id){

	                /*Update of Budget  */
					GOV_MONTHLY_CONSUMPTION_BUDGET = GOV_MONTHLY_CONSUMPTION_BUDGET - accepted_consumption_1_message
	                ->offered_consumption_volume *ORDERED_QUANTITIES.array[i].price;

					MONTHLY_CONSUMPTION_EXPENDITURE +=accepted_consumption_1_message
	                ->offered_consumption_volume * ORDERED_QUANTITIES.array[i].price;
					GOV_OUTFLOWS_CALENDAR.consumption_expenditure +=
	                accepted_consumption_1_message->offered_consumption_volume *ORDERED_QUANTITIES.array[i].price;



					add_received_quantities(&GOV_RECEIVED_QUANTITIES,accepted_consumption_1_message->firm_id,accepted_consumption_1_message
			                ->offered_consumption_volume);


					PAYMENT_ACCOUNT = PAYMENT_ACCOUNT - accepted_consumption_1_message
			                ->offered_consumption_volume * ORDERED_QUANTITIES.array[i].price;


	                break;
				}
		}

	        FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP



	return 0;
}


int Government_rank_and_buy_goods_2(){




	return 0;
}


int Government_receive_goods_read_rationing_2(){



	return 0;
}



int Government_handle_leftover_budget(){




	return 0;
}

/* \fn: int Government_install_human_capital_policy()
 * \brief Function executes the human capital policy.
 */
int Government_install_human_capital_policy()
{

	printf("Government_install_human_capital_policy()");
	
	int i,j,id, total_no_households;
	adt_actual_skill_distribution_with_ids_array actual_skill_distribution;
	init_adt_actual_skill_distribution_with_ids_array(&actual_skill_distribution);

	//Create an array for recording the current skill distribution with all ids

	
	for(i=0;i<NEW_SKILL_DISTRIBUTION.size;i++)
	{
		add_adt_actual_skill_distribution_with_ids(&actual_skill_distribution,
			NEW_SKILL_DISTRIBUTION.array[i].general_skill_group,0);
	}

	// Record the current skill distribution:
	START_HUMAN_CAPITAL_POLICY_GENERAL_SKILL_INFORMATION_MESSAGE_LOOP
	
	for(i=0; i < actual_skill_distribution.size; i++)
	{
		if(human_capital_policy_general_skill_information_message->
			general_skills==actual_skill_distribution.array[i].general_skill_group )
		{
			add_int(&actual_skill_distribution.array[i].id_list,
				human_capital_policy_general_skill_information_message->id);
			break;
		}
	}
	FINISH_HUMAN_CAPITAL_POLICY_GENERAL_SKILL_INFORMATION_MESSAGE_LOOP


	//Count the households per skill group

	total_no_households = 0;

	for(i=0; i<NEW_SKILL_DISTRIBUTION.size;i++)
	{
		total_no_households += actual_skill_distribution.array[i].id_list.size;
	}

	// Redistribute the households

	for(i=0; i<NEW_SKILL_DISTRIBUTION.size-1;i++)
	{
		while(actual_skill_distribution.array[i].id_list.size>NEW_SKILL_DISTRIBUTION.array[i].percentage*total_no_households)
		{
			// Add the first household to the list of the next skill group

			id = actual_skill_distribution.array[i].id_list.array[0];
		
			printf("Vorher: actual_skill_distribution.array[i].id_list.size %d ", actual_skill_distribution.array[i].id_list.size);			
			
			// Remove the first household (which has moved to the next skill group)
			remove_int(&actual_skill_distribution.array[i].id_list,0);

			printf("Nsachher: actual_skill_distribution.array[i].id_list.size %d \n ", actual_skill_distribution.array[i].id_list.size);			


			printf("Vorher: actual_skill_distribution.array[i+1].id_list.size %d ", actual_skill_distribution.array[i+1].id_list.size);	
			add_int(&actual_skill_distribution.array[i+1].id_list,id);
			printf("Nachher: actual_skill_distribution.array[i+1].id_list.size %d \n ", actual_skill_distribution.array[i+1].id_list.size);	
			
		}
	}

	//Send the new general skill levels to the households
	for(i=0; i<actual_skill_distribution.size;i++)
	{
		for(j=0;j<actual_skill_distribution.array[i].id_list.size;j++)
		{
			add_human_capital_policy_new_general_skill_notification_message(
				actual_skill_distribution.array[i].id_list.array[j],
				ID,actual_skill_distribution.array[i].general_skill_group);
		
		}
	}

	free_adt_actual_skill_distribution_with_ids_array(&actual_skill_distribution);	

	HUMAN_CAPITAL_POLICY_FLAG =0;


return 0;
}


/* \fn: int Government_read_tax_payments()
 * \brief Function to read the tax revenues and store the monthly and yearly totals.
 */
int Government_read_tax_payments()
{   
    double sum =0.0;

    START_TAX_PAYMENT_MESSAGE_LOOP
    
        MONTHLY_TAX_REVENUES += tax_payment_message->tax_payment;
        sum += tax_payment_message->tax_payment;
        GOV_INFLOWS_CALENDAR.tax_revenues += tax_payment_message->tax_payment; 
    
    FINISH_TAX_PAYMENT_MESSAGE_LOOP
    
      

    START_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP
    
        MONTHLY_BENEFIT_PAYMENT -= unemployment_benefit_restitution_message->restitution_payment;
        sum += unemployment_benefit_restitution_message->restitution_payment;
        
        GOV_INFLOWS_CALENDAR.restitution_payment += 
        unemployment_benefit_restitution_message->restitution_payment;
        
    FINISH_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP 

   PAYMENT_ACCOUNT += sum;
   
   #ifdef _DEBUG_MODE
   if (PRINT_DEBUG)
   {
                   printf("\n\n Government_read_tax_payments ID: %d",ID);
                   printf("\n\n MONTHLY_TAX_REVENUES: %f sum: %f",MONTHLY_TAX_REVENUES,sum);
                   printf("\n\n PAYMENT_ACCOUNT: %f",PAYMENT_ACCOUNT);
   }
   #endif 
    
    return 0;
}

/* \fn: int Government_read_unemployment_benefit_notifications()
 * \brief Counter of the unemployment benefit messages, monthly and yearly totals of the unemployment benefit payments.
 */
int Government_read_unemployment_benefit_notifications()
{
    double sum;
    NUM_UNEMPLOYED = 0;
    
    //Start message loop
    sum=0.0;
    START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
        
        NUM_UNEMPLOYED++;
        sum += unemployment_notification_message->unemployment_payment;
        
        GOV_OUTFLOWS_CALENDAR.benefit_payment += 
        unemployment_notification_message->unemployment_payment;
        
    FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP

    MONTHLY_BENEFIT_PAYMENT += sum;    
    YEARLY_BENEFIT_PAYMENT += sum;     

    // Update the payment account
    
    PAYMENT_ACCOUNT -= sum;
    
    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG)
    {
                   printf("\n\n Government_read_unemployment_benefit_notifications ID: %d",ID);
                   printf("\n\n MONTHLY_BENEFIT_PAYMENT: %f sum: %f",MONTHLY_BENEFIT_PAYMENT,sum);
                   printf("\n\n YEARLY_BENEFIT_PAYMENT: %f PAYMENT_ACCOUNT: %f",YEARLY_BENEFIT_PAYMENT,PAYMENT_ACCOUNT);
    }
    #endif

    return 0;
}

/* \fn: int Government_read_transfer_notifications()
 * \brief Counter of the transfer notification messages, monthly and yearly totals of the transfer payments.
 */
int Government_read_transfer_notifications()
{
    int sum;
        
    //Start message loop 
    sum=0;



    START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(hh_transfer_notification_message->gov_id==ID)
            sum++;
    FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_TRANSFER_PAYMENT += sum*HH_TRANSFER_PAYMENT;
    YEARLY_TRANSFER_PAYMENT += sum*HH_TRANSFER_PAYMENT;  
    
    GOV_OUTFLOWS_CALENDAR.transfer_payment_household +=  sum*HH_TRANSFER_PAYMENT; 

    // Update the payment account
    PAYMENT_ACCOUNT -= sum*HH_TRANSFER_PAYMENT;
    if(AUSTERITY_POLICY > 0){

    		if(AUSTERITY_PHASE==1){
				ADD_FOREIGN_DEBT += sum*HH_TRANSFER_PAYMENT;
				FOREIGN_DEBT  += sum*HH_TRANSFER_PAYMENT;
				PAYMENT_ACCOUNT += sum*HH_TRANSFER_PAYMENT;
    		}

        	// communitization of transfers
			if((AUSTERITY_POLICY_SCENARIO==2 || AUSTERITY_POLICY_SCENARIO==4)  &&  AUSTERITY_PHASE > 1){


				SUBSIDY_REPORTED_TO_EUROSTAT += sum*HH_TRANSFER_PAYMENT;


			}

        }
    //Start message loop 
    sum=0;
    START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(firm_transfer_notification_message->gov_id==ID)
            sum++;
    FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT;
    YEARLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT; 
    
    GOV_OUTFLOWS_CALENDAR.transfer_payment_firm +=  sum*FIRM_TRANSFER_PAYMENT;  

    // Update the payment account
    PAYMENT_ACCOUNT -= sum*FIRM_TRANSFER_PAYMENT;
    




    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG)
    {
                   printf("\n\n Government_read_transfer_notifications ID: %d",ID);
                   printf("\n\n MONTHLY_TRANSFER_PAYMENT: %f YEARLY_TRANSFER_PAYMENT: %f",MONTHLY_TRANSFER_PAYMENT,YEARLY_TRANSFER_PAYMENT);
    }
    #endif
    
    return 0;
}
    
/* \fn: int Government_read_subsidy_notifications()
 * \brief Counter of the subsidy notification messages, monthly and yearly totals of the subsidy payments.
 */
int Government_read_subsidy_notifications()
{
    double sum;
        
    //Start message loop 
    sum=0.0;
    START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(hh_subsidy_notification_message->gov_id==ID)
            sum += hh_subsidy_notification_message->subsidy_payment;
            
        GOV_OUTFLOWS_CALENDAR.subsidy_payment_household += 
        hh_subsidy_notification_message->subsidy_payment;
        
    FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_SUBSIDY_PAYMENT += sum;
    YEARLY_SUBSIDY_PAYMENT += sum;  
    
    SUBSIDY_REPORTED_TO_EUROSTAT += sum;

    MONTHLY_SUBSIDY_PAYMENT_TO_HOUSEHOLDS += sum;

    // Update the payment account
    PAYMENT_ACCOUNT -= sum;

    //Start message loop 
    sum=0.0;
    START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(firm_subsidy_notification_message->gov_id==ID)
            sum += firm_subsidy_notification_message->subsidy_payment;
            
        GOV_OUTFLOWS_CALENDAR.subsidy_payment_firm += 
        firm_subsidy_notification_message->subsidy_payment;
        
    FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_SUBSIDY_PAYMENT += sum;
    YEARLY_SUBSIDY_PAYMENT += sum;

    MONTHLY_SUBSIDY_PAYMENT_TO_FIRMS += sum;

    // Update the payment account
    PAYMENT_ACCOUNT -= sum;

	SUBSIDY_REPORTED_TO_EUROSTAT += sum;



	if(DAY%MONTH==0){


		/*For Joe experiment: if the region id ==2, then gov expenditures and unemployment benefits are co-financed by the other region*/
		if(GOV_EXPENDITURES_AND_UNEMP_BENEFITS_REDISTRIBUTED && REGION_ID ==2){

				SUBSIDY_REPORTED_TO_EUROSTAT +=  MONTHLY_BENEFIT_PAYMENT + GOV_OUTFLOWS_CALENDAR.consumption_expenditure;
		}

		if(SUBSIDY_REDISTRIBUTION){

			add_total_subsidies_message(ID,REGION_ID, SUBSIDY_REPORTED_TO_EUROSTAT);

		}

	SUBSIDY_REPORTED_TO_EUROSTAT = 0;

	}

	//Send message to Eurostat
    
    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG)
    {
                   printf("\n\n Government_read_subsidy_notifications ID: %d",ID);
                   printf("\n\n MONTHLY_SUBSIDY_PAYMENT: %f YEARLY_SUBSIDY_PAYMENT: %f",MONTHLY_SUBSIDY_PAYMENT,YEARLY_SUBSIDY_PAYMENT);
    }
    #endif

    return 0;
}


/* \fn: int Government_send_account_update()
 * \brief Function to send the payment_account value to the Central Bank.
 */
int Government_send_account_update()
{
     FILE *file1;
     char *filename;
        // At the very end of agent government: update the bank account
        add_gov_to_central_bank_account_update_message(ID, PAYMENT_ACCOUNT, YEARLY_GDP);

        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
        {
	    printf("\n\n Government_send_account_update ID: %d",ID);
	    printf("\n\t PAYMENT_ACCOUNT: %f\n\n",PAYMENT_ACCOUNT);
        }
        #endif
        
        if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Governments_daily_balance_sheet.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f",DAY,ID,PAYMENT_ACCOUNT);
            fprintf(file1," %d",REGION_ID);
            fclose(file1);
            free(filename);
        }  
        
    return 0;
}

/* \fn: int Government_balance_sheet()
 * \brief Function to compute balance sheet of Gov.
 */
int Government_compute_balance_sheet()
{                   

	if(DAY%MONTH == 0)
	{

	    //Government reads the dividend msg from ECB, after ECB knows its equity.
		START_ECB_DIVIDEND_MESSAGE_LOOP
		    PAYMENT_ACCOUNT += ecb_dividend_message->dividend_per_gov;
		    GOV_INFLOWS_CALENDAR.ecb_dividend = ecb_dividend_message->dividend_per_gov;
		FINISH_ECB_DIVIDEND_MESSAGE_LOOP

		GOV_STOCKS_CALENDAR.payment_account_day_20=PAYMENT_ACCOUNT;
    
    		GOV_OUTFLOWS_CALENDAR.total_expenses=
    		GOV_OUTFLOWS_CALENDAR.investment_expenditure+
    		GOV_OUTFLOWS_CALENDAR.consumption_expenditure+
    		GOV_OUTFLOWS_CALENDAR.benefit_payment+
    		GOV_OUTFLOWS_CALENDAR.subsidy_payment_household+
    		GOV_OUTFLOWS_CALENDAR.subsidy_payment_firm+
    		GOV_OUTFLOWS_CALENDAR.transfer_payment_household+
    		GOV_OUTFLOWS_CALENDAR.transfer_payment_firm+
    		GOV_OUTFLOWS_CALENDAR.bond_interest_payment+
    		GOV_OUTFLOWS_CALENDAR.total_bond_repurchase+
    		GOV_OUTFLOWS_CALENDAR.debt_installment;
    		
    
    		GOV_INFLOWS_CALENDAR.total_income=
    		GOV_INFLOWS_CALENDAR.tax_revenues +
    		GOV_INFLOWS_CALENDAR.restitution_payment +
    		GOV_INFLOWS_CALENDAR.total_bond_financing+
    		GOV_INFLOWS_CALENDAR.total_money_financing+
    		GOV_INFLOWS_CALENDAR.ecb_dividend;
    		
    		GOV_INFLOWS_CALENDAR.net_inflow =
    		GOV_INFLOWS_CALENDAR.total_income -
    		GOV_OUTFLOWS_CALENDAR.total_expenses;
    		
    		GOV_STOCKS_CALENDAR.payment_account = PAYMENT_ACCOUNT;
    		GOV_STOCKS_CALENDAR.total_assets = PAYMENT_ACCOUNT;
    		//GOV_STOCKS_CALENDAR.value_bonds_outstanding = BOND.nr_outstanding*BOND.face_value;
    		GOV_STOCKS_CALENDAR.ecb_money += TOTAL_MONEY_FINANCING;
    		GOV_STOCKS_CALENDAR.equity =	
    		GOV_STOCKS_CALENDAR.total_assets -
    		GOV_STOCKS_CALENDAR.value_bonds_outstanding -
    		GOV_STOCKS_CALENDAR.ecb_money;
    		
    		//GOV_STOCKS_CALENDAR.nr_bonds_outstanding = BOND.nr_outstanding;
    		
	    }             
        
    return 0;
}

/* \fn: int Government_resolve_unsold_bonds_dummy()
 * \brief Function to resolve the bonds that are left unsold at the end of each month.
 */
int Government_resolve_unsold_bonds_dummy()
{   
    return 0;
}

/* \fn: int Government_monthly_budget_accounting()
 * \brief Function to perform accounting at the end of each month.
 */
int Government_monthly_budget_accounting()
{
    double in, out;
    FILE *file1;
    char *filename;


	if(GOV_INFLOWS_OUTFLOWS.size==GOV_BUDGETING_HORIZON)
		remove_adt_gov_inflows_outflows(&GOV_INFLOWS_OUTFLOWS,0);

    //Compute the following: the interest rate is the base rate of the Central Bank
    //GOV_INTEREST_RATE = (double) 0.05/12.0;
    //GOV_INTEREST_RATE = CB_BASE_RATE/12.0;
    
    YEARLY_TAX_REVENUES += MONTHLY_TAX_REVENUES;
    
    //Items that have already been added to the payment_account
        in = MONTHLY_TAX_REVENUES +SUBSIDY_TRANSFER_RECEIVED + ADD_FOREIGN_DEBT;
        MONTHLY_INCOME = in;
        
    //Items that have already been subtracted from the payment_account

        if(AUSTERITY_POLICY ==0){
        out = MONTHLY_BENEFIT_PAYMENT +
        MONTHLY_TRANSFER_PAYMENT + 
		MONTHLY_SUBSIDY_PAYMENT +
        MONTHLY_BOND_INTEREST_PAYMENT +
        MONTHLY_INVESTMENT_EXPENDITURE +
        MONTHLY_CONSUMPTION_EXPENDITURE+
        FOREIGN_DEBT_INSTALLMENT;
        
        MONTHLY_EXPENDITURE = out;


        }else{

        	out = MONTHLY_BENEFIT_PAYMENT +
        			MONTHLY_SUBSIDY_PAYMENT +
        	        MONTHLY_BOND_INTEREST_PAYMENT +
        	        MONTHLY_INVESTMENT_EXPENDITURE +
        	        MONTHLY_CONSUMPTION_EXPENDITURE+
        	        FOREIGN_DEBT_INSTALLMENT +MONTHLY_TRANSFER_PAYMENT;

        	        MONTHLY_EXPENDITURE = out;



        }



		add_adt_gov_inflows_outflows(&GOV_INFLOWS_OUTFLOWS,in,out,in/TAX_RATE_HH_LABOUR);

        
    //Compute budget deficit
        MONTHLY_BUDGET_BALANCE = in - out;
        
    //Debt accounting: if the balance>0 debt decreases, if balance<0, debt increases.
        //Debt>0 means a debt, Debt<0 means a surplus.
        CUMULATED_DEFICIT -= MONTHLY_BUDGET_BALANCE;
        //TOTAL_DEBT = BOND.nr_outstanding*BOND.face_value;
        TOTAL_DEBT = CUMULATED_DEFICIT + FOREIGN_DEBT;

        //Check: value of payment account should be equal to total_debt:

        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG && ((TOTAL_DEBT + PAYMENT_ACCOUNT) != 0.0))
            fprintf(stdout,"\n ERROR in Government: Total debt %2.5f is not equal to payment account %2.5f\n\n", TOTAL_DEBT, PAYMENT_ACCOUNT);
        #endif 
                
    //Monetary policy rule: decide on fraction of deficit to be financed by bonds/fiar money
        TOTAL_MONEY_FINANCING=0;
        TOTAL_BOND_FINANCING=0;
        
/* Sander, 17.06.09: Old style code: refers to the monthly budget deficit        
        if (MONTHLY_BUDGET_BALANCE<0.0)
        {
            TOTAL_MONEY_FINANCING = GOV_POLICY_MONEY_FINANCING_FRACTION*fabs(MONTHLY_BUDGET_BALANCE);
            TOTAL_BOND_FINANCING = (1-GOV_POLICY_MONEY_FINANCING_FRACTION)*fabs(MONTHLY_BUDGET_BALANCE);
        }
*/        
/* Sander, 17.06.09: Marco proposed code: refers to a negative payment_account*/
        if (PAYMENT_ACCOUNT<0.0)
        {
            TOTAL_MONEY_FINANCING = GOV_POLICY_MONEY_FINANCING_FRACTION*fabs(PAYMENT_ACCOUNT);
            TOTAL_BOND_FINANCING = (1-GOV_POLICY_MONEY_FINANCING_FRACTION)*fabs(PAYMENT_ACCOUNT);
        }
        
        //Government sends a message to ECB with the value of fiat money requested
        //Assume that the ECB is FULLY accommodating the government's demand for fiat money
        //add_request_fiat_money_message(nominal_value);
        add_request_fiat_money_message(TOTAL_MONEY_FINANCING);
        GOV_INFLOWS_CALENDAR.total_money_financing +=TOTAL_MONEY_FINANCING;

        PAYMENT_ACCOUNT += TOTAL_MONEY_FINANCING;



        if(AUSTERITY_PHASE==2){


			if(FOREIGN_DEBT> 0.0){


				PAYMENT_ACCOUNT -= FOREIGN_DEBT_INSTALLMENT;

				FOREIGN_DEBT -= FOREIGN_DEBT_INSTALLMENT;

				if(AUSTERITY_REPAY_SCENARIO==2  ){


				        SUBSIDY_REPORTED_TO_EUROSTAT += FOREIGN_DEBT_INSTALLMENT;

				}


			}else{


				FOREIGN_DEBT_INSTALLMENT = 0.0;
				AUSTERITY_PHASE = 3;

			}




		}




        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
        {
            printf("\n\n Government_monthly_budget_accounting ID: %d",ID);
            printf("\n\t MONTHLY_TAX_REVENUES: %f MONTHLY_BENEFIT_PAYMENT: %f",MONTHLY_TAX_REVENUES, MONTHLY_BENEFIT_PAYMENT);
            printf("\n\t MONTHLY_BOND_INTEREST_PAYMENT: %f out: %f",MONTHLY_BOND_INTEREST_PAYMENT, out);
            printf("\n\t out: %f MONTHLY_BUDGET_BALANCE: %f",out, MONTHLY_BUDGET_BALANCE);
            printf("\n\t PAYMENT_ACCOUNT: %f CUMULATED_DEFICIT: %f TOTAL_DEBT: %f",PAYMENT_ACCOUNT,CUMULATED_DEFICIT, TOTAL_DEBT);
            
            getchar();
        }
        #endif 
        
        // #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/government_monthly_accounting.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f ",DAY,ID,MONTHLY_TAX_REVENUES,MONTHLY_BENEFIT_PAYMENT);
            fprintf(file1,"%f %f ",MONTHLY_BOND_INTEREST_PAYMENT,out);
            fprintf(file1,"%f %f ",MONTHLY_BUDGET_BALANCE,PAYMENT_ACCOUNT);
            fprintf(file1,"%f %f %d",CUMULATED_DEFICIT,TOTAL_DEBT,REGION_ID);
            fclose(file1);
            free(filename);
        }
        // #endif 

    return 0;
}

/* \fn: int Government_bonds_issuing_decision_dummy()
 * \brief Dummy to replace Government_bonds_issuing_decision.
 */

int Government_bonds_issuing_decision_dummy()
{
        return 0;
}

/* \fn: int Government_monthly_resetting()
 * \brief Monthly resetting of counters.
 */
int Government_monthly_resetting()
{
    //Reset the monthly counters:
    MONTHLY_TAX_REVENUES =0.0;
    MONTHLY_BENEFIT_PAYMENT =0.0;
    MONTHLY_TRANSFER_PAYMENT =0.0;
    MONTHLY_SUBSIDY_PAYMENT =0.0;
    MONTHLY_SUBSIDY_PAYMENT_TO_FIRMS =0.0;
    MONTHLY_SUBSIDY_PAYMENT_TO_HOUSEHOLDS =0.0;
    MONTHLY_BOND_INTEREST_PAYMENT =0.0;
    MONTHLY_INVESTMENT_EXPENDITURE =0.0;
    MONTHLY_CONSUMPTION_EXPENDITURE =0.0;
    ADD_FOREIGN_DEBT = 0.0;
    
    
    GOV_STOCKS_CALENDAR.payment_account_day_1=PAYMENT_ACCOUNT;
    
    GOV_OUTFLOWS_CALENDAR.investment_expenditure=0.0;
    GOV_OUTFLOWS_CALENDAR.consumption_expenditure=0.0;
    GOV_OUTFLOWS_CALENDAR.transfer_payment_household=0.0;
    GOV_OUTFLOWS_CALENDAR.transfer_payment_firm=0.0;
    GOV_OUTFLOWS_CALENDAR.subsidy_payment_household=0.0;
    GOV_OUTFLOWS_CALENDAR.subsidy_payment_firm=0.0;
    GOV_OUTFLOWS_CALENDAR.benefit_payment=0.0;
    GOV_OUTFLOWS_CALENDAR.bond_interest_payment=0.0;
    GOV_OUTFLOWS_CALENDAR.debt_installment=0.0;
    GOV_OUTFLOWS_CALENDAR.total_bond_repurchase=0.0;
    GOV_OUTFLOWS_CALENDAR.total_expenses=0.0;
    
    GOV_INFLOWS_CALENDAR.tax_revenues=0.0;
    GOV_INFLOWS_CALENDAR.restitution_payment=0.0;
    GOV_INFLOWS_CALENDAR.total_bond_financing=0.0;
    GOV_INFLOWS_CALENDAR.total_money_financing=0.0;
    GOV_INFLOWS_CALENDAR.total_income=0.0;
    GOV_INFLOWS_CALENDAR.net_inflow=0.0;
    
    

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_GOV)
    { 
            printf("\n Government_monthly_resetting");
            printf("\n\t MONTHLY_TAX_REVENUES: %f MONTHLY_BENEFIT_PAYMENT: %f",MONTHLY_TAX_REVENUES, MONTHLY_BENEFIT_PAYMENT);
            printf("\n\t MONTHLY_TRANSFER_PAYMENT: %f MONTHLY_SUBSIDY_PAYMENT: %f",MONTHLY_TRANSFER_PAYMENT, MONTHLY_SUBSIDY_PAYMENT);
            printf("\n\t MONTHLY_INVESTMENT_EXPENDITURE: %f MONTHLY_CONSUMPTION_EXPENDITURE: %f",MONTHLY_INVESTMENT_EXPENDITURE, MONTHLY_CONSUMPTION_EXPENDITURE);
            printf("\n\t MONTHLY_BOND_INTEREST_PAYMENT: %f",MONTHLY_BOND_INTEREST_PAYMENT);
    }
    #endif 
        
    return 0;
}

/* \fn: int Government_yearly_budget_accounting()
 * \brief Function to perform accounting at the end of each year.
 */
int Government_yearly_budget_accounting()
{
    double in, out;

    //Compute the following:
   // GOV_INTEREST_RATE = 0.05;
    //GOV_INTEREST_RATE = CB_BASE_RATE;

    //Items that have already been added to the payment_account
        in = YEARLY_TAX_REVENUES;
        YEARLY_INCOME = in;
        
    //Items that have already been subtracted from the payment_account
        out = YEARLY_BENEFIT_PAYMENT +
        YEARLY_TRANSFER_PAYMENT +
		YEARLY_SUBSIDY_PAYMENT +
        YEARLY_BOND_INTEREST_PAYMENT +
        YEARLY_INVESTMENT_EXPENDITURE +
        YEARLY_CONSUMPTION_EXPENDITURE;
        
        YEARLY_EXPENDITURE = out;
        
    //Compute budget deficit
        YEARLY_BUDGET_BALANCE = in - out;

        DEBT_GDP_RATIO =   TOTAL_DEBT/ YEARLY_GDP;

    return 0;
}

/* \fn: int Government_yearly_resetting()
 * \brief Yearly resetting of counters.
 */
int Government_yearly_resetting()
{
    //Reset the yearly counters:
    YEARLY_TAX_REVENUES =0.0;
    YEARLY_BENEFIT_PAYMENT =0.0;
    YEARLY_TRANSFER_PAYMENT =0.0;
    YEARLY_SUBSIDY_PAYMENT =0.0;
    YEARLY_BOND_INTEREST_PAYMENT =0.0;
    YEARLY_INVESTMENT_EXPENDITURE =0.0;
    YEARLY_CONSUMPTION_EXPENDITURE =0.0;

	//Store last year's GDP    
	PREVIOUS_YEAR_GDP = YEARLY_GDP;
	YEARLY_GDP =0.0;

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_GOV)
    { 
	    printf("\n Government_yearly_resetting");       
	    printf("\n\t YEARLY_TAX_REVENUES: %f YEARLY_BENEFIT_PAYMENT: %f",YEARLY_TAX_REVENUES, YEARLY_BENEFIT_PAYMENT);
	    printf("\n\t YEARLY_TRANSFER_PAYMENT: %f YEARLY_SUBSIDY_PAYMENT: %f",YEARLY_TRANSFER_PAYMENT, YEARLY_SUBSIDY_PAYMENT);
            printf("\n\t YEARLY_INVESTMENT_EXPENDITURE: %f YEARLY_CONSUMPTION_EXPENDITURE: %f",YEARLY_INVESTMENT_EXPENDITURE, YEARLY_CONSUMPTION_EXPENDITURE);
            printf("\n\t YEARLY_BOND_INTEREST_PAYMENT: %f",YEARLY_BOND_INTEREST_PAYMENT);

    }
    #endif 
    
    return 0;
}

/* \fn: int Government_read_data_from_Eurostat()
 * \brief Function to read data from Eurostat.
 */
int Government_read_data_from_Eurostat()
{
    int i;

	MONTHLY_GDP=0.0;
    COUNTRY_WIDE_MEAN_WAGE=0.0;


	SUBSIDY_TRANSFER_RECEIVED = 0;


	if(LAST_MONTHLY_GDPS.size ==  GOV_BUDGETING_HORIZON){


		remove_double(&LAST_MONTHLY_GDPS,0);

	}



	START_REDISTRIBUTED_SUBSIDIES_MESSAGE_LOOP
       
	SUBSIDY_TRANSFER_RECEIVED = redistributed_subsidies_message->amount;

	PAYMENT_ACCOUNT += SUBSIDY_TRANSFER_RECEIVED;	

    FINISH_REDISTRIBUTED_SUBSIDIES_MESSAGE_LOOP

    
    START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
        for (i=0; i<NO_REGIONS_PER_GOV; i++)
        {
            if(data_for_government_message->region_id==LIST_OF_REGIONS.array[i])
            {
                //Read region mean wage
                COUNTRY_WIDE_MEAN_WAGE += data_for_government_message->mean_wage;

                //Read region GDP
                MONTHLY_GDP += data_for_government_message->gdp;

                UNEMPLOYMENT_RATE = data_for_government_message->unemployment_rate;

                add_double(&CONSUMPTION_BUDGETS_PER_CAPITA, data_for_government_message->consumption_budget_per_capita);

                add_double(&CONSUMPTION_QUOTAS_REL_TO_REG1,data_for_government_message->consumption_quota);

            }
        }
    FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
    
    //Set country-wide mean wage as avg of region's mean wages
    if(NO_REGIONS_PER_GOV>0)
        COUNTRY_WIDE_MEAN_WAGE = COUNTRY_WIDE_MEAN_WAGE/NO_REGIONS_PER_GOV;
    else
        printf("\n Please set constant NO_REGIONS_PER_GOV>0, now NO_REGIONS_PER_GOV = %d\n", NO_REGIONS_PER_GOV);
                
	//Update the yearly GDP with the monthly value:
	YEARLY_GDP += MONTHLY_GDP;


	add_double(&LAST_MONTHLY_GDPS, MONTHLY_GDP);

    //Compute annual GDP growth rate only once a year (retains its value during the year):
    if ((DAY%240)==1)
    {
	    if (PREVIOUS_YEAR_GDP > 0.0)
	        GDP_GROWTH = (YEARLY_GDP/PREVIOUS_YEAR_GDP) -1;
	    else GDP_GROWTH = 0.0; 
	}

    #ifdef _DEBUG_MODE        
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Government_read_data_from_Eurostat ID: %d",ID);
        printf("\n\t YEARLY_GDP: %f PREVIOUS_YEAR_GDP: %f",YEARLY_GDP, PREVIOUS_YEAR_GDP);
        getchar();
    }
    #endif 
        
    //Set GDP as percentage of the deficit:
    if(MONTHLY_GDP>0.0)
    {
        MONTHLY_BUDGET_BALANCE_GDP_FRACTION = MONTHLY_BUDGET_BALANCE/MONTHLY_GDP;
    }
    else 
        MONTHLY_BUDGET_BALANCE_GDP_FRACTION=0.0;

    if(YEARLY_GDP>0.0)
    {
        YEARLY_BUDGET_BALANCE_GDP_FRACTION = YEARLY_BUDGET_BALANCE/YEARLY_GDP;
    }
    else 
        YEARLY_BUDGET_BALANCE_GDP_FRACTION=0.0;

	//If it is the start of the year, reset yearly GDP
	//See yearly resetting, which runs after this function
/*
    if ((DAY%240)==1)
    {
		YEARLY_GDP=0.0;
	}
 */
       
    //Now read the global economic data to retrieve the economy-wide inflation and unemployment rates:    
    START_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP    
        INFLATION_RATE = eurostat_send_macrodata_message->inflation;
    FINISH_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP
    
    return 0;   
}



int Government_send_data_to_Eurostat()
{






   //Conditions for migration effect: migration_experiment = true, current iteration is indicated one, and migration only applied in region 1



	add_government_send_data_message(ID, REGION_ID, MONTHLY_CONSUMPTION_EXPENDITURE );
    return 0;
}

/* \fn: int Government_set_policy()
 * \brief Function to set policy rules: income forecast and expenditure budget.
 */
int Government_set_policy()
{   
    FILE *file1=NULL;
    char *filename=NULL;

//    double yearly_tax_revenues_target; 
/*     
    //Fiscal policy rule 1

        //increase tax rates when in debt
        if(PAYMENT_ACCOUNT<0)
        {
            TAX_RATE_CORPORATE  += 0.01;
            TAX_RATE_HH_LABOUR  += 0.01; 
            TAX_RATE_HH_CAPITAL += 0.01;
        }
        else if(PAYMENT_ACCOUNT>1000)
        {
            //decrease tax rates when in surplus
            TAX_RATE_CORPORATE  -= 0.01;
            TAX_RATE_HH_LABOUR  -= 0.01; 
            TAX_RATE_HH_CAPITAL -= 0.01;
        }
*/
        //Fiscal policy rule 2
/*
        //increase tax rates when GDP growth > 0.05
        if(GDP_GROWTH>0.05)
        {
            TAX_RATE_CORPORATE  += 0.01;
            TAX_RATE_HH_LABOUR  += 0.01; 
            TAX_RATE_HH_CAPITAL += 0.01;
        }
        else if(GDP_GROWTH<0.01)
        {
            //decrease tax rates when GDP growth < 0.01
            TAX_RATE_CORPORATE  -= 0.01;
            TAX_RATE_HH_LABOUR  -= 0.01; 
            TAX_RATE_HH_CAPITAL -= 0.01;
        }



*/
    





    //Set GDP forecast equal to extrapolation of previous growth rate*GDP
    GDP_FORECAST = (1+GDP_GROWTH)*YEARLY_GDP;
    
    //Set income forecast
    YEARLY_INCOME_FORECAST = (1+GDP_GROWTH)*YEARLY_INCOME;

    //Set expenditure forecast: counter-cyclical to gdp growth
    YEARLY_EXPENDITURE_BUDGET = (1+GDP_GROWTH)*YEARLY_EXPENDITURE;
    
    BUDGET_BALANCE_FORECAST = YEARLY_INCOME_FORECAST - YEARLY_EXPENDITURE_BUDGET;
    
    //Set the following policies:

    //Determine new government consumption
     //YEARLY_CONSUMPTION_BUDGET = GOV_POLICY_GDP_FRACTION_CONSUMPTION * GDP_FORECAST;
     //MONTHLY_CONSUMPTION_BUDGET = YEARLY_CONSUMPTION_BUDGET/12;
     
    //Determine new government investment
     YEARLY_INVESTMENT_BUDGET = GOV_POLICY_GDP_FRACTION_INVESTMENT * GDP_FORECAST;
     MONTHLY_INVESTMENT_BUDGET = YEARLY_INVESTMENT_BUDGET/12;

 /*   if ((POLICY_EXP1)&&(GOV_POLICY_SWITCH_QUANTITATIVE_EASING==0))
    {                   
                
        if ( (YEARLY_BUDGET_BALANCE+PAYMENT_ACCOUNT)>0)
        {
             TAX_RATE_HH_LABOUR = TAX_RATE_HH_LABOUR - 0.05;
             TAX_RATE_CORPORATE = TAX_RATE_CORPORATE - 0.05;
             }
             else
        {
             TAX_RATE_HH_LABOUR = TAX_RATE_HH_LABOUR + 0.05;
             TAX_RATE_CORPORATE = TAX_RATE_CORPORATE + 0.05;
             }
        if (TAX_RATE_HH_LABOUR<0.05) TAX_RATE_HH_LABOUR = 0.05;
        if (TAX_RATE_CORPORATE<0.05) TAX_RATE_CORPORATE = 0.05;
      } 
*/
    
	if (PRINT_DEBUG_FILE_EXP1)
    {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Government_policies.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"%d %d %f %f\n",DAY,ID,TAX_RATE_HH_LABOUR,TAX_RATE_CORPORATE);
            fclose(file1);
            free(filename);
	}
           
    return 0;
}
