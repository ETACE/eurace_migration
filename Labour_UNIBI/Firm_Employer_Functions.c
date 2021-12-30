#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
#include "Labour_aux_headers.h"


/*************************************Firm Role: Labour Market*********************************/


/** \fn Firm_calculate_specific_skills_and_wage_offer()
 * \brief: 
	- Firm calculates the average specific skills for each general skill group. 
	- Firm determines the wage offer for each general skill group.*/
int Firm_set_labour_market_actions()
{

	if(NO_EMPLOYEES_PRODUCTION > EMPLOYEES_NEEDED_PRODUCTION)
	{
		NO_REDUNDANCIES = NO_EMPLOYEES_PRODUCTION - EMPLOYEES_NEEDED_PRODUCTION;
		VACANCIES = 0;

	}else
	{
		NO_REDUNDANCIES = 0;

		VACANCIES =  EMPLOYEES_NEEDED_PRODUCTION -NO_EMPLOYEES_PRODUCTION;

	}

	
	if(NO_EMPLOYEES_INNOVATION > EMPLOYEES_NEEDED_INNOVATION)
	{
		NO_REDUNDANCIES_R_AND_D_EMPLOYEES = NO_EMPLOYEES_INNOVATION - EMPLOYEES_NEEDED_INNOVATION;
		VACANCIES = 0;

	}else
	{
		NO_REDUNDANCIES_R_AND_D_EMPLOYEES = 0;
		VACANCIES_R_AND_D_EMPLOYEES =  EMPLOYEES_NEEDED_INNOVATION -NO_EMPLOYEES_INNOVATION;
	}


return 0;
}



/** \fn Firm_calculate_specific_skills_and_wage_offer()
 * \brief: 
	- Firm calculates the average specific skills for each general skill group. 
	- Firm determines the wage offer for each general skill group.*/
int Firm_calculate_specific_skills_and_wage_offer()
{
	int n;
	int m;
	
	/*Sum up the specific skills of employees  for each general skill group (1-5): for average*/
	double sum_1 = 0;
	double sum_2 = 0;
	double sum_3 = 0;
	double sum_4 = 0;
	double sum_5 = 0;

	NO_EMPLOYEES_SKILL_1=0;
	NO_EMPLOYEES_SKILL_2=0;
	NO_EMPLOYEES_SKILL_3=0;
	NO_EMPLOYEES_SKILL_4=0;
	NO_EMPLOYEES_SKILL_5=0;

	NO_APPLICATIONS_ROUND_1=0;
	NO_APPLICATIONS_ROUND_2=0;

for(n = 0; n < EMPLOYEES.size; n++)
{

/*Explore the genral skill level of dismissed employee.*/
		switch(EMPLOYEES.array[n].general_skill)
		{
			/*If dismissed employee has skill level 1 reduce the number of employees with skill level 1 by 1.*/
			case 1:
				NO_EMPLOYEES_SKILL_1++;
				break;

				case 2:
				NO_EMPLOYEES_SKILL_2++;
				break;

			case 3:
				NO_EMPLOYEES_SKILL_3++;
				break;

			case 4:
				NO_EMPLOYEES_SKILL_4++;
				break;
					
			/*If dismissed employee has skill level 5 reduce the number of employees with skill level 5 by 1.*/
			case 5:
				NO_EMPLOYEES_SKILL_5++;
				break;
		}


}






	/*For every employee*/
	for(n = 0; n < EMPLOYEES.size; n++)
	{
		/*Explore the general skill level (1-5) of each employee*/
		switch(EMPLOYEES.array[n].general_skill)
		{
			/*If employee has general skill level 1 add specific skill to sum1*/
			case 1:
			sum_1 = sum_1 + EMPLOYEES.array[n].specific_skill;
			break;

			case 2:
			sum_2 = sum_2 + EMPLOYEES.array[n].specific_skill;
			break;

			case 3:
			sum_3 = sum_3 + EMPLOYEES.array[n].specific_skill;
			break;

			case 4:
			sum_4 = sum_4 + EMPLOYEES.array[n].specific_skill;
			break;

			/*If employee has general skill level 5 add specific skill to sum5*/
			case 5:
			sum_5 = sum_5 + EMPLOYEES.array[n].specific_skill;
			break;
		}
	}

	/*For each general skill group: Calculate the average specific skills.*/
	for(m = 1; m < 6;m++)
	{
		switch(m)
		{
			/*If skill level 1: Calculate the average specific skills of general skill group 1.*/
			case 1:
				/*If there are employees with general skill level 1.*/
				if(NO_EMPLOYEES_SKILL_1 > 0)
				{   
					/*Calculate average specific skill of skill group 1*/
					AVERAGE_S_SKILL_OF_1 = sum_1/NO_EMPLOYEES_SKILL_1;
				}

				/*Wage offer determination: Basic wage offer per unit of specific skills times the minimum of 
				the average specific skill of general skill group 1 or technology.*/
				WAGE_OFFER_FOR_SKILL_1 = max( MINIMUM_WAGE,WAGE_OFFER* min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1));
				break;
			

			case 2:
				if(NO_EMPLOYEES_SKILL_2 > 0)
				{
					AVERAGE_S_SKILL_OF_2 = sum_2/NO_EMPLOYEES_SKILL_2;  
				}

				/*The other skill groups get a higher wage offer depending on the   productivity (specific skill)*/
				WAGE_OFFER_FOR_SKILL_2 = max( MINIMUM_WAGE,WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2));
				break;
			

			case 3:
				if(NO_EMPLOYEES_SKILL_3 > 0)
				{
					AVERAGE_S_SKILL_OF_3 = sum_3/NO_EMPLOYEES_SKILL_3;  
				}

				WAGE_OFFER_FOR_SKILL_3 = max( MINIMUM_WAGE,WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3));
				break;
			

			case 4:
				if(NO_EMPLOYEES_SKILL_4 > 0)
				{
					AVERAGE_S_SKILL_OF_4 = sum_4/NO_EMPLOYEES_SKILL_4;  
				}

				WAGE_OFFER_FOR_SKILL_4 = max( MINIMUM_WAGE,WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4));
				break;
			

			/*If skill level 5: Calculate the average specific skills of general skill group 5.*/
			case 5:
				if(NO_EMPLOYEES_SKILL_5 > 0)
				{
					/*Calculate average specific skill of skill group 5*/
					AVERAGE_S_SKILL_OF_5 = sum_5/NO_EMPLOYEES_SKILL_5;  
				}
			
				/*Wage offer determination: Basic wage offer per unit of specific skills times the minimum of 
				the average specific skill of general skill group 5 or technology.*/
				WAGE_OFFER_FOR_SKILL_5 = max( MINIMUM_WAGE,WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5));
				break;  
		}
	}

	WAGE_OFFER_FOR_R_AND_D_EMPLOYEES = BASE_WAGE_OFFER_R_AND_D*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5);

	return 0;
}



