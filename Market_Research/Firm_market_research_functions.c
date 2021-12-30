#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
/* This auxiliry function is called by *** function. It is used to 
	calculate the probability of the price quality combinitation of the good chosen by 
	a household in the survey. beta_p and beta_q are the coefficients of the logit model that are numerically estimated.
*/
double Firm_logit_model(double beta_p, double beta_q, int choice)
{

	int i;
	double probability,denominator;

	denominator = 0.0;
	// Compute the denominator length of static array PRICE_QUALITY_INNO is 12!
	for(i=0; i< 12 ;i++)
	{

		denominator +=  exp(beta_q*log(PRICE_QUALITY_INNO[i].quality) + beta_p*log(PRICE_QUALITY_INNO[i].price));

	}

	// Compute the probability
	probability = exp(beta_q*log(PRICE_QUALITY_INNO[choice].quality)+ beta_p*log(PRICE_QUALITY_INNO[choice].price))/denominator;

	return probability;	
	
}




void Firm_price_increment(price_quality_pair_array * quality_price_competitor){


for(int i=0; i < (* quality_price_competitor).size;i++){



	if(random_unif() < (1.0/12.0) && abs((* quality_price_competitor).array[i].price - QUALITY_PRICE_COMPETITORS.array[i].price)){


		(* quality_price_competitor).array[i].price  = (* quality_price_competitor).array[i].price *(1+VARIABLES_CHANGE.price_index);


	}

	
}
	
	
}



double Firm_compute_regional_market_share_aux_function(int region_id, int time, double candidate_price, price_quality_pair_array * quality_price_competitor){


	double market_share = 0;


	double monthly_inflation_rate =  pow(1+VARIABLES_CHANGE.price_index,1/12.0)-1;

	//double monthly_inflation_rate =  0;
	
	double denominator = 0.0;
	
	for(int j=0; j< (* quality_price_competitor).size; j++)
	{

		//denominator += exp(ESTIMATED_COEFFICIENTS.price*log(pow(1+monthly_inflation_rate,time)*QUALITY_PRICE_COMPETITORS.array[j].price) + ESTIMATED_COEFFICIENTS.quality*log(QUALITY_PRICE_COMPETITORS.array[j].quality));

		if(region_id == (* quality_price_competitor).array[j].region_id)
			denominator += exp(ESTIMATED_COEFFICIENTS.price*log(pow(1+monthly_inflation_rate,time)*(* quality_price_competitor).array[j].price) + ESTIMATED_COEFFICIENTS.quality*log(2));
		else
			denominator += exp(ESTIMATED_COEFFICIENTS.price*log(pow(1+monthly_inflation_rate,time)*(* quality_price_competitor).array[j].price) + ESTIMATED_COEFFICIENTS.quality*log(1));
	}


	if(region_id == REGION_ID)
		market_share =  exp(ESTIMATED_COEFFICIENTS.price*log(candidate_price) + ESTIMATED_COEFFICIENTS.quality*log(2))/(exp(ESTIMATED_COEFFICIENTS.price*log(candidate_price) + ESTIMATED_COEFFICIENTS.quality*log(2))+ denominator);
	else
		market_share =  exp(ESTIMATED_COEFFICIENTS.price*log(candidate_price) + ESTIMATED_COEFFICIENTS.quality*log(1))/(exp(ESTIMATED_COEFFICIENTS.price*log(candidate_price) + ESTIMATED_COEFFICIENTS.quality*log(1))+ denominator);


	return market_share;



}




/** \fn Firm_draw_sample
 */
