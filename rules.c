/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

/** \fn int FLAME_integer_in_array(int a, int * b, int size)
 * \brief Returns 1 if an integer is a member of an integer array, else 0
 * \param a The integer to check.
 * \param b Pointer to the integer array.
 * \param size The size of the array
 * \return 1 for true, 0 for false.
 */
int FLAME_integer_in_array(int a, int * b, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		if(a == b[i]) return 1;
	}
	
	return 0;
}

/** \fn void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
 * \brief Create memory to hold agent filter variables for every agent using the filter on the current node.
 * \param agent_number The number of agent types.
 * \param agent_count List of the number of agents of each agent type.
 * \param agent_struct_size The struct size needed for each agent type.
 * \param cparam_size The size of the memory created.
 * \return Pointer to the created memory.
 */
void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
{
	/* Pointer to the memory created that is going to be returned */
	void *data;
	/* Variable used in for loops */
	int i;
	/* Variable to hold total size of memory required for agent structures */
	size_t total_param_size = 0;

	/* For each agent type add required memory for agent structures */
	for(i = 0; i < agent_number; i++)
	{
		total_param_size += agent_count[i] * agent_struct_size[i];
	}

	//assert(count > 0);
	//assert(total_param_size > 0);
	/* Does libmboard free this memory? */
	
	/* Allocate required memory, where memory holds the number
	 * of each agent type, in order, and the total required
	 * memory for agent structures */
	data = malloc(agent_number*sizeof(int) + total_param_size);
	/* Make the memory size parameter equal to the actual memory size */
	*cparam_size = agent_number*sizeof(int) + total_param_size;
	/* Assert that the created memory was successfully created and not null */
	assert(data != NULL);

	/* Return the pointer to the created memory */
	return data;
}