/** \fn Firm_send_vacancies()
 * \brief: 
	- Firm sends vacancies message if the number of employees is smaller than the number of needed employees.
	- Vacancies include Firm_ID, Region_ID, and different wage offers for each general skill group.
 */
int Firm_send_vacancies()
{
	

	if(VACANCIES > 0)
	{
	/*Send vacancies message with different wage offers for each general skill group.*/
		add_vacancies_message(ID, 
		REGION_ID, 
		WAGE_OFFER_FOR_SKILL_1, 
		WAGE_OFFER_FOR_SKILL_2, 
		WAGE_OFFER_FOR_SKILL_3, 
		WAGE_OFFER_FOR_SKILL_4, 
		WAGE_OFFER_FOR_SKILL_5);
	}

	if(VACANCIES_R_AND_D_EMPLOYEES>0)
	{
		add_vacancies_r_and_d_employees_message(ID, 
		REGION_ID, WAGE_OFFER_FOR_R_AND_D_EMPLOYEES);

	}

	return 0;
}



/** \fn Firm_send_redundancies()
 * \brief: 
	- Firm send firing messages if the number of employees is higher than the number of needed employees.
	- Market driven dismissals.
 */
int Firm_send_redundancies()
{
	int j;
	int i;
	int no_redundancies;
	

	/*If firm wants to dismiss employees with lowest specific skills first.*/
	/*sorting employees: highest specific skills first*/
	//qsort(EMPLOYEES.array, EMPLOYEES.size, sizeof(employee),
	//employee_list_rank_specific_skills_function);
		
	/*If firm wants to dismiss employees with lowest general skills first.*/
	/*sorting employees: highest genral skills first*/
	qsort(EMPLOYEES.array, EMPLOYEES.size, sizeof(employee),employee_list_rank_general_skills_function);


	for(i = 0; i < NO_REDUNDANCIES; i++)
	{   
		/*1. Option: Firing by chance*/
		//j = random_int(0,(EMPLOYEES.size-1));
		//add_firing_message(ID, EMPLOYEES.array[j].id);

		/*2/3. Option: Firing employees with lowest specific(2)/genral skill(3)*/
		j = EMPLOYEES.size-1;
		add_firing_message(ID, EMPLOYEES.array[j].id);
			
		/*Explore the genral skill level of dismissed employee.*/
		switch(EMPLOYEES.array[j].general_skill)
		{
			/*If dismissed employee has skill level 1 reduce the number of employees with skill level 1 by 1.*/
			case 1:
				NO_EMPLOYEES_SKILL_1--;
				break;

				case 2:
				NO_EMPLOYEES_SKILL_2--;
				break;

			case 3:
				NO_EMPLOYEES_SKILL_3--;
				break;

			case 4:
				NO_EMPLOYEES_SKILL_4--;
				break;
					
			/*If dismissed employee has skill level 5 reduce the number of employees with skill level 5 by 1.*/
			case 5:
				NO_EMPLOYEES_SKILL_5--;
				break;
		}

		if(EMPLOYEES.array[j].subsidy_pct>0)
			NO_EMPLOYEES_SUBSIDIZED--;
			
		/*Remove the employee from the list.*/
		remove_employee(&EMPLOYEES, j);
		/*Reduce the overall number of employees by 1.*/
		NO_EMPLOYEES--;
		NO_EMPLOYEES_PRODUCTION--;
		
	}


	//Firing of R and D employees:

	for(i=0; i<NO_REDUNDANCIES_R_AND_D_EMPLOYEES;i++)
	{

		//Random firing:

		j = random_int(0,(R_AND_D_EMPLOYEES.size-1));

		add_firing_message(ID, R_AND_D_EMPLOYEES.array[j].id);
		remove_employee(&R_AND_D_EMPLOYEES, j);
		NO_EMPLOYEES--;
		NO_EMPLOYEES_INNOVATION--;
	}
	
	return 0;
}