int Firm_set_market_research_data_pricing()
{

	int i,j,no_considered_prices;


	//Compute yearly growth rates of price index and quality index


	//1. Price index
	if(VARIABLES_LAST_YEAR.array[0].price_index>1e-5)
	{
		VARIABLES_CHANGE.price_index = (CURRENT_PRICE_INDEX - VARIABLES_LAST_YEAR.array[0].price_index)/VARIABLES_LAST_YEAR.array[0].price_index;
	}else{
		VARIABLES_CHANGE.price_index=0.0;
	}
	//2. Quality Index
	if(VARIABLES_LAST_YEAR.array[0].quality_index>1e-5)
	{
		VARIABLES_CHANGE.quality_index = (CURRENT_QUALITY_INDEX - VARIABLES_LAST_YEAR.array[0].quality_index)/VARIABLES_LAST_YEAR.array[0].quality_index;
	}else{
		VARIABLES_CHANGE.quality_index=0.0;
	}
	
	//5. Productivity Progress
	VARIABLES_CHANGE.productivity_progress=0;


	for(i =0; i<VARIABLES_LAST_YEAR.size; i++ )
	{
		
		VARIABLES_CHANGE.productivity_progress+=VARIABLES_LAST_YEAR.array[i].productivity_progress;
	
	}
	if(VARIABLES_LAST_YEAR.size>0)
	{
		  VARIABLES_CHANGE.productivity_progress=VARIABLES_CHANGE.productivity_progress/VARIABLES_LAST_YEAR.size;
	}

	


	//1. Price index
	if(VARIABLES_LAST_YEAR.array[0].price_index>1e-5)
	{
		VARIABLES_CHANGE.price_index = (CURRENT_PRICE_INDEX - VARIABLES_LAST_YEAR.array[0].price_index)/VARIABLES_LAST_YEAR.array[0].price_index;
	}else{
		VARIABLES_CHANGE.price_index=0.0;
	}
	//2. Quality Index
	if(VARIABLES_LAST_YEAR.array[0].quality_index>1e-5)
	{
		VARIABLES_CHANGE.quality_index = (CURRENT_QUALITY_INDEX - VARIABLES_LAST_YEAR.array[0].quality_index)/VARIABLES_LAST_YEAR.array[0].quality_index;
	}else{
		VARIABLES_CHANGE.quality_index=0.0;
	}
	
	//5. Productivity Progress
	VARIABLES_CHANGE.productivity_progress=0;


	for(i =0; i<VARIABLES_LAST_YEAR.size; i++ )
	{
		
		VARIABLES_CHANGE.productivity_progress+=VARIABLES_LAST_YEAR.array[i].productivity_progress;

	}
	if(VARIABLES_LAST_YEAR.size>0)
	{
		  VARIABLES_CHANGE.productivity_progress=VARIABLES_CHANGE.productivity_progress/VARIABLES_LAST_YEAR.size;
	}

	
	   
   	double regressor;
   	double intercept;
   	double variance;
	double sum_1, sum_2;

for(i=0;i<LAST_MARKET_SIZES.size;i++)
{
    if(LAST_MARKET_SIZES.array[i].market_sizes.size>5)
	{

		 sum_1=0;
    	 sum_2=0;
		 variance=0.0;

    	for (j=0;j<LAST_MARKET_SIZES.array[i].market_sizes.size; j++)
    	    	{
    	    	sum_1+= (LAST_MARKET_SIZES.array[i].market_sizes.size + 1 - LAST_MARKET_SIZES.array[i].market_sizes.array[j].period)* LAST_MARKET_SIZES.array[i].market_sizes.array[j].market_size;

    	    	sum_2+=  LAST_MARKET_SIZES.array[i].market_sizes.array[j].market_size;


    	    	}


    	regressor = (LAST_MARKET_SIZES.array[i].market_sizes.size * sum_1 - 0.5*LAST_MARKET_SIZES.array[i].market_sizes.size*(LAST_MARKET_SIZES.array[i].market_sizes.size+1)*sum_2)/
        		(1/6.0*pow(LAST_MARKET_SIZES.array[i].market_sizes.size,2)*(LAST_MARKET_SIZES.array[i].market_sizes.size+1)*
        		(2*LAST_MARKET_SIZES.array[i].market_sizes.size+1)-1/4.0*(pow(LAST_MARKET_SIZES.array[i].market_sizes.size,2)*pow((LAST_MARKET_SIZES.array[i].market_sizes.size+1),2)));

    	intercept =  1/(1.0*LAST_MARKET_SIZES.array[i].market_sizes.size)*sum_2 - 0.5*regressor*(LAST_MARKET_SIZES.array[i].market_sizes.size+1);

    	variance = 0;

    	for(j=0; j< LAST_MARKET_SIZES.array[i].market_sizes.size; j++)
    	  {
    		 variance+= pow(LAST_MARKET_SIZES.array[i].market_sizes.array[j].market_size-(intercept+
    				 (LAST_MARKET_SIZES.array[i].market_sizes.size + 1 - LAST_MARKET_SIZES.array[i].market_sizes.array[j].period)* regressor),2)
    				  /(LAST_MARKET_SIZES.array[i].market_sizes.size-1);
    	  }

    	LINEAR_REGRESSION_MARKET_SIZE.array[i].mall_id=LAST_MARKET_SIZES.array[i].mall_id;
		LINEAR_REGRESSION_MARKET_SIZE.array[i].region_id=LAST_MARKET_SIZES.array[i].region_id;
    	LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept=intercept;
	if(regressor < 0)
	{
		LINEAR_REGRESSION_MARKET_SIZE.array[i].regressor=regressor;
	}else
	{
		LINEAR_REGRESSION_MARKET_SIZE.array[i].regressor=regressor;
	}


    	LINEAR_REGRESSION_MARKET_SIZE.array[i].variance=variance;

	}else
	{

		LINEAR_REGRESSION_MARKET_SIZE.array[i].mall_id=LAST_MARKET_SIZES.array[i].region_id;
		if(LAST_MARKET_SIZES.array[i].market_sizes.size==0)
		{
    		LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept=1800.0;
		}else
		{
			LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept=0.0;
			for(j=0;j<LAST_MARKET_SIZES.array[i].market_sizes.size;j++)
			{
				LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept+= LAST_MARKET_SIZES.array[i].market_sizes.array[j].market_size;
			}
			LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept= LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept/LAST_MARKET_SIZES.array[i].market_sizes.size;
			LINEAR_REGRESSION_MARKET_SIZE.array[i].mall_id=LAST_MARKET_SIZES.array[i].mall_id;
			LINEAR_REGRESSION_MARKET_SIZE.array[i].region_id=LAST_MARKET_SIZES.array[i].region_id;

		}
    	LINEAR_REGRESSION_MARKET_SIZE.array[i].regressor=0.0;
    	LINEAR_REGRESSION_MARKET_SIZE.array[i].variance=0.0;

	}
}
//Estimation of current market size based the linear regression
ESTIMATED_MARKET_SIZE  = LINEAR_REGRESSION_MARKET_SIZE.array[0].intercept + (1+LAST_MARKET_SIZES.array[0].market_sizes.size)*LINEAR_REGRESSION_MARKET_SIZE.array[0].regressor;

	

//Save price and price index in memory
PRICE_INDEX_AT_QUESTIONNAIRE = CURRENT_PRICE_INDEX;
PRICE_AT_QUESTIONNAIRE = PRICE;


//Reset the sample size counter

ACTUAL_SAMPLE_SIZE = 0;




		PRICE_RANGE_PRICING.start_price =  MR_START_PRICE;
		PRICE_RANGE_PRICING.end_price = MR_END_PRICE;
		PRICE_RANGE_PRICING.increment = MR_PRICE_INCREMENT;



		if(PERIODS_OUTPUT_ZERO_COUNTER >12 && DAY > 480)
			PRICE_AT_QUESTIONNAIRE = CURRENT_PRICE_INDEX;




double no_cp=  (PRICE_RANGE_PRICING.end_price - PRICE_RANGE_PRICING.start_price)/ PRICE_RANGE_PRICING.increment;

no_considered_prices = (int) no_cp;


	//delete the Market research array:





	for(i=MARKET_RESEARCH_DATA_PRICING.size-1;i>=0;i--)
	{

	remove_dt_market_research_price(&MARKET_RESEARCH_DATA_PRICING,i);

	}
	
	for(i=0; i<no_considered_prices;i++)
	{
		add_dt_market_research_price(&MARKET_RESEARCH_DATA_PRICING,(PRICE_RANGE_PRICING.start_price + i * PRICE_RANGE_PRICING.increment)-1, PRICE_AT_QUESTIONNAIRE*(PRICE_RANGE_PRICING.start_price + i * PRICE_RANGE_PRICING.increment),0);


		add_estimated_values_adt(&(MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values),0,0,0,0,0,0,0,0,0);



	}



	//Print debug:
	#ifdef _DEBUG_MODE    
   	if (PRINT_DEBUG_MARKET_RESEARCH)
	{
   		if(ID==ID_DEBUG_PROBE)
		{
   			printf("\n Firm_set_market_research_data():\n ");
			for(i=0; i<LAST_MARKET_SIZES.array[0].market_sizes.size;i++ )
			{
				printf("%d \t %f \n",LAST_MARKET_SIZES.array[0].market_sizes.array[i].period,LAST_MARKET_SIZES.array[0].market_sizes.array[i].market_size);
			}

		}	
	}
	#endif

	
	

	//Set the price and quality douples pairs by hand:





		PRICE_QUALITY_INNO[0].price= 0.90*PRICE_LAST_MONTH;     PRICE_QUALITY_INNO[0].quality=2;    	PRICE_QUALITY_INNO[0].region_id =1;
		PRICE_QUALITY_INNO[1].price= 0.90*PRICE_LAST_MONTH;     PRICE_QUALITY_INNO[1].quality= 1 ;		PRICE_QUALITY_INNO[1].region_id =2;

		PRICE_QUALITY_INNO[2].price= 0.95*PRICE_LAST_MONTH;     PRICE_QUALITY_INNO[2].quality=2;        PRICE_QUALITY_INNO[2].region_id =1;
		PRICE_QUALITY_INNO[3].price= 0.95*PRICE_LAST_MONTH;     PRICE_QUALITY_INNO[3].quality= 1;		PRICE_QUALITY_INNO[3].region_id =2;


		PRICE_QUALITY_INNO[4].price= PRICE_LAST_MONTH;    		 PRICE_QUALITY_INNO[4].quality=2;    	PRICE_QUALITY_INNO[4].region_id =1;
		PRICE_QUALITY_INNO[5].price= PRICE_LAST_MONTH;    		 PRICE_QUALITY_INNO[5].quality=1;		PRICE_QUALITY_INNO[5].region_id =2;


		PRICE_QUALITY_INNO[6].price= 1.05*PRICE_LAST_MONTH;      PRICE_QUALITY_INNO[6].quality=2; 		PRICE_QUALITY_INNO[6].region_id =1;
		PRICE_QUALITY_INNO[7].price= 1.05*PRICE_LAST_MONTH;      PRICE_QUALITY_INNO[7].quality=1;		PRICE_QUALITY_INNO[7].region_id =2;


		PRICE_QUALITY_INNO[8].price= 1.1*PRICE_LAST_MONTH	;     PRICE_QUALITY_INNO[8].quality=2;		PRICE_QUALITY_INNO[8].region_id =1;
		PRICE_QUALITY_INNO[9].price= 1.1*PRICE_LAST_MONTH	;     PRICE_QUALITY_INNO[9].quality=1;		PRICE_QUALITY_INNO[9].region_id =2;


		PRICE_QUALITY_INNO[10].price= 1.15*PRICE_LAST_MONTH	;     PRICE_QUALITY_INNO[10].quality=2;		PRICE_QUALITY_INNO[10].region_id =1;
		PRICE_QUALITY_INNO[11].price= 1.15*PRICE_LAST_MONTH	;     PRICE_QUALITY_INNO[11].quality=1;		PRICE_QUALITY_INNO[11].region_id =2;


	
	return 0;
}


int Firm_set_market_research_data_innovation()
{

	

return 0;
}