/** \fn int FLAME_condition_Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_14_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_14_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_variables_reset(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_variables_reset(xmachine_memory_Firm *a)
{
	if((a->equity < 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if(!(a->equity < 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_check_financial_and_bankruptcy_state_Firm_End_Credit_Role_Firm_bankruptcy_checked(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_check_financial_and_bankruptcy_state_Firm_End_Credit_Role_Firm_bankruptcy_checked(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_variables_reset2(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_variables_reset2(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_illiquidity_state == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_minsky_state_crisis_Firm_checks_financial_crisis_Firm_resolve_financial_crisis(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_minsky_state_crisis_Firm_checks_financial_crisis_Firm_resolve_financial_crisis(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_illiquidity_state == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_bankruptcy_generic_procedure_Firm_not_active_Firm_bankruptcy_state_0(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_bankruptcy_generic_procedure_Firm_not_active_Firm_bankruptcy_state_0(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_idle_counter == 239)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_not_active_Firm_bankruptcy_state_0(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_not_active_Firm_bankruptcy_state_0(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_idle_counter != 239)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_bankruptcy_reset_delayed_Firm_bankruptcy_state_01_Firm_bankruptcy_state_1(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_bankruptcy_reset_delayed_Firm_bankruptcy_state_01_Firm_bankruptcy_state_1(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_bankruptcy_state_01_Firm_bankruptcy_state_1(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_bankruptcy_state_01_Firm_bankruptcy_state_1(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_bankruptcy_idle_counter_Firm_checks_if_active_Firm_not_active(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_bankruptcy_idle_counter_Firm_checks_if_active_Firm_not_active(xmachine_memory_Firm *a)
{
	if((a->active == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_checks_if_active_Firm_is_active(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_checks_if_active_Firm_is_active(xmachine_memory_Firm *a)
{
	if((a->active == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_remains_in_bankruptcy_Firm_bankruptcy_state_1_Firm_bankruptcy_state_4(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_remains_in_bankruptcy_Firm_bankruptcy_state_1_Firm_bankruptcy_state_4(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0001)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_reset_bankruptcy_flags_Firm_bankruptcy_state_4_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_reset_bankruptcy_flags_Firm_bankruptcy_state_4_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_idle_counter == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_bankruptcy_state_4_Firm_End_Branches(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_bankruptcy_state_4_Firm_End_Branches(xmachine_memory_Firm *a)
{
	if(!(a->bankruptcy_idle_counter == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_bankruptcy_state_1_Firm_bankruptcy_state_4(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_bankruptcy_state_1_Firm_bankruptcy_state_4(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0001)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_send_vacancies_04ccc_03(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_send_vacancies_04ccc_03(xmachine_memory_Firm *a)
{
	if(((a->vacancies > 0) || (a->vacancies_r_and_d_employees > 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_send_redundancies_011_03ccc(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_send_redundancies_011_03ccc(xmachine_memory_Firm *a)
{
	if(((a->no_redundancies > 0) || (a->no_redundancies_r_and_d_employees > 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_011_03ccc(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_011_03ccc(xmachine_memory_Firm *a)
{
	if(((a->no_redundancies == 0) && (a->no_redundancies_r_and_d_employees == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_finish_labour_market_first_round_05b_09a(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_finish_labour_market_first_round_05b_09a(xmachine_memory_Firm *a)
{
	if(((a->vacancies == 0) && (a->vacancies_r_and_d_employees == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_update_wage_offer_05b_06(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_update_wage_offer_05b_06(xmachine_memory_Firm *a)
{
	if(((a->vacancies > 0) || (a->vacancies_r_and_d_employees > 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_update_wage_offer_2_09b_10(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_update_wage_offer_2_09b_10(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_09b_10(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_09b_10(xmachine_memory_Firm *a)
{
	if(!(a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_04ccc_03c(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_04ccc_03c(xmachine_memory_Firm *a)
{
	if(((a->vacancies == 0) && (a->vacancies_r_and_d_employees == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_send_id_to_malls_start_Firm_Firm_initialize(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_send_id_to_malls_start_Firm_Firm_initialize(xmachine_memory_Firm *a)
{
	if((iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_start_Firm_Firm_reset(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_start_Firm_Firm_reset(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_reset_variables_Firm_reset_Firm_init_01(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_reset_variables_Firm_reset_Firm_init_01(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_reset_Firm_interest(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_reset_Firm_interest(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_receive_data_Firm_init_01_Firm_interest(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_receive_data_Firm_init_01_Firm_interest(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_send_data_to_Eurostat_Firm_End_Branches_Firm_Send_Data(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_send_data_to_Eurostat_Firm_End_Branches_Firm_Send_Data(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_End_Branches_15(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_End_Branches_15(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_analyze_questionnaire_MR_3_MR_4(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_analyze_questionnaire_MR_3_MR_4(xmachine_memory_Firm *a)
{
	if((a->market_research_active == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_MR_3_MR_4(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_MR_3_MR_4(xmachine_memory_Firm *a)
{
	if((a->market_research_active != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_prepone_vintage_choice_MR_4_MR_4a(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_prepone_vintage_choice_MR_4_MR_4a(xmachine_memory_Firm *a)
{
	if((iteration_loop%240 == a->day_of_year_price_setting)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_decide_product_innovation_MR_5_MR_6(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_decide_product_innovation_MR_5_MR_6(xmachine_memory_Firm *a)
{
	if((a->product_innovation != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_MR_5_MR_6(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_MR_5_MR_6(xmachine_memory_Firm *a)
{
	if((a->product_innovation == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_market_research_data_pricing_MR_02_MR_03(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_market_research_data_pricing_MR_02_MR_03(xmachine_memory_Firm *a)
{
	if((a->market_research_delayed == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_bypass_setting_if_delayed_MR_02_MR_0(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_bypass_setting_if_delayed_MR_02_MR_0(xmachine_memory_Firm *a)
{
	if((a->market_research_delayed != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_market_research_data_innovation_MR_03_MR_0(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_market_research_data_innovation_MR_03_MR_0(xmachine_memory_Firm *a)
{
	if((a->product_innovation == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_MR_03_MR_0(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_MR_03_MR_0(xmachine_memory_Firm *a)
{
	if((a->product_innovation != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_release_new_product_MR_01_MR_02(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_release_new_product_MR_01_MR_02(xmachine_memory_Firm *a)
{
	if((a->remaining_periods_to_complete_product_development == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_Firm_Start_Market_Research_Role_MR_3(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_Firm_Start_Market_Research_Role_MR_3(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%240 == a->day_of_year_market_research)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_Firm_Start_Market_Research_Role_MR_01(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_Firm_Start_Market_Research_Role_MR_01(xmachine_memory_Firm *a)
{
	if((iteration_loop%240 == a->day_of_year_market_research)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_MR_01_MR_02(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_MR_01_MR_02(xmachine_memory_Firm *a)
{
	if((a->remaining_periods_to_complete_product_development != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_MR_4_Firm_Start_Producer_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_MR_4_Firm_Start_Producer_Role(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%240 == a->day_of_year_price_setting)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_09_15(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_09_15(xmachine_memory_Household *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_rank_and_buy_goods_1_09_10(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_rank_and_buy_goods_1_09_10(xmachine_memory_Household *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_set_values_zero_11_14(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_set_values_zero_11_14(xmachine_memory_Household *a)
{
	if((a->rationed != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_rank_and_buy_goods_2_11_12(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_rank_and_buy_goods_2_11_12(xmachine_memory_Household *a)
{
	if((a->rationed == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_receive_index_info_Household_Start_Financial_Market_Role_AFM_000(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_receive_index_info_Household_Start_Financial_Market_Role_AFM_000(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_idle_Household_Start_Financial_Market_Role_AFM_000(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_idle_Household_Start_Financial_Market_Role_AFM_000(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_receive_index_price_AFM_000_AFM_001(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_receive_index_price_AFM_000_AFM_001(xmachine_memory_Household *a)
{
	if(((iteration_loop%20 == a->day_of_month_to_act) && (TRADING_ACTIVITY == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_idle_AFM_000_Household_Start_Labour_Role(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_idle_AFM_000_Household_Start_Labour_Role(xmachine_memory_Household *a)
{
	if((!(iteration_loop%20 == a->day_of_month_to_act) || (TRADING_ACTIVITY == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_01d_01a(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_01d_01a(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_Household_Start_Labour_Role_01a(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_Household_Start_Labour_Role_01a(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_01d_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_01d_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_finish_labour_market_02_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_finish_labour_market_02_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_02_03(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_02_03(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_2_05_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_2_05_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_05_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_05_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_06b_09(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_06b_09(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_06b_06c(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_06b_06c(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_receive_wage_06e_07(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_receive_wage_06e_07(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_send_unemployment_benefit_notification_06e_08(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_send_unemployment_benefit_notification_06e_08(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_reset_variables_start_Household_Household_initialize(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_reset_variables_start_Household_Household_initialize(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_idle_start_Household_Household_initialize(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_idle_start_Household_Household_initialize(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_initialization_Household_initialize_Household_Start_Yearly_Loop_Top(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_initialization_Household_initialize_Household_Start_Yearly_Loop_Top(xmachine_memory_Household *a)
{
	if((iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_idle_Household_initialize_Household_Start_Yearly_Loop_Top(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_idle_Household_initialize_Household_Start_Yearly_Loop_Top(xmachine_memory_Household *a)
{
	if(!(iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_human_capital_policy_Pol_01_Household_Start_Policy_Data(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_human_capital_policy_Pol_01_Household_Start_Policy_Data(xmachine_memory_Household *a)
{
	if((a->human_capital_policy_flag == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_Pol_01_Household_Start_Policy_Data(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_Pol_01_Household_Start_Policy_Data(xmachine_memory_Household *a)
{
	if((a->human_capital_policy_flag != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_idle_Household_Start_Yearly_Loop_Top_Household_Start_Policy_Data(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_idle_Household_Start_Yearly_Loop_Top_Household_Start_Policy_Data(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_send_data_to_Eurostat_16_17(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_send_data_to_Eurostat_16_17(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_idle_16_17(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_idle_16_17(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_idle_17_end_Household(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_idle_17_end_Household(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_data_from_Eurostat_17_end_Household(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_data_from_Eurostat_17_end_Household(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_HH_MR_1_Household_Start_Financial_Market_Role(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_HH_MR_1_Household_Start_Financial_Market_Role(xmachine_memory_Household *a)
{
	if((a->willingness_to_attend != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_respond_HH_MR_1_HH_MR_2(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_respond_HH_MR_1_HH_MR_2(xmachine_memory_Household *a)
{
	if((a->willingness_to_attend == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_Mall_reset_export_data_001_01(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_Mall_reset_export_data_001_01(xmachine_memory_Mall *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_idle_001_01(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_idle_001_01(xmachine_memory_Mall *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_Mall_send_export_data_06_end_Mall(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_Mall_send_export_data_06_end_Mall(xmachine_memory_Mall *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_idle_06_end_Mall(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_idle_06_end_Mall(xmachine_memory_Mall *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_Mall_send_id_to_firms_start_Mall_Mall_initialize(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_Mall_send_id_to_firms_start_Mall_Mall_initialize(xmachine_memory_Mall *a)
{
	if((iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_idle_start_Mall_001(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_idle_start_Mall_001(xmachine_memory_Mall *a)
{
	if(!(iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_execute_financial_payments_01kk_IGFirm_End_Financial_Management(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_execute_financial_payments_01kk_IGFirm_End_Financial_Management(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_idle_IGFirm_Start_Financial_Management_Role_IGFirm_End_Financial_Management_Role(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_idle_IGFirm_Start_Financial_Management_Role_IGFirm_End_Financial_Management_Role(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_send_subsidy_notification_IGFirm_Start_Financial_Management_Role_05(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_send_subsidy_notification_IGFirm_Start_Financial_Management_Role_05(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_initialize_variables_Start_IGFirm_Productivity_01a(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_initialize_variables_Start_IGFirm_Productivity_01a(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_idle_Start_IGFirm_Productivity_01a(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_idle_Start_IGFirm_Productivity_01a(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_innovation_process_01a_01(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_innovation_process_01a_01(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_idle_01a_01(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_idle_01a_01(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_idle_01kk_02(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_idle_01kk_02(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_reset_variables_IGFirm_start_IGFirm_init_01(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_reset_variables_IGFirm_start_IGFirm_init_01(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_idle_IGFirm_start_IGFirm_interest(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_idle_IGFirm_start_IGFirm_interest(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_send_data_to_Eurostat_IGFirm_End_Branches_IGFirm_Send_Data(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_send_data_to_Eurostat_IGFirm_End_Branches_IGFirm_Send_Data(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_idle_IGFirm_End_Branches_06(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_idle_IGFirm_End_Branches_06(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_send_data_00_01(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_send_data_00_01(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_00_01(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_00_01(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%20 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%20 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%20 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%20 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%60 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%60 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_initialization_start_Eurostat_00(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_initialization_start_Eurostat_00(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_idle_start_Eurostat_00(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_idle_start_Eurostat_00(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_read_policy_rate_Bank_update_policy_rate_Bank_start_credit_market_role(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_read_policy_rate_Bank_update_policy_rate_Bank_start_credit_market_role(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_idle_Bank_update_policy_rate_Bank_start_credit_market_role(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_idle_Bank_update_policy_rate_Bank_start_credit_market_role(xmachine_memory_Bank *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_send_dividend_payment_Bank_01_Bank_01b(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_send_dividend_payment_Bank_01_Bank_01b(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_set_quantities_zero_Bank_01_Bank_01b(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_set_quantities_zero_Bank_01_Bank_01b(xmachine_memory_Bank *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_rank_credit_requests_Bank_02_Bank_021(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_rank_credit_requests_Bank_02_Bank_021(xmachine_memory_Bank *a)
{
	if((a->active == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_idle_Bank_02_Bank_04(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_idle_Bank_02_Bank_04(xmachine_memory_Bank *a)
{
	if((a->active == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_accounting_Bank_06_Bank_07(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_accounting_Bank_06_Bank_07(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_idle_Bank_06_Bank_07(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_idle_Bank_06_Bank_07(xmachine_memory_Bank *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_idle_start_Bank_Bank_update_policy_rate(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_idle_start_Bank_Bank_update_policy_rate(xmachine_memory_Bank *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_read_policy_announcements_start_Bank_Bank_reset(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_read_policy_announcements_start_Bank_Bank_reset(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_initialization_start_Government_Government_Start_Monthly_Loop_Top(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_initialization_start_Government_Government_Start_Monthly_Loop_Top(xmachine_memory_Government *a)
{
	if((iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_start_Government_Government_Start_Monthly_Loop_Top(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_start_Government_Government_Start_Monthly_Loop_Top(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240000000 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_monthly_resetting_Government_Start_Monthly_Loop_Top_001(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_monthly_resetting_Government_Start_Monthly_Loop_Top_001(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_Government_Start_Monthly_Loop_Top_Government_Start_Yearly_Loop_Top(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_Government_Start_Monthly_Loop_Top_Government_Start_Yearly_Loop_Top(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_set_policy_Government_Start_Yearly_Loop_Top_002(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_set_policy_Government_Start_Yearly_Loop_Top_002(xmachine_memory_Government *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_install_human_capital_policy_003_003a(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_install_human_capital_policy_003_003a(xmachine_memory_Government *a)
{
	if((a->human_capital_policy_flag == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_idle_003_003a(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_idle_003_003a(xmachine_memory_Government *a)
{
	if((a->human_capital_policy_flag != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_migration_003b_Gov_Start_Bond_Market(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_migration_003b_Gov_Start_Bond_Market(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 19)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_003b_Gov_Start_Bond_Market(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_003b_Gov_Start_Bond_Market(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 19)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_Government_Start_Yearly_Loop_Top_003b(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_Government_Start_Yearly_Loop_Top_003b(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_Start_Gov_Consumer_Role_Gov_Cons_1(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_Start_Gov_Consumer_Role_Gov_Cons_1(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_determine_consumption_budget_Start_Gov_Consumer_Role_Gov_Cons_1(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_determine_consumption_budget_Start_Gov_Consumer_Role_Gov_Cons_1(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_Gov_Start_Monthly_Loop_06(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_Gov_Start_Monthly_Loop_06(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_resolve_unsold_bonds_dummy_Gov_Start_Monthly_Loop_05a(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_resolve_unsold_bonds_dummy_Gov_Start_Monthly_Loop_05a(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_bonds_issuing_decision_dummy_Gov_bonds_decision_06(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_bonds_issuing_decision_dummy_Gov_bonds_decision_06(xmachine_memory_Government *a)
{
	if((a->total_bond_financing > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_Gov_bonds_decision_06(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_Gov_bonds_decision_06(xmachine_memory_Government *a)
{
	if(!(a->total_bond_financing > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_send_data_to_Eurostat_08_Gov_Start_Yearly_Loop(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_send_data_to_Eurostat_08_Gov_Start_Yearly_Loop(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_08_Gov_Start_Yearly_Loop(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_08_Gov_Start_Yearly_Loop(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_CentralBank_Central_Bank_reset_variables_start_Central_Bank_CB_reset(xmachine_memory_CentralBank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_CentralBank_Central_Bank_reset_variables_start_Central_Bank_CB_reset(xmachine_memory_CentralBank *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_CentralBank_Central_Bank_monetary_policy_CB_reset_CB_market_operations(xmachine_memory_CentralBank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_CentralBank_Central_Bank_monetary_policy_CB_reset_CB_market_operations(xmachine_memory_CentralBank *a)
{
	if((0 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_CentralBank_idle_start_Central_Bank_CB_market_operations(xmachine_memory_CentralBank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_CentralBank_idle_start_Central_Bank_CB_market_operations(xmachine_memory_CentralBank *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_CentralBank_Central_Bank_read_fiat_money_requests_CB_financial_operations_end_00(xmachine_memory_CentralBank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_CentralBank_Central_Bank_read_fiat_money_requests_CB_financial_operations_end_00(xmachine_memory_CentralBank *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_CentralBank_idle_CB_financial_operations_end_00(xmachine_memory_CentralBank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_CentralBank_idle_CB_financial_operations_end_00(xmachine_memory_CentralBank *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_ClearingHouse_ClearingHouse_send_index_info_start_Clearinghouse_AFM_00(xmachine_memory_ClearingHouse *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_ClearingHouse_ClearingHouse_send_index_info_start_Clearinghouse_AFM_00(xmachine_memory_ClearingHouse *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_ClearingHouse_idle_start_Clearinghouse_AFM_00(xmachine_memory_ClearingHouse *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_ClearingHouse_idle_start_Clearinghouse_AFM_00(xmachine_memory_ClearingHouse *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}



/** \fn int FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_capital_good_delivery *m = (m_capital_good_delivery*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_sales *m = (m_sales*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_specific_skill_update *m = (m_specific_skill_update*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_conditions *m = (m_loan_conditions*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_03_04_job_application(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_03_04_job_application(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_03_04_job_application(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_application *m = (m_job_application*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_read_job_responses_04_05a_job_acceptance(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_read_job_responses_04_05a_job_acceptance(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_read_job_responses_04_05a_job_acceptance(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_acceptance *m = (m_job_acceptance*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_2_07_08_job_application2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_2_07_08_job_application2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_2_07_08_job_application2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_application2 *m = (m_job_application2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_read_job_responses_2_08_09a_job_acceptance2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_read_job_responses_2_08_09a_job_acceptance2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_read_job_responses_2_08_09a_job_acceptance2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_acceptance2 *m = (m_job_acceptance2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_eurostat_send_specific_skills(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_eurostat_send_specific_skills(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_eurostat_send_specific_skills(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_eurostat_send_specific_skills *m = (m_eurostat_send_specific_skills*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->region_id == m->region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_policy_announcement(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_policy_announcement(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_send_questionnaire_MR_1_MR_2_interview_positive_response(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_send_questionnaire_MR_1_MR_2_interview_positive_response(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_send_questionnaire_MR_1_MR_2_interview_positive_response(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_interview_positive_response *m = (m_interview_positive_response*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_count_questionnaire_MR_2_MR_3_filled_out_questionnaire_product_innovation(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_count_questionnaire_MR_2_MR_3_filled_out_questionnaire_product_innovation(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Firm_Firm_count_questionnaire_MR_2_MR_3_filled_out_questionnaire_product_innovation(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_filled_out_questionnaire_product_innovation *m = (m_filled_out_questionnaire_product_innovation*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_rank_and_buy_goods_1_09_10_quality_price_info_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_rank_and_buy_goods_1_09_10_quality_price_info_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_rank_and_buy_goods_1_09_10_quality_price_info_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_1 *m = (m_quality_price_info_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_1 *m = (m_accepted_consumption_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->household_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_2 *m = (m_quality_price_info_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_2 *m = (m_accepted_consumption_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->household_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_update_portfolio_AFM_002_Household_Start_Labour_Role_order_status(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_update_portfolio_AFM_002_Household_Start_Labour_Role_order_status(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_update_portfolio_AFM_002_Household_Start_Labour_Role_order_status(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_order_status *m = (m_order_status*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->trader_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firing *m = (m_firing*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->worker_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_01a_01_vacancies_r_and_d_employees(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_01a_01_vacancies_r_and_d_employees(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_01a_01_vacancies_r_and_d_employees(const void *msg, const void *params)\n");
	
	
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->general_skill == 5)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_job_offers_send_response_01_02_job_offer(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_job_offers_send_response_01_02_job_offer(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_read_job_offers_send_response_01_02_job_offer(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_offer *m = (m_job_offer*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->worker_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2_03_04_vacancies_r_and_d_employees2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2_03_04_vacancies_r_and_d_employees2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2_03_04_vacancies_r_and_d_employees2(const void *msg, const void *params)\n");
	
	
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->general_skill == 5)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_job_offers_send_response_2_04_05_job_offer2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_job_offers_send_response_2_04_05_job_offer2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_read_job_offers_send_response_2_04_05_job_offer2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_offer2 *m = (m_job_offer2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->worker_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_wage_payment *m = (m_wage_payment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->worker_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_policy_announcement(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_policy_announcement(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_human_capital_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_human_capital_policy_announcement(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_human_capital_policy_announcement(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_human_capital_policy_announcement *m = (m_human_capital_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_human_capital_policy_Pol_01_Household_Start_Policy_Data_human_capital_policy_new_general_skill_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_human_capital_policy_Pol_01_Household_Start_Policy_Data_human_capital_policy_new_general_skill_notification(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_human_capital_policy_Pol_01_Household_Start_Policy_Data_human_capital_policy_new_general_skill_notification(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_human_capital_policy_new_general_skill_notification *m = (m_human_capital_policy_new_general_skill_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_data_from_Eurostat_17_end_Household_data_for_government(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_data_from_Eurostat_17_end_Household_data_for_government(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_read_data_from_Eurostat_17_end_Household_data_for_government(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_data_for_government *m = (m_data_for_government*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->region_id == m->region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_respond_HH_MR_1_HH_MR_2_interview_request(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_respond_HH_MR_1_HH_MR_2_interview_request(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_respond_HH_MR_1_HH_MR_2_interview_request(const void *msg, const void *params)\n");
	
	
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->willingness_to_attend == 1)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_respond_questionnaire_HH_MR_2_Household_Start_Financial_Market_Role_questionnaire_innovation(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_respond_questionnaire_HH_MR_2_Household_Start_Financial_Market_Role_questionnaire_innovation(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Household_Household_respond_questionnaire_HH_MR_2_Household_Start_Financial_Market_Role_questionnaire_innovation(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_questionnaire_innovation *m = (m_questionnaire_innovation*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->interviewer_id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_consumption_request_1 *m = (m_consumption_request_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Mall *a = (xmachine_memory_Mall *)params;

	/* The filter */
	if((a->id == m->mall_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_consumption_request_2 *m = (m_consumption_request_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Mall *a = (xmachine_memory_Mall *)params;

	/* The filter */
	if((a->id == m->mall_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_eurostat_send_specific_skills(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_eurostat_send_specific_skills(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_eurostat_send_specific_skills(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_eurostat_send_specific_skills *m = (m_eurostat_send_specific_skills*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_IGFirm *a = (xmachine_memory_IGFirm *)params;

	/* The filter */
	if((a->region_id == m->region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_policy_announcement(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_policy_announcement(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_IGFirm *a = (xmachine_memory_IGFirm *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_rank_credit_requests_Bank_02_Bank_021_loan_request(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_rank_credit_requests_Bank_02_Bank_021_loan_request(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Bank_Bank_rank_credit_requests_Bank_02_Bank_021_loan_request(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_request *m = (m_loan_request*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_021_Bank_03_loan_request_ranked(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_021_Bank_03_loan_request_ranked(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_021_Bank_03_loan_request_ranked(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_request_ranked *m = (m_loan_request_ranked*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_acceptance *m = (m_loan_acceptance*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_bank_account_update *m = (m_bank_account_update*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_credit_var_update(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_credit_var_update(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_credit_var_update(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_credit_var_update *m = (m_credit_var_update*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_reset_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_reset_policy_announcement(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_reset_policy_announcement(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_data_from_Eurostat_001_Government_Start_Yearly_Loop_Top_redistributed_subsidies(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_data_from_Eurostat_001_Government_Start_Yearly_Loop_Top_redistributed_subsidies(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_data_from_Eurostat_001_Government_Start_Yearly_Loop_Top_redistributed_subsidies(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_redistributed_subsidies *m = (m_redistributed_subsidies*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_install_human_capital_policy_003_003a_human_capital_policy_general_skill_information(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_install_human_capital_policy_003_003a_human_capital_policy_general_skill_information(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_install_human_capital_policy_003_003a_human_capital_policy_general_skill_information(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_human_capital_policy_general_skill_information *m = (m_human_capital_policy_general_skill_information*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_rank_and_buy_goods_1_Gov_Cons_1_Gov_Cons_2_quality_price_info_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_rank_and_buy_goods_1_Gov_Cons_1_Gov_Cons_2_quality_price_info_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_rank_and_buy_goods_1_Gov_Cons_1_Gov_Cons_2_quality_price_info_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_1 *m = (m_quality_price_info_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_receive_goods_read_rationing_Gov_Cons_2_Gov_Cons_3_accepted_consumption_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_receive_goods_read_rationing_Gov_Cons_2_Gov_Cons_3_accepted_consumption_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_receive_goods_read_rationing_Gov_Cons_2_Gov_Cons_3_accepted_consumption_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_1 *m = (m_accepted_consumption_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->household_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_rank_and_buy_goods_2_Gov_Cons_3_Gov_Cons_4_quality_price_info_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_rank_and_buy_goods_2_Gov_Cons_3_Gov_Cons_4_quality_price_info_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_rank_and_buy_goods_2_Gov_Cons_3_Gov_Cons_4_quality_price_info_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_2 *m = (m_quality_price_info_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_receive_goods_read_rationing_2_Gov_Cons_4_Gov_Cons_5_accepted_consumption_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_receive_goods_read_rationing_2_Gov_Cons_4_Gov_Cons_5_accepted_consumption_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_receive_goods_read_rationing_2_Gov_Cons_4_Gov_Cons_5_accepted_consumption_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_2 *m = (m_accepted_consumption_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->household_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_tax_payment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_tax_payment(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_tax_payment(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_tax_payment *m = (m_tax_payment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_unemployment_benefit_restitution(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_unemployment_benefit_restitution(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_unemployment_benefit_restitution(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_unemployment_benefit_restitution *m = (m_unemployment_benefit_restitution*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_hh_subsidy_notification *m = (m_hh_subsidy_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_subsidy_notification *m = (m_firm_subsidy_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_hh_transfer_notification *m = (m_hh_transfer_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_transfer_notification *m = (m_firm_transfer_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_Gov_Start_Monthly_Loop_unemployment_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_Gov_Start_Monthly_Loop_unemployment_notification(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_Gov_Start_Monthly_Loop_unemployment_notification(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_unemployment_notification *m = (m_unemployment_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_compute_balance_sheet_07_08_ecb_dividend(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_compute_balance_sheet_07_08_ecb_dividend(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_Government_Government_compute_balance_sheet_07_08_ecb_dividend(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_ecb_dividend *m = (m_ecb_dividend*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}


int FLAME_sort_Firm_Firm_calc_input_demands_01_02_productivity(const void *x, const void *y)
{
	if( ((m_productivity *)x)->cap_productivity < ((m_productivity *)y)->cap_productivity ) return -1;
	else if( ((m_productivity *)x)->cap_productivity > ((m_productivity *)y)->cap_productivity ) return 1;
	else return 0;
}
int FLAME_sort_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions(const void *x, const void *y)
{
	if( ((m_loan_conditions *)x)->proposed_interest_rate < ((m_loan_conditions *)y)->proposed_interest_rate ) return -1;
	else if( ((m_loan_conditions *)x)->proposed_interest_rate > ((m_loan_conditions *)y)->proposed_interest_rate ) return 1;
	else return 0;
}
int FLAME_sort_Bank_Bank_decide_credit_conditions_Bank_021_Bank_03_loan_request_ranked(const void *x, const void *y)
{
	if( ((m_loan_request_ranked *)x)->value_at_risk_request < ((m_loan_request_ranked *)y)->value_at_risk_request ) return -1;
	else if( ((m_loan_request_ranked *)x)->value_at_risk_request > ((m_loan_request_ranked *)y)->value_at_risk_request ) return 1;
	else return 0;
}