/** \fn Firm_send_random_redundancies()
* \brief: 
	- Firm dismisses a small randomly determined fraction of employees. 
	- Interpretation: employee quits, employer is not satisfied....
	- Not market driven.
*/
int Firm_send_random_redundancies()
{
	int i;
	
	double dissolv_probability = UPPER_BOUND_FIRING/100.0;


	for (i=0; i < EMPLOYEES.size; i++){

		
			if(random_unif()<dissolv_probability){


				add_firing_message(ID, EMPLOYEES.array[i].id);

				switch(EMPLOYEES.array[i].general_skill)
				{
					/*If dismissed employee has skill level 5 reduce the number of employees with skill level 1 by 1.*/
					case 1:
						NO_EMPLOYEES_SKILL_1--;
						break;

					case 2:
						NO_EMPLOYEES_SKILL_2--;
						break;

					case 3:
						NO_EMPLOYEES_SKILL_3--;
						break;

					case 4:
						NO_EMPLOYEES_SKILL_4--;
						break;

					/*If dismissed employee has skill level 5 reduce the number of employees with skill level 5 by 1.*/
					case 5:
						NO_EMPLOYEES_SKILL_5--;
						break;
				}

				if(EMPLOYEES.array[i].subsidy_pct>0)
					NO_EMPLOYEES_SUBSIDIZED--;

				/*Remove the employee from the list.*/
				remove_employee(&EMPLOYEES, i);
				/*Reduce the overall number of employees by 1.*/
				NO_EMPLOYEES--;
				NO_EMPLOYEES_PRODUCTION--;
				
			}



		
	}


	/*Reconsider the vacancies:*/
	VACANCIES =  max(0,EMPLOYEES_NEEDED_PRODUCTION -NO_EMPLOYEES_PRODUCTION);
	POSTED_VACANCIES = VACANCIES;

	// Random firing of one R and D employee 

	int random_num_2, random_num_3;
	random_num_2 = random_int(0,100);
	
	if(random_num_2 < 10 && R_AND_D_EMPLOYEES.size>0)
	{
		random_num_3 = random_int(0,R_AND_D_EMPLOYEES.size-1);

		add_firing_message(ID, R_AND_D_EMPLOYEES.array[random_num_3].id);

		remove_employee(&R_AND_D_EMPLOYEES, random_num_3);
		NO_EMPLOYEES--;
		NO_EMPLOYEES_INNOVATION--;
	}

	/*Reconsider the R&D vacancies:*/
	VACANCIES_R_AND_D_EMPLOYEES = max(0, EMPLOYEES_NEEDED_INNOVATION -NO_EMPLOYEES_INNOVATION);
	POSTED_VACANCIES_R_AND_D_EMPLOYEES  = VACANCIES_R_AND_D_EMPLOYEES ;
	
 
	return 0;
} 



/** \fn Firm_read_job_applications_send_offer_or_rejection()
 * \brief: 
	- Firm reads job applications. 
	- Firm sends job offers.
		1: If number of applicants is smaller than the number of vacancies: send job offer to each applicant.
		2: If number of applicant is higher than the number of vacancies: use logit model.
			Applicants with higher general skills have a higher probability to receive a job offer.
 */