int Firm_bypass_setting_if_delayed()
{

	MARKET_RESEARCH_DELAYED =0;

return 0;
}


/** \fn Firm_release_new_product
 */
int Firm_release_new_product()
{



	return 0;
	
	
	
} 
/** \fn Firm_draw_sample
 */
int Firm_draw_sample()
{

	add_interview_request_message(ID);
	
	return 0;
	
	
	
} 

/** \fn Firm_send_questionnaire
 */
int Firm_send_questionnaire()
{
	
	//Read response:
	
	START_INTERVIEW_POSITIVE_RESPONSE_MESSAGE_LOOP
	
		
		ACTUAL_SAMPLE_SIZE++;
		
		
	FINISH_INTERVIEW_POSITIVE_RESPONSE_MESSAGE_LOOP	
	
	
	

	
	//Send message for pricing:
	//add_questionnaire_pricing_message(ID,PRICE_RANGE_PRICING.start_price*PRICE,no_considered_prices_pricing,PRICE_RANGE_PRICING.increment*PRICE,QUALITY,VARIABLES_CHANGE.price_index,VARIABLES_CHANGE.quality_index,MARKET_RESEARCH_DATA_PRICING.array[0].estimated_values.size);	
	
		add_questionnaire_innovation_message(ID,PRICE_QUALITY_INNO);


	if(ACTUAL_SAMPLE_SIZE<MARKET_RESEARCH_SAMPLE_SIZE)
	{
		DAY_OF_YEAR_MARKET_RESEARCH = (DAY_OF_YEAR_MARKET_RESEARCH +1)%240; 
		MARKET_RESEARCH_DELAYED = 1;
		MARKET_RESEARCH_ACTIVE=0;

	}else
	{
		MARKET_RESEARCH_ACTIVE=1;
	}
	

	#ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_MARKET_RESEARCH)
    {
		  if(ID==ID_DEBUG_PROBE)
            {
		        printf("\n\n IT %d Firm_send_questionnaire() ID: %d",DAY, ID);
				printf("\n MARKET_RESEARCH_SAMPLE_SIZE %d	ACTUAL_SAMPLE_SIZE %d",MARKET_RESEARCH_SAMPLE_SIZE,ACTUAL_SAMPLE_SIZE);

	
		}

    }
    #endif
	
	return 0;
}



int Firm_count_questionnaire()
{


	int i;

	// reseting of the counters
	for(i=0; i < 12; i++)
	{

		PRICE_QUALITY_COUNTS[i]=0;

	}
	
	START_FILLED_OUT_QUESTIONNAIRE_PRODUCT_INNOVATION_MESSAGE_LOOP

	// Increment the quality price combination chosen by the household:
	PRICE_QUALITY_COUNTS[filled_out_questionnaire_product_innovation_message->choice]++;

	FINISH_FILLED_OUT_QUESTIONNAIRE_PRODUCT_INNOVATION_MESSAGE_LOOP


	return 0;
}


int Firm_analyze_questionnaire()
{

	int i,j,k,l;



	double beta_p, beta_q;
	

	/*Estimation of the logit parameters: numerical approximation with Newton-Raphson method*/

	
	// Define starting values

	beta_p =0.5;    
	beta_q = 0.5;

	//Define test variable for convergence: if the change from one to nest step is < conv then we have convergence

	
	double coefficient_vactor[2];

	coefficient_vactor[0]=beta_p;
	coefficient_vactor[1]=beta_q;

	for(i=0; i< 1000; i++)
	{

	// Deterimine the gradiant vecor

	double gradiant[2];


		gradiant[0]=0.0;
		gradiant[1]=0.0;

		for(k=0; k<12; k++)
		{

			double sum_1 = 0.0;
			double sum_2 = 0.0;
			for(l=0; l<12; l++)
			{

				if(k==l)
				{
					sum_1 += (log(PRICE_QUALITY_INNO[l].price)*(1-  Firm_logit_model(coefficient_vactor[0], coefficient_vactor[1],l)));
					sum_2 += (log(PRICE_QUALITY_INNO[l].quality)*(1-  Firm_logit_model(coefficient_vactor[0], coefficient_vactor[1],l)));
				
				}else
				{
					sum_1 += (log(PRICE_QUALITY_INNO[l].price)*(0-  Firm_logit_model(coefficient_vactor[0], coefficient_vactor[1],l)));
					sum_2 += (log(PRICE_QUALITY_INNO[l].quality)*(0-  Firm_logit_model(coefficient_vactor[0], coefficient_vactor[1],l)));
				}
			
				//printf("prob %f  l %d coef 1 %f  coef 2 %f\n", Firm_logit_model(coefficient_vactor[0], coefficient_vactor[1],l),l,coefficient_vactor[0],coefficient_vactor[1]);
			}
			
			//printf("sum_1: %f   sum_2: %f PRICE_QUALITY_COUNTS[k] %d  Price %f   Quality %f\n ",sum_1, sum_2,PRICE_QUALITY_COUNTS[k],PRICE_QUALITY_INNO[k].price,PRICE_QUALITY_INNO[k].quality);

			gradiant[0]+=  PRICE_QUALITY_COUNTS[k]* sum_1; 
			gradiant[1]+=  PRICE_QUALITY_COUNTS[k]* sum_2; 
		}



	//printf("gradient 1: %f   gradient 2 : %f \n ",gradiant[0], gradiant[1]);

	// Determine hessian matrix

	double hessian[2][2];
	double hessian_inv[2][2];

	
	double sum[2];

	sum[0]= 0.0;
	sum[1]= 0.0;
	// Compute sum of probability * coefficient
	for(j=0; j< 12; j++)
	{

		double prob = Firm_logit_model(coefficient_vactor[0], coefficient_vactor[1],j);
		sum[0] += log(PRICE_QUALITY_INNO[j].price)* prob;
		sum[1] += log(PRICE_QUALITY_INNO[j].quality)* prob;
	
	}

	//printf("sum[0] %f  sum[1]  %f\n",sum[0],sum[1]);



			hessian[0][0]=0;
			hessian[1][0]=0;	
			hessian[0][1]=0;
			hessian[1][1]=0;


			for(k=0; k<12; k++)
			{
				double sum_11=0.0;
				double sum_22=0.0;
				double sum_12=0.0;
				double sum_21=0.0;

				for(l=0; l<12; l++)
				{
					double prob = Firm_logit_model(coefficient_vactor[0], coefficient_vactor[1],l);

					sum_11 += (-1)*prob*(log(PRICE_QUALITY_INNO[l].price)-sum[0])*(log(PRICE_QUALITY_INNO[l].price));
					sum_22 += (-1)*prob*(log(PRICE_QUALITY_INNO[l].quality)-sum[1])*(log(PRICE_QUALITY_INNO[l].quality));

					sum_12 += (-1)*prob*(log(PRICE_QUALITY_INNO[l].price)-sum[0])*(log(PRICE_QUALITY_INNO[l].quality));
					sum_21 += (-1)*prob*(log(PRICE_QUALITY_INNO[l].quality)-sum[1])*(log(PRICE_QUALITY_INNO[l].price));

				}
				
				hessian[0][0] += PRICE_QUALITY_COUNTS[k]*sum_11;
				hessian[1][1] += PRICE_QUALITY_COUNTS[k]* sum_22;
				hessian[0][1] += PRICE_QUALITY_COUNTS[k]*sum_12;
				hessian[1][0] += PRICE_QUALITY_COUNTS[k]*sum_21;
			}
		
	// Inverting of hessian:

	double determinant = hessian[0][0]*hessian[1][1] - hessian[0][1]*hessian[1][0];

	hessian_inv[0][0] = (1/determinant)*hessian[1][1]; 
	hessian_inv[1][1] = (1/determinant)*hessian[0][0]; 

	hessian_inv[0][1] = (-1)*(1/determinant)*hessian[0][1]; 
	hessian_inv[1][0] = (-1)*(1/determinant)*hessian[1][0]; 

	//printf("ID: %d determinant %f \n",ID, determinant);



	//printf("hessian_inv[1][1]  %f hessian_inv[1][2] %f \n ",hessian_inv[0][0], hessian_inv[0][1]);
	//printf("hessian_inv[2][1]  %f hessian_inv[2][2] %f \n ",hessian_inv[1][0], hessian_inv[1][1]);

	//Next iteration:

	double coef_old[2];
	for(j=0; j<2; j++)
	{
			coef_old[j]	= coefficient_vactor[j];
			coefficient_vactor[j] = 	coefficient_vactor[j] - (hessian_inv[j][0] *   gradiant[0] + hessian_inv[j][1] *   gradiant[1]); 	
				
	}

	//printf("\n beta_p: %f    beta_q: %f \n", coefficient_vactor[0], coefficient_vactor[1]);

	// test of convergence: If  cc = t(G)*(-Hâ�»1)*G < eps -> convergence (see Train(2009))
	
	double eps = 0.00001;
	double cc;

	cc = gradiant[0]* (-1)*(hessian_inv[0][0]*gradiant[0] + hessian_inv[0][1]*gradiant[1]) - (gradiant[1]*(hessian_inv[1][0]*gradiant[0] + hessian_inv[1][1]*gradiant[1]));
	

		if(cc < eps)
		{
		//	printf("cc = %f < eps = %f \n",cc,eps);
		//	printf("Convergence reached after %d iterations\n",i);
			break;
		}
	}


	printf("\nID %d Estimated coefficients beta_p: %f    beta_q: %f \n",ID, coefficient_vactor[0], coefficient_vactor[1]);



		ESTIMATED_COEFFICIENTS.quality = coefficient_vactor[1];
		ESTIMATED_COEFFICIENTS.price = coefficient_vactor[0];

		ESTIMATED_VARIANCE_MARKET_SHARE = 0.0;

		double denominator = 0.0;		
		/*determine denominator of logit*/
		for(i=0; i<12; i++)
		{
		
			denominator += exp(ESTIMATED_COEFFICIENTS.price*log(PRICE_QUALITY_INNO[i].price)  +   ESTIMATED_COEFFICIENTS.quality*log(PRICE_QUALITY_INNO[i].quality ));

		}


		for(i=0; i<12; i++)
		{
		
			ESTIMATED_VARIANCE_MARKET_SHARE += pow(exp(ESTIMATED_COEFFICIENTS.price*log(PRICE_QUALITY_INNO[i].price )  +   ESTIMATED_COEFFICIENTS.quality*log(PRICE_QUALITY_INNO[i].quality) )/denominator    -PRICE_QUALITY_COUNTS[i]/(1.0*ACTUAL_SAMPLE_SIZE) , 2);

		}

		ESTIMATED_VARIANCE_MARKET_SHARE = ESTIMATED_VARIANCE_MARKET_SHARE / 11.0;


		MARKET_RESEARCH_ACTIVE =0;


return 0;

}


