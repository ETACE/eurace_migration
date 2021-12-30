#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"
#include <gsl/gsl_rng.h>
#include <time.h>


/** \fn Household_decide_to_attend_interview
 */
int Household_decide_to_attend_interview()
{
	INTERVIEWER_ID = 0;
	WILLINGNESS_TO_ATTEND = 0;
	
	double random_nummer;
	
	random_nummer = random_int(0,100);
	
	
	
	RANDOM_NO_TEST = random_nummer;
	
	random_nummer  = random_nummer/100.0;
	// If random_nummer < attending propability then the household would attend an interview
	if(random_nummer < QUESTIONNAIRE_ATTENDING_PROPABILITY)
	{
		WILLINGNESS_TO_ATTEND = 1;
		
	}
	
	return 0;
}


/** \fn Household_respond
 */
int Household_respond()
{

	int_array temp_ids;
	init_int_array(&temp_ids);



	START_INTERVIEW_REQUEST_MESSAGE_LOOP

	add_int(&temp_ids, interview_request_message->firm_id);

	FINISH_INTERVIEW_REQUEST_MESSAGE_LOOP
	



	INTERVIEWER_ID = temp_ids.array[random_int(0,temp_ids.size-1)];
	WILLINGNESS_TO_ATTEND = 0;

	add_interview_positive_response_message(ID, REGION_ID, INTERVIEWER_ID);

	//Respond if attend
	
	free_int_array(&temp_ids);

	return 0;
}



int Household_respond_questionnaire()
{
	
	int i,j,t;
	
	double price, quality, mean_price_growth;
	double random_number, logit, logit_denominator;
	int year_under_consideration, total_years ;
	double quality_growth_rate, price_growth_rate;
	

	//int random_number;

	//double random_number_double;
	const gsl_rng_type * T;
	gsl_rng * r;
	

	
	gsl_rng_env_setup();

	T = gsl_rng_default;
	r = gsl_rng_alloc (T);
	
	int seed = ID + (unsigned)time(NULL); 
	gsl_rng_set(r, seed);

	int price_done;

	price_done=0;


	int choice;
	double logit_sum;
	

	START_QUESTIONNAIRE_INNOVATION_MESSAGE_LOOP


	//When going through the price quality array sent with the message: The length is given with 12:

	logit_denominator =0;

	// Determine the denominator
	for(i=0; i< 12; i++)
	{

		logit_denominator += exp(GAMMA_QUALITY*log(questionnaire_innovation_message->price_quality[i].quality)
			-GAMMA_CONST*log(questionnaire_innovation_message->price_quality[i].price));
	}
		
	// Draw a random number:
	random_number = gsl_rng_uniform (r);

		//printf("random_number %f \n",random_number);		

	// Determine logits and decide on good

	logit_sum =0.0;
	choice=0;
	for(i=0; i< 12; i++)
	{


		logit = exp(GAMMA_QUALITY*log(questionnaire_innovation_message->price_quality[i].quality)
			-GAMMA_CONST*log(questionnaire_innovation_message->price_quality[i].price))/logit_denominator;

		logit_sum += logit;

		//printf("Price %f   Quality %f   Logit %f   logit_sum %f \n", questionnaire_innovation_message->price_quality[i].price,questionnaire_innovation_message->price_quality[i].quality,logit,logit_sum);
	
		choice=i;

		if(random_number < logit_sum)
		{
			//Set the good chosenand break the loop
			
			break;

		}
		
	}

	//printf("\n");


			add_filled_out_questionnaire_product_innovation_message( INTERVIEWER_ID,REGION_ID,choice);

					
	FINISH_QUESTIONNAIRE_INNOVATION_MESSAGE_LOOP

	
	gsl_rng_free (r);
	
	return 0;
}