int Firm_read_job_applications_send_job_offer_or_rejection()
{
	int i;
	int j;
	int k;
	int no_applications;

	double contribution_margin;

	/* Create a job application dynamic array */
	job_application_array job_application_list; 
	init_job_application_array(&job_application_list);



	START_JOB_APPLICATION_MESSAGE_LOOP

	int eff_wage_below_minimum_wage = 0;


		double wage_offer;
		double wage_mark_down = 1.0;


				switch(job_application_message->general_skill)
				{
					/*Check if the expected average specific skill is >0; otherwise this application is not considered*/
					case 1:

						wage_offer = WAGE_OFFER_FOR_SKILL_1;

						if(fabs(WAGE_OFFER_FOR_SKILL_1- MINIMUM_WAGE )<1e-5 && job_application_message->job_type){

							eff_wage_below_minimum_wage = 1;

							if(POLICY_MIGRATION_TOP_UP_BENEFITS ){

								wage_offer = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1);


							}

							if(POLICY_MIGRATION_WAGE_SUBSIDIES){


								if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){

									wage_mark_down =  WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

								}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED)

									wage_mark_down = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

							}


						}


						contribution_margin =  (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1) - wage_offer*wage_mark_down)/(wage_offer*wage_mark_down); ;


						break;

					case 2:

						wage_offer = WAGE_OFFER_FOR_SKILL_2;

						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2) - wage_offer )/wage_offer;

						break;

					case 3:

						wage_offer = WAGE_OFFER_FOR_SKILL_3;


						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3) - wage_offer)/wage_offer ;

						break;

					case 4:

						wage_offer = WAGE_OFFER_FOR_SKILL_4;

						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4) - wage_offer)/wage_offer ;

						break;


					case 5:

						wage_offer = WAGE_OFFER_FOR_SKILL_5;

						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5) - wage_offer)/wage_offer;


						break;
				}


		/* Read job application messages for this Firm */




			double prob = exp(LOGIT_PARAMETER_WORKER_PRESELECTION* (contribution_margin + 0.1))/(1 + exp(LOGIT_PARAMETER_WORKER_PRESELECTION* (contribution_margin + 0.1)));

			double random = random_unif();


			if(random < prob){

			/*Add application to application list.*/
			add_job_application(&job_application_list, 
			job_application_message->worker_id,
			job_application_message->region_id,
			job_application_message->general_skill, 
			job_application_message->specific_skill, wage_offer, eff_wage_below_minimum_wage);

			}


	FINISH_JOB_APPLICATION_MESSAGE_LOOP


	no_applications = job_application_list.size;

	NO_APPLICATIONS_ROUND_1 =  no_applications;

	/*Sort the applications. Highest general skills first.*/
	/*qsort(job_application_list.array, job_application_list.size, 
	sizeof(job_application), job_application_list_rank_general_skill_function);*/

	/*Case 1: Number of Vacancies is equal or higher than number of applications:
	each applicant gets a job offer*/   
	if(no_applications <= VACANCIES)
	{	
		for(i = 0; i < (job_application_list.size); i++)
		{
			add_job_offer_message(ID,
				job_application_list.array[i].worker_id,
				REGION_ID,
				job_application_list.array[i].wage_offer,job_application_list.array[i].job_type);

		}


	}
	/*Case 2: Number of Vacancies is smaller  than number of applications:
	firm choose applicants using a logit model*/
	else
	{
		/*For each vacancy to fill...*/
		for(i = 0; i< VACANCIES; i++)
		{
			/*Create temporary array to store logits of the applicants.*/
			logit_array  logit_applications_list;
			init_logit_array(&logit_applications_list);

			/*Variables for the logit*/
			double denominator_logit = 0;
			double logit = 0.0;
			double sum_of_logits;
			double random_number;



			/*For each vacancy to fill sum up the logits of all (remaining) applicants.*/
			for(j = 0; j< job_application_list.size;j++)
			{

				double cost_per_productivity = 0.00000001;

				double wage_mark_down = 1.0;

				if(job_application_list.array[j].job_type && POLICY_MIGRATION_WAGE_SUBSIDIES){

					if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){

							wage_mark_down =  WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

						}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED){

							wage_mark_down = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

					}

				}


				switch(job_application_list.array[j].general_skill)
				{

					/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 1*/
					case 1:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 2:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 3:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 4:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 5:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;
				}


				/*logit = exp(x*general_skill + y* specific skills):
				x and y are sensivity parameters and determine the effect of the skills on the value of the logit*/
				denominator_logit+= exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + LOGIT_PARAMETER_SPECIFIC_SKILLS*log(cost_per_productivity));

			}

			/*The denominator of the logit model has to be greater than 0.*/   
			if(denominator_logit>0 )
			{
				/*For each vacancy calculate the logit for each (remaining) applicant according to his general/specific skills.*/
				for(j = 0; j< job_application_list.size;j++)
				{



						double cost_per_productivity = 0.0001;

						double wage_mark_down = 1.0;

						if(job_application_list.array[j].job_type && POLICY_MIGRATION_WAGE_SUBSIDIES){

							if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){

									wage_mark_down =  WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

								}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED){

									wage_mark_down = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

							}

						}
					switch(job_application_list.array[j].general_skill)
					{
						/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 1*/
						case 1:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 2:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 3:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 4:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 5:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;
					}


						logit = exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill +
						LOGIT_PARAMETER_SPECIFIC_SKILLS*log(cost_per_productivity))/ denominator_logit;


					/*Store the applicant_id and the corresponding logit in a list.*/
					add_logit(&logit_applications_list, 
					100*logit,job_application_list.array[j].worker_id,
					job_application_list.array[j].general_skill,job_application_list.array[j].wage_offer, job_application_list.array[j].job_type);
				}
			}
			
			/*This draws a random number*/
			random_number =  (double)random_int(0,100);

			sum_of_logits = 0;
			for(j = 0; j< logit_applications_list.size;j++)
			{
				sum_of_logits += logit_applications_list.array[j].logit_value;

				/*Check if the random number is smaller than the (cumulative) sum of logits over (remaining applicants):
				If the value of the applicants logit is high the probability that the random number is smaller than the sum of
				logits is also high.*/
				if(random_number<sum_of_logits)
				{
					/*If condition is true, the firm chooses that worker and 
					send a job offer with the corresponding wage offer   */ 

							add_job_offer_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							logit_applications_list.array[j].wage_offer,logit_applications_list.array[j].job_type);

					/*The chosen worker has to be removed from the application list*/
					for(k = 0; k< job_application_list.size;k++)
					{
						if(job_application_list.array[k].worker_id == logit_applications_list.array[j].worker_id)
						{
							remove_job_application(&job_application_list,k);
							break;
						}
					}
					
					/*If one job offer was sent stop traversing the application list and go to the next vacancy.*/
					break;  
				}
			}
			/* Free the job application dynamic array */
			free_logit_array(&logit_applications_list);
		}
	}




	/* Free the job application dynamic array */
	free_job_application_array(&job_application_list);

	return 0;
}