int Firm_prepone_vintage_choice()
{

		int i,j;
		

		  //Clean the array of vintages
		  for(i=TECHNOLOGY_VINTAGES.size-1; i>=0;i--)
		{
		remove_adt_technology_vintages(&TECHNOLOGY_VINTAGES,i);
		}

	   	 /*Getting information about the offered vintages*/
	        START_PRODUCTIVITY_MESSAGE_LOOP

	         //printf("productivity_message->cap_productivity  %f, \n productivity_message->cap_good_price %f \n",productivity_message->cap_productivity,productivity_message->cap_good_price );
			add_adt_technology_vintages(&TECHNOLOGY_VINTAGES,productivity_message->cap_productivity, productivity_message->cap_good_price,0.0);


	        FINISH_PRODUCTIVITY_MESSAGE_LOOP


		 TECHNOLOGICAL_FRONTIER = TECHNOLOGY_VINTAGES.array[TECHNOLOGY_VINTAGES.size-1].productivity;
	     ACTUAL_CAP_PRICE = TECHNOLOGY_VINTAGES.array[TECHNOLOGY_VINTAGES.size-1].price;


		double sum_eff_productivites[TECHNOLOGY_VINTAGES.size];
		double productivity_price_ratio[TECHNOLOGY_VINTAGES.size];
		
		double specific_skills;

		for(i=0;i<TECHNOLOGY_VINTAGES.size;i++)
			{


			/* ...the sum of discounted effective productivities. This means the min of the productivity of the capital good and the mean specific skills where the later converges to the A_i,t */

			specific_skills = MEAN_SPECIFIC_SKILLS;
			sum_eff_productivites[i] = 0;		
			
			for(j=0;j<PLANNING_HORIZON_VINTAGE_CHOICE;j++)
				{
					if(SKILL_UPDATE_ACC_TO_FORMULA==1)
					{
      					/*Update the specific skill: depends on the actual specific skill, 
        				the gap between the actual specific skills and the actual productivity of the employer,
        				and the general skill which determines the speed of closing the this gap.*/
       					specific_skills = max(specific_skills, specific_skills+ 
					(TECHNOLOGY_VINTAGES.array[i].productivity-specific_skills)
					*((1-pow(0.5,1/(20+0.25*(AVERAGE_G_SKILL-1)*(4-20))))));
					}else
					{
	 				 /*Update the specific skill: depends on the actual specific skill, 
       					 the gap between the actual specific skills and the actual productivity of
					 the employer. The rate is predetermined.*/

					
      				specific_skills = max(specific_skills, specific_skills+ (TECHNOLOGY_VINTAGES.array[i].productivity-specific_skills)		     
					*AVERAGE_ADAPTATION_SPEED_SPECIFIC_SKILLS);

					
					}
				
				sum_eff_productivites[i]+= pow(1/(1+DISCONT_RATE),j)*
					min(TECHNOLOGY_VINTAGES.array[i].productivity,specific_skills); 
				}

				/* If subsidies for best vintage are switched on: reduce the effective price
				 for best practice technology*/				

					productivity_price_ratio[i]= sum_eff_productivites[i]/ (price_of_vintage(i, INVESTMENT_SUBSIDY_TYPE, TECHNOLOGY_VINTAGES , SUBSIDY_PCT,TECHNOLOGICAL_FRONTIER));
					TECHNOLOGY_VINTAGES.array[i].sum_effective_productivities = sum_eff_productivites[i];


			}

			/*A Logit model used for vintage choice*/
			
			double sum=0;
			double logit_vintage[TECHNOLOGY_VINTAGES.size];
				
			if(DAY>=TRANSITION_PHASE)
			{
				/*Summing for logit denominator*/
				for(i=0; i<TECHNOLOGY_VINTAGES.size;i++)
				{
					sum += exp(GAMMA_LOGIT_VINTAGE_CHOICE*log(productivity_price_ratio[i]));
				}

				/*Computing the logits*/
				for(i=0; i<TECHNOLOGY_VINTAGES.size;i++)
				{
					logit_vintage[i]= exp(GAMMA_LOGIT_VINTAGE_CHOICE*log(productivity_price_ratio[i]))/sum;
				}
			

				/*random generator and selection of logit*/

				double rnd_number = (double)random_int(0,100)/100.0;

				for(i=0; i<TECHNOLOGY_VINTAGES.size;i++)
				{	
					if(rnd_number<logit_vintage[i])
					{
						VINTAGE_SELECTED = i;
						break;
					}else
					{
						if(i<TECHNOLOGY_VINTAGES.size-1)
							logit_vintage[i+1]+=logit_vintage[i];
					}
	
				}
			
			}else
			{
				/*Ensure that in the transition phase the firm does only buy the already bought vintage */
				if(CAPITAL_STOCK_VINTAGES.size==1)
				{
					for(i=0; i <TECHNOLOGY_VINTAGES.size;i++)
					{
						if(abs_double(TECHNOLOGY_VINTAGES.array[i].productivity-CAPITAL_STOCK_VINTAGES.array[0].productivity)<1e-5)
						{
							VINTAGE_SELECTED = i;
							break;
						}

					}
				}
			}

		VINTAGE_CHOICE_ALREADY_TAKEN = 1;
		VINTAGE_CHOICE_TAKEN = 1;


		#ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_MARKET_RESEARCH)
    {
		if(ID==ID_DEBUG_PROBE)
        {
		        printf("\n Firm_prepone_vintage_choice(): \n VINTAGE_SELECTED %d", VINTAGE_SELECTED);
		}

    }
    #endif

	
	return 0;
}