/** \fn Firm_read_job_responses()
 * \brief:
	- Firm reads job responses and add employees.
 */
int Firm_read_job_responses()
{   
	START_JOB_ACCEPTANCE_MESSAGE_LOOP

		/* Read job acceptance messages for this Firm */
		if(job_acceptance_message->firm_id == ID)
		{
			/*Add employee to employee list, increase the number of overall employees by 1 
			and decrease the number of vacancies.*/
			NO_EMPLOYEES_PRODUCTION++;
			NO_EMPLOYEES++;
			VACANCIES--;

			double wage_offer;


			if(job_acceptance_message->job_type)
				NO_EMPLOYEES_SUBSIDIZED++;

			double subsidies = 0;

			/*Explore the general skill level of the new worker.*/
			switch(job_acceptance_message->general_skill)
			{
				/*If new employee has general skill level 1 add him to the employee list and increase the number of 
				employees with general skill level 1 by 1.*/
				case 1:

					wage_offer = WAGE_OFFER_FOR_SKILL_1;

					if(job_acceptance_message->job_type==1){

						if(POLICY_MIGRATION_TOP_UP_BENEFITS ){

							wage_offer = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1);

						}

						if(POLICY_MIGRATION_WAGE_SUBSIDIES){


							if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){


								wage_offer = WAGE_OFFER_FOR_SKILL_1;

								subsidies = (1 - WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1);


							}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED)

								wage_offer = WAGE_OFFER_FOR_SKILL_1;

								subsidies = (1 - WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1);

						}


					}



					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  wage_offer,
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill, subsidies);

					NO_EMPLOYEES_SKILL_1++;
					break;

				case 2:


					wage_offer = WAGE_OFFER_FOR_SKILL_2;


					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  wage_offer,
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_2++;
					break;

				case 3:



					wage_offer = WAGE_OFFER_FOR_SKILL_3;

					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  wage_offer,
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_3++;
					break;

				case 4:


					wage_offer = WAGE_OFFER_FOR_SKILL_4;

					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  wage_offer,
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_4++;
					break;
					
				/*If new employee has general skill level 5 add him to the employee list and increase the number of 
				employees with general skill level 5 by 1.*/
				case 5:


					wage_offer = WAGE_OFFER_FOR_SKILL_5;

					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  wage_offer,
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_5++;
					break;
			}   
		}

	FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP

	return 0;
}



/** \fn Firm_update_wage_offer()
 * \brief: 
	- Firm increases the basic wage_offer to get more applications in the next round if there are unfilled vacancies left.
 */
int Firm_update_wage_offer()
{

	double wage_offer_update = WAGE_UPDATE;

		//if(REG_DIFF_UNION_STRENGTH && REGION_ID==1)
		//wage_offer_update = REG2_FACTOR_UNION_STRENGTH;

	/*If there are "a lot" of vacancies still open...*/ 
	double vacanc_ratio = 0.0;

	if(POSTED_VACANCIES > 0)
		vacanc_ratio = VACANCIES/(1.0*POSTED_VACANCIES);

	if( ((vacanc_ratio > 0.5)) && DAY >= TRANSITION_PHASE)
	{


		/*Update the basic wage offer.*/
		WAGE_OFFER = WAGE_OFFER*(1+wage_offer_update);

		/*Update the general skill dependend wage offers.*/

		if(!(fabs(WAGE_OFFER_FOR_SKILL_1-MINIMUM_WAGE)<1e-5))
			WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER_FOR_SKILL_1*(1+wage_offer_update);
		if(!(fabs(WAGE_OFFER_FOR_SKILL_2-MINIMUM_WAGE)<1e-5))
			WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER_FOR_SKILL_2*(1+wage_offer_update);
		if(!(fabs(WAGE_OFFER_FOR_SKILL_3-MINIMUM_WAGE)<1e-5))
			WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER_FOR_SKILL_3*(1+wage_offer_update);
		if(!(fabs(WAGE_OFFER_FOR_SKILL_4-MINIMUM_WAGE)<1e-5))
			WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER_FOR_SKILL_4*(1+wage_offer_update);
		if(!(fabs(WAGE_OFFER_FOR_SKILL_5-MINIMUM_WAGE)<1e-5))
			WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER_FOR_SKILL_5*(1+wage_offer_update);
	}
	if(VACANCIES_R_AND_D_EMPLOYEES>0)
	{
		BASE_WAGE_OFFER_R_AND_D=BASE_WAGE_OFFER_R_AND_D*(1+wage_offer_update);
		WAGE_OFFER_FOR_R_AND_D_EMPLOYEES = WAGE_OFFER_FOR_R_AND_D_EMPLOYEES*(1+wage_offer_update);

	}

return 0;
}



/** \fn Firm_send_vacancies_2()
 * \brief: 
	- Firms which  did not fill all vacancies post vacancies and wage offer and send vacancies message
 */
int Firm_send_vacancies_2()
{

	/* If vacancies left */
	if(VACANCIES > 0)
	{
		/*For every general skill level (1-5)*/		
		add_vacancies2_message(ID, 
		REGION_ID, 
		WAGE_OFFER_FOR_SKILL_1, 
		WAGE_OFFER_FOR_SKILL_2, 
		WAGE_OFFER_FOR_SKILL_3, 
		WAGE_OFFER_FOR_SKILL_4, 
		WAGE_OFFER_FOR_SKILL_5);
	}   

	if(VACANCIES_R_AND_D_EMPLOYEES > 0)
	{
		add_vacancies_r_and_d_employees2_message(ID, 
		REGION_ID, WAGE_OFFER_FOR_R_AND_D_EMPLOYEES);
	}

	return 0;
}




/** \fn Firm_read_job_applications_send_offer_or_rejection_2()
 * \brief: 
	- Firm reads job applications. 
	- Firm sends job offers.
		1: If number of applicants is smaller than the number of vacancies: send job offer to each applicant.
		2: If number of applicant is higher than the number of vacancies: use logit model.
			Applicants with higher general skills have a higher probability to receive a job offer.
 */
int Firm_read_job_applications_send_job_offer_or_rejection_2()
{
	int i;
	int j;
	int k;
	int no_applications;
	int counter_subsidized_workers;
	int considered;

	double contribution_margin;

	/* Create a job application dynamic array */
	job_application_array job_application_list; 
	init_job_application_array(&job_application_list);

	job_application_array r_and_d_job_application_list; 
	init_job_application_array(&r_and_d_job_application_list);


	counter_subsidized_workers = NO_EMPLOYEES_SUBSIDIZED;

	START_JOB_APPLICATION2_MESSAGE_LOOP

	int eff_wage_below_minimum_wage = 0;


		double wage_offer;
		double wage_mark_down = 1.0;


				switch(job_application2_message->general_skill)
				{
					/*Check if the expected average specific skill is >0; otherwise this application is not considered*/
					case 1:


						wage_offer = WAGE_OFFER_FOR_SKILL_1;

						if(fabs(WAGE_OFFER_FOR_SKILL_1- MINIMUM_WAGE )<1e-5 && job_application2_message->job_type){

							eff_wage_below_minimum_wage = 1;

							if(POLICY_MIGRATION_TOP_UP_BENEFITS ){

								wage_offer = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1);

							}

							if(POLICY_MIGRATION_WAGE_SUBSIDIES){


								if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){

									wage_mark_down =  WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

								}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED)

									wage_mark_down = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

							}


						}

						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1) - wage_offer*wage_mark_down )/ (wage_offer*wage_mark_down);

						break;

					case 2:

						wage_offer = WAGE_OFFER_FOR_SKILL_2;

						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2) - wage_offer )/wage_offer;
						break;

					case 3:

						wage_offer = WAGE_OFFER_FOR_SKILL_3;

						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3) - wage_offer)/wage_offer;

						break;

					case 4:

						wage_offer = WAGE_OFFER_FOR_SKILL_4;


						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4) - wage_offer )/wage_offer;


						break;


					case 5:

						wage_offer = WAGE_OFFER_FOR_SKILL_5;

						contribution_margin = (PRICE*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5) - wage_offer )/wage_offer;


						break;
				}


		/* Read job application messages for this Firm */

				double prob = exp(LOGIT_PARAMETER_WORKER_PRESELECTION* (contribution_margin + 0.1))/(1 + exp(LOGIT_PARAMETER_WORKER_PRESELECTION* (contribution_margin + 0.1)));

				double random = random_unif();


				if(random < prob){

					/*Add application to application list.*/
					add_job_application(&job_application_list,
					job_application2_message->worker_id,
					job_application2_message->region_id,
					job_application2_message->general_skill,
					job_application2_message->specific_skill, wage_offer, eff_wage_below_minimum_wage);


				}

	FINISH_JOB_APPLICATION2_MESSAGE_LOOP


	no_applications = job_application_list.size;
	NO_APPLICATIONS_ROUND_2 = no_applications;

	/*Sort the applications. Highest general skills first.*/
	/*qsort(job_application_list.array, job_application_list.size, 
	sizeof(job_application), job_application_list_rank_general_skill_function);*/

	/*Case 1: Number of Vacancies is equal or higher than number of applications:
	each applicant gets a job offer*/   
	if(no_applications <= VACANCIES)
	{	
		for(i = 0; i < (job_application_list.size); i++)
				{
					add_job_offer2_message(ID,
						job_application_list.array[i].worker_id,
						REGION_ID,
						job_application_list.array[i].wage_offer,job_application_list.array[i].job_type);

				}


	}
	/*Case 2: Number of Vacancies is smaller  than number of applications:
	firm choose applicants using a logit model*/
	else
	{
		/*For each vacancy to fill...*/
		for(i = 0; i< VACANCIES; i++)
		{
			/*Create temporary array to store logits of the applicants.*/
			logit_array  logit_applications_list;
			init_logit_array(&logit_applications_list);

			/*Variables for the logit*/
			double denominator_logit = 0;
			double logit = 0.0;
			double sum_of_logits;
			double random_number;




			/*For each vacancy to fill sum up the logits of all (remaining) applicants.*/
			for(j = 0; j< job_application_list.size;j++)
			{

				double cost_per_productivity = 0.0;

				double wage_mark_down = 1.0;

				if(job_application_list.array[j].job_type && POLICY_MIGRATION_WAGE_SUBSIDIES){

					if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){

							wage_mark_down =  WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

						}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED){

							wage_mark_down = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

					}

				}


				switch(job_application_list.array[j].general_skill)
					{
				/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 1*/
					case 1:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 2:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 3:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 4:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;

					case 5:

						cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5)/(wage_mark_down*job_application_list.array[j].wage_offer);
						break;
					}



				/*logit = exp(x*general_skill + y* specific skills):
				x and y are sensivity parameters and determine the effect of the skills on the value of the logit*/
				denominator_logit+= exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + LOGIT_PARAMETER_SPECIFIC_SKILLS*log(cost_per_productivity));


			}

			/*The denominator of the logit model has to be greater than 0.*/   
			if(denominator_logit>0 )
			{

				double cost_per_productivity = 0;

				/*For each vacancy calculate the logit for each (remaining) applicant according to his general/specific skills.*/
				for(j = 0; j< job_application_list.size;j++)
				{
					double wage_mark_down = 1.0;

					if(job_application_list.array[j].job_type && POLICY_MIGRATION_WAGE_SUBSIDIES){

						if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){

								wage_mark_down =  WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

							}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED){

								wage_mark_down = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1;

						}

					}


					switch(job_application_list.array[j].general_skill)
					{
						/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 1*/
						case 1:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 2:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 3:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 4:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;

						case 5:

							cost_per_productivity = min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5)/(wage_mark_down*job_application_list.array[j].wage_offer);
							break;
					}

					logit = exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill +
										LOGIT_PARAMETER_SPECIFIC_SKILLS*log(cost_per_productivity))/ denominator_logit;


					/*Store the applicant_id and the corresponding logit in a list.*/
					add_logit(&logit_applications_list, 
					100*logit,job_application_list.array[j].worker_id,
					job_application_list.array[j].general_skill,job_application_list.array[j].wage_offer, job_application_list.array[j].job_type);
				}
			}
			
			/*This draws a random number*/
			random_number =  (double)random_int(0,100);

			sum_of_logits = 0;
			for(j = 0; j< logit_applications_list.size;j++)
			{
				sum_of_logits += logit_applications_list.array[j].logit_value;

				/*Check if the random number is smaller than the (cumulative) sum of logits over (remaining applicants):
				If the value of the applicants logit is high the probability that the random number is smaller than the sum of
				logits is also high.*/
				if(random_number<sum_of_logits)
				{
					/*If condition is true, the firm chooses that worker and 
					send a job offer with the corresponding wage offer   */ 

							add_job_offer2_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							logit_applications_list.array[j].wage_offer,logit_applications_list.array[j].job_type);
							

					/*The chosen worker has to be removed from the application list*/
					for(k = 0; k< job_application_list.size;k++)
					{
						if(job_application_list.array[k].worker_id == logit_applications_list.array[j].worker_id)
						{
							remove_job_application(&job_application_list,k);
							break;
						}
					}
					
					/*If one job offer was sent stop traversing the application list and go to the next vacancy.*/
					break;  
				}
			}
			/* Free the job application dynamic array */
			free_logit_array(&logit_applications_list);
		}
	}



	/* Free the job application dynamic array */
	free_job_application_array(&job_application_list);



	return 0;
}