int	Firm_set_price()
{
	
	int i,j,t,Y;	

	int no_employees, no_employees_at_end_of_year, labour_demand;
	double average_productivity;
	double eff_productivity;
	double used_capital_stock;
	double planned_output;	
	double sum_output;
	double pot_output;
	double sum_earnings;
	double sum_earnings_discounted;
	double mean_specific_skills;
	double estimated_mean_wage;
	double realized_output;
	double capital_stock_depreciation_units;
	double payment_account;
	double installment_payment;
	double interest_payments;
	double earnings;
	double debt_needed;
	double investment_nominal;
	double temp_highest_earnings;
	double mean_specific_skills_at_end_of_year;
	double estimated_mean_wage_at_end_of_year ;
	double payment_account_at_end_of_year;
	double earnings_at_end_of_year;
	double 	buffer_at_end_of_year ;
	double labor_costs, capital_costs, calc_cap_costs;
	double sum_interest_payments;
	double combined_variance_demand_function;
	double buffer;
	double critical_stock;
	double expected_sales;
	double actual_sales_estimation;
	double current_stocks;
	double base_wage_offer;
	double base_wage_offer_end_of_year;


	DAY_OF_MONTH_PRICE_WAS_SET = DAY % 240;


	/*Compute mean wage that takes wage subsidies into account*/

	double mean_wage = 0.0;

	for(int i=0; i < EMPLOYEES.size;i++){

		mean_wage += (1-EMPLOYEES.array[i].subsidy_pct)*EMPLOYEES.array[i].wage;


	}

	if(EMPLOYEES.size>0)
		mean_wage = mean_wage / EMPLOYEES.size;
	else
		mean_wage = MEAN_WAGE;

	PRICE_LAST_MONTH = PRICE;


	double union_strength =  UNION_STRENGTH;

		if(REG_DIFF_UNION_STRENGTH && REGION_ID==2)
			union_strength = REG2_FACTOR_UNION_STRENGTH;






	double monthly_wage_growth = 1+VARIABLES_CHANGE.productivity_progress*union_strength;

			#ifdef _DEBUG_MODE    
 		   if (PRINT_DEBUG_MARKET_RESEARCH)
   			 {
				  if(ID==ID_DEBUG_PROBE)
     	       {
					printf( "\nOld PRICE %f \n",PRICE);
							
				}
  		  }
  		 #endif


	//delete array PROSPECTIVE_VARIABLES

	for(i=PROSPECTIVE_VARIABLES.size-1;i>=0;i--)
	{
		remove_dt_prospective_variables(&PROSPECTIVE_VARIABLES,i);
	}

	// optimal price choices for the next years until the completation of the R & D project	
	for(i=EXPECTED_PRICE_CHOICES.size-1;i>=0;i--)
	{
		remove_double(&EXPECTED_PRICE_CHOICES,i);
	}

	//Define temporary arrays for some variables which change from year to year. Starting with the actual values...
	adt_capital_stock_vintages_array capital_stock_at_end_of_year;
	init_adt_capital_stock_vintages_array(&capital_stock_at_end_of_year);

	financing_capital_array temp_capital_financing_at_end_of_year;
	init_financing_capital_array(&temp_capital_financing_at_end_of_year);

	debt_item_array temp_loans_at_end_of_year;
	init_debt_item_array(&temp_loans_at_end_of_year);

	for(i=0;i<CAPITAL_STOCK_VINTAGES.size;i++)
	{
		add_adt_capital_stock_vintages(&capital_stock_at_end_of_year, CAPITAL_STOCK_VINTAGES.array[i].
		amount,CAPITAL_STOCK_VINTAGES.array[i].productivity);
	}

	for(i=0;i<CAPITAL_FINANCING.size;i++)
	{
		add_financing_capital(&temp_capital_financing_at_end_of_year,CAPITAL_FINANCING.array[i].financing_per_month,
		CAPITAL_FINANCING.array[i].nr_periods_before_repayment);
	}

	for(i=0;i<LOANS.size;i++)
	{
		add_debt_item(&temp_loans_at_end_of_year, 0,LOANS.array[i].loan_value,LOANS.array[i].interest_rate,LOANS.array[i].installment_amount
			,0,0,0,LOANS.array[i].nr_periods_before_repayment);
	}

	//Temporary variables to store...
	mean_specific_skills_at_end_of_year = MEAN_SPECIFIC_SKILLS;
	estimated_mean_wage_at_end_of_year = mean_wage;
	no_employees_at_end_of_year = NO_EMPLOYEES_PRODUCTION;
	payment_account_at_end_of_year = PAYMENT_ACCOUNT;
	earnings_at_end_of_year= EARNINGS;
	buffer_at_end_of_year = TOTAL_BUFFER;
	base_wage_offer_end_of_year = WAGE_OFFER;


	Y=0;
	//for(Y=0;Y<MARKET_RESEARCH_DATA_PRICING.array[0].estimated_values.size-1;Y++)
	{
		temp_highest_earnings =0;


		for(i=0;i<MARKET_RESEARCH_DATA_PRICING.size;i++)
		{

			//Reset the earnings 
			adt_capital_stock_vintages_array capital_stock;
			init_adt_capital_stock_vintages_array(&capital_stock);

			for(j=0;j<capital_stock_at_end_of_year.size;j++)
			{
				add_adt_capital_stock_vintages(&capital_stock, capital_stock_at_end_of_year.array[j].amount,capital_stock_at_end_of_year.array[j].productivity);
			}

			financing_capital_array temp_capital_financing;
			init_financing_capital_array(&temp_capital_financing);

			for(j=0;j<temp_capital_financing_at_end_of_year.size;j++)
			{
				add_financing_capital(&temp_capital_financing, temp_capital_financing_at_end_of_year.array[j].financing_per_month,
				temp_capital_financing_at_end_of_year.array[j].nr_periods_before_repayment);
			}

			debt_item_array temp_loans;
			init_debt_item_array(&temp_loans);

			for(j=0;j<temp_loans_at_end_of_year.size;j++)
			{
				add_debt_item(&temp_loans, 0,temp_loans_at_end_of_year.array[j].loan_value,temp_loans_at_end_of_year.array[j].interest_rate,temp_loans_at_end_of_year.array[j].installment_amount
					,0,0,0,temp_loans_at_end_of_year.array[j].nr_periods_before_repayment);
			}

				
			dt_monthly_estimations_array temp_variables_over_year;
			init_dt_monthly_estimations_array(&temp_variables_over_year);

	
			sum_earnings=0.0;
			sum_earnings_discounted=0.0;			

			mean_specific_skills = mean_specific_skills_at_end_of_year;
			estimated_mean_wage =estimated_mean_wage_at_end_of_year;
			no_employees = no_employees_at_end_of_year;
			payment_account = payment_account_at_end_of_year;
			earnings=earnings_at_end_of_year;
			buffer = buffer_at_end_of_year;
			base_wage_offer = base_wage_offer_end_of_year;
			
			MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_earnings =0.0;

			current_stocks = buffer;
			
			//Optimal price and quantity choice:

			double average_marketshare = 0;



			// Copy of the competitor array

			price_quality_pair_array quality_price_competitor;
			init_price_quality_pair_array(&quality_price_competitor);




			for(int j=0; j< QUALITY_PRICE_COMPETITORS.size; j++)
				{

					add_price_quality_pair(&quality_price_competitor, QUALITY_PRICE_COMPETITORS.array[j].region_id, QUALITY_PRICE_COMPETITORS.array[j].price,QUALITY_PRICE_COMPETITORS.array[j].quality);


				}


			for(int r =1; r < LINEAR_REGRESSION_MARKET_SIZE.size;r++ ){

				average_marketshare += Firm_compute_regional_market_share_aux_function(r, 0, MARKET_RESEARCH_DATA_PRICING.array[i].price,&quality_price_competitor)*LINEAR_REGRESSION_MARKET_SIZE.array[r].intercept/LINEAR_REGRESSION_MARKET_SIZE.array[0].intercept;


			}



			double estimated_variance_binomiual = average_marketshare*(1-average_marketshare);






			//combined_variance_demand_function = estimated_variance_binomiual* LINEAR_REGRESSION_MARKET_SIZE.array[i].variance  +   pow(average_marketshare,2) *LINEAR_REGRESSION_MARKET_SIZE.array[0].variance  + pow(LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept,2)*estimated_variance_binomiual;;
			combined_variance_demand_function = estimated_variance_binomiual* LINEAR_REGRESSION_MARKET_SIZE.array[i].intercept;


			buffer = QUANTIL_NORMAL_DISTRIBUTION*pow(combined_variance_demand_function ,0.5);

			//buffer = 0.0;

			/*XXX Changed 140116*/
			//current_stocks=TOTAL_BUFFER; // original implementation
			current_stocks=STOCK;
			//current_stocks= 0;
			for(t=0;t<12;t++)
			{
				average_productivity=0.0;
				eff_productivity = 0.0;
				used_capital_stock=0.0;
				sum_output=0;
				pot_output=0;
				capital_stock_depreciation_units=0.0;
				installment_payment=0.0;
				interest_payments=0.0;
				investment_nominal=0.0;
				labor_costs=0.0;
				capital_costs=0.0;
				calc_cap_costs=0.0;
				sum_interest_payments=0.0; 


				expected_sales = 0;

				for(int r =1; r < LINEAR_REGRESSION_MARKET_SIZE.size;r++ ){


					expected_sales+= ((LINEAR_REGRESSION_MARKET_SIZE.array[r].intercept
										+ (1+LAST_MARKET_SIZES.array[r].market_sizes.size+Y*12+t)*LINEAR_REGRESSION_MARKET_SIZE.array[r].regressor)*Firm_compute_regional_market_share_aux_function(r, t, MARKET_RESEARCH_DATA_PRICING.array[i].price,&quality_price_competitor));




				}

				//Set critical stock: Expected sales plus buffer
				critical_stock = expected_sales + buffer;

				//Set output: Difference of critical and current stock 
				planned_output = max(critical_stock - current_stocks, 0);

				//Fix costs:
				// Capital costs for sunk investments:

				MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs=0;
			
				for(j=0; j< temp_capital_financing.size;j++)
				{
					if(temp_capital_financing.array[j].nr_periods_before_repayment==0)
      	        	{
             	       remove_financing_capital(&temp_capital_financing,j);
       	       	    	j--;
                	}else
               		{
                		temp_capital_financing.array[j].nr_periods_before_repayment--;
                		MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs
							+= temp_capital_financing.array[j].financing_per_month;
						calc_cap_costs+=temp_capital_financing.array[j].financing_per_month;
                	}
				}

				//Interest payments:
				for(j=temp_loans.size-1;j>=0;j--)
				{
					
					interest_payments=temp_loans.array[j].loan_value* temp_loans.array[j].interest_rate/12.0;
					MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs
						+=interest_payments;
					installment_payment += temp_loans.array[j].installment_amount;
					sum_interest_payments+=interest_payments;
					temp_loans.array[j].loan_value-=temp_loans.array[j].installment_amount;					
					temp_loans.array[j].nr_periods_before_repayment--;

					if(temp_loans.array[j].nr_periods_before_repayment<1)
					{
						remove_debt_item(&temp_loans,j);

					}

				}	

			


					#ifdef _DEBUG_MODE    
 		   if (PRINT_DEBUG_MARKET_RESEARCH)
   			 {
				  if(ID==ID_DEBUG_PROBE && Y==0)
     	       {
		    
				//printf( "fixed costs %f   Interest costs:  %f      Calc Capital costs  %f\n",MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs,sum_interest_payments,calc_cap_costs);
					for(j=0;j<temp_loans.size;j++)
					{

						//printf( "Y: %d t: %d temp_loans.array[j].nr_periods_before_repayment %d  temp_loans.array[j].loan_value %f \n",Y,t,temp_loans.array[j].nr_periods_before_repayment,temp_loans.array[j].loan_value);
					}
				}

  		  }
  		 #endif	

				//Compute input factor needs
				for(j=capital_stock.size-1;j>=0;j--)
				{
					capital_stock.array[j].amount= capital_stock.array[j].amount*(1-DEPRECIATION_RATE);
					capital_stock_depreciation_units+=capital_stock.array[j].amount*DEPRECIATION_RATE;
		
					if(sum_output < planned_output)
					{
						pot_output += min(mean_specific_skills,capital_stock.array[j].productivity)*capital_stock.array[j].amount;

						if(pot_output>planned_output)
						{
							double sum_cap_selected_vintage=(planned_output - sum_output)
								/min(mean_specific_skills,capital_stock.array[j].productivity);
							sum_output += (planned_output - sum_output);
							used_capital_stock+=sum_cap_selected_vintage;
							average_productivity += capital_stock.array[j].productivity*sum_cap_selected_vintage;
							eff_productivity += min(capital_stock.array[j].productivity,mean_specific_skills)
								*sum_cap_selected_vintage;
							
						}else
						{
							used_capital_stock+=capital_stock.array[j].amount;		
							sum_output += min(mean_specific_skills,capital_stock.array[j].productivity)*capital_stock.array[j].amount;
							average_productivity += capital_stock.array[j].productivity*capital_stock.array[j].amount;
							eff_productivity += min(capital_stock.array[j].productivity,
								mean_specific_skills)*capital_stock.array[j].amount;
						}
					}
				}
				if(sum_output < planned_output)
				{
					double inv;
					inv = (planned_output - sum_output)/ min(TECHNOLOGY_VINTAGES.array[VINTAGE_SELECTED].productivity,mean_specific_skills);
	
					inv = min(inv, max(INV_INERTIA*capital_stock_depreciation_units,1.0));
					used_capital_stock+=inv;

					inv += (round_double_to_int(used_capital_stock) - used_capital_stock);
					average_productivity += TECHNOLOGY_VINTAGES.array[VINTAGE_SELECTED].productivity*inv;
					eff_productivity += min(TECHNOLOGY_VINTAGES.array[VINTAGE_SELECTED].productivity,
								mean_specific_skills)*inv;
						
					for(j=0; j<capital_stock.size;j++)
					{
						if(abs_double(TECHNOLOGY_VINTAGES.array[VINTAGE_SELECTED].productivity-capital_stock.array[j].productivity)<1e-5)
						{
							capital_stock.array[j].amount+=inv;
							break;
						}else
						{
							if(j==capital_stock.size-1)
							{
								add_adt_capital_stock_vintages(&capital_stock,inv,TECHNOLOGY_VINTAGES.array[VINTAGE_SELECTED].productivity);
							}
						}
					}

					/* If subsidies for best vintage are switched on: reduce the effective price
					 for best practice technology*/				

						investment_nominal=inv*price_of_vintage(VINTAGE_SELECTED, INVESTMENT_SUBSIDY_TYPE, TECHNOLOGY_VINTAGES , SUBSIDY_PCT,TECHNOLOGICAL_FRONTIER);

					add_financing_capital(&temp_capital_financing,investment_nominal/CONST_INSTALLMENT_PERIODS, CONST_INSTALLMENT_PERIODS);
						
				
				}

				labour_demand = round_double_to_int(used_capital_stock);

				if(labour_demand<1)
					labour_demand=1;

				/*XXX new 11.01.2016*/

				if (labour_demand> no_employees){

					int add_workers_needed = labour_demand - no_employees;

					int add_workers = 0;

					for (int la = 0; la < add_workers_needed; la++){

						//if(random_unif() < AGG_VACANCY_FILLING_RATE){
						{
							add_workers++;

						}


					}

					double wage_offer_update = WAGE_UPDATE;

				//	if(REG_DIFF_UNION_STRENGTH && REGION_ID==1)
				//			wage_offer_update = REG2_FACTOR_UNION_STRENGTH;


					double vac_ratio = 0.0;

					vac_ratio = 1 - add_workers/(1.0*add_workers_needed);

					if(vac_ratio > 0.49 )
						base_wage_offer = base_wage_offer*(1+wage_offer_update);

					labour_demand = no_employees + add_workers;

				}


				used_capital_stock = round_double_to_int(used_capital_stock);
				if(used_capital_stock>1e-5)
				{
					average_productivity = average_productivity / used_capital_stock;
					eff_productivity = eff_productivity / used_capital_stock;
				}else
				{
					average_productivity = TECHNOLOGY;
					used_capital_stock  = TECHNOLOGY;

				}
				/*Capital costs*/
				capital_costs=calc_cap_costs + investment_nominal
					/CONST_INSTALLMENT_PERIODS;

				/*Determine tealized output*/
				realized_output= labour_demand*eff_productivity;

				current_stocks += realized_output;
			
				//Compute mean wage:	
				if(labour_demand>no_employees)
				{
					estimated_mean_wage =no_employees/(1.0*labour_demand) * estimated_mean_wage  
						+ (labour_demand - no_employees)/(1.0*labour_demand)*base_wage_offer*min(average_productivity,mean_specific_skills);

				}

				//Compute variable costs
				if(realized_output>1e-5)
				{
					MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_variable_costs = 	
						(labour_demand*estimated_mean_wage + investment_nominal/CONST_INSTALLMENT_PERIODS)/realized_output;
				}
				else
				{
					MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_variable_costs = 0.0;
				}
	
				labor_costs = labour_demand*estimated_mean_wage;
				//Check financing:
	
				payment_account= payment_account - 
					labour_demand*estimated_mean_wage - investment_nominal -
					sum_interest_payments - installment_payment -max(0,earnings)*TAX_RATE_CORPORATE - max(0,earnings)*(1-TAX_RATE_CORPORATE)
					*CONST_DIVIDEND_EARNINGS_RATIO;

				//Check if additional loans are necessary
				debt_needed = (-1)*min(payment_account,0);



						
				if(debt_needed>1e-5)
				{
					add_debt_item(&temp_loans, 0,debt_needed,LAST_INTEREST_RATE_FOR_LOANS,debt_needed/CONST_INSTALLMENT_PERIODS,0,0,0,CONST_INSTALLMENT_PERIODS);
				}
				payment_account+=debt_needed;



				// Compute actual sales:

				actual_sales_estimation = min(current_stocks,expected_sales);



				//Compute earnings
				earnings= actual_sales_estimation* (MARKET_RESEARCH_DATA_PRICING.array[i].price - 
					MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_variable_costs)  - 
					MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs;


				add_dt_monthly_estimations(&temp_variables_over_year,realized_output,earnings,actual_sales_estimation,
					labor_costs,capital_costs,sum_interest_payments,estimated_mean_wage,mean_specific_skills,average_productivity,investment_nominal);


				#ifdef _DEBUG_MODE    
 	   if (PRINT_DEBUG_MARKET_RESEARCH)
   		 {
			  if(ID==ID_DEBUG_PROBE)
            {
		//	if(Y==0)
		  // printf( "payment_account %f   debt_needed %f \n",payment_account ,  debt_needed );
			//printf( "earnings %f   realized_output %f  variable costs %f  fixed costs %f   investment_nominal %f \n ", earnings,  realized_output,MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_variable_costs,MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs, investment_nominal);

			
			
		}

    }
    #endif







				sum_earnings_discounted += pow(1/(1+DISCONT_RATE),t)*earnings;
				sum_earnings += earnings;			

				MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_earnings += pow(1/(1+DISCONT_RATE),Y*12+t)*earnings;
	
				//Add expected earnings on payment account
				payment_account+= actual_sales_estimation*MARKET_RESEARCH_DATA_PRICING.array[i].price;

				current_stocks -=actual_sales_estimation;
	
				//Update mean wage:
	


				estimated_mean_wage = estimated_mean_wage*monthly_wage_growth;



	
				no_employees  = labour_demand;

				// Skill update:

				if(SKILL_UPDATE_ACC_TO_FORMULA==1)
				{
      				/*Update the specific skill: depends on the actual specific skill, 
        			the gap between the actual specific skills and the actual productivity of the employer,
        			and the general skill which determines the speed of closing the this gap.*/
       				mean_specific_skills = max(mean_specific_skills, mean_specific_skills+ 
						max(average_productivity-mean_specific_skills,0)
						*((1-pow(0.5,1/(20+0.25*(AVERAGE_G_SKILL-1)*(4-20))))));
				}else
				{
	 				 /*Update the specific skill: depends on the actual specific skill, 
       				 the gap between the actual specific skills and the actual productivity of
					 the employer. The rate is predetermined.*/
				
      					mean_specific_skills = max(mean_specific_skills, mean_specific_skills+ max(average_productivity-mean_specific_skills,0)		     
							*AVERAGE_ADAPTATION_SPEED_SPECIFIC_SKILLS);
						
				}
			}		


			free_price_quality_pair_array(&quality_price_competitor);

	
			#ifdef _DEBUG_MODE    
 	   if (PRINT_DEBUG_MARKET_RESEARCH)
   		 {
			  if(ID==ID_DEBUG_PROBE && Y==MARKET_RESEARCH_DATA_PRICING.array[0].estimated_values.size-2)
            {
			
		 printf( "Price: %f   sum_earnings_discounted  %f    sum_earnings %f \n",MARKET_RESEARCH_DATA_PRICING.array[i].price, sum_earnings_discounted ,sum_earnings);

			//printf( "earnings %f  %f \n ", earnings,  realized_output,MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_variable_costs,MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs, investment_nominal);
		}

    }
    #endif
		

			//Search for the highest expected earnings. Therefore we start with the first price and overwrite the values if the expected earnings are higher
			if(i==0 || temp_highest_earnings < MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_earnings)
			{

	
					if(i!=0)
					{
						remove_dt_prospective_variables(&PROSPECTIVE_VARIABLES,Y);
					}

					add_dt_prospective_variables(&PROSPECTIVE_VARIABLES,mean_specific_skills,estimated_mean_wage, no_employees, earnings, payment_account, buffer,0,0,0);
	
	
					for(j=0;j<capital_stock.size;j++)
					{
						add_adt_capital_stock_vintages(&PROSPECTIVE_VARIABLES.array[Y].capital_stock_vintages, capital_stock.array[j].
							amount,capital_stock.array[j].productivity);
					}

					for(j=0;j<temp_capital_financing.size;j++)
					{
						add_financing_capital(&PROSPECTIVE_VARIABLES.array[Y].capital_financing, temp_capital_financing.array[j].financing_per_month,
							temp_capital_financing.array[j].nr_periods_before_repayment);
					}
				


					for(j=0;j<temp_loans.size;j++)
					{
						add_debt_item(&PROSPECTIVE_VARIABLES.array[Y].loans, 0,temp_loans.array[j].loan_value
						,temp_loans.array[j].interest_rate,temp_loans.array[j].installment_amount
							,0,0,0,temp_loans.array[j].nr_periods_before_repayment);
					}
				

				temp_highest_earnings = MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_earnings;

				if(EXPECTED_PRICE_CHOICES.size != Y + 1)
				{
					add_double(&EXPECTED_PRICE_CHOICES,MARKET_RESEARCH_DATA_PRICING.array[i].price);
				}else
				{
					EXPECTED_PRICE_CHOICES.array[Y]=MARKET_RESEARCH_DATA_PRICING.array[i].price;
				}

				//Set new price:
				if(Y==0)
				{
					for(t=0;t<12;t++)
					{
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].output= 			
							temp_variables_over_year.array[t].output;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].earnings= 			
							temp_variables_over_year.array[t].earnings;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].labor_costs= 
							temp_variables_over_year.array[t].labor_costs;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].capital_costs= 
							temp_variables_over_year.array[t].capital_costs;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].interest_payments= 
							temp_variables_over_year.array[t].interest_payments;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].wage= 
							temp_variables_over_year.array[t].wage;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].mean_specific_skills= 
							temp_variables_over_year.array[t].mean_specific_skills;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].average_productivity= 
							temp_variables_over_year.array[t].average_productivity;
						EXPECTED_EARNINGS_AND_COSTS_OVER_YEAR[t].investment_nominal=
							temp_variables_over_year.array[t].investment_nominal;
					
					}

				
					/*We set the price only if we are not in the adjustment period*/
					  if(!(DAY >20 && DAY < 480 && INITIAL_PRICE_ADJUSTMENT)){



						  if(DAY >240)
							  PRICE = MARKET_RESEARCH_DATA_PRICING.array[i].price;
						  else
							  PRICE = (1+MARK_UP)*UNIT_COSTS;

					  }


				
					EARNINGS_WHILE_LAST_PRICING_PERIOD = SUM_EARNINGS_SINCE_PRICE_CHANGE;
					SUM_EARNINGS_SINCE_PRICE_CHANGE=0.0;	




				
				}

			}
				
	
			
			//Free memory
			free_adt_capital_stock_vintages_array(&capital_stock);
			free_financing_capital_array(&temp_capital_financing);
			free_debt_item_array(&temp_loans);
			free_dt_monthly_estimations_array(&temp_variables_over_year);
	
	
		}
				
		//Pass these variables of the optimal price startegy to the next considered year 
		if(Y<MARKET_RESEARCH_DATA_PRICING.array[0].estimated_values.size-1)
		{
			for(i=0;i<capital_stock_at_end_of_year.size;i++)
			{
				remove_adt_capital_stock_vintages(&capital_stock_at_end_of_year,i);
				i--;
			}
	
			for(i=0;i<PROSPECTIVE_VARIABLES.array[Y].capital_stock_vintages.size;i++)
			{
				add_adt_capital_stock_vintages(&capital_stock_at_end_of_year, PROSPECTIVE_VARIABLES.array[Y].capital_stock_vintages.array[i].
				amount,PROSPECTIVE_VARIABLES.array[Y].capital_stock_vintages.array[i].productivity);
			}
		
		
			for(i=0;i<temp_capital_financing_at_end_of_year.size;i++)
			{
				remove_financing_capital(&temp_capital_financing_at_end_of_year,i);
			i--;
			}
		
			for(i=0;i<PROSPECTIVE_VARIABLES.array[Y].capital_financing.size;i++)
			{
				add_financing_capital(&temp_capital_financing_at_end_of_year, PROSPECTIVE_VARIABLES.array[Y].capital_financing.array[i].financing_per_month,
				PROSPECTIVE_VARIABLES.array[Y].capital_financing.array[i].nr_periods_before_repayment);
			}
		
			for(i=0;i<temp_loans_at_end_of_year.size;i++)
			{
				remove_debt_item(&temp_loans_at_end_of_year,i);
				i--;
			}
		
			for(i=0;i<PROSPECTIVE_VARIABLES.array[Y].loans.size;i++)
			{
				add_debt_item(&temp_loans_at_end_of_year, 0,PROSPECTIVE_VARIABLES.array[Y].loans.array[i].loan_value
					,PROSPECTIVE_VARIABLES.array[Y].loans.array[i].interest_rate,PROSPECTIVE_VARIABLES.array[Y].loans.array[i].installment_amount
					,0,0,0,PROSPECTIVE_VARIABLES.array[Y].loans.array[i].nr_periods_before_repayment);
				
					#ifdef _DEBUG_MODE    
 		   if (PRINT_DEBUG_MARKET_RESEARCH)
   			 {
				  if(ID==ID_DEBUG_PROBE)
     	       {
		    
					//printf( "fixed costs %f\n",MARKET_RESEARCH_DATA_PRICING.array[i].estimated_values.array[Y].estimated_fix_costs);
					

					//	printf( "PROSPECTIVE_VARIABLES.array[%d].loans.array[%d].loan_value %f installmet %f periods remaining %d\n",Y,i,PROSPECTIVE_VARIABLES.array[Y].loans.array[i].loan_value, PROSPECTIVE_VARIABLES.array[Y].loans.array[i].installment_amount,PROSPECTIVE_VARIABLES.array[Y].loans.array[i].nr_periods_before_repayment );
	
				}

  		  }
  		 #endif



			}
		
			mean_specific_skills_at_end_of_year = PROSPECTIVE_VARIABLES.array[Y].mean_specific_skills;
			estimated_mean_wage_at_end_of_year = PROSPECTIVE_VARIABLES.array[Y].estimated_mean_wage;
			no_employees_at_end_of_year = PROSPECTIVE_VARIABLES.array[Y].no_employees;
			payment_account_at_end_of_year =PROSPECTIVE_VARIABLES.array[Y].payment_account ;
			earnings_at_end_of_year= PROSPECTIVE_VARIABLES.array[Y].earnings;
			buffer_at_end_of_year = PROSPECTIVE_VARIABLES.array[Y].buffer;
		}	

	}		
	
	

	free_adt_capital_stock_vintages_array(&capital_stock_at_end_of_year);
	free_financing_capital_array(&temp_capital_financing_at_end_of_year);
	free_debt_item_array(&temp_loans_at_end_of_year);
	

	//Set price just set flag
	PRICE_JUST_SET_FLAG = 1;



	COUNTER_MONTH_SINCE_LAST_PRICE_SETTING=0;
   
			#ifdef _DEBUG_MODE    
 		   if (PRINT_DEBUG_MARKET_RESEARCH)
   			 {
				  if(ID==ID_DEBUG_PROBE)
     	       {
					printf( "\nNew PRICE %f\n",PRICE);

					printf( "COMBINED_VARIANCE_DEMAND_FUNCTION %f\n",COMBINED_VARIANCE_DEMAND_FUNCTION );
			
				}
  		  }
  		 #endif

	return 0;
}




int Firm_decide_product_innovation()
{

	

	return 0;
}



int Firm_clean_up_arrays()
{

int i;

	#ifndef _DEBUG_MODE 
	//Delete MARKET_RESEARCH_DATA_PRICING
	for(i=MARKET_RESEARCH_DATA_PRICING.size-1;i>=0;i--)
	{
		remove_dt_market_research_price(&MARKET_RESEARCH_DATA_PRICING,i);
	}
	//Delete MARKET_RESEARCH_DATA_PRODUCT_INNOVATION
	for(i=MARKET_RESEARCH_DATA_PRODUCT_INNOVATION.size-1;i>=0;i--)
	{
	remove_dt_market_research_qualities(&MARKET_RESEARCH_DATA_PRODUCT_INNOVATION,i);	
	}
	//delete array PROSPECTIVE_VARIABLES

	for(i=PROSPECTIVE_VARIABLES.size-1;i>=0;i--)
	{
		remove_dt_prospective_variables(&PROSPECTIVE_VARIABLES,i);
	}
	
	 #endif
return 0;
}