/** \fn Firm_read_job_responses_2()
 * \brief:
	- Firm reads job responses and add employees.
 */
int Firm_read_job_responses_2()
{   
	START_JOB_ACCEPTANCE2_MESSAGE_LOOP

		/* Read job acceptance messages for this Firm */
		if(job_acceptance2_message->firm_id == ID )
		{
			/*Add employee to employee list, increase the number of overall employees by 1 
			and decrease the number of vacancies.*/
			NO_EMPLOYEES_PRODUCTION++;
			NO_EMPLOYEES++;
			VACANCIES--;

			if(job_acceptance2_message->job_type){

				NO_EMPLOYEES_SUBSIDIZED++;

			}

			double wage_offer;


			double subsidies = 0.0;

			/*Explore the general skill level of the new worker.*/
			switch(job_acceptance2_message->general_skill)
			{
				/*If new employee has general skill level 1 add him to the employee list and increase the number of 
				employees with general skill level 1 by 1.*/
				case 1:

					wage_offer = WAGE_OFFER_FOR_SKILL_1;

					if(job_acceptance2_message->job_type==1){

						if(POLICY_MIGRATION_TOP_UP_BENEFITS ){

							wage_offer = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1);

						}


						if(POLICY_MIGRATION_WAGE_SUBSIDIES){


							if(POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED && (TECHNOLOGY > AVERAGE_TECHNOLOGY_FROM_EUROSTAT) ){


								wage_offer = WAGE_OFFER_FOR_SKILL_1;

								subsidies = (1 - WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1);


							}else if(!POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED)

								wage_offer = WAGE_OFFER_FOR_SKILL_1;

								subsidies = (1 - WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1)/ WAGE_OFFER_FOR_SKILL_1);

						}


					}

					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  wage_offer,
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_1++;
					break;

				case 2:

					wage_offer = WAGE_OFFER_FOR_SKILL_2;

					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  wage_offer,
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_2++;
					break;

				case 3:

					wage_offer = WAGE_OFFER_FOR_SKILL_3;

					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  wage_offer,
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_3++;
					break;

				case 4:

					wage_offer = WAGE_OFFER_FOR_SKILL_4;

					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  wage_offer,
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_4++;
					break;
					
				/*If new employee has general skill level 5 add him to the employee list and increase the number of 
				employees with general skill level 5 by 1.*/
				case 5:

					wage_offer = WAGE_OFFER_FOR_SKILL_5;

					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  wage_offer,
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill,subsidies);

					NO_EMPLOYEES_SKILL_5++;
					break;
			}   
		}

	FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP

	return 0;
}



/** \fn Firm_update_wage_offer_2()
 * \brief: 
	- Firm increases the basic wage_offer to get more applications in the next month if there are unfilled vacancies left.
 */
int Firm_update_wage_offer_2()
{
	/*If there are "a lot" of vacancies still open...*/ 
	//if(VACANCIES > MIN_VACANCY)  
	//{
		/*Update the basic wage offer.*/
		//WAGE_OFFER = WAGE_OFFER*(1+WAGE_UPDATE);

		/*Update the general skill dependend wage offers.*/
		//WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER_FOR_SKILL_1*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER_FOR_SKILL_2*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER_FOR_SKILL_3*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER_FOR_SKILL_4*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER_FOR_SKILL_5*(1+WAGE_UPDATE);
	//} 

	return 0;
}



/** \fn Firm_compute_mean_wage_specific_skills()
 * \brief: 
	- Firm computes the mean wage, mean specific skills and mean general skills of the workforce
 */
int Firm_compute_mean_wage_specific_skills()
{

	int i,j;
	double ave_wage =0.0;
	double ave_specific_skills =0.0;
	double ave_general_skills =0.0;
	double ave_wage_r_and_d =0.0;
	double ave_adaptation_speed = 0.0;

	/*Sum up the wage and the specific skills of each worker.*/
	for(i=0;i<EMPLOYEES.size;i++)
	{
		ave_wage+=EMPLOYEES.array[i].wage;
		ave_specific_skills += EMPLOYEES.array[i].specific_skill;
		ave_general_skills += EMPLOYEES.array[i].general_skill;

		// If the spec. skill update is according to the predetermined speeds:
		if(SKILL_UPDATE_ACC_TO_FORMULA==0)
		{
			for(j=0; j<  LIST_ADAPTATION_SPEED_PER_SKILL_GROUP.size;j++)
			{
				if(LIST_ADAPTATION_SPEED_PER_SKILL_GROUP.array[j].general_skill_level==  EMPLOYEES.array[i].general_skill)
				{
					ave_adaptation_speed += LIST_ADAPTATION_SPEED_PER_SKILL_GROUP.array[j].adaptation_speed; 
					break;
				}
			}
		}
		
	}

	/*If the firm has no employees*/
	double no_employees = (double) NO_EMPLOYEES_PRODUCTION;
	if(no_employees==0)
	{
		MEAN_WAGE = WAGE_OFFER *  AVERAGE_S_SKILL_FROM_EUROSTAT;
		MEAN_SPECIFIC_SKILLS = AVERAGE_S_SKILL_FROM_EUROSTAT;
	}
	/*If the firm has  employees calculate the mean wage and mean specific skills.*/
	else
	{
		MEAN_WAGE = ave_wage /( no_employees);
		MEAN_SPECIFIC_SKILLS =ave_specific_skills/no_employees;
		AVERAGE_G_SKILL = ave_general_skills/no_employees;

		// If the spec. skill update is according to the predetermined speeds:
		if(SKILL_UPDATE_ACC_TO_FORMULA==0)
		{
			AVERAGE_ADAPTATION_SPEED_SPECIFIC_SKILLS = ave_adaptation_speed /( 1.0*no_employees);
		}
	}


	/*Compute the mean wage of R and D employees:*/
	for(i=0;i<R_AND_D_EMPLOYEES.size;i++)
	{
		ave_wage_r_and_d+=R_AND_D_EMPLOYEES.array[i].wage;
	}
	/*If the firm has no employees*/
	double no_employees_r_and_d = (double) NO_EMPLOYEES_INNOVATION;
	if(no_employees_r_and_d==0)
	{
		MEAN_WAGE_R_AND_D = WAGE_OFFER_FOR_R_AND_D_EMPLOYEES*  AVERAGE_S_SKILL_FROM_EUROSTAT;
	}
	/*If the firm has  employees calculate the mean wage and mean specific skills.*/
	else
	{
		MEAN_WAGE_R_AND_D = ave_wage_r_and_d /( no_employees_r_and_d);
	}
	/*Compute the total mean wage (Mean wage of both types of employees)*/
	if(NO_EMPLOYEES > 0)
	{
		TOTAL_MEAN_WAGE = no_employees_r_and_d/(1.0*NO_EMPLOYEES)*MEAN_WAGE + MEAN_WAGE_R_AND_D*no_employees/(1.0*NO_EMPLOYEES);
	}else
	{
		TOTAL_MEAN_WAGE=MEAN_WAGE;
	}
	return 0;
}


/************************************ Firm agent auxiliary functions ************************************/

int Firm_finish_labour_market_first_round()
{
	return 0;
}

int Firm_start_labour_market()
{
	return 0;
}

int Firm_read_job_quitting()
{

	return 0;
}

int Firm_read_job_quitting_2()
{

	return 0;
}


