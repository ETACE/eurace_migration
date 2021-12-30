/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */
#ifndef _HEADER_H
#define _HEADER_H

#ifdef _DEBUG_MODE
    #define ERRCHECK
#else
    #define NDEBUG
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "mboard.h"

#define FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS 0
#define FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS 0
#define FLAME_USE_FILTERS_IN_SYNC 1


/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT)
#endif


/** \def TOTAL_REGIONS
 * \brief Provide access to environment variables in uppercase. */
#define TOTAL_REGIONS (FLAME_get_environment_variable_total_regions())
/** \def ID_DEBUG_PROBE
 * \brief Provide access to environment variables in uppercase. */
#define ID_DEBUG_PROBE (FLAME_get_environment_variable_id_debug_probe())
/** \def PRINT_LOG
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_LOG (FLAME_get_environment_variable_print_log())
/** \def PRINT_DEBUG_BANKRUPTCY
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_BANKRUPTCY (FLAME_get_environment_variable_print_debug_bankruptcy())
/** \def PRINT_DEBUG_EUROSTAT
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_EUROSTAT (FLAME_get_environment_variable_print_debug_eurostat())
/** \def PRINT_DEBUG_CH
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_CH (FLAME_get_environment_variable_print_debug_ch())
/** \def PRINT_DEBUG_AFM
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_AFM (FLAME_get_environment_variable_print_debug_afm())
/** \def PRINT_DEBUG_AFM_CH
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_AFM_CH (FLAME_get_environment_variable_print_debug_afm_ch())
/** \def PRINT_DEBUG_EXP1
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_EXP1 (FLAME_get_environment_variable_print_debug_exp1())
/** \def PRINT_DEBUG_FILE_EXP1
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_FILE_EXP1 (FLAME_get_environment_variable_print_debug_file_exp1())
/** \def PRINT_DEBUG_FILE_EXP2
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_FILE_EXP2 (FLAME_get_environment_variable_print_debug_file_exp2())
/** \def POLICY_EXP1
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_EXP1 (FLAME_get_environment_variable_policy_exp1())
/** \def PRINT_DEBUG_GOV
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_GOV (FLAME_get_environment_variable_print_debug_gov())
/** \def PRINT_DEBUG_HOUSEHOLD
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_HOUSEHOLD (FLAME_get_environment_variable_print_debug_household())
/** \def PRINT_DEBUG_CREDIT
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_CREDIT (FLAME_get_environment_variable_print_debug_credit())
/** \def PRINT_DEBUG_CONSUMPTION
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_CONSUMPTION (FLAME_get_environment_variable_print_debug_consumption())
/** \def PRINT_DEBUG_FINMAN
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_FINMAN (FLAME_get_environment_variable_print_debug_finman())
/** \def PRINT_DEBUG_PRODUCTION
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_PRODUCTION (FLAME_get_environment_variable_print_debug_production())
/** \def PRINT_DEBUG
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG (FLAME_get_environment_variable_print_debug())
/** \def PRINT_DEBUG_MARKET_RESEARCH
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG_MARKET_RESEARCH (FLAME_get_environment_variable_print_debug_market_research())
/** \def POLICY_EXP_ENERGY_SHOCK
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_EXP_ENERGY_SHOCK (FLAME_get_environment_variable_policy_exp_energy_shock())
/** \def POLICY_EXP_STABILIZATION_SUBSIDY
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_EXP_STABILIZATION_SUBSIDY (FLAME_get_environment_variable_policy_exp_stabilization_subsidy())
/** \def POLICY_EXP_STABILIZATION_TAX
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_EXP_STABILIZATION_TAX (FLAME_get_environment_variable_policy_exp_stabilization_tax())
/** \def CONST_BANKRUPTCY_IDLE_PERIOD
 * \brief Provide access to environment variables in uppercase. */
#define CONST_BANKRUPTCY_IDLE_PERIOD (FLAME_get_environment_variable_const_bankruptcy_idle_period())
/** \def DAYS_PER_MONTH
 * \brief Provide access to environment variables in uppercase. */
#define DAYS_PER_MONTH (FLAME_get_environment_variable_days_per_month())
/** \def XML_CLONED
 * \brief Provide access to environment variables in uppercase. */
#define XML_CLONED (FLAME_get_environment_variable_xml_cloned())
/** \def INDIVIDUAL_LEARNING
 * \brief Provide access to environment variables in uppercase. */
#define INDIVIDUAL_LEARNING (FLAME_get_environment_variable_individual_learning())
/** \def CONST_WAGE_WEALTH_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define CONST_WAGE_WEALTH_RATIO (FLAME_get_environment_variable_const_wage_wealth_ratio())
/** \def CONST_INCOME_TAX_RATE
 * \brief Provide access to environment variables in uppercase. */
#define CONST_INCOME_TAX_RATE (FLAME_get_environment_variable_const_income_tax_rate())
/** \def GAMMA_CONST
 * \brief Provide access to environment variables in uppercase. */
#define GAMMA_CONST (FLAME_get_environment_variable_gamma_const())
/** \def GAMMA_QUALITY
 * \brief Provide access to environment variables in uppercase. */
#define GAMMA_QUALITY (FLAME_get_environment_variable_gamma_quality())
/** \def INITIAL_PRICE
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_PRICE (FLAME_get_environment_variable_initial_price())
/** \def DEPRECIATION_RATE
 * \brief Provide access to environment variables in uppercase. */
#define DEPRECIATION_RATE (FLAME_get_environment_variable_depreciation_rate())
/** \def DISCONT_RATE
 * \brief Provide access to environment variables in uppercase. */
#define DISCONT_RATE (FLAME_get_environment_variable_discont_rate())
/** \def MARK_UP
 * \brief Provide access to environment variables in uppercase. */
#define MARK_UP (FLAME_get_environment_variable_mark_up())
/** \def LAMBDA
 * \brief Provide access to environment variables in uppercase. */
#define LAMBDA (FLAME_get_environment_variable_lambda())
/** \def TARGET_SAVINGS_RATE
 * \brief Provide access to environment variables in uppercase. */
#define TARGET_SAVINGS_RATE (FLAME_get_environment_variable_target_savings_rate())
/** \def CARROL_CONSUMPTION_PARAMETER
 * \brief Provide access to environment variables in uppercase. */
#define CARROL_CONSUMPTION_PARAMETER (FLAME_get_environment_variable_carrol_consumption_parameter())
/** \def QUANTIL_NORMAL_DISTRIBUTION
 * \brief Provide access to environment variables in uppercase. */
#define QUANTIL_NORMAL_DISTRIBUTION (FLAME_get_environment_variable_quantil_normal_distribution())
/** \def FIRM_PLANNING_HORIZON
 * \brief Provide access to environment variables in uppercase. */
#define FIRM_PLANNING_HORIZON (FLAME_get_environment_variable_firm_planning_horizon())
/** \def INITIAL_STOCK_UP
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_STOCK_UP (FLAME_get_environment_variable_initial_stock_up())
/** \def INITIAL_PRICE_ADJUSTMENT
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_PRICE_ADJUSTMENT (FLAME_get_environment_variable_initial_price_adjustment())
/** \def ADAPTION_DELIVERY_VOLUME
 * \brief Provide access to environment variables in uppercase. */
#define ADAPTION_DELIVERY_VOLUME (FLAME_get_environment_variable_adaption_delivery_volume())
/** \def INV_INERTIA
 * \brief Provide access to environment variables in uppercase. */
#define INV_INERTIA (FLAME_get_environment_variable_inv_inertia())
/** \def PLANNING_HORIZON_VINTAGE_CHOICE
 * \brief Provide access to environment variables in uppercase. */
#define PLANNING_HORIZON_VINTAGE_CHOICE (FLAME_get_environment_variable_planning_horizon_vintage_choice())
/** \def GAMMA_LOGIT_VINTAGE_CHOICE
 * \brief Provide access to environment variables in uppercase. */
#define GAMMA_LOGIT_VINTAGE_CHOICE (FLAME_get_environment_variable_gamma_logit_vintage_choice())
/** \def DELTA_LOGIT_VINTAGE_CHOICE
 * \brief Provide access to environment variables in uppercase. */
#define DELTA_LOGIT_VINTAGE_CHOICE (FLAME_get_environment_variable_delta_logit_vintage_choice())
/** \def NUMBER_OF_BANKS_TO_APPLY
 * \brief Provide access to environment variables in uppercase. */
#define NUMBER_OF_BANKS_TO_APPLY (FLAME_get_environment_variable_number_of_banks_to_apply())
/** \def CONST_NUMBER_OF_BANKS
 * \brief Provide access to environment variables in uppercase. */
#define CONST_NUMBER_OF_BANKS (FLAME_get_environment_variable_const_number_of_banks())
/** \def CONST_INSTALLMENT_PERIODS
 * \brief Provide access to environment variables in uppercase. */
#define CONST_INSTALLMENT_PERIODS (FLAME_get_environment_variable_const_installment_periods())
/** \def BANK_LAMBDA
 * \brief Provide access to environment variables in uppercase. */
#define BANK_LAMBDA (FLAME_get_environment_variable_bank_lambda())
/** \def ECB_INTEREST_RATE
 * \brief Provide access to environment variables in uppercase. */
#define ECB_INTEREST_RATE (FLAME_get_environment_variable_ecb_interest_rate())
/** \def ECB_INTEREST_RATE_MARKDOWN
 * \brief Provide access to environment variables in uppercase. */
#define ECB_INTEREST_RATE_MARKDOWN (FLAME_get_environment_variable_ecb_interest_rate_markdown())
/** \def ALFA
 * \brief Provide access to environment variables in uppercase. */
#define ALFA (FLAME_get_environment_variable_alfa())
/** \def MIN_CASH_RESERVE_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define MIN_CASH_RESERVE_RATIO (FLAME_get_environment_variable_min_cash_reserve_ratio())
/** \def CONST_FIRM_LEVERAGE
 * \brief Provide access to environment variables in uppercase. */
#define CONST_FIRM_LEVERAGE (FLAME_get_environment_variable_const_firm_leverage())
/** \def DEBT_RESCALING_FACTOR
 * \brief Provide access to environment variables in uppercase. */
#define DEBT_RESCALING_FACTOR (FLAME_get_environment_variable_debt_rescaling_factor())
/** \def TARGET_LEVERAGE_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define TARGET_LEVERAGE_RATIO (FLAME_get_environment_variable_target_leverage_ratio())
/** \def TARGET_LIQUIDITY_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define TARGET_LIQUIDITY_RATIO (FLAME_get_environment_variable_target_liquidity_ratio())
/** \def CONST_DIVIDEND_EARNINGS_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define CONST_DIVIDEND_EARNINGS_RATIO (FLAME_get_environment_variable_const_dividend_earnings_ratio())
/** \def CONST_DIVIDEND_TRESHOLD_FULL_PAYOUT
 * \brief Provide access to environment variables in uppercase. */
#define CONST_DIVIDEND_TRESHOLD_FULL_PAYOUT (FLAME_get_environment_variable_const_dividend_treshold_full_payout())
/** \def IGFIRM_DIVIDEND_PAYOUT_STRETCHING_MONTH
 * \brief Provide access to environment variables in uppercase. */
#define IGFIRM_DIVIDEND_PAYOUT_STRETCHING_MONTH (FLAME_get_environment_variable_igfirm_dividend_payout_stretching_month())
/** \def INDEX_PRICE_ADJ
 * \brief Provide access to environment variables in uppercase. */
#define INDEX_PRICE_ADJ (FLAME_get_environment_variable_index_price_adj())
/** \def INDEX_PRICE_ADJ_MAX
 * \brief Provide access to environment variables in uppercase. */
#define INDEX_PRICE_ADJ_MAX (FLAME_get_environment_variable_index_price_adj_max())
/** \def INDEX_PRICE_ADJ_MIN
 * \brief Provide access to environment variables in uppercase. */
#define INDEX_PRICE_ADJ_MIN (FLAME_get_environment_variable_index_price_adj_min())
/** \def TRADING_ACTIVITY
 * \brief Provide access to environment variables in uppercase. */
#define TRADING_ACTIVITY (FLAME_get_environment_variable_trading_activity())
/** \def TRADING_RANDOM
 * \brief Provide access to environment variables in uppercase. */
#define TRADING_RANDOM (FLAME_get_environment_variable_trading_random())
/** \def IGFIRM_FIN_MAN_DEBUG
 * \brief Provide access to environment variables in uppercase. */
#define IGFIRM_FIN_MAN_DEBUG (FLAME_get_environment_variable_igfirm_fin_man_debug())
/** \def CONST_IGFIRM_DIVIDEND_TARGET_PCT
 * \brief Provide access to environment variables in uppercase. */
#define CONST_IGFIRM_DIVIDEND_TARGET_PCT (FLAME_get_environment_variable_const_igfirm_dividend_target_pct())
/** \def CONST_IGFIRM_DIVIDEND_ADJUSTMENT_PARAMETER
 * \brief Provide access to environment variables in uppercase. */
#define CONST_IGFIRM_DIVIDEND_ADJUSTMENT_PARAMETER (FLAME_get_environment_variable_const_igfirm_dividend_adjustment_parameter())
/** \def SWITCH_IGFIRM_ENDOGENOUS_INNOVATION_PROBABILITY
 * \brief Provide access to environment variables in uppercase. */
#define SWITCH_IGFIRM_ENDOGENOUS_INNOVATION_PROBABILITY (FLAME_get_environment_variable_switch_igfirm_endogenous_innovation_probability())
/** \def IGFIRM_EXOGENOUS_INNOVATION_PROBABILITY
 * \brief Provide access to environment variables in uppercase. */
#define IGFIRM_EXOGENOUS_INNOVATION_PROBABILITY (FLAME_get_environment_variable_igfirm_exogenous_innovation_probability())
/** \def POWER_OF_END_PROBABILITY_FUNCTION
 * \brief Provide access to environment variables in uppercase. */
#define POWER_OF_END_PROBABILITY_FUNCTION (FLAME_get_environment_variable_power_of_end_probability_function())
/** \def IGFIRM_PRODUCER_DEBUG
 * \brief Provide access to environment variables in uppercase. */
#define IGFIRM_PRODUCER_DEBUG (FLAME_get_environment_variable_igfirm_producer_debug())
/** \def IGFIRM_EXOGENOUS_PRODUCTIVITY_PROGRESS
 * \brief Provide access to environment variables in uppercase. */
#define IGFIRM_EXOGENOUS_PRODUCTIVITY_PROGRESS (FLAME_get_environment_variable_igfirm_exogenous_productivity_progress())
/** \def SYMMETRIC_SHOCK
 * \brief Provide access to environment variables in uppercase. */
#define SYMMETRIC_SHOCK (FLAME_get_environment_variable_symmetric_shock())
/** \def ENERGY_SHOCK_START
 * \brief Provide access to environment variables in uppercase. */
#define ENERGY_SHOCK_START (FLAME_get_environment_variable_energy_shock_start())
/** \def ENERGY_SHOCK_END
 * \brief Provide access to environment variables in uppercase. */
#define ENERGY_SHOCK_END (FLAME_get_environment_variable_energy_shock_end())
/** \def CONST_ENERGY_SHOCK_INTENSITY
 * \brief Provide access to environment variables in uppercase. */
#define CONST_ENERGY_SHOCK_INTENSITY (FLAME_get_environment_variable_const_energy_shock_intensity())
/** \def ENERGY_SHOCK_FREQUENCY
 * \brief Provide access to environment variables in uppercase. */
#define ENERGY_SHOCK_FREQUENCY (FLAME_get_environment_variable_energy_shock_frequency())
/** \def TRANSITION_PHASE
 * \brief Provide access to environment variables in uppercase. */
#define TRANSITION_PHASE (FLAME_get_environment_variable_transition_phase())
/** \def INNOVATION_BY_RANDOM
 * \brief Provide access to environment variables in uppercase. */
#define INNOVATION_BY_RANDOM (FLAME_get_environment_variable_innovation_by_random())
/** \def IG_GOOD_LIMITED_OFFER
 * \brief Provide access to environment variables in uppercase. */
#define IG_GOOD_LIMITED_OFFER (FLAME_get_environment_variable_ig_good_limited_offer())
/** \def MAX_OFFER_IG_GOOD
 * \brief Provide access to environment variables in uppercase. */
#define MAX_OFFER_IG_GOOD (FLAME_get_environment_variable_max_offer_ig_good())
/** \def INITIAL_FRONTIER_FIRM_TRANSITION_PHASE
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_FRONTIER_FIRM_TRANSITION_PHASE (FLAME_get_environment_variable_initial_frontier_firm_transition_phase())
/** \def INITIAL_PRODUCTIVITY_FIRM
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_PRODUCTIVITY_FIRM (FLAME_get_environment_variable_initial_productivity_firm())
/** \def INITIAL_SPECIFIC_SKILLS
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_SPECIFIC_SKILLS (FLAME_get_environment_variable_initial_specific_skills())
/** \def STRENGHT_OF_TECH_PROGRESS
 * \brief Provide access to environment variables in uppercase. */
#define STRENGHT_OF_TECH_PROGRESS (FLAME_get_environment_variable_strenght_of_tech_progress())
/** \def LINEAR_COMBINATION_PRICING_IG_GOOD
 * \brief Provide access to environment variables in uppercase. */
#define LINEAR_COMBINATION_PRICING_IG_GOOD (FLAME_get_environment_variable_linear_combination_pricing_ig_good())
/** \def INITIAL_CAPITAL_PRICE_WAGE_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_CAPITAL_PRICE_WAGE_RATIO (FLAME_get_environment_variable_initial_capital_price_wage_ratio())
/** \def UNION_STRENGTH
 * \brief Provide access to environment variables in uppercase. */
#define UNION_STRENGTH (FLAME_get_environment_variable_union_strength())
/** \def REG_DIFF_UNION_STRENGTH
 * \brief Provide access to environment variables in uppercase. */
#define REG_DIFF_UNION_STRENGTH (FLAME_get_environment_variable_reg_diff_union_strength())
/** \def REG2_FACTOR_UNION_STRENGTH
 * \brief Provide access to environment variables in uppercase. */
#define REG2_FACTOR_UNION_STRENGTH (FLAME_get_environment_variable_reg2_factor_union_strength())
/** \def WAGE_UPDATE
 * \brief Provide access to environment variables in uppercase. */
#define WAGE_UPDATE (FLAME_get_environment_variable_wage_update())
/** \def MIN_VACANCY
 * \brief Provide access to environment variables in uppercase. */
#define MIN_VACANCY (FLAME_get_environment_variable_min_vacancy())
/** \def WAGE_RESERVATION_UPDATE
 * \brief Provide access to environment variables in uppercase. */
#define WAGE_RESERVATION_UPDATE (FLAME_get_environment_variable_wage_reservation_update())
/** \def REGION_COST
 * \brief Provide access to environment variables in uppercase. */
#define REGION_COST (FLAME_get_environment_variable_region_cost())
/** \def DELIVERY_PROB_IF_CRITICAL_STOCK_0
 * \brief Provide access to environment variables in uppercase. */
#define DELIVERY_PROB_IF_CRITICAL_STOCK_0 (FLAME_get_environment_variable_delivery_prob_if_critical_stock_0())
/** \def LABORMARKET_SCENARIO_REG2
 * \brief Provide access to environment variables in uppercase. */
#define LABORMARKET_SCENARIO_REG2 (FLAME_get_environment_variable_labormarket_scenario_reg2())
/** \def NUMBER_APPLICATIONS
 * \brief Provide access to environment variables in uppercase. */
#define NUMBER_APPLICATIONS (FLAME_get_environment_variable_number_applications())
/** \def APPLICATIONS_PER_DAY
 * \brief Provide access to environment variables in uppercase. */
#define APPLICATIONS_PER_DAY (FLAME_get_environment_variable_applications_per_day())
/** \def LOWER_BOUND_FIRING
 * \brief Provide access to environment variables in uppercase. */
#define LOWER_BOUND_FIRING (FLAME_get_environment_variable_lower_bound_firing())
/** \def UPPER_BOUND_FIRING
 * \brief Provide access to environment variables in uppercase. */
#define UPPER_BOUND_FIRING (FLAME_get_environment_variable_upper_bound_firing())
/** \def LOGIT_PARAMETER_SPECIFIC_SKILLS
 * \brief Provide access to environment variables in uppercase. */
#define LOGIT_PARAMETER_SPECIFIC_SKILLS (FLAME_get_environment_variable_logit_parameter_specific_skills())
/** \def LOGIT_PARAMETER_WORKER_PRESELECTION
 * \brief Provide access to environment variables in uppercase. */
#define LOGIT_PARAMETER_WORKER_PRESELECTION (FLAME_get_environment_variable_logit_parameter_worker_preselection())
/** \def LOGIT_PARAMETER_GENERAL_SKILLS
 * \brief Provide access to environment variables in uppercase. */
#define LOGIT_PARAMETER_GENERAL_SKILLS (FLAME_get_environment_variable_logit_parameter_general_skills())
/** \def SKILL_UPDATE_ACC_TO_FORMULA
 * \brief Provide access to environment variables in uppercase. */
#define SKILL_UPDATE_ACC_TO_FORMULA (FLAME_get_environment_variable_skill_update_acc_to_formula())
/** \def RND_SEED
 * \brief Provide access to environment variables in uppercase. */
#define RND_SEED (FLAME_get_environment_variable_rnd_seed())
/** \def GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT (FLAME_get_environment_variable_gov_policy_unemployment_benefit_pct())
/** \def GAMMA_GOV
 * \brief Provide access to environment variables in uppercase. */
#define GAMMA_GOV (FLAME_get_environment_variable_gamma_gov())
/** \def JOE_SCENARIO
 * \brief Provide access to environment variables in uppercase. */
#define JOE_SCENARIO (FLAME_get_environment_variable_joe_scenario())
/** \def GOV_EXPENDITURES_AND_UNEMP_BENEFITS_REDISTRIBUTED
 * \brief Provide access to environment variables in uppercase. */
#define GOV_EXPENDITURES_AND_UNEMP_BENEFITS_REDISTRIBUTED (FLAME_get_environment_variable_gov_expenditures_and_unemp_benefits_redistributed())
/** \def GOV_POLICY_MONEY_FINANCING_FRACTION
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_MONEY_FINANCING_FRACTION (FLAME_get_environment_variable_gov_policy_money_financing_fraction())
/** \def ADAPTIVE_TAX_RATES
 * \brief Provide access to environment variables in uppercase. */
#define ADAPTIVE_TAX_RATES (FLAME_get_environment_variable_adaptive_tax_rates())
/** \def GOV_2_RELAXED_BUDGET_RULE
 * \brief Provide access to environment variables in uppercase. */
#define GOV_2_RELAXED_BUDGET_RULE (FLAME_get_environment_variable_gov_2_relaxed_budget_rule())
/** \def GOV_2_EXPENDITURES_COVERED
 * \brief Provide access to environment variables in uppercase. */
#define GOV_2_EXPENDITURES_COVERED (FLAME_get_environment_variable_gov_2_expenditures_covered())
/** \def GOV_2_CONSUMPTION_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define GOV_2_CONSUMPTION_RATIO (FLAME_get_environment_variable_gov_2_consumption_ratio())
/** \def GOV_REGIONAL_CONSUMPTION_SCENARIO
 * \brief Provide access to environment variables in uppercase. */
#define GOV_REGIONAL_CONSUMPTION_SCENARIO (FLAME_get_environment_variable_gov_regional_consumption_scenario())
/** \def REG2_MARKUP_FACTOR
 * \brief Provide access to environment variables in uppercase. */
#define REG2_MARKUP_FACTOR (FLAME_get_environment_variable_reg2_markup_factor())
/** \def MIGRATION_REGION_ID
 * \brief Provide access to environment variables in uppercase. */
#define MIGRATION_REGION_ID (FLAME_get_environment_variable_migration_region_id())
/** \def MIGRATION_ALLOCATION_QUOTA
 * \brief Provide access to environment variables in uppercase. */
#define MIGRATION_ALLOCATION_QUOTA (FLAME_get_environment_variable_migration_allocation_quota())
/** \def MIGRATION_ALLOCATION_POLICY
 * \brief Provide access to environment variables in uppercase. */
#define MIGRATION_ALLOCATION_POLICY (FLAME_get_environment_variable_migration_allocation_policy())
/** \def MIGRATION_EXPERIMENT
 * \brief Provide access to environment variables in uppercase. */
#define MIGRATION_EXPERIMENT (FLAME_get_environment_variable_migration_experiment())
/** \def MINIMUM_WAGE_POLICY
 * \brief Provide access to environment variables in uppercase. */
#define MINIMUM_WAGE_POLICY (FLAME_get_environment_variable_minimum_wage_policy())
/** \def MINIMUM_WAGE_POLICY_TARGET_MINIMUM_WAGE
 * \brief Provide access to environment variables in uppercase. */
#define MINIMUM_WAGE_POLICY_TARGET_MINIMUM_WAGE (FLAME_get_environment_variable_minimum_wage_policy_target_minimum_wage())
/** \def POLICY_MIGRATION_TOP_UP_BENEFITS
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_MIGRATION_TOP_UP_BENEFITS (FLAME_get_environment_variable_policy_migration_top_up_benefits())
/** \def POLICY_MIGRATION_WAGE_SUBSIDIES
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_MIGRATION_WAGE_SUBSIDIES (FLAME_get_environment_variable_policy_migration_wage_subsidies())
/** \def POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_MIGRATION_WAGE_SUBSIDIES_TARGETED (FLAME_get_environment_variable_policy_migration_wage_subsidies_targeted())
/** \def MIGRATION_TOP_UP_BENEFIT
 * \brief Provide access to environment variables in uppercase. */
#define MIGRATION_TOP_UP_BENEFIT (FLAME_get_environment_variable_migration_top_up_benefit())
/** \def MIGRATION_DATE
 * \brief Provide access to environment variables in uppercase. */
#define MIGRATION_DATE (FLAME_get_environment_variable_migration_date())
/** \def GOV_POLICY_GDP_FRACTION_CONSUMPTION
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_GDP_FRACTION_CONSUMPTION (FLAME_get_environment_variable_gov_policy_gdp_fraction_consumption())
/** \def EXP_FIRM_SUBSIDY_SCENARIO
 * \brief Provide access to environment variables in uppercase. */
#define EXP_FIRM_SUBSIDY_SCENARIO (FLAME_get_environment_variable_exp_firm_subsidy_scenario())
/** \def AUSTERITY_POLICY
 * \brief Provide access to environment variables in uppercase. */
#define AUSTERITY_POLICY (FLAME_get_environment_variable_austerity_policy())
/** \def AUSTERITY_POLICY_SCENARIO
 * \brief Provide access to environment variables in uppercase. */
#define AUSTERITY_POLICY_SCENARIO (FLAME_get_environment_variable_austerity_policy_scenario())
/** \def AUSTERITY_REPAY_SCENARIO
 * \brief Provide access to environment variables in uppercase. */
#define AUSTERITY_REPAY_SCENARIO (FLAME_get_environment_variable_austerity_repay_scenario())
/** \def AUSTERITY_CONSUMPTION_THRESHOLD
 * \brief Provide access to environment variables in uppercase. */
#define AUSTERITY_CONSUMPTION_THRESHOLD (FLAME_get_environment_variable_austerity_consumption_threshold())
/** \def AUSTERITY_DEBT_THRESHOLD
 * \brief Provide access to environment variables in uppercase. */
#define AUSTERITY_DEBT_THRESHOLD (FLAME_get_environment_variable_austerity_debt_threshold())
/** \def AUSTERITY_REPAYMENT_PERIOD
 * \brief Provide access to environment variables in uppercase. */
#define AUSTERITY_REPAYMENT_PERIOD (FLAME_get_environment_variable_austerity_repayment_period())
/** \def GOV_POLICY_GDP_FRACTION_INVESTMENT
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_GDP_FRACTION_INVESTMENT (FLAME_get_environment_variable_gov_policy_gdp_fraction_investment())
/** \def NO_REGIONS_PER_GOV
 * \brief Provide access to environment variables in uppercase. */
#define NO_REGIONS_PER_GOV (FLAME_get_environment_variable_no_regions_per_gov())
/** \def FLEXIBILITY_POLICY
 * \brief Provide access to environment variables in uppercase. */
#define FLEXIBILITY_POLICY (FLAME_get_environment_variable_flexibility_policy())
/** \def GOV_BUDGETING_HORIZON
 * \brief Provide access to environment variables in uppercase. */
#define GOV_BUDGETING_HORIZON (FLAME_get_environment_variable_gov_budgeting_horizon())
/** \def SUBSIDY_TRIGGER_ON
 * \brief Provide access to environment variables in uppercase. */
#define SUBSIDY_TRIGGER_ON (FLAME_get_environment_variable_subsidy_trigger_on())
/** \def SUBSIDY_TRIGGER_OFF
 * \brief Provide access to environment variables in uppercase. */
#define SUBSIDY_TRIGGER_OFF (FLAME_get_environment_variable_subsidy_trigger_off())
/** \def POLICY_STARTING_AT_ITERATION
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_STARTING_AT_ITERATION (FLAME_get_environment_variable_policy_starting_at_iteration())
/** \def GOV_POLICY_SWITH_QUANTITATIVE_EASING
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_SWITH_QUANTITATIVE_EASING (FLAME_get_environment_variable_gov_policy_swith_quantitative_easing())
/** \def GOV_POLICY_SWITCH_HUMAN_CAPITAL_IMPROVEMENT
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_SWITCH_HUMAN_CAPITAL_IMPROVEMENT (FLAME_get_environment_variable_gov_policy_switch_human_capital_improvement())
/** \def SUBSIDY_REDISTRIBUTION
 * \brief Provide access to environment variables in uppercase. */
#define SUBSIDY_REDISTRIBUTION (FLAME_get_environment_variable_subsidy_redistribution())
/** \def TECH_POLICY_EFFECTIVENESS_SWITCH
 * \brief Provide access to environment variables in uppercase. */
#define TECH_POLICY_EFFECTIVENESS_SWITCH (FLAME_get_environment_variable_tech_policy_effectiveness_switch())
/** \def PROBABILITY_TECH_POLICY_EFFECTIVENESS
 * \brief Provide access to environment variables in uppercase. */
#define PROBABILITY_TECH_POLICY_EFFECTIVENESS (FLAME_get_environment_variable_probability_tech_policy_effectiveness())
/** \def POLICY_EXP_BEST_TECHNOLOGY_SUBSIDY
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_EXP_BEST_TECHNOLOGY_SUBSIDY (FLAME_get_environment_variable_policy_exp_best_technology_subsidy())
/** \def SUBSIDY_REDISTRIBUTION_PARAMETER
 * \brief Provide access to environment variables in uppercase. */
#define SUBSIDY_REDISTRIBUTION_PARAMETER (FLAME_get_environment_variable_subsidy_redistribution_parameter())
/** \def POLICY_EXP_ALL_TECHNOLOGIES_SUBSIDY
 * \brief Provide access to environment variables in uppercase. */
#define POLICY_EXP_ALL_TECHNOLOGIES_SUBSIDY (FLAME_get_environment_variable_policy_exp_all_technologies_subsidy())
/** \def REGIONAL_POLICY_TECHNOLOGY_SUBSIDY
 * \brief Provide access to environment variables in uppercase. */
#define REGIONAL_POLICY_TECHNOLOGY_SUBSIDY (FLAME_get_environment_variable_regional_policy_technology_subsidy())
/** \def BEST_TECHNOLOGY_SUBSIDY_PCT
 * \brief Provide access to environment variables in uppercase. */
#define BEST_TECHNOLOGY_SUBSIDY_PCT (FLAME_get_environment_variable_best_technology_subsidy_pct())
/** \def INNOVATION_SWITCHED_ON
 * \brief Provide access to environment variables in uppercase. */
#define INNOVATION_SWITCHED_ON (FLAME_get_environment_variable_innovation_switched_on())
/** \def MR_START_PRICE
 * \brief Provide access to environment variables in uppercase. */
#define MR_START_PRICE (FLAME_get_environment_variable_mr_start_price())
/** \def MR_END_PRICE
 * \brief Provide access to environment variables in uppercase. */
#define MR_END_PRICE (FLAME_get_environment_variable_mr_end_price())
/** \def MR_PRICE_INCREMENT
 * \brief Provide access to environment variables in uppercase. */
#define MR_PRICE_INCREMENT (FLAME_get_environment_variable_mr_price_increment())
/** \def MAX_NO_EMPLOYEES_PRODUCT_INNOVATION
 * \brief Provide access to environment variables in uppercase. */
#define MAX_NO_EMPLOYEES_PRODUCT_INNOVATION (FLAME_get_environment_variable_max_no_employees_product_innovation())
/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 10
/** \def ARRAY_GROWTH_RATE
 * \brief Growth ratio to scale size of dynamic arrays. 
 * Use golden ratio. This makes for a Fibonacci sequence, so the next allocation size 
 * is the sum of the current size and the previous size thus improving the chance of 
 * memory block reuse. It also allows for moderate rate of growth.
 */
#define ARRAY_GROWTH_RATE 1.618034
/** \def START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process bank_account_update messages. */
#define START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP  for(bank_account_update_message = get_first_bank_account_update_message(); bank_account_update_message != NULL; bank_account_update_message = get_next_bank_account_update_message(bank_account_update_message)) {
/** \def FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process bank_account_update messages. */
#define FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP }
/** \def START_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process bank_to_central_bank_account_update messages. */
#define START_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP  for(bank_to_central_bank_account_update_message = get_first_bank_to_central_bank_account_update_message(); bank_to_central_bank_account_update_message != NULL; bank_to_central_bank_account_update_message = get_next_bank_to_central_bank_account_update_message(bank_to_central_bank_account_update_message)) {
/** \def FINISH_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process bank_to_central_bank_account_update messages. */
#define FINISH_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP }
/** \def START_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process gov_to_central_bank_account_update messages. */
#define START_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP  for(gov_to_central_bank_account_update_message = get_first_gov_to_central_bank_account_update_message(); gov_to_central_bank_account_update_message != NULL; gov_to_central_bank_account_update_message = get_next_gov_to_central_bank_account_update_message(gov_to_central_bank_account_update_message)) {
/** \def FINISH_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process gov_to_central_bank_account_update messages. */
#define FINISH_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP }
/** \def START_WAGE_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process wage_payment messages. */
#define START_WAGE_PAYMENT_MESSAGE_LOOP  for(wage_payment_message = get_first_wage_payment_message(); wage_payment_message != NULL; wage_payment_message = get_next_wage_payment_message(wage_payment_message)) {
/** \def FINISH_WAGE_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process wage_payment messages. */
#define FINISH_WAGE_PAYMENT_MESSAGE_LOOP }
/** \def START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
 * \brief Start of loop to process quality_price_info_1 messages. */
#define START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP  for(quality_price_info_1_message = get_first_quality_price_info_1_message(); quality_price_info_1_message != NULL; quality_price_info_1_message = get_next_quality_price_info_1_message(quality_price_info_1_message)) {
/** \def FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
 * \brief Finish of loop to process quality_price_info_1 messages. */
#define FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP }
/** \def START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP
 * \brief Start of loop to process quality_price_info_2 messages. */
#define START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP  for(quality_price_info_2_message = get_first_quality_price_info_2_message(); quality_price_info_2_message != NULL; quality_price_info_2_message = get_next_quality_price_info_2_message(quality_price_info_2_message)) {
/** \def FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP
 * \brief Finish of loop to process quality_price_info_2 messages. */
#define FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP }
/** \def START_UPDATE_MALL_STOCK_MESSAGE_LOOP
 * \brief Start of loop to process update_mall_stock messages. */
#define START_UPDATE_MALL_STOCK_MESSAGE_LOOP  for(update_mall_stock_message = get_first_update_mall_stock_message(); update_mall_stock_message != NULL; update_mall_stock_message = get_next_update_mall_stock_message(update_mall_stock_message)) {
/** \def FINISH_UPDATE_MALL_STOCK_MESSAGE_LOOP
 * \brief Finish of loop to process update_mall_stock messages. */
#define FINISH_UPDATE_MALL_STOCK_MESSAGE_LOOP }
/** \def START_CONSUMPTION_REQUEST_1_MESSAGE_LOOP
 * \brief Start of loop to process consumption_request_1 messages. */
#define START_CONSUMPTION_REQUEST_1_MESSAGE_LOOP  for(consumption_request_1_message = get_first_consumption_request_1_message(); consumption_request_1_message != NULL; consumption_request_1_message = get_next_consumption_request_1_message(consumption_request_1_message)) {
/** \def FINISH_CONSUMPTION_REQUEST_1_MESSAGE_LOOP
 * \brief Finish of loop to process consumption_request_1 messages. */
#define FINISH_CONSUMPTION_REQUEST_1_MESSAGE_LOOP }
/** \def START_CONSUMPTION_REQUEST_2_MESSAGE_LOOP
 * \brief Start of loop to process consumption_request_2 messages. */
#define START_CONSUMPTION_REQUEST_2_MESSAGE_LOOP  for(consumption_request_2_message = get_first_consumption_request_2_message(); consumption_request_2_message != NULL; consumption_request_2_message = get_next_consumption_request_2_message(consumption_request_2_message)) {
/** \def FINISH_CONSUMPTION_REQUEST_2_MESSAGE_LOOP
 * \brief Finish of loop to process consumption_request_2 messages. */
#define FINISH_CONSUMPTION_REQUEST_2_MESSAGE_LOOP }
/** \def START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP
 * \brief Start of loop to process accepted_consumption_1 messages. */
#define START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP  for(accepted_consumption_1_message = get_first_accepted_consumption_1_message(); accepted_consumption_1_message != NULL; accepted_consumption_1_message = get_next_accepted_consumption_1_message(accepted_consumption_1_message)) {
/** \def FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP
 * \brief Finish of loop to process accepted_consumption_1 messages. */
#define FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP }
/** \def START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
 * \brief Start of loop to process accepted_consumption_2 messages. */
#define START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP  for(accepted_consumption_2_message = get_first_accepted_consumption_2_message(); accepted_consumption_2_message != NULL; accepted_consumption_2_message = get_next_accepted_consumption_2_message(accepted_consumption_2_message)) {
/** \def FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
 * \brief Finish of loop to process accepted_consumption_2 messages. */
#define FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP }
/** \def START_SALES_MESSAGE_LOOP
 * \brief Start of loop to process sales messages. */
#define START_SALES_MESSAGE_LOOP  for(sales_message = get_first_sales_message(); sales_message != NULL; sales_message = get_next_sales_message(sales_message)) {
/** \def FINISH_SALES_MESSAGE_LOOP
 * \brief Finish of loop to process sales messages. */
#define FINISH_SALES_MESSAGE_LOOP }
/** \def START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process specific_skill_update messages. */
#define START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP  for(specific_skill_update_message = get_first_specific_skill_update_message(); specific_skill_update_message != NULL; specific_skill_update_message = get_next_specific_skill_update_message(specific_skill_update_message)) {
/** \def FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process specific_skill_update messages. */
#define FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP }
/** \def START_POLICY_RATE_MESSAGE_LOOP
 * \brief Start of loop to process policy_rate messages. */
#define START_POLICY_RATE_MESSAGE_LOOP  for(policy_rate_message = get_first_policy_rate_message(); policy_rate_message != NULL; policy_rate_message = get_next_policy_rate_message(policy_rate_message)) {
/** \def FINISH_POLICY_RATE_MESSAGE_LOOP
 * \brief Finish of loop to process policy_rate messages. */
#define FINISH_POLICY_RATE_MESSAGE_LOOP }
/** \def START_BANK_IDENTITY_MESSAGE_LOOP
 * \brief Start of loop to process bank_identity messages. */
#define START_BANK_IDENTITY_MESSAGE_LOOP  for(bank_identity_message = get_first_bank_identity_message(); bank_identity_message != NULL; bank_identity_message = get_next_bank_identity_message(bank_identity_message)) {
/** \def FINISH_BANK_IDENTITY_MESSAGE_LOOP
 * \brief Finish of loop to process bank_identity messages. */
#define FINISH_BANK_IDENTITY_MESSAGE_LOOP }
/** \def START_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process loan_request messages. */
#define START_LOAN_REQUEST_MESSAGE_LOOP  for(loan_request_message = get_first_loan_request_message(); loan_request_message != NULL; loan_request_message = get_next_loan_request_message(loan_request_message)) {
/** \def FINISH_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process loan_request messages. */
#define FINISH_LOAN_REQUEST_MESSAGE_LOOP }
/** \def START_LOAN_REQUEST_RANKED_MESSAGE_LOOP
 * \brief Start of loop to process loan_request_ranked messages. */
#define START_LOAN_REQUEST_RANKED_MESSAGE_LOOP  for(loan_request_ranked_message = get_first_loan_request_ranked_message(); loan_request_ranked_message != NULL; loan_request_ranked_message = get_next_loan_request_ranked_message(loan_request_ranked_message)) {
/** \def FINISH_LOAN_REQUEST_RANKED_MESSAGE_LOOP
 * \brief Finish of loop to process loan_request_ranked messages. */
#define FINISH_LOAN_REQUEST_RANKED_MESSAGE_LOOP }
/** \def START_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Start of loop to process loan_conditions messages. */
#define START_LOAN_CONDITIONS_MESSAGE_LOOP  for(loan_conditions_message = get_first_loan_conditions_message(); loan_conditions_message != NULL; loan_conditions_message = get_next_loan_conditions_message(loan_conditions_message)) {
/** \def FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Finish of loop to process loan_conditions messages. */
#define FINISH_LOAN_CONDITIONS_MESSAGE_LOOP }
/** \def START_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Start of loop to process loan_acceptance messages. */
#define START_LOAN_ACCEPTANCE_MESSAGE_LOOP  for(loan_acceptance_message = get_first_loan_acceptance_message(); loan_acceptance_message != NULL; loan_acceptance_message = get_next_loan_acceptance_message(loan_acceptance_message)) {
/** \def FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Finish of loop to process loan_acceptance messages. */
#define FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP }
/** \def START_INSTALLMENT_MESSAGE_LOOP
 * \brief Start of loop to process installment messages. */
#define START_INSTALLMENT_MESSAGE_LOOP  for(installment_message = get_first_installment_message(); installment_message != NULL; installment_message = get_next_installment_message(installment_message)) {
/** \def FINISH_INSTALLMENT_MESSAGE_LOOP
 * \brief Finish of loop to process installment messages. */
#define FINISH_INSTALLMENT_MESSAGE_LOOP }
/** \def START_BANKRUPTCY_MESSAGE_LOOP
 * \brief Start of loop to process bankruptcy messages. */
#define START_BANKRUPTCY_MESSAGE_LOOP  for(bankruptcy_message = get_first_bankruptcy_message(); bankruptcy_message != NULL; bankruptcy_message = get_next_bankruptcy_message(bankruptcy_message)) {
/** \def FINISH_BANKRUPTCY_MESSAGE_LOOP
 * \brief Finish of loop to process bankruptcy messages. */
#define FINISH_BANKRUPTCY_MESSAGE_LOOP }
/** \def START_BANK_INTEREST_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process bank_interest_payment messages. */
#define START_BANK_INTEREST_PAYMENT_MESSAGE_LOOP  for(bank_interest_payment_message = get_first_bank_interest_payment_message(); bank_interest_payment_message != NULL; bank_interest_payment_message = get_next_bank_interest_payment_message(bank_interest_payment_message)) {
/** \def FINISH_BANK_INTEREST_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process bank_interest_payment messages. */
#define FINISH_BANK_INTEREST_PAYMENT_MESSAGE_LOOP }
/** \def START_ACCOUNT_INTEREST_MESSAGE_LOOP
 * \brief Start of loop to process account_interest messages. */
#define START_ACCOUNT_INTEREST_MESSAGE_LOOP  for(account_interest_message = get_first_account_interest_message(); account_interest_message != NULL; account_interest_message = get_next_account_interest_message(account_interest_message)) {
/** \def FINISH_ACCOUNT_INTEREST_MESSAGE_LOOP
 * \brief Finish of loop to process account_interest messages. */
#define FINISH_ACCOUNT_INTEREST_MESSAGE_LOOP }
/** \def START_ECB_DIVIDEND_MESSAGE_LOOP
 * \brief Start of loop to process ecb_dividend messages. */
#define START_ECB_DIVIDEND_MESSAGE_LOOP  for(ecb_dividend_message = get_first_ecb_dividend_message(); ecb_dividend_message != NULL; ecb_dividend_message = get_next_ecb_dividend_message(ecb_dividend_message)) {
/** \def FINISH_ECB_DIVIDEND_MESSAGE_LOOP
 * \brief Finish of loop to process ecb_dividend messages. */
#define FINISH_ECB_DIVIDEND_MESSAGE_LOOP }
/** \def START_CREDIT_VAR_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process credit_var_update messages. */
#define START_CREDIT_VAR_UPDATE_MESSAGE_LOOP  for(credit_var_update_message = get_first_credit_var_update_message(); credit_var_update_message != NULL; credit_var_update_message = get_next_credit_var_update_message(credit_var_update_message)) {
/** \def FINISH_CREDIT_VAR_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process credit_var_update messages. */
#define FINISH_CREDIT_VAR_UPDATE_MESSAGE_LOOP }
/** \def START_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP
 * \brief Start of loop to process bankruptcy_illiquidity messages. */
#define START_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP  for(bankruptcy_illiquidity_message = get_first_bankruptcy_illiquidity_message(); bankruptcy_illiquidity_message != NULL; bankruptcy_illiquidity_message = get_next_bankruptcy_illiquidity_message(bankruptcy_illiquidity_message)) {
/** \def FINISH_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP
 * \brief Finish of loop to process bankruptcy_illiquidity messages. */
#define FINISH_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP }
/** \def START_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP
 * \brief Start of loop to process bankruptcy_insolvency messages. */
#define START_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP  for(bankruptcy_insolvency_message = get_first_bankruptcy_insolvency_message(); bankruptcy_insolvency_message != NULL; bankruptcy_insolvency_message = get_next_bankruptcy_insolvency_message(bankruptcy_insolvency_message)) {
/** \def FINISH_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP
 * \brief Finish of loop to process bankruptcy_insolvency messages. */
#define FINISH_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP }
/** \def START_INDEX_INFO_MESSAGE_LOOP
 * \brief Start of loop to process index_info messages. */
#define START_INDEX_INFO_MESSAGE_LOOP  for(index_info_message = get_first_index_info_message(); index_info_message != NULL; index_info_message = get_next_index_info_message(index_info_message)) {
/** \def FINISH_INDEX_INFO_MESSAGE_LOOP
 * \brief Finish of loop to process index_info messages. */
#define FINISH_INDEX_INFO_MESSAGE_LOOP }
/** \def START_INDEX_PRICE_MESSAGE_LOOP
 * \brief Start of loop to process index_price messages. */
#define START_INDEX_PRICE_MESSAGE_LOOP  for(index_price_message = get_first_index_price_message(); index_price_message != NULL; index_price_message = get_next_index_price_message(index_price_message)) {
/** \def FINISH_INDEX_PRICE_MESSAGE_LOOP
 * \brief Finish of loop to process index_price messages. */
#define FINISH_INDEX_PRICE_MESSAGE_LOOP }
/** \def START_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process order messages. */
#define START_ORDER_MESSAGE_LOOP  for(order_message = get_first_order_message(); order_message != NULL; order_message = get_next_order_message(order_message)) {
/** \def FINISH_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process order messages. */
#define FINISH_ORDER_MESSAGE_LOOP }
/** \def START_ORDER_STATUS_MESSAGE_LOOP
 * \brief Start of loop to process order_status messages. */
#define START_ORDER_STATUS_MESSAGE_LOOP  for(order_status_message = get_first_order_status_message(); order_status_message != NULL; order_status_message = get_next_order_status_message(order_status_message)) {
/** \def FINISH_ORDER_STATUS_MESSAGE_LOOP
 * \brief Finish of loop to process order_status messages. */
#define FINISH_ORDER_STATUS_MESSAGE_LOOP }
/** \def START_DIVIDEND_INFO_MESSAGE_LOOP
 * \brief Start of loop to process dividend_info messages. */
#define START_DIVIDEND_INFO_MESSAGE_LOOP  for(dividend_info_message = get_first_dividend_info_message(); dividend_info_message != NULL; dividend_info_message = get_next_dividend_info_message(dividend_info_message)) {
/** \def FINISH_DIVIDEND_INFO_MESSAGE_LOOP
 * \brief Finish of loop to process dividend_info messages. */
#define FINISH_DIVIDEND_INFO_MESSAGE_LOOP }
/** \def START_PRODUCTIVITY_MESSAGE_LOOP
 * \brief Start of loop to process productivity messages. */
#define START_PRODUCTIVITY_MESSAGE_LOOP  for(productivity_message = get_first_productivity_message(); productivity_message != NULL; productivity_message = get_next_productivity_message(productivity_message)) {
/** \def FINISH_PRODUCTIVITY_MESSAGE_LOOP
 * \brief Finish of loop to process productivity messages. */
#define FINISH_PRODUCTIVITY_MESSAGE_LOOP }
/** \def START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_request messages. */
#define START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP  for(capital_good_request_message = get_first_capital_good_request_message(); capital_good_request_message != NULL; capital_good_request_message = get_next_capital_good_request_message(capital_good_request_message)) {
/** \def FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_request messages. */
#define FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP }
/** \def START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_delivery messages. */
#define START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP  for(capital_good_delivery_message = get_first_capital_good_delivery_message(); capital_good_delivery_message != NULL; capital_good_delivery_message = get_next_capital_good_delivery_message(capital_good_delivery_message)) {
/** \def FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_delivery messages. */
#define FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP }
/** \def START_PAY_CAPITAL_GOODS_MESSAGE_LOOP
 * \brief Start of loop to process pay_capital_goods messages. */
#define START_PAY_CAPITAL_GOODS_MESSAGE_LOOP  for(pay_capital_goods_message = get_first_pay_capital_goods_message(); pay_capital_goods_message != NULL; pay_capital_goods_message = get_next_pay_capital_goods_message(pay_capital_goods_message)) {
/** \def FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP
 * \brief Finish of loop to process pay_capital_goods messages. */
#define FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP }
/** \def START_VACANCIES_MESSAGE_LOOP
 * \brief Start of loop to process vacancies messages. */
#define START_VACANCIES_MESSAGE_LOOP  for(vacancies_message = get_first_vacancies_message(); vacancies_message != NULL; vacancies_message = get_next_vacancies_message(vacancies_message)) {
/** \def FINISH_VACANCIES_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies messages. */
#define FINISH_VACANCIES_MESSAGE_LOOP }
/** \def START_VACANCIES2_MESSAGE_LOOP
 * \brief Start of loop to process vacancies2 messages. */
#define START_VACANCIES2_MESSAGE_LOOP  for(vacancies2_message = get_first_vacancies2_message(); vacancies2_message != NULL; vacancies2_message = get_next_vacancies2_message(vacancies2_message)) {
/** \def FINISH_VACANCIES2_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies2 messages. */
#define FINISH_VACANCIES2_MESSAGE_LOOP }
/** \def START_VACANCIES_R_AND_D_EMPLOYEES_MESSAGE_LOOP
 * \brief Start of loop to process vacancies_r_and_d_employees messages. */
#define START_VACANCIES_R_AND_D_EMPLOYEES_MESSAGE_LOOP  for(vacancies_r_and_d_employees_message = get_first_vacancies_r_and_d_employees_message(); vacancies_r_and_d_employees_message != NULL; vacancies_r_and_d_employees_message = get_next_vacancies_r_and_d_employees_message(vacancies_r_and_d_employees_message)) {
/** \def FINISH_VACANCIES_R_AND_D_EMPLOYEES_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies_r_and_d_employees messages. */
#define FINISH_VACANCIES_R_AND_D_EMPLOYEES_MESSAGE_LOOP }
/** \def START_VACANCIES_R_AND_D_EMPLOYEES2_MESSAGE_LOOP
 * \brief Start of loop to process vacancies_r_and_d_employees2 messages. */
#define START_VACANCIES_R_AND_D_EMPLOYEES2_MESSAGE_LOOP  for(vacancies_r_and_d_employees2_message = get_first_vacancies_r_and_d_employees2_message(); vacancies_r_and_d_employees2_message != NULL; vacancies_r_and_d_employees2_message = get_next_vacancies_r_and_d_employees2_message(vacancies_r_and_d_employees2_message)) {
/** \def FINISH_VACANCIES_R_AND_D_EMPLOYEES2_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies_r_and_d_employees2 messages. */
#define FINISH_VACANCIES_R_AND_D_EMPLOYEES2_MESSAGE_LOOP }
/** \def START_FIRING_MESSAGE_LOOP
 * \brief Start of loop to process firing messages. */
#define START_FIRING_MESSAGE_LOOP  for(firing_message = get_first_firing_message(); firing_message != NULL; firing_message = get_next_firing_message(firing_message)) {
/** \def FINISH_FIRING_MESSAGE_LOOP
 * \brief Finish of loop to process firing messages. */
#define FINISH_FIRING_MESSAGE_LOOP }
/** \def START_JOB_APPLICATION_MESSAGE_LOOP
 * \brief Start of loop to process job_application messages. */
#define START_JOB_APPLICATION_MESSAGE_LOOP  for(job_application_message = get_first_job_application_message(); job_application_message != NULL; job_application_message = get_next_job_application_message(job_application_message)) {
/** \def FINISH_JOB_APPLICATION_MESSAGE_LOOP
 * \brief Finish of loop to process job_application messages. */
#define FINISH_JOB_APPLICATION_MESSAGE_LOOP }
/** \def START_JOB_APPLICATION2_MESSAGE_LOOP
 * \brief Start of loop to process job_application2 messages. */
#define START_JOB_APPLICATION2_MESSAGE_LOOP  for(job_application2_message = get_first_job_application2_message(); job_application2_message != NULL; job_application2_message = get_next_job_application2_message(job_application2_message)) {
/** \def FINISH_JOB_APPLICATION2_MESSAGE_LOOP
 * \brief Finish of loop to process job_application2 messages. */
#define FINISH_JOB_APPLICATION2_MESSAGE_LOOP }
/** \def START_JOB_OFFER_MESSAGE_LOOP
 * \brief Start of loop to process job_offer messages. */
#define START_JOB_OFFER_MESSAGE_LOOP  for(job_offer_message = get_first_job_offer_message(); job_offer_message != NULL; job_offer_message = get_next_job_offer_message(job_offer_message)) {
/** \def FINISH_JOB_OFFER_MESSAGE_LOOP
 * \brief Finish of loop to process job_offer messages. */
#define FINISH_JOB_OFFER_MESSAGE_LOOP }
/** \def START_JOB_OFFER2_MESSAGE_LOOP
 * \brief Start of loop to process job_offer2 messages. */
#define START_JOB_OFFER2_MESSAGE_LOOP  for(job_offer2_message = get_first_job_offer2_message(); job_offer2_message != NULL; job_offer2_message = get_next_job_offer2_message(job_offer2_message)) {
/** \def FINISH_JOB_OFFER2_MESSAGE_LOOP
 * \brief Finish of loop to process job_offer2 messages. */
#define FINISH_JOB_OFFER2_MESSAGE_LOOP }
/** \def START_JOB_ACCEPTANCE_MESSAGE_LOOP
 * \brief Start of loop to process job_acceptance messages. */
#define START_JOB_ACCEPTANCE_MESSAGE_LOOP  for(job_acceptance_message = get_first_job_acceptance_message(); job_acceptance_message != NULL; job_acceptance_message = get_next_job_acceptance_message(job_acceptance_message)) {
/** \def FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP
 * \brief Finish of loop to process job_acceptance messages. */
#define FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP }
/** \def START_JOB_ACCEPTANCE2_MESSAGE_LOOP
 * \brief Start of loop to process job_acceptance2 messages. */
#define START_JOB_ACCEPTANCE2_MESSAGE_LOOP  for(job_acceptance2_message = get_first_job_acceptance2_message(); job_acceptance2_message != NULL; job_acceptance2_message = get_next_job_acceptance2_message(job_acceptance2_message)) {
/** \def FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP
 * \brief Finish of loop to process job_acceptance2 messages. */
#define FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP }
/** \def START_QUITTING_MESSAGE_LOOP
 * \brief Start of loop to process quitting messages. */
#define START_QUITTING_MESSAGE_LOOP  for(quitting_message = get_first_quitting_message(); quitting_message != NULL; quitting_message = get_next_quitting_message(quitting_message)) {
/** \def FINISH_QUITTING_MESSAGE_LOOP
 * \brief Finish of loop to process quitting messages. */
#define FINISH_QUITTING_MESSAGE_LOOP }
/** \def START_QUITTING2_MESSAGE_LOOP
 * \brief Start of loop to process quitting2 messages. */
#define START_QUITTING2_MESSAGE_LOOP  for(quitting2_message = get_first_quitting2_message(); quitting2_message != NULL; quitting2_message = get_next_quitting2_message(quitting2_message)) {
/** \def FINISH_QUITTING2_MESSAGE_LOOP
 * \brief Finish of loop to process quitting2 messages. */
#define FINISH_QUITTING2_MESSAGE_LOOP }
/** \def START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process unemployment_notification messages. */
#define START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP  for(unemployment_notification_message = get_first_unemployment_notification_message(); unemployment_notification_message != NULL; unemployment_notification_message = get_next_unemployment_notification_message(unemployment_notification_message)) {
/** \def FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process unemployment_notification messages. */
#define FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP }
/** \def START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Start of loop to process policy_announcement messages. */
#define START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP  for(policy_announcement_message = get_first_policy_announcement_message(); policy_announcement_message != NULL; policy_announcement_message = get_next_policy_announcement_message(policy_announcement_message)) {
/** \def FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Finish of loop to process policy_announcement messages. */
#define FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP }
/** \def START_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process tax_payment messages. */
#define START_TAX_PAYMENT_MESSAGE_LOOP  for(tax_payment_message = get_first_tax_payment_message(); tax_payment_message != NULL; tax_payment_message = get_next_tax_payment_message(tax_payment_message)) {
/** \def FINISH_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process tax_payment messages. */
#define FINISH_TAX_PAYMENT_MESSAGE_LOOP }
/** \def START_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP
 * \brief Start of loop to process unemployment_benefit_restitution messages. */
#define START_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP  for(unemployment_benefit_restitution_message = get_first_unemployment_benefit_restitution_message(); unemployment_benefit_restitution_message != NULL; unemployment_benefit_restitution_message = get_next_unemployment_benefit_restitution_message(unemployment_benefit_restitution_message)) {
/** \def FINISH_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP
 * \brief Finish of loop to process unemployment_benefit_restitution messages. */
#define FINISH_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP }
/** \def START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process hh_transfer_notification messages. */
#define START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP  for(hh_transfer_notification_message = get_first_hh_transfer_notification_message(); hh_transfer_notification_message != NULL; hh_transfer_notification_message = get_next_hh_transfer_notification_message(hh_transfer_notification_message)) {
/** \def FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process hh_transfer_notification messages. */
#define FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP }
/** \def START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process hh_subsidy_notification messages. */
#define START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP  for(hh_subsidy_notification_message = get_first_hh_subsidy_notification_message(); hh_subsidy_notification_message != NULL; hh_subsidy_notification_message = get_next_hh_subsidy_notification_message(hh_subsidy_notification_message)) {
/** \def FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process hh_subsidy_notification messages. */
#define FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP }
/** \def START_HUMAN_CAPITAL_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Start of loop to process human_capital_policy_announcement messages. */
#define START_HUMAN_CAPITAL_POLICY_ANNOUNCEMENT_MESSAGE_LOOP  for(human_capital_policy_announcement_message = get_first_human_capital_policy_announcement_message(); human_capital_policy_announcement_message != NULL; human_capital_policy_announcement_message = get_next_human_capital_policy_announcement_message(human_capital_policy_announcement_message)) {
/** \def FINISH_HUMAN_CAPITAL_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Finish of loop to process human_capital_policy_announcement messages. */
#define FINISH_HUMAN_CAPITAL_POLICY_ANNOUNCEMENT_MESSAGE_LOOP }
/** \def START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process firm_transfer_notification messages. */
#define START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP  for(firm_transfer_notification_message = get_first_firm_transfer_notification_message(); firm_transfer_notification_message != NULL; firm_transfer_notification_message = get_next_firm_transfer_notification_message(firm_transfer_notification_message)) {
/** \def FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_transfer_notification messages. */
#define FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP }
/** \def START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process firm_subsidy_notification messages. */
#define START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP  for(firm_subsidy_notification_message = get_first_firm_subsidy_notification_message(); firm_subsidy_notification_message != NULL; firm_subsidy_notification_message = get_next_firm_subsidy_notification_message(firm_subsidy_notification_message)) {
/** \def FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_subsidy_notification messages. */
#define FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP }
/** \def START_REQUEST_FIAT_MONEY_MESSAGE_LOOP
 * \brief Start of loop to process request_fiat_money messages. */
#define START_REQUEST_FIAT_MONEY_MESSAGE_LOOP  for(request_fiat_money_message = get_first_request_fiat_money_message(); request_fiat_money_message != NULL; request_fiat_money_message = get_next_request_fiat_money_message(request_fiat_money_message)) {
/** \def FINISH_REQUEST_FIAT_MONEY_MESSAGE_LOOP
 * \brief Finish of loop to process request_fiat_money messages. */
#define FINISH_REQUEST_FIAT_MONEY_MESSAGE_LOOP }
/** \def START_HUMAN_CAPITAL_POLICY_GENERAL_SKILL_INFORMATION_MESSAGE_LOOP
 * \brief Start of loop to process human_capital_policy_general_skill_information messages. */
#define START_HUMAN_CAPITAL_POLICY_GENERAL_SKILL_INFORMATION_MESSAGE_LOOP  for(human_capital_policy_general_skill_information_message = get_first_human_capital_policy_general_skill_information_message(); human_capital_policy_general_skill_information_message != NULL; human_capital_policy_general_skill_information_message = get_next_human_capital_policy_general_skill_information_message(human_capital_policy_general_skill_information_message)) {
/** \def FINISH_HUMAN_CAPITAL_POLICY_GENERAL_SKILL_INFORMATION_MESSAGE_LOOP
 * \brief Finish of loop to process human_capital_policy_general_skill_information messages. */
#define FINISH_HUMAN_CAPITAL_POLICY_GENERAL_SKILL_INFORMATION_MESSAGE_LOOP }
/** \def START_HUMAN_CAPITAL_POLICY_NEW_GENERAL_SKILL_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process human_capital_policy_new_general_skill_notification messages. */
#define START_HUMAN_CAPITAL_POLICY_NEW_GENERAL_SKILL_NOTIFICATION_MESSAGE_LOOP  for(human_capital_policy_new_general_skill_notification_message = get_first_human_capital_policy_new_general_skill_notification_message(); human_capital_policy_new_general_skill_notification_message != NULL; human_capital_policy_new_general_skill_notification_message = get_next_human_capital_policy_new_general_skill_notification_message(human_capital_policy_new_general_skill_notification_message)) {
/** \def FINISH_HUMAN_CAPITAL_POLICY_NEW_GENERAL_SKILL_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process human_capital_policy_new_general_skill_notification messages. */
#define FINISH_HUMAN_CAPITAL_POLICY_NEW_GENERAL_SKILL_NOTIFICATION_MESSAGE_LOOP }
/** \def START_FIRM_SEND_DATA_MESSAGE_LOOP
 * \brief Start of loop to process firm_send_data messages. */
#define START_FIRM_SEND_DATA_MESSAGE_LOOP  for(firm_send_data_message = get_first_firm_send_data_message(); firm_send_data_message != NULL; firm_send_data_message = get_next_firm_send_data_message(firm_send_data_message)) {
/** \def FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process firm_send_data messages. */
#define FINISH_FIRM_SEND_DATA_MESSAGE_LOOP }
/** \def START_GOVERNMENT_SEND_DATA_MESSAGE_LOOP
 * \brief Start of loop to process government_send_data messages. */
#define START_GOVERNMENT_SEND_DATA_MESSAGE_LOOP  for(government_send_data_message = get_first_government_send_data_message(); government_send_data_message != NULL; government_send_data_message = get_next_government_send_data_message(government_send_data_message)) {
/** \def FINISH_GOVERNMENT_SEND_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process government_send_data messages. */
#define FINISH_GOVERNMENT_SEND_DATA_MESSAGE_LOOP }
/** \def START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
 * \brief Start of loop to process household_send_data messages. */
#define START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP  for(household_send_data_message = get_first_household_send_data_message(); household_send_data_message != NULL; household_send_data_message = get_next_household_send_data_message(household_send_data_message)) {
/** \def FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process household_send_data messages. */
#define FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP }
/** \def START_MALL_DATA_MESSAGE_LOOP
 * \brief Start of loop to process mall_data messages. */
#define START_MALL_DATA_MESSAGE_LOOP  for(mall_data_message = get_first_mall_data_message(); mall_data_message != NULL; mall_data_message = get_next_mall_data_message(mall_data_message)) {
/** \def FINISH_MALL_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process mall_data messages. */
#define FINISH_MALL_DATA_MESSAGE_LOOP }
/** \def START_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Start of loop to process eurostat_send_specific_skills messages. */
#define START_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP  for(eurostat_send_specific_skills_message = get_first_eurostat_send_specific_skills_message(); eurostat_send_specific_skills_message != NULL; eurostat_send_specific_skills_message = get_next_eurostat_send_specific_skills_message(eurostat_send_specific_skills_message)) {
/** \def FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Finish of loop to process eurostat_send_specific_skills messages. */
#define FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP }
/** \def START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Start of loop to process data_for_government messages. */
#define START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP  for(data_for_government_message = get_first_data_for_government_message(); data_for_government_message != NULL; data_for_government_message = get_next_data_for_government_message(data_for_government_message)) {
/** \def FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Finish of loop to process data_for_government messages. */
#define FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP }
/** \def START_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP
 * \brief Start of loop to process eurostat_send_macrodata messages. */
#define START_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP  for(eurostat_send_macrodata_message = get_first_eurostat_send_macrodata_message(); eurostat_send_macrodata_message != NULL; eurostat_send_macrodata_message = get_next_eurostat_send_macrodata_message(eurostat_send_macrodata_message)) {
/** \def FINISH_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP
 * \brief Finish of loop to process eurostat_send_macrodata messages. */
#define FINISH_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP }
/** \def START_MSG_FIRM_ID_TO_MALLS_MESSAGE_LOOP
 * \brief Start of loop to process msg_firm_id_to_malls messages. */
#define START_MSG_FIRM_ID_TO_MALLS_MESSAGE_LOOP  for(msg_firm_id_to_malls_message = get_first_msg_firm_id_to_malls_message(); msg_firm_id_to_malls_message != NULL; msg_firm_id_to_malls_message = get_next_msg_firm_id_to_malls_message(msg_firm_id_to_malls_message)) {
/** \def FINISH_MSG_FIRM_ID_TO_MALLS_MESSAGE_LOOP
 * \brief Finish of loop to process msg_firm_id_to_malls messages. */
#define FINISH_MSG_FIRM_ID_TO_MALLS_MESSAGE_LOOP }
/** \def START_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP
 * \brief Start of loop to process msg_mall_id_to_firms messages. */
#define START_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP  for(msg_mall_id_to_firms_message = get_first_msg_mall_id_to_firms_message(); msg_mall_id_to_firms_message != NULL; msg_mall_id_to_firms_message = get_next_msg_mall_id_to_firms_message(msg_mall_id_to_firms_message)) {
/** \def FINISH_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP
 * \brief Finish of loop to process msg_mall_id_to_firms messages. */
#define FINISH_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP }
/** \def START_MSG_SKILLS_EUROSTAT_TO_IGFIRM_MESSAGE_LOOP
 * \brief Start of loop to process msg_skills_eurostat_to_igfirm messages. */
#define START_MSG_SKILLS_EUROSTAT_TO_IGFIRM_MESSAGE_LOOP  for(msg_skills_eurostat_to_igfirm_message = get_first_msg_skills_eurostat_to_igfirm_message(); msg_skills_eurostat_to_igfirm_message != NULL; msg_skills_eurostat_to_igfirm_message = get_next_msg_skills_eurostat_to_igfirm_message(msg_skills_eurostat_to_igfirm_message)) {
/** \def FINISH_MSG_SKILLS_EUROSTAT_TO_IGFIRM_MESSAGE_LOOP
 * \brief Finish of loop to process msg_skills_eurostat_to_igfirm messages. */
#define FINISH_MSG_SKILLS_EUROSTAT_TO_IGFIRM_MESSAGE_LOOP }
/** \def START_MSG_MARKET_SIZES_MESSAGE_LOOP
 * \brief Start of loop to process msg_market_sizes messages. */
#define START_MSG_MARKET_SIZES_MESSAGE_LOOP  for(msg_market_sizes_message = get_first_msg_market_sizes_message(); msg_market_sizes_message != NULL; msg_market_sizes_message = get_next_msg_market_sizes_message(msg_market_sizes_message)) {
/** \def FINISH_MSG_MARKET_SIZES_MESSAGE_LOOP
 * \brief Finish of loop to process msg_market_sizes messages. */
#define FINISH_MSG_MARKET_SIZES_MESSAGE_LOOP }
/** \def START_TOTAL_SUBSIDIES_MESSAGE_LOOP
 * \brief Start of loop to process total_subsidies messages. */
#define START_TOTAL_SUBSIDIES_MESSAGE_LOOP  for(total_subsidies_message = get_first_total_subsidies_message(); total_subsidies_message != NULL; total_subsidies_message = get_next_total_subsidies_message(total_subsidies_message)) {
/** \def FINISH_TOTAL_SUBSIDIES_MESSAGE_LOOP
 * \brief Finish of loop to process total_subsidies messages. */
#define FINISH_TOTAL_SUBSIDIES_MESSAGE_LOOP }
/** \def START_REDISTRIBUTED_SUBSIDIES_MESSAGE_LOOP
 * \brief Start of loop to process redistributed_subsidies messages. */
#define START_REDISTRIBUTED_SUBSIDIES_MESSAGE_LOOP  for(redistributed_subsidies_message = get_first_redistributed_subsidies_message(); redistributed_subsidies_message != NULL; redistributed_subsidies_message = get_next_redistributed_subsidies_message(redistributed_subsidies_message)) {
/** \def FINISH_REDISTRIBUTED_SUBSIDIES_MESSAGE_LOOP
 * \brief Finish of loop to process redistributed_subsidies messages. */
#define FINISH_REDISTRIBUTED_SUBSIDIES_MESSAGE_LOOP }
/** \def START_QUALITY_PRICE_MESSAGE_LOOP
 * \brief Start of loop to process quality_price messages. */
#define START_QUALITY_PRICE_MESSAGE_LOOP  for(quality_price_message = get_first_quality_price_message(); quality_price_message != NULL; quality_price_message = get_next_quality_price_message(quality_price_message)) {
/** \def FINISH_QUALITY_PRICE_MESSAGE_LOOP
 * \brief Finish of loop to process quality_price messages. */
#define FINISH_QUALITY_PRICE_MESSAGE_LOOP }
/** \def START_INTERVIEW_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process interview_request messages. */
#define START_INTERVIEW_REQUEST_MESSAGE_LOOP  for(interview_request_message = get_first_interview_request_message(); interview_request_message != NULL; interview_request_message = get_next_interview_request_message(interview_request_message)) {
/** \def FINISH_INTERVIEW_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process interview_request messages. */
#define FINISH_INTERVIEW_REQUEST_MESSAGE_LOOP }
/** \def START_INTERVIEW_POSITIVE_RESPONSE_MESSAGE_LOOP
 * \brief Start of loop to process interview_positive_response messages. */
#define START_INTERVIEW_POSITIVE_RESPONSE_MESSAGE_LOOP  for(interview_positive_response_message = get_first_interview_positive_response_message(); interview_positive_response_message != NULL; interview_positive_response_message = get_next_interview_positive_response_message(interview_positive_response_message)) {
/** \def FINISH_INTERVIEW_POSITIVE_RESPONSE_MESSAGE_LOOP
 * \brief Finish of loop to process interview_positive_response messages. */
#define FINISH_INTERVIEW_POSITIVE_RESPONSE_MESSAGE_LOOP }
/** \def START_QUESTIONNAIRE_INNOVATION_MESSAGE_LOOP
 * \brief Start of loop to process questionnaire_innovation messages. */
#define START_QUESTIONNAIRE_INNOVATION_MESSAGE_LOOP  for(questionnaire_innovation_message = get_first_questionnaire_innovation_message(); questionnaire_innovation_message != NULL; questionnaire_innovation_message = get_next_questionnaire_innovation_message(questionnaire_innovation_message)) {
/** \def FINISH_QUESTIONNAIRE_INNOVATION_MESSAGE_LOOP
 * \brief Finish of loop to process questionnaire_innovation messages. */
#define FINISH_QUESTIONNAIRE_INNOVATION_MESSAGE_LOOP }
/** \def START_FILLED_OUT_QUESTIONNAIRE_PRODUCT_INNOVATION_MESSAGE_LOOP
 * \brief Start of loop to process filled_out_questionnaire_product_innovation messages. */
#define START_FILLED_OUT_QUESTIONNAIRE_PRODUCT_INNOVATION_MESSAGE_LOOP  for(filled_out_questionnaire_product_innovation_message = get_first_filled_out_questionnaire_product_innovation_message(); filled_out_questionnaire_product_innovation_message != NULL; filled_out_questionnaire_product_innovation_message = get_next_filled_out_questionnaire_product_innovation_message(filled_out_questionnaire_product_innovation_message)) {
/** \def FINISH_FILLED_OUT_QUESTIONNAIRE_PRODUCT_INNOVATION_MESSAGE_LOOP
 * \brief Finish of loop to process filled_out_questionnaire_product_innovation messages. */
#define FINISH_FILLED_OUT_QUESTIONNAIRE_PRODUCT_INNOVATION_MESSAGE_LOOP }


struct FLAME_output
{
	int type; /* 0=snapshot 1=Firm 2=Household 3=Mall 4=IGFirm 5=Eurostat 6=Bank 7=Government 8=CentralBank 9=ClearingHouse */
	int format; /* 0=XML */
	char * location;
	int period;
	int phase;
	int flag; /* Used when outputting to show it has been used */

	struct FLAME_output * next;
};
typedef struct FLAME_output FLAME_output;

/** \struct int_array
 * \brief Dynamic array to hold integers.
 *
 * Holds a pointer to an integer array and values for size and memory size.
 */
struct int_array
{
	int size;
	int total_size;

	int * array;
};

/** \struct float_array
 * \brief Dynamic array to hold floats.
 *
 * Holds a pointer to an float array and values for size and memory size.
 */
struct float_array
{
	int size;
	int total_size;

	float * array;
};

/** \struct double_array
 * \brief Dynamic array to hold doubles.
 *
 * Holds a pointer to a double array and values for size and memory size.
 */
struct double_array
{
	int size;
	int total_size;

	double * array;
};

/** \struct char_array
 * \brief Dynamic array to hold chars.
 *
 * Holds a pointer to a char array and values for size and memory size.
 */
struct char_array
{
	int size;
	int total_size;

	char * array;
};

/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct float_array float_array
 * \brief Typedef for float_array struct.
 */
typedef struct float_array float_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;

/** \struct consumption_goods_offer
 * \brief Used by household and mall to hold consumption goods offers.
 *
 * Used by household and mall to hold consumption goods offers.
 */
struct consumption_goods_offer
{
	int id;	/**< Datatype memory variable id of type int. */
	double quality;	/**< Datatype memory variable quality of type double. */
	double price;	/**< Datatype memory variable price of type double. */
};

/** \struct consumption_goods_offer_array
 * \brief Dynamic array to hold consumption_goods_offers
 */
struct consumption_goods_offer_array
{
	int size;
	int total_size;

	struct consumption_goods_offer * array;
};

/** \var typedef consumption_goods_offer consumption_goods_offer
 * \brief Typedef for consumption_goods_offer struct.
 */
typedef struct consumption_goods_offer consumption_goods_offer;
/** \var typedef consumption_goods_offer_array consumption_goods_offer_array
 * \brief Typedef for consumption_goods_offer_array struct.
 */
typedef struct consumption_goods_offer_array consumption_goods_offer_array;
/** \struct estimators_linear_regression
 * \brief Used by firms to estimated the demand by applying a linear regression.
 *
 * Used by firms to estimated the demand by applying a linear regression.
 */
struct estimators_linear_regression
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double intercept;	/**< Datatype memory variable intercept of type double. */
	double regressor;	/**< Datatype memory variable regressor of type double. */
	double variance;	/**< Datatype memory variable variance of type double. */
};

/** \struct estimators_linear_regression_array
 * \brief Dynamic array to hold estimators_linear_regressions
 */
struct estimators_linear_regression_array
{
	int size;
	int total_size;

	struct estimators_linear_regression * array;
};

/** \var typedef estimators_linear_regression estimators_linear_regression
 * \brief Typedef for estimators_linear_regression struct.
 */
typedef struct estimators_linear_regression estimators_linear_regression;
/** \var typedef estimators_linear_regression_array estimators_linear_regression_array
 * \brief Typedef for estimators_linear_regression_array struct.
 */
typedef struct estimators_linear_regression_array estimators_linear_regression_array;
/** \struct consumption_request
 * \brief Used by  mall to hold demand.
 *
 * Used by  mall to hold demand.
 */
struct consumption_request
{
	int worker_id;	/**< Datatype memory variable worker_id of type int. */
	int consumer_region_id;	/**< Datatype memory variable consumer_region_id of type int. */
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
};

/** \struct consumption_request_array
 * \brief Dynamic array to hold consumption_requests
 */
struct consumption_request_array
{
	int size;
	int total_size;

	struct consumption_request * array;
};

/** \var typedef consumption_request consumption_request
 * \brief Typedef for consumption_request struct.
 */
typedef struct consumption_request consumption_request;
/** \var typedef consumption_request_array consumption_request_array
 * \brief Typedef for consumption_request_array struct.
 */
typedef struct consumption_request_array consumption_request_array;
/** \struct mall_info
 * \brief Used by firm to hold information about sales in malls.
 *
 * Used by firm to hold information about sales in malls.
 */
struct mall_info
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	double critical_stock;	/**< Datatype memory variable critical_stock of type double. */
	double current_stock;	/**< Datatype memory variable current_stock of type double. */
};

/** \struct mall_info_array
 * \brief Dynamic array to hold mall_infos
 */
struct mall_info_array
{
	int size;
	int total_size;

	struct mall_info * array;
};

/** \var typedef mall_info mall_info
 * \brief Typedef for mall_info struct.
 */
typedef struct mall_info mall_info;
/** \var typedef mall_info_array mall_info_array
 * \brief Typedef for mall_info_array struct.
 */
typedef struct mall_info_array mall_info_array;
/** \struct mall_quality_price_info
 * \brief Used by household to hold information about quality and prices of one good offered by mall.
 *
 * Used by household to hold information about quality and prices of one good offered by mall.
 */
struct mall_quality_price_info
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int mall_region_id;	/**< Datatype memory variable mall_region_id of type int. */
	double quality;	/**< Datatype memory variable quality of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	int available;	/**< Datatype memory variable available of type int. */
};

/** \struct mall_quality_price_info_array
 * \brief Dynamic array to hold mall_quality_price_infos
 */
struct mall_quality_price_info_array
{
	int size;
	int total_size;

	struct mall_quality_price_info * array;
};

/** \var typedef mall_quality_price_info mall_quality_price_info
 * \brief Typedef for mall_quality_price_info struct.
 */
typedef struct mall_quality_price_info mall_quality_price_info;
/** \var typedef mall_quality_price_info_array mall_quality_price_info_array
 * \brief Typedef for mall_quality_price_info_array struct.
 */
typedef struct mall_quality_price_info_array mall_quality_price_info_array;
/** \struct mall_stock
 * \brief Used by mall to hold information about current stock.
 *
 * Used by mall to hold information about current stock.
 */
struct mall_stock
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double stock;	/**< Datatype memory variable stock of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double quality;	/**< Datatype memory variable quality of type double. */
	double previous_price;	/**< Datatype memory variable previous_price of type double. */
};

/** \struct mall_stock_array
 * \brief Dynamic array to hold mall_stocks
 */
struct mall_stock_array
{
	int size;
	int total_size;

	struct mall_stock * array;
};

/** \var typedef mall_stock mall_stock
 * \brief Typedef for mall_stock struct.
 */
typedef struct mall_stock mall_stock;
/** \var typedef mall_stock_array mall_stock_array
 * \brief Typedef for mall_stock_array struct.
 */
typedef struct mall_stock_array mall_stock_array;
/** \struct delivery_volume_per_mall
 * \brief Used by firm to hold information about delivery volume per mall.
 *
 * Used by firm to hold information about delivery volume per mall.
 */
struct delivery_volume_per_mall
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double quality;	/**< Datatype memory variable quality of type double. */
};

/** \struct delivery_volume_per_mall_array
 * \brief Dynamic array to hold delivery_volume_per_malls
 */
struct delivery_volume_per_mall_array
{
	int size;
	int total_size;

	struct delivery_volume_per_mall * array;
};

/** \var typedef delivery_volume_per_mall delivery_volume_per_mall
 * \brief Typedef for delivery_volume_per_mall struct.
 */
typedef struct delivery_volume_per_mall delivery_volume_per_mall;
/** \var typedef delivery_volume_per_mall_array delivery_volume_per_mall_array
 * \brief Typedef for delivery_volume_per_mall_array struct.
 */
typedef struct delivery_volume_per_mall_array delivery_volume_per_mall_array;
/** \struct logit_firm_id
 * \brief Used by household to stock logits and corresponding firm IDs.
 *
 * Used by household to stock logits and corresponding firm IDs.
 */
struct logit_firm_id
{
	double logit;	/**< Datatype memory variable logit of type double. */
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
};

/** \struct logit_firm_id_array
 * \brief Dynamic array to hold logit_firm_ids
 */
struct logit_firm_id_array
{
	int size;
	int total_size;

	struct logit_firm_id * array;
};

/** \var typedef logit_firm_id logit_firm_id
 * \brief Typedef for logit_firm_id struct.
 */
typedef struct logit_firm_id logit_firm_id;
/** \var typedef logit_firm_id_array logit_firm_id_array
 * \brief Typedef for logit_firm_id_array struct.
 */
typedef struct logit_firm_id_array logit_firm_id_array;
/** \struct sales_in_mall
 * \brief Used by mall to calculate sales.
 *
 * Used by mall to calculate sales.
 */
struct sales_in_mall
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double sales;	/**< Datatype memory variable sales of type double. */
};

/** \struct sales_in_mall_array
 * \brief Dynamic array to hold sales_in_malls
 */
struct sales_in_mall_array
{
	int size;
	int total_size;

	struct sales_in_mall * array;
};

/** \var typedef sales_in_mall sales_in_mall
 * \brief Typedef for sales_in_mall struct.
 */
typedef struct sales_in_mall sales_in_mall;
/** \var typedef sales_in_mall_array sales_in_mall_array
 * \brief Typedef for sales_in_mall_array struct.
 */
typedef struct sales_in_mall_array sales_in_mall_array;
/** \struct ordered_quantity
 * \brief Used by household to stock ordered quantities.
 *
 * Used by household to stock ordered quantities.
 */
struct ordered_quantity
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double quality;	/**< Datatype memory variable quality of type double. */
};

/** \struct ordered_quantity_array
 * \brief Dynamic array to hold ordered_quantitys
 */
struct ordered_quantity_array
{
	int size;
	int total_size;

	struct ordered_quantity * array;
};

/** \var typedef ordered_quantity ordered_quantity
 * \brief Typedef for ordered_quantity struct.
 */
typedef struct ordered_quantity ordered_quantity;
/** \var typedef ordered_quantity_array ordered_quantity_array
 * \brief Typedef for ordered_quantity_array struct.
 */
typedef struct ordered_quantity_array ordered_quantity_array;
/** \struct received_quantities
 * \brief Used by household to stock received quantities.
 *
 * Used by household to stock received quantities.
 */
struct received_quantities
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
};

/** \struct received_quantities_array
 * \brief Dynamic array to hold received_quantitiess
 */
struct received_quantities_array
{
	int size;
	int total_size;

	struct received_quantities * array;
};

/** \var typedef received_quantities received_quantities
 * \brief Typedef for received_quantities struct.
 */
typedef struct received_quantities received_quantities;
/** \var typedef received_quantities_array received_quantities_array
 * \brief Typedef for received_quantities_array struct.
 */
typedef struct received_quantities_array received_quantities_array;
/** \struct sold_quantities_per_mall
 * \brief Used by firm to hold informations about sales .
 *
 * Used by firm to hold informations about sales .
 */
struct sold_quantities_per_mall
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	double sold_quantity;	/**< Datatype memory variable sold_quantity of type double. */
	int stock_empty;	/**< Datatype memory variable stock_empty of type int. */
	double estimated_demand;	/**< Datatype memory variable estimated_demand of type double. */
};

/** \struct sold_quantities_per_mall_array
 * \brief Dynamic array to hold sold_quantities_per_malls
 */
struct sold_quantities_per_mall_array
{
	int size;
	int total_size;

	struct sold_quantities_per_mall * array;
};

/** \var typedef sold_quantities_per_mall sold_quantities_per_mall
 * \brief Typedef for sold_quantities_per_mall struct.
 */
typedef struct sold_quantities_per_mall sold_quantities_per_mall;
/** \var typedef sold_quantities_per_mall_array sold_quantities_per_mall_array
 * \brief Typedef for sold_quantities_per_mall_array struct.
 */
typedef struct sold_quantities_per_mall_array sold_quantities_per_mall_array;
/** \struct data_type_sales
 * \brief Used for storing the sales of a mall in one period..
 *
 * Used for storing the sales of a mall in one period..
 */
struct data_type_sales
{
	int period;	/**< Datatype memory variable period of type int. */
	double sales;	/**< Datatype memory variable sales of type double. */
};

/** \struct data_type_sales_array
 * \brief Dynamic array to hold data_type_saless
 */
struct data_type_sales_array
{
	int size;
	int total_size;

	struct data_type_sales * array;
};

/** \var typedef data_type_sales data_type_sales
 * \brief Typedef for data_type_sales struct.
 */
typedef struct data_type_sales data_type_sales;
/** \var typedef data_type_sales_array data_type_sales_array
 * \brief Typedef for data_type_sales_array struct.
 */
typedef struct data_type_sales_array data_type_sales_array;
/** \struct sales_statistics
 * \brief Used by firm to store sales in malls of last periods.
 *
 * Used by firm to store sales in malls of last periods.
 */
struct sales_statistics
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	data_type_sales_array sales;	/**< Datatype memory variable sales of type data_type_sales_array. */
};

/** \struct sales_statistics_array
 * \brief Dynamic array to hold sales_statisticss
 */
struct sales_statistics_array
{
	int size;
	int total_size;

	struct sales_statistics * array;
};

/** \var typedef sales_statistics sales_statistics
 * \brief Typedef for sales_statistics struct.
 */
typedef struct sales_statistics sales_statistics;
/** \var typedef sales_statistics_array sales_statistics_array
 * \brief Typedef for sales_statistics_array struct.
 */
typedef struct sales_statistics_array sales_statistics_array;
/** \struct adt_technology_vintages
 * \brief Holds information for the vintage choice..
 *
 * Holds information for the vintage choice..
 */
struct adt_technology_vintages
{
	double productivity;	/**< Datatype memory variable productivity of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double sum_effective_productivities;	/**< Datatype memory variable sum_effective_productivities of type double. */
};

/** \struct adt_technology_vintages_array
 * \brief Dynamic array to hold adt_technology_vintagess
 */
struct adt_technology_vintages_array
{
	int size;
	int total_size;

	struct adt_technology_vintages * array;
};

/** \var typedef adt_technology_vintages adt_technology_vintages
 * \brief Typedef for adt_technology_vintages struct.
 */
typedef struct adt_technology_vintages adt_technology_vintages;
/** \var typedef adt_technology_vintages_array adt_technology_vintages_array
 * \brief Typedef for adt_technology_vintages_array struct.
 */
typedef struct adt_technology_vintages_array adt_technology_vintages_array;
/** \struct adt_capital_stock_vintages
 * \brief Holds the vintages of the capital stock.
 *
 * Holds the vintages of the capital stock.
 */
struct adt_capital_stock_vintages
{
	double amount;	/**< Datatype memory variable amount of type double. */
	double productivity;	/**< Datatype memory variable productivity of type double. */
};

/** \struct adt_capital_stock_vintages_array
 * \brief Dynamic array to hold adt_capital_stock_vintagess
 */
struct adt_capital_stock_vintages_array
{
	int size;
	int total_size;

	struct adt_capital_stock_vintages * array;
};

/** \var typedef adt_capital_stock_vintages adt_capital_stock_vintages
 * \brief Typedef for adt_capital_stock_vintages struct.
 */
typedef struct adt_capital_stock_vintages adt_capital_stock_vintages;
/** \var typedef adt_capital_stock_vintages_array adt_capital_stock_vintages_array
 * \brief Typedef for adt_capital_stock_vintages_array struct.
 */
typedef struct adt_capital_stock_vintages_array adt_capital_stock_vintages_array;
/** \struct financing_capital
 * \brief Holds the monthly amounts of investments which are accounted in the pricing..
 *
 * Holds the monthly amounts of investments which are accounted in the pricing..
 */
struct financing_capital
{
	double financing_per_month;	/**< Datatype memory variable financing_per_month of type double. */
	int nr_periods_before_repayment;	/**< Datatype memory variable nr_periods_before_repayment of type int. */
};

/** \struct financing_capital_array
 * \brief Dynamic array to hold financing_capitals
 */
struct financing_capital_array
{
	int size;
	int total_size;

	struct financing_capital * array;
};

/** \var typedef financing_capital financing_capital
 * \brief Typedef for financing_capital struct.
 */
typedef struct financing_capital financing_capital;
/** \var typedef financing_capital_array financing_capital_array
 * \brief Typedef for financing_capital_array struct.
 */
typedef struct financing_capital_array financing_capital_array;
/** \struct temporary_sales_statistics
 * \brief This data type is used for building a temporray array of last sales in the malls. .
 *
 * This data type is used for building a temporray array of last sales in the malls. .
 */
struct temporary_sales_statistics
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	int period;	/**< Datatype memory variable period of type int. */
	double sales;	/**< Datatype memory variable sales of type double. */
};

/** \struct temporary_sales_statistics_array
 * \brief Dynamic array to hold temporary_sales_statisticss
 */
struct temporary_sales_statistics_array
{
	int size;
	int total_size;

	struct temporary_sales_statistics * array;
};

/** \var typedef temporary_sales_statistics temporary_sales_statistics
 * \brief Typedef for temporary_sales_statistics struct.
 */
typedef struct temporary_sales_statistics temporary_sales_statistics;
/** \var typedef temporary_sales_statistics_array temporary_sales_statistics_array
 * \brief Typedef for temporary_sales_statistics_array struct.
 */
typedef struct temporary_sales_statistics_array temporary_sales_statistics_array;
/** \struct account_item
 * \brief ADTwithattributesofapaymentaccount..
 *
 * ADTwithattributesofapaymentaccount..
 */
struct account_item
{
	int id;	/**< Datatype memory variable id of type int. */
	double payment_account;	/**< Datatype memory variable payment_account of type double. */
};

/** \struct account_item_array
 * \brief Dynamic array to hold account_items
 */
struct account_item_array
{
	int size;
	int total_size;

	struct account_item * array;
};

/** \var typedef account_item account_item
 * \brief Typedef for account_item struct.
 */
typedef struct account_item account_item;
/** \var typedef account_item_array account_item_array
 * \brief Typedef for account_item_array struct.
 */
typedef struct account_item_array account_item_array;
/** \struct debt_item
 * \brief ADT containing the attributes of a single loan.
 *
 * ADT containing the attributes of a single loan.
 */
struct debt_item
{
	int bank_id;	/**< Datatype memory variable bank_id of type int. */
	double loan_value;	/**< Datatype memory variable loan_value of type double. */
	double interest_rate;	/**< Datatype memory variable interest_rate of type double. */
	double installment_amount;	/**< Datatype memory variable installment_amount of type double. */
	double var_per_installment;	/**< Datatype memory variable var_per_installment of type double. */
	double residual_var;	/**< Datatype memory variable residual_var of type double. */
	double bad_debt;	/**< Datatype memory variable bad_debt of type double. */
	int nr_periods_before_repayment;	/**< Datatype memory variable nr_periods_before_repayment of type int. */
};

/** \struct debt_item_array
 * \brief Dynamic array to hold debt_items
 */
struct debt_item_array
{
	int size;
	int total_size;

	struct debt_item * array;
};

/** \var typedef debt_item debt_item
 * \brief Typedef for debt_item struct.
 */
typedef struct debt_item debt_item;
/** \var typedef debt_item_array debt_item_array
 * \brief Typedef for debt_item_array struct.
 */
typedef struct debt_item_array debt_item_array;
/** \struct order
 * \brief ADT for stock orders.
 *
 * ADT for stock orders.
 */
struct order
{
	int trader_id;	/**< Datatype memory variable trader_id of type int. */
	double value;	/**< Datatype memory variable value of type double. */
	int quantity;	/**< Datatype memory variable quantity of type int. */
};

/** \struct order_array
 * \brief Dynamic array to hold orders
 */
struct order_array
{
	int size;
	int total_size;

	struct order * array;
};

/** \var typedef order order
 * \brief Typedef for order struct.
 */
typedef struct order order;
/** \var typedef order_array order_array
 * \brief Typedef for order_array struct.
 */
typedef struct order_array order_array;
/** \struct index_adt
 * \brief ADT for the stock market index.
 *
 * ADT for the stock market index.
 */
struct index_adt
{
	double price;	/**< Datatype memory variable price of type double. */
	double weight;	/**< Datatype memory variable weight of type double. */
	double total_dividend;	/**< Datatype memory variable total_dividend of type double. */
	double dividend_per_share;	/**< Datatype memory variable dividend_per_share of type double. */
	int nr_shares;	/**< Datatype memory variable nr_shares of type int. */
	double moving_avg_price;	/**< Datatype memory variable moving_avg_price of type double. */
	double_array price_history;	/**< Datatype memory variable price_history of type double_array. */
};

/** \struct index_adt_array
 * \brief Dynamic array to hold index_adts
 */
struct index_adt_array
{
	int size;
	int total_size;

	struct index_adt * array;
};

/** \var typedef index_adt index_adt
 * \brief Typedef for index_adt struct.
 */
typedef struct index_adt index_adt;
/** \var typedef index_adt_array index_adt_array
 * \brief Typedef for index_adt_array struct.
 */
typedef struct index_adt_array index_adt_array;
/** \struct index_portfolio
 * \brief Household portfolio of index shares..
 *
 * Household portfolio of index shares..
 */
struct index_portfolio
{
	double lastprice;	/**< Datatype memory variable lastprice of type double. */
	int units;	/**< Datatype memory variable units of type int. */
	double moving_avg_price;	/**< Datatype memory variable moving_avg_price of type double. */
};

/** \struct index_portfolio_array
 * \brief Dynamic array to hold index_portfolios
 */
struct index_portfolio_array
{
	int size;
	int total_size;

	struct index_portfolio * array;
};

/** \var typedef index_portfolio index_portfolio
 * \brief Typedef for index_portfolio struct.
 */
typedef struct index_portfolio index_portfolio;
/** \var typedef index_portfolio_array index_portfolio_array
 * \brief Typedef for index_portfolio_array struct.
 */
typedef struct index_portfolio_array index_portfolio_array;
/** \struct Belief
 * \brief ADT containing belief attributes about stock market index.
 *
 * ADT containing belief attributes about stock market index.
 */
struct Belief
{
	double expected_dividend;	/**< Datatype memory variable expected_dividend of type double. */
	double expected_price;	/**< Datatype memory variable expected_price of type double. */
	double expected_return;	/**< Datatype memory variable expected_return of type double. */
	double expected_volatility;	/**< Datatype memory variable expected_volatility of type double. */
	double last_price;	/**< Datatype memory variable last_price of type double. */
	double fraction_to_invest;	/**< Datatype memory variable fraction_to_invest of type double. */
};

/** \struct Belief_array
 * \brief Dynamic array to hold Beliefs
 */
struct Belief_array
{
	int size;
	int total_size;

	struct Belief * array;
};

/** \var typedef Belief Belief
 * \brief Typedef for Belief struct.
 */
typedef struct Belief Belief;
/** \var typedef Belief_array Belief_array
 * \brief Typedef for Belief_array struct.
 */
typedef struct Belief_array Belief_array;
/** \struct capital_good_request
 * \brief Holds the capital good orders of the firms.
 *
 * Holds the capital good orders of the firms.
 */
struct capital_good_request
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double capital_good_order;	/**< Datatype memory variable capital_good_order of type double. */
	int vintage;	/**< Datatype memory variable vintage of type int. */
};

/** \struct capital_good_request_array
 * \brief Dynamic array to hold capital_good_requests
 */
struct capital_good_request_array
{
	int size;
	int total_size;

	struct capital_good_request * array;
};

/** \var typedef capital_good_request capital_good_request
 * \brief Typedef for capital_good_request struct.
 */
typedef struct capital_good_request capital_good_request;
/** \var typedef capital_good_request_array capital_good_request_array
 * \brief Typedef for capital_good_request_array struct.
 */
typedef struct capital_good_request_array capital_good_request_array;
/** \struct vintage
 * \brief Holds information about the different vintages..
 *
 * Holds information about the different vintages..
 */
struct vintage
{
	double productivity;	/**< Datatype memory variable productivity of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double discounted_productivity;	/**< Datatype memory variable discounted_productivity of type double. */
	double sales;	/**< Datatype memory variable sales of type double. */
};

/** \struct vintage_array
 * \brief Dynamic array to hold vintages
 */
struct vintage_array
{
	int size;
	int total_size;

	struct vintage * array;
};

/** \var typedef vintage vintage
 * \brief Typedef for vintage struct.
 */
typedef struct vintage vintage;
/** \var typedef vintage_array vintage_array
 * \brief Typedef for vintage_array struct.
 */
typedef struct vintage_array vintage_array;
/** \struct adt_sales_per_vintage
 * \brief Holds information about the sales of each vintage..
 *
 * Holds information about the sales of each vintage..
 */
struct adt_sales_per_vintage
{
	double productivity_of_vintage;	/**< Datatype memory variable productivity_of_vintage of type double. */
	double sales;	/**< Datatype memory variable sales of type double. */
	double revenue;	/**< Datatype memory variable revenue of type double. */
};

/** \struct adt_sales_per_vintage_array
 * \brief Dynamic array to hold adt_sales_per_vintages
 */
struct adt_sales_per_vintage_array
{
	int size;
	int total_size;

	struct adt_sales_per_vintage * array;
};

/** \var typedef adt_sales_per_vintage adt_sales_per_vintage
 * \brief Typedef for adt_sales_per_vintage struct.
 */
typedef struct adt_sales_per_vintage adt_sales_per_vintage;
/** \var typedef adt_sales_per_vintage_array adt_sales_per_vintage_array
 * \brief Typedef for adt_sales_per_vintage_array struct.
 */
typedef struct adt_sales_per_vintage_array adt_sales_per_vintage_array;
/** \struct adt_list_adaptation_speed
 * \brief Used by firm, household and IG firm to store the adaptation speeds for the skill groups.
 *
 * Used by firm, household and IG firm to store the adaptation speeds for the skill groups.
 */
struct adt_list_adaptation_speed
{
	int general_skill_level;	/**< Datatype memory variable general_skill_level of type int. */
	double adaptation_speed;	/**< Datatype memory variable adaptation_speed of type double. */
};

/** \struct adt_list_adaptation_speed_array
 * \brief Dynamic array to hold adt_list_adaptation_speeds
 */
struct adt_list_adaptation_speed_array
{
	int size;
	int total_size;

	struct adt_list_adaptation_speed * array;
};

/** \var typedef adt_list_adaptation_speed adt_list_adaptation_speed
 * \brief Typedef for adt_list_adaptation_speed struct.
 */
typedef struct adt_list_adaptation_speed adt_list_adaptation_speed;
/** \var typedef adt_list_adaptation_speed_array adt_list_adaptation_speed_array
 * \brief Typedef for adt_list_adaptation_speed_array struct.
 */
typedef struct adt_list_adaptation_speed_array adt_list_adaptation_speed_array;
/** \struct employee
 * \brief Used to hold employee information in firms.
 *
 * Used to hold employee information in firms.
 */
struct employee
{
	int id;	/**< Datatype memory variable id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double wage;	/**< Datatype memory variable wage of type double. */
	int general_skill;	/**< Datatype memory variable general_skill of type int. */
	double specific_skill;	/**< Datatype memory variable specific_skill of type double. */
	double subsidy_pct;	/**< Datatype memory variable subsidy_pct of type double. */
};

/** \struct employee_array
 * \brief Dynamic array to hold employees
 */
struct employee_array
{
	int size;
	int total_size;

	struct employee * array;
};

/** \var typedef employee employee
 * \brief Typedef for employee struct.
 */
typedef struct employee employee;
/** \var typedef employee_array employee_array
 * \brief Typedef for employee_array struct.
 */
typedef struct employee_array employee_array;
/** \struct vacancy
 * \brief Used by households to hold vacancy information.
 *
 * Used by households to hold vacancy information.
 */
struct vacancy
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double wage_offer;	/**< Datatype memory variable wage_offer of type double. */
	int job_type;	/**< Datatype memory variable job_type of type int. */
};

/** \struct vacancy_array
 * \brief Dynamic array to hold vacancys
 */
struct vacancy_array
{
	int size;
	int total_size;

	struct vacancy * array;
};

/** \var typedef vacancy vacancy
 * \brief Typedef for vacancy struct.
 */
typedef struct vacancy vacancy;
/** \var typedef vacancy_array vacancy_array
 * \brief Typedef for vacancy_array struct.
 */
typedef struct vacancy_array vacancy_array;
/** \struct job_application
 * \brief Used by firms to hold job applications.
 *
 * Used by firms to hold job applications.
 */
struct job_application
{
	int worker_id;	/**< Datatype memory variable worker_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int general_skill;	/**< Datatype memory variable general_skill of type int. */
	double specific_skill;	/**< Datatype memory variable specific_skill of type double. */
	double wage_offer;	/**< Datatype memory variable wage_offer of type double. */
	int job_type;	/**< Datatype memory variable job_type of type int. */
};

/** \struct job_application_array
 * \brief Dynamic array to hold job_applications
 */
struct job_application_array
{
	int size;
	int total_size;

	struct job_application * array;
};

/** \var typedef job_application job_application
 * \brief Typedef for job_application struct.
 */
typedef struct job_application job_application;
/** \var typedef job_application_array job_application_array
 * \brief Typedef for job_application_array struct.
 */
typedef struct job_application_array job_application_array;
/** \struct job_offer
 * \brief Used by households and firms to hold job offers.
 *
 * Used by households and firms to hold job offers.
 */
struct job_offer
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double wage_offer;	/**< Datatype memory variable wage_offer of type double. */
	int job_type;	/**< Datatype memory variable job_type of type int. */
};

/** \struct job_offer_array
 * \brief Dynamic array to hold job_offers
 */
struct job_offer_array
{
	int size;
	int total_size;

	struct job_offer * array;
};

/** \var typedef job_offer job_offer
 * \brief Typedef for job_offer struct.
 */
typedef struct job_offer job_offer;
/** \var typedef job_offer_array job_offer_array
 * \brief Typedef for job_offer_array struct.
 */
typedef struct job_offer_array job_offer_array;
/** \struct logit
 * \brief Used by firms to stock logits and corresponding worker IDs.
 *
 * Used by firms to stock logits and corresponding worker IDs.
 */
struct logit
{
	double logit_value;	/**< Datatype memory variable logit_value of type double. */
	int worker_id;	/**< Datatype memory variable worker_id of type int. */
	int general_skill;	/**< Datatype memory variable general_skill of type int. */
	double wage_offer;	/**< Datatype memory variable wage_offer of type double. */
	int job_type;	/**< Datatype memory variable job_type of type int. */
};

/** \struct logit_array
 * \brief Dynamic array to hold logits
 */
struct logit_array
{
	int size;
	int total_size;

	struct logit * array;
};

/** \var typedef logit logit
 * \brief Typedef for logit struct.
 */
typedef struct logit logit;
/** \var typedef logit_array logit_array
 * \brief Typedef for logit_array struct.
 */
typedef struct logit_array logit_array;
/** \struct adt_skill_distribution
 * \brief Skill distribution.
 *
 * Skill distribution.
 */
struct adt_skill_distribution
{
	int general_skill_group;	/**< Datatype memory variable general_skill_group of type int. */
	double percentage;	/**< Datatype memory variable percentage of type double. */
};

/** \struct adt_skill_distribution_array
 * \brief Dynamic array to hold adt_skill_distributions
 */
struct adt_skill_distribution_array
{
	int size;
	int total_size;

	struct adt_skill_distribution * array;
};

/** \var typedef adt_skill_distribution adt_skill_distribution
 * \brief Typedef for adt_skill_distribution struct.
 */
typedef struct adt_skill_distribution adt_skill_distribution;
/** \var typedef adt_skill_distribution_array adt_skill_distribution_array
 * \brief Typedef for adt_skill_distribution_array struct.
 */
typedef struct adt_skill_distribution_array adt_skill_distribution_array;
/** \struct adt_actual_skill_distribution_with_ids
 * \brief Skill distribution.
 *
 * Skill distribution.
 */
struct adt_actual_skill_distribution_with_ids
{
	int general_skill_group;	/**< Datatype memory variable general_skill_group of type int. */
	int_array id_list;	/**< Datatype memory variable id_list of type int_array. */
};

/** \struct adt_actual_skill_distribution_with_ids_array
 * \brief Dynamic array to hold adt_actual_skill_distribution_with_idss
 */
struct adt_actual_skill_distribution_with_ids_array
{
	int size;
	int total_size;

	struct adt_actual_skill_distribution_with_ids * array;
};

/** \var typedef adt_actual_skill_distribution_with_ids adt_actual_skill_distribution_with_ids
 * \brief Typedef for adt_actual_skill_distribution_with_ids struct.
 */
typedef struct adt_actual_skill_distribution_with_ids adt_actual_skill_distribution_with_ids;
/** \var typedef adt_actual_skill_distribution_with_ids_array adt_actual_skill_distribution_with_ids_array
 * \brief Typedef for adt_actual_skill_distribution_with_ids_array struct.
 */
typedef struct adt_actual_skill_distribution_with_ids_array adt_actual_skill_distribution_with_ids_array;
/** \struct adt_gov_inflows_outflows
 * \brief gov_inflows_outflows.
 *
 * gov_inflows_outflows.
 */
struct adt_gov_inflows_outflows
{
	double inflows;	/**< Datatype memory variable inflows of type double. */
	double outflows;	/**< Datatype memory variable outflows of type double. */
	double tax_basis;	/**< Datatype memory variable tax_basis of type double. */
};

/** \struct adt_gov_inflows_outflows_array
 * \brief Dynamic array to hold adt_gov_inflows_outflowss
 */
struct adt_gov_inflows_outflows_array
{
	int size;
	int total_size;

	struct adt_gov_inflows_outflows * array;
};

/** \var typedef adt_gov_inflows_outflows adt_gov_inflows_outflows
 * \brief Typedef for adt_gov_inflows_outflows struct.
 */
typedef struct adt_gov_inflows_outflows adt_gov_inflows_outflows;
/** \var typedef adt_gov_inflows_outflows_array adt_gov_inflows_outflows_array
 * \brief Typedef for adt_gov_inflows_outflows_array struct.
 */
typedef struct adt_gov_inflows_outflows_array adt_gov_inflows_outflows_array;
/** \struct household_data
 * \brief Used by Eurostat to store data of the different regions.
 *
 * Used by Eurostat to store data of the different regions.
 */
struct household_data
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int no_households;	/**< Datatype memory variable no_households of type int. */
	int no_households_skill_1;	/**< Datatype memory variable no_households_skill_1 of type int. */
	int no_households_skill_2;	/**< Datatype memory variable no_households_skill_2 of type int. */
	int no_households_skill_3;	/**< Datatype memory variable no_households_skill_3 of type int. */
	int no_households_skill_4;	/**< Datatype memory variable no_households_skill_4 of type int. */
	int no_households_skill_5;	/**< Datatype memory variable no_households_skill_5 of type int. */
	int employed;	/**< Datatype memory variable employed of type int. */
	int employed_skill_1;	/**< Datatype memory variable employed_skill_1 of type int. */
	int employed_skill_2;	/**< Datatype memory variable employed_skill_2 of type int. */
	int employed_skill_3;	/**< Datatype memory variable employed_skill_3 of type int. */
	int employed_skill_4;	/**< Datatype memory variable employed_skill_4 of type int. */
	int employed_skill_5;	/**< Datatype memory variable employed_skill_5 of type int. */
	int unemployed;	/**< Datatype memory variable unemployed of type int. */
	double unemployment_rate;	/**< Datatype memory variable unemployment_rate of type double. */
	double unemployment_rate_skill_1;	/**< Datatype memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< Datatype memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< Datatype memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< Datatype memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< Datatype memory variable unemployment_rate_skill_5 of type double. */
	double consumption_budget;	/**< Datatype memory variable consumption_budget of type double. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	double average_wage_skill_1;	/**< Datatype memory variable average_wage_skill_1 of type double. */
	double average_wage_skill_2;	/**< Datatype memory variable average_wage_skill_2 of type double. */
	double average_wage_skill_3;	/**< Datatype memory variable average_wage_skill_3 of type double. */
	double average_wage_skill_4;	/**< Datatype memory variable average_wage_skill_4 of type double. */
	double average_wage_skill_5;	/**< Datatype memory variable average_wage_skill_5 of type double. */
	double average_s_skill;	/**< Datatype memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< Datatype memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< Datatype memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< Datatype memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< Datatype memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< Datatype memory variable average_s_skill_5 of type double. */
};

/** \struct household_data_array
 * \brief Dynamic array to hold household_datas
 */
struct household_data_array
{
	int size;
	int total_size;

	struct household_data * array;
};

/** \var typedef household_data household_data
 * \brief Typedef for household_data struct.
 */
typedef struct household_data household_data;
/** \var typedef household_data_array household_data_array
 * \brief Typedef for household_data_array struct.
 */
typedef struct household_data_array household_data_array;
/** \struct price_quality_pair
 * \brief .
 *
 * .
 */
struct price_quality_pair
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double price;	/**< Datatype memory variable price of type double. */
	double quality;	/**< Datatype memory variable quality of type double. */
};

/** \struct price_quality_pair_array
 * \brief Dynamic array to hold price_quality_pairs
 */
struct price_quality_pair_array
{
	int size;
	int total_size;

	struct price_quality_pair * array;
};

/** \var typedef price_quality_pair price_quality_pair
 * \brief Typedef for price_quality_pair struct.
 */
typedef struct price_quality_pair price_quality_pair;
/** \var typedef price_quality_pair_array price_quality_pair_array
 * \brief Typedef for price_quality_pair_array struct.
 */
typedef struct price_quality_pair_array price_quality_pair_array;
/** \struct firm_data
 * \brief Used by Eurostat to store data of the different regions.
 *
 * Used by Eurostat to store data of the different regions.
 */
struct firm_data
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int no_firms;	/**< Datatype memory variable no_firms of type int. */
	int no_active_firms;	/**< Datatype memory variable no_active_firms of type int. */
	int vacancies;	/**< Datatype memory variable vacancies of type int. */
	int posted_vacancies;	/**< Datatype memory variable posted_vacancies of type int. */
	int employees;	/**< Datatype memory variable employees of type int. */
	int employees_skill_1;	/**< Datatype memory variable employees_skill_1 of type int. */
	int employees_skill_2;	/**< Datatype memory variable employees_skill_2 of type int. */
	int employees_skill_3;	/**< Datatype memory variable employees_skill_3 of type int. */
	int employees_skill_4;	/**< Datatype memory variable employees_skill_4 of type int. */
	int employees_skill_5;	/**< Datatype memory variable employees_skill_5 of type int. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	double average_wage_skill_1;	/**< Datatype memory variable average_wage_skill_1 of type double. */
	double average_wage_skill_2;	/**< Datatype memory variable average_wage_skill_2 of type double. */
	double average_wage_skill_3;	/**< Datatype memory variable average_wage_skill_3 of type double. */
	double average_wage_skill_4;	/**< Datatype memory variable average_wage_skill_4 of type double. */
	double average_wage_skill_5;	/**< Datatype memory variable average_wage_skill_5 of type double. */
	double average_s_skill;	/**< Datatype memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< Datatype memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< Datatype memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< Datatype memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< Datatype memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< Datatype memory variable average_s_skill_5 of type double. */
	double labour_productivity;	/**< Datatype memory variable labour_productivity of type double. */
	double total_earnings;	/**< Datatype memory variable total_earnings of type double. */
	double total_debt;	/**< Datatype memory variable total_debt of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double total_equity;	/**< Datatype memory variable total_equity of type double. */
	double average_debt_earnings_ratio;	/**< Datatype memory variable average_debt_earnings_ratio of type double. */
	double average_debt_equity_ratio;	/**< Datatype memory variable average_debt_equity_ratio of type double. */
	double labour_share_ratio;	/**< Datatype memory variable labour_share_ratio of type double. */
	double monthly_sold_quantity;	/**< Datatype memory variable monthly_sold_quantity of type double. */
	double monthly_output;	/**< Datatype memory variable monthly_output of type double. */
	double monthly_revenue;	/**< Datatype memory variable monthly_revenue of type double. */
	double monthly_planned_output;	/**< Datatype memory variable monthly_planned_output of type double. */
	double monthly_investment_value;	/**< Datatype memory variable monthly_investment_value of type double. */
	double investment_gdp_ratio;	/**< Datatype memory variable investment_gdp_ratio of type double. */
	double gdp;	/**< Datatype memory variable gdp of type double. */
	double cpi;	/**< Datatype memory variable cpi of type double. */
	double cpi_last_month;	/**< Datatype memory variable cpi_last_month of type double. */
	int no_firm_births;	/**< Datatype memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< Datatype memory variable no_firm_deaths of type int. */
	double productivity_progress;	/**< Datatype memory variable productivity_progress of type double. */
	double productivity;	/**< Datatype memory variable productivity of type double. */
	double wage_offer;	/**< Datatype memory variable wage_offer of type double. */
	double technology;	/**< Datatype memory variable technology of type double. */
};

/** \struct firm_data_array
 * \brief Dynamic array to hold firm_datas
 */
struct firm_data_array
{
	int size;
	int total_size;

	struct firm_data * array;
};

/** \var typedef firm_data firm_data
 * \brief Typedef for firm_data struct.
 */
typedef struct firm_data firm_data;
/** \var typedef firm_data_array firm_data_array
 * \brief Typedef for firm_data_array struct.
 */
typedef struct firm_data_array firm_data_array;
/** \struct government_data
 * \brief Used by Eurostat to store data from different regions.
 *
 * Used by Eurostat to store data from different regions.
 */
struct government_data
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double consumption_expenditures;	/**< Datatype memory variable consumption_expenditures of type double. */
};

/** \struct government_data_array
 * \brief Dynamic array to hold government_datas
 */
struct government_data_array
{
	int size;
	int total_size;

	struct government_data * array;
};

/** \var typedef government_data government_data
 * \brief Typedef for government_data struct.
 */
typedef struct government_data government_data;
/** \var typedef government_data_array government_data_array
 * \brief Typedef for government_data_array struct.
 */
typedef struct government_data_array government_data_array;
/** \struct region_data_item
 * \brief Used by Eurostat to store data from different regions.
 *
 * Used by Eurostat to store data from different regions.
 */
struct region_data_item
{
	double cpi;	/**< Datatype memory variable cpi of type double. */
	double cpi_last_month;	/**< Datatype memory variable cpi_last_month of type double. */
	double gdp;	/**< Datatype memory variable gdp of type double. */
	double output;	/**< Datatype memory variable output of type double. */
	int employment;	/**< Datatype memory variable employment of type int. */
	double unemployment_rate;	/**< Datatype memory variable unemployment_rate of type double. */
	double unemployment_rate_skill_1;	/**< Datatype memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< Datatype memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< Datatype memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< Datatype memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< Datatype memory variable unemployment_rate_skill_5 of type double. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	int no_firms;	/**< Datatype memory variable no_firms of type int. */
	int no_active_firms;	/**< Datatype memory variable no_active_firms of type int. */
	int no_firm_births;	/**< Datatype memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< Datatype memory variable no_firm_deaths of type int. */
	double investment_value;	/**< Datatype memory variable investment_value of type double. */
};

/** \struct region_data_item_array
 * \brief Dynamic array to hold region_data_items
 */
struct region_data_item_array
{
	int size;
	int total_size;

	struct region_data_item * array;
};

/** \var typedef region_data_item region_data_item
 * \brief Typedef for region_data_item struct.
 */
typedef struct region_data_item region_data_item;
/** \var typedef region_data_item_array region_data_item_array
 * \brief Typedef for region_data_item_array struct.
 */
typedef struct region_data_item_array region_data_item_array;
/** \struct history_item
 * \brief Used by Eurostat to store history data.
 *
 * Used by Eurostat to store history data.
 */
struct history_item
{
	double cpi;	/**< Datatype memory variable cpi of type double. */
	double gdp;	/**< Datatype memory variable gdp of type double. */
	double output;	/**< Datatype memory variable output of type double. */
	int employment;	/**< Datatype memory variable employment of type int. */
	double unemployment_rate;	/**< Datatype memory variable unemployment_rate of type double. */
	double unemployment_rate_skill_1;	/**< Datatype memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< Datatype memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< Datatype memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< Datatype memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< Datatype memory variable unemployment_rate_skill_5 of type double. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	int no_firms;	/**< Datatype memory variable no_firms of type int. */
	int no_active_firms;	/**< Datatype memory variable no_active_firms of type int. */
	int no_firm_births;	/**< Datatype memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< Datatype memory variable no_firm_deaths of type int. */
	double investment_value;	/**< Datatype memory variable investment_value of type double. */
	region_data_item_array region_data;	/**< Datatype memory variable region_data of type region_data_item_array. */
};

/** \struct history_item_array
 * \brief Dynamic array to hold history_items
 */
struct history_item_array
{
	int size;
	int total_size;

	struct history_item * array;
};

/** \var typedef history_item history_item
 * \brief Typedef for history_item struct.
 */
typedef struct history_item history_item;
/** \var typedef history_item_array history_item_array
 * \brief Typedef for history_item_array struct.
 */
typedef struct history_item_array history_item_array;
/** \struct firm_stocks_adt
 * \brief Datastructure containing balance sheet stocks of the firm.
 *
 * Datastructure containing balance sheet stocks of the firm.
 */
struct firm_stocks_adt
{
	double payment_account;	/**< Datatype memory variable payment_account of type double. */
	double total_value_local_inventory;	/**< Datatype memory variable total_value_local_inventory of type double. */
	double total_value_capital_stock;	/**< Datatype memory variable total_value_capital_stock of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double total_debt;	/**< Datatype memory variable total_debt of type double. */
	double equity;	/**< Datatype memory variable equity of type double. */
	double total_liabilities;	/**< Datatype memory variable total_liabilities of type double. */
	int current_shares_outstanding;	/**< Datatype memory variable current_shares_outstanding of type int. */
	double payment_account_day_1;	/**< Datatype memory variable payment_account_day_1 of type double. */
	double payment_account_day_20;	/**< Datatype memory variable payment_account_day_20 of type double. */
};

/** \struct firm_stocks_adt_array
 * \brief Dynamic array to hold firm_stocks_adts
 */
struct firm_stocks_adt_array
{
	int size;
	int total_size;

	struct firm_stocks_adt * array;
};

/** \var typedef firm_stocks_adt firm_stocks_adt
 * \brief Typedef for firm_stocks_adt struct.
 */
typedef struct firm_stocks_adt firm_stocks_adt;
/** \var typedef firm_stocks_adt_array firm_stocks_adt_array
 * \brief Typedef for firm_stocks_adt_array struct.
 */
typedef struct firm_stocks_adt_array firm_stocks_adt_array;
/** \struct firm_outflows_adt
 * \brief Datastructure containing balance sheet outflows of the firm.
 *
 * Datastructure containing balance sheet outflows of the firm.
 */
struct firm_outflows_adt
{
	double labour_costs;	/**< Datatype memory variable labour_costs of type double. */
	double capital_costs;	/**< Datatype memory variable capital_costs of type double. */
	double energy_costs;	/**< Datatype memory variable energy_costs of type double. */
	double tax_payment;	/**< Datatype memory variable tax_payment of type double. */
	double total_debt_installment_payment;	/**< Datatype memory variable total_debt_installment_payment of type double. */
	double total_interest_payment;	/**< Datatype memory variable total_interest_payment of type double. */
	double total_dividend_payment;	/**< Datatype memory variable total_dividend_payment of type double. */
	double value_of_repurchased_shares;	/**< Datatype memory variable value_of_repurchased_shares of type double. */
	double total_expenses;	/**< Datatype memory variable total_expenses of type double. */
};

/** \struct firm_outflows_adt_array
 * \brief Dynamic array to hold firm_outflows_adts
 */
struct firm_outflows_adt_array
{
	int size;
	int total_size;

	struct firm_outflows_adt * array;
};

/** \var typedef firm_outflows_adt firm_outflows_adt
 * \brief Typedef for firm_outflows_adt struct.
 */
typedef struct firm_outflows_adt firm_outflows_adt;
/** \var typedef firm_outflows_adt_array firm_outflows_adt_array
 * \brief Typedef for firm_outflows_adt_array struct.
 */
typedef struct firm_outflows_adt_array firm_outflows_adt_array;
/** \struct firm_inflows_adt
 * \brief Datastructure containing balance sheet inflows of the firm.
 *
 * Datastructure containing balance sheet inflows of the firm.
 */
struct firm_inflows_adt
{
	double cum_revenue;	/**< Datatype memory variable cum_revenue of type double. */
	double new_loans;	/**< Datatype memory variable new_loans of type double. */
	double value_of_issued_shares;	/**< Datatype memory variable value_of_issued_shares of type double. */
	double subsidy;	/**< Datatype memory variable subsidy of type double. */
	double total_income;	/**< Datatype memory variable total_income of type double. */
	double deposit_interest;	/**< Datatype memory variable deposit_interest of type double. */
	double net_inflow;	/**< Datatype memory variable net_inflow of type double. */
};

/** \struct firm_inflows_adt_array
 * \brief Dynamic array to hold firm_inflows_adts
 */
struct firm_inflows_adt_array
{
	int size;
	int total_size;

	struct firm_inflows_adt * array;
};

/** \var typedef firm_inflows_adt firm_inflows_adt
 * \brief Typedef for firm_inflows_adt struct.
 */
typedef struct firm_inflows_adt firm_inflows_adt;
/** \var typedef firm_inflows_adt_array firm_inflows_adt_array
 * \brief Typedef for firm_inflows_adt_array struct.
 */
typedef struct firm_inflows_adt_array firm_inflows_adt_array;
/** \struct household_stocks_adt
 * \brief Datastructure containing balance sheet stocks of the household.
 *
 * Datastructure containing balance sheet stocks of the household.
 */
struct household_stocks_adt
{
	double payment_account;	/**< Datatype memory variable payment_account of type double. */
	double portfolio_value;	/**< Datatype memory variable portfolio_value of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double total_liabilities;	/**< Datatype memory variable total_liabilities of type double. */
	int nr_assets;	/**< Datatype memory variable nr_assets of type int. */
	double payment_account_day_1;	/**< Datatype memory variable payment_account_day_1 of type double. */
	double payment_account_day_20;	/**< Datatype memory variable payment_account_day_20 of type double. */
};

/** \struct household_stocks_adt_array
 * \brief Dynamic array to hold household_stocks_adts
 */
struct household_stocks_adt_array
{
	int size;
	int total_size;

	struct household_stocks_adt * array;
};

/** \var typedef household_stocks_adt household_stocks_adt
 * \brief Typedef for household_stocks_adt struct.
 */
typedef struct household_stocks_adt household_stocks_adt;
/** \var typedef household_stocks_adt_array household_stocks_adt_array
 * \brief Typedef for household_stocks_adt_array struct.
 */
typedef struct household_stocks_adt_array household_stocks_adt_array;
/** \struct household_outflows_adt
 * \brief Datastructure containing balance sheet outflows of the household.
 *
 * Datastructure containing balance sheet outflows of the household.
 */
struct household_outflows_adt
{
	double consumption_expenditure;	/**< Datatype memory variable consumption_expenditure of type double. */
	double tax_payment;	/**< Datatype memory variable tax_payment of type double. */
	double restitution_payment;	/**< Datatype memory variable restitution_payment of type double. */
	double asset_purchases;	/**< Datatype memory variable asset_purchases of type double. */
	double total_expenses;	/**< Datatype memory variable total_expenses of type double. */
};

/** \struct household_outflows_adt_array
 * \brief Dynamic array to hold household_outflows_adts
 */
struct household_outflows_adt_array
{
	int size;
	int total_size;

	struct household_outflows_adt * array;
};

/** \var typedef household_outflows_adt household_outflows_adt
 * \brief Typedef for household_outflows_adt struct.
 */
typedef struct household_outflows_adt household_outflows_adt;
/** \var typedef household_outflows_adt_array household_outflows_adt_array
 * \brief Typedef for household_outflows_adt_array struct.
 */
typedef struct household_outflows_adt_array household_outflows_adt_array;
/** \struct household_inflows_adt
 * \brief Datastructure containing balance sheet inflows of the household.
 *
 * Datastructure containing balance sheet inflows of the household.
 */
struct household_inflows_adt
{
	double wage;	/**< Datatype memory variable wage of type double. */
	double unemployment_benefit;	/**< Datatype memory variable unemployment_benefit of type double. */
	double subsidies;	/**< Datatype memory variable subsidies of type double. */
	double transfer;	/**< Datatype memory variable transfer of type double. */
	double gov_interest;	/**< Datatype memory variable gov_interest of type double. */
	double asset_sales;	/**< Datatype memory variable asset_sales of type double. */
	double total_dividends;	/**< Datatype memory variable total_dividends of type double. */
	double deposit_interest;	/**< Datatype memory variable deposit_interest of type double. */
	double total_income;	/**< Datatype memory variable total_income of type double. */
	double net_inflow;	/**< Datatype memory variable net_inflow of type double. */
};

/** \struct household_inflows_adt_array
 * \brief Dynamic array to hold household_inflows_adts
 */
struct household_inflows_adt_array
{
	int size;
	int total_size;

	struct household_inflows_adt * array;
};

/** \var typedef household_inflows_adt household_inflows_adt
 * \brief Typedef for household_inflows_adt struct.
 */
typedef struct household_inflows_adt household_inflows_adt;
/** \var typedef household_inflows_adt_array household_inflows_adt_array
 * \brief Typedef for household_inflows_adt_array struct.
 */
typedef struct household_inflows_adt_array household_inflows_adt_array;
/** \struct igfirm_stocks_adt
 * \brief Datastructure containing balance sheet stocks of the IGFirm.
 *
 * Datastructure containing balance sheet stocks of the IGFirm.
 */
struct igfirm_stocks_adt
{
	double payment_account;	/**< Datatype memory variable payment_account of type double. */
	double total_value_local_inventory;	/**< Datatype memory variable total_value_local_inventory of type double. */
	double total_value_capital_stock;	/**< Datatype memory variable total_value_capital_stock of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double total_debt;	/**< Datatype memory variable total_debt of type double. */
	double equity;	/**< Datatype memory variable equity of type double. */
	double total_liabilities;	/**< Datatype memory variable total_liabilities of type double. */
	int current_shares_outstanding;	/**< Datatype memory variable current_shares_outstanding of type int. */
	double payment_account_day_1;	/**< Datatype memory variable payment_account_day_1 of type double. */
	double payment_account_day_20;	/**< Datatype memory variable payment_account_day_20 of type double. */
};

/** \struct igfirm_stocks_adt_array
 * \brief Dynamic array to hold igfirm_stocks_adts
 */
struct igfirm_stocks_adt_array
{
	int size;
	int total_size;

	struct igfirm_stocks_adt * array;
};

/** \var typedef igfirm_stocks_adt igfirm_stocks_adt
 * \brief Typedef for igfirm_stocks_adt struct.
 */
typedef struct igfirm_stocks_adt igfirm_stocks_adt;
/** \var typedef igfirm_stocks_adt_array igfirm_stocks_adt_array
 * \brief Typedef for igfirm_stocks_adt_array struct.
 */
typedef struct igfirm_stocks_adt_array igfirm_stocks_adt_array;
/** \struct igfirm_outflows_adt
 * \brief Datastructure containing balance sheet outflows of the IGFirm.
 *
 * Datastructure containing balance sheet outflows of the IGFirm.
 */
struct igfirm_outflows_adt
{
	double labour_costs;	/**< Datatype memory variable labour_costs of type double. */
	double capital_costs;	/**< Datatype memory variable capital_costs of type double. */
	double energy_costs;	/**< Datatype memory variable energy_costs of type double. */
	double tax_payment;	/**< Datatype memory variable tax_payment of type double. */
	double total_debt_installment_payment;	/**< Datatype memory variable total_debt_installment_payment of type double. */
	double total_interest_payment;	/**< Datatype memory variable total_interest_payment of type double. */
	double total_dividend_payment;	/**< Datatype memory variable total_dividend_payment of type double. */
	double value_of_repurchased_shares;	/**< Datatype memory variable value_of_repurchased_shares of type double. */
	double total_expenses;	/**< Datatype memory variable total_expenses of type double. */
};

/** \struct igfirm_outflows_adt_array
 * \brief Dynamic array to hold igfirm_outflows_adts
 */
struct igfirm_outflows_adt_array
{
	int size;
	int total_size;

	struct igfirm_outflows_adt * array;
};

/** \var typedef igfirm_outflows_adt igfirm_outflows_adt
 * \brief Typedef for igfirm_outflows_adt struct.
 */
typedef struct igfirm_outflows_adt igfirm_outflows_adt;
/** \var typedef igfirm_outflows_adt_array igfirm_outflows_adt_array
 * \brief Typedef for igfirm_outflows_adt_array struct.
 */
typedef struct igfirm_outflows_adt_array igfirm_outflows_adt_array;
/** \struct igfirm_inflows_adt
 * \brief Datastructure containing balance sheet inflows of the IGFirm.
 *
 * Datastructure containing balance sheet inflows of the IGFirm.
 */
struct igfirm_inflows_adt
{
	double cum_revenue;	/**< Datatype memory variable cum_revenue of type double. */
	double new_loans;	/**< Datatype memory variable new_loans of type double. */
	double value_of_issued_shares;	/**< Datatype memory variable value_of_issued_shares of type double. */
	double subsidy;	/**< Datatype memory variable subsidy of type double. */
	double total_income;	/**< Datatype memory variable total_income of type double. */
	double deposit_interest;	/**< Datatype memory variable deposit_interest of type double. */
	double net_inflow;	/**< Datatype memory variable net_inflow of type double. */
};

/** \struct igfirm_inflows_adt_array
 * \brief Dynamic array to hold igfirm_inflows_adts
 */
struct igfirm_inflows_adt_array
{
	int size;
	int total_size;

	struct igfirm_inflows_adt * array;
};

/** \var typedef igfirm_inflows_adt igfirm_inflows_adt
 * \brief Typedef for igfirm_inflows_adt struct.
 */
typedef struct igfirm_inflows_adt igfirm_inflows_adt;
/** \var typedef igfirm_inflows_adt_array igfirm_inflows_adt_array
 * \brief Typedef for igfirm_inflows_adt_array struct.
 */
typedef struct igfirm_inflows_adt_array igfirm_inflows_adt_array;
/** \struct bank_stocks_adt
 * \brief Datastructure containing balance sheet stocks of the bank.
 *
 * Datastructure containing balance sheet stocks of the bank.
 */
struct bank_stocks_adt
{
	double cash;	/**< Datatype memory variable cash of type double. */
	double total_credit;	/**< Datatype memory variable total_credit of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double deposits;	/**< Datatype memory variable deposits of type double. */
	double ecb_debt;	/**< Datatype memory variable ecb_debt of type double. */
	double equity;	/**< Datatype memory variable equity of type double. */
	double total_liabilities;	/**< Datatype memory variable total_liabilities of type double. */
	int current_shares_outstanding;	/**< Datatype memory variable current_shares_outstanding of type int. */
	double cash_day_1;	/**< Datatype memory variable cash_day_1 of type double. */
	double cash_day_20;	/**< Datatype memory variable cash_day_20 of type double. */
};

/** \struct bank_stocks_adt_array
 * \brief Dynamic array to hold bank_stocks_adts
 */
struct bank_stocks_adt_array
{
	int size;
	int total_size;

	struct bank_stocks_adt * array;
};

/** \var typedef bank_stocks_adt bank_stocks_adt
 * \brief Typedef for bank_stocks_adt struct.
 */
typedef struct bank_stocks_adt bank_stocks_adt;
/** \var typedef bank_stocks_adt_array bank_stocks_adt_array
 * \brief Typedef for bank_stocks_adt_array struct.
 */
typedef struct bank_stocks_adt_array bank_stocks_adt_array;
/** \struct bank_outflows_adt
 * \brief Datastructure containing balance sheet outflows of the bank.
 *
 * Datastructure containing balance sheet outflows of the bank.
 */
struct bank_outflows_adt
{
	double firm_loan_issues;	/**< Datatype memory variable firm_loan_issues of type double. */
	double debt_installment_to_ecb;	/**< Datatype memory variable debt_installment_to_ecb of type double. */
	double ecb_interest_payment;	/**< Datatype memory variable ecb_interest_payment of type double. */
	double deposit_interest_payment;	/**< Datatype memory variable deposit_interest_payment of type double. */
	double dividend_payment;	/**< Datatype memory variable dividend_payment of type double. */
	double tax_payment;	/**< Datatype memory variable tax_payment of type double. */
	double deposit_outflow;	/**< Datatype memory variable deposit_outflow of type double. */
	double total_expenses;	/**< Datatype memory variable total_expenses of type double. */
};

/** \struct bank_outflows_adt_array
 * \brief Dynamic array to hold bank_outflows_adts
 */
struct bank_outflows_adt_array
{
	int size;
	int total_size;

	struct bank_outflows_adt * array;
};

/** \var typedef bank_outflows_adt bank_outflows_adt
 * \brief Typedef for bank_outflows_adt struct.
 */
typedef struct bank_outflows_adt bank_outflows_adt;
/** \var typedef bank_outflows_adt_array bank_outflows_adt_array
 * \brief Typedef for bank_outflows_adt_array struct.
 */
typedef struct bank_outflows_adt_array bank_outflows_adt_array;
/** \struct bank_inflows_adt
 * \brief Datastructure containing balance sheet inflows of the bank.
 *
 * Datastructure containing balance sheet inflows of the bank.
 */
struct bank_inflows_adt
{
	double firm_loan_installments;	/**< Datatype memory variable firm_loan_installments of type double. */
	double firm_interest_payments;	/**< Datatype memory variable firm_interest_payments of type double. */
	double new_ecb_debt;	/**< Datatype memory variable new_ecb_debt of type double. */
	double deposit_inflow;	/**< Datatype memory variable deposit_inflow of type double. */
	double total_income;	/**< Datatype memory variable total_income of type double. */
	double net_inflow;	/**< Datatype memory variable net_inflow of type double. */
	double net_deposit_inflow;	/**< Datatype memory variable net_deposit_inflow of type double. */
};

/** \struct bank_inflows_adt_array
 * \brief Dynamic array to hold bank_inflows_adts
 */
struct bank_inflows_adt_array
{
	int size;
	int total_size;

	struct bank_inflows_adt * array;
};

/** \var typedef bank_inflows_adt bank_inflows_adt
 * \brief Typedef for bank_inflows_adt struct.
 */
typedef struct bank_inflows_adt bank_inflows_adt;
/** \var typedef bank_inflows_adt_array bank_inflows_adt_array
 * \brief Typedef for bank_inflows_adt_array struct.
 */
typedef struct bank_inflows_adt_array bank_inflows_adt_array;
/** \struct gov_stocks_adt
 * \brief Datastructure containing balance sheet stocks of the Government.
 *
 * Datastructure containing balance sheet stocks of the Government.
 */
struct gov_stocks_adt
{
	double payment_account;	/**< Datatype memory variable payment_account of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double value_bonds_outstanding;	/**< Datatype memory variable value_bonds_outstanding of type double. */
	double ecb_money;	/**< Datatype memory variable ecb_money of type double. */
	double equity;	/**< Datatype memory variable equity of type double. */
	double total_liabilities;	/**< Datatype memory variable total_liabilities of type double. */
	int nr_bonds_outstanding;	/**< Datatype memory variable nr_bonds_outstanding of type int. */
	double payment_account_day_1;	/**< Datatype memory variable payment_account_day_1 of type double. */
	double payment_account_day_20;	/**< Datatype memory variable payment_account_day_20 of type double. */
};

/** \struct gov_stocks_adt_array
 * \brief Dynamic array to hold gov_stocks_adts
 */
struct gov_stocks_adt_array
{
	int size;
	int total_size;

	struct gov_stocks_adt * array;
};

/** \var typedef gov_stocks_adt gov_stocks_adt
 * \brief Typedef for gov_stocks_adt struct.
 */
typedef struct gov_stocks_adt gov_stocks_adt;
/** \var typedef gov_stocks_adt_array gov_stocks_adt_array
 * \brief Typedef for gov_stocks_adt_array struct.
 */
typedef struct gov_stocks_adt_array gov_stocks_adt_array;
/** \struct gov_outflows_adt
 * \brief Datastructure containing balance sheet outflows of the Government.
 *
 * Datastructure containing balance sheet outflows of the Government.
 */
struct gov_outflows_adt
{
	double investment_expenditure;	/**< Datatype memory variable investment_expenditure of type double. */
	double consumption_expenditure;	/**< Datatype memory variable consumption_expenditure of type double. */
	double benefit_payment;	/**< Datatype memory variable benefit_payment of type double. */
	double subsidy_payment_household;	/**< Datatype memory variable subsidy_payment_household of type double. */
	double subsidy_payment_firm;	/**< Datatype memory variable subsidy_payment_firm of type double. */
	double transfer_payment_household;	/**< Datatype memory variable transfer_payment_household of type double. */
	double transfer_payment_firm;	/**< Datatype memory variable transfer_payment_firm of type double. */
	double bond_interest_payment;	/**< Datatype memory variable bond_interest_payment of type double. */
	double debt_installment;	/**< Datatype memory variable debt_installment of type double. */
	double total_bond_repurchase;	/**< Datatype memory variable total_bond_repurchase of type double. */
	double total_expenses;	/**< Datatype memory variable total_expenses of type double. */
};

/** \struct gov_outflows_adt_array
 * \brief Dynamic array to hold gov_outflows_adts
 */
struct gov_outflows_adt_array
{
	int size;
	int total_size;

	struct gov_outflows_adt * array;
};

/** \var typedef gov_outflows_adt gov_outflows_adt
 * \brief Typedef for gov_outflows_adt struct.
 */
typedef struct gov_outflows_adt gov_outflows_adt;
/** \var typedef gov_outflows_adt_array gov_outflows_adt_array
 * \brief Typedef for gov_outflows_adt_array struct.
 */
typedef struct gov_outflows_adt_array gov_outflows_adt_array;
/** \struct gov_inflows_adt
 * \brief Datastructure containing balance sheet inflows of the Government.
 *
 * Datastructure containing balance sheet inflows of the Government.
 */
struct gov_inflows_adt
{
	double tax_revenues;	/**< Datatype memory variable tax_revenues of type double. */
	double restitution_payment;	/**< Datatype memory variable restitution_payment of type double. */
	double total_bond_financing;	/**< Datatype memory variable total_bond_financing of type double. */
	double total_money_financing;	/**< Datatype memory variable total_money_financing of type double. */
	double ecb_dividend;	/**< Datatype memory variable ecb_dividend of type double. */
	double total_income;	/**< Datatype memory variable total_income of type double. */
	double net_inflow;	/**< Datatype memory variable net_inflow of type double. */
};

/** \struct gov_inflows_adt_array
 * \brief Dynamic array to hold gov_inflows_adts
 */
struct gov_inflows_adt_array
{
	int size;
	int total_size;

	struct gov_inflows_adt * array;
};

/** \var typedef gov_inflows_adt gov_inflows_adt
 * \brief Typedef for gov_inflows_adt struct.
 */
typedef struct gov_inflows_adt gov_inflows_adt;
/** \var typedef gov_inflows_adt_array gov_inflows_adt_array
 * \brief Typedef for gov_inflows_adt_array struct.
 */
typedef struct gov_inflows_adt_array gov_inflows_adt_array;
/** \struct ecb_stocks_adt
 * \brief Datastructure containing balance sheet stocks of the Central Bank.
 *
 * Datastructure containing balance sheet stocks of the Central Bank.
 */
struct ecb_stocks_adt
{
	double cash;	/**< Datatype memory variable cash of type double. */
	double gov_bond_holdings;	/**< Datatype memory variable gov_bond_holdings of type double. */
	double fiat_money_banks;	/**< Datatype memory variable fiat_money_banks of type double. */
	double fiat_money_govs;	/**< Datatype memory variable fiat_money_govs of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double payment_account_banks;	/**< Datatype memory variable payment_account_banks of type double. */
	double payment_account_govs;	/**< Datatype memory variable payment_account_govs of type double. */
	double fiat_money;	/**< Datatype memory variable fiat_money of type double. */
	double equity;	/**< Datatype memory variable equity of type double. */
	double total_liabilities;	/**< Datatype memory variable total_liabilities of type double. */
	int nr_gov_bonds;	/**< Datatype memory variable nr_gov_bonds of type int. */
	double equity_day_1;	/**< Datatype memory variable equity_day_1 of type double. */
	double fiat_money_govs_bond;	/**< Datatype memory variable fiat_money_govs_bond of type double. */
};

/** \struct ecb_stocks_adt_array
 * \brief Dynamic array to hold ecb_stocks_adts
 */
struct ecb_stocks_adt_array
{
	int size;
	int total_size;

	struct ecb_stocks_adt * array;
};

/** \var typedef ecb_stocks_adt ecb_stocks_adt
 * \brief Typedef for ecb_stocks_adt struct.
 */
typedef struct ecb_stocks_adt ecb_stocks_adt;
/** \var typedef ecb_stocks_adt_array ecb_stocks_adt_array
 * \brief Typedef for ecb_stocks_adt_array struct.
 */
typedef struct ecb_stocks_adt_array ecb_stocks_adt_array;
/** \struct ecb_outflows_adt
 * \brief Datastructure containing balance sheet outflows of the ECB.
 *
 * Datastructure containing balance sheet outflows of the ECB.
 */
struct ecb_outflows_adt
{
	double gov_bond_purchase;	/**< Datatype memory variable gov_bond_purchase of type double. */
	double bank_fiat_money;	/**< Datatype memory variable bank_fiat_money of type double. */
	double bank_deposits;	/**< Datatype memory variable bank_deposits of type double. */
	double gov_deposits;	/**< Datatype memory variable gov_deposits of type double. */
	double dividend_payment;	/**< Datatype memory variable dividend_payment of type double. */
	double total_expenses;	/**< Datatype memory variable total_expenses of type double. */
};

/** \struct ecb_outflows_adt_array
 * \brief Dynamic array to hold ecb_outflows_adts
 */
struct ecb_outflows_adt_array
{
	int size;
	int total_size;

	struct ecb_outflows_adt * array;
};

/** \var typedef ecb_outflows_adt ecb_outflows_adt
 * \brief Typedef for ecb_outflows_adt struct.
 */
typedef struct ecb_outflows_adt ecb_outflows_adt;
/** \var typedef ecb_outflows_adt_array ecb_outflows_adt_array
 * \brief Typedef for ecb_outflows_adt_array struct.
 */
typedef struct ecb_outflows_adt_array ecb_outflows_adt_array;
/** \struct ecb_inflows_adt
 * \brief Datastructure containing balance sheet inflows of the ECB.
 *
 * Datastructure containing balance sheet inflows of the ECB.
 */
struct ecb_inflows_adt
{
	double bank_interest;	/**< Datatype memory variable bank_interest of type double. */
	double bank_debt_installment;	/**< Datatype memory variable bank_debt_installment of type double. */
	double gov_interest;	/**< Datatype memory variable gov_interest of type double. */
	double bank_deposits;	/**< Datatype memory variable bank_deposits of type double. */
	double gov_deposits;	/**< Datatype memory variable gov_deposits of type double. */
	double total_income;	/**< Datatype memory variable total_income of type double. */
	double net_inflow;	/**< Datatype memory variable net_inflow of type double. */
};

/** \struct ecb_inflows_adt_array
 * \brief Dynamic array to hold ecb_inflows_adts
 */
struct ecb_inflows_adt_array
{
	int size;
	int total_size;

	struct ecb_inflows_adt * array;
};

/** \var typedef ecb_inflows_adt ecb_inflows_adt
 * \brief Typedef for ecb_inflows_adt struct.
 */
typedef struct ecb_inflows_adt ecb_inflows_adt;
/** \var typedef ecb_inflows_adt_array ecb_inflows_adt_array
 * \brief Typedef for ecb_inflows_adt_array struct.
 */
typedef struct ecb_inflows_adt_array ecb_inflows_adt_array;
/** \struct firm_balance_sheet_adt
 * \brief ADT containing the firm balance sheet..
 *
 * ADT containing the firm balance sheet..
 */
struct firm_balance_sheet_adt
{
	firm_stocks_adt stocks;	/**< Datatype memory variable stocks of type firm_stocks_adt. */
	firm_outflows_adt outflows;	/**< Datatype memory variable outflows of type firm_outflows_adt. */
	firm_inflows_adt inflows;	/**< Datatype memory variable inflows of type firm_inflows_adt. */
};

/** \struct firm_balance_sheet_adt_array
 * \brief Dynamic array to hold firm_balance_sheet_adts
 */
struct firm_balance_sheet_adt_array
{
	int size;
	int total_size;

	struct firm_balance_sheet_adt * array;
};

/** \var typedef firm_balance_sheet_adt firm_balance_sheet_adt
 * \brief Typedef for firm_balance_sheet_adt struct.
 */
typedef struct firm_balance_sheet_adt firm_balance_sheet_adt;
/** \var typedef firm_balance_sheet_adt_array firm_balance_sheet_adt_array
 * \brief Typedef for firm_balance_sheet_adt_array struct.
 */
typedef struct firm_balance_sheet_adt_array firm_balance_sheet_adt_array;
/** \struct household_balance_sheet_adt
 * \brief ADT containing the household balance sheet..
 *
 * ADT containing the household balance sheet..
 */
struct household_balance_sheet_adt
{
	household_stocks_adt stocks;	/**< Datatype memory variable stocks of type household_stocks_adt. */
	household_outflows_adt outflows;	/**< Datatype memory variable outflows of type household_outflows_adt. */
	household_inflows_adt inflows;	/**< Datatype memory variable inflows of type household_inflows_adt. */
};

/** \struct household_balance_sheet_adt_array
 * \brief Dynamic array to hold household_balance_sheet_adts
 */
struct household_balance_sheet_adt_array
{
	int size;
	int total_size;

	struct household_balance_sheet_adt * array;
};

/** \var typedef household_balance_sheet_adt household_balance_sheet_adt
 * \brief Typedef for household_balance_sheet_adt struct.
 */
typedef struct household_balance_sheet_adt household_balance_sheet_adt;
/** \var typedef household_balance_sheet_adt_array household_balance_sheet_adt_array
 * \brief Typedef for household_balance_sheet_adt_array struct.
 */
typedef struct household_balance_sheet_adt_array household_balance_sheet_adt_array;
/** \struct igfirm_balance_sheet_adt
 * \brief ADT containing the IGFirm balance sheet..
 *
 * ADT containing the IGFirm balance sheet..
 */
struct igfirm_balance_sheet_adt
{
	igfirm_stocks_adt stocks;	/**< Datatype memory variable stocks of type igfirm_stocks_adt. */
	igfirm_outflows_adt outflows;	/**< Datatype memory variable outflows of type igfirm_outflows_adt. */
	igfirm_inflows_adt inflows;	/**< Datatype memory variable inflows of type igfirm_inflows_adt. */
};

/** \struct igfirm_balance_sheet_adt_array
 * \brief Dynamic array to hold igfirm_balance_sheet_adts
 */
struct igfirm_balance_sheet_adt_array
{
	int size;
	int total_size;

	struct igfirm_balance_sheet_adt * array;
};

/** \var typedef igfirm_balance_sheet_adt igfirm_balance_sheet_adt
 * \brief Typedef for igfirm_balance_sheet_adt struct.
 */
typedef struct igfirm_balance_sheet_adt igfirm_balance_sheet_adt;
/** \var typedef igfirm_balance_sheet_adt_array igfirm_balance_sheet_adt_array
 * \brief Typedef for igfirm_balance_sheet_adt_array struct.
 */
typedef struct igfirm_balance_sheet_adt_array igfirm_balance_sheet_adt_array;
/** \struct bank_balance_sheet_adt
 * \brief ADT containing the bank balance sheet..
 *
 * ADT containing the bank balance sheet..
 */
struct bank_balance_sheet_adt
{
	bank_stocks_adt stocks;	/**< Datatype memory variable stocks of type bank_stocks_adt. */
	bank_outflows_adt outflows;	/**< Datatype memory variable outflows of type bank_outflows_adt. */
	bank_inflows_adt inflows;	/**< Datatype memory variable inflows of type bank_inflows_adt. */
};

/** \struct bank_balance_sheet_adt_array
 * \brief Dynamic array to hold bank_balance_sheet_adts
 */
struct bank_balance_sheet_adt_array
{
	int size;
	int total_size;

	struct bank_balance_sheet_adt * array;
};

/** \var typedef bank_balance_sheet_adt bank_balance_sheet_adt
 * \brief Typedef for bank_balance_sheet_adt struct.
 */
typedef struct bank_balance_sheet_adt bank_balance_sheet_adt;
/** \var typedef bank_balance_sheet_adt_array bank_balance_sheet_adt_array
 * \brief Typedef for bank_balance_sheet_adt_array struct.
 */
typedef struct bank_balance_sheet_adt_array bank_balance_sheet_adt_array;
/** \struct gov_balance_sheet_adt
 * \brief ADT containing the Government balance sheet..
 *
 * ADT containing the Government balance sheet..
 */
struct gov_balance_sheet_adt
{
	gov_stocks_adt stocks;	/**< Datatype memory variable stocks of type gov_stocks_adt. */
	gov_outflows_adt outflows;	/**< Datatype memory variable outflows of type gov_outflows_adt. */
	gov_inflows_adt inflows;	/**< Datatype memory variable inflows of type gov_inflows_adt. */
};

/** \struct gov_balance_sheet_adt_array
 * \brief Dynamic array to hold gov_balance_sheet_adts
 */
struct gov_balance_sheet_adt_array
{
	int size;
	int total_size;

	struct gov_balance_sheet_adt * array;
};

/** \var typedef gov_balance_sheet_adt gov_balance_sheet_adt
 * \brief Typedef for gov_balance_sheet_adt struct.
 */
typedef struct gov_balance_sheet_adt gov_balance_sheet_adt;
/** \var typedef gov_balance_sheet_adt_array gov_balance_sheet_adt_array
 * \brief Typedef for gov_balance_sheet_adt_array struct.
 */
typedef struct gov_balance_sheet_adt_array gov_balance_sheet_adt_array;
/** \struct ecb_balance_sheet_adt
 * \brief ADT containing the Central Bank balance sheet..
 *
 * ADT containing the Central Bank balance sheet..
 */
struct ecb_balance_sheet_adt
{
	ecb_stocks_adt stocks;	/**< Datatype memory variable stocks of type ecb_stocks_adt. */
	ecb_outflows_adt outflows;	/**< Datatype memory variable outflows of type ecb_outflows_adt. */
	ecb_inflows_adt inflows;	/**< Datatype memory variable inflows of type ecb_inflows_adt. */
};

/** \struct ecb_balance_sheet_adt_array
 * \brief Dynamic array to hold ecb_balance_sheet_adts
 */
struct ecb_balance_sheet_adt_array
{
	int size;
	int total_size;

	struct ecb_balance_sheet_adt * array;
};

/** \var typedef ecb_balance_sheet_adt ecb_balance_sheet_adt
 * \brief Typedef for ecb_balance_sheet_adt struct.
 */
typedef struct ecb_balance_sheet_adt ecb_balance_sheet_adt;
/** \var typedef ecb_balance_sheet_adt_array ecb_balance_sheet_adt_array
 * \brief Typedef for ecb_balance_sheet_adt_array struct.
 */
typedef struct ecb_balance_sheet_adt_array ecb_balance_sheet_adt_array;
/** \struct adt_subsidies_per_government
 * \brief ADT containing the subsidies paid per government.
 *
 * ADT containing the subsidies paid per government.
 */
struct adt_subsidies_per_government
{
	int gov_id;	/**< Datatype memory variable gov_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double amount;	/**< Datatype memory variable amount of type double. */
};

/** \struct adt_subsidies_per_government_array
 * \brief Dynamic array to hold adt_subsidies_per_governments
 */
struct adt_subsidies_per_government_array
{
	int size;
	int total_size;

	struct adt_subsidies_per_government * array;
};

/** \var typedef adt_subsidies_per_government adt_subsidies_per_government
 * \brief Typedef for adt_subsidies_per_government struct.
 */
typedef struct adt_subsidies_per_government adt_subsidies_per_government;
/** \var typedef adt_subsidies_per_government_array adt_subsidies_per_government_array
 * \brief Typedef for adt_subsidies_per_government_array struct.
 */
typedef struct adt_subsidies_per_government_array adt_subsidies_per_government_array;
/** \struct estimated_values_adt
 * \brief .
 *
 * .
 */
struct estimated_values_adt
{
	int no_positive_response;	/**< Datatype memory variable no_positive_response of type int. */
	double probability;	/**< Datatype memory variable probability of type double. */
	double estimated_fix_costs;	/**< Datatype memory variable estimated_fix_costs of type double. */
	double estimated_variable_costs;	/**< Datatype memory variable estimated_variable_costs of type double. */
	double estimated_earnings;	/**< Datatype memory variable estimated_earnings of type double. */
	double additional_capital_Investments_depreciated;	/**< Datatype memory variable additional_capital_Investments_depreciated of type double. */
	double mean_specific_skills;	/**< Datatype memory variable mean_specific_skills of type double. */
	double mean_wage;	/**< Datatype memory variable mean_wage of type double. */
	int no_employees;	/**< Datatype memory variable no_employees of type int. */
};

/** \struct estimated_values_adt_array
 * \brief Dynamic array to hold estimated_values_adts
 */
struct estimated_values_adt_array
{
	int size;
	int total_size;

	struct estimated_values_adt * array;
};

/** \var typedef estimated_values_adt estimated_values_adt
 * \brief Typedef for estimated_values_adt struct.
 */
typedef struct estimated_values_adt estimated_values_adt;
/** \var typedef estimated_values_adt_array estimated_values_adt_array
 * \brief Typedef for estimated_values_adt_array struct.
 */
typedef struct estimated_values_adt_array estimated_values_adt_array;
/** \struct dt_market_research_price
 * \brief .
 *
 * .
 */
struct dt_market_research_price
{
	double price_change;	/**< Datatype memory variable price_change of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	estimated_values_adt_array estimated_values;	/**< Datatype memory variable estimated_values of type estimated_values_adt_array. */
};

/** \struct dt_market_research_price_array
 * \brief Dynamic array to hold dt_market_research_prices
 */
struct dt_market_research_price_array
{
	int size;
	int total_size;

	struct dt_market_research_price * array;
};

/** \var typedef dt_market_research_price dt_market_research_price
 * \brief Typedef for dt_market_research_price struct.
 */
typedef struct dt_market_research_price dt_market_research_price;
/** \var typedef dt_market_research_price_array dt_market_research_price_array
 * \brief Typedef for dt_market_research_price_array struct.
 */
typedef struct dt_market_research_price_array dt_market_research_price_array;
/** \struct dt_market_research_qualities
 * \brief .
 *
 * .
 */
struct dt_market_research_qualities
{
	double quality;	/**< Datatype memory variable quality of type double. */
	dt_market_research_price_array market_research_price;	/**< Datatype memory variable market_research_price of type dt_market_research_price_array. */
};

/** \struct dt_market_research_qualities_array
 * \brief Dynamic array to hold dt_market_research_qualitiess
 */
struct dt_market_research_qualities_array
{
	int size;
	int total_size;

	struct dt_market_research_qualities * array;
};

/** \var typedef dt_market_research_qualities dt_market_research_qualities
 * \brief Typedef for dt_market_research_qualities struct.
 */
typedef struct dt_market_research_qualities dt_market_research_qualities;
/** \var typedef dt_market_research_qualities_array dt_market_research_qualities_array
 * \brief Typedef for dt_market_research_qualities_array struct.
 */
typedef struct dt_market_research_qualities_array dt_market_research_qualities_array;
/** \struct dt_best_price_strategies
 * \brief .
 *
 * .
 */
struct dt_best_price_strategies
{
	double quality;	/**< Datatype memory variable quality of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double expected_earnings;	/**< Datatype memory variable expected_earnings of type double. */
	double sum_earnings;	/**< Datatype memory variable sum_earnings of type double. */
	double sum_expected_earnings_discounted;	/**< Datatype memory variable sum_expected_earnings_discounted of type double. */
};

/** \struct dt_best_price_strategies_array
 * \brief Dynamic array to hold dt_best_price_strategiess
 */
struct dt_best_price_strategies_array
{
	int size;
	int total_size;

	struct dt_best_price_strategies * array;
};

/** \var typedef dt_best_price_strategies dt_best_price_strategies
 * \brief Typedef for dt_best_price_strategies struct.
 */
typedef struct dt_best_price_strategies dt_best_price_strategies;
/** \var typedef dt_best_price_strategies_array dt_best_price_strategies_array
 * \brief Typedef for dt_best_price_strategies_array struct.
 */
typedef struct dt_best_price_strategies_array dt_best_price_strategies_array;
/** \struct dt_price_range
 * \brief .
 *
 * .
 */
struct dt_price_range
{
	double start_price;	/**< Datatype memory variable start_price of type double. */
	double end_price;	/**< Datatype memory variable end_price of type double. */
	double increment;	/**< Datatype memory variable increment of type double. */
};

/** \struct dt_price_range_array
 * \brief Dynamic array to hold dt_price_ranges
 */
struct dt_price_range_array
{
	int size;
	int total_size;

	struct dt_price_range * array;
};

/** \var typedef dt_price_range dt_price_range
 * \brief Typedef for dt_price_range struct.
 */
typedef struct dt_price_range dt_price_range;
/** \var typedef dt_price_range_array dt_price_range_array
 * \brief Typedef for dt_price_range_array struct.
 */
typedef struct dt_price_range_array dt_price_range_array;
/** \struct dt_prospective_variables
 * \brief .
 *
 * .
 */
struct dt_prospective_variables
{
	double mean_specific_skills;	/**< Datatype memory variable mean_specific_skills of type double. */
	double estimated_mean_wage;	/**< Datatype memory variable estimated_mean_wage of type double. */
	double no_employees;	/**< Datatype memory variable no_employees of type double. */
	double earnings;	/**< Datatype memory variable earnings of type double. */
	double payment_account;	/**< Datatype memory variable payment_account of type double. */
	double buffer;	/**< Datatype memory variable buffer of type double. */
	adt_capital_stock_vintages_array capital_stock_vintages;	/**< Datatype memory variable capital_stock_vintages of type adt_capital_stock_vintages_array. */
	financing_capital_array capital_financing;	/**< Datatype memory variable capital_financing of type financing_capital_array. */
	debt_item_array loans;	/**< Datatype memory variable loans of type debt_item_array. */
};

/** \struct dt_prospective_variables_array
 * \brief Dynamic array to hold dt_prospective_variabless
 */
struct dt_prospective_variables_array
{
	int size;
	int total_size;

	struct dt_prospective_variables * array;
};

/** \var typedef dt_prospective_variables dt_prospective_variables
 * \brief Typedef for dt_prospective_variables struct.
 */
typedef struct dt_prospective_variables dt_prospective_variables;
/** \var typedef dt_prospective_variables_array dt_prospective_variables_array
 * \brief Typedef for dt_prospective_variables_array struct.
 */
typedef struct dt_prospective_variables_array dt_prospective_variables_array;
/** \struct dt_variables_changed
 * \brief .
 *
 * .
 */
struct dt_variables_changed
{
	double price_index;	/**< Datatype memory variable price_index of type double. */
	double quality_index;	/**< Datatype memory variable quality_index of type double. */
	double productivity_progress;	/**< Datatype memory variable productivity_progress of type double. */
};

/** \struct dt_variables_changed_array
 * \brief Dynamic array to hold dt_variables_changeds
 */
struct dt_variables_changed_array
{
	int size;
	int total_size;

	struct dt_variables_changed * array;
};

/** \var typedef dt_variables_changed dt_variables_changed
 * \brief Typedef for dt_variables_changed struct.
 */
typedef struct dt_variables_changed dt_variables_changed;
/** \var typedef dt_variables_changed_array dt_variables_changed_array
 * \brief Typedef for dt_variables_changed_array struct.
 */
typedef struct dt_variables_changed_array dt_variables_changed_array;
/** \struct dt_innovation_choice
 * \brief .
 *
 * .
 */
struct dt_innovation_choice
{
	int development_period;	/**< Datatype memory variable development_period of type int. */
	int employees_needed;	/**< Datatype memory variable employees_needed of type int. */
	double quality;	/**< Datatype memory variable quality of type double. */
	double expected_discounted_earnings;	/**< Datatype memory variable expected_discounted_earnings of type double. */
};

/** \struct dt_innovation_choice_array
 * \brief Dynamic array to hold dt_innovation_choices
 */
struct dt_innovation_choice_array
{
	int size;
	int total_size;

	struct dt_innovation_choice * array;
};

/** \var typedef dt_innovation_choice dt_innovation_choice
 * \brief Typedef for dt_innovation_choice struct.
 */
typedef struct dt_innovation_choice dt_innovation_choice;
/** \var typedef dt_innovation_choice_array dt_innovation_choice_array
 * \brief Typedef for dt_innovation_choice_array struct.
 */
typedef struct dt_innovation_choice_array dt_innovation_choice_array;
/** \struct dt_demand_function
 * \brief .
 *
 * .
 */
struct dt_demand_function
{
	double quality;	/**< Datatype memory variable quality of type double. */
	int year;	/**< Datatype memory variable year of type int. */
	double factor;	/**< Datatype memory variable factor of type double. */
	double exponent;	/**< Datatype memory variable exponent of type double. */
	double variance;	/**< Datatype memory variable variance of type double. */
};

/** \struct dt_demand_function_array
 * \brief Dynamic array to hold dt_demand_functions
 */
struct dt_demand_function_array
{
	int size;
	int total_size;

	struct dt_demand_function * array;
};

/** \var typedef dt_demand_function dt_demand_function
 * \brief Typedef for dt_demand_function struct.
 */
typedef struct dt_demand_function dt_demand_function;
/** \var typedef dt_demand_function_array dt_demand_function_array
 * \brief Typedef for dt_demand_function_array struct.
 */
typedef struct dt_demand_function_array dt_demand_function_array;
/** \struct dt_price_quantity_touple
 * \brief .
 *
 * .
 */
struct dt_price_quantity_touple
{
	double price;	/**< Datatype memory variable price of type double. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
};

/** \struct dt_price_quantity_touple_array
 * \brief Dynamic array to hold dt_price_quantity_touples
 */
struct dt_price_quantity_touple_array
{
	int size;
	int total_size;

	struct dt_price_quantity_touple * array;
};

/** \var typedef dt_price_quantity_touple dt_price_quantity_touple
 * \brief Typedef for dt_price_quantity_touple struct.
 */
typedef struct dt_price_quantity_touple dt_price_quantity_touple;
/** \var typedef dt_price_quantity_touple_array dt_price_quantity_touple_array
 * \brief Typedef for dt_price_quantity_touple_array struct.
 */
typedef struct dt_price_quantity_touple_array dt_price_quantity_touple_array;
/** \struct dt_market_size
 * \brief Used for storing the total market size in one of the previous period..
 *
 * Used for storing the total market size in one of the previous period..
 */
struct dt_market_size
{
	int period;	/**< Datatype memory variable period of type int. */
	double market_size;	/**< Datatype memory variable market_size of type double. */
};

/** \struct dt_market_size_array
 * \brief Dynamic array to hold dt_market_sizes
 */
struct dt_market_size_array
{
	int size;
	int total_size;

	struct dt_market_size * array;
};

/** \var typedef dt_market_size dt_market_size
 * \brief Typedef for dt_market_size struct.
 */
typedef struct dt_market_size dt_market_size;
/** \var typedef dt_market_size_array dt_market_size_array
 * \brief Typedef for dt_market_size_array struct.
 */
typedef struct dt_market_size_array dt_market_size_array;
/** \struct dt_total_and_regional_market_size
 * \brief Used for storing the total market size in one of the previous period..
 *
 * Used for storing the total market size in one of the previous period..
 */
struct dt_total_and_regional_market_size
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	dt_market_size_array market_sizes;	/**< Datatype memory variable market_sizes of type dt_market_size_array. */
};

/** \struct dt_total_and_regional_market_size_array
 * \brief Dynamic array to hold dt_total_and_regional_market_sizes
 */
struct dt_total_and_regional_market_size_array
{
	int size;
	int total_size;

	struct dt_total_and_regional_market_size * array;
};

/** \var typedef dt_total_and_regional_market_size dt_total_and_regional_market_size
 * \brief Typedef for dt_total_and_regional_market_size struct.
 */
typedef struct dt_total_and_regional_market_size dt_total_and_regional_market_size;
/** \var typedef dt_total_and_regional_market_size_array dt_total_and_regional_market_size_array
 * \brief Typedef for dt_total_and_regional_market_size_array struct.
 */
typedef struct dt_total_and_regional_market_size_array dt_total_and_regional_market_size_array;
/** \struct dt_value_lattice
 * \brief Used for storing the total market size in one of the previous period..
 *
 * Used for storing the total market size in one of the previous period..
 */
struct dt_value_lattice
{
	double intermediate_quality;	/**< Datatype memory variable intermediate_quality of type double. */
	double value;	/**< Datatype memory variable value of type double. */
	int strategy;	/**< Datatype memory variable strategy of type int. */
};

/** \struct dt_value_lattice_array
 * \brief Dynamic array to hold dt_value_lattices
 */
struct dt_value_lattice_array
{
	int size;
	int total_size;

	struct dt_value_lattice * array;
};

/** \var typedef dt_value_lattice dt_value_lattice
 * \brief Typedef for dt_value_lattice struct.
 */
typedef struct dt_value_lattice dt_value_lattice;
/** \var typedef dt_value_lattice_array dt_value_lattice_array
 * \brief Typedef for dt_value_lattice_array struct.
 */
typedef struct dt_value_lattice_array dt_value_lattice_array;
/** \struct dt_value_lattice_years
 * \brief Used for storing the total market size in one of the previous period..
 *
 * Used for storing the total market size in one of the previous period..
 */
struct dt_value_lattice_years
{
	int year;	/**< Datatype memory variable year of type int. */
	dt_value_lattice_array values;	/**< Datatype memory variable values of type dt_value_lattice_array. */
};

/** \struct dt_value_lattice_years_array
 * \brief Dynamic array to hold dt_value_lattice_yearss
 */
struct dt_value_lattice_years_array
{
	int size;
	int total_size;

	struct dt_value_lattice_years * array;
};

/** \var typedef dt_value_lattice_years dt_value_lattice_years
 * \brief Typedef for dt_value_lattice_years struct.
 */
typedef struct dt_value_lattice_years dt_value_lattice_years;
/** \var typedef dt_value_lattice_years_array dt_value_lattice_years_array
 * \brief Typedef for dt_value_lattice_years_array struct.
 */
typedef struct dt_value_lattice_years_array dt_value_lattice_years_array;
/** \struct dt_monthly_estimations
 * \brief Used for storing the monthly estimations for earnings, labor costs, capital costs and interest payments.
 *
 * Used for storing the monthly estimations for earnings, labor costs, capital costs and interest payments.
 */
struct dt_monthly_estimations
{
	double output;	/**< Datatype memory variable output of type double. */
	double earnings;	/**< Datatype memory variable earnings of type double. */
	double sold_quantity;	/**< Datatype memory variable sold_quantity of type double. */
	double labor_costs;	/**< Datatype memory variable labor_costs of type double. */
	double capital_costs;	/**< Datatype memory variable capital_costs of type double. */
	double interest_payments;	/**< Datatype memory variable interest_payments of type double. */
	double wage;	/**< Datatype memory variable wage of type double. */
	double mean_specific_skills;	/**< Datatype memory variable mean_specific_skills of type double. */
	double average_productivity;	/**< Datatype memory variable average_productivity of type double. */
	double investment_nominal;	/**< Datatype memory variable investment_nominal of type double. */
};

/** \struct dt_monthly_estimations_array
 * \brief Dynamic array to hold dt_monthly_estimationss
 */
struct dt_monthly_estimations_array
{
	int size;
	int total_size;

	struct dt_monthly_estimations * array;
};

/** \var typedef dt_monthly_estimations dt_monthly_estimations
 * \brief Typedef for dt_monthly_estimations struct.
 */
typedef struct dt_monthly_estimations dt_monthly_estimations;
/** \var typedef dt_monthly_estimations_array dt_monthly_estimations_array
 * \brief Typedef for dt_monthly_estimations_array struct.
 */
typedef struct dt_monthly_estimations_array dt_monthly_estimations_array;

/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int last_day_of_month_to_act;	/**< X-machine memory variable last_day_of_month_to_act of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	double payment_account_balance_sheet;	/**< X-machine memory variable payment_account_balance_sheet of type double. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	double cpi;	/**< X-machine memory variable cpi of type double. */
	double mean_wage;	/**< X-machine memory variable mean_wage of type double. */
	double total_mean_wage;	/**< X-machine memory variable total_mean_wage of type double. */
	double mean_wage_r_and_d;	/**< X-machine memory variable mean_wage_r_and_d of type double. */
	double needed_capital_stock;	/**< X-machine memory variable needed_capital_stock of type double. */
	double stock;	/**< X-machine memory variable stock of type double. */
	double critical_stock;	/**< X-machine memory variable critical_stock of type double. */
	double actual_cap_price;	/**< X-machine memory variable actual_cap_price of type double. */
	double mean_specific_skills;	/**< X-machine memory variable mean_specific_skills of type double. */
	double planned_production_quantity;	/**< X-machine memory variable planned_production_quantity of type double. */
	double production_quantity;	/**< X-machine memory variable production_quantity of type double. */
	double planned_output;	/**< X-machine memory variable planned_output of type double. */
	double output;	/**< X-machine memory variable output of type double. */
	double unit_costs;	/**< X-machine memory variable unit_costs of type double. */
	double total_supply;	/**< X-machine memory variable total_supply of type double. */
	double production_costs;	/**< X-machine memory variable production_costs of type double. */
	double total_buffer;	/**< X-machine memory variable total_buffer of type double. */
	double revenue_per_day;	/**< X-machine memory variable revenue_per_day of type double. */
	estimators_linear_regression_array linear_regression_estimators;	/**< X-machine memory variable linear_regression_estimators of type estimators_linear_regression_array. */
	double technological_frontier;	/**< X-machine memory variable technological_frontier of type double. */
	adt_technology_vintages_array technology_vintages;	/**< X-machine memory variable technology_vintages of type adt_technology_vintages_array. */
	int vintage_selected;	/**< X-machine memory variable vintage_selected of type int. */
	int investment_subsidy_type;	/**< X-machine memory variable investment_subsidy_type of type int. */
	double initial_market_size;	/**< X-machine memory variable initial_market_size of type double. */
	double initial_technology;	/**< X-machine memory variable initial_technology of type double. */
	double utilization_capacity;	/**< X-machine memory variable utilization_capacity of type double. */
	double used_capital_units;	/**< X-machine memory variable used_capital_units of type double. */
	double cum_revenue;	/**< X-machine memory variable cum_revenue of type double. */
	sales_statistics_array malls_sales_statistics;	/**< X-machine memory variable malls_sales_statistics of type sales_statistics_array. */
	double quality;	/**< X-machine memory variable quality of type double. */
	double price;	/**< X-machine memory variable price of type double. */
	double price_last_month;	/**< X-machine memory variable price_last_month of type double. */
	double actual_mark_up;	/**< X-machine memory variable actual_mark_up of type double. */
	double demand_capital_stock;	/**< X-machine memory variable demand_capital_stock of type double. */
	double effective_investments;	/**< X-machine memory variable effective_investments of type double. */
	double effective_capital_stock;	/**< X-machine memory variable effective_capital_stock of type double. */
	double planned_production_costs;	/**< X-machine memory variable planned_production_costs of type double. */
	double labour_costs_production;	/**< X-machine memory variable labour_costs_production of type double. */
	double labour_costs_innovation;	/**< X-machine memory variable labour_costs_innovation of type double. */
	double intermediate_quality_level_developing;	/**< X-machine memory variable intermediate_quality_level_developing of type double. */
	double adaption_production_volume_due_to_insufficient_finances;	/**< X-machine memory variable adaption_production_volume_due_to_insufficient_finances of type double. */
	sold_quantities_per_mall_array sold_quantities;	/**< X-machine memory variable sold_quantities of type sold_quantities_per_mall_array. */
	double total_sold_quantity;	/**< X-machine memory variable total_sold_quantity of type double. */
	double cum_total_sold_quantity;	/**< X-machine memory variable cum_total_sold_quantity of type double. */
	double sold_quantity_in_calendar_month;	/**< X-machine memory variable sold_quantity_in_calendar_month of type double. */
	delivery_volume_per_mall_array delivery_volume;	/**< X-machine memory variable delivery_volume of type delivery_volume_per_mall_array. */
	delivery_volume_per_mall_array planned_delivery_volume;	/**< X-machine memory variable planned_delivery_volume of type delivery_volume_per_mall_array. */
	mall_info_array current_mall_stocks;	/**< X-machine memory variable current_mall_stocks of type mall_info_array. */
	double_array last_planned_production_quantities;	/**< X-machine memory variable last_planned_production_quantities of type double_array. */
	double total_external_financing_obtained;	/**< X-machine memory variable total_external_financing_obtained of type double. */
	double capital_costs;	/**< X-machine memory variable capital_costs of type double. */
	int employees_needed_production;	/**< X-machine memory variable employees_needed_production of type int. */
	int no_employees_production;	/**< X-machine memory variable no_employees_production of type int. */
	double planned_innovation_expenditures;	/**< X-machine memory variable planned_innovation_expenditures of type double. */
	double planned_expenditures_production_innovation;	/**< X-machine memory variable planned_expenditures_production_innovation of type double. */
	double labour_costs;	/**< X-machine memory variable labour_costs of type double. */
	double labour_costs_per_unit;	/**< X-machine memory variable labour_costs_per_unit of type double. */
	adt_capital_stock_vintages_array capital_stock_vintages;	/**< X-machine memory variable capital_stock_vintages of type adt_capital_stock_vintages_array. */
	int vintage_choice_taken;	/**< X-machine memory variable vintage_choice_taken of type int. */
	financing_capital_array capital_financing;	/**< X-machine memory variable capital_financing of type financing_capital_array. */
	double financial_resources_for_production;	/**< X-machine memory variable financial_resources_for_production of type double. */
	double total_units_local_inventory;	/**< X-machine memory variable total_units_local_inventory of type double. */
	double calc_capital_costs;	/**< X-machine memory variable calc_capital_costs of type double. */
	double calc_production_costs;	/**< X-machine memory variable calc_production_costs of type double. */
	double firm_productivity;	/**< X-machine memory variable firm_productivity of type double. */
	double total_productivity_capital_stock;	/**< X-machine memory variable total_productivity_capital_stock of type double. */
	double firm_productivity_last_year;	/**< X-machine memory variable firm_productivity_last_year of type double. */
	double firm_productivity_progress;	/**< X-machine memory variable firm_productivity_progress of type double. */
	double sold_quantity_in_last_calendar_month;	/**< X-machine memory variable sold_quantity_in_last_calendar_month of type double. */
	double_array last_sold_quantities;	/**< X-machine memory variable last_sold_quantities of type double_array. */
	double_array last_revenues;	/**< X-machine memory variable last_revenues of type double_array. */
	int_array set_of_lenders;	/**< X-machine memory variable set_of_lenders of type int_array. */
	int_array potential_lenders;	/**< X-machine memory variable potential_lenders of type int_array. */
	int number_of_banks_asked;	/**< X-machine memory variable number_of_banks_asked of type int. */
	double received_interest_daily;	/**< X-machine memory variable received_interest_daily of type double. */
	double received_interest_in_calendar_month;	/**< X-machine memory variable received_interest_in_calendar_month of type double. */
	int flag_illiquidity_correction;	/**< X-machine memory variable flag_illiquidity_correction of type int. */
	double ebit;	/**< X-machine memory variable ebit of type double. */
	double earnings;	/**< X-machine memory variable earnings of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double tax_payment;	/**< X-machine memory variable tax_payment of type double. */
	double tax_payment_in_calendar_month;	/**< X-machine memory variable tax_payment_in_calendar_month of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double_array earnings_history;	/**< X-machine memory variable earnings_history of type double_array. */
	double previous_net_earnings;	/**< X-machine memory variable previous_net_earnings of type double. */
	double total_interest_payment;	/**< X-machine memory variable total_interest_payment of type double. */
	double total_interest_payment_in_calendar_month;	/**< X-machine memory variable total_interest_payment_in_calendar_month of type double. */
	double total_debt_installment_payment;	/**< X-machine memory variable total_debt_installment_payment of type double. */
	double total_debt_installment_payment_in_calendar_month;	/**< X-machine memory variable total_debt_installment_payment_in_calendar_month of type double. */
	double total_dividend_payment;	/**< X-machine memory variable total_dividend_payment of type double. */
	double total_dividend_payment_in_calendar_month;	/**< X-machine memory variable total_dividend_payment_in_calendar_month of type double. */
	int flag_full_dividend;	/**< X-machine memory variable flag_full_dividend of type int. */
	double current_share_price;	/**< X-machine memory variable current_share_price of type double. */
	double previous_dividend_per_share;	/**< X-machine memory variable previous_dividend_per_share of type double. */
	double current_dividend_per_share;	/**< X-machine memory variable current_dividend_per_share of type double. */
	double previous_earnings_per_share;	/**< X-machine memory variable previous_earnings_per_share of type double. */
	double current_earnings_per_share;	/**< X-machine memory variable current_earnings_per_share of type double. */
	double previous_dividend_per_earnings;	/**< X-machine memory variable previous_dividend_per_earnings of type double. */
	double current_dividend_per_earnings;	/**< X-machine memory variable current_dividend_per_earnings of type double. */
	double debt_earnings_ratio;	/**< X-machine memory variable debt_earnings_ratio of type double. */
	double debt_equity_ratio;	/**< X-machine memory variable debt_equity_ratio of type double. */
	double price_earnings_ratio;	/**< X-machine memory variable price_earnings_ratio of type double. */
	double retained_earnings_ratio;	/**< X-machine memory variable retained_earnings_ratio of type double. */
	double earnings_per_share_ratio_growth;	/**< X-machine memory variable earnings_per_share_ratio_growth of type double. */
	double critical_price_earnings_ratio;	/**< X-machine memory variable critical_price_earnings_ratio of type double. */
	double critical_earnings_per_share_ratio;	/**< X-machine memory variable critical_earnings_per_share_ratio of type double. */
	debt_item_array loans;	/**< X-machine memory variable loans of type debt_item_array. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double target_debt;	/**< X-machine memory variable target_debt of type double. */
	double total_debt_balance_sheet;	/**< X-machine memory variable total_debt_balance_sheet of type double. */
	double total_value_local_inventory;	/**< X-machine memory variable total_value_local_inventory of type double. */
	double total_value_local_inventory_balance_sheet;	/**< X-machine memory variable total_value_local_inventory_balance_sheet of type double. */
	double total_units_capital_stock;	/**< X-machine memory variable total_units_capital_stock of type double. */
	double total_value_capital_stock;	/**< X-machine memory variable total_value_capital_stock of type double. */
	double total_value_capital_stock_balance_sheet;	/**< X-machine memory variable total_value_capital_stock_balance_sheet of type double. */
	double total_capital_depreciation_value;	/**< X-machine memory variable total_capital_depreciation_value of type double. */
	double total_capital_depreciation_units;	/**< X-machine memory variable total_capital_depreciation_units of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double equity_balance_sheet;	/**< X-machine memory variable equity_balance_sheet of type double. */
	double production_liquidity_needs;	/**< X-machine memory variable production_liquidity_needs of type double. */
	double financial_liquidity_needs;	/**< X-machine memory variable financial_liquidity_needs of type double. */
	double total_financial_needs;	/**< X-machine memory variable total_financial_needs of type double. */
	double external_financial_needs;	/**< X-machine memory variable external_financial_needs of type double. */
	double earnings_per_share;	/**< X-machine memory variable earnings_per_share of type double. */
	double retained_earnings;	/**< X-machine memory variable retained_earnings of type double. */
	double total_payments;	/**< X-machine memory variable total_payments of type double. */
	int previous_shares_outstanding;	/**< X-machine memory variable previous_shares_outstanding of type int. */
	int minsky_state;	/**< X-machine memory variable minsky_state of type int. */
	int minsky_state_1;	/**< X-machine memory variable minsky_state_1 of type int. */
	int minsky_state_2;	/**< X-machine memory variable minsky_state_2 of type int. */
	int minsky_state_3;	/**< X-machine memory variable minsky_state_3 of type int. */
	int minsky_state_4;	/**< X-machine memory variable minsky_state_4 of type int. */
	int minsky_state_5;	/**< X-machine memory variable minsky_state_5 of type int. */
	int minsky_state_20;	/**< X-machine memory variable minsky_state_20 of type int. */
	int minsky_state_21;	/**< X-machine memory variable minsky_state_21 of type int. */
	int minsky_state_22;	/**< X-machine memory variable minsky_state_22 of type int. */
	int minsky_state_23;	/**< X-machine memory variable minsky_state_23 of type int. */
	int minsky_state_30;	/**< X-machine memory variable minsky_state_30 of type int. */
	int minsky_state_31;	/**< X-machine memory variable minsky_state_31 of type int. */
	int minsky_state_32;	/**< X-machine memory variable minsky_state_32 of type int. */
	int minsky_state_33;	/**< X-machine memory variable minsky_state_33 of type int. */
	int minsky_state_40;	/**< X-machine memory variable minsky_state_40 of type int. */
	int minsky_state_41;	/**< X-machine memory variable minsky_state_41 of type int. */
	int minsky_state_42;	/**< X-machine memory variable minsky_state_42 of type int. */
	int minsky_state_43;	/**< X-machine memory variable minsky_state_43 of type int. */
	int age_at_bankruptcy;	/**< X-machine memory variable age_at_bankruptcy of type int. */
	double debt_at_bankruptcy;	/**< X-machine memory variable debt_at_bankruptcy of type double. */
	double equity_at_bankruptcy;	/**< X-machine memory variable equity_at_bankruptcy of type double. */
	int no_employees_at_bankruptcy;	/**< X-machine memory variable no_employees_at_bankruptcy of type int. */
	double equity_asset_ratio;	/**< X-machine memory variable equity_asset_ratio of type double. */
	double profit_asset_ratio;	/**< X-machine memory variable profit_asset_ratio of type double. */
	double sales_asset_ratio;	/**< X-machine memory variable sales_asset_ratio of type double. */
	double investment_asset_ratio;	/**< X-machine memory variable investment_asset_ratio of type double. */
	double total_income;	/**< X-machine memory variable total_income of type double. */
	double total_liabilities;	/**< X-machine memory variable total_liabilities of type double. */
	double total_expenses;	/**< X-machine memory variable total_expenses of type double. */
	int current_shares_outstanding;	/**< X-machine memory variable current_shares_outstanding of type int. */
	employee_array employees;	/**< X-machine memory variable employees of type employee_array. */
	employee_array r_and_d_employees;	/**< X-machine memory variable r_and_d_employees of type employee_array. */
	double wage_offer;	/**< X-machine memory variable wage_offer of type double. */
	double technology;	/**< X-machine memory variable technology of type double. */
	int no_employees;	/**< X-machine memory variable no_employees of type int. */
	int no_employees_skill_1;	/**< X-machine memory variable no_employees_skill_1 of type int. */
	int no_employees_skill_2;	/**< X-machine memory variable no_employees_skill_2 of type int. */
	int no_employees_skill_3;	/**< X-machine memory variable no_employees_skill_3 of type int. */
	int no_employees_skill_4;	/**< X-machine memory variable no_employees_skill_4 of type int. */
	int no_employees_skill_5;	/**< X-machine memory variable no_employees_skill_5 of type int. */
	int no_employees_subsidized;	/**< X-machine memory variable no_employees_subsidized of type int. */
	double fraction_employees_subsidized;	/**< X-machine memory variable fraction_employees_subsidized of type double. */
	int vacancies;	/**< X-machine memory variable vacancies of type int. */
	int no_redundancies;	/**< X-machine memory variable no_redundancies of type int. */
	int no_applications_round_1;	/**< X-machine memory variable no_applications_round_1 of type int. */
	int no_applications_round_2;	/**< X-machine memory variable no_applications_round_2 of type int. */
	int no_redundancies_r_and_d_employees;	/**< X-machine memory variable no_redundancies_r_and_d_employees of type int. */
	int vacancies_r_and_d_employees;	/**< X-machine memory variable vacancies_r_and_d_employees of type int. */
	int posted_vacancies;	/**< X-machine memory variable posted_vacancies of type int. */
	int posted_vacancies_r_and_d_employees;	/**< X-machine memory variable posted_vacancies_r_and_d_employees of type int. */
	double average_g_skill;	/**< X-machine memory variable average_g_skill of type double. */
	double average_adaptation_speed_specific_skills;	/**< X-machine memory variable average_adaptation_speed_specific_skills of type double. */
	adt_list_adaptation_speed_array list_adaptation_speed_per_skill_group;	/**< X-machine memory variable list_adaptation_speed_per_skill_group of type adt_list_adaptation_speed_array. */
	double average_s_skill_of_1;	/**< X-machine memory variable average_s_skill_of_1 of type double. */
	double average_s_skill_of_2;	/**< X-machine memory variable average_s_skill_of_2 of type double. */
	double average_s_skill_of_3;	/**< X-machine memory variable average_s_skill_of_3 of type double. */
	double average_s_skill_of_4;	/**< X-machine memory variable average_s_skill_of_4 of type double. */
	double average_s_skill_of_5;	/**< X-machine memory variable average_s_skill_of_5 of type double. */
	double wage_offer_for_skill_1;	/**< X-machine memory variable wage_offer_for_skill_1 of type double. */
	double wage_offer_for_skill_2;	/**< X-machine memory variable wage_offer_for_skill_2 of type double. */
	double wage_offer_for_skill_3;	/**< X-machine memory variable wage_offer_for_skill_3 of type double. */
	double wage_offer_for_skill_4;	/**< X-machine memory variable wage_offer_for_skill_4 of type double. */
	double wage_offer_for_skill_5;	/**< X-machine memory variable wage_offer_for_skill_5 of type double. */
	double wage_offer_for_r_and_d_employees;	/**< X-machine memory variable wage_offer_for_r_and_d_employees of type double. */
	double base_wage_offer_r_and_d;	/**< X-machine memory variable base_wage_offer_r_and_d of type double. */
	int employees_needed;	/**< X-machine memory variable employees_needed of type int. */
	firm_balance_sheet_adt firm_balance_sheet_calendar;	/**< X-machine memory variable firm_balance_sheet_calendar of type firm_balance_sheet_adt. */
	firm_stocks_adt firm_stocks_calendar;	/**< X-machine memory variable firm_stocks_calendar of type firm_stocks_adt. */
	firm_outflows_adt firm_outflows_calendar;	/**< X-machine memory variable firm_outflows_calendar of type firm_outflows_adt. */
	firm_inflows_adt firm_inflows_calendar;	/**< X-machine memory variable firm_inflows_calendar of type firm_inflows_adt. */
	int age;	/**< X-machine memory variable age of type int. */
	double transfer_payment;	/**< X-machine memory variable transfer_payment of type double. */
	double subsidy_pct;	/**< X-machine memory variable subsidy_pct of type double. */
	int active;	/**< X-machine memory variable active of type int. */
	int inactive;	/**< X-machine memory variable inactive of type int. */
	int zero_output;	/**< X-machine memory variable zero_output of type int. */
	int bankruptcy_idle_counter;	/**< X-machine memory variable bankruptcy_idle_counter of type int. */
	int bankruptcy_state;	/**< X-machine memory variable bankruptcy_state of type int. */
	int bankruptcy_insolvency_state;	/**< X-machine memory variable bankruptcy_insolvency_state of type int. */
	int bankruptcy_illiquidity_state;	/**< X-machine memory variable bankruptcy_illiquidity_state of type int. */
	int financial_crisis_state;	/**< X-machine memory variable financial_crisis_state of type int. */
	double vacancy_filling_rate;	/**< X-machine memory variable vacancy_filling_rate of type double. */
	double average_s_skill_from_eurostat;	/**< X-machine memory variable average_s_skill_from_eurostat of type double. */
	double average_technology_from_eurostat;	/**< X-machine memory variable average_technology_from_eurostat of type double. */
	double average_wage_offer_from_eurostat;	/**< X-machine memory variable average_wage_offer_from_eurostat of type double. */
	double average_output_from_eurostat;	/**< X-machine memory variable average_output_from_eurostat of type double. */
	price_quality_pair_array quality_price_competitors;	/**< X-machine memory variable quality_price_competitors of type price_quality_pair_array. */
	double subsidy_payment;	/**< X-machine memory variable subsidy_payment of type double. */
	double current_price_index;	/**< X-machine memory variable current_price_index of type double. */
	double current_quality_index;	/**< X-machine memory variable current_quality_index of type double. */
	double minimum_wage;	/**< X-machine memory variable minimum_wage of type double. */
	int no_competitors;	/**< X-machine memory variable no_competitors of type int. */
	int indicator_earnings;	/**< X-machine memory variable indicator_earnings of type int. */
	int indicator_capital_costs;	/**< X-machine memory variable indicator_capital_costs of type int. */
	double agg_vacancy_filling_rate;	/**< X-machine memory variable agg_vacancy_filling_rate of type double. */
	int market_research_sample_size;	/**< X-machine memory variable market_research_sample_size of type int. */
	int product_innovation;	/**< X-machine memory variable product_innovation of type int. */
	int regional_analysis;	/**< X-machine memory variable regional_analysis of type int. */
	int day_of_year_market_research;	/**< X-machine memory variable day_of_year_market_research of type int. */
	int day_of_month_price_was_set;	/**< X-machine memory variable day_of_month_price_was_set of type int. */
	int actual_sample_size;	/**< X-machine memory variable actual_sample_size of type int. */
	dt_total_and_regional_market_size_array last_market_sizes;	/**< X-machine memory variable last_market_sizes of type dt_total_and_regional_market_size_array. */
	dt_price_range price_range_pricing;	/**< X-machine memory variable price_range_pricing of type dt_price_range. */
	double estimated_variance_market_share;	/**< X-machine memory variable estimated_variance_market_share of type double. */
	price_quality_pair estimated_coefficients;	/**< X-machine memory variable estimated_coefficients of type price_quality_pair. */
	dt_price_range price_range_innovation;	/**< X-machine memory variable price_range_innovation of type dt_price_range. */
	int price_quality_counts[12];	/**< X-machine memory variable price_quality_counts of type int. */
	price_quality_pair price_quality_inno[12];	/**< X-machine memory variable price_quality_inno of type price_quality_pair. */
	int new_product_released;	/**< X-machine memory variable new_product_released of type int. */
	dt_prospective_variables_array prospective_variables;	/**< X-machine memory variable prospective_variables of type dt_prospective_variables_array. */
	double price_at_questionnaire;	/**< X-machine memory variable price_at_questionnaire of type double. */
	double price_index_at_questionnaire;	/**< X-machine memory variable price_index_at_questionnaire of type double. */
	dt_best_price_strategies_array best_pricing_strategies;	/**< X-machine memory variable best_pricing_strategies of type dt_best_price_strategies_array. */
	double intermediate_quality;	/**< X-machine memory variable intermediate_quality of type double. */
	int no_employees_product_innovation_fundable;	/**< X-machine memory variable no_employees_product_innovation_fundable of type int. */
	double r_and_d_probability_for_incremental_success;	/**< X-machine memory variable r_and_d_probability_for_incremental_success of type double. */
	int day_of_year_price_setting;	/**< X-machine memory variable day_of_year_price_setting of type int. */
	int market_research_active;	/**< X-machine memory variable market_research_active of type int. */
	int innovation_successful;	/**< X-machine memory variable innovation_successful of type int. */
	double actual_market_share;	/**< X-machine memory variable actual_market_share of type double. */
	double market_size;	/**< X-machine memory variable market_size of type double. */
	double market_size_reg1;	/**< X-machine memory variable market_size_reg1 of type double. */
	double market_size_reg2;	/**< X-machine memory variable market_size_reg2 of type double. */
	double estimated_market_size;	/**< X-machine memory variable estimated_market_size of type double. */
	estimators_linear_regression_array linear_regression_market_size;	/**< X-machine memory variable linear_regression_market_size of type estimators_linear_regression_array. */
	int counter_month_since_last_price_setting;	/**< X-machine memory variable counter_month_since_last_price_setting of type int. */
	dt_demand_function demand_function_pricing;	/**< X-machine memory variable demand_function_pricing of type dt_demand_function. */
	dt_demand_function_array demand_functions_product_innovation;	/**< X-machine memory variable demand_functions_product_innovation of type dt_demand_function_array. */
	int market_research_delayed;	/**< X-machine memory variable market_research_delayed of type int. */
	dt_market_research_price_array market_research_data_pricing;	/**< X-machine memory variable market_research_data_pricing of type dt_market_research_price_array. */
	dt_market_research_qualities_array market_research_data_product_innovation;	/**< X-machine memory variable market_research_data_product_innovation of type dt_market_research_qualities_array. */
	double expected_earnings_per_month;	/**< X-machine memory variable expected_earnings_per_month of type double. */
	double_array expected_price_choices;	/**< X-machine memory variable expected_price_choices of type double_array. */
	double no_considered_qualities;	/**< X-machine memory variable no_considered_qualities of type double. */
	double last_interest_rate_for_loans;	/**< X-machine memory variable last_interest_rate_for_loans of type double. */
	double cum_earnings_last_r_d_project;	/**< X-machine memory variable cum_earnings_last_r_d_project of type double. */
	double cum_r_d_investments;	/**< X-machine memory variable cum_r_d_investments of type double. */
	double r_d_investments_last_project;	/**< X-machine memory variable r_d_investments_last_project of type double. */
	int total_person_months;	/**< X-machine memory variable total_person_months of type int. */
	int cum_person_months;	/**< X-machine memory variable cum_person_months of type int. */
	double actual_r_and_d_success_probability;	/**< X-machine memory variable actual_r_and_d_success_probability of type double. */
	double last_quality;	/**< X-machine memory variable last_quality of type double. */
	double quality_change;	/**< X-machine memory variable quality_change of type double. */
	double expected_sold_quantity_per_month;	/**< X-machine memory variable expected_sold_quantity_per_month of type double. */
	double estimated_market_share;	/**< X-machine memory variable estimated_market_share of type double. */
	double estimated_yearly_earnings;	/**< X-machine memory variable estimated_yearly_earnings of type double. */
	dt_monthly_estimations expected_earnings_and_costs_over_year[12];	/**< X-machine memory variable expected_earnings_and_costs_over_year of type dt_monthly_estimations. */
	double expected_output_in_current_month;	/**< X-machine memory variable expected_output_in_current_month of type double. */
	double expected_profit_in_current_month;	/**< X-machine memory variable expected_profit_in_current_month of type double. */
	double expected_labor_costs_in_current_month;	/**< X-machine memory variable expected_labor_costs_in_current_month of type double. */
	double expected_capital_costs_in_current_month;	/**< X-machine memory variable expected_capital_costs_in_current_month of type double. */
	double expected_interests_in_current_month;	/**< X-machine memory variable expected_interests_in_current_month of type double. */
	double expected_output_in_previous_month;	/**< X-machine memory variable expected_output_in_previous_month of type double. */
	double expected_actual_sold_quantity_in_previous_month;	/**< X-machine memory variable expected_actual_sold_quantity_in_previous_month of type double. */
	double expected_actual_sold_quantity_in_current_month;	/**< X-machine memory variable expected_actual_sold_quantity_in_current_month of type double. */
	double expected_labor_costs_in_previous_month;	/**< X-machine memory variable expected_labor_costs_in_previous_month of type double. */
	double expected_capital_costs_in_previous_month;	/**< X-machine memory variable expected_capital_costs_in_previous_month of type double. */
	double expected_interests_in_previous_month;	/**< X-machine memory variable expected_interests_in_previous_month of type double. */
	double expected_profit_in_previous_month;	/**< X-machine memory variable expected_profit_in_previous_month of type double. */
	double expected_wage_in_current_month;	/**< X-machine memory variable expected_wage_in_current_month of type double. */
	double expected_wage_in_previous_month;	/**< X-machine memory variable expected_wage_in_previous_month of type double. */
	double expected_mean_specific_skills_in_current_month;	/**< X-machine memory variable expected_mean_specific_skills_in_current_month of type double. */
	double expected_mean_specific_skills_in_previous_month;	/**< X-machine memory variable expected_mean_specific_skills_in_previous_month of type double. */
	double expected_average_productivity_in_current_month;	/**< X-machine memory variable expected_average_productivity_in_current_month of type double. */
	double expected_investment_nominal_in_current_month;	/**< X-machine memory variable expected_investment_nominal_in_current_month of type double. */
	double expected_investment_nominal_in_previous_month;	/**< X-machine memory variable expected_investment_nominal_in_previous_month of type double. */
	double expected_average_productivity_in_previous_month;	/**< X-machine memory variable expected_average_productivity_in_previous_month of type double. */
	double earnings_while_last_pricing_period;	/**< X-machine memory variable earnings_while_last_pricing_period of type double. */
	double sum_earnings_since_price_change;	/**< X-machine memory variable sum_earnings_since_price_change of type double. */
	dt_variables_changed_array variables_last_year;	/**< X-machine memory variable variables_last_year of type dt_variables_changed_array. */
	int innovation_month_counter;	/**< X-machine memory variable innovation_month_counter of type int. */
	int periods_output_zero_counter;	/**< X-machine memory variable periods_output_zero_counter of type int. */
	dt_variables_changed variables_change;	/**< X-machine memory variable variables_change of type dt_variables_changed. */
	double r_and_d_investments_per_month;	/**< X-machine memory variable r_and_d_investments_per_month of type double. */
	int innovation_flag;	/**< X-machine memory variable innovation_flag of type int. */
	int innovation_employees_needed;	/**< X-machine memory variable innovation_employees_needed of type int. */
	int no_employees_innovation;	/**< X-machine memory variable no_employees_innovation of type int. */
	int employees_needed_innovation;	/**< X-machine memory variable employees_needed_innovation of type int. */
	int optimal_employees_needed_innovation;	/**< X-machine memory variable optimal_employees_needed_innovation of type int. */
	int total_no_periods_for_product_development;	/**< X-machine memory variable total_no_periods_for_product_development of type int. */
	double ratio_project_value_established_product;	/**< X-machine memory variable ratio_project_value_established_product of type double. */
	int vintage_choice_already_taken;	/**< X-machine memory variable vintage_choice_already_taken of type int. */
	double change_due_to_last_innovation;	/**< X-machine memory variable change_due_to_last_innovation of type double. */
	int remaining_periods_to_complete_product_development;	/**< X-machine memory variable remaining_periods_to_complete_product_development of type int. */
	double planned_quality;	/**< X-machine memory variable planned_quality of type double. */
	double product_development_completed;	/**< X-machine memory variable product_development_completed of type double. */
	double price_just_set_flag;	/**< X-machine memory variable price_just_set_flag of type double. */
	dt_value_lattice_years_array value_lattice;	/**< X-machine memory variable value_lattice of type dt_value_lattice_years_array. */
	double combined_variance_demand_function;	/**< X-machine memory variable combined_variance_demand_function of type double. */
};

/** \struct xmachine_memory_Firm_holder
 * \brief Holds struct of memory of xmachine Firm.
 */
struct xmachine_memory_Firm_holder
{
	/*@dependent@*/ struct xmachine_memory_Firm * agent;	/**< Pointer to X-machine memory Firm. */

	/*@dependent@*/ struct xmachine_memory_Firm_holder * prev;	/**< Pointer to previous Firm agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Firm_holder * next;	/**< Pointer to next Firm agent in the list.  */
};

/** \struct xmachine_memory_Firm_holder
 * \brief Holds struct of memory of xmachine Firm.
 */
struct xmachine_memory_Firm_state
{
	/*@dependent@*/ struct xmachine_memory_Firm_holder * agents;	/**< Pointer to X-machine memory Firm. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int_array neighboring_region_ids;	/**< X-machine memory variable neighboring_region_ids of type int_array. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	int new_agent;	/**< X-machine memory variable new_agent of type int. */
	int migration_status;	/**< X-machine memory variable migration_status of type int. */
	double consumption_budget;	/**< X-machine memory variable consumption_budget of type double. */
	double consumption_budget_in_month;	/**< X-machine memory variable consumption_budget_in_month of type double. */
	int week_of_month;	/**< X-machine memory variable week_of_month of type int. */
	double weekly_budget;	/**< X-machine memory variable weekly_budget of type double. */
	int rationed;	/**< X-machine memory variable rationed of type int. */
	int mall_completely_sold_out;	/**< X-machine memory variable mall_completely_sold_out of type int. */
	ordered_quantity order_quantity[2];	/**< X-machine memory variable order_quantity of type ordered_quantity. */
	received_quantities received_quantity[2];	/**< X-machine memory variable received_quantity of type received_quantities. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	int day_of_month_receive_income;	/**< X-machine memory variable day_of_month_receive_income of type int. */
	double current_productivity_employer;	/**< X-machine memory variable current_productivity_employer of type double. */
	double current_mean_specific_skills_employer;	/**< X-machine memory variable current_mean_specific_skills_employer of type double. */
	double tax_payment;	/**< X-machine memory variable tax_payment of type double. */
	double cum_total_dividends;	/**< X-machine memory variable cum_total_dividends of type double. */
	double tax_rate_hh_capital;	/**< X-machine memory variable tax_rate_hh_capital of type double. */
	double tax_rate_hh_labour;	/**< X-machine memory variable tax_rate_hh_labour of type double. */
	double price_index;	/**< X-machine memory variable price_index of type double. */
	double price_index_base_period;	/**< X-machine memory variable price_index_base_period of type double. */
	double commuting_costs_price_level_weight;	/**< X-machine memory variable commuting_costs_price_level_weight of type double. */
	double expenditures;	/**< X-machine memory variable expenditures of type double. */
	double received_dividend;	/**< X-machine memory variable received_dividend of type double. */
	double received_dividend_in_calendar_month;	/**< X-machine memory variable received_dividend_in_calendar_month of type double. */
	double received_interest_daily;	/**< X-machine memory variable received_interest_daily of type double. */
	double received_interest_in_calendar_month;	/**< X-machine memory variable received_interest_in_calendar_month of type double. */
	int flag_consumption_shifting;	/**< X-machine memory variable flag_consumption_shifting of type int. */
	double excess_weekly_budget;	/**< X-machine memory variable excess_weekly_budget of type double. */
	double wealth_income_ratio_actual;	/**< X-machine memory variable wealth_income_ratio_actual of type double. */
	double wealth_income_ratio_target;	/**< X-machine memory variable wealth_income_ratio_target of type double. */
	double last_weekly_budget;	/**< X-machine memory variable last_weekly_budget of type double. */
	double risk_free_rate;	/**< X-machine memory variable risk_free_rate of type double. */
	double wealth;	/**< X-machine memory variable wealth of type double. */
	Belief beliefs;	/**< X-machine memory variable beliefs of type Belief. */
	index_portfolio assetsowned;	/**< X-machine memory variable assetsowned of type index_portfolio. */
	double logit_beta;	/**< X-machine memory variable logit_beta of type double. */
	double wage;	/**< X-machine memory variable wage of type double. */
	double wage_reservation;	/**< X-machine memory variable wage_reservation of type double. */
	int general_skill;	/**< X-machine memory variable general_skill of type int. */
	adt_list_adaptation_speed_array list_adaptation_speed_per_general_skill_group;	/**< X-machine memory variable list_adaptation_speed_per_general_skill_group of type adt_list_adaptation_speed_array. */
	int on_the_job_search;	/**< X-machine memory variable on_the_job_search of type int. */
	int search_today;	/**< X-machine memory variable search_today of type int. */
	double last_labour_income;	/**< X-machine memory variable last_labour_income of type double. */
	double specific_skill;	/**< X-machine memory variable specific_skill of type double. */
	int employee_firm_id;	/**< X-machine memory variable employee_firm_id of type int. */
	int hh_applications_per_day;	/**< X-machine memory variable hh_applications_per_day of type int. */
	int just_employed;	/**< X-machine memory variable just_employed of type int. */
	int just_unemployed;	/**< X-machine memory variable just_unemployed of type int. */
	int start_unemployed;	/**< X-machine memory variable start_unemployed of type int. */
	int start_employed;	/**< X-machine memory variable start_employed of type int. */
	int unemployed_duration;	/**< X-machine memory variable unemployed_duration of type int. */
	int enter_matching;	/**< X-machine memory variable enter_matching of type int. */
	int employer_region_id;	/**< X-machine memory variable employer_region_id of type int. */
	int employer_igfirm;	/**< X-machine memory variable employer_igfirm of type int. */
	int day_of_month_receive_benefit;	/**< X-machine memory variable day_of_month_receive_benefit of type int. */
	double unemployment_payment;	/**< X-machine memory variable unemployment_payment of type double. */
	double region_wide_mean_wage;	/**< X-machine memory variable region_wide_mean_wage of type double. */
	double basic_security_benefits;	/**< X-machine memory variable basic_security_benefits of type double. */
	double_array last_net_income;	/**< X-machine memory variable last_net_income of type double_array. */
	double mean_net_income;	/**< X-machine memory variable mean_net_income of type double. */
	household_balance_sheet_adt household_balance_sheet_calendar;	/**< X-machine memory variable household_balance_sheet_calendar of type household_balance_sheet_adt. */
	household_stocks_adt household_stocks_calendar;	/**< X-machine memory variable household_stocks_calendar of type household_stocks_adt. */
	household_outflows_adt household_outflows_calendar;	/**< X-machine memory variable household_outflows_calendar of type household_outflows_adt. */
	household_inflows_adt household_inflows_calendar;	/**< X-machine memory variable household_inflows_calendar of type household_inflows_adt. */
	double unemployment_benefit_pct;	/**< X-machine memory variable unemployment_benefit_pct of type double. */
	double minimum_wage;	/**< X-machine memory variable minimum_wage of type double. */
	double transfer_payment;	/**< X-machine memory variable transfer_payment of type double. */
	double subsidy_pct;	/**< X-machine memory variable subsidy_pct of type double. */
	double monthly_interest_income;	/**< X-machine memory variable monthly_interest_income of type double. */
	double total_income;	/**< X-machine memory variable total_income of type double. */
	double total_expenses;	/**< X-machine memory variable total_expenses of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double total_liabilities;	/**< X-machine memory variable total_liabilities of type double. */
	double monthly_consumption_expenditure;	/**< X-machine memory variable monthly_consumption_expenditure of type double. */
	double monthly_bond_interest_income;	/**< X-machine memory variable monthly_bond_interest_income of type double. */
	double subsidy_payment;	/**< X-machine memory variable subsidy_payment of type double. */
	double region_mean_wage;	/**< X-machine memory variable region_mean_wage of type double. */
	int human_capital_policy_flag;	/**< X-machine memory variable human_capital_policy_flag of type int. */
	double questionnaire_attending_propability;	/**< X-machine memory variable questionnaire_attending_propability of type double. */
	int willingness_to_attend;	/**< X-machine memory variable willingness_to_attend of type int. */
	int interviewer_id;	/**< X-machine memory variable interviewer_id of type int. */
	int random_no_test;	/**< X-machine memory variable random_no_test of type int. */
	int questionnaire[40];	/**< X-machine memory variable questionnaire of type int. */
	consumption_goods_offer_array current_price_quality_list;	/**< X-machine memory variable current_price_quality_list of type consumption_goods_offer_array. */
};

/** \struct xmachine_memory_Household_holder
 * \brief Holds struct of memory of xmachine Household.
 */
struct xmachine_memory_Household_holder
{
	/*@dependent@*/ struct xmachine_memory_Household * agent;	/**< Pointer to X-machine memory Household. */

	/*@dependent@*/ struct xmachine_memory_Household_holder * prev;	/**< Pointer to previous Household agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Household_holder * next;	/**< Pointer to next Household agent in the list.  */
};

/** \struct xmachine_memory_Household_holder
 * \brief Holds struct of memory of xmachine Household.
 */
struct xmachine_memory_Household_state
{
	/*@dependent@*/ struct xmachine_memory_Household_holder * agents;	/**< Pointer to X-machine memory Household. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Mall
 * \brief Holds memory of xmachine Mall.
 */
struct xmachine_memory_Mall
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	mall_stock_array current_stock;	/**< X-machine memory variable current_stock of type mall_stock_array. */
	sales_in_mall_array firm_revenues;	/**< X-machine memory variable firm_revenues of type sales_in_mall_array. */
	double total_supply;	/**< X-machine memory variable total_supply of type double. */
	double sales_per_month;	/**< X-machine memory variable sales_per_month of type double. */
	double export_volume_matrix[900];	/**< X-machine memory variable export_volume_matrix of type double. */
	double export_value_matrix[900];	/**< X-machine memory variable export_value_matrix of type double. */
	double export_previous_value_matrix[900];	/**< X-machine memory variable export_previous_value_matrix of type double. */
};

/** \struct xmachine_memory_Mall_holder
 * \brief Holds struct of memory of xmachine Mall.
 */
struct xmachine_memory_Mall_holder
{
	/*@dependent@*/ struct xmachine_memory_Mall * agent;	/**< Pointer to X-machine memory Mall. */

	/*@dependent@*/ struct xmachine_memory_Mall_holder * prev;	/**< Pointer to previous Mall agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Mall_holder * next;	/**< Pointer to next Mall agent in the list.  */
};

/** \struct xmachine_memory_Mall_holder
 * \brief Holds struct of memory of xmachine Mall.
 */
struct xmachine_memory_Mall_state
{
	/*@dependent@*/ struct xmachine_memory_Mall_holder * agents;	/**< Pointer to X-machine memory Mall. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_IGFirm
 * \brief Holds memory of xmachine IGFirm.
 */
struct xmachine_memory_IGFirm
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int last_day_of_month_to_act;	/**< X-machine memory variable last_day_of_month_to_act of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	double payment_account_balance_sheet;	/**< X-machine memory variable payment_account_balance_sheet of type double. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	double received_interest_daily;	/**< X-machine memory variable received_interest_daily of type double. */
	double received_interest_in_calendar_month;	/**< X-machine memory variable received_interest_in_calendar_month of type double. */
	double ebit;	/**< X-machine memory variable ebit of type double. */
	double earnings;	/**< X-machine memory variable earnings of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double tax_payment;	/**< X-machine memory variable tax_payment of type double. */
	double tax_payment_in_calendar_month;	/**< X-machine memory variable tax_payment_in_calendar_month of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double previous_net_earnings;	/**< X-machine memory variable previous_net_earnings of type double. */
	double total_dividend_payment;	/**< X-machine memory variable total_dividend_payment of type double. */
	double total_dividend_payment_in_calendar_month;	/**< X-machine memory variable total_dividend_payment_in_calendar_month of type double. */
	double current_share_price;	/**< X-machine memory variable current_share_price of type double. */
	double previous_dividend_per_share;	/**< X-machine memory variable previous_dividend_per_share of type double. */
	double current_dividend_per_share;	/**< X-machine memory variable current_dividend_per_share of type double. */
	double previous_earnings_per_share;	/**< X-machine memory variable previous_earnings_per_share of type double. */
	double current_earnings_per_share;	/**< X-machine memory variable current_earnings_per_share of type double. */
	double previous_dividend_per_earnings;	/**< X-machine memory variable previous_dividend_per_earnings of type double. */
	double current_dividend_per_earnings;	/**< X-machine memory variable current_dividend_per_earnings of type double. */
	double debt_earnings_ratio;	/**< X-machine memory variable debt_earnings_ratio of type double. */
	double debt_equity_ratio;	/**< X-machine memory variable debt_equity_ratio of type double. */
	double price_earnings_ratio;	/**< X-machine memory variable price_earnings_ratio of type double. */
	double retained_earnings_ratio;	/**< X-machine memory variable retained_earnings_ratio of type double. */
	double earnings_per_share_ratio_growth;	/**< X-machine memory variable earnings_per_share_ratio_growth of type double. */
	double critical_price_earnings_ratio;	/**< X-machine memory variable critical_price_earnings_ratio of type double. */
	double critical_earnings_per_share_ratio;	/**< X-machine memory variable critical_earnings_per_share_ratio of type double. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double total_debt_balance_sheet;	/**< X-machine memory variable total_debt_balance_sheet of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double equity_balance_sheet;	/**< X-machine memory variable equity_balance_sheet of type double. */
	double earnings_per_share;	/**< X-machine memory variable earnings_per_share of type double. */
	double total_payments;	/**< X-machine memory variable total_payments of type double. */
	int previous_shares_outstanding;	/**< X-machine memory variable previous_shares_outstanding of type int. */
	double total_income;	/**< X-machine memory variable total_income of type double. */
	double total_liabilities;	/**< X-machine memory variable total_liabilities of type double. */
	double total_expenses;	/**< X-machine memory variable total_expenses of type double. */
	double calc_production_costs;	/**< X-machine memory variable calc_production_costs of type double. */
	double productivity;	/**< X-machine memory variable productivity of type double. */
	double capital_good_price;	/**< X-machine memory variable capital_good_price of type double. */
	vintage_array vintages;	/**< X-machine memory variable vintages of type vintage_array. */
	adt_sales_per_vintage_array sales_per_vintage;	/**< X-machine memory variable sales_per_vintage of type adt_sales_per_vintage_array. */
	double mean_productivity_of_sales;	/**< X-machine memory variable mean_productivity_of_sales of type double. */
	double ratio_sold_productivity_best_practice;	/**< X-machine memory variable ratio_sold_productivity_best_practice of type double. */
	double igfirm_endogenous_innovation_probability;	/**< X-machine memory variable igfirm_endogenous_innovation_probability of type double. */
	double revenue_per_day;	/**< X-machine memory variable revenue_per_day of type double. */
	double net_profit;	/**< X-machine memory variable net_profit of type double. */
	int current_shares_outstanding;	/**< X-machine memory variable current_shares_outstanding of type int. */
	double energy_price_markup;	/**< X-machine memory variable energy_price_markup of type double. */
	double energy_costs_per_day;	/**< X-machine memory variable energy_costs_per_day of type double. */
	double earnings_per_day;	/**< X-machine memory variable earnings_per_day of type double. */
	double cum_energy_costs;	/**< X-machine memory variable cum_energy_costs of type double. */
	double_array last_net_profits;	/**< X-machine memory variable last_net_profits of type double_array. */
	double mean_sales_last_months;	/**< X-machine memory variable mean_sales_last_months of type double. */
	double_array last_sales;	/**< X-machine memory variable last_sales of type double_array. */
	double dividend_payment;	/**< X-machine memory variable dividend_payment of type double. */
	int duration_until_next_innovation;	/**< X-machine memory variable duration_until_next_innovation of type int. */
	double unit_costs;	/**< X-machine memory variable unit_costs of type double. */
	double sales;	/**< X-machine memory variable sales of type double. */
	double capital_good_demand;	/**< X-machine memory variable capital_good_demand of type double. */
	double capital_good_demand_last_month;	/**< X-machine memory variable capital_good_demand_last_month of type double. */
	double sales_last_month;	/**< X-machine memory variable sales_last_month of type double. */
	double cum_revenue;	/**< X-machine memory variable cum_revenue of type double. */
	double cum_revenue_last_month;	/**< X-machine memory variable cum_revenue_last_month of type double. */
	int_array innovation_sheme_low_progress;	/**< X-machine memory variable innovation_sheme_low_progress of type int_array. */
	int_array innovation_sheme_medium_progress;	/**< X-machine memory variable innovation_sheme_medium_progress of type int_array. */
	int_array innovation_sheme_high_progress;	/**< X-machine memory variable innovation_sheme_high_progress of type int_array. */
	double mean_general_skills;	/**< X-machine memory variable mean_general_skills of type double. */
	double mean_adaptation_speed;	/**< X-machine memory variable mean_adaptation_speed of type double. */
	adt_list_adaptation_speed_array list_adaptation_speed;	/**< X-machine memory variable list_adaptation_speed of type adt_list_adaptation_speed_array. */
	double productivity_progress_in_economy;	/**< X-machine memory variable productivity_progress_in_economy of type double. */
	double economy_wide_capital_stock;	/**< X-machine memory variable economy_wide_capital_stock of type double. */
	double dividend_buffer;	/**< X-machine memory variable dividend_buffer of type double. */
	double dividend_target;	/**< X-machine memory variable dividend_target of type double. */
	igfirm_balance_sheet_adt igfirm_balance_sheet_calendar;	/**< X-machine memory variable igfirm_balance_sheet_calendar of type igfirm_balance_sheet_adt. */
	igfirm_stocks_adt igfirm_stocks_calendar;	/**< X-machine memory variable igfirm_stocks_calendar of type igfirm_stocks_adt. */
	igfirm_outflows_adt igfirm_outflows_calendar;	/**< X-machine memory variable igfirm_outflows_calendar of type igfirm_outflows_adt. */
	igfirm_inflows_adt igfirm_inflows_calendar;	/**< X-machine memory variable igfirm_inflows_calendar of type igfirm_inflows_adt. */
	int age;	/**< X-machine memory variable age of type int. */
	double transfer_payment;	/**< X-machine memory variable transfer_payment of type double. */
	double subsidy_pct;	/**< X-machine memory variable subsidy_pct of type double. */
	int active;	/**< X-machine memory variable active of type int. */
	int bankruptcy_idle_counter;	/**< X-machine memory variable bankruptcy_idle_counter of type int. */
	int bankruptcy_state;	/**< X-machine memory variable bankruptcy_state of type int. */
	int bankruptcy_insolvency_state;	/**< X-machine memory variable bankruptcy_insolvency_state of type int. */
	int bankruptcy_illiquidity_state;	/**< X-machine memory variable bankruptcy_illiquidity_state of type int. */
	int financial_crisis_state;	/**< X-machine memory variable financial_crisis_state of type int. */
	double economy_wide_general_skills_in_firms;	/**< X-machine memory variable economy_wide_general_skills_in_firms of type double. */
	double economy_wide_specific_skills_in_firms;	/**< X-machine memory variable economy_wide_specific_skills_in_firms of type double. */
	double subsidy_payment;	/**< X-machine memory variable subsidy_payment of type double. */
	double wage_offer;	/**< X-machine memory variable wage_offer of type double. */
};

/** \struct xmachine_memory_IGFirm_holder
 * \brief Holds struct of memory of xmachine IGFirm.
 */
struct xmachine_memory_IGFirm_holder
{
	/*@dependent@*/ struct xmachine_memory_IGFirm * agent;	/**< Pointer to X-machine memory IGFirm. */

	/*@dependent@*/ struct xmachine_memory_IGFirm_holder * prev;	/**< Pointer to previous IGFirm agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_IGFirm_holder * next;	/**< Pointer to next IGFirm agent in the list.  */
};

/** \struct xmachine_memory_IGFirm_holder
 * \brief Holds struct of memory of xmachine IGFirm.
 */
struct xmachine_memory_IGFirm_state
{
	/*@dependent@*/ struct xmachine_memory_IGFirm_holder * agents;	/**< Pointer to X-machine memory IGFirm. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Eurostat
 * \brief Holds memory of xmachine Eurostat.
 */
struct xmachine_memory_Eurostat
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	int switch_datastorage;	/**< X-machine memory variable switch_datastorage of type int. */
	int num_households;	/**< X-machine memory variable num_households of type int. */
	int no_households_skill_1;	/**< X-machine memory variable no_households_skill_1 of type int. */
	int no_households_skill_2;	/**< X-machine memory variable no_households_skill_2 of type int. */
	int no_households_skill_3;	/**< X-machine memory variable no_households_skill_3 of type int. */
	int no_households_skill_4;	/**< X-machine memory variable no_households_skill_4 of type int. */
	int no_households_skill_5;	/**< X-machine memory variable no_households_skill_5 of type int. */
	int employed;	/**< X-machine memory variable employed of type int. */
	int employed_skill_1;	/**< X-machine memory variable employed_skill_1 of type int. */
	int employed_skill_2;	/**< X-machine memory variable employed_skill_2 of type int. */
	int employed_skill_3;	/**< X-machine memory variable employed_skill_3 of type int. */
	int employed_skill_4;	/**< X-machine memory variable employed_skill_4 of type int. */
	int employed_skill_5;	/**< X-machine memory variable employed_skill_5 of type int. */
	double average_unit_labor_costs_reg_1;	/**< X-machine memory variable average_unit_labor_costs_reg_1 of type double. */
	double average_unit_labor_costs_reg_2;	/**< X-machine memory variable average_unit_labor_costs_reg_2 of type double. */
	int unemployed;	/**< X-machine memory variable unemployed of type int. */
	double unemployment_rate;	/**< X-machine memory variable unemployment_rate of type double. */
	double employment_rate;	/**< X-machine memory variable employment_rate of type double. */
	double unemployment_rate_skill_1;	/**< X-machine memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< X-machine memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< X-machine memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< X-machine memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< X-machine memory variable unemployment_rate_skill_5 of type double. */
	int unemployed_reg1;	/**< X-machine memory variable unemployed_reg1 of type int. */
	int unemployed_reg2;	/**< X-machine memory variable unemployed_reg2 of type int. */
	double unemployment_rate_reg1;	/**< X-machine memory variable unemployment_rate_reg1 of type double. */
	double unemployment_rate_reg2;	/**< X-machine memory variable unemployment_rate_reg2 of type double. */
	double v_u_ratio_reg1;	/**< X-machine memory variable v_u_ratio_reg1 of type double. */
	double v_u_ratio_reg2;	/**< X-machine memory variable v_u_ratio_reg2 of type double. */
	double average_wage;	/**< X-machine memory variable average_wage of type double. */
	double average_wage_reservation;	/**< X-machine memory variable average_wage_reservation of type double. */
	double average_wage_reservation_region_1;	/**< X-machine memory variable average_wage_reservation_region_1 of type double. */
	double average_wage_reservation_region_2;	/**< X-machine memory variable average_wage_reservation_region_2 of type double. */
	double average_wage_skill_1;	/**< X-machine memory variable average_wage_skill_1 of type double. */
	double average_wage_skill_2;	/**< X-machine memory variable average_wage_skill_2 of type double. */
	double average_wage_skill_3;	/**< X-machine memory variable average_wage_skill_3 of type double. */
	double average_wage_skill_4;	/**< X-machine memory variable average_wage_skill_4 of type double. */
	double average_wage_skill_5;	/**< X-machine memory variable average_wage_skill_5 of type double. */
	double sd_wage;	/**< X-machine memory variable sd_wage of type double. */
	double sd_income;	/**< X-machine memory variable sd_income of type double. */
	double sd_wealth;	/**< X-machine memory variable sd_wealth of type double. */
	double sd_specific_skills;	/**< X-machine memory variable sd_specific_skills of type double. */
	double sd_wage_reg_1;	/**< X-machine memory variable sd_wage_reg_1 of type double. */
	double sd_income_reg_1;	/**< X-machine memory variable sd_income_reg_1 of type double. */
	double sd_wealth_reg_1;	/**< X-machine memory variable sd_wealth_reg_1 of type double. */
	double sd_specific_skills_reg_1;	/**< X-machine memory variable sd_specific_skills_reg_1 of type double. */
	double sd_wage_reg_2;	/**< X-machine memory variable sd_wage_reg_2 of type double. */
	double sd_income_reg_2;	/**< X-machine memory variable sd_income_reg_2 of type double. */
	double sd_wealth_reg_2;	/**< X-machine memory variable sd_wealth_reg_2 of type double. */
	double sd_specific_skills_reg_2;	/**< X-machine memory variable sd_specific_skills_reg_2 of type double. */
	double total_output_reg_2;	/**< X-machine memory variable total_output_reg_2 of type double. */
	double total_output_reg_1;	/**< X-machine memory variable total_output_reg_1 of type double. */
	double per_capita_output_reg_2;	/**< X-machine memory variable per_capita_output_reg_2 of type double. */
	double per_capita_output_reg_1;	/**< X-machine memory variable per_capita_output_reg_1 of type double. */
	double mean_price_reg_1;	/**< X-machine memory variable mean_price_reg_1 of type double. */
	double mean_price_reg_2;	/**< X-machine memory variable mean_price_reg_2 of type double. */
	double mean_technology_reg_1;	/**< X-machine memory variable mean_technology_reg_1 of type double. */
	double mean_technology_reg_2;	/**< X-machine memory variable mean_technology_reg_2 of type double. */
	double exports_reg1;	/**< X-machine memory variable exports_reg1 of type double. */
	double exports_reg2;	/**< X-machine memory variable exports_reg2 of type double. */
	double imports_reg1;	/**< X-machine memory variable imports_reg1 of type double. */
	double trade_balance_reg1;	/**< X-machine memory variable trade_balance_reg1 of type double. */
	double trade_balance_reg2;	/**< X-machine memory variable trade_balance_reg2 of type double. */
	double imports_reg2;	/**< X-machine memory variable imports_reg2 of type double. */
	double export_quota_reg1;	/**< X-machine memory variable export_quota_reg1 of type double. */
	double export_quota_reg2;	/**< X-machine memory variable export_quota_reg2 of type double. */
	double import_quota_reg1;	/**< X-machine memory variable import_quota_reg1 of type double. */
	double import_quota_reg2;	/**< X-machine memory variable import_quota_reg2 of type double. */
	double trade_balance_quota_reg1;	/**< X-machine memory variable trade_balance_quota_reg1 of type double. */
	double trade_balance_quota_reg2;	/**< X-machine memory variable trade_balance_quota_reg2 of type double. */
	double mean_wage_reg_1;	/**< X-machine memory variable mean_wage_reg_1 of type double. */
	double mean_wage_reg_2;	/**< X-machine memory variable mean_wage_reg_2 of type double. */
	double mean_wage_offer_reg_1;	/**< X-machine memory variable mean_wage_offer_reg_1 of type double. */
	double mean_wage_offer_reg_2;	/**< X-machine memory variable mean_wage_offer_reg_2 of type double. */
	double mean_s_skills_reg_1;	/**< X-machine memory variable mean_s_skills_reg_1 of type double. */
	double mean_s_skills_reg_2;	/**< X-machine memory variable mean_s_skills_reg_2 of type double. */
	double mean_mark_up_reg_1;	/**< X-machine memory variable mean_mark_up_reg_1 of type double. */
	double mean_mark_up_reg_2;	/**< X-machine memory variable mean_mark_up_reg_2 of type double. */
	double relative_price;	/**< X-machine memory variable relative_price of type double. */
	double relative_reservation_wage;	/**< X-machine memory variable relative_reservation_wage of type double. */
	double relative_mark_up;	/**< X-machine memory variable relative_mark_up of type double. */
	double relative_wage;	/**< X-machine memory variable relative_wage of type double. */
	double relative_wage_offer;	/**< X-machine memory variable relative_wage_offer of type double. */
	double relative_technology;	/**< X-machine memory variable relative_technology of type double. */
	double relative_s_skills;	/**< X-machine memory variable relative_s_skills of type double. */
	double relative_output;	/**< X-machine memory variable relative_output of type double. */
	double government_consumption;	/**< X-machine memory variable government_consumption of type double. */
	double gini_wage;	/**< X-machine memory variable gini_wage of type double. */
	double gini_income;	/**< X-machine memory variable gini_income of type double. */
	double gini_wealth;	/**< X-machine memory variable gini_wealth of type double. */
	double gini_specific_skills;	/**< X-machine memory variable gini_specific_skills of type double. */
	double gini_wage_reg_1;	/**< X-machine memory variable gini_wage_reg_1 of type double. */
	double gini_income_reg_1;	/**< X-machine memory variable gini_income_reg_1 of type double. */
	double gini_wealth_reg_1;	/**< X-machine memory variable gini_wealth_reg_1 of type double. */
	double gini_specific_skills_reg_1;	/**< X-machine memory variable gini_specific_skills_reg_1 of type double. */
	double gini_wage_reg_2;	/**< X-machine memory variable gini_wage_reg_2 of type double. */
	double gini_income_reg_2;	/**< X-machine memory variable gini_income_reg_2 of type double. */
	double gini_wealth_reg_2;	/**< X-machine memory variable gini_wealth_reg_2 of type double. */
	double gini_specific_skills_reg_2;	/**< X-machine memory variable gini_specific_skills_reg_2 of type double. */
	double labor_income_reg_1;	/**< X-machine memory variable labor_income_reg_1 of type double. */
	double labor_income_reg_2;	/**< X-machine memory variable labor_income_reg_2 of type double. */
	double dividend_income_reg_1;	/**< X-machine memory variable dividend_income_reg_1 of type double. */
	double dividend_income_reg_2;	/**< X-machine memory variable dividend_income_reg_2 of type double. */
	double interest_income_reg_1;	/**< X-machine memory variable interest_income_reg_1 of type double. */
	double interest_income_reg_2;	/**< X-machine memory variable interest_income_reg_2 of type double. */
	double financial_market_net_revenue_reg_1;	/**< X-machine memory variable financial_market_net_revenue_reg_1 of type double. */
	double financial_market_net_revenue_reg_2;	/**< X-machine memory variable financial_market_net_revenue_reg_2 of type double. */
	double average_s_skill;	/**< X-machine memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< X-machine memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< X-machine memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< X-machine memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< X-machine memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< X-machine memory variable average_s_skill_5 of type double. */
	double total_consumption_budget;	/**< X-machine memory variable total_consumption_budget of type double. */
	int no_firms;	/**< X-machine memory variable no_firms of type int. */
	int no_active_firms;	/**< X-machine memory variable no_active_firms of type int. */
	int no_vacancies;	/**< X-machine memory variable no_vacancies of type int. */
	int no_posted_vacancies;	/**< X-machine memory variable no_posted_vacancies of type int. */
	int no_employees;	/**< X-machine memory variable no_employees of type int. */
	int no_employees_production;	/**< X-machine memory variable no_employees_production of type int. */
	int no_employees_r_and_d;	/**< X-machine memory variable no_employees_r_and_d of type int. */
	int no_employees_skill_1;	/**< X-machine memory variable no_employees_skill_1 of type int. */
	int no_employees_skill_2;	/**< X-machine memory variable no_employees_skill_2 of type int. */
	int no_employees_skill_3;	/**< X-machine memory variable no_employees_skill_3 of type int. */
	int no_employees_skill_4;	/**< X-machine memory variable no_employees_skill_4 of type int. */
	int no_employees_skill_5;	/**< X-machine memory variable no_employees_skill_5 of type int. */
	price_quality_pair_array price_quality_combination;	/**< X-machine memory variable price_quality_combination of type price_quality_pair_array. */
	double firm_average_wage;	/**< X-machine memory variable firm_average_wage of type double. */
	double firm_average_production_wage;	/**< X-machine memory variable firm_average_production_wage of type double. */
	double firm_average_r_and_d_wage;	/**< X-machine memory variable firm_average_r_and_d_wage of type double. */
	double firm_average_wage_skill_1;	/**< X-machine memory variable firm_average_wage_skill_1 of type double. */
	double firm_average_wage_skill_2;	/**< X-machine memory variable firm_average_wage_skill_2 of type double. */
	double firm_average_wage_skill_3;	/**< X-machine memory variable firm_average_wage_skill_3 of type double. */
	double firm_average_wage_skill_4;	/**< X-machine memory variable firm_average_wage_skill_4 of type double. */
	double firm_average_wage_skill_5;	/**< X-machine memory variable firm_average_wage_skill_5 of type double. */
	double firm_average_g_skill;	/**< X-machine memory variable firm_average_g_skill of type double. */
	double firm_average_s_skill;	/**< X-machine memory variable firm_average_s_skill of type double. */
	double firm_average_s_skill_1;	/**< X-machine memory variable firm_average_s_skill_1 of type double. */
	double firm_average_s_skill_2;	/**< X-machine memory variable firm_average_s_skill_2 of type double. */
	double firm_average_s_skill_3;	/**< X-machine memory variable firm_average_s_skill_3 of type double. */
	double firm_average_s_skill_4;	/**< X-machine memory variable firm_average_s_skill_4 of type double. */
	double firm_average_s_skill_5;	/**< X-machine memory variable firm_average_s_skill_5 of type double. */
	double firm_average_quality;	/**< X-machine memory variable firm_average_quality of type double. */
	double firm_average_price;	/**< X-machine memory variable firm_average_price of type double. */
	firm_data_array region_firm_data;	/**< X-machine memory variable region_firm_data of type firm_data_array. */
	household_data_array region_household_data;	/**< X-machine memory variable region_household_data of type household_data_array. */
	government_data_array region_government_data;	/**< X-machine memory variable region_government_data of type government_data_array. */
	double total_earnings;	/**< X-machine memory variable total_earnings of type double. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double total_equity;	/**< X-machine memory variable total_equity of type double. */
	double average_debt_earnings_ratio;	/**< X-machine memory variable average_debt_earnings_ratio of type double. */
	double average_debt_equity_ratio;	/**< X-machine memory variable average_debt_equity_ratio of type double. */
	double labour_share_ratio;	/**< X-machine memory variable labour_share_ratio of type double. */
	double cpi;	/**< X-machine memory variable cpi of type double. */
	double hpi;	/**< X-machine memory variable hpi of type double. */
	adt_subsidies_per_government_array subsidies_per_government;	/**< X-machine memory variable subsidies_per_government of type adt_subsidies_per_government_array. */
	adt_subsidies_per_government_array subsidies_balanced;	/**< X-machine memory variable subsidies_balanced of type adt_subsidies_per_government_array. */
	double gdp;	/**< X-machine memory variable gdp of type double. */
	double monthly_investment_value;	/**< X-machine memory variable monthly_investment_value of type double. */
	double monthly_sold_quantity;	/**< X-machine memory variable monthly_sold_quantity of type double. */
	double herfindahl_index;	/**< X-machine memory variable herfindahl_index of type double. */
	double monthly_output;	/**< X-machine memory variable monthly_output of type double. */
	double monthly_revenue;	/**< X-machine memory variable monthly_revenue of type double. */
	double monthly_planned_output;	/**< X-machine memory variable monthly_planned_output of type double. */
	double price_index;	/**< X-machine memory variable price_index of type double. */
	history_item history_monthly[13];	/**< X-machine memory variable history_monthly of type history_item. */
	history_item history_quarterly[5];	/**< X-machine memory variable history_quarterly of type history_item. */
	history_item monthly_growth_rates;	/**< X-machine memory variable monthly_growth_rates of type history_item. */
	history_item quarterly_growth_rates;	/**< X-machine memory variable quarterly_growth_rates of type history_item. */
	history_item annual_growth_rates_monthly;	/**< X-machine memory variable annual_growth_rates_monthly of type history_item. */
	history_item annual_growth_rates_quarterly;	/**< X-machine memory variable annual_growth_rates_quarterly of type history_item. */
	int no_firm_births;	/**< X-machine memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< X-machine memory variable no_firm_deaths of type int. */
	int firm_age_distribution[301];	/**< X-machine memory variable firm_age_distribution of type int. */
	int firm_age_distribution_multiperiod[3612];	/**< X-machine memory variable firm_age_distribution_multiperiod of type int. */
	int firm_age_distribution_1_period_lag[301];	/**< X-machine memory variable firm_age_distribution_1_period_lag of type int. */
	int firm_age_distribution_2_period_lag[301];	/**< X-machine memory variable firm_age_distribution_2_period_lag of type int. */
	double firm_birth_rate;	/**< X-machine memory variable firm_birth_rate of type double. */
	double firm_death_rate;	/**< X-machine memory variable firm_death_rate of type double. */
	double survival_rate[301];	/**< X-machine memory variable survival_rate of type double. */
	double survival_rate_multiperiod_1[301];	/**< X-machine memory variable survival_rate_multiperiod_1 of type double. */
	double survival_rate_multiperiod_2[301];	/**< X-machine memory variable survival_rate_multiperiod_2 of type double. */
	double survival_rate_multiperiod[3612];	/**< X-machine memory variable survival_rate_multiperiod of type double. */
	int max_firm_creation;	/**< X-machine memory variable max_firm_creation of type int. */
	int recession_started;	/**< X-machine memory variable recession_started of type int. */
	int recession_duration;	/**< X-machine memory variable recession_duration of type int. */
	double export_volume_matrix[100];	/**< X-machine memory variable export_volume_matrix of type double. */
	double export_value_matrix[100];	/**< X-machine memory variable export_value_matrix of type double. */
	double export_previous_value_matrix[100];	/**< X-machine memory variable export_previous_value_matrix of type double. */
	double region_export_volume[100];	/**< X-machine memory variable region_export_volume of type double. */
	double region_import_volume[100];	/**< X-machine memory variable region_import_volume of type double. */
	double region_export_value[100];	/**< X-machine memory variable region_export_value of type double. */
	double region_import_value[100];	/**< X-machine memory variable region_import_value of type double. */
	double region_import_previous_value[100];	/**< X-machine memory variable region_import_previous_value of type double. */
	double firm_average_productivity_progress;	/**< X-machine memory variable firm_average_productivity_progress of type double. */
	double firm_average_productivity;	/**< X-machine memory variable firm_average_productivity of type double. */
	double investment_gdp_ratio;	/**< X-machine memory variable investment_gdp_ratio of type double. */
	double total_capital_stock_units;	/**< X-machine memory variable total_capital_stock_units of type double. */
	double total_value_mall_inventories;	/**< X-machine memory variable total_value_mall_inventories of type double. */
	double total_dividends;	/**< X-machine memory variable total_dividends of type double. */
	double base_wage_offer;	/**< X-machine memory variable base_wage_offer of type double. */
	int just_employed;	/**< X-machine memory variable just_employed of type int. */
	int just_unemployed;	/**< X-machine memory variable just_unemployed of type int. */
	int start_employed;	/**< X-machine memory variable start_employed of type int. */
	int start_unemployed;	/**< X-machine memory variable start_unemployed of type int. */
	int enter_matching;	/**< X-machine memory variable enter_matching of type int. */
	int unemployed_duration;	/**< X-machine memory variable unemployed_duration of type int. */
	int_array all_region_ids;	/**< X-machine memory variable all_region_ids of type int_array. */
	int_array all_gov_ids;	/**< X-machine memory variable all_gov_ids of type int_array. */
	double job_seperation_rate;	/**< X-machine memory variable job_seperation_rate of type double. */
	double job_finding_rate;	/**< X-machine memory variable job_finding_rate of type double. */
	double v_u_ratio;	/**< X-machine memory variable v_u_ratio of type double. */
	double matching_rate;	/**< X-machine memory variable matching_rate of type double. */
	double hh_payment_account;	/**< X-machine memory variable hh_payment_account of type double. */
	double mean_net_income;	/**< X-machine memory variable mean_net_income of type double. */
};

/** \struct xmachine_memory_Eurostat_holder
 * \brief Holds struct of memory of xmachine Eurostat.
 */
struct xmachine_memory_Eurostat_holder
{
	/*@dependent@*/ struct xmachine_memory_Eurostat * agent;	/**< Pointer to X-machine memory Eurostat. */

	/*@dependent@*/ struct xmachine_memory_Eurostat_holder * prev;	/**< Pointer to previous Eurostat agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Eurostat_holder * next;	/**< Pointer to next Eurostat agent in the list.  */
};

/** \struct xmachine_memory_Eurostat_holder
 * \brief Holds struct of memory of xmachine Eurostat.
 */
struct xmachine_memory_Eurostat_state
{
	/*@dependent@*/ struct xmachine_memory_Eurostat_holder * agents;	/**< Pointer to X-machine memory Eurostat. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Bank
 * \brief Holds memory of xmachine Bank.
 */
struct xmachine_memory_Bank
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	int active;	/**< X-machine memory variable active of type int. */
	int inactive;	/**< X-machine memory variable inactive of type int. */
	double cash;	/**< X-machine memory variable cash of type double. */
	double total_credit;	/**< X-machine memory variable total_credit of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double ecb_debt;	/**< X-machine memory variable ecb_debt of type double. */
	double value_at_risk;	/**< X-machine memory variable value_at_risk of type double. */
	double deposit_interest_rate;	/**< X-machine memory variable deposit_interest_rate of type double. */
	double bank_gamma[2];	/**< X-machine memory variable bank_gamma of type double. */
	double profits[2];	/**< X-machine memory variable profits of type double. */
	double bank_dividend_rate;	/**< X-machine memory variable bank_dividend_rate of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	int current_shares_outstanding;	/**< X-machine memory variable current_shares_outstanding of type int. */
	double debt_period;	/**< X-machine memory variable debt_period of type double. */
	int loan_request_message_found;	/**< X-machine memory variable loan_request_message_found of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double deposits;	/**< X-machine memory variable deposits of type double. */
	double firm_loan_installments;	/**< X-machine memory variable firm_loan_installments of type double. */
	double firm_loan_installments_in_calendar_month;	/**< X-machine memory variable firm_loan_installments_in_calendar_month of type double. */
	double firm_interest_payments;	/**< X-machine memory variable firm_interest_payments of type double. */
	double firm_interest_payments_in_calendar_month;	/**< X-machine memory variable firm_interest_payments_in_calendar_month of type double. */
	double firm_loan_issues;	/**< X-machine memory variable firm_loan_issues of type double. */
	double ecb_interest_payment;	/**< X-machine memory variable ecb_interest_payment of type double. */
	double total_dividend_payment;	/**< X-machine memory variable total_dividend_payment of type double. */
	double total_dividends_in_calendar_month;	/**< X-machine memory variable total_dividends_in_calendar_month of type double. */
	double taxes;	/**< X-machine memory variable taxes of type double. */
	double dividend_per_share;	/**< X-machine memory variable dividend_per_share of type double. */
	double current_share_price;	/**< X-machine memory variable current_share_price of type double. */
	double leverage_ratio;	/**< X-machine memory variable leverage_ratio of type double. */
	double cash_deposit_ratio;	/**< X-machine memory variable cash_deposit_ratio of type double. */
	double equity_asset_ratio;	/**< X-machine memory variable equity_asset_ratio of type double. */
	double mean_interest_rate;	/**< X-machine memory variable mean_interest_rate of type double. */
	double sum_new_interest_rates_in_calendar_month;	/**< X-machine memory variable sum_new_interest_rates_in_calendar_month of type double. */
	int no_new_loans_in_calendar_month;	/**< X-machine memory variable no_new_loans_in_calendar_month of type int. */
	double paid_interest_daily;	/**< X-machine memory variable paid_interest_daily of type double. */
	double paid_interest_in_calendar_month;	/**< X-machine memory variable paid_interest_in_calendar_month of type double. */
	double excess_var;	/**< X-machine memory variable excess_var of type double. */
	double excess_liquidity;	/**< X-machine memory variable excess_liquidity of type double. */
	double total_bad_debt_calendar_month;	/**< X-machine memory variable total_bad_debt_calendar_month of type double. */
	bank_balance_sheet_adt bank_balance_sheet_calendar;	/**< X-machine memory variable bank_balance_sheet_calendar of type bank_balance_sheet_adt. */
	bank_stocks_adt bank_stocks_calendar;	/**< X-machine memory variable bank_stocks_calendar of type bank_stocks_adt. */
	bank_outflows_adt bank_outflows_calendar;	/**< X-machine memory variable bank_outflows_calendar of type bank_outflows_adt. */
	bank_inflows_adt bank_inflows_calendar;	/**< X-machine memory variable bank_inflows_calendar of type bank_inflows_adt. */
	double total_income;	/**< X-machine memory variable total_income of type double. */
	double total_expenses;	/**< X-machine memory variable total_expenses of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double total_liabilities;	/**< X-machine memory variable total_liabilities of type double. */
};

/** \struct xmachine_memory_Bank_holder
 * \brief Holds struct of memory of xmachine Bank.
 */
struct xmachine_memory_Bank_holder
{
	/*@dependent@*/ struct xmachine_memory_Bank * agent;	/**< Pointer to X-machine memory Bank. */

	/*@dependent@*/ struct xmachine_memory_Bank_holder * prev;	/**< Pointer to previous Bank agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Bank_holder * next;	/**< Pointer to next Bank agent in the list.  */
};

/** \struct xmachine_memory_Bank_holder
 * \brief Holds struct of memory of xmachine Bank.
 */
struct xmachine_memory_Bank_state
{
	/*@dependent@*/ struct xmachine_memory_Bank_holder * agents;	/**< Pointer to X-machine memory Bank. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Government
 * \brief Holds memory of xmachine Government.
 */
struct xmachine_memory_Government
{
	int id;	/**< X-machine memory variable id of type int. */
	int_array list_of_regions;	/**< X-machine memory variable list_of_regions of type int_array. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	double unemployment_benefit_pct;	/**< X-machine memory variable unemployment_benefit_pct of type double. */
	double gdp_fraction_consumption;	/**< X-machine memory variable gdp_fraction_consumption of type double. */
	double gdp_fraction_investment;	/**< X-machine memory variable gdp_fraction_investment of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_hh_labour;	/**< X-machine memory variable tax_rate_hh_labour of type double. */
	double tax_rate_hh_capital;	/**< X-machine memory variable tax_rate_hh_capital of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double monthly_tax_revenues;	/**< X-machine memory variable monthly_tax_revenues of type double. */
	double yearly_tax_revenues;	/**< X-machine memory variable yearly_tax_revenues of type double. */
	double debt_gdp_ratio;	/**< X-machine memory variable debt_gdp_ratio of type double. */
	adt_gov_inflows_outflows_array gov_inflows_outflows;	/**< X-machine memory variable gov_inflows_outflows of type adt_gov_inflows_outflows_array. */
	double monthly_benefit_payment;	/**< X-machine memory variable monthly_benefit_payment of type double. */
	double minimum_wage_pct;	/**< X-machine memory variable minimum_wage_pct of type double. */
	double gov_monthly_consumption_budget;	/**< X-machine memory variable gov_monthly_consumption_budget of type double. */
	double yearly_benefit_payment;	/**< X-machine memory variable yearly_benefit_payment of type double. */
	double hh_transfer_payment;	/**< X-machine memory variable hh_transfer_payment of type double. */
	double firm_transfer_payment;	/**< X-machine memory variable firm_transfer_payment of type double. */
	double monthly_transfer_payment;	/**< X-machine memory variable monthly_transfer_payment of type double. */
	double yearly_transfer_payment;	/**< X-machine memory variable yearly_transfer_payment of type double. */
	double hh_subsidy_pct;	/**< X-machine memory variable hh_subsidy_pct of type double. */
	double firm_subsidy_pct;	/**< X-machine memory variable firm_subsidy_pct of type double. */
	int regional_firm_subsidy;	/**< X-machine memory variable regional_firm_subsidy of type int. */
	int subsidy_flag;	/**< X-machine memory variable subsidy_flag of type int. */
	double gov_interest_rate;	/**< X-machine memory variable gov_interest_rate of type double. */
	double monthly_bond_interest_payment;	/**< X-machine memory variable monthly_bond_interest_payment of type double. */
	double monthly_subsidy_payment;	/**< X-machine memory variable monthly_subsidy_payment of type double. */
	double monthly_subsidy_payment_to_households;	/**< X-machine memory variable monthly_subsidy_payment_to_households of type double. */
	double monthly_subsidy_payment_to_firms;	/**< X-machine memory variable monthly_subsidy_payment_to_firms of type double. */
	int austerity_phase;	/**< X-machine memory variable austerity_phase of type int. */
	double monthly_consumption_expenditure;	/**< X-machine memory variable monthly_consumption_expenditure of type double. */
	double foreign_debt;	/**< X-machine memory variable foreign_debt of type double. */
	double add_foreign_debt;	/**< X-machine memory variable add_foreign_debt of type double. */
	double foreign_debt_installment;	/**< X-machine memory variable foreign_debt_installment of type double. */
	double monthly_investment_expenditure;	/**< X-machine memory variable monthly_investment_expenditure of type double. */
	double monthly_budget_balance;	/**< X-machine memory variable monthly_budget_balance of type double. */
	double monthly_gdp;	/**< X-machine memory variable monthly_gdp of type double. */
	double_array last_monthly_gdps;	/**< X-machine memory variable last_monthly_gdps of type double_array. */
	double monthly_budget_balance_gdp_fraction;	/**< X-machine memory variable monthly_budget_balance_gdp_fraction of type double. */
	double monthly_consumption_budget;	/**< X-machine memory variable monthly_consumption_budget of type double. */
	double monthly_investment_budget;	/**< X-machine memory variable monthly_investment_budget of type double. */
	double monthly_income;	/**< X-machine memory variable monthly_income of type double. */
	double monthly_expenditure;	/**< X-machine memory variable monthly_expenditure of type double. */
	double yearly_subsidy_payment;	/**< X-machine memory variable yearly_subsidy_payment of type double. */
	double yearly_bond_interest_payment;	/**< X-machine memory variable yearly_bond_interest_payment of type double. */
	double yearly_investment_expenditure;	/**< X-machine memory variable yearly_investment_expenditure of type double. */
	double yearly_consumption_expenditure;	/**< X-machine memory variable yearly_consumption_expenditure of type double. */
	double yearly_income;	/**< X-machine memory variable yearly_income of type double. */
	double yearly_expenditure;	/**< X-machine memory variable yearly_expenditure of type double. */
	double subsidy_transfer_received;	/**< X-machine memory variable subsidy_transfer_received of type double. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double yearly_budget_balance;	/**< X-machine memory variable yearly_budget_balance of type double. */
	double total_money_financing;	/**< X-machine memory variable total_money_financing of type double. */
	double total_bond_financing;	/**< X-machine memory variable total_bond_financing of type double. */
	double country_wide_mean_wage;	/**< X-machine memory variable country_wide_mean_wage of type double. */
	int num_unemployed;	/**< X-machine memory variable num_unemployed of type int. */
	double yearly_gdp;	/**< X-machine memory variable yearly_gdp of type double. */
	double previous_year_gdp;	/**< X-machine memory variable previous_year_gdp of type double. */
	double subsidy_reported_to_eurostat;	/**< X-machine memory variable subsidy_reported_to_eurostat of type double. */
	double gdp_growth;	/**< X-machine memory variable gdp_growth of type double. */
	double gdp_forecast;	/**< X-machine memory variable gdp_forecast of type double. */
	double yearly_income_forecast;	/**< X-machine memory variable yearly_income_forecast of type double. */
	double yearly_expenditure_budget;	/**< X-machine memory variable yearly_expenditure_budget of type double. */
	double budget_balance_forecast;	/**< X-machine memory variable budget_balance_forecast of type double. */
	ordered_quantity_array ordered_quantities;	/**< X-machine memory variable ordered_quantities of type ordered_quantity_array. */
	received_quantities_array gov_received_quantities;	/**< X-machine memory variable gov_received_quantities of type received_quantities_array. */
	double_array consumption_budgets_per_capita;	/**< X-machine memory variable consumption_budgets_per_capita of type double_array. */
	double av_consumption_budget_per_capita;	/**< X-machine memory variable av_consumption_budget_per_capita of type double. */
	double_array consumption_quotas_rel_to_reg1;	/**< X-machine memory variable consumption_quotas_rel_to_reg1 of type double_array. */
	double av_consumption_quota_rel_to_reg1;	/**< X-machine memory variable av_consumption_quota_rel_to_reg1 of type double. */
	double yearly_consumption_budget;	/**< X-machine memory variable yearly_consumption_budget of type double. */
	double yearly_investment_budget;	/**< X-machine memory variable yearly_investment_budget of type double. */
	double yearly_budget_balance_gdp_fraction;	/**< X-machine memory variable yearly_budget_balance_gdp_fraction of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double total_liabilities;	/**< X-machine memory variable total_liabilities of type double. */
	double cumulated_deficit;	/**< X-machine memory variable cumulated_deficit of type double. */
	double inflation_rate;	/**< X-machine memory variable inflation_rate of type double. */
	double unemployment_rate;	/**< X-machine memory variable unemployment_rate of type double. */
	int human_capital_policy_installation_date_in_years;	/**< X-machine memory variable human_capital_policy_installation_date_in_years of type int. */
	int human_capital_policy_flag;	/**< X-machine memory variable human_capital_policy_flag of type int. */
	double basic_security_benefits_pct;	/**< X-machine memory variable basic_security_benefits_pct of type double. */
	double basic_security_benefits;	/**< X-machine memory variable basic_security_benefits of type double. */
	adt_skill_distribution_array new_skill_distribution;	/**< X-machine memory variable new_skill_distribution of type adt_skill_distribution_array. */
	double minimum_wage;	/**< X-machine memory variable minimum_wage of type double. */
	int_array all_region_ids;	/**< X-machine memory variable all_region_ids of type int_array. */
	int_array all_gov_ids;	/**< X-machine memory variable all_gov_ids of type int_array. */
	gov_balance_sheet_adt gov_balance_sheet_calendar;	/**< X-machine memory variable gov_balance_sheet_calendar of type gov_balance_sheet_adt. */
	gov_stocks_adt gov_stocks_calendar;	/**< X-machine memory variable gov_stocks_calendar of type gov_stocks_adt. */
	gov_outflows_adt gov_outflows_calendar;	/**< X-machine memory variable gov_outflows_calendar of type gov_outflows_adt. */
	gov_inflows_adt gov_inflows_calendar;	/**< X-machine memory variable gov_inflows_calendar of type gov_inflows_adt. */
};

/** \struct xmachine_memory_Government_holder
 * \brief Holds struct of memory of xmachine Government.
 */
struct xmachine_memory_Government_holder
{
	/*@dependent@*/ struct xmachine_memory_Government * agent;	/**< Pointer to X-machine memory Government. */

	/*@dependent@*/ struct xmachine_memory_Government_holder * prev;	/**< Pointer to previous Government agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Government_holder * next;	/**< Pointer to next Government agent in the list.  */
};

/** \struct xmachine_memory_Government_holder
 * \brief Holds struct of memory of xmachine Government.
 */
struct xmachine_memory_Government_state
{
	/*@dependent@*/ struct xmachine_memory_Government_holder * agents;	/**< Pointer to X-machine memory Government. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_CentralBank
 * \brief Holds memory of xmachine CentralBank.
 */
struct xmachine_memory_CentralBank
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double dividend_payment;	/**< X-machine memory variable dividend_payment of type double. */
	double fiat_money;	/**< X-machine memory variable fiat_money of type double. */
	double fiat_money_banks;	/**< X-machine memory variable fiat_money_banks of type double. */
	double ecb_deposits;	/**< X-machine memory variable ecb_deposits of type double. */
	account_item_array accounts_banks;	/**< X-machine memory variable accounts_banks of type account_item_array. */
	account_item_array accounts_govs;	/**< X-machine memory variable accounts_govs of type account_item_array. */
	account_item_array government_national_accounts;	/**< X-machine memory variable government_national_accounts of type account_item_array. */
	double cash;	/**< X-machine memory variable cash of type double. */
	ecb_balance_sheet_adt ecb_balance_sheet_calendar;	/**< X-machine memory variable ecb_balance_sheet_calendar of type ecb_balance_sheet_adt. */
	ecb_stocks_adt ecb_stocks_calendar;	/**< X-machine memory variable ecb_stocks_calendar of type ecb_stocks_adt. */
	ecb_outflows_adt ecb_outflows_calendar;	/**< X-machine memory variable ecb_outflows_calendar of type ecb_outflows_adt. */
	ecb_inflows_adt ecb_inflows_calendar;	/**< X-machine memory variable ecb_inflows_calendar of type ecb_inflows_adt. */
	double bond_holdings_value;	/**< X-machine memory variable bond_holdings_value of type double. */
	int nr_gov_bonds;	/**< X-machine memory variable nr_gov_bonds of type int. */
	double fiat_money_govs;	/**< X-machine memory variable fiat_money_govs of type double. */
	double fiat_money_bond_govs;	/**< X-machine memory variable fiat_money_bond_govs of type double. */
	double bank_interest;	/**< X-machine memory variable bank_interest of type double. */
	double gov_interest;	/**< X-machine memory variable gov_interest of type double. */
	double gov_bond_purchase;	/**< X-machine memory variable gov_bond_purchase of type double. */
	double total_income;	/**< X-machine memory variable total_income of type double. */
	double total_expenses;	/**< X-machine memory variable total_expenses of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double total_liabilities;	/**< X-machine memory variable total_liabilities of type double. */
};

/** \struct xmachine_memory_CentralBank_holder
 * \brief Holds struct of memory of xmachine CentralBank.
 */
struct xmachine_memory_CentralBank_holder
{
	/*@dependent@*/ struct xmachine_memory_CentralBank * agent;	/**< Pointer to X-machine memory CentralBank. */

	/*@dependent@*/ struct xmachine_memory_CentralBank_holder * prev;	/**< Pointer to previous CentralBank agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_CentralBank_holder * next;	/**< Pointer to next CentralBank agent in the list.  */
};

/** \struct xmachine_memory_CentralBank_holder
 * \brief Holds struct of memory of xmachine CentralBank.
 */
struct xmachine_memory_CentralBank_state
{
	/*@dependent@*/ struct xmachine_memory_CentralBank_holder * agents;	/**< Pointer to X-machine memory CentralBank. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_ClearingHouse
 * \brief Holds memory of xmachine ClearingHouse.
 */
struct xmachine_memory_ClearingHouse
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int partition_id;	/**< X-machine memory variable partition_id of type int. */
	order_array pending_orders;	/**< X-machine memory variable pending_orders of type order_array. */
	order_array processed_orders;	/**< X-machine memory variable processed_orders of type order_array. */
	index_adt stock_index;	/**< X-machine memory variable stock_index of type index_adt. */
	double dsratio;	/**< X-machine memory variable dsratio of type double. */
	double_array random_numbers_normal;	/**< X-machine memory variable random_numbers_normal of type double_array. */
	double monthly_counter_total_dividend;	/**< X-machine memory variable monthly_counter_total_dividend of type double. */
	double stock_index_price;	/**< X-machine memory variable stock_index_price of type double. */
};

/** \struct xmachine_memory_ClearingHouse_holder
 * \brief Holds struct of memory of xmachine ClearingHouse.
 */
struct xmachine_memory_ClearingHouse_holder
{
	/*@dependent@*/ struct xmachine_memory_ClearingHouse * agent;	/**< Pointer to X-machine memory ClearingHouse. */

	/*@dependent@*/ struct xmachine_memory_ClearingHouse_holder * prev;	/**< Pointer to previous ClearingHouse agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_ClearingHouse_holder * next;	/**< Pointer to next ClearingHouse agent in the list.  */
};

/** \struct xmachine_memory_ClearingHouse_holder
 * \brief Holds struct of memory of xmachine ClearingHouse.
 */
struct xmachine_memory_ClearingHouse_state
{
	/*@dependent@*/ struct xmachine_memory_ClearingHouse_holder * agents;	/**< Pointer to X-machine memory ClearingHouse. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Firm * xmachine_Firm;	/**< Pointer to X-machine memory of type Firm.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Household * xmachine_Household;	/**< Pointer to X-machine memory of type Household.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Mall * xmachine_Mall;	/**< Pointer to X-machine memory of type Mall.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_IGFirm * xmachine_IGFirm;	/**< Pointer to X-machine memory of type IGFirm.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Eurostat * xmachine_Eurostat;	/**< Pointer to X-machine memory of type Eurostat.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Bank * xmachine_Bank;	/**< Pointer to X-machine memory of type Bank.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Government * xmachine_Government;	/**< Pointer to X-machine memory of type Government.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_CentralBank * xmachine_CentralBank;	/**< Pointer to X-machine memory of type CentralBank.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_ClearingHouse * xmachine_ClearingHouse;	/**< Pointer to X-machine memory of type ClearingHouse.  */
};

/** \var void* FLAME_m_bank_account_update_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bank_account_update_composite_params;

/** \struct m_bank_account_update
 * \brief Holds message of type bank_account_update_message.
 */
struct m_bank_account_update
{
	int id;	/**< Message memory variable id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double payment_account;	/**< Message memory variable payment_account of type double. */
};

/** \var void* FLAME_m_bank_to_central_bank_account_update_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bank_to_central_bank_account_update_composite_params;

/** \struct m_bank_to_central_bank_account_update
 * \brief Holds message of type bank_to_central_bank_account_update_message.
 */
struct m_bank_to_central_bank_account_update
{
	int id;	/**< Message memory variable id of type int. */
	double payment_account;	/**< Message memory variable payment_account of type double. */
	double ecb_debt;	/**< Message memory variable ecb_debt of type double. */
};

/** \var void* FLAME_m_gov_to_central_bank_account_update_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_gov_to_central_bank_account_update_composite_params;

/** \struct m_gov_to_central_bank_account_update
 * \brief Holds message of type gov_to_central_bank_account_update_message.
 */
struct m_gov_to_central_bank_account_update
{
	int id;	/**< Message memory variable id of type int. */
	double payment_account;	/**< Message memory variable payment_account of type double. */
	double gdp;	/**< Message memory variable gdp of type double. */
};

/** \var void* FLAME_m_wage_payment_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_wage_payment_composite_params;

/** \struct m_wage_payment
 * \brief Holds message of type wage_payment_message.
 */
struct m_wage_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double payment;	/**< Message memory variable payment of type double. */
	double productivity;	/**< Message memory variable productivity of type double. */
	double average_specific_skills;	/**< Message memory variable average_specific_skills of type double. */
	int employer_igfirm;	/**< Message memory variable employer_igfirm of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
};

/** \var void* FLAME_m_quality_price_info_1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_quality_price_info_1_composite_params;

/** \struct m_quality_price_info_1
 * \brief Holds message of type quality_price_info_1_message.
 */
struct m_quality_price_info_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int mall_region_id;	/**< Message memory variable mall_region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int firm_region_id;	/**< Message memory variable firm_region_id of type int. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	int available;	/**< Message memory variable available of type int. */
};

/** \var void* FLAME_m_quality_price_info_2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_quality_price_info_2_composite_params;

/** \struct m_quality_price_info_2
 * \brief Holds message of type quality_price_info_2_message.
 */
struct m_quality_price_info_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int mall_region_id;	/**< Message memory variable mall_region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int firm_region_id;	/**< Message memory variable firm_region_id of type int. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	int available;	/**< Message memory variable available of type int. */
};

/** \var void* FLAME_m_update_mall_stock_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_update_mall_stock_composite_params;

/** \struct m_update_mall_stock
 * \brief Holds message of type update_mall_stock_message.
 */
struct m_update_mall_stock
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int firm_region_id;	/**< Message memory variable firm_region_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	double previous_price;	/**< Message memory variable previous_price of type double. */
};

/** \var void* FLAME_m_consumption_request_1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_consumption_request_1_composite_params;

/** \struct m_consumption_request_1
 * \brief Holds message of type consumption_request_1_message.
 */
struct m_consumption_request_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
};

/** \var void* FLAME_m_consumption_request_2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_consumption_request_2_composite_params;

/** \struct m_consumption_request_2
 * \brief Holds message of type consumption_request_2_message.
 */
struct m_consumption_request_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
};

/** \var void* FLAME_m_accepted_consumption_1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_accepted_consumption_1_composite_params;

/** \struct m_accepted_consumption_1
 * \brief Holds message of type accepted_consumption_1_message.
 */
struct m_accepted_consumption_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int household_id;	/**< Message memory variable household_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double offered_consumption_volume;	/**< Message memory variable offered_consumption_volume of type double. */
	int rationed;	/**< Message memory variable rationed of type int. */
};

/** \var void* FLAME_m_accepted_consumption_2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_accepted_consumption_2_composite_params;

/** \struct m_accepted_consumption_2
 * \brief Holds message of type accepted_consumption_2_message.
 */
struct m_accepted_consumption_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int household_id;	/**< Message memory variable household_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double offered_consumption_volume;	/**< Message memory variable offered_consumption_volume of type double. */
	int rationed;	/**< Message memory variable rationed of type int. */
};

/** \var void* FLAME_m_sales_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_sales_composite_params;

/** \struct m_sales
 * \brief Holds message of type sales_message.
 */
struct m_sales
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double revenue;	/**< Message memory variable revenue of type double. */
	int stock_empty;	/**< Message memory variable stock_empty of type int. */
	double current_stock;	/**< Message memory variable current_stock of type double. */
};

/** \var void* FLAME_m_specific_skill_update_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_specific_skill_update_composite_params;

/** \struct m_specific_skill_update
 * \brief Holds message of type specific_skill_update_message.
 */
struct m_specific_skill_update
{
	int id;	/**< Message memory variable id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double specific_skills;	/**< Message memory variable specific_skills of type double. */
	int general_skills;	/**< Message memory variable general_skills of type int. */
};

/** \var void* FLAME_m_policy_rate_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_policy_rate_composite_params;

/** \struct m_policy_rate
 * \brief Holds message of type policy_rate_message.
 */
struct m_policy_rate
{
	double policy_rate_value;	/**< Message memory variable policy_rate_value of type double. */
};

/** \var void* FLAME_m_bank_identity_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bank_identity_composite_params;

/** \struct m_bank_identity
 * \brief Holds message of type bank_identity_message.
 */
struct m_bank_identity
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
};

/** \var void* FLAME_m_loan_request_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_request_composite_params;

/** \struct m_loan_request
 * \brief Holds message of type loan_request_message.
 */
struct m_loan_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double equity;	/**< Message memory variable equity of type double. */
	double total_debt;	/**< Message memory variable total_debt of type double. */
	double external_financial_needs;	/**< Message memory variable external_financial_needs of type double. */
};

/** \var void* FLAME_m_loan_request_ranked_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_request_ranked_composite_params;

/** \struct m_loan_request_ranked
 * \brief Holds message of type loan_request_ranked_message.
 */
struct m_loan_request_ranked
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double equity;	/**< Message memory variable equity of type double. */
	double total_debt;	/**< Message memory variable total_debt of type double. */
	double credit_request;	/**< Message memory variable credit_request of type double. */
	double value_at_risk_request;	/**< Message memory variable value_at_risk_request of type double. */
};

/** \var void* FLAME_m_loan_conditions_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_conditions_composite_params;

/** \struct m_loan_conditions
 * \brief Holds message of type loan_conditions_message.
 */
struct m_loan_conditions
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double proposed_interest_rate;	/**< Message memory variable proposed_interest_rate of type double. */
	double amount_offered_credit;	/**< Message memory variable amount_offered_credit of type double. */
	double value_at_risk;	/**< Message memory variable value_at_risk of type double. */
};

/** \var void* FLAME_m_loan_acceptance_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_acceptance_composite_params;

/** \struct m_loan_acceptance
 * \brief Holds message of type loan_acceptance_message.
 */
struct m_loan_acceptance
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double credit_amount_taken;	/**< Message memory variable credit_amount_taken of type double. */
	double loan_total_var;	/**< Message memory variable loan_total_var of type double. */
	double interest_rate;	/**< Message memory variable interest_rate of type double. */
};

/** \var void* FLAME_m_installment_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_installment_composite_params;

/** \struct m_installment
 * \brief Holds message of type installment_message.
 */
struct m_installment
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double installment_amount;	/**< Message memory variable installment_amount of type double. */
	double interest_amount;	/**< Message memory variable interest_amount of type double. */
	double var_per_installment;	/**< Message memory variable var_per_installment of type double. */
	double total_var;	/**< Message memory variable total_var of type double. */
};

/** \var void* FLAME_m_bankruptcy_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bankruptcy_composite_params;

/** \struct m_bankruptcy
 * \brief Holds message of type bankruptcy_message.
 */
struct m_bankruptcy
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double bad_debt;	/**< Message memory variable bad_debt of type double. */
	double credit_refunded;	/**< Message memory variable credit_refunded of type double. */
	double writeoff_var;	/**< Message memory variable writeoff_var of type double. */
};

/** \var void* FLAME_m_bank_interest_payment_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bank_interest_payment_composite_params;

/** \struct m_bank_interest_payment
 * \brief Holds message of type bank_interest_payment_message.
 */
struct m_bank_interest_payment
{
	double bank_interest_amount;	/**< Message memory variable bank_interest_amount of type double. */
};

/** \var void* FLAME_m_account_interest_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_account_interest_composite_params;

/** \struct m_account_interest
 * \brief Holds message of type account_interest_message.
 */
struct m_account_interest
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double interest_rate;	/**< Message memory variable interest_rate of type double. */
};

/** \var void* FLAME_m_ecb_dividend_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_ecb_dividend_composite_params;

/** \struct m_ecb_dividend
 * \brief Holds message of type ecb_dividend_message.
 */
struct m_ecb_dividend
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double dividend_per_gov;	/**< Message memory variable dividend_per_gov of type double. */
};

/** \var void* FLAME_m_credit_var_update_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_credit_var_update_composite_params;

/** \struct m_credit_var_update
 * \brief Holds message of type credit_var_update_message.
 */
struct m_credit_var_update
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double value_at_risk;	/**< Message memory variable value_at_risk of type double. */
};

/** \var void* FLAME_m_bankruptcy_illiquidity_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bankruptcy_illiquidity_composite_params;

/** \struct m_bankruptcy_illiquidity
 * \brief Holds message of type bankruptcy_illiquidity_message.
 */
struct m_bankruptcy_illiquidity
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \var void* FLAME_m_bankruptcy_insolvency_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bankruptcy_insolvency_composite_params;

/** \struct m_bankruptcy_insolvency
 * \brief Holds message of type bankruptcy_insolvency_message.
 */
struct m_bankruptcy_insolvency
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \var void* FLAME_m_index_info_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_index_info_composite_params;

/** \struct m_index_info
 * \brief Holds message of type index_info_message.
 */
struct m_index_info
{
	double dividend_per_share;	/**< Message memory variable dividend_per_share of type double. */
};

/** \var void* FLAME_m_index_price_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_index_price_composite_params;

/** \struct m_index_price
 * \brief Holds message of type index_price_message.
 */
struct m_index_price
{
	double price;	/**< Message memory variable price of type double. */
	double moving_avg_price;	/**< Message memory variable moving_avg_price of type double. */
};

/** \var void* FLAME_m_order_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_order_composite_params;

/** \struct m_order
 * \brief Holds message of type order_message.
 */
struct m_order
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	double value;	/**< Message memory variable value of type double. */
};

/** \var void* FLAME_m_order_status_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_order_status_composite_params;

/** \struct m_order_status
 * \brief Holds message of type order_status_message.
 */
struct m_order_status
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	double value;	/**< Message memory variable value of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
};

/** \var void* FLAME_m_dividend_info_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_dividend_info_composite_params;

/** \struct m_dividend_info
 * \brief Holds message of type dividend_info_message.
 */
struct m_dividend_info
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double total_dividend;	/**< Message memory variable total_dividend of type double. */
};

/** \var void* FLAME_m_productivity_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_productivity_composite_params;

/** \struct m_productivity
 * \brief Holds message of type productivity_message.
 */
struct m_productivity
{
	int IGfirm_id;	/**< Message memory variable IGfirm_id of type int. */
	double cap_productivity;	/**< Message memory variable cap_productivity of type double. */
	double cap_good_price;	/**< Message memory variable cap_good_price of type double. */
};

/** \var void* FLAME_m_capital_good_request_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_capital_good_request_composite_params;

/** \struct m_capital_good_request
 * \brief Holds message of type capital_good_request_message.
 */
struct m_capital_good_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_good_demand;	/**< Message memory variable capital_good_demand of type double. */
	int vintage;	/**< Message memory variable vintage of type int. */
};

/** \var void* FLAME_m_capital_good_delivery_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_capital_good_delivery_composite_params;

/** \struct m_capital_good_delivery
 * \brief Holds message of type capital_good_delivery_message.
 */
struct m_capital_good_delivery
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_good_delivery_volume;	/**< Message memory variable capital_good_delivery_volume of type double. */
	double productivity;	/**< Message memory variable productivity of type double. */
	double capital_good_price;	/**< Message memory variable capital_good_price of type double. */
};

/** \var void* FLAME_m_pay_capital_goods_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_pay_capital_goods_composite_params;

/** \struct m_pay_capital_goods
 * \brief Holds message of type pay_capital_goods_message.
 */
struct m_pay_capital_goods
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_bill;	/**< Message memory variable capital_bill of type double. */
};

/** \var void* FLAME_m_vacancies_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_vacancies_composite_params;

/** \struct m_vacancies
 * \brief Holds message of type vacancies_message.
 */
struct m_vacancies
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double firm_wage_offer_for_skill_1;	/**< Message memory variable firm_wage_offer_for_skill_1 of type double. */
	double firm_wage_offer_for_skill_2;	/**< Message memory variable firm_wage_offer_for_skill_2 of type double. */
	double firm_wage_offer_for_skill_3;	/**< Message memory variable firm_wage_offer_for_skill_3 of type double. */
	double firm_wage_offer_for_skill_4;	/**< Message memory variable firm_wage_offer_for_skill_4 of type double. */
	double firm_wage_offer_for_skill_5;	/**< Message memory variable firm_wage_offer_for_skill_5 of type double. */
};

/** \var void* FLAME_m_vacancies2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_vacancies2_composite_params;

/** \struct m_vacancies2
 * \brief Holds message of type vacancies2_message.
 */
struct m_vacancies2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double firm_wage_offer_for_skill_1;	/**< Message memory variable firm_wage_offer_for_skill_1 of type double. */
	double firm_wage_offer_for_skill_2;	/**< Message memory variable firm_wage_offer_for_skill_2 of type double. */
	double firm_wage_offer_for_skill_3;	/**< Message memory variable firm_wage_offer_for_skill_3 of type double. */
	double firm_wage_offer_for_skill_4;	/**< Message memory variable firm_wage_offer_for_skill_4 of type double. */
	double firm_wage_offer_for_skill_5;	/**< Message memory variable firm_wage_offer_for_skill_5 of type double. */
};

/** \var void* FLAME_m_vacancies_r_and_d_employees_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_vacancies_r_and_d_employees_composite_params;

/** \struct m_vacancies_r_and_d_employees
 * \brief Holds message of type vacancies_r_and_d_employees_message.
 */
struct m_vacancies_r_and_d_employees
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double firm_wage_offer;	/**< Message memory variable firm_wage_offer of type double. */
};

/** \var void* FLAME_m_vacancies_r_and_d_employees2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_vacancies_r_and_d_employees2_composite_params;

/** \struct m_vacancies_r_and_d_employees2
 * \brief Holds message of type vacancies_r_and_d_employees2_message.
 */
struct m_vacancies_r_and_d_employees2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double firm_wage_offer;	/**< Message memory variable firm_wage_offer of type double. */
};

/** \var void* FLAME_m_firing_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_firing_composite_params;

/** \struct m_firing
 * \brief Holds message of type firing_message.
 */
struct m_firing
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
};

/** \var void* FLAME_m_job_application_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_application_composite_params;

/** \struct m_job_application
 * \brief Holds message of type job_application_message.
 */
struct m_job_application
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	int job_type;	/**< Message memory variable job_type of type int. */
};

/** \var void* FLAME_m_job_application2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_application2_composite_params;

/** \struct m_job_application2
 * \brief Holds message of type job_application2_message.
 */
struct m_job_application2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	int job_type;	/**< Message memory variable job_type of type int. */
};

/** \var void* FLAME_m_job_offer_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_offer_composite_params;

/** \struct m_job_offer
 * \brief Holds message of type job_offer_message.
 */
struct m_job_offer
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double wage_offer;	/**< Message memory variable wage_offer of type double. */
	int job_type;	/**< Message memory variable job_type of type int. */
};

/** \var void* FLAME_m_job_offer2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_offer2_composite_params;

/** \struct m_job_offer2
 * \brief Holds message of type job_offer2_message.
 */
struct m_job_offer2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double wage_offer;	/**< Message memory variable wage_offer of type double. */
	int job_type;	/**< Message memory variable job_type of type int. */
};

/** \var void* FLAME_m_job_acceptance_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_acceptance_composite_params;

/** \struct m_job_acceptance
 * \brief Holds message of type job_acceptance_message.
 */
struct m_job_acceptance
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	int job_type;	/**< Message memory variable job_type of type int. */
};

/** \var void* FLAME_m_job_acceptance2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_acceptance2_composite_params;

/** \struct m_job_acceptance2
 * \brief Holds message of type job_acceptance2_message.
 */
struct m_job_acceptance2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	int job_type;	/**< Message memory variable job_type of type int. */
};

/** \var void* FLAME_m_quitting_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_quitting_composite_params;

/** \struct m_quitting
 * \brief Holds message of type quitting_message.
 */
struct m_quitting
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \var void* FLAME_m_quitting2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_quitting2_composite_params;

/** \struct m_quitting2
 * \brief Holds message of type quitting2_message.
 */
struct m_quitting2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \var void* FLAME_m_unemployment_notification_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_unemployment_notification_composite_params;

/** \struct m_unemployment_notification
 * \brief Holds message of type unemployment_notification_message.
 */
struct m_unemployment_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double unemployment_payment;	/**< Message memory variable unemployment_payment of type double. */
};

/** \var void* FLAME_m_policy_announcement_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_policy_announcement_composite_params;

/** \struct m_policy_announcement
 * \brief Holds message of type policy_announcement_message.
 */
struct m_policy_announcement
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_rate_corporate;	/**< Message memory variable tax_rate_corporate of type double. */
	double tax_rate_hh_labour;	/**< Message memory variable tax_rate_hh_labour of type double. */
	double tax_rate_hh_capital;	/**< Message memory variable tax_rate_hh_capital of type double. */
	double tax_rate_vat;	/**< Message memory variable tax_rate_vat of type double. */
	double unemployment_benefit_pct;	/**< Message memory variable unemployment_benefit_pct of type double. */
	double hh_subsidy_pct;	/**< Message memory variable hh_subsidy_pct of type double. */
	double firm_subsidy_pct;	/**< Message memory variable firm_subsidy_pct of type double. */
	double hh_transfer_payment;	/**< Message memory variable hh_transfer_payment of type double. */
	double firm_transfer_payment;	/**< Message memory variable firm_transfer_payment of type double. */
	double minimum_wage;	/**< Message memory variable minimum_wage of type double. */
	double basic_security_benefits;	/**< Message memory variable basic_security_benefits of type double. */
};

/** \var void* FLAME_m_tax_payment_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_tax_payment_composite_params;

/** \struct m_tax_payment
 * \brief Holds message of type tax_payment_message.
 */
struct m_tax_payment
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_payment;	/**< Message memory variable tax_payment of type double. */
};

/** \var void* FLAME_m_unemployment_benefit_restitution_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_unemployment_benefit_restitution_composite_params;

/** \struct m_unemployment_benefit_restitution
 * \brief Holds message of type unemployment_benefit_restitution_message.
 */
struct m_unemployment_benefit_restitution
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double restitution_payment;	/**< Message memory variable restitution_payment of type double. */
};

/** \var void* FLAME_m_hh_transfer_notification_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_hh_transfer_notification_composite_params;

/** \struct m_hh_transfer_notification
 * \brief Holds message of type hh_transfer_notification_message.
 */
struct m_hh_transfer_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \var void* FLAME_m_hh_subsidy_notification_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_hh_subsidy_notification_composite_params;

/** \struct m_hh_subsidy_notification
 * \brief Holds message of type hh_subsidy_notification_message.
 */
struct m_hh_subsidy_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double subsidy_payment;	/**< Message memory variable subsidy_payment of type double. */
};

/** \var void* FLAME_m_human_capital_policy_announcement_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_human_capital_policy_announcement_composite_params;

/** \struct m_human_capital_policy_announcement
 * \brief Holds message of type human_capital_policy_announcement_message.
 */
struct m_human_capital_policy_announcement
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	int announcement;	/**< Message memory variable announcement of type int. */
};

/** \var void* FLAME_m_firm_transfer_notification_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_firm_transfer_notification_composite_params;

/** \struct m_firm_transfer_notification
 * \brief Holds message of type firm_transfer_notification_message.
 */
struct m_firm_transfer_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \var void* FLAME_m_firm_subsidy_notification_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_firm_subsidy_notification_composite_params;

/** \struct m_firm_subsidy_notification
 * \brief Holds message of type firm_subsidy_notification_message.
 */
struct m_firm_subsidy_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double subsidy_payment;	/**< Message memory variable subsidy_payment of type double. */
};

/** \var void* FLAME_m_request_fiat_money_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_request_fiat_money_composite_params;

/** \struct m_request_fiat_money
 * \brief Holds message of type request_fiat_money_message.
 */
struct m_request_fiat_money
{
	double nominal_value;	/**< Message memory variable nominal_value of type double. */
};

/** \var void* FLAME_m_human_capital_policy_general_skill_information_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_human_capital_policy_general_skill_information_composite_params;

/** \struct m_human_capital_policy_general_skill_information
 * \brief Holds message of type human_capital_policy_general_skill_information_message.
 */
struct m_human_capital_policy_general_skill_information
{
	int id;	/**< Message memory variable id of type int. */
	int gov_id;	/**< Message memory variable gov_id of type int. */
	int general_skills;	/**< Message memory variable general_skills of type int. */
};

/** \var void* FLAME_m_human_capital_policy_new_general_skill_notification_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_human_capital_policy_new_general_skill_notification_composite_params;

/** \struct m_human_capital_policy_new_general_skill_notification
 * \brief Holds message of type human_capital_policy_new_general_skill_notification_message.
 */
struct m_human_capital_policy_new_general_skill_notification
{
	int id;	/**< Message memory variable id of type int. */
	int gov_id;	/**< Message memory variable gov_id of type int. */
	int general_skills;	/**< Message memory variable general_skills of type int. */
};

/** \var void* FLAME_m_firm_send_data_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_firm_send_data_composite_params;

/** \struct m_firm_send_data
 * \brief Holds message of type firm_send_data_message.
 */
struct m_firm_send_data
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int vacancies;	/**< Message memory variable vacancies of type int. */
	int posted_vacancies;	/**< Message memory variable posted_vacancies of type int. */
	int employees;	/**< Message memory variable employees of type int. */
	int employees_skill_1;	/**< Message memory variable employees_skill_1 of type int. */
	int employees_skill_2;	/**< Message memory variable employees_skill_2 of type int. */
	int employees_skill_3;	/**< Message memory variable employees_skill_3 of type int. */
	int employees_skill_4;	/**< Message memory variable employees_skill_4 of type int. */
	int employees_skill_5;	/**< Message memory variable employees_skill_5 of type int. */
	int employees_production;	/**< Message memory variable employees_production of type int. */
	int employees_r_and_d;	/**< Message memory variable employees_r_and_d of type int. */
	double average_wage;	/**< Message memory variable average_wage of type double. */
	double average_wage_production;	/**< Message memory variable average_wage_production of type double. */
	double average_wage_r_and_d;	/**< Message memory variable average_wage_r_and_d of type double. */
	double average_s_skill;	/**< Message memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< Message memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< Message memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< Message memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< Message memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< Message memory variable average_s_skill_5 of type double. */
	double cum_revenue;	/**< Message memory variable cum_revenue of type double. */
	double capital_costs;	/**< Message memory variable capital_costs of type double. */
	double net_earnings;	/**< Message memory variable net_earnings of type double. */
	double total_debt;	/**< Message memory variable total_debt of type double. */
	double total_assets;	/**< Message memory variable total_assets of type double. */
	double equity;	/**< Message memory variable equity of type double. */
	double price;	/**< Message memory variable price of type double. */
	double price_last_month;	/**< Message memory variable price_last_month of type double. */
	double quality;	/**< Message memory variable quality of type double. */
	double total_supply;	/**< Message memory variable total_supply of type double. */
	double cum_total_sold_quantity;	/**< Message memory variable cum_total_sold_quantity of type double. */
	double output;	/**< Message memory variable output of type double. */
	double planned_output;	/**< Message memory variable planned_output of type double. */
	int age;	/**< Message memory variable age of type int. */
	double firm_productivity;	/**< Message memory variable firm_productivity of type double. */
	double firm_productivity_progress;	/**< Message memory variable firm_productivity_progress of type double. */
	double value_inventory;	/**< Message memory variable value_inventory of type double. */
	double units_capital_stock;	/**< Message memory variable units_capital_stock of type double. */
	double base_wage_offer;	/**< Message memory variable base_wage_offer of type double. */
	double dividends;	/**< Message memory variable dividends of type double. */
	double used_capital;	/**< Message memory variable used_capital of type double. */
	double technology;	/**< Message memory variable technology of type double. */
	double mark_up;	/**< Message memory variable mark_up of type double. */
	int zero_output_for_longer;	/**< Message memory variable zero_output_for_longer of type int. */
	double unit_labor_costs;	/**< Message memory variable unit_labor_costs of type double. */
};

/** \var void* FLAME_m_government_send_data_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_government_send_data_composite_params;

/** \struct m_government_send_data
 * \brief Holds message of type government_send_data_message.
 */
struct m_government_send_data
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double consumption_expenditures;	/**< Message memory variable consumption_expenditures of type double. */
};

/** \var void* FLAME_m_household_send_data_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_household_send_data_composite_params;

/** \struct m_household_send_data
 * \brief Holds message of type household_send_data_message.
 */
struct m_household_send_data
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	int employment_status;	/**< Message memory variable employment_status of type int. */
	double wage;	/**< Message memory variable wage of type double. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	int just_employed;	/**< Message memory variable just_employed of type int. */
	int just_unemployed;	/**< Message memory variable just_unemployed of type int. */
	int start_employed;	/**< Message memory variable start_employed of type int. */
	int start_unemployed;	/**< Message memory variable start_unemployed of type int. */
	int enter_matching;	/**< Message memory variable enter_matching of type int. */
	int unemployed_duration;	/**< Message memory variable unemployed_duration of type int. */
	double consumption_budget_in_month;	/**< Message memory variable consumption_budget_in_month of type double. */
	double payment_account;	/**< Message memory variable payment_account of type double. */
	double mean_net_income;	/**< Message memory variable mean_net_income of type double. */
	double wealth;	/**< Message memory variable wealth of type double. */
	double dividends;	/**< Message memory variable dividends of type double. */
	double interest_income;	/**< Message memory variable interest_income of type double. */
	double net_inflows_financial_market;	/**< Message memory variable net_inflows_financial_market of type double. */
	double reservation_wage;	/**< Message memory variable reservation_wage of type double. */
};

/** \var void* FLAME_m_mall_data_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_mall_data_composite_params;

/** \struct m_mall_data
 * \brief Holds message of type mall_data_message.
 */
struct m_mall_data
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_region;	/**< Message memory variable firm_region of type int. */
	int household_region;	/**< Message memory variable household_region of type int. */
	double export_volume;	/**< Message memory variable export_volume of type double. */
	double export_value;	/**< Message memory variable export_value of type double. */
	double export_previous_value;	/**< Message memory variable export_previous_value of type double. */
};

/** \var void* FLAME_m_eurostat_send_specific_skills_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_eurostat_send_specific_skills_composite_params;

/** \struct m_eurostat_send_specific_skills
 * \brief Holds message of type eurostat_send_specific_skills_message.
 */
struct m_eurostat_send_specific_skills
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	double specific_skill_1;	/**< Message memory variable specific_skill_1 of type double. */
	double specific_skill_2;	/**< Message memory variable specific_skill_2 of type double. */
	double specific_skill_3;	/**< Message memory variable specific_skill_3 of type double. */
	double specific_skill_4;	/**< Message memory variable specific_skill_4 of type double. */
	double specific_skill_5;	/**< Message memory variable specific_skill_5 of type double. */
	double productivity_progress;	/**< Message memory variable productivity_progress of type double. */
	double average_wage;	/**< Message memory variable average_wage of type double. */
	double vacancy_filling_rate;	/**< Message memory variable vacancy_filling_rate of type double. */
	double average_output;	/**< Message memory variable average_output of type double. */
	double cpi;	/**< Message memory variable cpi of type double. */
	double price_index;	/**< Message memory variable price_index of type double. */
	int no_firms;	/**< Message memory variable no_firms of type int. */
	double average_quality;	/**< Message memory variable average_quality of type double. */
	double average_price;	/**< Message memory variable average_price of type double. */
	double wage_offer;	/**< Message memory variable wage_offer of type double. */
	double technology;	/**< Message memory variable technology of type double. */
};

/** \var void* FLAME_m_data_for_government_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_data_for_government_composite_params;

/** \struct m_data_for_government
 * \brief Holds message of type data_for_government_message.
 */
struct m_data_for_government
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double gdp;	/**< Message memory variable gdp of type double. */
	double mean_wage;	/**< Message memory variable mean_wage of type double. */
	double unemployment_rate;	/**< Message memory variable unemployment_rate of type double. */
	double consumption_quota;	/**< Message memory variable consumption_quota of type double. */
	double consumption_budget_per_capita;	/**< Message memory variable consumption_budget_per_capita of type double. */
};

/** \var void* FLAME_m_eurostat_send_macrodata_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_eurostat_send_macrodata_composite_params;

/** \struct m_eurostat_send_macrodata
 * \brief Holds message of type eurostat_send_macrodata_message.
 */
struct m_eurostat_send_macrodata
{
	double inflation;	/**< Message memory variable inflation of type double. */
	double gdp;	/**< Message memory variable gdp of type double. */
	double unemployment_rate;	/**< Message memory variable unemployment_rate of type double. */
};

/** \var void* FLAME_m_msg_firm_id_to_malls_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_msg_firm_id_to_malls_composite_params;

/** \struct m_msg_firm_id_to_malls
 * \brief Holds message of type msg_firm_id_to_malls_message.
 */
struct m_msg_firm_id_to_malls
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
};

/** \var void* FLAME_m_msg_mall_id_to_firms_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_msg_mall_id_to_firms_composite_params;

/** \struct m_msg_mall_id_to_firms
 * \brief Holds message of type msg_mall_id_to_firms_message.
 */
struct m_msg_mall_id_to_firms
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
};

/** \var void* FLAME_m_msg_skills_eurostat_to_igfirm_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_msg_skills_eurostat_to_igfirm_composite_params;

/** \struct m_msg_skills_eurostat_to_igfirm
 * \brief Holds message of type msg_skills_eurostat_to_igfirm_message.
 */
struct m_msg_skills_eurostat_to_igfirm
{
	double mean_general_skills;	/**< Message memory variable mean_general_skills of type double. */
	double mean_specific_skills;	/**< Message memory variable mean_specific_skills of type double. */
	double productivity_progress;	/**< Message memory variable productivity_progress of type double. */
	double total_capital_stock_units;	/**< Message memory variable total_capital_stock_units of type double. */
};

/** \var void* FLAME_m_msg_market_sizes_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_msg_market_sizes_composite_params;

/** \struct m_msg_market_sizes
 * \brief Holds message of type msg_market_sizes_message.
 */
struct m_msg_market_sizes
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double market_size;	/**< Message memory variable market_size of type double. */
	double government_demand;	/**< Message memory variable government_demand of type double. */
};

/** \var void* FLAME_m_total_subsidies_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_total_subsidies_composite_params;

/** \struct m_total_subsidies
 * \brief Holds message of type total_subsidies_message.
 */
struct m_total_subsidies
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_redistributed_subsidies_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_redistributed_subsidies_composite_params;

/** \struct m_redistributed_subsidies
 * \brief Holds message of type redistributed_subsidies_message.
 */
struct m_redistributed_subsidies
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_quality_price_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_quality_price_composite_params;

/** \struct m_quality_price
 * \brief Holds message of type quality_price_message.
 */
struct m_quality_price
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
};

/** \var void* FLAME_m_interview_request_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_interview_request_composite_params;

/** \struct m_interview_request
 * \brief Holds message of type interview_request_message.
 */
struct m_interview_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \var void* FLAME_m_interview_positive_response_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_interview_positive_response_composite_params;

/** \struct m_interview_positive_response
 * \brief Holds message of type interview_positive_response_message.
 */
struct m_interview_positive_response
{
	int id;	/**< Message memory variable id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \var void* FLAME_m_questionnaire_innovation_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_questionnaire_innovation_composite_params;

/** \struct m_questionnaire_innovation
 * \brief Holds message of type questionnaire_innovation_message.
 */
struct m_questionnaire_innovation
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	price_quality_pair price_quality[12];	/**< Message memory variable price_quality of type price_quality_pair. */
};

/** \var void* FLAME_m_filled_out_questionnaire_product_innovation_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_filled_out_questionnaire_product_innovation_composite_params;

/** \struct m_filled_out_questionnaire_product_innovation
 * \brief Holds message of type filled_out_questionnaire_product_innovation_message.
 */
struct m_filled_out_questionnaire_product_innovation
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int choice;	/**< Message memory variable choice of type int. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm xmachine_memory_Firm;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm_holder xmachine_memory_Firm_holder;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm_state xmachine_memory_Firm_state;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household xmachine_memory_Household;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household_holder xmachine_memory_Household_holder;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household_state xmachine_memory_Household_state;
/** \var typedef xmachine_memory_Mall xmachine_memory_Mall
 * \brief Typedef for xmachine_memory_Mall struct.
 */
typedef struct xmachine_memory_Mall xmachine_memory_Mall;
/** \var typedef xmachine_memory_Mall xmachine_memory_Mall
 * \brief Typedef for xmachine_memory_Mall struct.
 */
typedef struct xmachine_memory_Mall_holder xmachine_memory_Mall_holder;
/** \var typedef xmachine_memory_Mall xmachine_memory_Mall
 * \brief Typedef for xmachine_memory_Mall struct.
 */
typedef struct xmachine_memory_Mall_state xmachine_memory_Mall_state;
/** \var typedef xmachine_memory_IGFirm xmachine_memory_IGFirm
 * \brief Typedef for xmachine_memory_IGFirm struct.
 */
typedef struct xmachine_memory_IGFirm xmachine_memory_IGFirm;
/** \var typedef xmachine_memory_IGFirm xmachine_memory_IGFirm
 * \brief Typedef for xmachine_memory_IGFirm struct.
 */
typedef struct xmachine_memory_IGFirm_holder xmachine_memory_IGFirm_holder;
/** \var typedef xmachine_memory_IGFirm xmachine_memory_IGFirm
 * \brief Typedef for xmachine_memory_IGFirm struct.
 */
typedef struct xmachine_memory_IGFirm_state xmachine_memory_IGFirm_state;
/** \var typedef xmachine_memory_Eurostat xmachine_memory_Eurostat
 * \brief Typedef for xmachine_memory_Eurostat struct.
 */
typedef struct xmachine_memory_Eurostat xmachine_memory_Eurostat;
/** \var typedef xmachine_memory_Eurostat xmachine_memory_Eurostat
 * \brief Typedef for xmachine_memory_Eurostat struct.
 */
typedef struct xmachine_memory_Eurostat_holder xmachine_memory_Eurostat_holder;
/** \var typedef xmachine_memory_Eurostat xmachine_memory_Eurostat
 * \brief Typedef for xmachine_memory_Eurostat struct.
 */
typedef struct xmachine_memory_Eurostat_state xmachine_memory_Eurostat_state;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank xmachine_memory_Bank;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank_holder xmachine_memory_Bank_holder;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank_state xmachine_memory_Bank_state;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government xmachine_memory_Government;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government_holder xmachine_memory_Government_holder;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government_state xmachine_memory_Government_state;
/** \var typedef xmachine_memory_CentralBank xmachine_memory_CentralBank
 * \brief Typedef for xmachine_memory_CentralBank struct.
 */
typedef struct xmachine_memory_CentralBank xmachine_memory_CentralBank;
/** \var typedef xmachine_memory_CentralBank xmachine_memory_CentralBank
 * \brief Typedef for xmachine_memory_CentralBank struct.
 */
typedef struct xmachine_memory_CentralBank_holder xmachine_memory_CentralBank_holder;
/** \var typedef xmachine_memory_CentralBank xmachine_memory_CentralBank
 * \brief Typedef for xmachine_memory_CentralBank struct.
 */
typedef struct xmachine_memory_CentralBank_state xmachine_memory_CentralBank_state;
/** \var typedef xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse
 * \brief Typedef for xmachine_memory_ClearingHouse struct.
 */
typedef struct xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse;
/** \var typedef xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse
 * \brief Typedef for xmachine_memory_ClearingHouse struct.
 */
typedef struct xmachine_memory_ClearingHouse_holder xmachine_memory_ClearingHouse_holder;
/** \var typedef xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse
 * \brief Typedef for xmachine_memory_ClearingHouse struct.
 */
typedef struct xmachine_memory_ClearingHouse_state xmachine_memory_ClearingHouse_state;
/** \typedef m_bank_account_update m_bank_account_update
 * \brief Typedef for m_bank_account_update struct.
 */
typedef struct m_bank_account_update m_bank_account_update;

/** \typedef m_bank_to_central_bank_account_update m_bank_to_central_bank_account_update
 * \brief Typedef for m_bank_to_central_bank_account_update struct.
 */
typedef struct m_bank_to_central_bank_account_update m_bank_to_central_bank_account_update;

/** \typedef m_gov_to_central_bank_account_update m_gov_to_central_bank_account_update
 * \brief Typedef for m_gov_to_central_bank_account_update struct.
 */
typedef struct m_gov_to_central_bank_account_update m_gov_to_central_bank_account_update;

/** \typedef m_wage_payment m_wage_payment
 * \brief Typedef for m_wage_payment struct.
 */
typedef struct m_wage_payment m_wage_payment;

/** \typedef m_quality_price_info_1 m_quality_price_info_1
 * \brief Typedef for m_quality_price_info_1 struct.
 */
typedef struct m_quality_price_info_1 m_quality_price_info_1;

/** \typedef m_quality_price_info_2 m_quality_price_info_2
 * \brief Typedef for m_quality_price_info_2 struct.
 */
typedef struct m_quality_price_info_2 m_quality_price_info_2;

/** \typedef m_update_mall_stock m_update_mall_stock
 * \brief Typedef for m_update_mall_stock struct.
 */
typedef struct m_update_mall_stock m_update_mall_stock;

/** \typedef m_consumption_request_1 m_consumption_request_1
 * \brief Typedef for m_consumption_request_1 struct.
 */
typedef struct m_consumption_request_1 m_consumption_request_1;

/** \typedef m_consumption_request_2 m_consumption_request_2
 * \brief Typedef for m_consumption_request_2 struct.
 */
typedef struct m_consumption_request_2 m_consumption_request_2;

/** \typedef m_accepted_consumption_1 m_accepted_consumption_1
 * \brief Typedef for m_accepted_consumption_1 struct.
 */
typedef struct m_accepted_consumption_1 m_accepted_consumption_1;

/** \typedef m_accepted_consumption_2 m_accepted_consumption_2
 * \brief Typedef for m_accepted_consumption_2 struct.
 */
typedef struct m_accepted_consumption_2 m_accepted_consumption_2;

/** \typedef m_sales m_sales
 * \brief Typedef for m_sales struct.
 */
typedef struct m_sales m_sales;

/** \typedef m_specific_skill_update m_specific_skill_update
 * \brief Typedef for m_specific_skill_update struct.
 */
typedef struct m_specific_skill_update m_specific_skill_update;

/** \typedef m_policy_rate m_policy_rate
 * \brief Typedef for m_policy_rate struct.
 */
typedef struct m_policy_rate m_policy_rate;

/** \typedef m_bank_identity m_bank_identity
 * \brief Typedef for m_bank_identity struct.
 */
typedef struct m_bank_identity m_bank_identity;

/** \typedef m_loan_request m_loan_request
 * \brief Typedef for m_loan_request struct.
 */
typedef struct m_loan_request m_loan_request;

/** \typedef m_loan_request_ranked m_loan_request_ranked
 * \brief Typedef for m_loan_request_ranked struct.
 */
typedef struct m_loan_request_ranked m_loan_request_ranked;

/** \typedef m_loan_conditions m_loan_conditions
 * \brief Typedef for m_loan_conditions struct.
 */
typedef struct m_loan_conditions m_loan_conditions;

/** \typedef m_loan_acceptance m_loan_acceptance
 * \brief Typedef for m_loan_acceptance struct.
 */
typedef struct m_loan_acceptance m_loan_acceptance;

/** \typedef m_installment m_installment
 * \brief Typedef for m_installment struct.
 */
typedef struct m_installment m_installment;

/** \typedef m_bankruptcy m_bankruptcy
 * \brief Typedef for m_bankruptcy struct.
 */
typedef struct m_bankruptcy m_bankruptcy;

/** \typedef m_bank_interest_payment m_bank_interest_payment
 * \brief Typedef for m_bank_interest_payment struct.
 */
typedef struct m_bank_interest_payment m_bank_interest_payment;

/** \typedef m_account_interest m_account_interest
 * \brief Typedef for m_account_interest struct.
 */
typedef struct m_account_interest m_account_interest;

/** \typedef m_ecb_dividend m_ecb_dividend
 * \brief Typedef for m_ecb_dividend struct.
 */
typedef struct m_ecb_dividend m_ecb_dividend;

/** \typedef m_credit_var_update m_credit_var_update
 * \brief Typedef for m_credit_var_update struct.
 */
typedef struct m_credit_var_update m_credit_var_update;

/** \typedef m_bankruptcy_illiquidity m_bankruptcy_illiquidity
 * \brief Typedef for m_bankruptcy_illiquidity struct.
 */
typedef struct m_bankruptcy_illiquidity m_bankruptcy_illiquidity;

/** \typedef m_bankruptcy_insolvency m_bankruptcy_insolvency
 * \brief Typedef for m_bankruptcy_insolvency struct.
 */
typedef struct m_bankruptcy_insolvency m_bankruptcy_insolvency;

/** \typedef m_index_info m_index_info
 * \brief Typedef for m_index_info struct.
 */
typedef struct m_index_info m_index_info;

/** \typedef m_index_price m_index_price
 * \brief Typedef for m_index_price struct.
 */
typedef struct m_index_price m_index_price;

/** \typedef m_order m_order
 * \brief Typedef for m_order struct.
 */
typedef struct m_order m_order;

/** \typedef m_order_status m_order_status
 * \brief Typedef for m_order_status struct.
 */
typedef struct m_order_status m_order_status;

/** \typedef m_dividend_info m_dividend_info
 * \brief Typedef for m_dividend_info struct.
 */
typedef struct m_dividend_info m_dividend_info;

/** \typedef m_productivity m_productivity
 * \brief Typedef for m_productivity struct.
 */
typedef struct m_productivity m_productivity;

/** \typedef m_capital_good_request m_capital_good_request
 * \brief Typedef for m_capital_good_request struct.
 */
typedef struct m_capital_good_request m_capital_good_request;

/** \typedef m_capital_good_delivery m_capital_good_delivery
 * \brief Typedef for m_capital_good_delivery struct.
 */
typedef struct m_capital_good_delivery m_capital_good_delivery;

/** \typedef m_pay_capital_goods m_pay_capital_goods
 * \brief Typedef for m_pay_capital_goods struct.
 */
typedef struct m_pay_capital_goods m_pay_capital_goods;

/** \typedef m_vacancies m_vacancies
 * \brief Typedef for m_vacancies struct.
 */
typedef struct m_vacancies m_vacancies;

/** \typedef m_vacancies2 m_vacancies2
 * \brief Typedef for m_vacancies2 struct.
 */
typedef struct m_vacancies2 m_vacancies2;

/** \typedef m_vacancies_r_and_d_employees m_vacancies_r_and_d_employees
 * \brief Typedef for m_vacancies_r_and_d_employees struct.
 */
typedef struct m_vacancies_r_and_d_employees m_vacancies_r_and_d_employees;

/** \typedef m_vacancies_r_and_d_employees2 m_vacancies_r_and_d_employees2
 * \brief Typedef for m_vacancies_r_and_d_employees2 struct.
 */
typedef struct m_vacancies_r_and_d_employees2 m_vacancies_r_and_d_employees2;

/** \typedef m_firing m_firing
 * \brief Typedef for m_firing struct.
 */
typedef struct m_firing m_firing;

/** \typedef m_job_application m_job_application
 * \brief Typedef for m_job_application struct.
 */
typedef struct m_job_application m_job_application;

/** \typedef m_job_application2 m_job_application2
 * \brief Typedef for m_job_application2 struct.
 */
typedef struct m_job_application2 m_job_application2;

/** \typedef m_job_offer m_job_offer
 * \brief Typedef for m_job_offer struct.
 */
typedef struct m_job_offer m_job_offer;

/** \typedef m_job_offer2 m_job_offer2
 * \brief Typedef for m_job_offer2 struct.
 */
typedef struct m_job_offer2 m_job_offer2;

/** \typedef m_job_acceptance m_job_acceptance
 * \brief Typedef for m_job_acceptance struct.
 */
typedef struct m_job_acceptance m_job_acceptance;

/** \typedef m_job_acceptance2 m_job_acceptance2
 * \brief Typedef for m_job_acceptance2 struct.
 */
typedef struct m_job_acceptance2 m_job_acceptance2;

/** \typedef m_quitting m_quitting
 * \brief Typedef for m_quitting struct.
 */
typedef struct m_quitting m_quitting;

/** \typedef m_quitting2 m_quitting2
 * \brief Typedef for m_quitting2 struct.
 */
typedef struct m_quitting2 m_quitting2;

/** \typedef m_unemployment_notification m_unemployment_notification
 * \brief Typedef for m_unemployment_notification struct.
 */
typedef struct m_unemployment_notification m_unemployment_notification;

/** \typedef m_policy_announcement m_policy_announcement
 * \brief Typedef for m_policy_announcement struct.
 */
typedef struct m_policy_announcement m_policy_announcement;

/** \typedef m_tax_payment m_tax_payment
 * \brief Typedef for m_tax_payment struct.
 */
typedef struct m_tax_payment m_tax_payment;

/** \typedef m_unemployment_benefit_restitution m_unemployment_benefit_restitution
 * \brief Typedef for m_unemployment_benefit_restitution struct.
 */
typedef struct m_unemployment_benefit_restitution m_unemployment_benefit_restitution;

/** \typedef m_hh_transfer_notification m_hh_transfer_notification
 * \brief Typedef for m_hh_transfer_notification struct.
 */
typedef struct m_hh_transfer_notification m_hh_transfer_notification;

/** \typedef m_hh_subsidy_notification m_hh_subsidy_notification
 * \brief Typedef for m_hh_subsidy_notification struct.
 */
typedef struct m_hh_subsidy_notification m_hh_subsidy_notification;

/** \typedef m_human_capital_policy_announcement m_human_capital_policy_announcement
 * \brief Typedef for m_human_capital_policy_announcement struct.
 */
typedef struct m_human_capital_policy_announcement m_human_capital_policy_announcement;

/** \typedef m_firm_transfer_notification m_firm_transfer_notification
 * \brief Typedef for m_firm_transfer_notification struct.
 */
typedef struct m_firm_transfer_notification m_firm_transfer_notification;

/** \typedef m_firm_subsidy_notification m_firm_subsidy_notification
 * \brief Typedef for m_firm_subsidy_notification struct.
 */
typedef struct m_firm_subsidy_notification m_firm_subsidy_notification;

/** \typedef m_request_fiat_money m_request_fiat_money
 * \brief Typedef for m_request_fiat_money struct.
 */
typedef struct m_request_fiat_money m_request_fiat_money;

/** \typedef m_human_capital_policy_general_skill_information m_human_capital_policy_general_skill_information
 * \brief Typedef for m_human_capital_policy_general_skill_information struct.
 */
typedef struct m_human_capital_policy_general_skill_information m_human_capital_policy_general_skill_information;

/** \typedef m_human_capital_policy_new_general_skill_notification m_human_capital_policy_new_general_skill_notification
 * \brief Typedef for m_human_capital_policy_new_general_skill_notification struct.
 */
typedef struct m_human_capital_policy_new_general_skill_notification m_human_capital_policy_new_general_skill_notification;

/** \typedef m_firm_send_data m_firm_send_data
 * \brief Typedef for m_firm_send_data struct.
 */
typedef struct m_firm_send_data m_firm_send_data;

/** \typedef m_government_send_data m_government_send_data
 * \brief Typedef for m_government_send_data struct.
 */
typedef struct m_government_send_data m_government_send_data;

/** \typedef m_household_send_data m_household_send_data
 * \brief Typedef for m_household_send_data struct.
 */
typedef struct m_household_send_data m_household_send_data;

/** \typedef m_mall_data m_mall_data
 * \brief Typedef for m_mall_data struct.
 */
typedef struct m_mall_data m_mall_data;

/** \typedef m_eurostat_send_specific_skills m_eurostat_send_specific_skills
 * \brief Typedef for m_eurostat_send_specific_skills struct.
 */
typedef struct m_eurostat_send_specific_skills m_eurostat_send_specific_skills;

/** \typedef m_data_for_government m_data_for_government
 * \brief Typedef for m_data_for_government struct.
 */
typedef struct m_data_for_government m_data_for_government;

/** \typedef m_eurostat_send_macrodata m_eurostat_send_macrodata
 * \brief Typedef for m_eurostat_send_macrodata struct.
 */
typedef struct m_eurostat_send_macrodata m_eurostat_send_macrodata;

/** \typedef m_msg_firm_id_to_malls m_msg_firm_id_to_malls
 * \brief Typedef for m_msg_firm_id_to_malls struct.
 */
typedef struct m_msg_firm_id_to_malls m_msg_firm_id_to_malls;

/** \typedef m_msg_mall_id_to_firms m_msg_mall_id_to_firms
 * \brief Typedef for m_msg_mall_id_to_firms struct.
 */
typedef struct m_msg_mall_id_to_firms m_msg_mall_id_to_firms;

/** \typedef m_msg_skills_eurostat_to_igfirm m_msg_skills_eurostat_to_igfirm
 * \brief Typedef for m_msg_skills_eurostat_to_igfirm struct.
 */
typedef struct m_msg_skills_eurostat_to_igfirm m_msg_skills_eurostat_to_igfirm;

/** \typedef m_msg_market_sizes m_msg_market_sizes
 * \brief Typedef for m_msg_market_sizes struct.
 */
typedef struct m_msg_market_sizes m_msg_market_sizes;

/** \typedef m_total_subsidies m_total_subsidies
 * \brief Typedef for m_total_subsidies struct.
 */
typedef struct m_total_subsidies m_total_subsidies;

/** \typedef m_redistributed_subsidies m_redistributed_subsidies
 * \brief Typedef for m_redistributed_subsidies struct.
 */
typedef struct m_redistributed_subsidies m_redistributed_subsidies;

/** \typedef m_quality_price m_quality_price
 * \brief Typedef for m_quality_price struct.
 */
typedef struct m_quality_price m_quality_price;

/** \typedef m_interview_request m_interview_request
 * \brief Typedef for m_interview_request struct.
 */
typedef struct m_interview_request m_interview_request;

/** \typedef m_interview_positive_response m_interview_positive_response
 * \brief Typedef for m_interview_positive_response struct.
 */
typedef struct m_interview_positive_response m_interview_positive_response;

/** \typedef m_questionnaire_innovation m_questionnaire_innovation
 * \brief Typedef for m_questionnaire_innovation struct.
 */
typedef struct m_questionnaire_innovation m_questionnaire_innovation;

/** \typedef m_filled_out_questionnaire_product_innovation m_filled_out_questionnaire_product_innovation
 * \brief Typedef for m_filled_out_questionnaire_product_innovation struct.
 */
typedef struct m_filled_out_questionnaire_product_innovation m_filled_out_questionnaire_product_innovation;


/** \struct location
 * \brief Holds location for calculating space partitioning .
 */
struct location
{
	double point;		/**< Point on an axis. */

	struct location * next;	/**< Pointer to next location on the list. */
};

/** \struct node_information
 * \brief Holds node information .
 */
struct node_information
{
	int node_id;	/**< Node ID. */
	double partition_data[6];	/**< Defines bounding box. */
	int agents_in_halo;	/**< Number of agents in the halo region. */
	int agent_total;	/**< Total number of agents on the node. */
	struct xmachine * agents;	/**< Pointer to list of X-machines. */
	struct m_bank_account_update * bank_account_update_messages;	/**< Pointer to bank_account_update message list. */
	struct m_bank_to_central_bank_account_update * bank_to_central_bank_account_update_messages;	/**< Pointer to bank_to_central_bank_account_update message list. */
	struct m_gov_to_central_bank_account_update * gov_to_central_bank_account_update_messages;	/**< Pointer to gov_to_central_bank_account_update message list. */
	struct m_wage_payment * wage_payment_messages;	/**< Pointer to wage_payment message list. */
	struct m_quality_price_info_1 * quality_price_info_1_messages;	/**< Pointer to quality_price_info_1 message list. */
	struct m_quality_price_info_2 * quality_price_info_2_messages;	/**< Pointer to quality_price_info_2 message list. */
	struct m_update_mall_stock * update_mall_stock_messages;	/**< Pointer to update_mall_stock message list. */
	struct m_consumption_request_1 * consumption_request_1_messages;	/**< Pointer to consumption_request_1 message list. */
	struct m_consumption_request_2 * consumption_request_2_messages;	/**< Pointer to consumption_request_2 message list. */
	struct m_accepted_consumption_1 * accepted_consumption_1_messages;	/**< Pointer to accepted_consumption_1 message list. */
	struct m_accepted_consumption_2 * accepted_consumption_2_messages;	/**< Pointer to accepted_consumption_2 message list. */
	struct m_sales * sales_messages;	/**< Pointer to sales message list. */
	struct m_specific_skill_update * specific_skill_update_messages;	/**< Pointer to specific_skill_update message list. */
	struct m_policy_rate * policy_rate_messages;	/**< Pointer to policy_rate message list. */
	struct m_bank_identity * bank_identity_messages;	/**< Pointer to bank_identity message list. */
	struct m_loan_request * loan_request_messages;	/**< Pointer to loan_request message list. */
	struct m_loan_request_ranked * loan_request_ranked_messages;	/**< Pointer to loan_request_ranked message list. */
	struct m_loan_conditions * loan_conditions_messages;	/**< Pointer to loan_conditions message list. */
	struct m_loan_acceptance * loan_acceptance_messages;	/**< Pointer to loan_acceptance message list. */
	struct m_installment * installment_messages;	/**< Pointer to installment message list. */
	struct m_bankruptcy * bankruptcy_messages;	/**< Pointer to bankruptcy message list. */
	struct m_bank_interest_payment * bank_interest_payment_messages;	/**< Pointer to bank_interest_payment message list. */
	struct m_account_interest * account_interest_messages;	/**< Pointer to account_interest message list. */
	struct m_ecb_dividend * ecb_dividend_messages;	/**< Pointer to ecb_dividend message list. */
	struct m_credit_var_update * credit_var_update_messages;	/**< Pointer to credit_var_update message list. */
	struct m_bankruptcy_illiquidity * bankruptcy_illiquidity_messages;	/**< Pointer to bankruptcy_illiquidity message list. */
	struct m_bankruptcy_insolvency * bankruptcy_insolvency_messages;	/**< Pointer to bankruptcy_insolvency message list. */
	struct m_index_info * index_info_messages;	/**< Pointer to index_info message list. */
	struct m_index_price * index_price_messages;	/**< Pointer to index_price message list. */
	struct m_order * order_messages;	/**< Pointer to order message list. */
	struct m_order_status * order_status_messages;	/**< Pointer to order_status message list. */
	struct m_dividend_info * dividend_info_messages;	/**< Pointer to dividend_info message list. */
	struct m_productivity * productivity_messages;	/**< Pointer to productivity message list. */
	struct m_capital_good_request * capital_good_request_messages;	/**< Pointer to capital_good_request message list. */
	struct m_capital_good_delivery * capital_good_delivery_messages;	/**< Pointer to capital_good_delivery message list. */
	struct m_pay_capital_goods * pay_capital_goods_messages;	/**< Pointer to pay_capital_goods message list. */
	struct m_vacancies * vacancies_messages;	/**< Pointer to vacancies message list. */
	struct m_vacancies2 * vacancies2_messages;	/**< Pointer to vacancies2 message list. */
	struct m_vacancies_r_and_d_employees * vacancies_r_and_d_employees_messages;	/**< Pointer to vacancies_r_and_d_employees message list. */
	struct m_vacancies_r_and_d_employees2 * vacancies_r_and_d_employees2_messages;	/**< Pointer to vacancies_r_and_d_employees2 message list. */
	struct m_firing * firing_messages;	/**< Pointer to firing message list. */
	struct m_job_application * job_application_messages;	/**< Pointer to job_application message list. */
	struct m_job_application2 * job_application2_messages;	/**< Pointer to job_application2 message list. */
	struct m_job_offer * job_offer_messages;	/**< Pointer to job_offer message list. */
	struct m_job_offer2 * job_offer2_messages;	/**< Pointer to job_offer2 message list. */
	struct m_job_acceptance * job_acceptance_messages;	/**< Pointer to job_acceptance message list. */
	struct m_job_acceptance2 * job_acceptance2_messages;	/**< Pointer to job_acceptance2 message list. */
	struct m_quitting * quitting_messages;	/**< Pointer to quitting message list. */
	struct m_quitting2 * quitting2_messages;	/**< Pointer to quitting2 message list. */
	struct m_unemployment_notification * unemployment_notification_messages;	/**< Pointer to unemployment_notification message list. */
	struct m_policy_announcement * policy_announcement_messages;	/**< Pointer to policy_announcement message list. */
	struct m_tax_payment * tax_payment_messages;	/**< Pointer to tax_payment message list. */
	struct m_unemployment_benefit_restitution * unemployment_benefit_restitution_messages;	/**< Pointer to unemployment_benefit_restitution message list. */
	struct m_hh_transfer_notification * hh_transfer_notification_messages;	/**< Pointer to hh_transfer_notification message list. */
	struct m_hh_subsidy_notification * hh_subsidy_notification_messages;	/**< Pointer to hh_subsidy_notification message list. */
	struct m_human_capital_policy_announcement * human_capital_policy_announcement_messages;	/**< Pointer to human_capital_policy_announcement message list. */
	struct m_firm_transfer_notification * firm_transfer_notification_messages;	/**< Pointer to firm_transfer_notification message list. */
	struct m_firm_subsidy_notification * firm_subsidy_notification_messages;	/**< Pointer to firm_subsidy_notification message list. */
	struct m_request_fiat_money * request_fiat_money_messages;	/**< Pointer to request_fiat_money message list. */
	struct m_human_capital_policy_general_skill_information * human_capital_policy_general_skill_information_messages;	/**< Pointer to human_capital_policy_general_skill_information message list. */
	struct m_human_capital_policy_new_general_skill_notification * human_capital_policy_new_general_skill_notification_messages;	/**< Pointer to human_capital_policy_new_general_skill_notification message list. */
	struct m_firm_send_data * firm_send_data_messages;	/**< Pointer to firm_send_data message list. */
	struct m_government_send_data * government_send_data_messages;	/**< Pointer to government_send_data message list. */
	struct m_household_send_data * household_send_data_messages;	/**< Pointer to household_send_data message list. */
	struct m_mall_data * mall_data_messages;	/**< Pointer to mall_data message list. */
	struct m_eurostat_send_specific_skills * eurostat_send_specific_skills_messages;	/**< Pointer to eurostat_send_specific_skills message list. */
	struct m_data_for_government * data_for_government_messages;	/**< Pointer to data_for_government message list. */
	struct m_eurostat_send_macrodata * eurostat_send_macrodata_messages;	/**< Pointer to eurostat_send_macrodata message list. */
	struct m_msg_firm_id_to_malls * msg_firm_id_to_malls_messages;	/**< Pointer to msg_firm_id_to_malls message list. */
	struct m_msg_mall_id_to_firms * msg_mall_id_to_firms_messages;	/**< Pointer to msg_mall_id_to_firms message list. */
	struct m_msg_skills_eurostat_to_igfirm * msg_skills_eurostat_to_igfirm_messages;	/**< Pointer to msg_skills_eurostat_to_igfirm message list. */
	struct m_msg_market_sizes * msg_market_sizes_messages;	/**< Pointer to msg_market_sizes message list. */
	struct m_total_subsidies * total_subsidies_messages;	/**< Pointer to total_subsidies message list. */
	struct m_redistributed_subsidies * redistributed_subsidies_messages;	/**< Pointer to redistributed_subsidies message list. */
	struct m_quality_price * quality_price_messages;	/**< Pointer to quality_price message list. */
	struct m_interview_request * interview_request_messages;	/**< Pointer to interview_request message list. */
	struct m_interview_positive_response * interview_positive_response_messages;	/**< Pointer to interview_positive_response message list. */
	struct m_questionnaire_innovation * questionnaire_innovation_messages;	/**< Pointer to questionnaire_innovation message list. */
	struct m_filled_out_questionnaire_product_innovation * filled_out_questionnaire_product_innovation_messages;	/**< Pointer to filled_out_questionnaire_product_innovation message list. */

	struct node_information * next;	/**< Pointer to next node on the list. */
};


/** \typedef struct location location
 * \brief Typedef for location struct.
 */
typedef struct location location;
/** \typedef struct node_information node_information
 * \brief Typedef for node_information struct.
 */
typedef struct node_information node_information;

/** \var int total_regions
* \brief A constant variable from the environment. */
int FLAME_environment_variable_total_regions;
/** \var int id_debug_probe
* \brief A constant variable from the environment. */
int FLAME_environment_variable_id_debug_probe;
/** \var int print_log
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_log;
/** \var int print_debug_bankruptcy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_bankruptcy;
/** \var int print_debug_eurostat
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_eurostat;
/** \var int print_debug_ch
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_ch;
/** \var int print_debug_afm
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_afm;
/** \var int print_debug_afm_ch
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_afm_ch;
/** \var int print_debug_exp1
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_exp1;
/** \var int print_debug_file_exp1
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_file_exp1;
/** \var int print_debug_file_exp2
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_file_exp2;
/** \var int policy_exp1
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_exp1;
/** \var int print_debug_gov
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_gov;
/** \var int print_debug_household
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_household;
/** \var int print_debug_credit
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_credit;
/** \var int print_debug_consumption
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_consumption;
/** \var int print_debug_finman
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_finman;
/** \var int print_debug_production
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_production;
/** \var int print_debug
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug;
/** \var int print_debug_market_research
* \brief A constant variable from the environment. */
int FLAME_environment_variable_print_debug_market_research;
/** \var int policy_exp_energy_shock
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_exp_energy_shock;
/** \var int policy_exp_stabilization_subsidy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_exp_stabilization_subsidy;
/** \var int policy_exp_stabilization_tax
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_exp_stabilization_tax;
/** \var int const_bankruptcy_idle_period
* \brief A constant variable from the environment. */
int FLAME_environment_variable_const_bankruptcy_idle_period;
/** \var int days_per_month
* \brief A constant variable from the environment. */
int FLAME_environment_variable_days_per_month;
/** \var int xml_cloned
* \brief A constant variable from the environment. */
int FLAME_environment_variable_xml_cloned;
/** \var int individual_learning
* \brief A constant variable from the environment. */
int FLAME_environment_variable_individual_learning;
/** \var double const_wage_wealth_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_wage_wealth_ratio;
/** \var double const_income_tax_rate
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_income_tax_rate;
/** \var double gamma_const
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gamma_const;
/** \var double gamma_quality
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gamma_quality;
/** \var double initial_price
* \brief A constant variable from the environment. */
double FLAME_environment_variable_initial_price;
/** \var double depreciation_rate
* \brief A constant variable from the environment. */
double FLAME_environment_variable_depreciation_rate;
/** \var double discont_rate
* \brief A constant variable from the environment. */
double FLAME_environment_variable_discont_rate;
/** \var double mark_up
* \brief A constant variable from the environment. */
double FLAME_environment_variable_mark_up;
/** \var double lambda
* \brief A constant variable from the environment. */
double FLAME_environment_variable_lambda;
/** \var double target_savings_rate
* \brief A constant variable from the environment. */
double FLAME_environment_variable_target_savings_rate;
/** \var double carrol_consumption_parameter
* \brief A constant variable from the environment. */
double FLAME_environment_variable_carrol_consumption_parameter;
/** \var double quantil_normal_distribution
* \brief A constant variable from the environment. */
double FLAME_environment_variable_quantil_normal_distribution;
/** \var int firm_planning_horizon
* \brief A constant variable from the environment. */
int FLAME_environment_variable_firm_planning_horizon;
/** \var double initial_stock_up
* \brief A constant variable from the environment. */
double FLAME_environment_variable_initial_stock_up;
/** \var int initial_price_adjustment
* \brief A constant variable from the environment. */
int FLAME_environment_variable_initial_price_adjustment;
/** \var double adaption_delivery_volume
* \brief A constant variable from the environment. */
double FLAME_environment_variable_adaption_delivery_volume;
/** \var double inv_inertia
* \brief A constant variable from the environment. */
double FLAME_environment_variable_inv_inertia;
/** \var int planning_horizon_vintage_choice
* \brief A constant variable from the environment. */
int FLAME_environment_variable_planning_horizon_vintage_choice;
/** \var double gamma_logit_vintage_choice
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gamma_logit_vintage_choice;
/** \var double delta_logit_vintage_choice
* \brief A constant variable from the environment. */
double FLAME_environment_variable_delta_logit_vintage_choice;
/** \var int number_of_banks_to_apply
* \brief A constant variable from the environment. */
int FLAME_environment_variable_number_of_banks_to_apply;
/** \var int const_number_of_banks
* \brief A constant variable from the environment. */
int FLAME_environment_variable_const_number_of_banks;
/** \var int const_installment_periods
* \brief A constant variable from the environment. */
int FLAME_environment_variable_const_installment_periods;
/** \var double bank_lambda
* \brief A constant variable from the environment. */
double FLAME_environment_variable_bank_lambda;
/** \var double ecb_interest_rate
* \brief A constant variable from the environment. */
double FLAME_environment_variable_ecb_interest_rate;
/** \var double ecb_interest_rate_markdown
* \brief A constant variable from the environment. */
double FLAME_environment_variable_ecb_interest_rate_markdown;
/** \var double alfa
* \brief A constant variable from the environment. */
double FLAME_environment_variable_alfa;
/** \var double min_cash_reserve_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_min_cash_reserve_ratio;
/** \var double const_firm_leverage
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_firm_leverage;
/** \var double debt_rescaling_factor
* \brief A constant variable from the environment. */
double FLAME_environment_variable_debt_rescaling_factor;
/** \var double target_leverage_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_target_leverage_ratio;
/** \var double target_liquidity_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_target_liquidity_ratio;
/** \var double const_dividend_earnings_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_dividend_earnings_ratio;
/** \var double const_dividend_treshold_full_payout
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_dividend_treshold_full_payout;
/** \var int igfirm_dividend_payout_stretching_month
* \brief A constant variable from the environment. */
int FLAME_environment_variable_igfirm_dividend_payout_stretching_month;
/** \var double index_price_adj
* \brief A constant variable from the environment. */
double FLAME_environment_variable_index_price_adj;
/** \var double index_price_adj_max
* \brief A constant variable from the environment. */
double FLAME_environment_variable_index_price_adj_max;
/** \var double index_price_adj_min
* \brief A constant variable from the environment. */
double FLAME_environment_variable_index_price_adj_min;
/** \var int trading_activity
* \brief A constant variable from the environment. */
int FLAME_environment_variable_trading_activity;
/** \var int trading_random
* \brief A constant variable from the environment. */
int FLAME_environment_variable_trading_random;
/** \var int igfirm_fin_man_debug
* \brief A constant variable from the environment. */
int FLAME_environment_variable_igfirm_fin_man_debug;
/** \var double const_igfirm_dividend_target_pct
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_igfirm_dividend_target_pct;
/** \var double const_igfirm_dividend_adjustment_parameter
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_igfirm_dividend_adjustment_parameter;
/** \var int switch_igfirm_endogenous_innovation_probability
* \brief A constant variable from the environment. */
int FLAME_environment_variable_switch_igfirm_endogenous_innovation_probability;
/** \var double igfirm_exogenous_innovation_probability
* \brief A constant variable from the environment. */
double FLAME_environment_variable_igfirm_exogenous_innovation_probability;
/** \var double power_of_end_probability_function
* \brief A constant variable from the environment. */
double FLAME_environment_variable_power_of_end_probability_function;
/** \var int igfirm_producer_debug
* \brief A constant variable from the environment. */
int FLAME_environment_variable_igfirm_producer_debug;
/** \var double igfirm_exogenous_productivity_progress
* \brief A constant variable from the environment. */
double FLAME_environment_variable_igfirm_exogenous_productivity_progress;
/** \var int symmetric_shock
* \brief A constant variable from the environment. */
int FLAME_environment_variable_symmetric_shock;
/** \var int energy_shock_start
* \brief A constant variable from the environment. */
int FLAME_environment_variable_energy_shock_start;
/** \var int energy_shock_end
* \brief A constant variable from the environment. */
int FLAME_environment_variable_energy_shock_end;
/** \var double const_energy_shock_intensity
* \brief A constant variable from the environment. */
double FLAME_environment_variable_const_energy_shock_intensity;
/** \var int energy_shock_frequency
* \brief A constant variable from the environment. */
int FLAME_environment_variable_energy_shock_frequency;
/** \var int transition_phase
* \brief A constant variable from the environment. */
int FLAME_environment_variable_transition_phase;
/** \var int innovation_by_random
* \brief A constant variable from the environment. */
int FLAME_environment_variable_innovation_by_random;
/** \var int ig_good_limited_offer
* \brief A constant variable from the environment. */
int FLAME_environment_variable_ig_good_limited_offer;
/** \var int max_offer_ig_good
* \brief A constant variable from the environment. */
int FLAME_environment_variable_max_offer_ig_good;
/** \var double initial_frontier_firm_transition_phase
* \brief A constant variable from the environment. */
double FLAME_environment_variable_initial_frontier_firm_transition_phase;
/** \var double initial_productivity_firm
* \brief A constant variable from the environment. */
double FLAME_environment_variable_initial_productivity_firm;
/** \var double initial_specific_skills
* \brief A constant variable from the environment. */
double FLAME_environment_variable_initial_specific_skills;
/** \var int strenght_of_tech_progress
* \brief A constant variable from the environment. */
int FLAME_environment_variable_strenght_of_tech_progress;
/** \var double linear_combination_pricing_ig_good
* \brief A constant variable from the environment. */
double FLAME_environment_variable_linear_combination_pricing_ig_good;
/** \var double initial_capital_price_wage_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_initial_capital_price_wage_ratio;
/** \var double union_strength
* \brief A constant variable from the environment. */
double FLAME_environment_variable_union_strength;
/** \var int reg_diff_union_strength
* \brief A constant variable from the environment. */
int FLAME_environment_variable_reg_diff_union_strength;
/** \var double reg2_factor_union_strength
* \brief A constant variable from the environment. */
double FLAME_environment_variable_reg2_factor_union_strength;
/** \var double wage_update
* \brief A constant variable from the environment. */
double FLAME_environment_variable_wage_update;
/** \var int min_vacancy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_min_vacancy;
/** \var double wage_reservation_update
* \brief A constant variable from the environment. */
double FLAME_environment_variable_wage_reservation_update;
/** \var double region_cost
* \brief A constant variable from the environment. */
double FLAME_environment_variable_region_cost;
/** \var double delivery_prob_if_critical_stock_0
* \brief A constant variable from the environment. */
double FLAME_environment_variable_delivery_prob_if_critical_stock_0;
/** \var int labormarket_scenario_reg2
* \brief A constant variable from the environment. */
int FLAME_environment_variable_labormarket_scenario_reg2;
/** \var int number_applications
* \brief A constant variable from the environment. */
int FLAME_environment_variable_number_applications;
/** \var int applications_per_day
* \brief A constant variable from the environment. */
int FLAME_environment_variable_applications_per_day;
/** \var int lower_bound_firing
* \brief A constant variable from the environment. */
int FLAME_environment_variable_lower_bound_firing;
/** \var int upper_bound_firing
* \brief A constant variable from the environment. */
int FLAME_environment_variable_upper_bound_firing;
/** \var double logit_parameter_specific_skills
* \brief A constant variable from the environment. */
double FLAME_environment_variable_logit_parameter_specific_skills;
/** \var double logit_parameter_worker_preselection
* \brief A constant variable from the environment. */
double FLAME_environment_variable_logit_parameter_worker_preselection;
/** \var double logit_parameter_general_skills
* \brief A constant variable from the environment. */
double FLAME_environment_variable_logit_parameter_general_skills;
/** \var int skill_update_acc_to_formula
* \brief A constant variable from the environment. */
int FLAME_environment_variable_skill_update_acc_to_formula;
/** \var int rnd_seed
* \brief A constant variable from the environment. */
int FLAME_environment_variable_rnd_seed;
/** \var double gov_policy_unemployment_benefit_pct
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gov_policy_unemployment_benefit_pct;
/** \var double gamma_gov
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gamma_gov;
/** \var int joe_scenario
* \brief A constant variable from the environment. */
int FLAME_environment_variable_joe_scenario;
/** \var int gov_expenditures_and_unemp_benefits_redistributed
* \brief A constant variable from the environment. */
int FLAME_environment_variable_gov_expenditures_and_unemp_benefits_redistributed;
/** \var double gov_policy_money_financing_fraction
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gov_policy_money_financing_fraction;
/** \var int adaptive_tax_rates
* \brief A constant variable from the environment. */
int FLAME_environment_variable_adaptive_tax_rates;
/** \var int gov_2_relaxed_budget_rule
* \brief A constant variable from the environment. */
int FLAME_environment_variable_gov_2_relaxed_budget_rule;
/** \var double gov_2_expenditures_covered
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gov_2_expenditures_covered;
/** \var double gov_2_consumption_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gov_2_consumption_ratio;
/** \var int gov_regional_consumption_scenario
* \brief A constant variable from the environment. */
int FLAME_environment_variable_gov_regional_consumption_scenario;
/** \var double reg2_markup_factor
* \brief A constant variable from the environment. */
double FLAME_environment_variable_reg2_markup_factor;
/** \var int migration_region_id
* \brief A constant variable from the environment. */
int FLAME_environment_variable_migration_region_id;
/** \var double migration_allocation_quota
* \brief A constant variable from the environment. */
double FLAME_environment_variable_migration_allocation_quota;
/** \var int migration_allocation_policy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_migration_allocation_policy;
/** \var int migration_experiment
* \brief A constant variable from the environment. */
int FLAME_environment_variable_migration_experiment;
/** \var int minimum_wage_policy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_minimum_wage_policy;
/** \var double minimum_wage_policy_target_minimum_wage
* \brief A constant variable from the environment. */
double FLAME_environment_variable_minimum_wage_policy_target_minimum_wage;
/** \var int policy_migration_top_up_benefits
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_migration_top_up_benefits;
/** \var int policy_migration_wage_subsidies
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_migration_wage_subsidies;
/** \var int policy_migration_wage_subsidies_targeted
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_migration_wage_subsidies_targeted;
/** \var double migration_top_up_benefit
* \brief A constant variable from the environment. */
double FLAME_environment_variable_migration_top_up_benefit;
/** \var int migration_date
* \brief A constant variable from the environment. */
int FLAME_environment_variable_migration_date;
/** \var double gov_policy_gdp_fraction_consumption
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gov_policy_gdp_fraction_consumption;
/** \var int exp_firm_subsidy_scenario
* \brief A constant variable from the environment. */
int FLAME_environment_variable_exp_firm_subsidy_scenario;
/** \var int austerity_policy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_austerity_policy;
/** \var int austerity_policy_scenario
* \brief A constant variable from the environment. */
int FLAME_environment_variable_austerity_policy_scenario;
/** \var int austerity_repay_scenario
* \brief A constant variable from the environment. */
int FLAME_environment_variable_austerity_repay_scenario;
/** \var double austerity_consumption_threshold
* \brief A constant variable from the environment. */
double FLAME_environment_variable_austerity_consumption_threshold;
/** \var double austerity_debt_threshold
* \brief A constant variable from the environment. */
double FLAME_environment_variable_austerity_debt_threshold;
/** \var int austerity_repayment_period
* \brief A constant variable from the environment. */
int FLAME_environment_variable_austerity_repayment_period;
/** \var double gov_policy_gdp_fraction_investment
* \brief A constant variable from the environment. */
double FLAME_environment_variable_gov_policy_gdp_fraction_investment;
/** \var int no_regions_per_gov
* \brief A constant variable from the environment. */
int FLAME_environment_variable_no_regions_per_gov;
/** \var int flexibility_policy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_flexibility_policy;
/** \var int gov_budgeting_horizon
* \brief A constant variable from the environment. */
int FLAME_environment_variable_gov_budgeting_horizon;
/** \var double subsidy_trigger_on
* \brief A constant variable from the environment. */
double FLAME_environment_variable_subsidy_trigger_on;
/** \var double subsidy_trigger_off
* \brief A constant variable from the environment. */
double FLAME_environment_variable_subsidy_trigger_off;
/** \var int policy_starting_at_iteration
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_starting_at_iteration;
/** \var int gov_policy_swith_quantitative_easing
* \brief A constant variable from the environment. */
int FLAME_environment_variable_gov_policy_swith_quantitative_easing;
/** \var int gov_policy_switch_human_capital_improvement
* \brief A constant variable from the environment. */
int FLAME_environment_variable_gov_policy_switch_human_capital_improvement;
/** \var int subsidy_redistribution
* \brief A constant variable from the environment. */
int FLAME_environment_variable_subsidy_redistribution;
/** \var int tech_policy_effectiveness_switch
* \brief A constant variable from the environment. */
int FLAME_environment_variable_tech_policy_effectiveness_switch;
/** \var double probability_tech_policy_effectiveness
* \brief A constant variable from the environment. */
double FLAME_environment_variable_probability_tech_policy_effectiveness;
/** \var int policy_exp_best_technology_subsidy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_exp_best_technology_subsidy;
/** \var double subsidy_redistribution_parameter
* \brief A constant variable from the environment. */
double FLAME_environment_variable_subsidy_redistribution_parameter;
/** \var int policy_exp_all_technologies_subsidy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_policy_exp_all_technologies_subsidy;
/** \var int regional_policy_technology_subsidy
* \brief A constant variable from the environment. */
int FLAME_environment_variable_regional_policy_technology_subsidy;
/** \var double best_technology_subsidy_pct
* \brief A constant variable from the environment. */
double FLAME_environment_variable_best_technology_subsidy_pct;
/** \var int innovation_switched_on
* \brief A constant variable from the environment. */
int FLAME_environment_variable_innovation_switched_on;
/** \var double mr_start_price
* \brief A constant variable from the environment. */
double FLAME_environment_variable_mr_start_price;
/** \var double mr_end_price
* \brief A constant variable from the environment. */
double FLAME_environment_variable_mr_end_price;
/** \var double mr_price_increment
* \brief A constant variable from the environment. */
double FLAME_environment_variable_mr_price_increment;
/** \var int max_no_employees_product_innovation
* \brief A constant variable from the environment. */
int FLAME_environment_variable_max_no_employees_product_innovation;
/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_bank_account_update * temp_bank_account_update_message
* \brief Pointer to m_bank_account_update to initialise linked list. */
m_bank_account_update * temp_bank_account_update_message;
/** \var m_bank_to_central_bank_account_update * temp_bank_to_central_bank_account_update_message
* \brief Pointer to m_bank_to_central_bank_account_update to initialise linked list. */
m_bank_to_central_bank_account_update * temp_bank_to_central_bank_account_update_message;
/** \var m_gov_to_central_bank_account_update * temp_gov_to_central_bank_account_update_message
* \brief Pointer to m_gov_to_central_bank_account_update to initialise linked list. */
m_gov_to_central_bank_account_update * temp_gov_to_central_bank_account_update_message;
/** \var m_wage_payment * temp_wage_payment_message
* \brief Pointer to m_wage_payment to initialise linked list. */
m_wage_payment * temp_wage_payment_message;
/** \var m_quality_price_info_1 * temp_quality_price_info_1_message
* \brief Pointer to m_quality_price_info_1 to initialise linked list. */
m_quality_price_info_1 * temp_quality_price_info_1_message;
/** \var m_quality_price_info_2 * temp_quality_price_info_2_message
* \brief Pointer to m_quality_price_info_2 to initialise linked list. */
m_quality_price_info_2 * temp_quality_price_info_2_message;
/** \var m_update_mall_stock * temp_update_mall_stock_message
* \brief Pointer to m_update_mall_stock to initialise linked list. */
m_update_mall_stock * temp_update_mall_stock_message;
/** \var m_consumption_request_1 * temp_consumption_request_1_message
* \brief Pointer to m_consumption_request_1 to initialise linked list. */
m_consumption_request_1 * temp_consumption_request_1_message;
/** \var m_consumption_request_2 * temp_consumption_request_2_message
* \brief Pointer to m_consumption_request_2 to initialise linked list. */
m_consumption_request_2 * temp_consumption_request_2_message;
/** \var m_accepted_consumption_1 * temp_accepted_consumption_1_message
* \brief Pointer to m_accepted_consumption_1 to initialise linked list. */
m_accepted_consumption_1 * temp_accepted_consumption_1_message;
/** \var m_accepted_consumption_2 * temp_accepted_consumption_2_message
* \brief Pointer to m_accepted_consumption_2 to initialise linked list. */
m_accepted_consumption_2 * temp_accepted_consumption_2_message;
/** \var m_sales * temp_sales_message
* \brief Pointer to m_sales to initialise linked list. */
m_sales * temp_sales_message;
/** \var m_specific_skill_update * temp_specific_skill_update_message
* \brief Pointer to m_specific_skill_update to initialise linked list. */
m_specific_skill_update * temp_specific_skill_update_message;
/** \var m_policy_rate * temp_policy_rate_message
* \brief Pointer to m_policy_rate to initialise linked list. */
m_policy_rate * temp_policy_rate_message;
/** \var m_bank_identity * temp_bank_identity_message
* \brief Pointer to m_bank_identity to initialise linked list. */
m_bank_identity * temp_bank_identity_message;
/** \var m_loan_request * temp_loan_request_message
* \brief Pointer to m_loan_request to initialise linked list. */
m_loan_request * temp_loan_request_message;
/** \var m_loan_request_ranked * temp_loan_request_ranked_message
* \brief Pointer to m_loan_request_ranked to initialise linked list. */
m_loan_request_ranked * temp_loan_request_ranked_message;
/** \var m_loan_conditions * temp_loan_conditions_message
* \brief Pointer to m_loan_conditions to initialise linked list. */
m_loan_conditions * temp_loan_conditions_message;
/** \var m_loan_acceptance * temp_loan_acceptance_message
* \brief Pointer to m_loan_acceptance to initialise linked list. */
m_loan_acceptance * temp_loan_acceptance_message;
/** \var m_installment * temp_installment_message
* \brief Pointer to m_installment to initialise linked list. */
m_installment * temp_installment_message;
/** \var m_bankruptcy * temp_bankruptcy_message
* \brief Pointer to m_bankruptcy to initialise linked list. */
m_bankruptcy * temp_bankruptcy_message;
/** \var m_bank_interest_payment * temp_bank_interest_payment_message
* \brief Pointer to m_bank_interest_payment to initialise linked list. */
m_bank_interest_payment * temp_bank_interest_payment_message;
/** \var m_account_interest * temp_account_interest_message
* \brief Pointer to m_account_interest to initialise linked list. */
m_account_interest * temp_account_interest_message;
/** \var m_ecb_dividend * temp_ecb_dividend_message
* \brief Pointer to m_ecb_dividend to initialise linked list. */
m_ecb_dividend * temp_ecb_dividend_message;
/** \var m_credit_var_update * temp_credit_var_update_message
* \brief Pointer to m_credit_var_update to initialise linked list. */
m_credit_var_update * temp_credit_var_update_message;
/** \var m_bankruptcy_illiquidity * temp_bankruptcy_illiquidity_message
* \brief Pointer to m_bankruptcy_illiquidity to initialise linked list. */
m_bankruptcy_illiquidity * temp_bankruptcy_illiquidity_message;
/** \var m_bankruptcy_insolvency * temp_bankruptcy_insolvency_message
* \brief Pointer to m_bankruptcy_insolvency to initialise linked list. */
m_bankruptcy_insolvency * temp_bankruptcy_insolvency_message;
/** \var m_index_info * temp_index_info_message
* \brief Pointer to m_index_info to initialise linked list. */
m_index_info * temp_index_info_message;
/** \var m_index_price * temp_index_price_message
* \brief Pointer to m_index_price to initialise linked list. */
m_index_price * temp_index_price_message;
/** \var m_order * temp_order_message
* \brief Pointer to m_order to initialise linked list. */
m_order * temp_order_message;
/** \var m_order_status * temp_order_status_message
* \brief Pointer to m_order_status to initialise linked list. */
m_order_status * temp_order_status_message;
/** \var m_dividend_info * temp_dividend_info_message
* \brief Pointer to m_dividend_info to initialise linked list. */
m_dividend_info * temp_dividend_info_message;
/** \var m_productivity * temp_productivity_message
* \brief Pointer to m_productivity to initialise linked list. */
m_productivity * temp_productivity_message;
/** \var m_capital_good_request * temp_capital_good_request_message
* \brief Pointer to m_capital_good_request to initialise linked list. */
m_capital_good_request * temp_capital_good_request_message;
/** \var m_capital_good_delivery * temp_capital_good_delivery_message
* \brief Pointer to m_capital_good_delivery to initialise linked list. */
m_capital_good_delivery * temp_capital_good_delivery_message;
/** \var m_pay_capital_goods * temp_pay_capital_goods_message
* \brief Pointer to m_pay_capital_goods to initialise linked list. */
m_pay_capital_goods * temp_pay_capital_goods_message;
/** \var m_vacancies * temp_vacancies_message
* \brief Pointer to m_vacancies to initialise linked list. */
m_vacancies * temp_vacancies_message;
/** \var m_vacancies2 * temp_vacancies2_message
* \brief Pointer to m_vacancies2 to initialise linked list. */
m_vacancies2 * temp_vacancies2_message;
/** \var m_vacancies_r_and_d_employees * temp_vacancies_r_and_d_employees_message
* \brief Pointer to m_vacancies_r_and_d_employees to initialise linked list. */
m_vacancies_r_and_d_employees * temp_vacancies_r_and_d_employees_message;
/** \var m_vacancies_r_and_d_employees2 * temp_vacancies_r_and_d_employees2_message
* \brief Pointer to m_vacancies_r_and_d_employees2 to initialise linked list. */
m_vacancies_r_and_d_employees2 * temp_vacancies_r_and_d_employees2_message;
/** \var m_firing * temp_firing_message
* \brief Pointer to m_firing to initialise linked list. */
m_firing * temp_firing_message;
/** \var m_job_application * temp_job_application_message
* \brief Pointer to m_job_application to initialise linked list. */
m_job_application * temp_job_application_message;
/** \var m_job_application2 * temp_job_application2_message
* \brief Pointer to m_job_application2 to initialise linked list. */
m_job_application2 * temp_job_application2_message;
/** \var m_job_offer * temp_job_offer_message
* \brief Pointer to m_job_offer to initialise linked list. */
m_job_offer * temp_job_offer_message;
/** \var m_job_offer2 * temp_job_offer2_message
* \brief Pointer to m_job_offer2 to initialise linked list. */
m_job_offer2 * temp_job_offer2_message;
/** \var m_job_acceptance * temp_job_acceptance_message
* \brief Pointer to m_job_acceptance to initialise linked list. */
m_job_acceptance * temp_job_acceptance_message;
/** \var m_job_acceptance2 * temp_job_acceptance2_message
* \brief Pointer to m_job_acceptance2 to initialise linked list. */
m_job_acceptance2 * temp_job_acceptance2_message;
/** \var m_quitting * temp_quitting_message
* \brief Pointer to m_quitting to initialise linked list. */
m_quitting * temp_quitting_message;
/** \var m_quitting2 * temp_quitting2_message
* \brief Pointer to m_quitting2 to initialise linked list. */
m_quitting2 * temp_quitting2_message;
/** \var m_unemployment_notification * temp_unemployment_notification_message
* \brief Pointer to m_unemployment_notification to initialise linked list. */
m_unemployment_notification * temp_unemployment_notification_message;
/** \var m_policy_announcement * temp_policy_announcement_message
* \brief Pointer to m_policy_announcement to initialise linked list. */
m_policy_announcement * temp_policy_announcement_message;
/** \var m_tax_payment * temp_tax_payment_message
* \brief Pointer to m_tax_payment to initialise linked list. */
m_tax_payment * temp_tax_payment_message;
/** \var m_unemployment_benefit_restitution * temp_unemployment_benefit_restitution_message
* \brief Pointer to m_unemployment_benefit_restitution to initialise linked list. */
m_unemployment_benefit_restitution * temp_unemployment_benefit_restitution_message;
/** \var m_hh_transfer_notification * temp_hh_transfer_notification_message
* \brief Pointer to m_hh_transfer_notification to initialise linked list. */
m_hh_transfer_notification * temp_hh_transfer_notification_message;
/** \var m_hh_subsidy_notification * temp_hh_subsidy_notification_message
* \brief Pointer to m_hh_subsidy_notification to initialise linked list. */
m_hh_subsidy_notification * temp_hh_subsidy_notification_message;
/** \var m_human_capital_policy_announcement * temp_human_capital_policy_announcement_message
* \brief Pointer to m_human_capital_policy_announcement to initialise linked list. */
m_human_capital_policy_announcement * temp_human_capital_policy_announcement_message;
/** \var m_firm_transfer_notification * temp_firm_transfer_notification_message
* \brief Pointer to m_firm_transfer_notification to initialise linked list. */
m_firm_transfer_notification * temp_firm_transfer_notification_message;
/** \var m_firm_subsidy_notification * temp_firm_subsidy_notification_message
* \brief Pointer to m_firm_subsidy_notification to initialise linked list. */
m_firm_subsidy_notification * temp_firm_subsidy_notification_message;
/** \var m_request_fiat_money * temp_request_fiat_money_message
* \brief Pointer to m_request_fiat_money to initialise linked list. */
m_request_fiat_money * temp_request_fiat_money_message;
/** \var m_human_capital_policy_general_skill_information * temp_human_capital_policy_general_skill_information_message
* \brief Pointer to m_human_capital_policy_general_skill_information to initialise linked list. */
m_human_capital_policy_general_skill_information * temp_human_capital_policy_general_skill_information_message;
/** \var m_human_capital_policy_new_general_skill_notification * temp_human_capital_policy_new_general_skill_notification_message
* \brief Pointer to m_human_capital_policy_new_general_skill_notification to initialise linked list. */
m_human_capital_policy_new_general_skill_notification * temp_human_capital_policy_new_general_skill_notification_message;
/** \var m_firm_send_data * temp_firm_send_data_message
* \brief Pointer to m_firm_send_data to initialise linked list. */
m_firm_send_data * temp_firm_send_data_message;
/** \var m_government_send_data * temp_government_send_data_message
* \brief Pointer to m_government_send_data to initialise linked list. */
m_government_send_data * temp_government_send_data_message;
/** \var m_household_send_data * temp_household_send_data_message
* \brief Pointer to m_household_send_data to initialise linked list. */
m_household_send_data * temp_household_send_data_message;
/** \var m_mall_data * temp_mall_data_message
* \brief Pointer to m_mall_data to initialise linked list. */
m_mall_data * temp_mall_data_message;
/** \var m_eurostat_send_specific_skills * temp_eurostat_send_specific_skills_message
* \brief Pointer to m_eurostat_send_specific_skills to initialise linked list. */
m_eurostat_send_specific_skills * temp_eurostat_send_specific_skills_message;
/** \var m_data_for_government * temp_data_for_government_message
* \brief Pointer to m_data_for_government to initialise linked list. */
m_data_for_government * temp_data_for_government_message;
/** \var m_eurostat_send_macrodata * temp_eurostat_send_macrodata_message
* \brief Pointer to m_eurostat_send_macrodata to initialise linked list. */
m_eurostat_send_macrodata * temp_eurostat_send_macrodata_message;
/** \var m_msg_firm_id_to_malls * temp_msg_firm_id_to_malls_message
* \brief Pointer to m_msg_firm_id_to_malls to initialise linked list. */
m_msg_firm_id_to_malls * temp_msg_firm_id_to_malls_message;
/** \var m_msg_mall_id_to_firms * temp_msg_mall_id_to_firms_message
* \brief Pointer to m_msg_mall_id_to_firms to initialise linked list. */
m_msg_mall_id_to_firms * temp_msg_mall_id_to_firms_message;
/** \var m_msg_skills_eurostat_to_igfirm * temp_msg_skills_eurostat_to_igfirm_message
* \brief Pointer to m_msg_skills_eurostat_to_igfirm to initialise linked list. */
m_msg_skills_eurostat_to_igfirm * temp_msg_skills_eurostat_to_igfirm_message;
/** \var m_msg_market_sizes * temp_msg_market_sizes_message
* \brief Pointer to m_msg_market_sizes to initialise linked list. */
m_msg_market_sizes * temp_msg_market_sizes_message;
/** \var m_total_subsidies * temp_total_subsidies_message
* \brief Pointer to m_total_subsidies to initialise linked list. */
m_total_subsidies * temp_total_subsidies_message;
/** \var m_redistributed_subsidies * temp_redistributed_subsidies_message
* \brief Pointer to m_redistributed_subsidies to initialise linked list. */
m_redistributed_subsidies * temp_redistributed_subsidies_message;
/** \var m_quality_price * temp_quality_price_message
* \brief Pointer to m_quality_price to initialise linked list. */
m_quality_price * temp_quality_price_message;
/** \var m_interview_request * temp_interview_request_message
* \brief Pointer to m_interview_request to initialise linked list. */
m_interview_request * temp_interview_request_message;
/** \var m_interview_positive_response * temp_interview_positive_response_message
* \brief Pointer to m_interview_positive_response to initialise linked list. */
m_interview_positive_response * temp_interview_positive_response_message;
/** \var m_questionnaire_innovation * temp_questionnaire_innovation_message
* \brief Pointer to m_questionnaire_innovation to initialise linked list. */
m_questionnaire_innovation * temp_questionnaire_innovation_message;
/** \var m_filled_out_questionnaire_product_innovation * temp_filled_out_questionnaire_product_innovation_message
* \brief Pointer to m_filled_out_questionnaire_product_innovation to initialise linked list. */
m_filled_out_questionnaire_product_innovation * temp_filled_out_questionnaire_product_innovation_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[1000]
* \brief Output path for files. */
char outputpath[1000];
/** \var long total_time
* \brief Total time for the simulation run (in seconds) */
double total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
//xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Firm * current_xmachine_Firm;
/*@dependent@*/ xmachine_memory_Firm_holder * temp_xmachine_Firm_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Firm_holder * current_xmachine_Firm_holder;
xmachine_memory_Firm_state * current_xmachine_Firm_next_state; /* New agents added to this state */
/* Pointer to list of Firm agents in state MR_01 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_01;
xmachine_memory_Firm_state * Firm_MR_01_state;
/* Pointer to list of Firm agents in state MR_03 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_03;
xmachine_memory_Firm_state * Firm_MR_03_state;
/* Pointer to list of Firm agents in state MR_02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_02;
xmachine_memory_Firm_state * Firm_MR_02_state;
/* Pointer to list of Firm agents in state MR_6 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_6;
xmachine_memory_Firm_state * Firm_MR_6_state;
/* Pointer to list of Firm agents in state MR_5 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_5;
xmachine_memory_Firm_state * Firm_MR_5_state;
/* Pointer to list of Firm agents in state MR_4a state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_4a;
xmachine_memory_Firm_state * Firm_MR_4a_state;
/* Pointer to list of Firm agents in state MR_4 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_4;
xmachine_memory_Firm_state * Firm_MR_4_state;
/* Pointer to list of Firm agents in state MR_3 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_3;
xmachine_memory_Firm_state * Firm_MR_3_state;
/* Pointer to list of Firm agents in state MR_2 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_2;
xmachine_memory_Firm_state * Firm_MR_2_state;
/* Pointer to list of Firm agents in state MR_1 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_1;
xmachine_memory_Firm_state * Firm_MR_1_state;
/* Pointer to list of Firm agents in state MR_0 state */
//xmachine_memory_Firm * temp_xmachine_Firm_MR_0;
xmachine_memory_Firm_state * Firm_MR_0_state;
/* Pointer to list of Firm agents in state end_Firm state */
//xmachine_memory_Firm * temp_xmachine_Firm_end_Firm;
xmachine_memory_Firm_state * Firm_end_Firm_state;
/* Pointer to list of Firm agents in state Firm_Send_Data state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Send_Data;
xmachine_memory_Firm_state * Firm_Firm_Send_Data_state;
/* Pointer to list of Firm agents in state Firm_Start_Market_Research_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Market_Research_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Market_Research_Role_state;
/* Pointer to list of Firm agents in state Firm_init_01 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_init_01;
xmachine_memory_Firm_state * Firm_Firm_init_01_state;
/* Pointer to list of Firm agents in state Firm_reset state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_reset;
xmachine_memory_Firm_state * Firm_Firm_reset_state;
/* Pointer to list of Firm agents in state Firm_initialize state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_initialize;
xmachine_memory_Firm_state * Firm_Firm_initialize_state;
/* Pointer to list of Firm agents in state start_Firm state */
//xmachine_memory_Firm * temp_xmachine_Firm_start_Firm;
xmachine_memory_Firm_state * Firm_start_Firm_state;
/* Pointer to list of Firm agents in state 10 state */
//xmachine_memory_Firm * temp_xmachine_Firm_10;
xmachine_memory_Firm_state * Firm_10_state;
/* Pointer to list of Firm agents in state 09b state */
//xmachine_memory_Firm * temp_xmachine_Firm_09b;
xmachine_memory_Firm_state * Firm_09b_state;
/* Pointer to list of Firm agents in state 08 state */
//xmachine_memory_Firm * temp_xmachine_Firm_08;
xmachine_memory_Firm_state * Firm_08_state;
/* Pointer to list of Firm agents in state 07 state */
//xmachine_memory_Firm * temp_xmachine_Firm_07;
xmachine_memory_Firm_state * Firm_07_state;
/* Pointer to list of Firm agents in state 09a state */
//xmachine_memory_Firm * temp_xmachine_Firm_09a;
xmachine_memory_Firm_state * Firm_09a_state;
/* Pointer to list of Firm agents in state 06 state */
//xmachine_memory_Firm * temp_xmachine_Firm_06;
xmachine_memory_Firm_state * Firm_06_state;
/* Pointer to list of Firm agents in state 03d state */
//xmachine_memory_Firm * temp_xmachine_Firm_03d;
xmachine_memory_Firm_state * Firm_03d_state;
/* Pointer to list of Firm agents in state 03c state */
//xmachine_memory_Firm * temp_xmachine_Firm_03c;
xmachine_memory_Firm_state * Firm_03c_state;
/* Pointer to list of Firm agents in state 09c state */
//xmachine_memory_Firm * temp_xmachine_Firm_09c;
xmachine_memory_Firm_state * Firm_09c_state;
/* Pointer to list of Firm agents in state 05b state */
//xmachine_memory_Firm * temp_xmachine_Firm_05b;
xmachine_memory_Firm_state * Firm_05b_state;
/* Pointer to list of Firm agents in state 05a state */
//xmachine_memory_Firm * temp_xmachine_Firm_05a;
xmachine_memory_Firm_state * Firm_05a_state;
/* Pointer to list of Firm agents in state 04 state */
//xmachine_memory_Firm * temp_xmachine_Firm_04;
xmachine_memory_Firm_state * Firm_04_state;
/* Pointer to list of Firm agents in state 03ccc state */
//xmachine_memory_Firm * temp_xmachine_Firm_03ccc;
xmachine_memory_Firm_state * Firm_03ccc_state;
/* Pointer to list of Firm agents in state 03 state */
//xmachine_memory_Firm * temp_xmachine_Firm_03;
xmachine_memory_Firm_state * Firm_03_state;
/* Pointer to list of Firm agents in state 04ccc state */
//xmachine_memory_Firm * temp_xmachine_Firm_04ccc;
xmachine_memory_Firm_state * Firm_04ccc_state;
/* Pointer to list of Firm agents in state 011 state */
//xmachine_memory_Firm * temp_xmachine_Firm_011;
xmachine_memory_Firm_state * Firm_011_state;
/* Pointer to list of Firm agents in state 011a state */
//xmachine_memory_Firm * temp_xmachine_Firm_011a;
xmachine_memory_Firm_state * Firm_011a_state;
/* Pointer to list of Firm agents in state 16 state */
//xmachine_memory_Firm * temp_xmachine_Firm_16;
xmachine_memory_Firm_state * Firm_16_state;
/* Pointer to list of Firm agents in state 15 state */
//xmachine_memory_Firm * temp_xmachine_Firm_15;
xmachine_memory_Firm_state * Firm_15_state;
/* Pointer to list of Firm agents in state Firm_End_Branches state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Branches;
xmachine_memory_Firm_state * Firm_Firm_End_Branches_state;
/* Pointer to list of Firm agents in state Firm_bankruptcy_state_4 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankruptcy_state_4;
xmachine_memory_Firm_state * Firm_Firm_bankruptcy_state_4_state;
/* Pointer to list of Firm agents in state Firm_is_active state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_is_active;
xmachine_memory_Firm_state * Firm_Firm_is_active_state;
/* Pointer to list of Firm agents in state Firm_bankruptcy_state_1 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankruptcy_state_1;
xmachine_memory_Firm_state * Firm_Firm_bankruptcy_state_1_state;
/* Pointer to list of Firm agents in state Firm_bankruptcy_state_01 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankruptcy_state_01;
xmachine_memory_Firm_state * Firm_Firm_bankruptcy_state_01_state;
/* Pointer to list of Firm agents in state Firm_bankruptcy_state_0 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankruptcy_state_0;
xmachine_memory_Firm_state * Firm_Firm_bankruptcy_state_0_state;
/* Pointer to list of Firm agents in state Firm_not_active state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_not_active;
xmachine_memory_Firm_state * Firm_Firm_not_active_state;
/* Pointer to list of Firm agents in state 005 state */
//xmachine_memory_Firm * temp_xmachine_Firm_005;
xmachine_memory_Firm_state * Firm_005_state;
/* Pointer to list of Firm agents in state Firm_End_External_Financing state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_External_Financing;
xmachine_memory_Firm_state * Firm_Firm_End_External_Financing_state;
/* Pointer to list of Firm agents in state Firm_resolve_financial_crisis state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_resolve_financial_crisis;
xmachine_memory_Firm_state * Firm_Firm_resolve_financial_crisis_state;
/* Pointer to list of Firm agents in state Firm_checks_financial_crisis state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_checks_financial_crisis;
xmachine_memory_Firm_state * Firm_Firm_checks_financial_crisis_state;
/* Pointer to list of Firm agents in state Firm_variables_reset2 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_variables_reset2;
xmachine_memory_Firm_state * Firm_Firm_variables_reset2_state;
/* Pointer to list of Firm agents in state Firm_bankruptcy_checked state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankruptcy_checked;
xmachine_memory_Firm_state * Firm_Firm_bankruptcy_checked_state;
/* Pointer to list of Firm agents in state 02b state */
//xmachine_memory_Firm * temp_xmachine_Firm_02b;
xmachine_memory_Firm_state * Firm_02b_state;
/* Pointer to list of Firm agents in state Firm_variables_reset state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_variables_reset;
xmachine_memory_Firm_state * Firm_Firm_variables_reset_state;
/* Pointer to list of Firm agents in state Firm_Bankruptcy_check state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Bankruptcy_check;
xmachine_memory_Firm_state * Firm_Firm_Bankruptcy_check_state;
/* Pointer to list of Firm agents in state 004 state */
//xmachine_memory_Firm * temp_xmachine_Firm_004;
xmachine_memory_Firm_state * Firm_004_state;
/* Pointer to list of Firm agents in state 003 state */
//xmachine_memory_Firm * temp_xmachine_Firm_003;
xmachine_memory_Firm_state * Firm_003_state;
/* Pointer to list of Firm agents in state 002 state */
//xmachine_memory_Firm * temp_xmachine_Firm_002;
xmachine_memory_Firm_state * Firm_002_state;
/* Pointer to list of Firm agents in state 001 state */
//xmachine_memory_Firm * temp_xmachine_Firm_001;
xmachine_memory_Firm_state * Firm_001_state;
/* Pointer to list of Firm agents in state Firm_End_Public_Sector_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Public_Sector_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Public_Sector_Role_state;
/* Pointer to list of Firm agents in state Firm_End_Credit_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Credit_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Credit_Role_state;
/* Pointer to list of Firm agents in state Firm_Credit_02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Credit_02;
xmachine_memory_Firm_state * Firm_Firm_Credit_02_state;
/* Pointer to list of Firm agents in state Firm_Start_Credit_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Credit_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Credit_Role_state;
/* Pointer to list of Firm agents in state Firm_checks_if_active state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_checks_if_active;
xmachine_memory_Firm_state * Firm_Firm_checks_if_active_state;
/* Pointer to list of Firm agents in state Firm_interest state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_interest;
xmachine_memory_Firm_state * Firm_Firm_interest_state;
/* Pointer to list of Firm agents in state Firm_Start_Financial_Management_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Financial_Management_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Financial_Management_Role_state;
/* Pointer to list of Firm agents in state Firm_End_Financial_Management_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Financial_Management_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Financial_Management_Role_state;
/* Pointer to list of Firm agents in state 14 state */
//xmachine_memory_Firm * temp_xmachine_Firm_14;
xmachine_memory_Firm_state * Firm_14_state;
/* Pointer to list of Firm agents in state Firm_End_Seller_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Seller_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Seller_Role_state;
/* Pointer to list of Firm agents in state Firm_Start_Seller_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Seller_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Seller_Role_state;
/* Pointer to list of Firm agents in state 12 state */
//xmachine_memory_Firm * temp_xmachine_Firm_12;
xmachine_memory_Firm_state * Firm_12_state;
/* Pointer to list of Firm agents in state 11 state */
//xmachine_memory_Firm * temp_xmachine_Firm_11;
xmachine_memory_Firm_state * Firm_11_state;
/* Pointer to list of Firm agents in state 11b state */
//xmachine_memory_Firm * temp_xmachine_Firm_11b;
xmachine_memory_Firm_state * Firm_11b_state;
/* Pointer to list of Firm agents in state 11a state */
//xmachine_memory_Firm * temp_xmachine_Firm_11a;
xmachine_memory_Firm_state * Firm_11a_state;
/* Pointer to list of Firm agents in state Firm_End_Labour_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Labour_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Labour_Role_state;
/* Pointer to list of Firm agents in state Firm_Start_Labour_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Labour_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Labour_Role_state;
/* Pointer to list of Firm agents in state Firm_End_Financial_Management state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Financial_Management;
xmachine_memory_Firm_state * Firm_Firm_End_Financial_Management_state;
/* Pointer to list of Firm agents in state 02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_02;
xmachine_memory_Firm_state * Firm_02_state;
/* Pointer to list of Firm agents in state 00b state */
//xmachine_memory_Firm * temp_xmachine_Firm_00b;
xmachine_memory_Firm_state * Firm_00b_state;
/* Pointer to list of Firm agents in state 01 state */
//xmachine_memory_Firm * temp_xmachine_Firm_01;
xmachine_memory_Firm_state * Firm_01_state;
/* Pointer to list of Firm agents in state Firm_Start_Producer_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Producer_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Producer_Role_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Household * current_xmachine_Household;
/*@dependent@*/ xmachine_memory_Household_holder * temp_xmachine_Household_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Household_holder * current_xmachine_Household_holder;
xmachine_memory_Household_state * current_xmachine_Household_next_state; /* New agents added to this state */
/* Pointer to list of Household agents in state HH_MR_2 state */
//xmachine_memory_Household * temp_xmachine_Household_HH_MR_2;
xmachine_memory_Household_state * Household_HH_MR_2_state;
/* Pointer to list of Household agents in state HH_MR_1 state */
//xmachine_memory_Household * temp_xmachine_Household_HH_MR_1;
xmachine_memory_Household_state * Household_HH_MR_1_state;
/* Pointer to list of Household agents in state end_Household state */
//xmachine_memory_Household * temp_xmachine_Household_end_Household;
xmachine_memory_Household_state * Household_end_Household_state;
/* Pointer to list of Household agents in state 17 state */
//xmachine_memory_Household * temp_xmachine_Household_17;
xmachine_memory_Household_state * Household_17_state;
/* Pointer to list of Household agents in state Household_Start_Market_Research_Role state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Market_Research_Role;
xmachine_memory_Household_state * Household_Household_Start_Market_Research_Role_state;
/* Pointer to list of Household agents in state Household_Start_Policy_Data state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Policy_Data;
xmachine_memory_Household_state * Household_Household_Start_Policy_Data_state;
/* Pointer to list of Household agents in state Pol_01 state */
//xmachine_memory_Household * temp_xmachine_Household_Pol_01;
xmachine_memory_Household_state * Household_Pol_01_state;
/* Pointer to list of Household agents in state Household_Start_Yearly_Loop_Top state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Yearly_Loop_Top;
xmachine_memory_Household_state * Household_Household_Start_Yearly_Loop_Top_state;
/* Pointer to list of Household agents in state Household_initialize state */
//xmachine_memory_Household * temp_xmachine_Household_Household_initialize;
xmachine_memory_Household_state * Household_Household_initialize_state;
/* Pointer to list of Household agents in state start_Household state */
//xmachine_memory_Household * temp_xmachine_Household_start_Household;
xmachine_memory_Household_state * Household_start_Household_state;
/* Pointer to list of Household agents in state 08b state */
//xmachine_memory_Household * temp_xmachine_Household_08b;
xmachine_memory_Household_state * Household_08b_state;
/* Pointer to list of Household agents in state 08 state */
//xmachine_memory_Household * temp_xmachine_Household_08;
xmachine_memory_Household_state * Household_08_state;
/* Pointer to list of Household agents in state 07 state */
//xmachine_memory_Household * temp_xmachine_Household_07;
xmachine_memory_Household_state * Household_07_state;
/* Pointer to list of Household agents in state 06e state */
//xmachine_memory_Household * temp_xmachine_Household_06e;
xmachine_memory_Household_state * Household_06e_state;
/* Pointer to list of Household agents in state 06d state */
//xmachine_memory_Household * temp_xmachine_Household_06d;
xmachine_memory_Household_state * Household_06d_state;
/* Pointer to list of Household agents in state 06c state */
//xmachine_memory_Household * temp_xmachine_Household_06c;
xmachine_memory_Household_state * Household_06c_state;
/* Pointer to list of Household agents in state 06b state */
//xmachine_memory_Household * temp_xmachine_Household_06b;
xmachine_memory_Household_state * Household_06b_state;
/* Pointer to list of Household agents in state 05 state */
//xmachine_memory_Household * temp_xmachine_Household_05;
xmachine_memory_Household_state * Household_05_state;
/* Pointer to list of Household agents in state 04 state */
//xmachine_memory_Household * temp_xmachine_Household_04;
xmachine_memory_Household_state * Household_04_state;
/* Pointer to list of Household agents in state 03 state */
//xmachine_memory_Household * temp_xmachine_Household_03;
xmachine_memory_Household_state * Household_03_state;
/* Pointer to list of Household agents in state 02 state */
//xmachine_memory_Household * temp_xmachine_Household_02;
xmachine_memory_Household_state * Household_02_state;
/* Pointer to list of Household agents in state 06 state */
//xmachine_memory_Household * temp_xmachine_Household_06;
xmachine_memory_Household_state * Household_06_state;
/* Pointer to list of Household agents in state 01 state */
//xmachine_memory_Household * temp_xmachine_Household_01;
xmachine_memory_Household_state * Household_01_state;
/* Pointer to list of Household agents in state 01a state */
//xmachine_memory_Household * temp_xmachine_Household_01a;
xmachine_memory_Household_state * Household_01a_state;
/* Pointer to list of Household agents in state 01d state */
//xmachine_memory_Household * temp_xmachine_Household_01d;
xmachine_memory_Household_state * Household_01d_state;
/* Pointer to list of Household agents in state Household_Start_Labour_Role state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Labour_Role;
xmachine_memory_Household_state * Household_Household_Start_Labour_Role_state;
/* Pointer to list of Household agents in state AFM_002 state */
//xmachine_memory_Household * temp_xmachine_Household_AFM_002;
xmachine_memory_Household_state * Household_AFM_002_state;
/* Pointer to list of Household agents in state AFM_001 state */
//xmachine_memory_Household * temp_xmachine_Household_AFM_001;
xmachine_memory_Household_state * Household_AFM_001_state;
/* Pointer to list of Household agents in state AFM_000 state */
//xmachine_memory_Household * temp_xmachine_Household_AFM_000;
xmachine_memory_Household_state * Household_AFM_000_state;
/* Pointer to list of Household agents in state Household_Start_Financial_Market_Role state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Financial_Market_Role;
xmachine_memory_Household_state * Household_Household_Start_Financial_Market_Role_state;
/* Pointer to list of Household agents in state 16 state */
//xmachine_memory_Household * temp_xmachine_Household_16;
xmachine_memory_Household_state * Household_16_state;
/* Pointer to list of Household agents in state 12 state */
//xmachine_memory_Household * temp_xmachine_Household_12;
xmachine_memory_Household_state * Household_12_state;
/* Pointer to list of Household agents in state 14 state */
//xmachine_memory_Household * temp_xmachine_Household_14;
xmachine_memory_Household_state * Household_14_state;
/* Pointer to list of Household agents in state 11 state */
//xmachine_memory_Household * temp_xmachine_Household_11;
xmachine_memory_Household_state * Household_11_state;
/* Pointer to list of Household agents in state 10 state */
//xmachine_memory_Household * temp_xmachine_Household_10;
xmachine_memory_Household_state * Household_10_state;
/* Pointer to list of Household agents in state 15 state */
//xmachine_memory_Household * temp_xmachine_Household_15;
xmachine_memory_Household_state * Household_15_state;
/* Pointer to list of Household agents in state 09 state */
//xmachine_memory_Household * temp_xmachine_Household_09;
xmachine_memory_Household_state * Household_09_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Mall * current_xmachine_Mall;
/*@dependent@*/ xmachine_memory_Mall_holder * temp_xmachine_Mall_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Mall_holder * current_xmachine_Mall_holder;
xmachine_memory_Mall_state * current_xmachine_Mall_next_state; /* New agents added to this state */
/* Pointer to list of Mall agents in state Mall_initialize state */
//xmachine_memory_Mall * temp_xmachine_Mall_Mall_initialize;
xmachine_memory_Mall_state * Mall_Mall_initialize_state;
/* Pointer to list of Mall agents in state start_Mall state */
//xmachine_memory_Mall * temp_xmachine_Mall_start_Mall;
xmachine_memory_Mall_state * Mall_start_Mall_state;
/* Pointer to list of Mall agents in state end_Mall state */
//xmachine_memory_Mall * temp_xmachine_Mall_end_Mall;
xmachine_memory_Mall_state * Mall_end_Mall_state;
/* Pointer to list of Mall agents in state 06 state */
//xmachine_memory_Mall * temp_xmachine_Mall_06;
xmachine_memory_Mall_state * Mall_06_state;
/* Pointer to list of Mall agents in state 05a state */
//xmachine_memory_Mall * temp_xmachine_Mall_05a;
xmachine_memory_Mall_state * Mall_05a_state;
/* Pointer to list of Mall agents in state 05 state */
//xmachine_memory_Mall * temp_xmachine_Mall_05;
xmachine_memory_Mall_state * Mall_05_state;
/* Pointer to list of Mall agents in state 04 state */
//xmachine_memory_Mall * temp_xmachine_Mall_04;
xmachine_memory_Mall_state * Mall_04_state;
/* Pointer to list of Mall agents in state 03 state */
//xmachine_memory_Mall * temp_xmachine_Mall_03;
xmachine_memory_Mall_state * Mall_03_state;
/* Pointer to list of Mall agents in state 02 state */
//xmachine_memory_Mall * temp_xmachine_Mall_02;
xmachine_memory_Mall_state * Mall_02_state;
/* Pointer to list of Mall agents in state 01 state */
//xmachine_memory_Mall * temp_xmachine_Mall_01;
xmachine_memory_Mall_state * Mall_01_state;
/* Pointer to list of Mall agents in state 001 state */
//xmachine_memory_Mall * temp_xmachine_Mall_001;
xmachine_memory_Mall_state * Mall_001_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_IGFirm * current_xmachine_IGFirm;
/*@dependent@*/ xmachine_memory_IGFirm_holder * temp_xmachine_IGFirm_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_IGFirm_holder * current_xmachine_IGFirm_holder;
xmachine_memory_IGFirm_state * current_xmachine_IGFirm_next_state; /* New agents added to this state */
/* Pointer to list of IGFirm agents in state end_IGFirm state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_end_IGFirm;
xmachine_memory_IGFirm_state * IGFirm_end_IGFirm_state;
/* Pointer to list of IGFirm agents in state IGFirm_Send_Data state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_Send_Data;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_Send_Data_state;
/* Pointer to list of IGFirm agents in state IGFirm_End_Branches state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_End_Branches;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_End_Branches_state;
/* Pointer to list of IGFirm agents in state IGFirm_init_01 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_init_01;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_init_01_state;
/* Pointer to list of IGFirm agents in state IGFirm_start state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_start;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_start_state;
/* Pointer to list of IGFirm agents in state 03 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_03;
xmachine_memory_IGFirm_state * IGFirm_03_state;
/* Pointer to list of IGFirm agents in state 02 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_02;
xmachine_memory_IGFirm_state * IGFirm_02_state;
/* Pointer to list of IGFirm agents in state 01 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_01;
xmachine_memory_IGFirm_state * IGFirm_01_state;
/* Pointer to list of IGFirm agents in state 01a state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_01a;
xmachine_memory_IGFirm_state * IGFirm_01a_state;
/* Pointer to list of IGFirm agents in state Start_IGFirm_Productivity state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_Start_IGFirm_Productivity;
xmachine_memory_IGFirm_state * IGFirm_Start_IGFirm_Productivity_state;
/* Pointer to list of IGFirm agents in state 07 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_07;
xmachine_memory_IGFirm_state * IGFirm_07_state;
/* Pointer to list of IGFirm agents in state 06 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_06;
xmachine_memory_IGFirm_state * IGFirm_06_state;
/* Pointer to list of IGFirm agents in state 004 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_004;
xmachine_memory_IGFirm_state * IGFirm_004_state;
/* Pointer to list of IGFirm agents in state 003 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_003;
xmachine_memory_IGFirm_state * IGFirm_003_state;
/* Pointer to list of IGFirm agents in state 002 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_002;
xmachine_memory_IGFirm_state * IGFirm_002_state;
/* Pointer to list of IGFirm agents in state IGFirm_End_Public_Sector_Role state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_End_Public_Sector_Role;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_End_Public_Sector_Role_state;
/* Pointer to list of IGFirm agents in state 05 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_05;
xmachine_memory_IGFirm_state * IGFirm_05_state;
/* Pointer to list of IGFirm agents in state IGFirm_End_Financial_Management_Role state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_End_Financial_Management_Role;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_End_Financial_Management_Role_state;
/* Pointer to list of IGFirm agents in state IGFirm_Start_Financial_Management_Role state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_Start_Financial_Management_Role;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_Start_Financial_Management_Role_state;
/* Pointer to list of IGFirm agents in state IGFirm_End_Financial_Management state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_End_Financial_Management;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_End_Financial_Management_state;
/* Pointer to list of IGFirm agents in state 01kk state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_01kk;
xmachine_memory_IGFirm_state * IGFirm_01kk_state;
/* Pointer to list of IGFirm agents in state IGFirm_is_active state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_is_active;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_is_active_state;
/* Pointer to list of IGFirm agents in state IGFirm_checks_if_active state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_checks_if_active;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_checks_if_active_state;
/* Pointer to list of IGFirm agents in state IGFirm_interest state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_IGFirm_interest;
xmachine_memory_IGFirm_state * IGFirm_IGFirm_interest_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Eurostat * current_xmachine_Eurostat;
/*@dependent@*/ xmachine_memory_Eurostat_holder * temp_xmachine_Eurostat_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Eurostat_holder * current_xmachine_Eurostat_holder;
xmachine_memory_Eurostat_state * current_xmachine_Eurostat_next_state; /* New agents added to this state */
/* Pointer to list of Eurostat agents in state start_Eurostat state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_start_Eurostat;
xmachine_memory_Eurostat_state * Eurostat_start_Eurostat_state;
/* Pointer to list of Eurostat agents in state end_Eurostat state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_end_Eurostat;
xmachine_memory_Eurostat_state * Eurostat_end_Eurostat_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_EndOfYear_Loop state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_EndOfYear_Loop;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_EndOfYear_Loop_state;
/* Pointer to list of Eurostat agents in state 05 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_05;
xmachine_memory_Eurostat_state * Eurostat_05_state;
/* Pointer to list of Eurostat agents in state 04 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_04;
xmachine_memory_Eurostat_state * Eurostat_04_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_Quarterly_Loop state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_Quarterly_Loop;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_Quarterly_Loop_state;
/* Pointer to list of Eurostat agents in state 02 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_02;
xmachine_memory_Eurostat_state * Eurostat_02_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_Monthly_Loop state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_Monthly_Loop;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_Monthly_Loop_state;
/* Pointer to list of Eurostat agents in state 01 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_01;
xmachine_memory_Eurostat_state * Eurostat_01_state;
/* Pointer to list of Eurostat agents in state 00 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_00;
xmachine_memory_Eurostat_state * Eurostat_00_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Bank * current_xmachine_Bank;
/*@dependent@*/ xmachine_memory_Bank_holder * temp_xmachine_Bank_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Bank_holder * current_xmachine_Bank_holder;
xmachine_memory_Bank_state * current_xmachine_Bank_next_state; /* New agents added to this state */
/* Pointer to list of Bank agents in state Bank_reset state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_reset;
xmachine_memory_Bank_state * Bank_Bank_reset_state;
/* Pointer to list of Bank agents in state start_Bank state */
//xmachine_memory_Bank * temp_xmachine_Bank_start_Bank;
xmachine_memory_Bank_state * Bank_start_Bank_state;
/* Pointer to list of Bank agents in state end_Bank state */
//xmachine_memory_Bank * temp_xmachine_Bank_end_Bank;
xmachine_memory_Bank_state * Bank_end_Bank_state;
/* Pointer to list of Bank agents in state Bank_08 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_08;
xmachine_memory_Bank_state * Bank_Bank_08_state;
/* Pointer to list of Bank agents in state Bank_07 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_07;
xmachine_memory_Bank_state * Bank_Bank_07_state;
/* Pointer to list of Bank agents in state Bank_06 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_06;
xmachine_memory_Bank_state * Bank_Bank_06_state;
/* Pointer to list of Bank agents in state Bank_05 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_05;
xmachine_memory_Bank_state * Bank_Bank_05_state;
/* Pointer to list of Bank agents in state Bank_04 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_04;
xmachine_memory_Bank_state * Bank_Bank_04_state;
/* Pointer to list of Bank agents in state Bank_03 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_03;
xmachine_memory_Bank_state * Bank_Bank_03_state;
/* Pointer to list of Bank agents in state Bank_021 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_021;
xmachine_memory_Bank_state * Bank_Bank_021_state;
/* Pointer to list of Bank agents in state Bank_02 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_02;
xmachine_memory_Bank_state * Bank_Bank_02_state;
/* Pointer to list of Bank agents in state Bank_01b state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_01b;
xmachine_memory_Bank_state * Bank_Bank_01b_state;
/* Pointer to list of Bank agents in state Bank_01 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_01;
xmachine_memory_Bank_state * Bank_Bank_01_state;
/* Pointer to list of Bank agents in state Bank_start_credit_market_role state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_start_credit_market_role;
xmachine_memory_Bank_state * Bank_Bank_start_credit_market_role_state;
/* Pointer to list of Bank agents in state Bank_update_policy_rate state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_update_policy_rate;
xmachine_memory_Bank_state * Bank_Bank_update_policy_rate_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Government * current_xmachine_Government;
/*@dependent@*/ xmachine_memory_Government_holder * temp_xmachine_Government_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Government_holder * current_xmachine_Government_holder;
xmachine_memory_Government_state * current_xmachine_Government_next_state; /* New agents added to this state */
/* Pointer to list of Government agents in state end_Government state */
//xmachine_memory_Government * temp_xmachine_Government_end_Government;
xmachine_memory_Government_state * Government_end_Government_state;
/* Pointer to list of Government agents in state Gov_Start_Yearly_Loop state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Yearly_Loop;
xmachine_memory_Government_state * Government_Gov_Start_Yearly_Loop_state;
/* Pointer to list of Government agents in state 08 state */
//xmachine_memory_Government * temp_xmachine_Government_08;
xmachine_memory_Government_state * Government_08_state;
/* Pointer to list of Government agents in state 07 state */
//xmachine_memory_Government * temp_xmachine_Government_07;
xmachine_memory_Government_state * Government_07_state;
/* Pointer to list of Government agents in state Gov_bonds_decision state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_bonds_decision;
xmachine_memory_Government_state * Government_Gov_bonds_decision_state;
/* Pointer to list of Government agents in state 05a state */
//xmachine_memory_Government * temp_xmachine_Government_05a;
xmachine_memory_Government_state * Government_05a_state;
/* Pointer to list of Government agents in state 06 state */
//xmachine_memory_Government * temp_xmachine_Government_06;
xmachine_memory_Government_state * Government_06_state;
/* Pointer to list of Government agents in state Gov_Start_Monthly_Loop state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Monthly_Loop;
xmachine_memory_Government_state * Government_Gov_Start_Monthly_Loop_state;
/* Pointer to list of Government agents in state 04 state */
//xmachine_memory_Government * temp_xmachine_Government_04;
xmachine_memory_Government_state * Government_04_state;
/* Pointer to list of Government agents in state 03 state */
//xmachine_memory_Government * temp_xmachine_Government_03;
xmachine_memory_Government_state * Government_03_state;
/* Pointer to list of Government agents in state 02 state */
//xmachine_memory_Government * temp_xmachine_Government_02;
xmachine_memory_Government_state * Government_02_state;
/* Pointer to list of Government agents in state End_Gov_Consumer_Role state */
//xmachine_memory_Government * temp_xmachine_Government_End_Gov_Consumer_Role;
xmachine_memory_Government_state * Government_End_Gov_Consumer_Role_state;
/* Pointer to list of Government agents in state Gov_Cons_5 state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Cons_5;
xmachine_memory_Government_state * Government_Gov_Cons_5_state;
/* Pointer to list of Government agents in state Gov_Cons_4 state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Cons_4;
xmachine_memory_Government_state * Government_Gov_Cons_4_state;
/* Pointer to list of Government agents in state Gov_Cons_3 state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Cons_3;
xmachine_memory_Government_state * Government_Gov_Cons_3_state;
/* Pointer to list of Government agents in state Gov_Cons_2 state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Cons_2;
xmachine_memory_Government_state * Government_Gov_Cons_2_state;
/* Pointer to list of Government agents in state Gov_Cons_1 state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Cons_1;
xmachine_memory_Government_state * Government_Gov_Cons_1_state;
/* Pointer to list of Government agents in state 003b state */
//xmachine_memory_Government * temp_xmachine_Government_003b;
xmachine_memory_Government_state * Government_003b_state;
/* Pointer to list of Government agents in state 003a state */
//xmachine_memory_Government * temp_xmachine_Government_003a;
xmachine_memory_Government_state * Government_003a_state;
/* Pointer to list of Government agents in state 003 state */
//xmachine_memory_Government * temp_xmachine_Government_003;
xmachine_memory_Government_state * Government_003_state;
/* Pointer to list of Government agents in state 002 state */
//xmachine_memory_Government * temp_xmachine_Government_002;
xmachine_memory_Government_state * Government_002_state;
/* Pointer to list of Government agents in state Government_Start_Yearly_Loop_Top state */
//xmachine_memory_Government * temp_xmachine_Government_Government_Start_Yearly_Loop_Top;
xmachine_memory_Government_state * Government_Government_Start_Yearly_Loop_Top_state;
/* Pointer to list of Government agents in state 001 state */
//xmachine_memory_Government * temp_xmachine_Government_001;
xmachine_memory_Government_state * Government_001_state;
/* Pointer to list of Government agents in state Government_Start_Monthly_Loop_Top state */
//xmachine_memory_Government * temp_xmachine_Government_Government_Start_Monthly_Loop_Top;
xmachine_memory_Government_state * Government_Government_Start_Monthly_Loop_Top_state;
/* Pointer to list of Government agents in state start_Government state */
//xmachine_memory_Government * temp_xmachine_Government_start_Government;
xmachine_memory_Government_state * Government_start_Government_state;
/* Pointer to list of Government agents in state Start_Gov_Consumer_Role state */
//xmachine_memory_Government * temp_xmachine_Government_Start_Gov_Consumer_Role;
xmachine_memory_Government_state * Government_Start_Gov_Consumer_Role_state;
/* Pointer to list of Government agents in state Gov_Start_Bond_Market state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Bond_Market;
xmachine_memory_Government_state * Government_Gov_Start_Bond_Market_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_CentralBank * current_xmachine_CentralBank;
/*@dependent@*/ xmachine_memory_CentralBank_holder * temp_xmachine_CentralBank_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_CentralBank_holder * current_xmachine_CentralBank_holder;
xmachine_memory_CentralBank_state * current_xmachine_CentralBank_next_state; /* New agents added to this state */
/* Pointer to list of CentralBank agents in state CB_financial_operations_end state */
//xmachine_memory_CentralBank * temp_xmachine_CentralBank_CB_financial_operations_end;
xmachine_memory_CentralBank_state * CentralBank_CB_financial_operations_end_state;
/* Pointer to list of CentralBank agents in state CB_market_operations state */
//xmachine_memory_CentralBank * temp_xmachine_CentralBank_CB_market_operations;
xmachine_memory_CentralBank_state * CentralBank_CB_market_operations_state;
/* Pointer to list of CentralBank agents in state CB_reset state */
//xmachine_memory_CentralBank * temp_xmachine_CentralBank_CB_reset;
xmachine_memory_CentralBank_state * CentralBank_CB_reset_state;
/* Pointer to list of CentralBank agents in state start_Central_Bank state */
//xmachine_memory_CentralBank * temp_xmachine_CentralBank_start_Central_Bank;
xmachine_memory_CentralBank_state * CentralBank_start_Central_Bank_state;
/* Pointer to list of CentralBank agents in state end_Central_Bank state */
//xmachine_memory_CentralBank * temp_xmachine_CentralBank_end_Central_Bank;
xmachine_memory_CentralBank_state * CentralBank_end_Central_Bank_state;
/* Pointer to list of CentralBank agents in state 00 state */
//xmachine_memory_CentralBank * temp_xmachine_CentralBank_00;
xmachine_memory_CentralBank_state * CentralBank_00_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_ClearingHouse * current_xmachine_ClearingHouse;
/*@dependent@*/ xmachine_memory_ClearingHouse_holder * temp_xmachine_ClearingHouse_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_ClearingHouse_holder * current_xmachine_ClearingHouse_holder;
xmachine_memory_ClearingHouse_state * current_xmachine_ClearingHouse_next_state; /* New agents added to this state */
/* Pointer to list of ClearingHouse agents in state end_Clearinghouse state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_end_Clearinghouse;
xmachine_memory_ClearingHouse_state * ClearingHouse_end_Clearinghouse_state;
/* Pointer to list of ClearingHouse agents in state AFM_05 state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_AFM_05;
xmachine_memory_ClearingHouse_state * ClearingHouse_AFM_05_state;
/* Pointer to list of ClearingHouse agents in state AFM_04 state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_AFM_04;
xmachine_memory_ClearingHouse_state * ClearingHouse_AFM_04_state;
/* Pointer to list of ClearingHouse agents in state AFM_03 state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_AFM_03;
xmachine_memory_ClearingHouse_state * ClearingHouse_AFM_03_state;
/* Pointer to list of ClearingHouse agents in state AFM_02 state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_AFM_02;
xmachine_memory_ClearingHouse_state * ClearingHouse_AFM_02_state;
/* Pointer to list of ClearingHouse agents in state AFM_01 state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_AFM_01;
xmachine_memory_ClearingHouse_state * ClearingHouse_AFM_01_state;
/* Pointer to list of ClearingHouse agents in state AFM_00 state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_AFM_00;
xmachine_memory_ClearingHouse_state * ClearingHouse_AFM_00_state;
/* Pointer to list of ClearingHouse agents in state start_Clearinghouse state */
//xmachine_memory_ClearingHouse * temp_xmachine_ClearingHouse_start_Clearinghouse;
xmachine_memory_ClearingHouse_state * ClearingHouse_start_Clearinghouse_state;



MBt_Board b_bank_account_update;
MBt_Iterator i_bank_account_update;

MBt_Board b_bank_to_central_bank_account_update;
MBt_Iterator i_bank_to_central_bank_account_update;

MBt_Board b_gov_to_central_bank_account_update;
MBt_Iterator i_gov_to_central_bank_account_update;

MBt_Board b_wage_payment;
MBt_Iterator i_wage_payment;

MBt_Board b_quality_price_info_1;
MBt_Iterator i_quality_price_info_1;

MBt_Board b_quality_price_info_2;
MBt_Iterator i_quality_price_info_2;

MBt_Board b_update_mall_stock;
MBt_Iterator i_update_mall_stock;

MBt_Board b_consumption_request_1;
MBt_Iterator i_consumption_request_1;

MBt_Board b_consumption_request_2;
MBt_Iterator i_consumption_request_2;

MBt_Board b_accepted_consumption_1;
MBt_Iterator i_accepted_consumption_1;

MBt_Board b_accepted_consumption_2;
MBt_Iterator i_accepted_consumption_2;

MBt_Board b_sales;
MBt_Iterator i_sales;

MBt_Board b_specific_skill_update;
MBt_Iterator i_specific_skill_update;

MBt_Board b_policy_rate;
MBt_Iterator i_policy_rate;

MBt_Board b_bank_identity;
MBt_Iterator i_bank_identity;

MBt_Board b_loan_request;
MBt_Iterator i_loan_request;

MBt_Board b_loan_request_ranked;
MBt_Iterator i_loan_request_ranked;

MBt_Board b_loan_conditions;
MBt_Iterator i_loan_conditions;

MBt_Board b_loan_acceptance;
MBt_Iterator i_loan_acceptance;

MBt_Board b_installment;
MBt_Iterator i_installment;

MBt_Board b_bankruptcy;
MBt_Iterator i_bankruptcy;

MBt_Board b_bank_interest_payment;
MBt_Iterator i_bank_interest_payment;

MBt_Board b_account_interest;
MBt_Iterator i_account_interest;

MBt_Board b_ecb_dividend;
MBt_Iterator i_ecb_dividend;

MBt_Board b_credit_var_update;
MBt_Iterator i_credit_var_update;

MBt_Board b_bankruptcy_illiquidity;
MBt_Iterator i_bankruptcy_illiquidity;

MBt_Board b_bankruptcy_insolvency;
MBt_Iterator i_bankruptcy_insolvency;

MBt_Board b_index_info;
MBt_Iterator i_index_info;

MBt_Board b_index_price;
MBt_Iterator i_index_price;

MBt_Board b_order;
MBt_Iterator i_order;

MBt_Board b_order_status;
MBt_Iterator i_order_status;

MBt_Board b_dividend_info;
MBt_Iterator i_dividend_info;

MBt_Board b_productivity;
MBt_Iterator i_productivity;

MBt_Board b_capital_good_request;
MBt_Iterator i_capital_good_request;

MBt_Board b_capital_good_delivery;
MBt_Iterator i_capital_good_delivery;

MBt_Board b_pay_capital_goods;
MBt_Iterator i_pay_capital_goods;

MBt_Board b_vacancies;
MBt_Iterator i_vacancies;

MBt_Board b_vacancies2;
MBt_Iterator i_vacancies2;

MBt_Board b_vacancies_r_and_d_employees;
MBt_Iterator i_vacancies_r_and_d_employees;

MBt_Board b_vacancies_r_and_d_employees2;
MBt_Iterator i_vacancies_r_and_d_employees2;

MBt_Board b_firing;
MBt_Iterator i_firing;

MBt_Board b_job_application;
MBt_Iterator i_job_application;

MBt_Board b_job_application2;
MBt_Iterator i_job_application2;

MBt_Board b_job_offer;
MBt_Iterator i_job_offer;

MBt_Board b_job_offer2;
MBt_Iterator i_job_offer2;

MBt_Board b_job_acceptance;
MBt_Iterator i_job_acceptance;

MBt_Board b_job_acceptance2;
MBt_Iterator i_job_acceptance2;

MBt_Board b_quitting;
MBt_Iterator i_quitting;

MBt_Board b_quitting2;
MBt_Iterator i_quitting2;

MBt_Board b_unemployment_notification;
MBt_Iterator i_unemployment_notification;

MBt_Board b_policy_announcement;
MBt_Iterator i_policy_announcement;

MBt_Board b_tax_payment;
MBt_Iterator i_tax_payment;

MBt_Board b_unemployment_benefit_restitution;
MBt_Iterator i_unemployment_benefit_restitution;

MBt_Board b_hh_transfer_notification;
MBt_Iterator i_hh_transfer_notification;

MBt_Board b_hh_subsidy_notification;
MBt_Iterator i_hh_subsidy_notification;

MBt_Board b_human_capital_policy_announcement;
MBt_Iterator i_human_capital_policy_announcement;

MBt_Board b_firm_transfer_notification;
MBt_Iterator i_firm_transfer_notification;

MBt_Board b_firm_subsidy_notification;
MBt_Iterator i_firm_subsidy_notification;

MBt_Board b_request_fiat_money;
MBt_Iterator i_request_fiat_money;

MBt_Board b_human_capital_policy_general_skill_information;
MBt_Iterator i_human_capital_policy_general_skill_information;

MBt_Board b_human_capital_policy_new_general_skill_notification;
MBt_Iterator i_human_capital_policy_new_general_skill_notification;

MBt_Board b_firm_send_data;
MBt_Iterator i_firm_send_data;

MBt_Board b_government_send_data;
MBt_Iterator i_government_send_data;

MBt_Board b_household_send_data;
MBt_Iterator i_household_send_data;

MBt_Board b_mall_data;
MBt_Iterator i_mall_data;

MBt_Board b_eurostat_send_specific_skills;
MBt_Iterator i_eurostat_send_specific_skills;

MBt_Board b_data_for_government;
MBt_Iterator i_data_for_government;

MBt_Board b_eurostat_send_macrodata;
MBt_Iterator i_eurostat_send_macrodata;

MBt_Board b_msg_firm_id_to_malls;
MBt_Iterator i_msg_firm_id_to_malls;

MBt_Board b_msg_mall_id_to_firms;
MBt_Iterator i_msg_mall_id_to_firms;

MBt_Board b_msg_skills_eurostat_to_igfirm;
MBt_Iterator i_msg_skills_eurostat_to_igfirm;

MBt_Board b_msg_market_sizes;
MBt_Iterator i_msg_market_sizes;

MBt_Board b_total_subsidies;
MBt_Iterator i_total_subsidies;

MBt_Board b_redistributed_subsidies;
MBt_Iterator i_redistributed_subsidies;

MBt_Board b_quality_price;
MBt_Iterator i_quality_price;

MBt_Board b_interview_request;
MBt_Iterator i_interview_request;

MBt_Board b_interview_positive_response;
MBt_Iterator i_interview_positive_response;

MBt_Board b_questionnaire_innovation;
MBt_Iterator i_questionnaire_innovation;

MBt_Board b_filled_out_questionnaire_product_innovation;
MBt_Iterator i_filled_out_questionnaire_product_innovation;


/** \var m_bank_account_update * bank_account_update_message
* \brief Pointer to message struct for looping through bank_account_update message list */
m_bank_account_update * bank_account_update_message;
/** \var m_bank_to_central_bank_account_update * bank_to_central_bank_account_update_message
* \brief Pointer to message struct for looping through bank_to_central_bank_account_update message list */
m_bank_to_central_bank_account_update * bank_to_central_bank_account_update_message;
/** \var m_gov_to_central_bank_account_update * gov_to_central_bank_account_update_message
* \brief Pointer to message struct for looping through gov_to_central_bank_account_update message list */
m_gov_to_central_bank_account_update * gov_to_central_bank_account_update_message;
/** \var m_wage_payment * wage_payment_message
* \brief Pointer to message struct for looping through wage_payment message list */
m_wage_payment * wage_payment_message;
/** \var m_quality_price_info_1 * quality_price_info_1_message
* \brief Pointer to message struct for looping through quality_price_info_1 message list */
m_quality_price_info_1 * quality_price_info_1_message;
/** \var m_quality_price_info_2 * quality_price_info_2_message
* \brief Pointer to message struct for looping through quality_price_info_2 message list */
m_quality_price_info_2 * quality_price_info_2_message;
/** \var m_update_mall_stock * update_mall_stock_message
* \brief Pointer to message struct for looping through update_mall_stock message list */
m_update_mall_stock * update_mall_stock_message;
/** \var m_consumption_request_1 * consumption_request_1_message
* \brief Pointer to message struct for looping through consumption_request_1 message list */
m_consumption_request_1 * consumption_request_1_message;
/** \var m_consumption_request_2 * consumption_request_2_message
* \brief Pointer to message struct for looping through consumption_request_2 message list */
m_consumption_request_2 * consumption_request_2_message;
/** \var m_accepted_consumption_1 * accepted_consumption_1_message
* \brief Pointer to message struct for looping through accepted_consumption_1 message list */
m_accepted_consumption_1 * accepted_consumption_1_message;
/** \var m_accepted_consumption_2 * accepted_consumption_2_message
* \brief Pointer to message struct for looping through accepted_consumption_2 message list */
m_accepted_consumption_2 * accepted_consumption_2_message;
/** \var m_sales * sales_message
* \brief Pointer to message struct for looping through sales message list */
m_sales * sales_message;
/** \var m_specific_skill_update * specific_skill_update_message
* \brief Pointer to message struct for looping through specific_skill_update message list */
m_specific_skill_update * specific_skill_update_message;
/** \var m_policy_rate * policy_rate_message
* \brief Pointer to message struct for looping through policy_rate message list */
m_policy_rate * policy_rate_message;
/** \var m_bank_identity * bank_identity_message
* \brief Pointer to message struct for looping through bank_identity message list */
m_bank_identity * bank_identity_message;
/** \var m_loan_request * loan_request_message
* \brief Pointer to message struct for looping through loan_request message list */
m_loan_request * loan_request_message;
/** \var m_loan_request_ranked * loan_request_ranked_message
* \brief Pointer to message struct for looping through loan_request_ranked message list */
m_loan_request_ranked * loan_request_ranked_message;
/** \var m_loan_conditions * loan_conditions_message
* \brief Pointer to message struct for looping through loan_conditions message list */
m_loan_conditions * loan_conditions_message;
/** \var m_loan_acceptance * loan_acceptance_message
* \brief Pointer to message struct for looping through loan_acceptance message list */
m_loan_acceptance * loan_acceptance_message;
/** \var m_installment * installment_message
* \brief Pointer to message struct for looping through installment message list */
m_installment * installment_message;
/** \var m_bankruptcy * bankruptcy_message
* \brief Pointer to message struct for looping through bankruptcy message list */
m_bankruptcy * bankruptcy_message;
/** \var m_bank_interest_payment * bank_interest_payment_message
* \brief Pointer to message struct for looping through bank_interest_payment message list */
m_bank_interest_payment * bank_interest_payment_message;
/** \var m_account_interest * account_interest_message
* \brief Pointer to message struct for looping through account_interest message list */
m_account_interest * account_interest_message;
/** \var m_ecb_dividend * ecb_dividend_message
* \brief Pointer to message struct for looping through ecb_dividend message list */
m_ecb_dividend * ecb_dividend_message;
/** \var m_credit_var_update * credit_var_update_message
* \brief Pointer to message struct for looping through credit_var_update message list */
m_credit_var_update * credit_var_update_message;
/** \var m_bankruptcy_illiquidity * bankruptcy_illiquidity_message
* \brief Pointer to message struct for looping through bankruptcy_illiquidity message list */
m_bankruptcy_illiquidity * bankruptcy_illiquidity_message;
/** \var m_bankruptcy_insolvency * bankruptcy_insolvency_message
* \brief Pointer to message struct for looping through bankruptcy_insolvency message list */
m_bankruptcy_insolvency * bankruptcy_insolvency_message;
/** \var m_index_info * index_info_message
* \brief Pointer to message struct for looping through index_info message list */
m_index_info * index_info_message;
/** \var m_index_price * index_price_message
* \brief Pointer to message struct for looping through index_price message list */
m_index_price * index_price_message;
/** \var m_order * order_message
* \brief Pointer to message struct for looping through order message list */
m_order * order_message;
/** \var m_order_status * order_status_message
* \brief Pointer to message struct for looping through order_status message list */
m_order_status * order_status_message;
/** \var m_dividend_info * dividend_info_message
* \brief Pointer to message struct for looping through dividend_info message list */
m_dividend_info * dividend_info_message;
/** \var m_productivity * productivity_message
* \brief Pointer to message struct for looping through productivity message list */
m_productivity * productivity_message;
/** \var m_capital_good_request * capital_good_request_message
* \brief Pointer to message struct for looping through capital_good_request message list */
m_capital_good_request * capital_good_request_message;
/** \var m_capital_good_delivery * capital_good_delivery_message
* \brief Pointer to message struct for looping through capital_good_delivery message list */
m_capital_good_delivery * capital_good_delivery_message;
/** \var m_pay_capital_goods * pay_capital_goods_message
* \brief Pointer to message struct for looping through pay_capital_goods message list */
m_pay_capital_goods * pay_capital_goods_message;
/** \var m_vacancies * vacancies_message
* \brief Pointer to message struct for looping through vacancies message list */
m_vacancies * vacancies_message;
/** \var m_vacancies2 * vacancies2_message
* \brief Pointer to message struct for looping through vacancies2 message list */
m_vacancies2 * vacancies2_message;
/** \var m_vacancies_r_and_d_employees * vacancies_r_and_d_employees_message
* \brief Pointer to message struct for looping through vacancies_r_and_d_employees message list */
m_vacancies_r_and_d_employees * vacancies_r_and_d_employees_message;
/** \var m_vacancies_r_and_d_employees2 * vacancies_r_and_d_employees2_message
* \brief Pointer to message struct for looping through vacancies_r_and_d_employees2 message list */
m_vacancies_r_and_d_employees2 * vacancies_r_and_d_employees2_message;
/** \var m_firing * firing_message
* \brief Pointer to message struct for looping through firing message list */
m_firing * firing_message;
/** \var m_job_application * job_application_message
* \brief Pointer to message struct for looping through job_application message list */
m_job_application * job_application_message;
/** \var m_job_application2 * job_application2_message
* \brief Pointer to message struct for looping through job_application2 message list */
m_job_application2 * job_application2_message;
/** \var m_job_offer * job_offer_message
* \brief Pointer to message struct for looping through job_offer message list */
m_job_offer * job_offer_message;
/** \var m_job_offer2 * job_offer2_message
* \brief Pointer to message struct for looping through job_offer2 message list */
m_job_offer2 * job_offer2_message;
/** \var m_job_acceptance * job_acceptance_message
* \brief Pointer to message struct for looping through job_acceptance message list */
m_job_acceptance * job_acceptance_message;
/** \var m_job_acceptance2 * job_acceptance2_message
* \brief Pointer to message struct for looping through job_acceptance2 message list */
m_job_acceptance2 * job_acceptance2_message;
/** \var m_quitting * quitting_message
* \brief Pointer to message struct for looping through quitting message list */
m_quitting * quitting_message;
/** \var m_quitting2 * quitting2_message
* \brief Pointer to message struct for looping through quitting2 message list */
m_quitting2 * quitting2_message;
/** \var m_unemployment_notification * unemployment_notification_message
* \brief Pointer to message struct for looping through unemployment_notification message list */
m_unemployment_notification * unemployment_notification_message;
/** \var m_policy_announcement * policy_announcement_message
* \brief Pointer to message struct for looping through policy_announcement message list */
m_policy_announcement * policy_announcement_message;
/** \var m_tax_payment * tax_payment_message
* \brief Pointer to message struct for looping through tax_payment message list */
m_tax_payment * tax_payment_message;
/** \var m_unemployment_benefit_restitution * unemployment_benefit_restitution_message
* \brief Pointer to message struct for looping through unemployment_benefit_restitution message list */
m_unemployment_benefit_restitution * unemployment_benefit_restitution_message;
/** \var m_hh_transfer_notification * hh_transfer_notification_message
* \brief Pointer to message struct for looping through hh_transfer_notification message list */
m_hh_transfer_notification * hh_transfer_notification_message;
/** \var m_hh_subsidy_notification * hh_subsidy_notification_message
* \brief Pointer to message struct for looping through hh_subsidy_notification message list */
m_hh_subsidy_notification * hh_subsidy_notification_message;
/** \var m_human_capital_policy_announcement * human_capital_policy_announcement_message
* \brief Pointer to message struct for looping through human_capital_policy_announcement message list */
m_human_capital_policy_announcement * human_capital_policy_announcement_message;
/** \var m_firm_transfer_notification * firm_transfer_notification_message
* \brief Pointer to message struct for looping through firm_transfer_notification message list */
m_firm_transfer_notification * firm_transfer_notification_message;
/** \var m_firm_subsidy_notification * firm_subsidy_notification_message
* \brief Pointer to message struct for looping through firm_subsidy_notification message list */
m_firm_subsidy_notification * firm_subsidy_notification_message;
/** \var m_request_fiat_money * request_fiat_money_message
* \brief Pointer to message struct for looping through request_fiat_money message list */
m_request_fiat_money * request_fiat_money_message;
/** \var m_human_capital_policy_general_skill_information * human_capital_policy_general_skill_information_message
* \brief Pointer to message struct for looping through human_capital_policy_general_skill_information message list */
m_human_capital_policy_general_skill_information * human_capital_policy_general_skill_information_message;
/** \var m_human_capital_policy_new_general_skill_notification * human_capital_policy_new_general_skill_notification_message
* \brief Pointer to message struct for looping through human_capital_policy_new_general_skill_notification message list */
m_human_capital_policy_new_general_skill_notification * human_capital_policy_new_general_skill_notification_message;
/** \var m_firm_send_data * firm_send_data_message
* \brief Pointer to message struct for looping through firm_send_data message list */
m_firm_send_data * firm_send_data_message;
/** \var m_government_send_data * government_send_data_message
* \brief Pointer to message struct for looping through government_send_data message list */
m_government_send_data * government_send_data_message;
/** \var m_household_send_data * household_send_data_message
* \brief Pointer to message struct for looping through household_send_data message list */
m_household_send_data * household_send_data_message;
/** \var m_mall_data * mall_data_message
* \brief Pointer to message struct for looping through mall_data message list */
m_mall_data * mall_data_message;
/** \var m_eurostat_send_specific_skills * eurostat_send_specific_skills_message
* \brief Pointer to message struct for looping through eurostat_send_specific_skills message list */
m_eurostat_send_specific_skills * eurostat_send_specific_skills_message;
/** \var m_data_for_government * data_for_government_message
* \brief Pointer to message struct for looping through data_for_government message list */
m_data_for_government * data_for_government_message;
/** \var m_eurostat_send_macrodata * eurostat_send_macrodata_message
* \brief Pointer to message struct for looping through eurostat_send_macrodata message list */
m_eurostat_send_macrodata * eurostat_send_macrodata_message;
/** \var m_msg_firm_id_to_malls * msg_firm_id_to_malls_message
* \brief Pointer to message struct for looping through msg_firm_id_to_malls message list */
m_msg_firm_id_to_malls * msg_firm_id_to_malls_message;
/** \var m_msg_mall_id_to_firms * msg_mall_id_to_firms_message
* \brief Pointer to message struct for looping through msg_mall_id_to_firms message list */
m_msg_mall_id_to_firms * msg_mall_id_to_firms_message;
/** \var m_msg_skills_eurostat_to_igfirm * msg_skills_eurostat_to_igfirm_message
* \brief Pointer to message struct for looping through msg_skills_eurostat_to_igfirm message list */
m_msg_skills_eurostat_to_igfirm * msg_skills_eurostat_to_igfirm_message;
/** \var m_msg_market_sizes * msg_market_sizes_message
* \brief Pointer to message struct for looping through msg_market_sizes message list */
m_msg_market_sizes * msg_market_sizes_message;
/** \var m_total_subsidies * total_subsidies_message
* \brief Pointer to message struct for looping through total_subsidies message list */
m_total_subsidies * total_subsidies_message;
/** \var m_redistributed_subsidies * redistributed_subsidies_message
* \brief Pointer to message struct for looping through redistributed_subsidies message list */
m_redistributed_subsidies * redistributed_subsidies_message;
/** \var m_quality_price * quality_price_message
* \brief Pointer to message struct for looping through quality_price message list */
m_quality_price * quality_price_message;
/** \var m_interview_request * interview_request_message
* \brief Pointer to message struct for looping through interview_request message list */
m_interview_request * interview_request_message;
/** \var m_interview_positive_response * interview_positive_response_message
* \brief Pointer to message struct for looping through interview_positive_response message list */
m_interview_positive_response * interview_positive_response_message;
/** \var m_questionnaire_innovation * questionnaire_innovation_message
* \brief Pointer to message struct for looping through questionnaire_innovation message list */
m_questionnaire_innovation * questionnaire_innovation_message;
/** \var m_filled_out_questionnaire_product_innovation * filled_out_questionnaire_product_innovation_message
* \brief Pointer to message struct for looping through filled_out_questionnaire_product_innovation message list */
m_filled_out_questionnaire_product_innovation * filled_out_questionnaire_product_innovation_message;
/** \var FLAME_output ** FLAME_outputs
* \brief Pointer to list of outputs */
FLAME_output * FLAME_outputs;
/** \var node_information * p_node_info
* \brief Pointer to first pointer of node list */
node_information ** p_node_info;
/** \var node_information * current_node
* \brief Pointer to current node */
node_information * current_node;

/** \var int iteration_loop
* \brief The current iteration number */
int iteration_loop;
/** \var int output_frequency
* \brief Frequency to output results */
int output_frequency;
/** \var int output_offset
* \brief Offset to output results */
int output_offset;

/** \def SPINF
* \brief Dummy inf value for space partition data. */
#define SPINF 999999.123456
/** \def RELEASE
* \brief Used to kill an agent via 'return RELEASE;'. */
#define RELEASE 1
/** \def kill_me_now
* \brief Used to kill an agent via 'kill_me_now'. */
#define kill_me_now return 1

void initialise_pointers(void);
void initialise_unit_testing(void);
FLAME_output * add_FLAME_output(FLAME_output ** outputs);
void free_FLAME_outputs(FLAME_output ** outputs);
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_consumption_goods_offer_array(consumption_goods_offer_array * array);
void reset_consumption_goods_offer_array(consumption_goods_offer_array * array);
void free_consumption_goods_offer_array(consumption_goods_offer_array * array);
void copy_consumption_goods_offer_array(consumption_goods_offer_array * from, consumption_goods_offer_array * to);
void add_consumption_goods_offer(consumption_goods_offer_array * array,  int id,  double quality,  double price);
void remove_consumption_goods_offer(consumption_goods_offer_array * array, int index);

void init_estimators_linear_regression_array(estimators_linear_regression_array * array);
void reset_estimators_linear_regression_array(estimators_linear_regression_array * array);
void free_estimators_linear_regression_array(estimators_linear_regression_array * array);
void copy_estimators_linear_regression_array(estimators_linear_regression_array * from, estimators_linear_regression_array * to);
void add_estimators_linear_regression(estimators_linear_regression_array * array,  int mall_id,  int region_id,  double intercept,  double regressor,  double variance);
void remove_estimators_linear_regression(estimators_linear_regression_array * array, int index);

void init_consumption_request_array(consumption_request_array * array);
void reset_consumption_request_array(consumption_request_array * array);
void free_consumption_request_array(consumption_request_array * array);
void copy_consumption_request_array(consumption_request_array * from, consumption_request_array * to);
void add_consumption_request(consumption_request_array * array,  int worker_id,  int consumer_region_id,  int firm_id,  double quantity);
void remove_consumption_request(consumption_request_array * array, int index);

void init_mall_info_array(mall_info_array * array);
void reset_mall_info_array(mall_info_array * array);
void free_mall_info_array(mall_info_array * array);
void copy_mall_info_array(mall_info_array * from, mall_info_array * to);
void add_mall_info(mall_info_array * array,  int mall_id,  double critical_stock,  double current_stock);
void remove_mall_info(mall_info_array * array, int index);

void init_mall_quality_price_info_array(mall_quality_price_info_array * array);
void reset_mall_quality_price_info_array(mall_quality_price_info_array * array);
void free_mall_quality_price_info_array(mall_quality_price_info_array * array);
void copy_mall_quality_price_info_array(mall_quality_price_info_array * from, mall_quality_price_info_array * to);
void add_mall_quality_price_info(mall_quality_price_info_array * array,  int mall_id,  int firm_id,  int mall_region_id,  double quality,  double price,  int available);
void remove_mall_quality_price_info(mall_quality_price_info_array * array, int index);

void init_mall_stock_array(mall_stock_array * array);
void reset_mall_stock_array(mall_stock_array * array);
void free_mall_stock_array(mall_stock_array * array);
void copy_mall_stock_array(mall_stock_array * from, mall_stock_array * to);
void add_mall_stock(mall_stock_array * array,  int firm_id,  int region_id,  double stock,  double price,  double quality,  double previous_price);
void remove_mall_stock(mall_stock_array * array, int index);

void init_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array);
void reset_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array);
void free_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array);
void copy_delivery_volume_per_mall_array(delivery_volume_per_mall_array * from, delivery_volume_per_mall_array * to);
void add_delivery_volume_per_mall(delivery_volume_per_mall_array * array,  int mall_id,  double quantity,  double price,  double quality);
void remove_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int index);

void init_logit_firm_id_array(logit_firm_id_array * array);
void reset_logit_firm_id_array(logit_firm_id_array * array);
void free_logit_firm_id_array(logit_firm_id_array * array);
void copy_logit_firm_id_array(logit_firm_id_array * from, logit_firm_id_array * to);
void add_logit_firm_id(logit_firm_id_array * array,  double logit,  int firm_id);
void remove_logit_firm_id(logit_firm_id_array * array, int index);

void init_sales_in_mall_array(sales_in_mall_array * array);
void reset_sales_in_mall_array(sales_in_mall_array * array);
void free_sales_in_mall_array(sales_in_mall_array * array);
void copy_sales_in_mall_array(sales_in_mall_array * from, sales_in_mall_array * to);
void add_sales_in_mall(sales_in_mall_array * array,  int firm_id,  double sales);
void remove_sales_in_mall(sales_in_mall_array * array, int index);

void init_ordered_quantity_array(ordered_quantity_array * array);
void reset_ordered_quantity_array(ordered_quantity_array * array);
void free_ordered_quantity_array(ordered_quantity_array * array);
void copy_ordered_quantity_array(ordered_quantity_array * from, ordered_quantity_array * to);
void add_ordered_quantity(ordered_quantity_array * array,  int firm_id,  double quantity,  double price,  double quality);
void remove_ordered_quantity(ordered_quantity_array * array, int index);

void init_received_quantities_array(received_quantities_array * array);
void reset_received_quantities_array(received_quantities_array * array);
void free_received_quantities_array(received_quantities_array * array);
void copy_received_quantities_array(received_quantities_array * from, received_quantities_array * to);
void add_received_quantities(received_quantities_array * array,  int firm_id,  double quantity);
void remove_received_quantities(received_quantities_array * array, int index);

void init_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array);
void reset_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array);
void free_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array);
void copy_sold_quantities_per_mall_array(sold_quantities_per_mall_array * from, sold_quantities_per_mall_array * to);
void add_sold_quantities_per_mall(sold_quantities_per_mall_array * array,  int mall_id,  double sold_quantity,  int stock_empty,  double estimated_demand);
void remove_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int index);

void init_data_type_sales_array(data_type_sales_array * array);
void reset_data_type_sales_array(data_type_sales_array * array);
void free_data_type_sales_array(data_type_sales_array * array);
void copy_data_type_sales_array(data_type_sales_array * from, data_type_sales_array * to);
void add_data_type_sales(data_type_sales_array * array,  int period,  double sales);
void remove_data_type_sales(data_type_sales_array * array, int index);

void init_sales_statistics_array(sales_statistics_array * array);
void reset_sales_statistics_array(sales_statistics_array * array);
void free_sales_statistics_array(sales_statistics_array * array);
void copy_sales_statistics_array(sales_statistics_array * from, sales_statistics_array * to);
void add_sales_statistics(sales_statistics_array * array,  int mall_id,  int region_id, /*@out@*/ data_type_sales_array * sales);
void remove_sales_statistics(sales_statistics_array * array, int index);

void init_adt_technology_vintages_array(adt_technology_vintages_array * array);
void reset_adt_technology_vintages_array(adt_technology_vintages_array * array);
void free_adt_technology_vintages_array(adt_technology_vintages_array * array);
void copy_adt_technology_vintages_array(adt_technology_vintages_array * from, adt_technology_vintages_array * to);
void add_adt_technology_vintages(adt_technology_vintages_array * array,  double productivity,  double price,  double sum_effective_productivities);
void remove_adt_technology_vintages(adt_technology_vintages_array * array, int index);

void init_adt_capital_stock_vintages_array(adt_capital_stock_vintages_array * array);
void reset_adt_capital_stock_vintages_array(adt_capital_stock_vintages_array * array);
void free_adt_capital_stock_vintages_array(adt_capital_stock_vintages_array * array);
void copy_adt_capital_stock_vintages_array(adt_capital_stock_vintages_array * from, adt_capital_stock_vintages_array * to);
void add_adt_capital_stock_vintages(adt_capital_stock_vintages_array * array,  double amount,  double productivity);
void remove_adt_capital_stock_vintages(adt_capital_stock_vintages_array * array, int index);

void init_financing_capital_array(financing_capital_array * array);
void reset_financing_capital_array(financing_capital_array * array);
void free_financing_capital_array(financing_capital_array * array);
void copy_financing_capital_array(financing_capital_array * from, financing_capital_array * to);
void add_financing_capital(financing_capital_array * array,  double financing_per_month,  int nr_periods_before_repayment);
void remove_financing_capital(financing_capital_array * array, int index);

void init_temporary_sales_statistics_array(temporary_sales_statistics_array * array);
void reset_temporary_sales_statistics_array(temporary_sales_statistics_array * array);
void free_temporary_sales_statistics_array(temporary_sales_statistics_array * array);
void copy_temporary_sales_statistics_array(temporary_sales_statistics_array * from, temporary_sales_statistics_array * to);
void add_temporary_sales_statistics(temporary_sales_statistics_array * array,  int mall_id,  int period,  double sales);
void remove_temporary_sales_statistics(temporary_sales_statistics_array * array, int index);

void init_account_item_array(account_item_array * array);
void reset_account_item_array(account_item_array * array);
void free_account_item_array(account_item_array * array);
void copy_account_item_array(account_item_array * from, account_item_array * to);
void add_account_item(account_item_array * array,  int id,  double payment_account);
void remove_account_item(account_item_array * array, int index);

void init_debt_item_array(debt_item_array * array);
void reset_debt_item_array(debt_item_array * array);
void free_debt_item_array(debt_item_array * array);
void copy_debt_item_array(debt_item_array * from, debt_item_array * to);
void add_debt_item(debt_item_array * array,  int bank_id,  double loan_value,  double interest_rate,  double installment_amount,  double var_per_installment,  double residual_var,  double bad_debt,  int nr_periods_before_repayment);
void remove_debt_item(debt_item_array * array, int index);

void init_order_array(order_array * array);
void reset_order_array(order_array * array);
void free_order_array(order_array * array);
void copy_order_array(order_array * from, order_array * to);
void add_order(order_array * array,  int trader_id,  double value,  int quantity);
void remove_order(order_array * array, int index);

void init_index_adt_array(index_adt_array * array);
void reset_index_adt_array(index_adt_array * array);
void free_index_adt_array(index_adt_array * array);
void copy_index_adt_array(index_adt_array * from, index_adt_array * to);
void add_index_adt(index_adt_array * array,  double price,  double weight,  double total_dividend,  double dividend_per_share,  int nr_shares,  double moving_avg_price, /*@out@*/ double_array * price_history);
void remove_index_adt(index_adt_array * array, int index);

void init_index_portfolio_array(index_portfolio_array * array);
void reset_index_portfolio_array(index_portfolio_array * array);
void free_index_portfolio_array(index_portfolio_array * array);
void copy_index_portfolio_array(index_portfolio_array * from, index_portfolio_array * to);
void add_index_portfolio(index_portfolio_array * array,  double lastprice,  int units,  double moving_avg_price);
void remove_index_portfolio(index_portfolio_array * array, int index);

void init_Belief_array(Belief_array * array);
void reset_Belief_array(Belief_array * array);
void free_Belief_array(Belief_array * array);
void copy_Belief_array(Belief_array * from, Belief_array * to);
void add_Belief(Belief_array * array,  double expected_dividend,  double expected_price,  double expected_return,  double expected_volatility,  double last_price,  double fraction_to_invest);
void remove_Belief(Belief_array * array, int index);

void init_capital_good_request_array(capital_good_request_array * array);
void reset_capital_good_request_array(capital_good_request_array * array);
void free_capital_good_request_array(capital_good_request_array * array);
void copy_capital_good_request_array(capital_good_request_array * from, capital_good_request_array * to);
void add_capital_good_request(capital_good_request_array * array,  int firm_id,  double capital_good_order,  int vintage);
void remove_capital_good_request(capital_good_request_array * array, int index);

void init_vintage_array(vintage_array * array);
void reset_vintage_array(vintage_array * array);
void free_vintage_array(vintage_array * array);
void copy_vintage_array(vintage_array * from, vintage_array * to);
void add_vintage(vintage_array * array,  double productivity,  double price,  double discounted_productivity,  double sales);
void remove_vintage(vintage_array * array, int index);

void init_adt_sales_per_vintage_array(adt_sales_per_vintage_array * array);
void reset_adt_sales_per_vintage_array(adt_sales_per_vintage_array * array);
void free_adt_sales_per_vintage_array(adt_sales_per_vintage_array * array);
void copy_adt_sales_per_vintage_array(adt_sales_per_vintage_array * from, adt_sales_per_vintage_array * to);
void add_adt_sales_per_vintage(adt_sales_per_vintage_array * array,  double productivity_of_vintage,  double sales,  double revenue);
void remove_adt_sales_per_vintage(adt_sales_per_vintage_array * array, int index);

void init_adt_list_adaptation_speed_array(adt_list_adaptation_speed_array * array);
void reset_adt_list_adaptation_speed_array(adt_list_adaptation_speed_array * array);
void free_adt_list_adaptation_speed_array(adt_list_adaptation_speed_array * array);
void copy_adt_list_adaptation_speed_array(adt_list_adaptation_speed_array * from, adt_list_adaptation_speed_array * to);
void add_adt_list_adaptation_speed(adt_list_adaptation_speed_array * array,  int general_skill_level,  double adaptation_speed);
void remove_adt_list_adaptation_speed(adt_list_adaptation_speed_array * array, int index);

void init_employee_array(employee_array * array);
void reset_employee_array(employee_array * array);
void free_employee_array(employee_array * array);
void copy_employee_array(employee_array * from, employee_array * to);
void add_employee(employee_array * array,  int id,  int region_id,  double wage,  int general_skill,  double specific_skill,  double subsidy_pct);
void remove_employee(employee_array * array, int index);

void init_vacancy_array(vacancy_array * array);
void reset_vacancy_array(vacancy_array * array);
void free_vacancy_array(vacancy_array * array);
void copy_vacancy_array(vacancy_array * from, vacancy_array * to);
void add_vacancy(vacancy_array * array,  int firm_id,  int region_id,  double wage_offer,  int job_type);
void remove_vacancy(vacancy_array * array, int index);

void init_job_application_array(job_application_array * array);
void reset_job_application_array(job_application_array * array);
void free_job_application_array(job_application_array * array);
void copy_job_application_array(job_application_array * from, job_application_array * to);
void add_job_application(job_application_array * array,  int worker_id,  int region_id,  int general_skill,  double specific_skill,  double wage_offer,  int job_type);
void remove_job_application(job_application_array * array, int index);

void init_job_offer_array(job_offer_array * array);
void reset_job_offer_array(job_offer_array * array);
void free_job_offer_array(job_offer_array * array);
void copy_job_offer_array(job_offer_array * from, job_offer_array * to);
void add_job_offer(job_offer_array * array,  int firm_id,  int region_id,  double wage_offer,  int job_type);
void remove_job_offer(job_offer_array * array, int index);

void init_logit_array(logit_array * array);
void reset_logit_array(logit_array * array);
void free_logit_array(logit_array * array);
void copy_logit_array(logit_array * from, logit_array * to);
void add_logit(logit_array * array,  double logit_value,  int worker_id,  int general_skill,  double wage_offer,  int job_type);
void remove_logit(logit_array * array, int index);

void init_adt_skill_distribution_array(adt_skill_distribution_array * array);
void reset_adt_skill_distribution_array(adt_skill_distribution_array * array);
void free_adt_skill_distribution_array(adt_skill_distribution_array * array);
void copy_adt_skill_distribution_array(adt_skill_distribution_array * from, adt_skill_distribution_array * to);
void add_adt_skill_distribution(adt_skill_distribution_array * array,  int general_skill_group,  double percentage);
void remove_adt_skill_distribution(adt_skill_distribution_array * array, int index);

void init_adt_actual_skill_distribution_with_ids_array(adt_actual_skill_distribution_with_ids_array * array);
void reset_adt_actual_skill_distribution_with_ids_array(adt_actual_skill_distribution_with_ids_array * array);
void free_adt_actual_skill_distribution_with_ids_array(adt_actual_skill_distribution_with_ids_array * array);
void copy_adt_actual_skill_distribution_with_ids_array(adt_actual_skill_distribution_with_ids_array * from, adt_actual_skill_distribution_with_ids_array * to);
void add_adt_actual_skill_distribution_with_ids(adt_actual_skill_distribution_with_ids_array * array,  int general_skill_group, /*@out@*/ int_array * id_list);
void remove_adt_actual_skill_distribution_with_ids(adt_actual_skill_distribution_with_ids_array * array, int index);

void init_adt_gov_inflows_outflows_array(adt_gov_inflows_outflows_array * array);
void reset_adt_gov_inflows_outflows_array(adt_gov_inflows_outflows_array * array);
void free_adt_gov_inflows_outflows_array(adt_gov_inflows_outflows_array * array);
void copy_adt_gov_inflows_outflows_array(adt_gov_inflows_outflows_array * from, adt_gov_inflows_outflows_array * to);
void add_adt_gov_inflows_outflows(adt_gov_inflows_outflows_array * array,  double inflows,  double outflows,  double tax_basis);
void remove_adt_gov_inflows_outflows(adt_gov_inflows_outflows_array * array, int index);

void init_household_data_array(household_data_array * array);
void reset_household_data_array(household_data_array * array);
void free_household_data_array(household_data_array * array);
void copy_household_data_array(household_data_array * from, household_data_array * to);
void add_household_data(household_data_array * array,  int region_id,  int no_households,  int no_households_skill_1,  int no_households_skill_2,  int no_households_skill_3,  int no_households_skill_4,  int no_households_skill_5,  int employed,  int employed_skill_1,  int employed_skill_2,  int employed_skill_3,  int employed_skill_4,  int employed_skill_5,  int unemployed,  double unemployment_rate,  double unemployment_rate_skill_1,  double unemployment_rate_skill_2,  double unemployment_rate_skill_3,  double unemployment_rate_skill_4,  double unemployment_rate_skill_5,  double consumption_budget,  double average_wage,  double average_wage_skill_1,  double average_wage_skill_2,  double average_wage_skill_3,  double average_wage_skill_4,  double average_wage_skill_5,  double average_s_skill,  double average_s_skill_1,  double average_s_skill_2,  double average_s_skill_3,  double average_s_skill_4,  double average_s_skill_5);
void remove_household_data(household_data_array * array, int index);

void init_price_quality_pair_array(price_quality_pair_array * array);
void reset_price_quality_pair_array(price_quality_pair_array * array);
void free_price_quality_pair_array(price_quality_pair_array * array);
void copy_price_quality_pair_array(price_quality_pair_array * from, price_quality_pair_array * to);
void add_price_quality_pair(price_quality_pair_array * array,  int region_id,  double price,  double quality);
void remove_price_quality_pair(price_quality_pair_array * array, int index);

void init_firm_data_array(firm_data_array * array);
void reset_firm_data_array(firm_data_array * array);
void free_firm_data_array(firm_data_array * array);
void copy_firm_data_array(firm_data_array * from, firm_data_array * to);
void add_firm_data(firm_data_array * array,  int region_id,  int no_firms,  int no_active_firms,  int vacancies,  int posted_vacancies,  int employees,  int employees_skill_1,  int employees_skill_2,  int employees_skill_3,  int employees_skill_4,  int employees_skill_5,  double average_wage,  double average_wage_skill_1,  double average_wage_skill_2,  double average_wage_skill_3,  double average_wage_skill_4,  double average_wage_skill_5,  double average_s_skill,  double average_s_skill_1,  double average_s_skill_2,  double average_s_skill_3,  double average_s_skill_4,  double average_s_skill_5,  double labour_productivity,  double total_earnings,  double total_debt,  double total_assets,  double total_equity,  double average_debt_earnings_ratio,  double average_debt_equity_ratio,  double labour_share_ratio,  double monthly_sold_quantity,  double monthly_output,  double monthly_revenue,  double monthly_planned_output,  double monthly_investment_value,  double investment_gdp_ratio,  double gdp,  double cpi,  double cpi_last_month,  int no_firm_births,  int no_firm_deaths,  double productivity_progress,  double productivity,  double wage_offer,  double technology);
void remove_firm_data(firm_data_array * array, int index);

void init_government_data_array(government_data_array * array);
void reset_government_data_array(government_data_array * array);
void free_government_data_array(government_data_array * array);
void copy_government_data_array(government_data_array * from, government_data_array * to);
void add_government_data(government_data_array * array,  int region_id,  double consumption_expenditures);
void remove_government_data(government_data_array * array, int index);

void init_region_data_item_array(region_data_item_array * array);
void reset_region_data_item_array(region_data_item_array * array);
void free_region_data_item_array(region_data_item_array * array);
void copy_region_data_item_array(region_data_item_array * from, region_data_item_array * to);
void add_region_data_item(region_data_item_array * array,  double cpi,  double cpi_last_month,  double gdp,  double output,  int employment,  double unemployment_rate,  double unemployment_rate_skill_1,  double unemployment_rate_skill_2,  double unemployment_rate_skill_3,  double unemployment_rate_skill_4,  double unemployment_rate_skill_5,  double average_wage,  int no_firms,  int no_active_firms,  int no_firm_births,  int no_firm_deaths,  double investment_value);
void remove_region_data_item(region_data_item_array * array, int index);

void init_history_item_array(history_item_array * array);
void reset_history_item_array(history_item_array * array);
void free_history_item_array(history_item_array * array);
void copy_history_item_array(history_item_array * from, history_item_array * to);
void add_history_item(history_item_array * array,  double cpi,  double gdp,  double output,  int employment,  double unemployment_rate,  double unemployment_rate_skill_1,  double unemployment_rate_skill_2,  double unemployment_rate_skill_3,  double unemployment_rate_skill_4,  double unemployment_rate_skill_5,  double average_wage,  int no_firms,  int no_active_firms,  int no_firm_births,  int no_firm_deaths,  double investment_value, /*@out@*/ region_data_item_array * region_data);
void remove_history_item(history_item_array * array, int index);

void init_firm_stocks_adt_array(firm_stocks_adt_array * array);
void reset_firm_stocks_adt_array(firm_stocks_adt_array * array);
void free_firm_stocks_adt_array(firm_stocks_adt_array * array);
void copy_firm_stocks_adt_array(firm_stocks_adt_array * from, firm_stocks_adt_array * to);
void add_firm_stocks_adt(firm_stocks_adt_array * array,  double payment_account,  double total_value_local_inventory,  double total_value_capital_stock,  double total_assets,  double total_debt,  double equity,  double total_liabilities,  int current_shares_outstanding,  double payment_account_day_1,  double payment_account_day_20);
void remove_firm_stocks_adt(firm_stocks_adt_array * array, int index);

void init_firm_outflows_adt_array(firm_outflows_adt_array * array);
void reset_firm_outflows_adt_array(firm_outflows_adt_array * array);
void free_firm_outflows_adt_array(firm_outflows_adt_array * array);
void copy_firm_outflows_adt_array(firm_outflows_adt_array * from, firm_outflows_adt_array * to);
void add_firm_outflows_adt(firm_outflows_adt_array * array,  double labour_costs,  double capital_costs,  double energy_costs,  double tax_payment,  double total_debt_installment_payment,  double total_interest_payment,  double total_dividend_payment,  double value_of_repurchased_shares,  double total_expenses);
void remove_firm_outflows_adt(firm_outflows_adt_array * array, int index);

void init_firm_inflows_adt_array(firm_inflows_adt_array * array);
void reset_firm_inflows_adt_array(firm_inflows_adt_array * array);
void free_firm_inflows_adt_array(firm_inflows_adt_array * array);
void copy_firm_inflows_adt_array(firm_inflows_adt_array * from, firm_inflows_adt_array * to);
void add_firm_inflows_adt(firm_inflows_adt_array * array,  double cum_revenue,  double new_loans,  double value_of_issued_shares,  double subsidy,  double total_income,  double deposit_interest,  double net_inflow);
void remove_firm_inflows_adt(firm_inflows_adt_array * array, int index);

void init_household_stocks_adt_array(household_stocks_adt_array * array);
void reset_household_stocks_adt_array(household_stocks_adt_array * array);
void free_household_stocks_adt_array(household_stocks_adt_array * array);
void copy_household_stocks_adt_array(household_stocks_adt_array * from, household_stocks_adt_array * to);
void add_household_stocks_adt(household_stocks_adt_array * array,  double payment_account,  double portfolio_value,  double total_assets,  double total_liabilities,  int nr_assets,  double payment_account_day_1,  double payment_account_day_20);
void remove_household_stocks_adt(household_stocks_adt_array * array, int index);

void init_household_outflows_adt_array(household_outflows_adt_array * array);
void reset_household_outflows_adt_array(household_outflows_adt_array * array);
void free_household_outflows_adt_array(household_outflows_adt_array * array);
void copy_household_outflows_adt_array(household_outflows_adt_array * from, household_outflows_adt_array * to);
void add_household_outflows_adt(household_outflows_adt_array * array,  double consumption_expenditure,  double tax_payment,  double restitution_payment,  double asset_purchases,  double total_expenses);
void remove_household_outflows_adt(household_outflows_adt_array * array, int index);

void init_household_inflows_adt_array(household_inflows_adt_array * array);
void reset_household_inflows_adt_array(household_inflows_adt_array * array);
void free_household_inflows_adt_array(household_inflows_adt_array * array);
void copy_household_inflows_adt_array(household_inflows_adt_array * from, household_inflows_adt_array * to);
void add_household_inflows_adt(household_inflows_adt_array * array,  double wage,  double unemployment_benefit,  double subsidies,  double transfer,  double gov_interest,  double asset_sales,  double total_dividends,  double deposit_interest,  double total_income,  double net_inflow);
void remove_household_inflows_adt(household_inflows_adt_array * array, int index);

void init_igfirm_stocks_adt_array(igfirm_stocks_adt_array * array);
void reset_igfirm_stocks_adt_array(igfirm_stocks_adt_array * array);
void free_igfirm_stocks_adt_array(igfirm_stocks_adt_array * array);
void copy_igfirm_stocks_adt_array(igfirm_stocks_adt_array * from, igfirm_stocks_adt_array * to);
void add_igfirm_stocks_adt(igfirm_stocks_adt_array * array,  double payment_account,  double total_value_local_inventory,  double total_value_capital_stock,  double total_assets,  double total_debt,  double equity,  double total_liabilities,  int current_shares_outstanding,  double payment_account_day_1,  double payment_account_day_20);
void remove_igfirm_stocks_adt(igfirm_stocks_adt_array * array, int index);

void init_igfirm_outflows_adt_array(igfirm_outflows_adt_array * array);
void reset_igfirm_outflows_adt_array(igfirm_outflows_adt_array * array);
void free_igfirm_outflows_adt_array(igfirm_outflows_adt_array * array);
void copy_igfirm_outflows_adt_array(igfirm_outflows_adt_array * from, igfirm_outflows_adt_array * to);
void add_igfirm_outflows_adt(igfirm_outflows_adt_array * array,  double labour_costs,  double capital_costs,  double energy_costs,  double tax_payment,  double total_debt_installment_payment,  double total_interest_payment,  double total_dividend_payment,  double value_of_repurchased_shares,  double total_expenses);
void remove_igfirm_outflows_adt(igfirm_outflows_adt_array * array, int index);

void init_igfirm_inflows_adt_array(igfirm_inflows_adt_array * array);
void reset_igfirm_inflows_adt_array(igfirm_inflows_adt_array * array);
void free_igfirm_inflows_adt_array(igfirm_inflows_adt_array * array);
void copy_igfirm_inflows_adt_array(igfirm_inflows_adt_array * from, igfirm_inflows_adt_array * to);
void add_igfirm_inflows_adt(igfirm_inflows_adt_array * array,  double cum_revenue,  double new_loans,  double value_of_issued_shares,  double subsidy,  double total_income,  double deposit_interest,  double net_inflow);
void remove_igfirm_inflows_adt(igfirm_inflows_adt_array * array, int index);

void init_bank_stocks_adt_array(bank_stocks_adt_array * array);
void reset_bank_stocks_adt_array(bank_stocks_adt_array * array);
void free_bank_stocks_adt_array(bank_stocks_adt_array * array);
void copy_bank_stocks_adt_array(bank_stocks_adt_array * from, bank_stocks_adt_array * to);
void add_bank_stocks_adt(bank_stocks_adt_array * array,  double cash,  double total_credit,  double total_assets,  double deposits,  double ecb_debt,  double equity,  double total_liabilities,  int current_shares_outstanding,  double cash_day_1,  double cash_day_20);
void remove_bank_stocks_adt(bank_stocks_adt_array * array, int index);

void init_bank_outflows_adt_array(bank_outflows_adt_array * array);
void reset_bank_outflows_adt_array(bank_outflows_adt_array * array);
void free_bank_outflows_adt_array(bank_outflows_adt_array * array);
void copy_bank_outflows_adt_array(bank_outflows_adt_array * from, bank_outflows_adt_array * to);
void add_bank_outflows_adt(bank_outflows_adt_array * array,  double firm_loan_issues,  double debt_installment_to_ecb,  double ecb_interest_payment,  double deposit_interest_payment,  double dividend_payment,  double tax_payment,  double deposit_outflow,  double total_expenses);
void remove_bank_outflows_adt(bank_outflows_adt_array * array, int index);

void init_bank_inflows_adt_array(bank_inflows_adt_array * array);
void reset_bank_inflows_adt_array(bank_inflows_adt_array * array);
void free_bank_inflows_adt_array(bank_inflows_adt_array * array);
void copy_bank_inflows_adt_array(bank_inflows_adt_array * from, bank_inflows_adt_array * to);
void add_bank_inflows_adt(bank_inflows_adt_array * array,  double firm_loan_installments,  double firm_interest_payments,  double new_ecb_debt,  double deposit_inflow,  double total_income,  double net_inflow,  double net_deposit_inflow);
void remove_bank_inflows_adt(bank_inflows_adt_array * array, int index);

void init_gov_stocks_adt_array(gov_stocks_adt_array * array);
void reset_gov_stocks_adt_array(gov_stocks_adt_array * array);
void free_gov_stocks_adt_array(gov_stocks_adt_array * array);
void copy_gov_stocks_adt_array(gov_stocks_adt_array * from, gov_stocks_adt_array * to);
void add_gov_stocks_adt(gov_stocks_adt_array * array,  double payment_account,  double total_assets,  double value_bonds_outstanding,  double ecb_money,  double equity,  double total_liabilities,  int nr_bonds_outstanding,  double payment_account_day_1,  double payment_account_day_20);
void remove_gov_stocks_adt(gov_stocks_adt_array * array, int index);

void init_gov_outflows_adt_array(gov_outflows_adt_array * array);
void reset_gov_outflows_adt_array(gov_outflows_adt_array * array);
void free_gov_outflows_adt_array(gov_outflows_adt_array * array);
void copy_gov_outflows_adt_array(gov_outflows_adt_array * from, gov_outflows_adt_array * to);
void add_gov_outflows_adt(gov_outflows_adt_array * array,  double investment_expenditure,  double consumption_expenditure,  double benefit_payment,  double subsidy_payment_household,  double subsidy_payment_firm,  double transfer_payment_household,  double transfer_payment_firm,  double bond_interest_payment,  double debt_installment,  double total_bond_repurchase,  double total_expenses);
void remove_gov_outflows_adt(gov_outflows_adt_array * array, int index);

void init_gov_inflows_adt_array(gov_inflows_adt_array * array);
void reset_gov_inflows_adt_array(gov_inflows_adt_array * array);
void free_gov_inflows_adt_array(gov_inflows_adt_array * array);
void copy_gov_inflows_adt_array(gov_inflows_adt_array * from, gov_inflows_adt_array * to);
void add_gov_inflows_adt(gov_inflows_adt_array * array,  double tax_revenues,  double restitution_payment,  double total_bond_financing,  double total_money_financing,  double ecb_dividend,  double total_income,  double net_inflow);
void remove_gov_inflows_adt(gov_inflows_adt_array * array, int index);

void init_ecb_stocks_adt_array(ecb_stocks_adt_array * array);
void reset_ecb_stocks_adt_array(ecb_stocks_adt_array * array);
void free_ecb_stocks_adt_array(ecb_stocks_adt_array * array);
void copy_ecb_stocks_adt_array(ecb_stocks_adt_array * from, ecb_stocks_adt_array * to);
void add_ecb_stocks_adt(ecb_stocks_adt_array * array,  double cash,  double gov_bond_holdings,  double fiat_money_banks,  double fiat_money_govs,  double total_assets,  double payment_account_banks,  double payment_account_govs,  double fiat_money,  double equity,  double total_liabilities,  int nr_gov_bonds,  double equity_day_1,  double fiat_money_govs_bond);
void remove_ecb_stocks_adt(ecb_stocks_adt_array * array, int index);

void init_ecb_outflows_adt_array(ecb_outflows_adt_array * array);
void reset_ecb_outflows_adt_array(ecb_outflows_adt_array * array);
void free_ecb_outflows_adt_array(ecb_outflows_adt_array * array);
void copy_ecb_outflows_adt_array(ecb_outflows_adt_array * from, ecb_outflows_adt_array * to);
void add_ecb_outflows_adt(ecb_outflows_adt_array * array,  double gov_bond_purchase,  double bank_fiat_money,  double bank_deposits,  double gov_deposits,  double dividend_payment,  double total_expenses);
void remove_ecb_outflows_adt(ecb_outflows_adt_array * array, int index);

void init_ecb_inflows_adt_array(ecb_inflows_adt_array * array);
void reset_ecb_inflows_adt_array(ecb_inflows_adt_array * array);
void free_ecb_inflows_adt_array(ecb_inflows_adt_array * array);
void copy_ecb_inflows_adt_array(ecb_inflows_adt_array * from, ecb_inflows_adt_array * to);
void add_ecb_inflows_adt(ecb_inflows_adt_array * array,  double bank_interest,  double bank_debt_installment,  double gov_interest,  double bank_deposits,  double gov_deposits,  double total_income,  double net_inflow);
void remove_ecb_inflows_adt(ecb_inflows_adt_array * array, int index);

void init_firm_balance_sheet_adt_array(firm_balance_sheet_adt_array * array);
void reset_firm_balance_sheet_adt_array(firm_balance_sheet_adt_array * array);
void free_firm_balance_sheet_adt_array(firm_balance_sheet_adt_array * array);
void copy_firm_balance_sheet_adt_array(firm_balance_sheet_adt_array * from, firm_balance_sheet_adt_array * to);
void add_firm_balance_sheet_adt(firm_balance_sheet_adt_array * array, /*@out@*/ firm_stocks_adt * stocks, /*@out@*/ firm_outflows_adt * outflows, /*@out@*/ firm_inflows_adt * inflows);
void remove_firm_balance_sheet_adt(firm_balance_sheet_adt_array * array, int index);

void init_household_balance_sheet_adt_array(household_balance_sheet_adt_array * array);
void reset_household_balance_sheet_adt_array(household_balance_sheet_adt_array * array);
void free_household_balance_sheet_adt_array(household_balance_sheet_adt_array * array);
void copy_household_balance_sheet_adt_array(household_balance_sheet_adt_array * from, household_balance_sheet_adt_array * to);
void add_household_balance_sheet_adt(household_balance_sheet_adt_array * array, /*@out@*/ household_stocks_adt * stocks, /*@out@*/ household_outflows_adt * outflows, /*@out@*/ household_inflows_adt * inflows);
void remove_household_balance_sheet_adt(household_balance_sheet_adt_array * array, int index);

void init_igfirm_balance_sheet_adt_array(igfirm_balance_sheet_adt_array * array);
void reset_igfirm_balance_sheet_adt_array(igfirm_balance_sheet_adt_array * array);
void free_igfirm_balance_sheet_adt_array(igfirm_balance_sheet_adt_array * array);
void copy_igfirm_balance_sheet_adt_array(igfirm_balance_sheet_adt_array * from, igfirm_balance_sheet_adt_array * to);
void add_igfirm_balance_sheet_adt(igfirm_balance_sheet_adt_array * array, /*@out@*/ igfirm_stocks_adt * stocks, /*@out@*/ igfirm_outflows_adt * outflows, /*@out@*/ igfirm_inflows_adt * inflows);
void remove_igfirm_balance_sheet_adt(igfirm_balance_sheet_adt_array * array, int index);

void init_bank_balance_sheet_adt_array(bank_balance_sheet_adt_array * array);
void reset_bank_balance_sheet_adt_array(bank_balance_sheet_adt_array * array);
void free_bank_balance_sheet_adt_array(bank_balance_sheet_adt_array * array);
void copy_bank_balance_sheet_adt_array(bank_balance_sheet_adt_array * from, bank_balance_sheet_adt_array * to);
void add_bank_balance_sheet_adt(bank_balance_sheet_adt_array * array, /*@out@*/ bank_stocks_adt * stocks, /*@out@*/ bank_outflows_adt * outflows, /*@out@*/ bank_inflows_adt * inflows);
void remove_bank_balance_sheet_adt(bank_balance_sheet_adt_array * array, int index);

void init_gov_balance_sheet_adt_array(gov_balance_sheet_adt_array * array);
void reset_gov_balance_sheet_adt_array(gov_balance_sheet_adt_array * array);
void free_gov_balance_sheet_adt_array(gov_balance_sheet_adt_array * array);
void copy_gov_balance_sheet_adt_array(gov_balance_sheet_adt_array * from, gov_balance_sheet_adt_array * to);
void add_gov_balance_sheet_adt(gov_balance_sheet_adt_array * array, /*@out@*/ gov_stocks_adt * stocks, /*@out@*/ gov_outflows_adt * outflows, /*@out@*/ gov_inflows_adt * inflows);
void remove_gov_balance_sheet_adt(gov_balance_sheet_adt_array * array, int index);

void init_ecb_balance_sheet_adt_array(ecb_balance_sheet_adt_array * array);
void reset_ecb_balance_sheet_adt_array(ecb_balance_sheet_adt_array * array);
void free_ecb_balance_sheet_adt_array(ecb_balance_sheet_adt_array * array);
void copy_ecb_balance_sheet_adt_array(ecb_balance_sheet_adt_array * from, ecb_balance_sheet_adt_array * to);
void add_ecb_balance_sheet_adt(ecb_balance_sheet_adt_array * array, /*@out@*/ ecb_stocks_adt * stocks, /*@out@*/ ecb_outflows_adt * outflows, /*@out@*/ ecb_inflows_adt * inflows);
void remove_ecb_balance_sheet_adt(ecb_balance_sheet_adt_array * array, int index);

void init_adt_subsidies_per_government_array(adt_subsidies_per_government_array * array);
void reset_adt_subsidies_per_government_array(adt_subsidies_per_government_array * array);
void free_adt_subsidies_per_government_array(adt_subsidies_per_government_array * array);
void copy_adt_subsidies_per_government_array(adt_subsidies_per_government_array * from, adt_subsidies_per_government_array * to);
void add_adt_subsidies_per_government(adt_subsidies_per_government_array * array,  int gov_id,  int region_id,  double amount);
void remove_adt_subsidies_per_government(adt_subsidies_per_government_array * array, int index);

void init_estimated_values_adt_array(estimated_values_adt_array * array);
void reset_estimated_values_adt_array(estimated_values_adt_array * array);
void free_estimated_values_adt_array(estimated_values_adt_array * array);
void copy_estimated_values_adt_array(estimated_values_adt_array * from, estimated_values_adt_array * to);
void add_estimated_values_adt(estimated_values_adt_array * array,  int no_positive_response,  double probability,  double estimated_fix_costs,  double estimated_variable_costs,  double estimated_earnings,  double additional_capital_Investments_depreciated,  double mean_specific_skills,  double mean_wage,  int no_employees);
void remove_estimated_values_adt(estimated_values_adt_array * array, int index);

void init_dt_market_research_price_array(dt_market_research_price_array * array);
void reset_dt_market_research_price_array(dt_market_research_price_array * array);
void free_dt_market_research_price_array(dt_market_research_price_array * array);
void copy_dt_market_research_price_array(dt_market_research_price_array * from, dt_market_research_price_array * to);
void add_dt_market_research_price(dt_market_research_price_array * array,  double price_change,  double price, /*@out@*/ estimated_values_adt_array * estimated_values);
void remove_dt_market_research_price(dt_market_research_price_array * array, int index);

void init_dt_market_research_qualities_array(dt_market_research_qualities_array * array);
void reset_dt_market_research_qualities_array(dt_market_research_qualities_array * array);
void free_dt_market_research_qualities_array(dt_market_research_qualities_array * array);
void copy_dt_market_research_qualities_array(dt_market_research_qualities_array * from, dt_market_research_qualities_array * to);
void add_dt_market_research_qualities(dt_market_research_qualities_array * array,  double quality, /*@out@*/ dt_market_research_price_array * market_research_price);
void remove_dt_market_research_qualities(dt_market_research_qualities_array * array, int index);

void init_dt_best_price_strategies_array(dt_best_price_strategies_array * array);
void reset_dt_best_price_strategies_array(dt_best_price_strategies_array * array);
void free_dt_best_price_strategies_array(dt_best_price_strategies_array * array);
void copy_dt_best_price_strategies_array(dt_best_price_strategies_array * from, dt_best_price_strategies_array * to);
void add_dt_best_price_strategies(dt_best_price_strategies_array * array,  double quality,  double price,  double expected_earnings,  double sum_earnings,  double sum_expected_earnings_discounted);
void remove_dt_best_price_strategies(dt_best_price_strategies_array * array, int index);

void init_dt_price_range_array(dt_price_range_array * array);
void reset_dt_price_range_array(dt_price_range_array * array);
void free_dt_price_range_array(dt_price_range_array * array);
void copy_dt_price_range_array(dt_price_range_array * from, dt_price_range_array * to);
void add_dt_price_range(dt_price_range_array * array,  double start_price,  double end_price,  double increment);
void remove_dt_price_range(dt_price_range_array * array, int index);

void init_dt_prospective_variables_array(dt_prospective_variables_array * array);
void reset_dt_prospective_variables_array(dt_prospective_variables_array * array);
void free_dt_prospective_variables_array(dt_prospective_variables_array * array);
void copy_dt_prospective_variables_array(dt_prospective_variables_array * from, dt_prospective_variables_array * to);
void add_dt_prospective_variables(dt_prospective_variables_array * array,  double mean_specific_skills,  double estimated_mean_wage,  double no_employees,  double earnings,  double payment_account,  double buffer, /*@out@*/ adt_capital_stock_vintages_array * capital_stock_vintages, /*@out@*/ financing_capital_array * capital_financing, /*@out@*/ debt_item_array * loans);
void remove_dt_prospective_variables(dt_prospective_variables_array * array, int index);

void init_dt_variables_changed_array(dt_variables_changed_array * array);
void reset_dt_variables_changed_array(dt_variables_changed_array * array);
void free_dt_variables_changed_array(dt_variables_changed_array * array);
void copy_dt_variables_changed_array(dt_variables_changed_array * from, dt_variables_changed_array * to);
void add_dt_variables_changed(dt_variables_changed_array * array,  double price_index,  double quality_index,  double productivity_progress);
void remove_dt_variables_changed(dt_variables_changed_array * array, int index);

void init_dt_innovation_choice_array(dt_innovation_choice_array * array);
void reset_dt_innovation_choice_array(dt_innovation_choice_array * array);
void free_dt_innovation_choice_array(dt_innovation_choice_array * array);
void copy_dt_innovation_choice_array(dt_innovation_choice_array * from, dt_innovation_choice_array * to);
void add_dt_innovation_choice(dt_innovation_choice_array * array,  int development_period,  int employees_needed,  double quality,  double expected_discounted_earnings);
void remove_dt_innovation_choice(dt_innovation_choice_array * array, int index);

void init_dt_demand_function_array(dt_demand_function_array * array);
void reset_dt_demand_function_array(dt_demand_function_array * array);
void free_dt_demand_function_array(dt_demand_function_array * array);
void copy_dt_demand_function_array(dt_demand_function_array * from, dt_demand_function_array * to);
void add_dt_demand_function(dt_demand_function_array * array,  double quality,  int year,  double factor,  double exponent,  double variance);
void remove_dt_demand_function(dt_demand_function_array * array, int index);

void init_dt_price_quantity_touple_array(dt_price_quantity_touple_array * array);
void reset_dt_price_quantity_touple_array(dt_price_quantity_touple_array * array);
void free_dt_price_quantity_touple_array(dt_price_quantity_touple_array * array);
void copy_dt_price_quantity_touple_array(dt_price_quantity_touple_array * from, dt_price_quantity_touple_array * to);
void add_dt_price_quantity_touple(dt_price_quantity_touple_array * array,  double price,  double quantity);
void remove_dt_price_quantity_touple(dt_price_quantity_touple_array * array, int index);

void init_dt_market_size_array(dt_market_size_array * array);
void reset_dt_market_size_array(dt_market_size_array * array);
void free_dt_market_size_array(dt_market_size_array * array);
void copy_dt_market_size_array(dt_market_size_array * from, dt_market_size_array * to);
void add_dt_market_size(dt_market_size_array * array,  int period,  double market_size);
void remove_dt_market_size(dt_market_size_array * array, int index);

void init_dt_total_and_regional_market_size_array(dt_total_and_regional_market_size_array * array);
void reset_dt_total_and_regional_market_size_array(dt_total_and_regional_market_size_array * array);
void free_dt_total_and_regional_market_size_array(dt_total_and_regional_market_size_array * array);
void copy_dt_total_and_regional_market_size_array(dt_total_and_regional_market_size_array * from, dt_total_and_regional_market_size_array * to);
void add_dt_total_and_regional_market_size(dt_total_and_regional_market_size_array * array,  int region_id,  int mall_id, /*@out@*/ dt_market_size_array * market_sizes);
void remove_dt_total_and_regional_market_size(dt_total_and_regional_market_size_array * array, int index);

void init_dt_value_lattice_array(dt_value_lattice_array * array);
void reset_dt_value_lattice_array(dt_value_lattice_array * array);
void free_dt_value_lattice_array(dt_value_lattice_array * array);
void copy_dt_value_lattice_array(dt_value_lattice_array * from, dt_value_lattice_array * to);
void add_dt_value_lattice(dt_value_lattice_array * array,  double intermediate_quality,  double value,  int strategy);
void remove_dt_value_lattice(dt_value_lattice_array * array, int index);

void init_dt_value_lattice_years_array(dt_value_lattice_years_array * array);
void reset_dt_value_lattice_years_array(dt_value_lattice_years_array * array);
void free_dt_value_lattice_years_array(dt_value_lattice_years_array * array);
void copy_dt_value_lattice_years_array(dt_value_lattice_years_array * from, dt_value_lattice_years_array * to);
void add_dt_value_lattice_years(dt_value_lattice_years_array * array,  int year, /*@out@*/ dt_value_lattice_array * values);
void remove_dt_value_lattice_years(dt_value_lattice_years_array * array, int index);

void init_dt_monthly_estimations_array(dt_monthly_estimations_array * array);
void reset_dt_monthly_estimations_array(dt_monthly_estimations_array * array);
void free_dt_monthly_estimations_array(dt_monthly_estimations_array * array);
void copy_dt_monthly_estimations_array(dt_monthly_estimations_array * from, dt_monthly_estimations_array * to);
void add_dt_monthly_estimations(dt_monthly_estimations_array * array,  double output,  double earnings,  double sold_quantity,  double labor_costs,  double capital_costs,  double interest_payments,  double wage,  double mean_specific_skills,  double average_productivity,  double investment_nominal);
void remove_dt_monthly_estimations(dt_monthly_estimations_array * array, int index);

void init_int_static_array(/*@out@*/ int * array, int size);
void init_int_array(int_array * array);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
//void sort_int_array(int_array array);
//int quicksort_int(int array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
void init_float_static_array(float * array, int size);
void init_float_array(float_array * array);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
//void sort_float_array(float_array array);
//int quicksort_float(float array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
void init_double_static_array(/*@out@*/ double* array, int size);
void init_double_array(double_array * array);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
//void sort_double_array(double_array array);
//int quicksort_double(double array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
void init_char_static_array(/*@out@*/ char * array, int size);
void init_char_array(char_array * array);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
int idle(void);
/* xml.c */
int read_int_static_array(char * buffer, int buffer_size, int * j, int * int_static_array, int size);
int read_float_static_array(char * buffer, int buffer_size, int * j, float * float_static_array, int size);
int read_double_static_array(char * buffer, int buffer_size, int * j, double * double_static_array, int size);
int read_char_static_array(char * buffer, int buffer_size, int * j, char * char_static_array, int size);
int read_int_dynamic_array(char * buffer, int buffer_size, int * j, int_array * int_dynamic_array);
int read_float_dynamic_array(char * buffer, int buffer_size, int * j, float_array * float_dynamic_array);
int read_double_dynamic_array(char * buffer, int buffer_size, int * j, double_array * double_dynamic_array);
int read_char_dynamic_array(char * buffer, int buffer_size, int * j, char_array * char_dynamic_array);

void init_consumption_goods_offer(/*@out@*/ consumption_goods_offer * temp);
void init_consumption_goods_offer_static_array(/*@out@*/ consumption_goods_offer * array, int size);
int read_consumption_goods_offer(char * buffer, int buffer_size, int * j, consumption_goods_offer * temp_datatype);
int read_consumption_goods_offer_dynamic_array(char * buffer, int buffer_size, int * j, consumption_goods_offer_array * temp_datatype_array);
int read_consumption_goods_offer_static_array(char * buffer, int buffer_size, int * j, consumption_goods_offer * temp_datatype_array, int size);
void write_consumption_goods_offer(FILE *file, consumption_goods_offer * temp_datatype);
void write_consumption_goods_offer_static_array(FILE *file, consumption_goods_offer * temp_datatype, int size);
void write_consumption_goods_offer_dynamic_array(FILE *file, consumption_goods_offer_array * temp_datatype);
void init_estimators_linear_regression(/*@out@*/ estimators_linear_regression * temp);
void init_estimators_linear_regression_static_array(/*@out@*/ estimators_linear_regression * array, int size);
int read_estimators_linear_regression(char * buffer, int buffer_size, int * j, estimators_linear_regression * temp_datatype);
int read_estimators_linear_regression_dynamic_array(char * buffer, int buffer_size, int * j, estimators_linear_regression_array * temp_datatype_array);
int read_estimators_linear_regression_static_array(char * buffer, int buffer_size, int * j, estimators_linear_regression * temp_datatype_array, int size);
void write_estimators_linear_regression(FILE *file, estimators_linear_regression * temp_datatype);
void write_estimators_linear_regression_static_array(FILE *file, estimators_linear_regression * temp_datatype, int size);
void write_estimators_linear_regression_dynamic_array(FILE *file, estimators_linear_regression_array * temp_datatype);
void init_consumption_request(/*@out@*/ consumption_request * temp);
void init_consumption_request_static_array(/*@out@*/ consumption_request * array, int size);
int read_consumption_request(char * buffer, int buffer_size, int * j, consumption_request * temp_datatype);
int read_consumption_request_dynamic_array(char * buffer, int buffer_size, int * j, consumption_request_array * temp_datatype_array);
int read_consumption_request_static_array(char * buffer, int buffer_size, int * j, consumption_request * temp_datatype_array, int size);
void write_consumption_request(FILE *file, consumption_request * temp_datatype);
void write_consumption_request_static_array(FILE *file, consumption_request * temp_datatype, int size);
void write_consumption_request_dynamic_array(FILE *file, consumption_request_array * temp_datatype);
void init_mall_info(/*@out@*/ mall_info * temp);
void init_mall_info_static_array(/*@out@*/ mall_info * array, int size);
int read_mall_info(char * buffer, int buffer_size, int * j, mall_info * temp_datatype);
int read_mall_info_dynamic_array(char * buffer, int buffer_size, int * j, mall_info_array * temp_datatype_array);
int read_mall_info_static_array(char * buffer, int buffer_size, int * j, mall_info * temp_datatype_array, int size);
void write_mall_info(FILE *file, mall_info * temp_datatype);
void write_mall_info_static_array(FILE *file, mall_info * temp_datatype, int size);
void write_mall_info_dynamic_array(FILE *file, mall_info_array * temp_datatype);
void init_mall_quality_price_info(/*@out@*/ mall_quality_price_info * temp);
void init_mall_quality_price_info_static_array(/*@out@*/ mall_quality_price_info * array, int size);
int read_mall_quality_price_info(char * buffer, int buffer_size, int * j, mall_quality_price_info * temp_datatype);
int read_mall_quality_price_info_dynamic_array(char * buffer, int buffer_size, int * j, mall_quality_price_info_array * temp_datatype_array);
int read_mall_quality_price_info_static_array(char * buffer, int buffer_size, int * j, mall_quality_price_info * temp_datatype_array, int size);
void write_mall_quality_price_info(FILE *file, mall_quality_price_info * temp_datatype);
void write_mall_quality_price_info_static_array(FILE *file, mall_quality_price_info * temp_datatype, int size);
void write_mall_quality_price_info_dynamic_array(FILE *file, mall_quality_price_info_array * temp_datatype);
void init_mall_stock(/*@out@*/ mall_stock * temp);
void init_mall_stock_static_array(/*@out@*/ mall_stock * array, int size);
int read_mall_stock(char * buffer, int buffer_size, int * j, mall_stock * temp_datatype);
int read_mall_stock_dynamic_array(char * buffer, int buffer_size, int * j, mall_stock_array * temp_datatype_array);
int read_mall_stock_static_array(char * buffer, int buffer_size, int * j, mall_stock * temp_datatype_array, int size);
void write_mall_stock(FILE *file, mall_stock * temp_datatype);
void write_mall_stock_static_array(FILE *file, mall_stock * temp_datatype, int size);
void write_mall_stock_dynamic_array(FILE *file, mall_stock_array * temp_datatype);
void init_delivery_volume_per_mall(/*@out@*/ delivery_volume_per_mall * temp);
void init_delivery_volume_per_mall_static_array(/*@out@*/ delivery_volume_per_mall * array, int size);
int read_delivery_volume_per_mall(char * buffer, int buffer_size, int * j, delivery_volume_per_mall * temp_datatype);
int read_delivery_volume_per_mall_dynamic_array(char * buffer, int buffer_size, int * j, delivery_volume_per_mall_array * temp_datatype_array);
int read_delivery_volume_per_mall_static_array(char * buffer, int buffer_size, int * j, delivery_volume_per_mall * temp_datatype_array, int size);
void write_delivery_volume_per_mall(FILE *file, delivery_volume_per_mall * temp_datatype);
void write_delivery_volume_per_mall_static_array(FILE *file, delivery_volume_per_mall * temp_datatype, int size);
void write_delivery_volume_per_mall_dynamic_array(FILE *file, delivery_volume_per_mall_array * temp_datatype);
void init_logit_firm_id(/*@out@*/ logit_firm_id * temp);
void init_logit_firm_id_static_array(/*@out@*/ logit_firm_id * array, int size);
int read_logit_firm_id(char * buffer, int buffer_size, int * j, logit_firm_id * temp_datatype);
int read_logit_firm_id_dynamic_array(char * buffer, int buffer_size, int * j, logit_firm_id_array * temp_datatype_array);
int read_logit_firm_id_static_array(char * buffer, int buffer_size, int * j, logit_firm_id * temp_datatype_array, int size);
void write_logit_firm_id(FILE *file, logit_firm_id * temp_datatype);
void write_logit_firm_id_static_array(FILE *file, logit_firm_id * temp_datatype, int size);
void write_logit_firm_id_dynamic_array(FILE *file, logit_firm_id_array * temp_datatype);
void init_sales_in_mall(/*@out@*/ sales_in_mall * temp);
void init_sales_in_mall_static_array(/*@out@*/ sales_in_mall * array, int size);
int read_sales_in_mall(char * buffer, int buffer_size, int * j, sales_in_mall * temp_datatype);
int read_sales_in_mall_dynamic_array(char * buffer, int buffer_size, int * j, sales_in_mall_array * temp_datatype_array);
int read_sales_in_mall_static_array(char * buffer, int buffer_size, int * j, sales_in_mall * temp_datatype_array, int size);
void write_sales_in_mall(FILE *file, sales_in_mall * temp_datatype);
void write_sales_in_mall_static_array(FILE *file, sales_in_mall * temp_datatype, int size);
void write_sales_in_mall_dynamic_array(FILE *file, sales_in_mall_array * temp_datatype);
void init_ordered_quantity(/*@out@*/ ordered_quantity * temp);
void init_ordered_quantity_static_array(/*@out@*/ ordered_quantity * array, int size);
int read_ordered_quantity(char * buffer, int buffer_size, int * j, ordered_quantity * temp_datatype);
int read_ordered_quantity_dynamic_array(char * buffer, int buffer_size, int * j, ordered_quantity_array * temp_datatype_array);
int read_ordered_quantity_static_array(char * buffer, int buffer_size, int * j, ordered_quantity * temp_datatype_array, int size);
void write_ordered_quantity(FILE *file, ordered_quantity * temp_datatype);
void write_ordered_quantity_static_array(FILE *file, ordered_quantity * temp_datatype, int size);
void write_ordered_quantity_dynamic_array(FILE *file, ordered_quantity_array * temp_datatype);
void init_received_quantities(/*@out@*/ received_quantities * temp);
void init_received_quantities_static_array(/*@out@*/ received_quantities * array, int size);
int read_received_quantities(char * buffer, int buffer_size, int * j, received_quantities * temp_datatype);
int read_received_quantities_dynamic_array(char * buffer, int buffer_size, int * j, received_quantities_array * temp_datatype_array);
int read_received_quantities_static_array(char * buffer, int buffer_size, int * j, received_quantities * temp_datatype_array, int size);
void write_received_quantities(FILE *file, received_quantities * temp_datatype);
void write_received_quantities_static_array(FILE *file, received_quantities * temp_datatype, int size);
void write_received_quantities_dynamic_array(FILE *file, received_quantities_array * temp_datatype);
void init_sold_quantities_per_mall(/*@out@*/ sold_quantities_per_mall * temp);
void init_sold_quantities_per_mall_static_array(/*@out@*/ sold_quantities_per_mall * array, int size);
int read_sold_quantities_per_mall(char * buffer, int buffer_size, int * j, sold_quantities_per_mall * temp_datatype);
int read_sold_quantities_per_mall_dynamic_array(char * buffer, int buffer_size, int * j, sold_quantities_per_mall_array * temp_datatype_array);
int read_sold_quantities_per_mall_static_array(char * buffer, int buffer_size, int * j, sold_quantities_per_mall * temp_datatype_array, int size);
void write_sold_quantities_per_mall(FILE *file, sold_quantities_per_mall * temp_datatype);
void write_sold_quantities_per_mall_static_array(FILE *file, sold_quantities_per_mall * temp_datatype, int size);
void write_sold_quantities_per_mall_dynamic_array(FILE *file, sold_quantities_per_mall_array * temp_datatype);
void init_data_type_sales(/*@out@*/ data_type_sales * temp);
void init_data_type_sales_static_array(/*@out@*/ data_type_sales * array, int size);
int read_data_type_sales(char * buffer, int buffer_size, int * j, data_type_sales * temp_datatype);
int read_data_type_sales_dynamic_array(char * buffer, int buffer_size, int * j, data_type_sales_array * temp_datatype_array);
int read_data_type_sales_static_array(char * buffer, int buffer_size, int * j, data_type_sales * temp_datatype_array, int size);
void write_data_type_sales(FILE *file, data_type_sales * temp_datatype);
void write_data_type_sales_static_array(FILE *file, data_type_sales * temp_datatype, int size);
void write_data_type_sales_dynamic_array(FILE *file, data_type_sales_array * temp_datatype);
void init_sales_statistics(/*@out@*/ sales_statistics * temp);
void init_sales_statistics_static_array(/*@out@*/ sales_statistics * array, int size);
int read_sales_statistics(char * buffer, int buffer_size, int * j, sales_statistics * temp_datatype);
int read_sales_statistics_dynamic_array(char * buffer, int buffer_size, int * j, sales_statistics_array * temp_datatype_array);
int read_sales_statistics_static_array(char * buffer, int buffer_size, int * j, sales_statistics * temp_datatype_array, int size);
void write_sales_statistics(FILE *file, sales_statistics * temp_datatype);
void write_sales_statistics_static_array(FILE *file, sales_statistics * temp_datatype, int size);
void write_sales_statistics_dynamic_array(FILE *file, sales_statistics_array * temp_datatype);
void init_adt_technology_vintages(/*@out@*/ adt_technology_vintages * temp);
void init_adt_technology_vintages_static_array(/*@out@*/ adt_technology_vintages * array, int size);
int read_adt_technology_vintages(char * buffer, int buffer_size, int * j, adt_technology_vintages * temp_datatype);
int read_adt_technology_vintages_dynamic_array(char * buffer, int buffer_size, int * j, adt_technology_vintages_array * temp_datatype_array);
int read_adt_technology_vintages_static_array(char * buffer, int buffer_size, int * j, adt_technology_vintages * temp_datatype_array, int size);
void write_adt_technology_vintages(FILE *file, adt_technology_vintages * temp_datatype);
void write_adt_technology_vintages_static_array(FILE *file, adt_technology_vintages * temp_datatype, int size);
void write_adt_technology_vintages_dynamic_array(FILE *file, adt_technology_vintages_array * temp_datatype);
void init_adt_capital_stock_vintages(/*@out@*/ adt_capital_stock_vintages * temp);
void init_adt_capital_stock_vintages_static_array(/*@out@*/ adt_capital_stock_vintages * array, int size);
int read_adt_capital_stock_vintages(char * buffer, int buffer_size, int * j, adt_capital_stock_vintages * temp_datatype);
int read_adt_capital_stock_vintages_dynamic_array(char * buffer, int buffer_size, int * j, adt_capital_stock_vintages_array * temp_datatype_array);
int read_adt_capital_stock_vintages_static_array(char * buffer, int buffer_size, int * j, adt_capital_stock_vintages * temp_datatype_array, int size);
void write_adt_capital_stock_vintages(FILE *file, adt_capital_stock_vintages * temp_datatype);
void write_adt_capital_stock_vintages_static_array(FILE *file, adt_capital_stock_vintages * temp_datatype, int size);
void write_adt_capital_stock_vintages_dynamic_array(FILE *file, adt_capital_stock_vintages_array * temp_datatype);
void init_financing_capital(/*@out@*/ financing_capital * temp);
void init_financing_capital_static_array(/*@out@*/ financing_capital * array, int size);
int read_financing_capital(char * buffer, int buffer_size, int * j, financing_capital * temp_datatype);
int read_financing_capital_dynamic_array(char * buffer, int buffer_size, int * j, financing_capital_array * temp_datatype_array);
int read_financing_capital_static_array(char * buffer, int buffer_size, int * j, financing_capital * temp_datatype_array, int size);
void write_financing_capital(FILE *file, financing_capital * temp_datatype);
void write_financing_capital_static_array(FILE *file, financing_capital * temp_datatype, int size);
void write_financing_capital_dynamic_array(FILE *file, financing_capital_array * temp_datatype);
void init_temporary_sales_statistics(/*@out@*/ temporary_sales_statistics * temp);
void init_temporary_sales_statistics_static_array(/*@out@*/ temporary_sales_statistics * array, int size);
int read_temporary_sales_statistics(char * buffer, int buffer_size, int * j, temporary_sales_statistics * temp_datatype);
int read_temporary_sales_statistics_dynamic_array(char * buffer, int buffer_size, int * j, temporary_sales_statistics_array * temp_datatype_array);
int read_temporary_sales_statistics_static_array(char * buffer, int buffer_size, int * j, temporary_sales_statistics * temp_datatype_array, int size);
void write_temporary_sales_statistics(FILE *file, temporary_sales_statistics * temp_datatype);
void write_temporary_sales_statistics_static_array(FILE *file, temporary_sales_statistics * temp_datatype, int size);
void write_temporary_sales_statistics_dynamic_array(FILE *file, temporary_sales_statistics_array * temp_datatype);
void init_account_item(/*@out@*/ account_item * temp);
void init_account_item_static_array(/*@out@*/ account_item * array, int size);
int read_account_item(char * buffer, int buffer_size, int * j, account_item * temp_datatype);
int read_account_item_dynamic_array(char * buffer, int buffer_size, int * j, account_item_array * temp_datatype_array);
int read_account_item_static_array(char * buffer, int buffer_size, int * j, account_item * temp_datatype_array, int size);
void write_account_item(FILE *file, account_item * temp_datatype);
void write_account_item_static_array(FILE *file, account_item * temp_datatype, int size);
void write_account_item_dynamic_array(FILE *file, account_item_array * temp_datatype);
void init_debt_item(/*@out@*/ debt_item * temp);
void init_debt_item_static_array(/*@out@*/ debt_item * array, int size);
int read_debt_item(char * buffer, int buffer_size, int * j, debt_item * temp_datatype);
int read_debt_item_dynamic_array(char * buffer, int buffer_size, int * j, debt_item_array * temp_datatype_array);
int read_debt_item_static_array(char * buffer, int buffer_size, int * j, debt_item * temp_datatype_array, int size);
void write_debt_item(FILE *file, debt_item * temp_datatype);
void write_debt_item_static_array(FILE *file, debt_item * temp_datatype, int size);
void write_debt_item_dynamic_array(FILE *file, debt_item_array * temp_datatype);
void init_order(/*@out@*/ order * temp);
void init_order_static_array(/*@out@*/ order * array, int size);
int read_order(char * buffer, int buffer_size, int * j, order * temp_datatype);
int read_order_dynamic_array(char * buffer, int buffer_size, int * j, order_array * temp_datatype_array);
int read_order_static_array(char * buffer, int buffer_size, int * j, order * temp_datatype_array, int size);
void write_order(FILE *file, order * temp_datatype);
void write_order_static_array(FILE *file, order * temp_datatype, int size);
void write_order_dynamic_array(FILE *file, order_array * temp_datatype);
void init_index_adt(/*@out@*/ index_adt * temp);
void init_index_adt_static_array(/*@out@*/ index_adt * array, int size);
int read_index_adt(char * buffer, int buffer_size, int * j, index_adt * temp_datatype);
int read_index_adt_dynamic_array(char * buffer, int buffer_size, int * j, index_adt_array * temp_datatype_array);
int read_index_adt_static_array(char * buffer, int buffer_size, int * j, index_adt * temp_datatype_array, int size);
void write_index_adt(FILE *file, index_adt * temp_datatype);
void write_index_adt_static_array(FILE *file, index_adt * temp_datatype, int size);
void write_index_adt_dynamic_array(FILE *file, index_adt_array * temp_datatype);
void init_index_portfolio(/*@out@*/ index_portfolio * temp);
void init_index_portfolio_static_array(/*@out@*/ index_portfolio * array, int size);
int read_index_portfolio(char * buffer, int buffer_size, int * j, index_portfolio * temp_datatype);
int read_index_portfolio_dynamic_array(char * buffer, int buffer_size, int * j, index_portfolio_array * temp_datatype_array);
int read_index_portfolio_static_array(char * buffer, int buffer_size, int * j, index_portfolio * temp_datatype_array, int size);
void write_index_portfolio(FILE *file, index_portfolio * temp_datatype);
void write_index_portfolio_static_array(FILE *file, index_portfolio * temp_datatype, int size);
void write_index_portfolio_dynamic_array(FILE *file, index_portfolio_array * temp_datatype);
void init_Belief(/*@out@*/ Belief * temp);
void init_Belief_static_array(/*@out@*/ Belief * array, int size);
int read_Belief(char * buffer, int buffer_size, int * j, Belief * temp_datatype);
int read_Belief_dynamic_array(char * buffer, int buffer_size, int * j, Belief_array * temp_datatype_array);
int read_Belief_static_array(char * buffer, int buffer_size, int * j, Belief * temp_datatype_array, int size);
void write_Belief(FILE *file, Belief * temp_datatype);
void write_Belief_static_array(FILE *file, Belief * temp_datatype, int size);
void write_Belief_dynamic_array(FILE *file, Belief_array * temp_datatype);
void init_capital_good_request(/*@out@*/ capital_good_request * temp);
void init_capital_good_request_static_array(/*@out@*/ capital_good_request * array, int size);
int read_capital_good_request(char * buffer, int buffer_size, int * j, capital_good_request * temp_datatype);
int read_capital_good_request_dynamic_array(char * buffer, int buffer_size, int * j, capital_good_request_array * temp_datatype_array);
int read_capital_good_request_static_array(char * buffer, int buffer_size, int * j, capital_good_request * temp_datatype_array, int size);
void write_capital_good_request(FILE *file, capital_good_request * temp_datatype);
void write_capital_good_request_static_array(FILE *file, capital_good_request * temp_datatype, int size);
void write_capital_good_request_dynamic_array(FILE *file, capital_good_request_array * temp_datatype);
void init_vintage(/*@out@*/ vintage * temp);
void init_vintage_static_array(/*@out@*/ vintage * array, int size);
int read_vintage(char * buffer, int buffer_size, int * j, vintage * temp_datatype);
int read_vintage_dynamic_array(char * buffer, int buffer_size, int * j, vintage_array * temp_datatype_array);
int read_vintage_static_array(char * buffer, int buffer_size, int * j, vintage * temp_datatype_array, int size);
void write_vintage(FILE *file, vintage * temp_datatype);
void write_vintage_static_array(FILE *file, vintage * temp_datatype, int size);
void write_vintage_dynamic_array(FILE *file, vintage_array * temp_datatype);
void init_adt_sales_per_vintage(/*@out@*/ adt_sales_per_vintage * temp);
void init_adt_sales_per_vintage_static_array(/*@out@*/ adt_sales_per_vintage * array, int size);
int read_adt_sales_per_vintage(char * buffer, int buffer_size, int * j, adt_sales_per_vintage * temp_datatype);
int read_adt_sales_per_vintage_dynamic_array(char * buffer, int buffer_size, int * j, adt_sales_per_vintage_array * temp_datatype_array);
int read_adt_sales_per_vintage_static_array(char * buffer, int buffer_size, int * j, adt_sales_per_vintage * temp_datatype_array, int size);
void write_adt_sales_per_vintage(FILE *file, adt_sales_per_vintage * temp_datatype);
void write_adt_sales_per_vintage_static_array(FILE *file, adt_sales_per_vintage * temp_datatype, int size);
void write_adt_sales_per_vintage_dynamic_array(FILE *file, adt_sales_per_vintage_array * temp_datatype);
void init_adt_list_adaptation_speed(/*@out@*/ adt_list_adaptation_speed * temp);
void init_adt_list_adaptation_speed_static_array(/*@out@*/ adt_list_adaptation_speed * array, int size);
int read_adt_list_adaptation_speed(char * buffer, int buffer_size, int * j, adt_list_adaptation_speed * temp_datatype);
int read_adt_list_adaptation_speed_dynamic_array(char * buffer, int buffer_size, int * j, adt_list_adaptation_speed_array * temp_datatype_array);
int read_adt_list_adaptation_speed_static_array(char * buffer, int buffer_size, int * j, adt_list_adaptation_speed * temp_datatype_array, int size);
void write_adt_list_adaptation_speed(FILE *file, adt_list_adaptation_speed * temp_datatype);
void write_adt_list_adaptation_speed_static_array(FILE *file, adt_list_adaptation_speed * temp_datatype, int size);
void write_adt_list_adaptation_speed_dynamic_array(FILE *file, adt_list_adaptation_speed_array * temp_datatype);
void init_employee(/*@out@*/ employee * temp);
void init_employee_static_array(/*@out@*/ employee * array, int size);
int read_employee(char * buffer, int buffer_size, int * j, employee * temp_datatype);
int read_employee_dynamic_array(char * buffer, int buffer_size, int * j, employee_array * temp_datatype_array);
int read_employee_static_array(char * buffer, int buffer_size, int * j, employee * temp_datatype_array, int size);
void write_employee(FILE *file, employee * temp_datatype);
void write_employee_static_array(FILE *file, employee * temp_datatype, int size);
void write_employee_dynamic_array(FILE *file, employee_array * temp_datatype);
void init_vacancy(/*@out@*/ vacancy * temp);
void init_vacancy_static_array(/*@out@*/ vacancy * array, int size);
int read_vacancy(char * buffer, int buffer_size, int * j, vacancy * temp_datatype);
int read_vacancy_dynamic_array(char * buffer, int buffer_size, int * j, vacancy_array * temp_datatype_array);
int read_vacancy_static_array(char * buffer, int buffer_size, int * j, vacancy * temp_datatype_array, int size);
void write_vacancy(FILE *file, vacancy * temp_datatype);
void write_vacancy_static_array(FILE *file, vacancy * temp_datatype, int size);
void write_vacancy_dynamic_array(FILE *file, vacancy_array * temp_datatype);
void init_job_application(/*@out@*/ job_application * temp);
void init_job_application_static_array(/*@out@*/ job_application * array, int size);
int read_job_application(char * buffer, int buffer_size, int * j, job_application * temp_datatype);
int read_job_application_dynamic_array(char * buffer, int buffer_size, int * j, job_application_array * temp_datatype_array);
int read_job_application_static_array(char * buffer, int buffer_size, int * j, job_application * temp_datatype_array, int size);
void write_job_application(FILE *file, job_application * temp_datatype);
void write_job_application_static_array(FILE *file, job_application * temp_datatype, int size);
void write_job_application_dynamic_array(FILE *file, job_application_array * temp_datatype);
void init_job_offer(/*@out@*/ job_offer * temp);
void init_job_offer_static_array(/*@out@*/ job_offer * array, int size);
int read_job_offer(char * buffer, int buffer_size, int * j, job_offer * temp_datatype);
int read_job_offer_dynamic_array(char * buffer, int buffer_size, int * j, job_offer_array * temp_datatype_array);
int read_job_offer_static_array(char * buffer, int buffer_size, int * j, job_offer * temp_datatype_array, int size);
void write_job_offer(FILE *file, job_offer * temp_datatype);
void write_job_offer_static_array(FILE *file, job_offer * temp_datatype, int size);
void write_job_offer_dynamic_array(FILE *file, job_offer_array * temp_datatype);
void init_logit(/*@out@*/ logit * temp);
void init_logit_static_array(/*@out@*/ logit * array, int size);
int read_logit(char * buffer, int buffer_size, int * j, logit * temp_datatype);
int read_logit_dynamic_array(char * buffer, int buffer_size, int * j, logit_array * temp_datatype_array);
int read_logit_static_array(char * buffer, int buffer_size, int * j, logit * temp_datatype_array, int size);
void write_logit(FILE *file, logit * temp_datatype);
void write_logit_static_array(FILE *file, logit * temp_datatype, int size);
void write_logit_dynamic_array(FILE *file, logit_array * temp_datatype);
void init_adt_skill_distribution(/*@out@*/ adt_skill_distribution * temp);
void init_adt_skill_distribution_static_array(/*@out@*/ adt_skill_distribution * array, int size);
int read_adt_skill_distribution(char * buffer, int buffer_size, int * j, adt_skill_distribution * temp_datatype);
int read_adt_skill_distribution_dynamic_array(char * buffer, int buffer_size, int * j, adt_skill_distribution_array * temp_datatype_array);
int read_adt_skill_distribution_static_array(char * buffer, int buffer_size, int * j, adt_skill_distribution * temp_datatype_array, int size);
void write_adt_skill_distribution(FILE *file, adt_skill_distribution * temp_datatype);
void write_adt_skill_distribution_static_array(FILE *file, adt_skill_distribution * temp_datatype, int size);
void write_adt_skill_distribution_dynamic_array(FILE *file, adt_skill_distribution_array * temp_datatype);
void init_adt_actual_skill_distribution_with_ids(/*@out@*/ adt_actual_skill_distribution_with_ids * temp);
void init_adt_actual_skill_distribution_with_ids_static_array(/*@out@*/ adt_actual_skill_distribution_with_ids * array, int size);
int read_adt_actual_skill_distribution_with_ids(char * buffer, int buffer_size, int * j, adt_actual_skill_distribution_with_ids * temp_datatype);
int read_adt_actual_skill_distribution_with_ids_dynamic_array(char * buffer, int buffer_size, int * j, adt_actual_skill_distribution_with_ids_array * temp_datatype_array);
int read_adt_actual_skill_distribution_with_ids_static_array(char * buffer, int buffer_size, int * j, adt_actual_skill_distribution_with_ids * temp_datatype_array, int size);
void write_adt_actual_skill_distribution_with_ids(FILE *file, adt_actual_skill_distribution_with_ids * temp_datatype);
void write_adt_actual_skill_distribution_with_ids_static_array(FILE *file, adt_actual_skill_distribution_with_ids * temp_datatype, int size);
void write_adt_actual_skill_distribution_with_ids_dynamic_array(FILE *file, adt_actual_skill_distribution_with_ids_array * temp_datatype);
void init_adt_gov_inflows_outflows(/*@out@*/ adt_gov_inflows_outflows * temp);
void init_adt_gov_inflows_outflows_static_array(/*@out@*/ adt_gov_inflows_outflows * array, int size);
int read_adt_gov_inflows_outflows(char * buffer, int buffer_size, int * j, adt_gov_inflows_outflows * temp_datatype);
int read_adt_gov_inflows_outflows_dynamic_array(char * buffer, int buffer_size, int * j, adt_gov_inflows_outflows_array * temp_datatype_array);
int read_adt_gov_inflows_outflows_static_array(char * buffer, int buffer_size, int * j, adt_gov_inflows_outflows * temp_datatype_array, int size);
void write_adt_gov_inflows_outflows(FILE *file, adt_gov_inflows_outflows * temp_datatype);
void write_adt_gov_inflows_outflows_static_array(FILE *file, adt_gov_inflows_outflows * temp_datatype, int size);
void write_adt_gov_inflows_outflows_dynamic_array(FILE *file, adt_gov_inflows_outflows_array * temp_datatype);
void init_household_data(/*@out@*/ household_data * temp);
void init_household_data_static_array(/*@out@*/ household_data * array, int size);
int read_household_data(char * buffer, int buffer_size, int * j, household_data * temp_datatype);
int read_household_data_dynamic_array(char * buffer, int buffer_size, int * j, household_data_array * temp_datatype_array);
int read_household_data_static_array(char * buffer, int buffer_size, int * j, household_data * temp_datatype_array, int size);
void write_household_data(FILE *file, household_data * temp_datatype);
void write_household_data_static_array(FILE *file, household_data * temp_datatype, int size);
void write_household_data_dynamic_array(FILE *file, household_data_array * temp_datatype);
void init_price_quality_pair(/*@out@*/ price_quality_pair * temp);
void init_price_quality_pair_static_array(/*@out@*/ price_quality_pair * array, int size);
int read_price_quality_pair(char * buffer, int buffer_size, int * j, price_quality_pair * temp_datatype);
int read_price_quality_pair_dynamic_array(char * buffer, int buffer_size, int * j, price_quality_pair_array * temp_datatype_array);
int read_price_quality_pair_static_array(char * buffer, int buffer_size, int * j, price_quality_pair * temp_datatype_array, int size);
void write_price_quality_pair(FILE *file, price_quality_pair * temp_datatype);
void write_price_quality_pair_static_array(FILE *file, price_quality_pair * temp_datatype, int size);
void write_price_quality_pair_dynamic_array(FILE *file, price_quality_pair_array * temp_datatype);
void init_firm_data(/*@out@*/ firm_data * temp);
void init_firm_data_static_array(/*@out@*/ firm_data * array, int size);
int read_firm_data(char * buffer, int buffer_size, int * j, firm_data * temp_datatype);
int read_firm_data_dynamic_array(char * buffer, int buffer_size, int * j, firm_data_array * temp_datatype_array);
int read_firm_data_static_array(char * buffer, int buffer_size, int * j, firm_data * temp_datatype_array, int size);
void write_firm_data(FILE *file, firm_data * temp_datatype);
void write_firm_data_static_array(FILE *file, firm_data * temp_datatype, int size);
void write_firm_data_dynamic_array(FILE *file, firm_data_array * temp_datatype);
void init_government_data(/*@out@*/ government_data * temp);
void init_government_data_static_array(/*@out@*/ government_data * array, int size);
int read_government_data(char * buffer, int buffer_size, int * j, government_data * temp_datatype);
int read_government_data_dynamic_array(char * buffer, int buffer_size, int * j, government_data_array * temp_datatype_array);
int read_government_data_static_array(char * buffer, int buffer_size, int * j, government_data * temp_datatype_array, int size);
void write_government_data(FILE *file, government_data * temp_datatype);
void write_government_data_static_array(FILE *file, government_data * temp_datatype, int size);
void write_government_data_dynamic_array(FILE *file, government_data_array * temp_datatype);
void init_region_data_item(/*@out@*/ region_data_item * temp);
void init_region_data_item_static_array(/*@out@*/ region_data_item * array, int size);
int read_region_data_item(char * buffer, int buffer_size, int * j, region_data_item * temp_datatype);
int read_region_data_item_dynamic_array(char * buffer, int buffer_size, int * j, region_data_item_array * temp_datatype_array);
int read_region_data_item_static_array(char * buffer, int buffer_size, int * j, region_data_item * temp_datatype_array, int size);
void write_region_data_item(FILE *file, region_data_item * temp_datatype);
void write_region_data_item_static_array(FILE *file, region_data_item * temp_datatype, int size);
void write_region_data_item_dynamic_array(FILE *file, region_data_item_array * temp_datatype);
void init_history_item(/*@out@*/ history_item * temp);
void init_history_item_static_array(/*@out@*/ history_item * array, int size);
int read_history_item(char * buffer, int buffer_size, int * j, history_item * temp_datatype);
int read_history_item_dynamic_array(char * buffer, int buffer_size, int * j, history_item_array * temp_datatype_array);
int read_history_item_static_array(char * buffer, int buffer_size, int * j, history_item * temp_datatype_array, int size);
void write_history_item(FILE *file, history_item * temp_datatype);
void write_history_item_static_array(FILE *file, history_item * temp_datatype, int size);
void write_history_item_dynamic_array(FILE *file, history_item_array * temp_datatype);
void init_firm_stocks_adt(/*@out@*/ firm_stocks_adt * temp);
void init_firm_stocks_adt_static_array(/*@out@*/ firm_stocks_adt * array, int size);
int read_firm_stocks_adt(char * buffer, int buffer_size, int * j, firm_stocks_adt * temp_datatype);
int read_firm_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, firm_stocks_adt_array * temp_datatype_array);
int read_firm_stocks_adt_static_array(char * buffer, int buffer_size, int * j, firm_stocks_adt * temp_datatype_array, int size);
void write_firm_stocks_adt(FILE *file, firm_stocks_adt * temp_datatype);
void write_firm_stocks_adt_static_array(FILE *file, firm_stocks_adt * temp_datatype, int size);
void write_firm_stocks_adt_dynamic_array(FILE *file, firm_stocks_adt_array * temp_datatype);
void init_firm_outflows_adt(/*@out@*/ firm_outflows_adt * temp);
void init_firm_outflows_adt_static_array(/*@out@*/ firm_outflows_adt * array, int size);
int read_firm_outflows_adt(char * buffer, int buffer_size, int * j, firm_outflows_adt * temp_datatype);
int read_firm_outflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, firm_outflows_adt_array * temp_datatype_array);
int read_firm_outflows_adt_static_array(char * buffer, int buffer_size, int * j, firm_outflows_adt * temp_datatype_array, int size);
void write_firm_outflows_adt(FILE *file, firm_outflows_adt * temp_datatype);
void write_firm_outflows_adt_static_array(FILE *file, firm_outflows_adt * temp_datatype, int size);
void write_firm_outflows_adt_dynamic_array(FILE *file, firm_outflows_adt_array * temp_datatype);
void init_firm_inflows_adt(/*@out@*/ firm_inflows_adt * temp);
void init_firm_inflows_adt_static_array(/*@out@*/ firm_inflows_adt * array, int size);
int read_firm_inflows_adt(char * buffer, int buffer_size, int * j, firm_inflows_adt * temp_datatype);
int read_firm_inflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, firm_inflows_adt_array * temp_datatype_array);
int read_firm_inflows_adt_static_array(char * buffer, int buffer_size, int * j, firm_inflows_adt * temp_datatype_array, int size);
void write_firm_inflows_adt(FILE *file, firm_inflows_adt * temp_datatype);
void write_firm_inflows_adt_static_array(FILE *file, firm_inflows_adt * temp_datatype, int size);
void write_firm_inflows_adt_dynamic_array(FILE *file, firm_inflows_adt_array * temp_datatype);
void init_household_stocks_adt(/*@out@*/ household_stocks_adt * temp);
void init_household_stocks_adt_static_array(/*@out@*/ household_stocks_adt * array, int size);
int read_household_stocks_adt(char * buffer, int buffer_size, int * j, household_stocks_adt * temp_datatype);
int read_household_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, household_stocks_adt_array * temp_datatype_array);
int read_household_stocks_adt_static_array(char * buffer, int buffer_size, int * j, household_stocks_adt * temp_datatype_array, int size);
void write_household_stocks_adt(FILE *file, household_stocks_adt * temp_datatype);
void write_household_stocks_adt_static_array(FILE *file, household_stocks_adt * temp_datatype, int size);
void write_household_stocks_adt_dynamic_array(FILE *file, household_stocks_adt_array * temp_datatype);
void init_household_outflows_adt(/*@out@*/ household_outflows_adt * temp);
void init_household_outflows_adt_static_array(/*@out@*/ household_outflows_adt * array, int size);
int read_household_outflows_adt(char * buffer, int buffer_size, int * j, household_outflows_adt * temp_datatype);
int read_household_outflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, household_outflows_adt_array * temp_datatype_array);
int read_household_outflows_adt_static_array(char * buffer, int buffer_size, int * j, household_outflows_adt * temp_datatype_array, int size);
void write_household_outflows_adt(FILE *file, household_outflows_adt * temp_datatype);
void write_household_outflows_adt_static_array(FILE *file, household_outflows_adt * temp_datatype, int size);
void write_household_outflows_adt_dynamic_array(FILE *file, household_outflows_adt_array * temp_datatype);
void init_household_inflows_adt(/*@out@*/ household_inflows_adt * temp);
void init_household_inflows_adt_static_array(/*@out@*/ household_inflows_adt * array, int size);
int read_household_inflows_adt(char * buffer, int buffer_size, int * j, household_inflows_adt * temp_datatype);
int read_household_inflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, household_inflows_adt_array * temp_datatype_array);
int read_household_inflows_adt_static_array(char * buffer, int buffer_size, int * j, household_inflows_adt * temp_datatype_array, int size);
void write_household_inflows_adt(FILE *file, household_inflows_adt * temp_datatype);
void write_household_inflows_adt_static_array(FILE *file, household_inflows_adt * temp_datatype, int size);
void write_household_inflows_adt_dynamic_array(FILE *file, household_inflows_adt_array * temp_datatype);
void init_igfirm_stocks_adt(/*@out@*/ igfirm_stocks_adt * temp);
void init_igfirm_stocks_adt_static_array(/*@out@*/ igfirm_stocks_adt * array, int size);
int read_igfirm_stocks_adt(char * buffer, int buffer_size, int * j, igfirm_stocks_adt * temp_datatype);
int read_igfirm_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, igfirm_stocks_adt_array * temp_datatype_array);
int read_igfirm_stocks_adt_static_array(char * buffer, int buffer_size, int * j, igfirm_stocks_adt * temp_datatype_array, int size);
void write_igfirm_stocks_adt(FILE *file, igfirm_stocks_adt * temp_datatype);
void write_igfirm_stocks_adt_static_array(FILE *file, igfirm_stocks_adt * temp_datatype, int size);
void write_igfirm_stocks_adt_dynamic_array(FILE *file, igfirm_stocks_adt_array * temp_datatype);
void init_igfirm_outflows_adt(/*@out@*/ igfirm_outflows_adt * temp);
void init_igfirm_outflows_adt_static_array(/*@out@*/ igfirm_outflows_adt * array, int size);
int read_igfirm_outflows_adt(char * buffer, int buffer_size, int * j, igfirm_outflows_adt * temp_datatype);
int read_igfirm_outflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, igfirm_outflows_adt_array * temp_datatype_array);
int read_igfirm_outflows_adt_static_array(char * buffer, int buffer_size, int * j, igfirm_outflows_adt * temp_datatype_array, int size);
void write_igfirm_outflows_adt(FILE *file, igfirm_outflows_adt * temp_datatype);
void write_igfirm_outflows_adt_static_array(FILE *file, igfirm_outflows_adt * temp_datatype, int size);
void write_igfirm_outflows_adt_dynamic_array(FILE *file, igfirm_outflows_adt_array * temp_datatype);
void init_igfirm_inflows_adt(/*@out@*/ igfirm_inflows_adt * temp);
void init_igfirm_inflows_adt_static_array(/*@out@*/ igfirm_inflows_adt * array, int size);
int read_igfirm_inflows_adt(char * buffer, int buffer_size, int * j, igfirm_inflows_adt * temp_datatype);
int read_igfirm_inflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, igfirm_inflows_adt_array * temp_datatype_array);
int read_igfirm_inflows_adt_static_array(char * buffer, int buffer_size, int * j, igfirm_inflows_adt * temp_datatype_array, int size);
void write_igfirm_inflows_adt(FILE *file, igfirm_inflows_adt * temp_datatype);
void write_igfirm_inflows_adt_static_array(FILE *file, igfirm_inflows_adt * temp_datatype, int size);
void write_igfirm_inflows_adt_dynamic_array(FILE *file, igfirm_inflows_adt_array * temp_datatype);
void init_bank_stocks_adt(/*@out@*/ bank_stocks_adt * temp);
void init_bank_stocks_adt_static_array(/*@out@*/ bank_stocks_adt * array, int size);
int read_bank_stocks_adt(char * buffer, int buffer_size, int * j, bank_stocks_adt * temp_datatype);
int read_bank_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, bank_stocks_adt_array * temp_datatype_array);
int read_bank_stocks_adt_static_array(char * buffer, int buffer_size, int * j, bank_stocks_adt * temp_datatype_array, int size);
void write_bank_stocks_adt(FILE *file, bank_stocks_adt * temp_datatype);
void write_bank_stocks_adt_static_array(FILE *file, bank_stocks_adt * temp_datatype, int size);
void write_bank_stocks_adt_dynamic_array(FILE *file, bank_stocks_adt_array * temp_datatype);
void init_bank_outflows_adt(/*@out@*/ bank_outflows_adt * temp);
void init_bank_outflows_adt_static_array(/*@out@*/ bank_outflows_adt * array, int size);
int read_bank_outflows_adt(char * buffer, int buffer_size, int * j, bank_outflows_adt * temp_datatype);
int read_bank_outflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, bank_outflows_adt_array * temp_datatype_array);
int read_bank_outflows_adt_static_array(char * buffer, int buffer_size, int * j, bank_outflows_adt * temp_datatype_array, int size);
void write_bank_outflows_adt(FILE *file, bank_outflows_adt * temp_datatype);
void write_bank_outflows_adt_static_array(FILE *file, bank_outflows_adt * temp_datatype, int size);
void write_bank_outflows_adt_dynamic_array(FILE *file, bank_outflows_adt_array * temp_datatype);
void init_bank_inflows_adt(/*@out@*/ bank_inflows_adt * temp);
void init_bank_inflows_adt_static_array(/*@out@*/ bank_inflows_adt * array, int size);
int read_bank_inflows_adt(char * buffer, int buffer_size, int * j, bank_inflows_adt * temp_datatype);
int read_bank_inflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, bank_inflows_adt_array * temp_datatype_array);
int read_bank_inflows_adt_static_array(char * buffer, int buffer_size, int * j, bank_inflows_adt * temp_datatype_array, int size);
void write_bank_inflows_adt(FILE *file, bank_inflows_adt * temp_datatype);
void write_bank_inflows_adt_static_array(FILE *file, bank_inflows_adt * temp_datatype, int size);
void write_bank_inflows_adt_dynamic_array(FILE *file, bank_inflows_adt_array * temp_datatype);
void init_gov_stocks_adt(/*@out@*/ gov_stocks_adt * temp);
void init_gov_stocks_adt_static_array(/*@out@*/ gov_stocks_adt * array, int size);
int read_gov_stocks_adt(char * buffer, int buffer_size, int * j, gov_stocks_adt * temp_datatype);
int read_gov_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, gov_stocks_adt_array * temp_datatype_array);
int read_gov_stocks_adt_static_array(char * buffer, int buffer_size, int * j, gov_stocks_adt * temp_datatype_array, int size);
void write_gov_stocks_adt(FILE *file, gov_stocks_adt * temp_datatype);
void write_gov_stocks_adt_static_array(FILE *file, gov_stocks_adt * temp_datatype, int size);
void write_gov_stocks_adt_dynamic_array(FILE *file, gov_stocks_adt_array * temp_datatype);
void init_gov_outflows_adt(/*@out@*/ gov_outflows_adt * temp);
void init_gov_outflows_adt_static_array(/*@out@*/ gov_outflows_adt * array, int size);
int read_gov_outflows_adt(char * buffer, int buffer_size, int * j, gov_outflows_adt * temp_datatype);
int read_gov_outflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, gov_outflows_adt_array * temp_datatype_array);
int read_gov_outflows_adt_static_array(char * buffer, int buffer_size, int * j, gov_outflows_adt * temp_datatype_array, int size);
void write_gov_outflows_adt(FILE *file, gov_outflows_adt * temp_datatype);
void write_gov_outflows_adt_static_array(FILE *file, gov_outflows_adt * temp_datatype, int size);
void write_gov_outflows_adt_dynamic_array(FILE *file, gov_outflows_adt_array * temp_datatype);
void init_gov_inflows_adt(/*@out@*/ gov_inflows_adt * temp);
void init_gov_inflows_adt_static_array(/*@out@*/ gov_inflows_adt * array, int size);
int read_gov_inflows_adt(char * buffer, int buffer_size, int * j, gov_inflows_adt * temp_datatype);
int read_gov_inflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, gov_inflows_adt_array * temp_datatype_array);
int read_gov_inflows_adt_static_array(char * buffer, int buffer_size, int * j, gov_inflows_adt * temp_datatype_array, int size);
void write_gov_inflows_adt(FILE *file, gov_inflows_adt * temp_datatype);
void write_gov_inflows_adt_static_array(FILE *file, gov_inflows_adt * temp_datatype, int size);
void write_gov_inflows_adt_dynamic_array(FILE *file, gov_inflows_adt_array * temp_datatype);
void init_ecb_stocks_adt(/*@out@*/ ecb_stocks_adt * temp);
void init_ecb_stocks_adt_static_array(/*@out@*/ ecb_stocks_adt * array, int size);
int read_ecb_stocks_adt(char * buffer, int buffer_size, int * j, ecb_stocks_adt * temp_datatype);
int read_ecb_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, ecb_stocks_adt_array * temp_datatype_array);
int read_ecb_stocks_adt_static_array(char * buffer, int buffer_size, int * j, ecb_stocks_adt * temp_datatype_array, int size);
void write_ecb_stocks_adt(FILE *file, ecb_stocks_adt * temp_datatype);
void write_ecb_stocks_adt_static_array(FILE *file, ecb_stocks_adt * temp_datatype, int size);
void write_ecb_stocks_adt_dynamic_array(FILE *file, ecb_stocks_adt_array * temp_datatype);
void init_ecb_outflows_adt(/*@out@*/ ecb_outflows_adt * temp);
void init_ecb_outflows_adt_static_array(/*@out@*/ ecb_outflows_adt * array, int size);
int read_ecb_outflows_adt(char * buffer, int buffer_size, int * j, ecb_outflows_adt * temp_datatype);
int read_ecb_outflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, ecb_outflows_adt_array * temp_datatype_array);
int read_ecb_outflows_adt_static_array(char * buffer, int buffer_size, int * j, ecb_outflows_adt * temp_datatype_array, int size);
void write_ecb_outflows_adt(FILE *file, ecb_outflows_adt * temp_datatype);
void write_ecb_outflows_adt_static_array(FILE *file, ecb_outflows_adt * temp_datatype, int size);
void write_ecb_outflows_adt_dynamic_array(FILE *file, ecb_outflows_adt_array * temp_datatype);
void init_ecb_inflows_adt(/*@out@*/ ecb_inflows_adt * temp);
void init_ecb_inflows_adt_static_array(/*@out@*/ ecb_inflows_adt * array, int size);
int read_ecb_inflows_adt(char * buffer, int buffer_size, int * j, ecb_inflows_adt * temp_datatype);
int read_ecb_inflows_adt_dynamic_array(char * buffer, int buffer_size, int * j, ecb_inflows_adt_array * temp_datatype_array);
int read_ecb_inflows_adt_static_array(char * buffer, int buffer_size, int * j, ecb_inflows_adt * temp_datatype_array, int size);
void write_ecb_inflows_adt(FILE *file, ecb_inflows_adt * temp_datatype);
void write_ecb_inflows_adt_static_array(FILE *file, ecb_inflows_adt * temp_datatype, int size);
void write_ecb_inflows_adt_dynamic_array(FILE *file, ecb_inflows_adt_array * temp_datatype);
void init_firm_balance_sheet_adt(/*@out@*/ firm_balance_sheet_adt * temp);
void init_firm_balance_sheet_adt_static_array(/*@out@*/ firm_balance_sheet_adt * array, int size);
int read_firm_balance_sheet_adt(char * buffer, int buffer_size, int * j, firm_balance_sheet_adt * temp_datatype);
int read_firm_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, firm_balance_sheet_adt_array * temp_datatype_array);
int read_firm_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, firm_balance_sheet_adt * temp_datatype_array, int size);
void write_firm_balance_sheet_adt(FILE *file, firm_balance_sheet_adt * temp_datatype);
void write_firm_balance_sheet_adt_static_array(FILE *file, firm_balance_sheet_adt * temp_datatype, int size);
void write_firm_balance_sheet_adt_dynamic_array(FILE *file, firm_balance_sheet_adt_array * temp_datatype);
void init_household_balance_sheet_adt(/*@out@*/ household_balance_sheet_adt * temp);
void init_household_balance_sheet_adt_static_array(/*@out@*/ household_balance_sheet_adt * array, int size);
int read_household_balance_sheet_adt(char * buffer, int buffer_size, int * j, household_balance_sheet_adt * temp_datatype);
int read_household_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, household_balance_sheet_adt_array * temp_datatype_array);
int read_household_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, household_balance_sheet_adt * temp_datatype_array, int size);
void write_household_balance_sheet_adt(FILE *file, household_balance_sheet_adt * temp_datatype);
void write_household_balance_sheet_adt_static_array(FILE *file, household_balance_sheet_adt * temp_datatype, int size);
void write_household_balance_sheet_adt_dynamic_array(FILE *file, household_balance_sheet_adt_array * temp_datatype);
void init_igfirm_balance_sheet_adt(/*@out@*/ igfirm_balance_sheet_adt * temp);
void init_igfirm_balance_sheet_adt_static_array(/*@out@*/ igfirm_balance_sheet_adt * array, int size);
int read_igfirm_balance_sheet_adt(char * buffer, int buffer_size, int * j, igfirm_balance_sheet_adt * temp_datatype);
int read_igfirm_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, igfirm_balance_sheet_adt_array * temp_datatype_array);
int read_igfirm_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, igfirm_balance_sheet_adt * temp_datatype_array, int size);
void write_igfirm_balance_sheet_adt(FILE *file, igfirm_balance_sheet_adt * temp_datatype);
void write_igfirm_balance_sheet_adt_static_array(FILE *file, igfirm_balance_sheet_adt * temp_datatype, int size);
void write_igfirm_balance_sheet_adt_dynamic_array(FILE *file, igfirm_balance_sheet_adt_array * temp_datatype);
void init_bank_balance_sheet_adt(/*@out@*/ bank_balance_sheet_adt * temp);
void init_bank_balance_sheet_adt_static_array(/*@out@*/ bank_balance_sheet_adt * array, int size);
int read_bank_balance_sheet_adt(char * buffer, int buffer_size, int * j, bank_balance_sheet_adt * temp_datatype);
int read_bank_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, bank_balance_sheet_adt_array * temp_datatype_array);
int read_bank_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, bank_balance_sheet_adt * temp_datatype_array, int size);
void write_bank_balance_sheet_adt(FILE *file, bank_balance_sheet_adt * temp_datatype);
void write_bank_balance_sheet_adt_static_array(FILE *file, bank_balance_sheet_adt * temp_datatype, int size);
void write_bank_balance_sheet_adt_dynamic_array(FILE *file, bank_balance_sheet_adt_array * temp_datatype);
void init_gov_balance_sheet_adt(/*@out@*/ gov_balance_sheet_adt * temp);
void init_gov_balance_sheet_adt_static_array(/*@out@*/ gov_balance_sheet_adt * array, int size);
int read_gov_balance_sheet_adt(char * buffer, int buffer_size, int * j, gov_balance_sheet_adt * temp_datatype);
int read_gov_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, gov_balance_sheet_adt_array * temp_datatype_array);
int read_gov_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, gov_balance_sheet_adt * temp_datatype_array, int size);
void write_gov_balance_sheet_adt(FILE *file, gov_balance_sheet_adt * temp_datatype);
void write_gov_balance_sheet_adt_static_array(FILE *file, gov_balance_sheet_adt * temp_datatype, int size);
void write_gov_balance_sheet_adt_dynamic_array(FILE *file, gov_balance_sheet_adt_array * temp_datatype);
void init_ecb_balance_sheet_adt(/*@out@*/ ecb_balance_sheet_adt * temp);
void init_ecb_balance_sheet_adt_static_array(/*@out@*/ ecb_balance_sheet_adt * array, int size);
int read_ecb_balance_sheet_adt(char * buffer, int buffer_size, int * j, ecb_balance_sheet_adt * temp_datatype);
int read_ecb_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, ecb_balance_sheet_adt_array * temp_datatype_array);
int read_ecb_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, ecb_balance_sheet_adt * temp_datatype_array, int size);
void write_ecb_balance_sheet_adt(FILE *file, ecb_balance_sheet_adt * temp_datatype);
void write_ecb_balance_sheet_adt_static_array(FILE *file, ecb_balance_sheet_adt * temp_datatype, int size);
void write_ecb_balance_sheet_adt_dynamic_array(FILE *file, ecb_balance_sheet_adt_array * temp_datatype);
void init_adt_subsidies_per_government(/*@out@*/ adt_subsidies_per_government * temp);
void init_adt_subsidies_per_government_static_array(/*@out@*/ adt_subsidies_per_government * array, int size);
int read_adt_subsidies_per_government(char * buffer, int buffer_size, int * j, adt_subsidies_per_government * temp_datatype);
int read_adt_subsidies_per_government_dynamic_array(char * buffer, int buffer_size, int * j, adt_subsidies_per_government_array * temp_datatype_array);
int read_adt_subsidies_per_government_static_array(char * buffer, int buffer_size, int * j, adt_subsidies_per_government * temp_datatype_array, int size);
void write_adt_subsidies_per_government(FILE *file, adt_subsidies_per_government * temp_datatype);
void write_adt_subsidies_per_government_static_array(FILE *file, adt_subsidies_per_government * temp_datatype, int size);
void write_adt_subsidies_per_government_dynamic_array(FILE *file, adt_subsidies_per_government_array * temp_datatype);
void init_estimated_values_adt(/*@out@*/ estimated_values_adt * temp);
void init_estimated_values_adt_static_array(/*@out@*/ estimated_values_adt * array, int size);
int read_estimated_values_adt(char * buffer, int buffer_size, int * j, estimated_values_adt * temp_datatype);
int read_estimated_values_adt_dynamic_array(char * buffer, int buffer_size, int * j, estimated_values_adt_array * temp_datatype_array);
int read_estimated_values_adt_static_array(char * buffer, int buffer_size, int * j, estimated_values_adt * temp_datatype_array, int size);
void write_estimated_values_adt(FILE *file, estimated_values_adt * temp_datatype);
void write_estimated_values_adt_static_array(FILE *file, estimated_values_adt * temp_datatype, int size);
void write_estimated_values_adt_dynamic_array(FILE *file, estimated_values_adt_array * temp_datatype);
void init_dt_market_research_price(/*@out@*/ dt_market_research_price * temp);
void init_dt_market_research_price_static_array(/*@out@*/ dt_market_research_price * array, int size);
int read_dt_market_research_price(char * buffer, int buffer_size, int * j, dt_market_research_price * temp_datatype);
int read_dt_market_research_price_dynamic_array(char * buffer, int buffer_size, int * j, dt_market_research_price_array * temp_datatype_array);
int read_dt_market_research_price_static_array(char * buffer, int buffer_size, int * j, dt_market_research_price * temp_datatype_array, int size);
void write_dt_market_research_price(FILE *file, dt_market_research_price * temp_datatype);
void write_dt_market_research_price_static_array(FILE *file, dt_market_research_price * temp_datatype, int size);
void write_dt_market_research_price_dynamic_array(FILE *file, dt_market_research_price_array * temp_datatype);
void init_dt_market_research_qualities(/*@out@*/ dt_market_research_qualities * temp);
void init_dt_market_research_qualities_static_array(/*@out@*/ dt_market_research_qualities * array, int size);
int read_dt_market_research_qualities(char * buffer, int buffer_size, int * j, dt_market_research_qualities * temp_datatype);
int read_dt_market_research_qualities_dynamic_array(char * buffer, int buffer_size, int * j, dt_market_research_qualities_array * temp_datatype_array);
int read_dt_market_research_qualities_static_array(char * buffer, int buffer_size, int * j, dt_market_research_qualities * temp_datatype_array, int size);
void write_dt_market_research_qualities(FILE *file, dt_market_research_qualities * temp_datatype);
void write_dt_market_research_qualities_static_array(FILE *file, dt_market_research_qualities * temp_datatype, int size);
void write_dt_market_research_qualities_dynamic_array(FILE *file, dt_market_research_qualities_array * temp_datatype);
void init_dt_best_price_strategies(/*@out@*/ dt_best_price_strategies * temp);
void init_dt_best_price_strategies_static_array(/*@out@*/ dt_best_price_strategies * array, int size);
int read_dt_best_price_strategies(char * buffer, int buffer_size, int * j, dt_best_price_strategies * temp_datatype);
int read_dt_best_price_strategies_dynamic_array(char * buffer, int buffer_size, int * j, dt_best_price_strategies_array * temp_datatype_array);
int read_dt_best_price_strategies_static_array(char * buffer, int buffer_size, int * j, dt_best_price_strategies * temp_datatype_array, int size);
void write_dt_best_price_strategies(FILE *file, dt_best_price_strategies * temp_datatype);
void write_dt_best_price_strategies_static_array(FILE *file, dt_best_price_strategies * temp_datatype, int size);
void write_dt_best_price_strategies_dynamic_array(FILE *file, dt_best_price_strategies_array * temp_datatype);
void init_dt_price_range(/*@out@*/ dt_price_range * temp);
void init_dt_price_range_static_array(/*@out@*/ dt_price_range * array, int size);
int read_dt_price_range(char * buffer, int buffer_size, int * j, dt_price_range * temp_datatype);
int read_dt_price_range_dynamic_array(char * buffer, int buffer_size, int * j, dt_price_range_array * temp_datatype_array);
int read_dt_price_range_static_array(char * buffer, int buffer_size, int * j, dt_price_range * temp_datatype_array, int size);
void write_dt_price_range(FILE *file, dt_price_range * temp_datatype);
void write_dt_price_range_static_array(FILE *file, dt_price_range * temp_datatype, int size);
void write_dt_price_range_dynamic_array(FILE *file, dt_price_range_array * temp_datatype);
void init_dt_prospective_variables(/*@out@*/ dt_prospective_variables * temp);
void init_dt_prospective_variables_static_array(/*@out@*/ dt_prospective_variables * array, int size);
int read_dt_prospective_variables(char * buffer, int buffer_size, int * j, dt_prospective_variables * temp_datatype);
int read_dt_prospective_variables_dynamic_array(char * buffer, int buffer_size, int * j, dt_prospective_variables_array * temp_datatype_array);
int read_dt_prospective_variables_static_array(char * buffer, int buffer_size, int * j, dt_prospective_variables * temp_datatype_array, int size);
void write_dt_prospective_variables(FILE *file, dt_prospective_variables * temp_datatype);
void write_dt_prospective_variables_static_array(FILE *file, dt_prospective_variables * temp_datatype, int size);
void write_dt_prospective_variables_dynamic_array(FILE *file, dt_prospective_variables_array * temp_datatype);
void init_dt_variables_changed(/*@out@*/ dt_variables_changed * temp);
void init_dt_variables_changed_static_array(/*@out@*/ dt_variables_changed * array, int size);
int read_dt_variables_changed(char * buffer, int buffer_size, int * j, dt_variables_changed * temp_datatype);
int read_dt_variables_changed_dynamic_array(char * buffer, int buffer_size, int * j, dt_variables_changed_array * temp_datatype_array);
int read_dt_variables_changed_static_array(char * buffer, int buffer_size, int * j, dt_variables_changed * temp_datatype_array, int size);
void write_dt_variables_changed(FILE *file, dt_variables_changed * temp_datatype);
void write_dt_variables_changed_static_array(FILE *file, dt_variables_changed * temp_datatype, int size);
void write_dt_variables_changed_dynamic_array(FILE *file, dt_variables_changed_array * temp_datatype);
void init_dt_innovation_choice(/*@out@*/ dt_innovation_choice * temp);
void init_dt_innovation_choice_static_array(/*@out@*/ dt_innovation_choice * array, int size);
int read_dt_innovation_choice(char * buffer, int buffer_size, int * j, dt_innovation_choice * temp_datatype);
int read_dt_innovation_choice_dynamic_array(char * buffer, int buffer_size, int * j, dt_innovation_choice_array * temp_datatype_array);
int read_dt_innovation_choice_static_array(char * buffer, int buffer_size, int * j, dt_innovation_choice * temp_datatype_array, int size);
void write_dt_innovation_choice(FILE *file, dt_innovation_choice * temp_datatype);
void write_dt_innovation_choice_static_array(FILE *file, dt_innovation_choice * temp_datatype, int size);
void write_dt_innovation_choice_dynamic_array(FILE *file, dt_innovation_choice_array * temp_datatype);
void init_dt_demand_function(/*@out@*/ dt_demand_function * temp);
void init_dt_demand_function_static_array(/*@out@*/ dt_demand_function * array, int size);
int read_dt_demand_function(char * buffer, int buffer_size, int * j, dt_demand_function * temp_datatype);
int read_dt_demand_function_dynamic_array(char * buffer, int buffer_size, int * j, dt_demand_function_array * temp_datatype_array);
int read_dt_demand_function_static_array(char * buffer, int buffer_size, int * j, dt_demand_function * temp_datatype_array, int size);
void write_dt_demand_function(FILE *file, dt_demand_function * temp_datatype);
void write_dt_demand_function_static_array(FILE *file, dt_demand_function * temp_datatype, int size);
void write_dt_demand_function_dynamic_array(FILE *file, dt_demand_function_array * temp_datatype);
void init_dt_price_quantity_touple(/*@out@*/ dt_price_quantity_touple * temp);
void init_dt_price_quantity_touple_static_array(/*@out@*/ dt_price_quantity_touple * array, int size);
int read_dt_price_quantity_touple(char * buffer, int buffer_size, int * j, dt_price_quantity_touple * temp_datatype);
int read_dt_price_quantity_touple_dynamic_array(char * buffer, int buffer_size, int * j, dt_price_quantity_touple_array * temp_datatype_array);
int read_dt_price_quantity_touple_static_array(char * buffer, int buffer_size, int * j, dt_price_quantity_touple * temp_datatype_array, int size);
void write_dt_price_quantity_touple(FILE *file, dt_price_quantity_touple * temp_datatype);
void write_dt_price_quantity_touple_static_array(FILE *file, dt_price_quantity_touple * temp_datatype, int size);
void write_dt_price_quantity_touple_dynamic_array(FILE *file, dt_price_quantity_touple_array * temp_datatype);
void init_dt_market_size(/*@out@*/ dt_market_size * temp);
void init_dt_market_size_static_array(/*@out@*/ dt_market_size * array, int size);
int read_dt_market_size(char * buffer, int buffer_size, int * j, dt_market_size * temp_datatype);
int read_dt_market_size_dynamic_array(char * buffer, int buffer_size, int * j, dt_market_size_array * temp_datatype_array);
int read_dt_market_size_static_array(char * buffer, int buffer_size, int * j, dt_market_size * temp_datatype_array, int size);
void write_dt_market_size(FILE *file, dt_market_size * temp_datatype);
void write_dt_market_size_static_array(FILE *file, dt_market_size * temp_datatype, int size);
void write_dt_market_size_dynamic_array(FILE *file, dt_market_size_array * temp_datatype);
void init_dt_total_and_regional_market_size(/*@out@*/ dt_total_and_regional_market_size * temp);
void init_dt_total_and_regional_market_size_static_array(/*@out@*/ dt_total_and_regional_market_size * array, int size);
int read_dt_total_and_regional_market_size(char * buffer, int buffer_size, int * j, dt_total_and_regional_market_size * temp_datatype);
int read_dt_total_and_regional_market_size_dynamic_array(char * buffer, int buffer_size, int * j, dt_total_and_regional_market_size_array * temp_datatype_array);
int read_dt_total_and_regional_market_size_static_array(char * buffer, int buffer_size, int * j, dt_total_and_regional_market_size * temp_datatype_array, int size);
void write_dt_total_and_regional_market_size(FILE *file, dt_total_and_regional_market_size * temp_datatype);
void write_dt_total_and_regional_market_size_static_array(FILE *file, dt_total_and_regional_market_size * temp_datatype, int size);
void write_dt_total_and_regional_market_size_dynamic_array(FILE *file, dt_total_and_regional_market_size_array * temp_datatype);
void init_dt_value_lattice(/*@out@*/ dt_value_lattice * temp);
void init_dt_value_lattice_static_array(/*@out@*/ dt_value_lattice * array, int size);
int read_dt_value_lattice(char * buffer, int buffer_size, int * j, dt_value_lattice * temp_datatype);
int read_dt_value_lattice_dynamic_array(char * buffer, int buffer_size, int * j, dt_value_lattice_array * temp_datatype_array);
int read_dt_value_lattice_static_array(char * buffer, int buffer_size, int * j, dt_value_lattice * temp_datatype_array, int size);
void write_dt_value_lattice(FILE *file, dt_value_lattice * temp_datatype);
void write_dt_value_lattice_static_array(FILE *file, dt_value_lattice * temp_datatype, int size);
void write_dt_value_lattice_dynamic_array(FILE *file, dt_value_lattice_array * temp_datatype);
void init_dt_value_lattice_years(/*@out@*/ dt_value_lattice_years * temp);
void init_dt_value_lattice_years_static_array(/*@out@*/ dt_value_lattice_years * array, int size);
int read_dt_value_lattice_years(char * buffer, int buffer_size, int * j, dt_value_lattice_years * temp_datatype);
int read_dt_value_lattice_years_dynamic_array(char * buffer, int buffer_size, int * j, dt_value_lattice_years_array * temp_datatype_array);
int read_dt_value_lattice_years_static_array(char * buffer, int buffer_size, int * j, dt_value_lattice_years * temp_datatype_array, int size);
void write_dt_value_lattice_years(FILE *file, dt_value_lattice_years * temp_datatype);
void write_dt_value_lattice_years_static_array(FILE *file, dt_value_lattice_years * temp_datatype, int size);
void write_dt_value_lattice_years_dynamic_array(FILE *file, dt_value_lattice_years_array * temp_datatype);
void init_dt_monthly_estimations(/*@out@*/ dt_monthly_estimations * temp);
void init_dt_monthly_estimations_static_array(/*@out@*/ dt_monthly_estimations * array, int size);
int read_dt_monthly_estimations(char * buffer, int buffer_size, int * j, dt_monthly_estimations * temp_datatype);
int read_dt_monthly_estimations_dynamic_array(char * buffer, int buffer_size, int * j, dt_monthly_estimations_array * temp_datatype_array);
int read_dt_monthly_estimations_static_array(char * buffer, int buffer_size, int * j, dt_monthly_estimations * temp_datatype_array, int size);
void write_dt_monthly_estimations(FILE *file, dt_monthly_estimations * temp_datatype);
void write_dt_monthly_estimations_static_array(FILE *file, dt_monthly_estimations * temp_datatype, int size);
void write_dt_monthly_estimations_dynamic_array(FILE *file, dt_monthly_estimations_array * temp_datatype);

void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[],
					   int partition_method, int flag);
void saveiterationdata(int iteration_number);

void free_consumption_goods_offer(consumption_goods_offer * temp);
void free_consumption_goods_offer_static_array(consumption_goods_offer * array, int size);
void copy_consumption_goods_offer(consumption_goods_offer * from, consumption_goods_offer * to);
void copy_consumption_goods_offer_static_array(consumption_goods_offer * from, consumption_goods_offer * to, int size);
void free_estimators_linear_regression(estimators_linear_regression * temp);
void free_estimators_linear_regression_static_array(estimators_linear_regression * array, int size);
void copy_estimators_linear_regression(estimators_linear_regression * from, estimators_linear_regression * to);
void copy_estimators_linear_regression_static_array(estimators_linear_regression * from, estimators_linear_regression * to, int size);
void free_consumption_request(consumption_request * temp);
void free_consumption_request_static_array(consumption_request * array, int size);
void copy_consumption_request(consumption_request * from, consumption_request * to);
void copy_consumption_request_static_array(consumption_request * from, consumption_request * to, int size);
void free_mall_info(mall_info * temp);
void free_mall_info_static_array(mall_info * array, int size);
void copy_mall_info(mall_info * from, mall_info * to);
void copy_mall_info_static_array(mall_info * from, mall_info * to, int size);
void free_mall_quality_price_info(mall_quality_price_info * temp);
void free_mall_quality_price_info_static_array(mall_quality_price_info * array, int size);
void copy_mall_quality_price_info(mall_quality_price_info * from, mall_quality_price_info * to);
void copy_mall_quality_price_info_static_array(mall_quality_price_info * from, mall_quality_price_info * to, int size);
void free_mall_stock(mall_stock * temp);
void free_mall_stock_static_array(mall_stock * array, int size);
void copy_mall_stock(mall_stock * from, mall_stock * to);
void copy_mall_stock_static_array(mall_stock * from, mall_stock * to, int size);
void free_delivery_volume_per_mall(delivery_volume_per_mall * temp);
void free_delivery_volume_per_mall_static_array(delivery_volume_per_mall * array, int size);
void copy_delivery_volume_per_mall(delivery_volume_per_mall * from, delivery_volume_per_mall * to);
void copy_delivery_volume_per_mall_static_array(delivery_volume_per_mall * from, delivery_volume_per_mall * to, int size);
void free_logit_firm_id(logit_firm_id * temp);
void free_logit_firm_id_static_array(logit_firm_id * array, int size);
void copy_logit_firm_id(logit_firm_id * from, logit_firm_id * to);
void copy_logit_firm_id_static_array(logit_firm_id * from, logit_firm_id * to, int size);
void free_sales_in_mall(sales_in_mall * temp);
void free_sales_in_mall_static_array(sales_in_mall * array, int size);
void copy_sales_in_mall(sales_in_mall * from, sales_in_mall * to);
void copy_sales_in_mall_static_array(sales_in_mall * from, sales_in_mall * to, int size);
void free_ordered_quantity(ordered_quantity * temp);
void free_ordered_quantity_static_array(ordered_quantity * array, int size);
void copy_ordered_quantity(ordered_quantity * from, ordered_quantity * to);
void copy_ordered_quantity_static_array(ordered_quantity * from, ordered_quantity * to, int size);
void free_received_quantities(received_quantities * temp);
void free_received_quantities_static_array(received_quantities * array, int size);
void copy_received_quantities(received_quantities * from, received_quantities * to);
void copy_received_quantities_static_array(received_quantities * from, received_quantities * to, int size);
void free_sold_quantities_per_mall(sold_quantities_per_mall * temp);
void free_sold_quantities_per_mall_static_array(sold_quantities_per_mall * array, int size);
void copy_sold_quantities_per_mall(sold_quantities_per_mall * from, sold_quantities_per_mall * to);
void copy_sold_quantities_per_mall_static_array(sold_quantities_per_mall * from, sold_quantities_per_mall * to, int size);
void free_data_type_sales(data_type_sales * temp);
void free_data_type_sales_static_array(data_type_sales * array, int size);
void copy_data_type_sales(data_type_sales * from, data_type_sales * to);
void copy_data_type_sales_static_array(data_type_sales * from, data_type_sales * to, int size);
void free_sales_statistics(sales_statistics * temp);
void free_sales_statistics_static_array(sales_statistics * array, int size);
void copy_sales_statistics(sales_statistics * from, sales_statistics * to);
void copy_sales_statistics_static_array(sales_statistics * from, sales_statistics * to, int size);
void free_adt_technology_vintages(adt_technology_vintages * temp);
void free_adt_technology_vintages_static_array(adt_technology_vintages * array, int size);
void copy_adt_technology_vintages(adt_technology_vintages * from, adt_technology_vintages * to);
void copy_adt_technology_vintages_static_array(adt_technology_vintages * from, adt_technology_vintages * to, int size);
void free_adt_capital_stock_vintages(adt_capital_stock_vintages * temp);
void free_adt_capital_stock_vintages_static_array(adt_capital_stock_vintages * array, int size);
void copy_adt_capital_stock_vintages(adt_capital_stock_vintages * from, adt_capital_stock_vintages * to);
void copy_adt_capital_stock_vintages_static_array(adt_capital_stock_vintages * from, adt_capital_stock_vintages * to, int size);
void free_financing_capital(financing_capital * temp);
void free_financing_capital_static_array(financing_capital * array, int size);
void copy_financing_capital(financing_capital * from, financing_capital * to);
void copy_financing_capital_static_array(financing_capital * from, financing_capital * to, int size);
void free_temporary_sales_statistics(temporary_sales_statistics * temp);
void free_temporary_sales_statistics_static_array(temporary_sales_statistics * array, int size);
void copy_temporary_sales_statistics(temporary_sales_statistics * from, temporary_sales_statistics * to);
void copy_temporary_sales_statistics_static_array(temporary_sales_statistics * from, temporary_sales_statistics * to, int size);
void free_account_item(account_item * temp);
void free_account_item_static_array(account_item * array, int size);
void copy_account_item(account_item * from, account_item * to);
void copy_account_item_static_array(account_item * from, account_item * to, int size);
void free_debt_item(debt_item * temp);
void free_debt_item_static_array(debt_item * array, int size);
void copy_debt_item(debt_item * from, debt_item * to);
void copy_debt_item_static_array(debt_item * from, debt_item * to, int size);
void free_order(order * temp);
void free_order_static_array(order * array, int size);
void copy_order(order * from, order * to);
void copy_order_static_array(order * from, order * to, int size);
void free_index_adt(index_adt * temp);
void free_index_adt_static_array(index_adt * array, int size);
void copy_index_adt(index_adt * from, index_adt * to);
void copy_index_adt_static_array(index_adt * from, index_adt * to, int size);
void free_index_portfolio(index_portfolio * temp);
void free_index_portfolio_static_array(index_portfolio * array, int size);
void copy_index_portfolio(index_portfolio * from, index_portfolio * to);
void copy_index_portfolio_static_array(index_portfolio * from, index_portfolio * to, int size);
void free_Belief(Belief * temp);
void free_Belief_static_array(Belief * array, int size);
void copy_Belief(Belief * from, Belief * to);
void copy_Belief_static_array(Belief * from, Belief * to, int size);
void free_capital_good_request(capital_good_request * temp);
void free_capital_good_request_static_array(capital_good_request * array, int size);
void copy_capital_good_request(capital_good_request * from, capital_good_request * to);
void copy_capital_good_request_static_array(capital_good_request * from, capital_good_request * to, int size);
void free_vintage(vintage * temp);
void free_vintage_static_array(vintage * array, int size);
void copy_vintage(vintage * from, vintage * to);
void copy_vintage_static_array(vintage * from, vintage * to, int size);
void free_adt_sales_per_vintage(adt_sales_per_vintage * temp);
void free_adt_sales_per_vintage_static_array(adt_sales_per_vintage * array, int size);
void copy_adt_sales_per_vintage(adt_sales_per_vintage * from, adt_sales_per_vintage * to);
void copy_adt_sales_per_vintage_static_array(adt_sales_per_vintage * from, adt_sales_per_vintage * to, int size);
void free_adt_list_adaptation_speed(adt_list_adaptation_speed * temp);
void free_adt_list_adaptation_speed_static_array(adt_list_adaptation_speed * array, int size);
void copy_adt_list_adaptation_speed(adt_list_adaptation_speed * from, adt_list_adaptation_speed * to);
void copy_adt_list_adaptation_speed_static_array(adt_list_adaptation_speed * from, adt_list_adaptation_speed * to, int size);
void free_employee(employee * temp);
void free_employee_static_array(employee * array, int size);
void copy_employee(employee * from, employee * to);
void copy_employee_static_array(employee * from, employee * to, int size);
void free_vacancy(vacancy * temp);
void free_vacancy_static_array(vacancy * array, int size);
void copy_vacancy(vacancy * from, vacancy * to);
void copy_vacancy_static_array(vacancy * from, vacancy * to, int size);
void free_job_application(job_application * temp);
void free_job_application_static_array(job_application * array, int size);
void copy_job_application(job_application * from, job_application * to);
void copy_job_application_static_array(job_application * from, job_application * to, int size);
void free_job_offer(job_offer * temp);
void free_job_offer_static_array(job_offer * array, int size);
void copy_job_offer(job_offer * from, job_offer * to);
void copy_job_offer_static_array(job_offer * from, job_offer * to, int size);
void free_logit(logit * temp);
void free_logit_static_array(logit * array, int size);
void copy_logit(logit * from, logit * to);
void copy_logit_static_array(logit * from, logit * to, int size);
void free_adt_skill_distribution(adt_skill_distribution * temp);
void free_adt_skill_distribution_static_array(adt_skill_distribution * array, int size);
void copy_adt_skill_distribution(adt_skill_distribution * from, adt_skill_distribution * to);
void copy_adt_skill_distribution_static_array(adt_skill_distribution * from, adt_skill_distribution * to, int size);
void free_adt_actual_skill_distribution_with_ids(adt_actual_skill_distribution_with_ids * temp);
void free_adt_actual_skill_distribution_with_ids_static_array(adt_actual_skill_distribution_with_ids * array, int size);
void copy_adt_actual_skill_distribution_with_ids(adt_actual_skill_distribution_with_ids * from, adt_actual_skill_distribution_with_ids * to);
void copy_adt_actual_skill_distribution_with_ids_static_array(adt_actual_skill_distribution_with_ids * from, adt_actual_skill_distribution_with_ids * to, int size);
void free_adt_gov_inflows_outflows(adt_gov_inflows_outflows * temp);
void free_adt_gov_inflows_outflows_static_array(adt_gov_inflows_outflows * array, int size);
void copy_adt_gov_inflows_outflows(adt_gov_inflows_outflows * from, adt_gov_inflows_outflows * to);
void copy_adt_gov_inflows_outflows_static_array(adt_gov_inflows_outflows * from, adt_gov_inflows_outflows * to, int size);
void free_household_data(household_data * temp);
void free_household_data_static_array(household_data * array, int size);
void copy_household_data(household_data * from, household_data * to);
void copy_household_data_static_array(household_data * from, household_data * to, int size);
void free_price_quality_pair(price_quality_pair * temp);
void free_price_quality_pair_static_array(price_quality_pair * array, int size);
void copy_price_quality_pair(price_quality_pair * from, price_quality_pair * to);
void copy_price_quality_pair_static_array(price_quality_pair * from, price_quality_pair * to, int size);
void free_firm_data(firm_data * temp);
void free_firm_data_static_array(firm_data * array, int size);
void copy_firm_data(firm_data * from, firm_data * to);
void copy_firm_data_static_array(firm_data * from, firm_data * to, int size);
void free_government_data(government_data * temp);
void free_government_data_static_array(government_data * array, int size);
void copy_government_data(government_data * from, government_data * to);
void copy_government_data_static_array(government_data * from, government_data * to, int size);
void free_region_data_item(region_data_item * temp);
void free_region_data_item_static_array(region_data_item * array, int size);
void copy_region_data_item(region_data_item * from, region_data_item * to);
void copy_region_data_item_static_array(region_data_item * from, region_data_item * to, int size);
void free_history_item(history_item * temp);
void free_history_item_static_array(history_item * array, int size);
void copy_history_item(history_item * from, history_item * to);
void copy_history_item_static_array(history_item * from, history_item * to, int size);
void free_firm_stocks_adt(firm_stocks_adt * temp);
void free_firm_stocks_adt_static_array(firm_stocks_adt * array, int size);
void copy_firm_stocks_adt(firm_stocks_adt * from, firm_stocks_adt * to);
void copy_firm_stocks_adt_static_array(firm_stocks_adt * from, firm_stocks_adt * to, int size);
void free_firm_outflows_adt(firm_outflows_adt * temp);
void free_firm_outflows_adt_static_array(firm_outflows_adt * array, int size);
void copy_firm_outflows_adt(firm_outflows_adt * from, firm_outflows_adt * to);
void copy_firm_outflows_adt_static_array(firm_outflows_adt * from, firm_outflows_adt * to, int size);
void free_firm_inflows_adt(firm_inflows_adt * temp);
void free_firm_inflows_adt_static_array(firm_inflows_adt * array, int size);
void copy_firm_inflows_adt(firm_inflows_adt * from, firm_inflows_adt * to);
void copy_firm_inflows_adt_static_array(firm_inflows_adt * from, firm_inflows_adt * to, int size);
void free_household_stocks_adt(household_stocks_adt * temp);
void free_household_stocks_adt_static_array(household_stocks_adt * array, int size);
void copy_household_stocks_adt(household_stocks_adt * from, household_stocks_adt * to);
void copy_household_stocks_adt_static_array(household_stocks_adt * from, household_stocks_adt * to, int size);
void free_household_outflows_adt(household_outflows_adt * temp);
void free_household_outflows_adt_static_array(household_outflows_adt * array, int size);
void copy_household_outflows_adt(household_outflows_adt * from, household_outflows_adt * to);
void copy_household_outflows_adt_static_array(household_outflows_adt * from, household_outflows_adt * to, int size);
void free_household_inflows_adt(household_inflows_adt * temp);
void free_household_inflows_adt_static_array(household_inflows_adt * array, int size);
void copy_household_inflows_adt(household_inflows_adt * from, household_inflows_adt * to);
void copy_household_inflows_adt_static_array(household_inflows_adt * from, household_inflows_adt * to, int size);
void free_igfirm_stocks_adt(igfirm_stocks_adt * temp);
void free_igfirm_stocks_adt_static_array(igfirm_stocks_adt * array, int size);
void copy_igfirm_stocks_adt(igfirm_stocks_adt * from, igfirm_stocks_adt * to);
void copy_igfirm_stocks_adt_static_array(igfirm_stocks_adt * from, igfirm_stocks_adt * to, int size);
void free_igfirm_outflows_adt(igfirm_outflows_adt * temp);
void free_igfirm_outflows_adt_static_array(igfirm_outflows_adt * array, int size);
void copy_igfirm_outflows_adt(igfirm_outflows_adt * from, igfirm_outflows_adt * to);
void copy_igfirm_outflows_adt_static_array(igfirm_outflows_adt * from, igfirm_outflows_adt * to, int size);
void free_igfirm_inflows_adt(igfirm_inflows_adt * temp);
void free_igfirm_inflows_adt_static_array(igfirm_inflows_adt * array, int size);
void copy_igfirm_inflows_adt(igfirm_inflows_adt * from, igfirm_inflows_adt * to);
void copy_igfirm_inflows_adt_static_array(igfirm_inflows_adt * from, igfirm_inflows_adt * to, int size);
void free_bank_stocks_adt(bank_stocks_adt * temp);
void free_bank_stocks_adt_static_array(bank_stocks_adt * array, int size);
void copy_bank_stocks_adt(bank_stocks_adt * from, bank_stocks_adt * to);
void copy_bank_stocks_adt_static_array(bank_stocks_adt * from, bank_stocks_adt * to, int size);
void free_bank_outflows_adt(bank_outflows_adt * temp);
void free_bank_outflows_adt_static_array(bank_outflows_adt * array, int size);
void copy_bank_outflows_adt(bank_outflows_adt * from, bank_outflows_adt * to);
void copy_bank_outflows_adt_static_array(bank_outflows_adt * from, bank_outflows_adt * to, int size);
void free_bank_inflows_adt(bank_inflows_adt * temp);
void free_bank_inflows_adt_static_array(bank_inflows_adt * array, int size);
void copy_bank_inflows_adt(bank_inflows_adt * from, bank_inflows_adt * to);
void copy_bank_inflows_adt_static_array(bank_inflows_adt * from, bank_inflows_adt * to, int size);
void free_gov_stocks_adt(gov_stocks_adt * temp);
void free_gov_stocks_adt_static_array(gov_stocks_adt * array, int size);
void copy_gov_stocks_adt(gov_stocks_adt * from, gov_stocks_adt * to);
void copy_gov_stocks_adt_static_array(gov_stocks_adt * from, gov_stocks_adt * to, int size);
void free_gov_outflows_adt(gov_outflows_adt * temp);
void free_gov_outflows_adt_static_array(gov_outflows_adt * array, int size);
void copy_gov_outflows_adt(gov_outflows_adt * from, gov_outflows_adt * to);
void copy_gov_outflows_adt_static_array(gov_outflows_adt * from, gov_outflows_adt * to, int size);
void free_gov_inflows_adt(gov_inflows_adt * temp);
void free_gov_inflows_adt_static_array(gov_inflows_adt * array, int size);
void copy_gov_inflows_adt(gov_inflows_adt * from, gov_inflows_adt * to);
void copy_gov_inflows_adt_static_array(gov_inflows_adt * from, gov_inflows_adt * to, int size);
void free_ecb_stocks_adt(ecb_stocks_adt * temp);
void free_ecb_stocks_adt_static_array(ecb_stocks_adt * array, int size);
void copy_ecb_stocks_adt(ecb_stocks_adt * from, ecb_stocks_adt * to);
void copy_ecb_stocks_adt_static_array(ecb_stocks_adt * from, ecb_stocks_adt * to, int size);
void free_ecb_outflows_adt(ecb_outflows_adt * temp);
void free_ecb_outflows_adt_static_array(ecb_outflows_adt * array, int size);
void copy_ecb_outflows_adt(ecb_outflows_adt * from, ecb_outflows_adt * to);
void copy_ecb_outflows_adt_static_array(ecb_outflows_adt * from, ecb_outflows_adt * to, int size);
void free_ecb_inflows_adt(ecb_inflows_adt * temp);
void free_ecb_inflows_adt_static_array(ecb_inflows_adt * array, int size);
void copy_ecb_inflows_adt(ecb_inflows_adt * from, ecb_inflows_adt * to);
void copy_ecb_inflows_adt_static_array(ecb_inflows_adt * from, ecb_inflows_adt * to, int size);
void free_firm_balance_sheet_adt(firm_balance_sheet_adt * temp);
void free_firm_balance_sheet_adt_static_array(firm_balance_sheet_adt * array, int size);
void copy_firm_balance_sheet_adt(firm_balance_sheet_adt * from, firm_balance_sheet_adt * to);
void copy_firm_balance_sheet_adt_static_array(firm_balance_sheet_adt * from, firm_balance_sheet_adt * to, int size);
void free_household_balance_sheet_adt(household_balance_sheet_adt * temp);
void free_household_balance_sheet_adt_static_array(household_balance_sheet_adt * array, int size);
void copy_household_balance_sheet_adt(household_balance_sheet_adt * from, household_balance_sheet_adt * to);
void copy_household_balance_sheet_adt_static_array(household_balance_sheet_adt * from, household_balance_sheet_adt * to, int size);
void free_igfirm_balance_sheet_adt(igfirm_balance_sheet_adt * temp);
void free_igfirm_balance_sheet_adt_static_array(igfirm_balance_sheet_adt * array, int size);
void copy_igfirm_balance_sheet_adt(igfirm_balance_sheet_adt * from, igfirm_balance_sheet_adt * to);
void copy_igfirm_balance_sheet_adt_static_array(igfirm_balance_sheet_adt * from, igfirm_balance_sheet_adt * to, int size);
void free_bank_balance_sheet_adt(bank_balance_sheet_adt * temp);
void free_bank_balance_sheet_adt_static_array(bank_balance_sheet_adt * array, int size);
void copy_bank_balance_sheet_adt(bank_balance_sheet_adt * from, bank_balance_sheet_adt * to);
void copy_bank_balance_sheet_adt_static_array(bank_balance_sheet_adt * from, bank_balance_sheet_adt * to, int size);
void free_gov_balance_sheet_adt(gov_balance_sheet_adt * temp);
void free_gov_balance_sheet_adt_static_array(gov_balance_sheet_adt * array, int size);
void copy_gov_balance_sheet_adt(gov_balance_sheet_adt * from, gov_balance_sheet_adt * to);
void copy_gov_balance_sheet_adt_static_array(gov_balance_sheet_adt * from, gov_balance_sheet_adt * to, int size);
void free_ecb_balance_sheet_adt(ecb_balance_sheet_adt * temp);
void free_ecb_balance_sheet_adt_static_array(ecb_balance_sheet_adt * array, int size);
void copy_ecb_balance_sheet_adt(ecb_balance_sheet_adt * from, ecb_balance_sheet_adt * to);
void copy_ecb_balance_sheet_adt_static_array(ecb_balance_sheet_adt * from, ecb_balance_sheet_adt * to, int size);
void free_adt_subsidies_per_government(adt_subsidies_per_government * temp);
void free_adt_subsidies_per_government_static_array(adt_subsidies_per_government * array, int size);
void copy_adt_subsidies_per_government(adt_subsidies_per_government * from, adt_subsidies_per_government * to);
void copy_adt_subsidies_per_government_static_array(adt_subsidies_per_government * from, adt_subsidies_per_government * to, int size);
void free_estimated_values_adt(estimated_values_adt * temp);
void free_estimated_values_adt_static_array(estimated_values_adt * array, int size);
void copy_estimated_values_adt(estimated_values_adt * from, estimated_values_adt * to);
void copy_estimated_values_adt_static_array(estimated_values_adt * from, estimated_values_adt * to, int size);
void free_dt_market_research_price(dt_market_research_price * temp);
void free_dt_market_research_price_static_array(dt_market_research_price * array, int size);
void copy_dt_market_research_price(dt_market_research_price * from, dt_market_research_price * to);
void copy_dt_market_research_price_static_array(dt_market_research_price * from, dt_market_research_price * to, int size);
void free_dt_market_research_qualities(dt_market_research_qualities * temp);
void free_dt_market_research_qualities_static_array(dt_market_research_qualities * array, int size);
void copy_dt_market_research_qualities(dt_market_research_qualities * from, dt_market_research_qualities * to);
void copy_dt_market_research_qualities_static_array(dt_market_research_qualities * from, dt_market_research_qualities * to, int size);
void free_dt_best_price_strategies(dt_best_price_strategies * temp);
void free_dt_best_price_strategies_static_array(dt_best_price_strategies * array, int size);
void copy_dt_best_price_strategies(dt_best_price_strategies * from, dt_best_price_strategies * to);
void copy_dt_best_price_strategies_static_array(dt_best_price_strategies * from, dt_best_price_strategies * to, int size);
void free_dt_price_range(dt_price_range * temp);
void free_dt_price_range_static_array(dt_price_range * array, int size);
void copy_dt_price_range(dt_price_range * from, dt_price_range * to);
void copy_dt_price_range_static_array(dt_price_range * from, dt_price_range * to, int size);
void free_dt_prospective_variables(dt_prospective_variables * temp);
void free_dt_prospective_variables_static_array(dt_prospective_variables * array, int size);
void copy_dt_prospective_variables(dt_prospective_variables * from, dt_prospective_variables * to);
void copy_dt_prospective_variables_static_array(dt_prospective_variables * from, dt_prospective_variables * to, int size);
void free_dt_variables_changed(dt_variables_changed * temp);
void free_dt_variables_changed_static_array(dt_variables_changed * array, int size);
void copy_dt_variables_changed(dt_variables_changed * from, dt_variables_changed * to);
void copy_dt_variables_changed_static_array(dt_variables_changed * from, dt_variables_changed * to, int size);
void free_dt_innovation_choice(dt_innovation_choice * temp);
void free_dt_innovation_choice_static_array(dt_innovation_choice * array, int size);
void copy_dt_innovation_choice(dt_innovation_choice * from, dt_innovation_choice * to);
void copy_dt_innovation_choice_static_array(dt_innovation_choice * from, dt_innovation_choice * to, int size);
void free_dt_demand_function(dt_demand_function * temp);
void free_dt_demand_function_static_array(dt_demand_function * array, int size);
void copy_dt_demand_function(dt_demand_function * from, dt_demand_function * to);
void copy_dt_demand_function_static_array(dt_demand_function * from, dt_demand_function * to, int size);
void free_dt_price_quantity_touple(dt_price_quantity_touple * temp);
void free_dt_price_quantity_touple_static_array(dt_price_quantity_touple * array, int size);
void copy_dt_price_quantity_touple(dt_price_quantity_touple * from, dt_price_quantity_touple * to);
void copy_dt_price_quantity_touple_static_array(dt_price_quantity_touple * from, dt_price_quantity_touple * to, int size);
void free_dt_market_size(dt_market_size * temp);
void free_dt_market_size_static_array(dt_market_size * array, int size);
void copy_dt_market_size(dt_market_size * from, dt_market_size * to);
void copy_dt_market_size_static_array(dt_market_size * from, dt_market_size * to, int size);
void free_dt_total_and_regional_market_size(dt_total_and_regional_market_size * temp);
void free_dt_total_and_regional_market_size_static_array(dt_total_and_regional_market_size * array, int size);
void copy_dt_total_and_regional_market_size(dt_total_and_regional_market_size * from, dt_total_and_regional_market_size * to);
void copy_dt_total_and_regional_market_size_static_array(dt_total_and_regional_market_size * from, dt_total_and_regional_market_size * to, int size);
void free_dt_value_lattice(dt_value_lattice * temp);
void free_dt_value_lattice_static_array(dt_value_lattice * array, int size);
void copy_dt_value_lattice(dt_value_lattice * from, dt_value_lattice * to);
void copy_dt_value_lattice_static_array(dt_value_lattice * from, dt_value_lattice * to, int size);
void free_dt_value_lattice_years(dt_value_lattice_years * temp);
void free_dt_value_lattice_years_static_array(dt_value_lattice_years * array, int size);
void copy_dt_value_lattice_years(dt_value_lattice_years * from, dt_value_lattice_years * to);
void copy_dt_value_lattice_years_static_array(dt_value_lattice_years * from, dt_value_lattice_years * to, int size);
void free_dt_monthly_estimations(dt_monthly_estimations * temp);
void free_dt_monthly_estimations_static_array(dt_monthly_estimations * array, int size);
void copy_dt_monthly_estimations(dt_monthly_estimations * from, dt_monthly_estimations * to);
void copy_dt_monthly_estimations_static_array(dt_monthly_estimations * from, dt_monthly_estimations * to, int size);

xmachine_memory_Firm_state * init_Firm_state();
xmachine_memory_Firm * init_Firm_agent();
void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state);
void transition_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * from_state, xmachine_memory_Firm_state * to_state);
void add_Firm_agent_internal(xmachine_memory_Firm * agent, xmachine_memory_Firm_state * state);
void add_Firm_agent(int id, int region_id, int gov_id, int day_of_month_to_act, int last_day_of_month_to_act, double payment_account, double payment_account_balance_sheet, int bank_id, int partition_id, double cpi, double mean_wage, double total_mean_wage, double mean_wage_r_and_d, double needed_capital_stock, double stock, double critical_stock, double actual_cap_price, double mean_specific_skills, double planned_production_quantity, double production_quantity, double planned_output, double output, double unit_costs, double total_supply, double production_costs, double total_buffer, double revenue_per_day, estimators_linear_regression_array * linear_regression_estimators, double technological_frontier, adt_technology_vintages_array * technology_vintages, int vintage_selected, int investment_subsidy_type, double initial_market_size, double initial_technology, double utilization_capacity, double used_capital_units, double cum_revenue, sales_statistics_array * malls_sales_statistics, double quality, double price, double price_last_month, double actual_mark_up, double demand_capital_stock, double effective_investments, double effective_capital_stock, double planned_production_costs, double labour_costs_production, double labour_costs_innovation, double intermediate_quality_level_developing, double adaption_production_volume_due_to_insufficient_finances, sold_quantities_per_mall_array * sold_quantities, double total_sold_quantity, double cum_total_sold_quantity, double sold_quantity_in_calendar_month, delivery_volume_per_mall_array * delivery_volume, delivery_volume_per_mall_array * planned_delivery_volume, mall_info_array * current_mall_stocks, double_array * last_planned_production_quantities, double total_external_financing_obtained, double capital_costs, int employees_needed_production, int no_employees_production, double planned_innovation_expenditures, double planned_expenditures_production_innovation, double labour_costs, double labour_costs_per_unit, adt_capital_stock_vintages_array * capital_stock_vintages, int vintage_choice_taken, financing_capital_array * capital_financing, double financial_resources_for_production, double total_units_local_inventory, double calc_capital_costs, double calc_production_costs, double firm_productivity, double total_productivity_capital_stock, double firm_productivity_last_year, double firm_productivity_progress, double sold_quantity_in_last_calendar_month, double_array * last_sold_quantities, double_array * last_revenues, int_array * set_of_lenders, int_array * potential_lenders, int number_of_banks_asked, double received_interest_daily, double received_interest_in_calendar_month, int flag_illiquidity_correction, double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double tax_payment_in_calendar_month, double net_earnings, double_array * earnings_history, double previous_net_earnings, double total_interest_payment, double total_interest_payment_in_calendar_month, double total_debt_installment_payment, double total_debt_installment_payment_in_calendar_month, double total_dividend_payment, double total_dividend_payment_in_calendar_month, int flag_full_dividend, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, debt_item_array * loans, double total_debt, double target_debt, double total_debt_balance_sheet, double total_value_local_inventory, double total_value_local_inventory_balance_sheet, double total_units_capital_stock, double total_value_capital_stock, double total_value_capital_stock_balance_sheet, double total_capital_depreciation_value, double total_capital_depreciation_units, double total_assets, double equity, double equity_balance_sheet, double production_liquidity_needs, double financial_liquidity_needs, double total_financial_needs, double external_financial_needs, double earnings_per_share, double retained_earnings, double total_payments, int previous_shares_outstanding, int minsky_state, int minsky_state_1, int minsky_state_2, int minsky_state_3, int minsky_state_4, int minsky_state_5, int minsky_state_20, int minsky_state_21, int minsky_state_22, int minsky_state_23, int minsky_state_30, int minsky_state_31, int minsky_state_32, int minsky_state_33, int minsky_state_40, int minsky_state_41, int minsky_state_42, int minsky_state_43, int age_at_bankruptcy, double debt_at_bankruptcy, double equity_at_bankruptcy, int no_employees_at_bankruptcy, double equity_asset_ratio, double profit_asset_ratio, double sales_asset_ratio, double investment_asset_ratio, double total_income, double total_liabilities, double total_expenses, int current_shares_outstanding, employee_array * employees, employee_array * r_and_d_employees, double wage_offer, double technology, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, int no_employees_subsidized, double fraction_employees_subsidized, int vacancies, int no_redundancies, int no_applications_round_1, int no_applications_round_2, int no_redundancies_r_and_d_employees, int vacancies_r_and_d_employees, int posted_vacancies, int posted_vacancies_r_and_d_employees, double average_g_skill, double average_adaptation_speed_specific_skills, adt_list_adaptation_speed_array * list_adaptation_speed_per_skill_group, double average_s_skill_of_1, double average_s_skill_of_2, double average_s_skill_of_3, double average_s_skill_of_4, double average_s_skill_of_5, double wage_offer_for_skill_1, double wage_offer_for_skill_2, double wage_offer_for_skill_3, double wage_offer_for_skill_4, double wage_offer_for_skill_5, double wage_offer_for_r_and_d_employees, double base_wage_offer_r_and_d, int employees_needed, firm_balance_sheet_adt firm_balance_sheet_calendar, firm_stocks_adt firm_stocks_calendar, firm_outflows_adt firm_outflows_calendar, firm_inflows_adt firm_inflows_calendar, int age, double transfer_payment, double subsidy_pct, int active, int inactive, int zero_output, int bankruptcy_idle_counter, int bankruptcy_state, int bankruptcy_insolvency_state, int bankruptcy_illiquidity_state, int financial_crisis_state, double vacancy_filling_rate, double average_s_skill_from_eurostat, double average_technology_from_eurostat, double average_wage_offer_from_eurostat, double average_output_from_eurostat, price_quality_pair_array * quality_price_competitors, double subsidy_payment, double current_price_index, double current_quality_index, double minimum_wage, int no_competitors, int indicator_earnings, int indicator_capital_costs, double agg_vacancy_filling_rate, int market_research_sample_size, int product_innovation, int regional_analysis, int day_of_year_market_research, int day_of_month_price_was_set, int actual_sample_size, dt_total_and_regional_market_size_array * last_market_sizes, dt_price_range price_range_pricing, double estimated_variance_market_share, price_quality_pair estimated_coefficients, dt_price_range price_range_innovation, int price_quality_counts[], price_quality_pair price_quality_inno[], int new_product_released, dt_prospective_variables_array * prospective_variables, double price_at_questionnaire, double price_index_at_questionnaire, dt_best_price_strategies_array * best_pricing_strategies, double intermediate_quality, int no_employees_product_innovation_fundable, double r_and_d_probability_for_incremental_success, int day_of_year_price_setting, int market_research_active, int innovation_successful, double actual_market_share, double market_size, double market_size_reg1, double market_size_reg2, double estimated_market_size, estimators_linear_regression_array * linear_regression_market_size, int counter_month_since_last_price_setting, dt_demand_function demand_function_pricing, dt_demand_function_array * demand_functions_product_innovation, int market_research_delayed, dt_market_research_price_array * market_research_data_pricing, dt_market_research_qualities_array * market_research_data_product_innovation, double expected_earnings_per_month, double_array * expected_price_choices, double no_considered_qualities, double last_interest_rate_for_loans, double cum_earnings_last_r_d_project, double cum_r_d_investments, double r_d_investments_last_project, int total_person_months, int cum_person_months, double actual_r_and_d_success_probability, double last_quality, double quality_change, double expected_sold_quantity_per_month, double estimated_market_share, double estimated_yearly_earnings, dt_monthly_estimations expected_earnings_and_costs_over_year[], double expected_output_in_current_month, double expected_profit_in_current_month, double expected_labor_costs_in_current_month, double expected_capital_costs_in_current_month, double expected_interests_in_current_month, double expected_output_in_previous_month, double expected_actual_sold_quantity_in_previous_month, double expected_actual_sold_quantity_in_current_month, double expected_labor_costs_in_previous_month, double expected_capital_costs_in_previous_month, double expected_interests_in_previous_month, double expected_profit_in_previous_month, double expected_wage_in_current_month, double expected_wage_in_previous_month, double expected_mean_specific_skills_in_current_month, double expected_mean_specific_skills_in_previous_month, double expected_average_productivity_in_current_month, double expected_investment_nominal_in_current_month, double expected_investment_nominal_in_previous_month, double expected_average_productivity_in_previous_month, double earnings_while_last_pricing_period, double sum_earnings_since_price_change, dt_variables_changed_array * variables_last_year, int innovation_month_counter, int periods_output_zero_counter, dt_variables_changed variables_change, double r_and_d_investments_per_month, int innovation_flag, int innovation_employees_needed, int no_employees_innovation, int employees_needed_innovation, int optimal_employees_needed_innovation, int total_no_periods_for_product_development, double ratio_project_value_established_product, int vintage_choice_already_taken, double change_due_to_last_innovation, int remaining_periods_to_complete_product_development, double planned_quality, double product_development_completed, double price_just_set_flag, dt_value_lattice_years_array * value_lattice, double combined_variance_demand_function);
void unittest_init_Firm_agent();
void unittest_free_Firm_agent();
xmachine_memory_Household_state * init_Household_state();
xmachine_memory_Household * init_Household_agent();
void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state);
void transition_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * from_state, xmachine_memory_Household_state * to_state);
void add_Household_agent_internal(xmachine_memory_Household * agent, xmachine_memory_Household_state * state);
void add_Household_agent(int id, int region_id, int_array * neighboring_region_ids, int gov_id, int day_of_month_to_act, double payment_account, int bank_id, int partition_id, int new_agent, int migration_status, double consumption_budget, double consumption_budget_in_month, int week_of_month, double weekly_budget, int rationed, int mall_completely_sold_out, ordered_quantity order_quantity[], received_quantities received_quantity[], int day_of_week_to_act, int day_of_month_receive_income, double current_productivity_employer, double current_mean_specific_skills_employer, double tax_payment, double cum_total_dividends, double tax_rate_hh_capital, double tax_rate_hh_labour, double price_index, double price_index_base_period, double commuting_costs_price_level_weight, double expenditures, double received_dividend, double received_dividend_in_calendar_month, double received_interest_daily, double received_interest_in_calendar_month, int flag_consumption_shifting, double excess_weekly_budget, double wealth_income_ratio_actual, double wealth_income_ratio_target, double last_weekly_budget, double risk_free_rate, double wealth, Belief beliefs, index_portfolio assetsowned, double logit_beta, double wage, double wage_reservation, int general_skill, adt_list_adaptation_speed_array * list_adaptation_speed_per_general_skill_group, int on_the_job_search, int search_today, double last_labour_income, double specific_skill, int employee_firm_id, int hh_applications_per_day, int just_employed, int just_unemployed, int start_unemployed, int start_employed, int unemployed_duration, int enter_matching, int employer_region_id, int employer_igfirm, int day_of_month_receive_benefit, double unemployment_payment, double region_wide_mean_wage, double basic_security_benefits, double_array * last_net_income, double mean_net_income, household_balance_sheet_adt household_balance_sheet_calendar, household_stocks_adt household_stocks_calendar, household_outflows_adt household_outflows_calendar, household_inflows_adt household_inflows_calendar, double unemployment_benefit_pct, double minimum_wage, double transfer_payment, double subsidy_pct, double monthly_interest_income, double total_income, double total_expenses, double total_assets, double total_liabilities, double monthly_consumption_expenditure, double monthly_bond_interest_income, double subsidy_payment, double region_mean_wage, int human_capital_policy_flag, double questionnaire_attending_propability, int willingness_to_attend, int interviewer_id, int random_no_test, int questionnaire[], consumption_goods_offer_array * current_price_quality_list);
void unittest_init_Household_agent();
void unittest_free_Household_agent();
xmachine_memory_Mall_state * init_Mall_state();
xmachine_memory_Mall * init_Mall_agent();
void free_Mall_agent(xmachine_memory_Mall_holder * tmp, xmachine_memory_Mall_state * state);
void transition_Mall_agent(xmachine_memory_Mall_holder * tmp, xmachine_memory_Mall_state * from_state, xmachine_memory_Mall_state * to_state);
void add_Mall_agent_internal(xmachine_memory_Mall * agent, xmachine_memory_Mall_state * state);
void add_Mall_agent(int id, int region_id, int gov_id, int partition_id, mall_stock_array * current_stock, sales_in_mall_array * firm_revenues, double total_supply, double sales_per_month, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[]);
void unittest_init_Mall_agent();
void unittest_free_Mall_agent();
xmachine_memory_IGFirm_state * init_IGFirm_state();
xmachine_memory_IGFirm * init_IGFirm_agent();
void free_IGFirm_agent(xmachine_memory_IGFirm_holder * tmp, xmachine_memory_IGFirm_state * state);
void transition_IGFirm_agent(xmachine_memory_IGFirm_holder * tmp, xmachine_memory_IGFirm_state * from_state, xmachine_memory_IGFirm_state * to_state);
void add_IGFirm_agent_internal(xmachine_memory_IGFirm * agent, xmachine_memory_IGFirm_state * state);
void add_IGFirm_agent(int id, int region_id, int gov_id, int bank_id, int day_of_month_to_act, int last_day_of_month_to_act, double payment_account, double payment_account_balance_sheet, int partition_id, double received_interest_daily, double received_interest_in_calendar_month, double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double tax_payment_in_calendar_month, double net_earnings, double previous_net_earnings, double total_dividend_payment, double total_dividend_payment_in_calendar_month, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, double total_debt, double total_debt_balance_sheet, double total_assets, double equity, double equity_balance_sheet, double earnings_per_share, double total_payments, int previous_shares_outstanding, double total_income, double total_liabilities, double total_expenses, double calc_production_costs, double productivity, double capital_good_price, vintage_array * vintages, adt_sales_per_vintage_array * sales_per_vintage, double mean_productivity_of_sales, double ratio_sold_productivity_best_practice, double igfirm_endogenous_innovation_probability, double revenue_per_day, double net_profit, int current_shares_outstanding, double energy_price_markup, double energy_costs_per_day, double earnings_per_day, double cum_energy_costs, double_array * last_net_profits, double mean_sales_last_months, double_array * last_sales, double dividend_payment, int duration_until_next_innovation, double unit_costs, double sales, double capital_good_demand, double capital_good_demand_last_month, double sales_last_month, double cum_revenue, double cum_revenue_last_month, int_array * innovation_sheme_low_progress, int_array * innovation_sheme_medium_progress, int_array * innovation_sheme_high_progress, double mean_general_skills, double mean_adaptation_speed, adt_list_adaptation_speed_array * list_adaptation_speed, double productivity_progress_in_economy, double economy_wide_capital_stock, double dividend_buffer, double dividend_target, igfirm_balance_sheet_adt igfirm_balance_sheet_calendar, igfirm_stocks_adt igfirm_stocks_calendar, igfirm_outflows_adt igfirm_outflows_calendar, igfirm_inflows_adt igfirm_inflows_calendar, int age, double transfer_payment, double subsidy_pct, int active, int bankruptcy_idle_counter, int bankruptcy_state, int bankruptcy_insolvency_state, int bankruptcy_illiquidity_state, int financial_crisis_state, double economy_wide_general_skills_in_firms, double economy_wide_specific_skills_in_firms, double subsidy_payment, double wage_offer);
void unittest_init_IGFirm_agent();
void unittest_free_IGFirm_agent();
xmachine_memory_Eurostat_state * init_Eurostat_state();
xmachine_memory_Eurostat * init_Eurostat_agent();
void free_Eurostat_agent(xmachine_memory_Eurostat_holder * tmp, xmachine_memory_Eurostat_state * state);
void transition_Eurostat_agent(xmachine_memory_Eurostat_holder * tmp, xmachine_memory_Eurostat_state * from_state, xmachine_memory_Eurostat_state * to_state);
void add_Eurostat_agent_internal(xmachine_memory_Eurostat * agent, xmachine_memory_Eurostat_state * state);
void add_Eurostat_agent(int id, int region_id, int partition_id, int switch_datastorage, int num_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, double average_unit_labor_costs_reg_1, double average_unit_labor_costs_reg_2, int unemployed, double unemployment_rate, double employment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, int unemployed_reg1, int unemployed_reg2, double unemployment_rate_reg1, double unemployment_rate_reg2, double v_u_ratio_reg1, double v_u_ratio_reg2, double average_wage, double average_wage_reservation, double average_wage_reservation_region_1, double average_wage_reservation_region_2, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double sd_wage, double sd_income, double sd_wealth, double sd_specific_skills, double sd_wage_reg_1, double sd_income_reg_1, double sd_wealth_reg_1, double sd_specific_skills_reg_1, double sd_wage_reg_2, double sd_income_reg_2, double sd_wealth_reg_2, double sd_specific_skills_reg_2, double total_output_reg_2, double total_output_reg_1, double per_capita_output_reg_2, double per_capita_output_reg_1, double mean_price_reg_1, double mean_price_reg_2, double mean_technology_reg_1, double mean_technology_reg_2, double exports_reg1, double exports_reg2, double imports_reg1, double trade_balance_reg1, double trade_balance_reg2, double imports_reg2, double export_quota_reg1, double export_quota_reg2, double import_quota_reg1, double import_quota_reg2, double trade_balance_quota_reg1, double trade_balance_quota_reg2, double mean_wage_reg_1, double mean_wage_reg_2, double mean_wage_offer_reg_1, double mean_wage_offer_reg_2, double mean_s_skills_reg_1, double mean_s_skills_reg_2, double mean_mark_up_reg_1, double mean_mark_up_reg_2, double relative_price, double relative_reservation_wage, double relative_mark_up, double relative_wage, double relative_wage_offer, double relative_technology, double relative_s_skills, double relative_output, double government_consumption, double gini_wage, double gini_income, double gini_wealth, double gini_specific_skills, double gini_wage_reg_1, double gini_income_reg_1, double gini_wealth_reg_1, double gini_specific_skills_reg_1, double gini_wage_reg_2, double gini_income_reg_2, double gini_wealth_reg_2, double gini_specific_skills_reg_2, double labor_income_reg_1, double labor_income_reg_2, double dividend_income_reg_1, double dividend_income_reg_2, double interest_income_reg_1, double interest_income_reg_2, double financial_market_net_revenue_reg_1, double financial_market_net_revenue_reg_2, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double total_consumption_budget, int no_firms, int no_active_firms, int no_vacancies, int no_posted_vacancies, int no_employees, int no_employees_production, int no_employees_r_and_d, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, price_quality_pair_array * price_quality_combination, double firm_average_wage, double firm_average_production_wage, double firm_average_r_and_d_wage, double firm_average_wage_skill_1, double firm_average_wage_skill_2, double firm_average_wage_skill_3, double firm_average_wage_skill_4, double firm_average_wage_skill_5, double firm_average_g_skill, double firm_average_s_skill, double firm_average_s_skill_1, double firm_average_s_skill_2, double firm_average_s_skill_3, double firm_average_s_skill_4, double firm_average_s_skill_5, double firm_average_quality, double firm_average_price, firm_data_array * region_firm_data, household_data_array * region_household_data, government_data_array * region_government_data, double total_earnings, double total_debt, double total_assets, double total_equity, double average_debt_earnings_ratio, double average_debt_equity_ratio, double labour_share_ratio, double cpi, double hpi, adt_subsidies_per_government_array * subsidies_per_government, adt_subsidies_per_government_array * subsidies_balanced, double gdp, double monthly_investment_value, double monthly_sold_quantity, double herfindahl_index, double monthly_output, double monthly_revenue, double monthly_planned_output, double price_index, history_item history_monthly[], history_item history_quarterly[], history_item monthly_growth_rates, history_item quarterly_growth_rates, history_item annual_growth_rates_monthly, history_item annual_growth_rates_quarterly, int no_firm_births, int no_firm_deaths, int firm_age_distribution[], int firm_age_distribution_multiperiod[], int firm_age_distribution_1_period_lag[], int firm_age_distribution_2_period_lag[], double firm_birth_rate, double firm_death_rate, double survival_rate[], double survival_rate_multiperiod_1[], double survival_rate_multiperiod_2[], double survival_rate_multiperiod[], int max_firm_creation, int recession_started, int recession_duration, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[], double region_export_volume[], double region_import_volume[], double region_export_value[], double region_import_value[], double region_import_previous_value[], double firm_average_productivity_progress, double firm_average_productivity, double investment_gdp_ratio, double total_capital_stock_units, double total_value_mall_inventories, double total_dividends, double base_wage_offer, int just_employed, int just_unemployed, int start_employed, int start_unemployed, int enter_matching, int unemployed_duration, int_array * all_region_ids, int_array * all_gov_ids, double job_seperation_rate, double job_finding_rate, double v_u_ratio, double matching_rate, double hh_payment_account, double mean_net_income);
void unittest_init_Eurostat_agent();
void unittest_free_Eurostat_agent();
xmachine_memory_Bank_state * init_Bank_state();
xmachine_memory_Bank * init_Bank_agent();
void free_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * state);
void transition_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * from_state, xmachine_memory_Bank_state * to_state);
void add_Bank_agent_internal(xmachine_memory_Bank * agent, xmachine_memory_Bank_state * state);
void add_Bank_agent(int id, int region_id, int gov_id, int partition_id, int active, int inactive, double cash, double total_credit, double equity, double ecb_debt, double value_at_risk, double deposit_interest_rate, double bank_gamma[], double profits[], double bank_dividend_rate, double tax_rate_corporate, int current_shares_outstanding, double debt_period, int loan_request_message_found, int day_of_month_to_act, double deposits, double firm_loan_installments, double firm_loan_installments_in_calendar_month, double firm_interest_payments, double firm_interest_payments_in_calendar_month, double firm_loan_issues, double ecb_interest_payment, double total_dividend_payment, double total_dividends_in_calendar_month, double taxes, double dividend_per_share, double current_share_price, double leverage_ratio, double cash_deposit_ratio, double equity_asset_ratio, double mean_interest_rate, double sum_new_interest_rates_in_calendar_month, int no_new_loans_in_calendar_month, double paid_interest_daily, double paid_interest_in_calendar_month, double excess_var, double excess_liquidity, double total_bad_debt_calendar_month, bank_balance_sheet_adt bank_balance_sheet_calendar, bank_stocks_adt bank_stocks_calendar, bank_outflows_adt bank_outflows_calendar, bank_inflows_adt bank_inflows_calendar, double total_income, double total_expenses, double total_assets, double total_liabilities);
void unittest_init_Bank_agent();
void unittest_free_Bank_agent();
xmachine_memory_Government_state * init_Government_state();
xmachine_memory_Government * init_Government_agent();
void free_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * state);
void transition_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * from_state, xmachine_memory_Government_state * to_state);
void add_Government_agent_internal(xmachine_memory_Government * agent, xmachine_memory_Government_state * state);
void add_Government_agent(int id, int_array * list_of_regions, double payment_account, int day_of_month_to_act, int region_id, int partition_id, double unemployment_benefit_pct, double gdp_fraction_consumption, double gdp_fraction_investment, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double monthly_tax_revenues, double yearly_tax_revenues, double debt_gdp_ratio, adt_gov_inflows_outflows_array * gov_inflows_outflows, double monthly_benefit_payment, double minimum_wage_pct, double gov_monthly_consumption_budget, double yearly_benefit_payment, double hh_transfer_payment, double firm_transfer_payment, double monthly_transfer_payment, double yearly_transfer_payment, double hh_subsidy_pct, double firm_subsidy_pct, int regional_firm_subsidy, int subsidy_flag, double gov_interest_rate, double monthly_bond_interest_payment, double monthly_subsidy_payment, double monthly_subsidy_payment_to_households, double monthly_subsidy_payment_to_firms, int austerity_phase, double monthly_consumption_expenditure, double foreign_debt, double add_foreign_debt, double foreign_debt_installment, double monthly_investment_expenditure, double monthly_budget_balance, double monthly_gdp, double_array * last_monthly_gdps, double monthly_budget_balance_gdp_fraction, double monthly_consumption_budget, double monthly_investment_budget, double monthly_income, double monthly_expenditure, double yearly_subsidy_payment, double yearly_bond_interest_payment, double yearly_investment_expenditure, double yearly_consumption_expenditure, double yearly_income, double yearly_expenditure, double subsidy_transfer_received, double total_debt, double yearly_budget_balance, double total_money_financing, double total_bond_financing, double country_wide_mean_wage, int num_unemployed, double yearly_gdp, double previous_year_gdp, double subsidy_reported_to_eurostat, double gdp_growth, double gdp_forecast, double yearly_income_forecast, double yearly_expenditure_budget, double budget_balance_forecast, ordered_quantity_array * ordered_quantities, received_quantities_array * gov_received_quantities, double_array * consumption_budgets_per_capita, double av_consumption_budget_per_capita, double_array * consumption_quotas_rel_to_reg1, double av_consumption_quota_rel_to_reg1, double yearly_consumption_budget, double yearly_investment_budget, double yearly_budget_balance_gdp_fraction, double total_assets, double total_liabilities, double cumulated_deficit, double inflation_rate, double unemployment_rate, int human_capital_policy_installation_date_in_years, int human_capital_policy_flag, double basic_security_benefits_pct, double basic_security_benefits, adt_skill_distribution_array * new_skill_distribution, double minimum_wage, int_array * all_region_ids, int_array * all_gov_ids, gov_balance_sheet_adt gov_balance_sheet_calendar, gov_stocks_adt gov_stocks_calendar, gov_outflows_adt gov_outflows_calendar, gov_inflows_adt gov_inflows_calendar);
void unittest_init_Government_agent();
void unittest_free_Government_agent();
xmachine_memory_CentralBank_state * init_CentralBank_state();
xmachine_memory_CentralBank * init_CentralBank_agent();
void free_CentralBank_agent(xmachine_memory_CentralBank_holder * tmp, xmachine_memory_CentralBank_state * state);
void transition_CentralBank_agent(xmachine_memory_CentralBank_holder * tmp, xmachine_memory_CentralBank_state * from_state, xmachine_memory_CentralBank_state * to_state);
void add_CentralBank_agent_internal(xmachine_memory_CentralBank * agent, xmachine_memory_CentralBank_state * state);
void add_CentralBank_agent(int id, int region_id, int partition_id, double equity, double dividend_payment, double fiat_money, double fiat_money_banks, double ecb_deposits, account_item_array * accounts_banks, account_item_array * accounts_govs, account_item_array * government_national_accounts, double cash, ecb_balance_sheet_adt ecb_balance_sheet_calendar, ecb_stocks_adt ecb_stocks_calendar, ecb_outflows_adt ecb_outflows_calendar, ecb_inflows_adt ecb_inflows_calendar, double bond_holdings_value, int nr_gov_bonds, double fiat_money_govs, double fiat_money_bond_govs, double bank_interest, double gov_interest, double gov_bond_purchase, double total_income, double total_expenses, double total_assets, double total_liabilities);
void unittest_init_CentralBank_agent();
void unittest_free_CentralBank_agent();
xmachine_memory_ClearingHouse_state * init_ClearingHouse_state();
xmachine_memory_ClearingHouse * init_ClearingHouse_agent();
void free_ClearingHouse_agent(xmachine_memory_ClearingHouse_holder * tmp, xmachine_memory_ClearingHouse_state * state);
void transition_ClearingHouse_agent(xmachine_memory_ClearingHouse_holder * tmp, xmachine_memory_ClearingHouse_state * from_state, xmachine_memory_ClearingHouse_state * to_state);
void add_ClearingHouse_agent_internal(xmachine_memory_ClearingHouse * agent, xmachine_memory_ClearingHouse_state * state);
void add_ClearingHouse_agent(int id, int region_id, int partition_id, order_array * pending_orders, order_array * processed_orders, index_adt stock_index, double dsratio, double_array * random_numbers_normal, double monthly_counter_total_dividend, double stock_index_price);
void unittest_init_ClearingHouse_agent();
void unittest_free_ClearingHouse_agent();

void add_bank_account_update_message(int id, int bank_id, double payment_account);
m_bank_account_update * add_bank_account_update_message_internal(void);
m_bank_account_update * get_first_bank_account_update_message(void);
m_bank_account_update * get_next_bank_account_update_message(m_bank_account_update * current);
void freebank_account_updatemessages(void);

void add_bank_to_central_bank_account_update_message(int id, double payment_account, double ecb_debt);
m_bank_to_central_bank_account_update * add_bank_to_central_bank_account_update_message_internal(void);
m_bank_to_central_bank_account_update * get_first_bank_to_central_bank_account_update_message(void);
m_bank_to_central_bank_account_update * get_next_bank_to_central_bank_account_update_message(m_bank_to_central_bank_account_update * current);
void freebank_to_central_bank_account_updatemessages(void);

void add_gov_to_central_bank_account_update_message(int id, double payment_account, double gdp);
m_gov_to_central_bank_account_update * add_gov_to_central_bank_account_update_message_internal(void);
m_gov_to_central_bank_account_update * get_first_gov_to_central_bank_account_update_message(void);
m_gov_to_central_bank_account_update * get_next_gov_to_central_bank_account_update_message(m_gov_to_central_bank_account_update * current);
void freegov_to_central_bank_account_updatemessages(void);

void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills, int employer_igfirm, double specific_skill);
m_wage_payment * add_wage_payment_message_internal(void);
m_wage_payment * get_first_wage_payment_message(void);
m_wage_payment * get_next_wage_payment_message(m_wage_payment * current);
void freewage_paymentmessages(void);

void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, int firm_region_id, double quality, double price, int available);
m_quality_price_info_1 * add_quality_price_info_1_message_internal(void);
m_quality_price_info_1 * get_first_quality_price_info_1_message(void);
m_quality_price_info_1 * get_next_quality_price_info_1_message(m_quality_price_info_1 * current);
void freequality_price_info_1messages(void);

void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, int firm_region_id, double quality, double price, int available);
m_quality_price_info_2 * add_quality_price_info_2_message_internal(void);
m_quality_price_info_2 * get_first_quality_price_info_2_message(void);
m_quality_price_info_2 * get_next_quality_price_info_2_message(m_quality_price_info_2 * current);
void freequality_price_info_2messages(void);

void add_update_mall_stock_message(int mall_id, int firm_id, int firm_region_id, double quantity, double quality, double price, double previous_price);
m_update_mall_stock * add_update_mall_stock_message_internal(void);
m_update_mall_stock * get_first_update_mall_stock_message(void);
m_update_mall_stock * get_next_update_mall_stock_message(m_update_mall_stock * current);
void freeupdate_mall_stockmessages(void);

void add_consumption_request_1_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity);
m_consumption_request_1 * add_consumption_request_1_message_internal(void);
m_consumption_request_1 * get_first_consumption_request_1_message(void);
m_consumption_request_1 * get_next_consumption_request_1_message(m_consumption_request_1 * current);
void freeconsumption_request_1messages(void);

void add_consumption_request_2_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity);
m_consumption_request_2 * add_consumption_request_2_message_internal(void);
m_consumption_request_2 * get_first_consumption_request_2_message(void);
m_consumption_request_2 * get_next_consumption_request_2_message(m_consumption_request_2 * current);
void freeconsumption_request_2messages(void);

void add_accepted_consumption_1_message(int mall_id, int household_id, int firm_id, double offered_consumption_volume, int rationed);
m_accepted_consumption_1 * add_accepted_consumption_1_message_internal(void);
m_accepted_consumption_1 * get_first_accepted_consumption_1_message(void);
m_accepted_consumption_1 * get_next_accepted_consumption_1_message(m_accepted_consumption_1 * current);
void freeaccepted_consumption_1messages(void);

void add_accepted_consumption_2_message(int mall_id, int household_id, int firm_id, double offered_consumption_volume, int rationed);
m_accepted_consumption_2 * add_accepted_consumption_2_message_internal(void);
m_accepted_consumption_2 * get_first_accepted_consumption_2_message(void);
m_accepted_consumption_2 * get_next_accepted_consumption_2_message(m_accepted_consumption_2 * current);
void freeaccepted_consumption_2messages(void);

void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double current_stock);
m_sales * add_sales_message_internal(void);
m_sales * get_first_sales_message(void);
m_sales * get_next_sales_message(m_sales * current);
void freesalesmessages(void);

void add_specific_skill_update_message(int id, int firm_id, double specific_skills, int general_skills);
m_specific_skill_update * add_specific_skill_update_message_internal(void);
m_specific_skill_update * get_first_specific_skill_update_message(void);
m_specific_skill_update * get_next_specific_skill_update_message(m_specific_skill_update * current);
void freespecific_skill_updatemessages(void);

void add_policy_rate_message(double policy_rate_value);
m_policy_rate * add_policy_rate_message_internal(void);
m_policy_rate * get_first_policy_rate_message(void);
m_policy_rate * get_next_policy_rate_message(m_policy_rate * current);
void freepolicy_ratemessages(void);

void add_bank_identity_message(int bank_id);
m_bank_identity * add_bank_identity_message_internal(void);
m_bank_identity * get_first_bank_identity_message(void);
m_bank_identity * get_next_bank_identity_message(m_bank_identity * current);
void freebank_identitymessages(void);

void add_loan_request_message(int firm_id, int bank_id, double equity, double total_debt, double external_financial_needs);
m_loan_request * add_loan_request_message_internal(void);
m_loan_request * get_first_loan_request_message(void);
m_loan_request * get_next_loan_request_message(m_loan_request * current);
void freeloan_requestmessages(void);

void add_loan_request_ranked_message(int firm_id, int bank_id, double equity, double total_debt, double credit_request, double value_at_risk_request);
m_loan_request_ranked * add_loan_request_ranked_message_internal(void);
m_loan_request_ranked * get_first_loan_request_ranked_message(void);
m_loan_request_ranked * get_next_loan_request_ranked_message(m_loan_request_ranked * current);
void freeloan_request_rankedmessages(void);

void add_loan_conditions_message(int firm_id, int bank_id, double proposed_interest_rate, double amount_offered_credit, double value_at_risk);
m_loan_conditions * add_loan_conditions_message_internal(void);
m_loan_conditions * get_first_loan_conditions_message(void);
m_loan_conditions * get_next_loan_conditions_message(m_loan_conditions * current);
void freeloan_conditionsmessages(void);

void add_loan_acceptance_message(int bank_id, double credit_amount_taken, double loan_total_var, double interest_rate);
m_loan_acceptance * add_loan_acceptance_message_internal(void);
m_loan_acceptance * get_first_loan_acceptance_message(void);
m_loan_acceptance * get_next_loan_acceptance_message(m_loan_acceptance * current);
void freeloan_acceptancemessages(void);

void add_installment_message(int bank_id, double installment_amount, double interest_amount, double var_per_installment, double total_var);
m_installment * add_installment_message_internal(void);
m_installment * get_first_installment_message(void);
m_installment * get_next_installment_message(m_installment * current);
void freeinstallmentmessages(void);

void add_bankruptcy_message(int firm_id, int bank_id, double bad_debt, double credit_refunded, double writeoff_var);
m_bankruptcy * add_bankruptcy_message_internal(void);
m_bankruptcy * get_first_bankruptcy_message(void);
m_bankruptcy * get_next_bankruptcy_message(m_bankruptcy * current);
void freebankruptcymessages(void);

void add_bank_interest_payment_message(double bank_interest_amount);
m_bank_interest_payment * add_bank_interest_payment_message_internal(void);
m_bank_interest_payment * get_first_bank_interest_payment_message(void);
m_bank_interest_payment * get_next_bank_interest_payment_message(m_bank_interest_payment * current);
void freebank_interest_paymentmessages(void);

void add_account_interest_message(int bank_id, double interest_rate);
m_account_interest * add_account_interest_message_internal(void);
m_account_interest * get_first_account_interest_message(void);
m_account_interest * get_next_account_interest_message(m_account_interest * current);
void freeaccount_interestmessages(void);

void add_ecb_dividend_message(int gov_id, double dividend_per_gov);
m_ecb_dividend * add_ecb_dividend_message_internal(void);
m_ecb_dividend * get_first_ecb_dividend_message(void);
m_ecb_dividend * get_next_ecb_dividend_message(m_ecb_dividend * current);
void freeecb_dividendmessages(void);

void add_credit_var_update_message(int firm_id, int bank_id, double value_at_risk);
m_credit_var_update * add_credit_var_update_message_internal(void);
m_credit_var_update * get_first_credit_var_update_message(void);
m_credit_var_update * get_next_credit_var_update_message(m_credit_var_update * current);
void freecredit_var_updatemessages(void);

void add_bankruptcy_illiquidity_message(int firm_id);
m_bankruptcy_illiquidity * add_bankruptcy_illiquidity_message_internal(void);
m_bankruptcy_illiquidity * get_first_bankruptcy_illiquidity_message(void);
m_bankruptcy_illiquidity * get_next_bankruptcy_illiquidity_message(m_bankruptcy_illiquidity * current);
void freebankruptcy_illiquiditymessages(void);

void add_bankruptcy_insolvency_message(int firm_id);
m_bankruptcy_insolvency * add_bankruptcy_insolvency_message_internal(void);
m_bankruptcy_insolvency * get_first_bankruptcy_insolvency_message(void);
m_bankruptcy_insolvency * get_next_bankruptcy_insolvency_message(m_bankruptcy_insolvency * current);
void freebankruptcy_insolvencymessages(void);

void add_index_info_message(double dividend_per_share);
m_index_info * add_index_info_message_internal(void);
m_index_info * get_first_index_info_message(void);
m_index_info * get_next_index_info_message(m_index_info * current);
void freeindex_infomessages(void);

void add_index_price_message(double price, double moving_avg_price);
m_index_price * add_index_price_message_internal(void);
m_index_price * get_first_index_price_message(void);
m_index_price * get_next_index_price_message(m_index_price * current);
void freeindex_pricemessages(void);

void add_order_message(int trader_id, double value);
m_order * add_order_message_internal(void);
m_order * get_first_order_message(void);
m_order * get_next_order_message(m_order * current);
void freeordermessages(void);

void add_order_status_message(int trader_id, double value, int quantity);
m_order_status * add_order_status_message_internal(void);
m_order_status * get_first_order_status_message(void);
m_order_status * get_next_order_status_message(m_order_status * current);
void freeorder_statusmessages(void);

void add_dividend_info_message(int firm_id, double total_dividend);
m_dividend_info * add_dividend_info_message_internal(void);
m_dividend_info * get_first_dividend_info_message(void);
m_dividend_info * get_next_dividend_info_message(m_dividend_info * current);
void freedividend_infomessages(void);

void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price);
m_productivity * add_productivity_message_internal(void);
m_productivity * get_first_productivity_message(void);
m_productivity * get_next_productivity_message(m_productivity * current);
void freeproductivitymessages(void);

void add_capital_good_request_message(int firm_id, double capital_good_demand, int vintage);
m_capital_good_request * add_capital_good_request_message_internal(void);
m_capital_good_request * get_first_capital_good_request_message(void);
m_capital_good_request * get_next_capital_good_request_message(m_capital_good_request * current);
void freecapital_good_requestmessages(void);

void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price);
m_capital_good_delivery * add_capital_good_delivery_message_internal(void);
m_capital_good_delivery * get_first_capital_good_delivery_message(void);
m_capital_good_delivery * get_next_capital_good_delivery_message(m_capital_good_delivery * current);
void freecapital_good_deliverymessages(void);

void add_pay_capital_goods_message(int firm_id, double capital_bill);
m_pay_capital_goods * add_pay_capital_goods_message_internal(void);
m_pay_capital_goods * get_first_pay_capital_goods_message(void);
m_pay_capital_goods * get_next_pay_capital_goods_message(m_pay_capital_goods * current);
void freepay_capital_goodsmessages(void);

void add_vacancies_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5);
m_vacancies * add_vacancies_message_internal(void);
m_vacancies * get_first_vacancies_message(void);
m_vacancies * get_next_vacancies_message(m_vacancies * current);
void freevacanciesmessages(void);

void add_vacancies2_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5);
m_vacancies2 * add_vacancies2_message_internal(void);
m_vacancies2 * get_first_vacancies2_message(void);
m_vacancies2 * get_next_vacancies2_message(m_vacancies2 * current);
void freevacancies2messages(void);

void add_vacancies_r_and_d_employees_message(int firm_id, int region_id, double firm_wage_offer);
m_vacancies_r_and_d_employees * add_vacancies_r_and_d_employees_message_internal(void);
m_vacancies_r_and_d_employees * get_first_vacancies_r_and_d_employees_message(void);
m_vacancies_r_and_d_employees * get_next_vacancies_r_and_d_employees_message(m_vacancies_r_and_d_employees * current);
void freevacancies_r_and_d_employeesmessages(void);

void add_vacancies_r_and_d_employees2_message(int firm_id, int region_id, double firm_wage_offer);
m_vacancies_r_and_d_employees2 * add_vacancies_r_and_d_employees2_message_internal(void);
m_vacancies_r_and_d_employees2 * get_first_vacancies_r_and_d_employees2_message(void);
m_vacancies_r_and_d_employees2 * get_next_vacancies_r_and_d_employees2_message(m_vacancies_r_and_d_employees2 * current);
void freevacancies_r_and_d_employees2messages(void);

void add_firing_message(int firm_id, int worker_id);
m_firing * add_firing_message_internal(void);
m_firing * get_first_firing_message(void);
m_firing * get_next_firing_message(m_firing * current);
void freefiringmessages(void);

void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type);
m_job_application * add_job_application_message_internal(void);
m_job_application * get_first_job_application_message(void);
m_job_application * get_next_job_application_message(m_job_application * current);
void freejob_applicationmessages(void);

void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type);
m_job_application2 * add_job_application2_message_internal(void);
m_job_application2 * get_first_job_application2_message(void);
m_job_application2 * get_next_job_application2_message(m_job_application2 * current);
void freejob_application2messages(void);

void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer, int job_type);
m_job_offer * add_job_offer_message_internal(void);
m_job_offer * get_first_job_offer_message(void);
m_job_offer * get_next_job_offer_message(m_job_offer * current);
void freejob_offermessages(void);

void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer, int job_type);
m_job_offer2 * add_job_offer2_message_internal(void);
m_job_offer2 * get_first_job_offer2_message(void);
m_job_offer2 * get_next_job_offer2_message(m_job_offer2 * current);
void freejob_offer2messages(void);

void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type);
m_job_acceptance * add_job_acceptance_message_internal(void);
m_job_acceptance * get_first_job_acceptance_message(void);
m_job_acceptance * get_next_job_acceptance_message(m_job_acceptance * current);
void freejob_acceptancemessages(void);

void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type);
m_job_acceptance2 * add_job_acceptance2_message_internal(void);
m_job_acceptance2 * get_first_job_acceptance2_message(void);
m_job_acceptance2 * get_next_job_acceptance2_message(m_job_acceptance2 * current);
void freejob_acceptance2messages(void);

void add_quitting_message(int worker_id, int firm_id);
m_quitting * add_quitting_message_internal(void);
m_quitting * get_first_quitting_message(void);
m_quitting * get_next_quitting_message(m_quitting * current);
void freequittingmessages(void);

void add_quitting2_message(int worker_id, int firm_id);
m_quitting2 * add_quitting2_message_internal(void);
m_quitting2 * get_first_quitting2_message(void);
m_quitting2 * get_next_quitting2_message(m_quitting2 * current);
void freequitting2messages(void);

void add_unemployment_notification_message(int gov_id, double unemployment_payment);
m_unemployment_notification * add_unemployment_notification_message_internal(void);
m_unemployment_notification * get_first_unemployment_notification_message(void);
m_unemployment_notification * get_next_unemployment_notification_message(m_unemployment_notification * current);
void freeunemployment_notificationmessages(void);

void add_policy_announcement_message(int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double unemployment_benefit_pct, double hh_subsidy_pct, double firm_subsidy_pct, double hh_transfer_payment, double firm_transfer_payment, double minimum_wage, double basic_security_benefits);
m_policy_announcement * add_policy_announcement_message_internal(void);
m_policy_announcement * get_first_policy_announcement_message(void);
m_policy_announcement * get_next_policy_announcement_message(m_policy_announcement * current);
void freepolicy_announcementmessages(void);

void add_tax_payment_message(int gov_id, double tax_payment);
m_tax_payment * add_tax_payment_message_internal(void);
m_tax_payment * get_first_tax_payment_message(void);
m_tax_payment * get_next_tax_payment_message(m_tax_payment * current);
void freetax_paymentmessages(void);

void add_unemployment_benefit_restitution_message(int gov_id, double restitution_payment);
m_unemployment_benefit_restitution * add_unemployment_benefit_restitution_message_internal(void);
m_unemployment_benefit_restitution * get_first_unemployment_benefit_restitution_message(void);
m_unemployment_benefit_restitution * get_next_unemployment_benefit_restitution_message(m_unemployment_benefit_restitution * current);
void freeunemployment_benefit_restitutionmessages(void);

void add_hh_transfer_notification_message(int gov_id);
m_hh_transfer_notification * add_hh_transfer_notification_message_internal(void);
m_hh_transfer_notification * get_first_hh_transfer_notification_message(void);
m_hh_transfer_notification * get_next_hh_transfer_notification_message(m_hh_transfer_notification * current);
void freehh_transfer_notificationmessages(void);

void add_hh_subsidy_notification_message(int gov_id, double subsidy_payment);
m_hh_subsidy_notification * add_hh_subsidy_notification_message_internal(void);
m_hh_subsidy_notification * get_first_hh_subsidy_notification_message(void);
m_hh_subsidy_notification * get_next_hh_subsidy_notification_message(m_hh_subsidy_notification * current);
void freehh_subsidy_notificationmessages(void);

void add_human_capital_policy_announcement_message(int gov_id, int announcement);
m_human_capital_policy_announcement * add_human_capital_policy_announcement_message_internal(void);
m_human_capital_policy_announcement * get_first_human_capital_policy_announcement_message(void);
m_human_capital_policy_announcement * get_next_human_capital_policy_announcement_message(m_human_capital_policy_announcement * current);
void freehuman_capital_policy_announcementmessages(void);

void add_firm_transfer_notification_message(int gov_id);
m_firm_transfer_notification * add_firm_transfer_notification_message_internal(void);
m_firm_transfer_notification * get_first_firm_transfer_notification_message(void);
m_firm_transfer_notification * get_next_firm_transfer_notification_message(m_firm_transfer_notification * current);
void freefirm_transfer_notificationmessages(void);

void add_firm_subsidy_notification_message(int gov_id, double subsidy_payment);
m_firm_subsidy_notification * add_firm_subsidy_notification_message_internal(void);
m_firm_subsidy_notification * get_first_firm_subsidy_notification_message(void);
m_firm_subsidy_notification * get_next_firm_subsidy_notification_message(m_firm_subsidy_notification * current);
void freefirm_subsidy_notificationmessages(void);

void add_request_fiat_money_message(double nominal_value);
m_request_fiat_money * add_request_fiat_money_message_internal(void);
m_request_fiat_money * get_first_request_fiat_money_message(void);
m_request_fiat_money * get_next_request_fiat_money_message(m_request_fiat_money * current);
void freerequest_fiat_moneymessages(void);

void add_human_capital_policy_general_skill_information_message(int id, int gov_id, int general_skills);
m_human_capital_policy_general_skill_information * add_human_capital_policy_general_skill_information_message_internal(void);
m_human_capital_policy_general_skill_information * get_first_human_capital_policy_general_skill_information_message(void);
m_human_capital_policy_general_skill_information * get_next_human_capital_policy_general_skill_information_message(m_human_capital_policy_general_skill_information * current);
void freehuman_capital_policy_general_skill_informationmessages(void);

void add_human_capital_policy_new_general_skill_notification_message(int id, int gov_id, int general_skills);
m_human_capital_policy_new_general_skill_notification * add_human_capital_policy_new_general_skill_notification_message_internal(void);
m_human_capital_policy_new_general_skill_notification * get_first_human_capital_policy_new_general_skill_notification_message(void);
m_human_capital_policy_new_general_skill_notification * get_next_human_capital_policy_new_general_skill_notification_message(m_human_capital_policy_new_general_skill_notification * current);
void freehuman_capital_policy_new_general_skill_notificationmessages(void);

void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int posted_vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, int employees_production, int employees_r_and_d, double average_wage, double average_wage_production, double average_wage_r_and_d, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double cum_revenue, double capital_costs, double net_earnings, double total_debt, double total_assets, double equity, double price, double price_last_month, double quality, double total_supply, double cum_total_sold_quantity, double output, double planned_output, int age, double firm_productivity, double firm_productivity_progress, double value_inventory, double units_capital_stock, double base_wage_offer, double dividends, double used_capital, double technology, double mark_up, int zero_output_for_longer, double unit_labor_costs);
m_firm_send_data * add_firm_send_data_message_internal(void);
m_firm_send_data * get_first_firm_send_data_message(void);
m_firm_send_data * get_next_firm_send_data_message(m_firm_send_data * current);
void freefirm_send_datamessages(void);

void add_government_send_data_message(int gov_id, int region_id, double consumption_expenditures);
m_government_send_data * add_government_send_data_message_internal(void);
m_government_send_data * get_first_government_send_data_message(void);
m_government_send_data * get_next_government_send_data_message(m_government_send_data * current);
void freegovernment_send_datamessages(void);

void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill, int just_employed, int just_unemployed, int start_employed, int start_unemployed, int enter_matching, int unemployed_duration, double consumption_budget_in_month, double payment_account, double mean_net_income, double wealth, double dividends, double interest_income, double net_inflows_financial_market, double reservation_wage);
m_household_send_data * add_household_send_data_message_internal(void);
m_household_send_data * get_first_household_send_data_message(void);
m_household_send_data * get_next_household_send_data_message(m_household_send_data * current);
void freehousehold_send_datamessages(void);

void add_mall_data_message(int mall_id, int firm_region, int household_region, double export_volume, double export_value, double export_previous_value);
m_mall_data * add_mall_data_message_internal(void);
m_mall_data * get_first_mall_data_message(void);
m_mall_data * get_next_mall_data_message(m_mall_data * current);
void freemall_datamessages(void);

void add_eurostat_send_specific_skills_message(int region_id, double specific_skill, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double productivity_progress, double average_wage, double vacancy_filling_rate, double average_output, double cpi, double price_index, int no_firms, double average_quality, double average_price, double wage_offer, double technology);
m_eurostat_send_specific_skills * add_eurostat_send_specific_skills_message_internal(void);
m_eurostat_send_specific_skills * get_first_eurostat_send_specific_skills_message(void);
m_eurostat_send_specific_skills * get_next_eurostat_send_specific_skills_message(m_eurostat_send_specific_skills * current);
void freeeurostat_send_specific_skillsmessages(void);

void add_data_for_government_message(int region_id, double gdp, double mean_wage, double unemployment_rate, double consumption_quota, double consumption_budget_per_capita);
m_data_for_government * add_data_for_government_message_internal(void);
m_data_for_government * get_first_data_for_government_message(void);
m_data_for_government * get_next_data_for_government_message(m_data_for_government * current);
void freedata_for_governmentmessages(void);

void add_eurostat_send_macrodata_message(double inflation, double gdp, double unemployment_rate);
m_eurostat_send_macrodata * add_eurostat_send_macrodata_message_internal(void);
m_eurostat_send_macrodata * get_first_eurostat_send_macrodata_message(void);
m_eurostat_send_macrodata * get_next_eurostat_send_macrodata_message(m_eurostat_send_macrodata * current);
void freeeurostat_send_macrodatamessages(void);

void add_msg_firm_id_to_malls_message(int firm_id, int region_id);
m_msg_firm_id_to_malls * add_msg_firm_id_to_malls_message_internal(void);
m_msg_firm_id_to_malls * get_first_msg_firm_id_to_malls_message(void);
m_msg_firm_id_to_malls * get_next_msg_firm_id_to_malls_message(m_msg_firm_id_to_malls * current);
void freemsg_firm_id_to_mallsmessages(void);

void add_msg_mall_id_to_firms_message(int mall_id, int region_id);
m_msg_mall_id_to_firms * add_msg_mall_id_to_firms_message_internal(void);
m_msg_mall_id_to_firms * get_first_msg_mall_id_to_firms_message(void);
m_msg_mall_id_to_firms * get_next_msg_mall_id_to_firms_message(m_msg_mall_id_to_firms * current);
void freemsg_mall_id_to_firmsmessages(void);

void add_msg_skills_eurostat_to_igfirm_message(double mean_general_skills, double mean_specific_skills, double productivity_progress, double total_capital_stock_units);
m_msg_skills_eurostat_to_igfirm * add_msg_skills_eurostat_to_igfirm_message_internal(void);
m_msg_skills_eurostat_to_igfirm * get_first_msg_skills_eurostat_to_igfirm_message(void);
m_msg_skills_eurostat_to_igfirm * get_next_msg_skills_eurostat_to_igfirm_message(m_msg_skills_eurostat_to_igfirm * current);
void freemsg_skills_eurostat_to_igfirmmessages(void);

void add_msg_market_sizes_message(int region_id, double market_size, double government_demand);
m_msg_market_sizes * add_msg_market_sizes_message_internal(void);
m_msg_market_sizes * get_first_msg_market_sizes_message(void);
m_msg_market_sizes * get_next_msg_market_sizes_message(m_msg_market_sizes * current);
void freemsg_market_sizesmessages(void);

void add_total_subsidies_message(int gov_id, int region_id, double amount);
m_total_subsidies * add_total_subsidies_message_internal(void);
m_total_subsidies * get_first_total_subsidies_message(void);
m_total_subsidies * get_next_total_subsidies_message(m_total_subsidies * current);
void freetotal_subsidiesmessages(void);

void add_redistributed_subsidies_message(int gov_id, double amount);
m_redistributed_subsidies * add_redistributed_subsidies_message_internal(void);
m_redistributed_subsidies * get_first_redistributed_subsidies_message(void);
m_redistributed_subsidies * get_next_redistributed_subsidies_message(m_redistributed_subsidies * current);
void freeredistributed_subsidiesmessages(void);

void add_quality_price_message(int region_id, double quality, double price);
m_quality_price * add_quality_price_message_internal(void);
m_quality_price * get_first_quality_price_message(void);
m_quality_price * get_next_quality_price_message(m_quality_price * current);
void freequality_pricemessages(void);

void add_interview_request_message(int firm_id);
m_interview_request * add_interview_request_message_internal(void);
m_interview_request * get_first_interview_request_message(void);
m_interview_request * get_next_interview_request_message(m_interview_request * current);
void freeinterview_requestmessages(void);

void add_interview_positive_response_message(int id, int region_id, int firm_id);
m_interview_positive_response * add_interview_positive_response_message_internal(void);
m_interview_positive_response * get_first_interview_positive_response_message(void);
m_interview_positive_response * get_next_interview_positive_response_message(m_interview_positive_response * current);
void freeinterview_positive_responsemessages(void);

void add_questionnaire_innovation_message(int firm_id, price_quality_pair price_quality[]);
m_questionnaire_innovation * add_questionnaire_innovation_message_internal(void);
m_questionnaire_innovation * get_first_questionnaire_innovation_message(void);
m_questionnaire_innovation * get_next_questionnaire_innovation_message(m_questionnaire_innovation * current);
void freequestionnaire_innovationmessages(void);

void add_filled_out_questionnaire_product_innovation_message(int firm_id, int region_id, int choice);
m_filled_out_questionnaire_product_innovation * add_filled_out_questionnaire_product_innovation_message_internal(void);
m_filled_out_questionnaire_product_innovation * get_first_filled_out_questionnaire_product_innovation_message(void);
m_filled_out_questionnaire_product_innovation * get_next_filled_out_questionnaire_product_innovation_message(m_filled_out_questionnaire_product_innovation * current);
void freefilled_out_questionnaire_product_innovationmessages(void);


void set_id(int id);
int get_id();
void set_region_id(int region_id);
int get_region_id();
void set_gov_id(int gov_id);
int get_gov_id();
void set_day_of_month_to_act(int day_of_month_to_act);
int get_day_of_month_to_act();
void set_last_day_of_month_to_act(int last_day_of_month_to_act);
int get_last_day_of_month_to_act();
void set_payment_account(double payment_account);
double get_payment_account();
void set_payment_account_balance_sheet(double payment_account_balance_sheet);
double get_payment_account_balance_sheet();
void set_bank_id(int bank_id);
int get_bank_id();
void set_partition_id(int partition_id);
int get_partition_id();
void set_cpi(double cpi);
double get_cpi();
void set_mean_wage(double mean_wage);
double get_mean_wage();
void set_total_mean_wage(double total_mean_wage);
double get_total_mean_wage();
void set_mean_wage_r_and_d(double mean_wage_r_and_d);
double get_mean_wage_r_and_d();
void set_needed_capital_stock(double needed_capital_stock);
double get_needed_capital_stock();
void set_stock(double stock);
double get_stock();
void set_critical_stock(double critical_stock);
double get_critical_stock();
void set_actual_cap_price(double actual_cap_price);
double get_actual_cap_price();
void set_mean_specific_skills(double mean_specific_skills);
double get_mean_specific_skills();
void set_planned_production_quantity(double planned_production_quantity);
double get_planned_production_quantity();
void set_production_quantity(double production_quantity);
double get_production_quantity();
void set_planned_output(double planned_output);
double get_planned_output();
void set_output(double output);
double get_output();
void set_unit_costs(double unit_costs);
double get_unit_costs();
void set_total_supply(double total_supply);
double get_total_supply();
void set_production_costs(double production_costs);
double get_production_costs();
void set_total_buffer(double total_buffer);
double get_total_buffer();
void set_revenue_per_day(double revenue_per_day);
double get_revenue_per_day();
estimators_linear_regression_array * get_linear_regression_estimators();
void set_technological_frontier(double technological_frontier);
double get_technological_frontier();
adt_technology_vintages_array * get_technology_vintages();
void set_vintage_selected(int vintage_selected);
int get_vintage_selected();
void set_investment_subsidy_type(int investment_subsidy_type);
int get_investment_subsidy_type();
void set_initial_market_size(double initial_market_size);
double get_initial_market_size();
void set_initial_technology(double initial_technology);
double get_initial_technology();
void set_utilization_capacity(double utilization_capacity);
double get_utilization_capacity();
void set_used_capital_units(double used_capital_units);
double get_used_capital_units();
void set_cum_revenue(double cum_revenue);
double get_cum_revenue();
sales_statistics_array * get_malls_sales_statistics();
void set_quality(double quality);
double get_quality();
void set_price(double price);
double get_price();
void set_price_last_month(double price_last_month);
double get_price_last_month();
void set_actual_mark_up(double actual_mark_up);
double get_actual_mark_up();
void set_demand_capital_stock(double demand_capital_stock);
double get_demand_capital_stock();
void set_effective_investments(double effective_investments);
double get_effective_investments();
void set_effective_capital_stock(double effective_capital_stock);
double get_effective_capital_stock();
void set_planned_production_costs(double planned_production_costs);
double get_planned_production_costs();
void set_labour_costs_production(double labour_costs_production);
double get_labour_costs_production();
void set_labour_costs_innovation(double labour_costs_innovation);
double get_labour_costs_innovation();
void set_intermediate_quality_level_developing(double intermediate_quality_level_developing);
double get_intermediate_quality_level_developing();
void set_adaption_production_volume_due_to_insufficient_finances(double adaption_production_volume_due_to_insufficient_finances);
double get_adaption_production_volume_due_to_insufficient_finances();
sold_quantities_per_mall_array * get_sold_quantities();
void set_total_sold_quantity(double total_sold_quantity);
double get_total_sold_quantity();
void set_cum_total_sold_quantity(double cum_total_sold_quantity);
double get_cum_total_sold_quantity();
void set_sold_quantity_in_calendar_month(double sold_quantity_in_calendar_month);
double get_sold_quantity_in_calendar_month();
delivery_volume_per_mall_array * get_delivery_volume();
delivery_volume_per_mall_array * get_planned_delivery_volume();
mall_info_array * get_current_mall_stocks();
double_array * get_last_planned_production_quantities();
void set_total_external_financing_obtained(double total_external_financing_obtained);
double get_total_external_financing_obtained();
void set_capital_costs(double capital_costs);
double get_capital_costs();
void set_employees_needed_production(int employees_needed_production);
int get_employees_needed_production();
void set_no_employees_production(int no_employees_production);
int get_no_employees_production();
void set_planned_innovation_expenditures(double planned_innovation_expenditures);
double get_planned_innovation_expenditures();
void set_planned_expenditures_production_innovation(double planned_expenditures_production_innovation);
double get_planned_expenditures_production_innovation();
void set_labour_costs(double labour_costs);
double get_labour_costs();
void set_labour_costs_per_unit(double labour_costs_per_unit);
double get_labour_costs_per_unit();
adt_capital_stock_vintages_array * get_capital_stock_vintages();
void set_vintage_choice_taken(int vintage_choice_taken);
int get_vintage_choice_taken();
financing_capital_array * get_capital_financing();
void set_financial_resources_for_production(double financial_resources_for_production);
double get_financial_resources_for_production();
void set_total_units_local_inventory(double total_units_local_inventory);
double get_total_units_local_inventory();
void set_calc_capital_costs(double calc_capital_costs);
double get_calc_capital_costs();
void set_calc_production_costs(double calc_production_costs);
double get_calc_production_costs();
void set_firm_productivity(double firm_productivity);
double get_firm_productivity();
void set_total_productivity_capital_stock(double total_productivity_capital_stock);
double get_total_productivity_capital_stock();
void set_firm_productivity_last_year(double firm_productivity_last_year);
double get_firm_productivity_last_year();
void set_firm_productivity_progress(double firm_productivity_progress);
double get_firm_productivity_progress();
void set_sold_quantity_in_last_calendar_month(double sold_quantity_in_last_calendar_month);
double get_sold_quantity_in_last_calendar_month();
double_array * get_last_sold_quantities();
double_array * get_last_revenues();
int_array * get_set_of_lenders();
int_array * get_potential_lenders();
void set_number_of_banks_asked(int number_of_banks_asked);
int get_number_of_banks_asked();
void set_received_interest_daily(double received_interest_daily);
double get_received_interest_daily();
void set_received_interest_in_calendar_month(double received_interest_in_calendar_month);
double get_received_interest_in_calendar_month();
void set_flag_illiquidity_correction(int flag_illiquidity_correction);
int get_flag_illiquidity_correction();
void set_ebit(double ebit);
double get_ebit();
void set_earnings(double earnings);
double get_earnings();
void set_tax_rate_corporate(double tax_rate_corporate);
double get_tax_rate_corporate();
void set_tax_rate_vat(double tax_rate_vat);
double get_tax_rate_vat();
void set_tax_payment(double tax_payment);
double get_tax_payment();
void set_tax_payment_in_calendar_month(double tax_payment_in_calendar_month);
double get_tax_payment_in_calendar_month();
void set_net_earnings(double net_earnings);
double get_net_earnings();
double_array * get_earnings_history();
void set_previous_net_earnings(double previous_net_earnings);
double get_previous_net_earnings();
void set_total_interest_payment(double total_interest_payment);
double get_total_interest_payment();
void set_total_interest_payment_in_calendar_month(double total_interest_payment_in_calendar_month);
double get_total_interest_payment_in_calendar_month();
void set_total_debt_installment_payment(double total_debt_installment_payment);
double get_total_debt_installment_payment();
void set_total_debt_installment_payment_in_calendar_month(double total_debt_installment_payment_in_calendar_month);
double get_total_debt_installment_payment_in_calendar_month();
void set_total_dividend_payment(double total_dividend_payment);
double get_total_dividend_payment();
void set_total_dividend_payment_in_calendar_month(double total_dividend_payment_in_calendar_month);
double get_total_dividend_payment_in_calendar_month();
void set_flag_full_dividend(int flag_full_dividend);
int get_flag_full_dividend();
void set_current_share_price(double current_share_price);
double get_current_share_price();
void set_previous_dividend_per_share(double previous_dividend_per_share);
double get_previous_dividend_per_share();
void set_current_dividend_per_share(double current_dividend_per_share);
double get_current_dividend_per_share();
void set_previous_earnings_per_share(double previous_earnings_per_share);
double get_previous_earnings_per_share();
void set_current_earnings_per_share(double current_earnings_per_share);
double get_current_earnings_per_share();
void set_previous_dividend_per_earnings(double previous_dividend_per_earnings);
double get_previous_dividend_per_earnings();
void set_current_dividend_per_earnings(double current_dividend_per_earnings);
double get_current_dividend_per_earnings();
void set_debt_earnings_ratio(double debt_earnings_ratio);
double get_debt_earnings_ratio();
void set_debt_equity_ratio(double debt_equity_ratio);
double get_debt_equity_ratio();
void set_price_earnings_ratio(double price_earnings_ratio);
double get_price_earnings_ratio();
void set_retained_earnings_ratio(double retained_earnings_ratio);
double get_retained_earnings_ratio();
void set_earnings_per_share_ratio_growth(double earnings_per_share_ratio_growth);
double get_earnings_per_share_ratio_growth();
void set_critical_price_earnings_ratio(double critical_price_earnings_ratio);
double get_critical_price_earnings_ratio();
void set_critical_earnings_per_share_ratio(double critical_earnings_per_share_ratio);
double get_critical_earnings_per_share_ratio();
debt_item_array * get_loans();
void set_total_debt(double total_debt);
double get_total_debt();
void set_target_debt(double target_debt);
double get_target_debt();
void set_total_debt_balance_sheet(double total_debt_balance_sheet);
double get_total_debt_balance_sheet();
void set_total_value_local_inventory(double total_value_local_inventory);
double get_total_value_local_inventory();
void set_total_value_local_inventory_balance_sheet(double total_value_local_inventory_balance_sheet);
double get_total_value_local_inventory_balance_sheet();
void set_total_units_capital_stock(double total_units_capital_stock);
double get_total_units_capital_stock();
void set_total_value_capital_stock(double total_value_capital_stock);
double get_total_value_capital_stock();
void set_total_value_capital_stock_balance_sheet(double total_value_capital_stock_balance_sheet);
double get_total_value_capital_stock_balance_sheet();
void set_total_capital_depreciation_value(double total_capital_depreciation_value);
double get_total_capital_depreciation_value();
void set_total_capital_depreciation_units(double total_capital_depreciation_units);
double get_total_capital_depreciation_units();
void set_total_assets(double total_assets);
double get_total_assets();
void set_equity(double equity);
double get_equity();
void set_equity_balance_sheet(double equity_balance_sheet);
double get_equity_balance_sheet();
void set_production_liquidity_needs(double production_liquidity_needs);
double get_production_liquidity_needs();
void set_financial_liquidity_needs(double financial_liquidity_needs);
double get_financial_liquidity_needs();
void set_total_financial_needs(double total_financial_needs);
double get_total_financial_needs();
void set_external_financial_needs(double external_financial_needs);
double get_external_financial_needs();
void set_earnings_per_share(double earnings_per_share);
double get_earnings_per_share();
void set_retained_earnings(double retained_earnings);
double get_retained_earnings();
void set_total_payments(double total_payments);
double get_total_payments();
void set_previous_shares_outstanding(int previous_shares_outstanding);
int get_previous_shares_outstanding();
void set_minsky_state(int minsky_state);
int get_minsky_state();
void set_minsky_state_1(int minsky_state_1);
int get_minsky_state_1();
void set_minsky_state_2(int minsky_state_2);
int get_minsky_state_2();
void set_minsky_state_3(int minsky_state_3);
int get_minsky_state_3();
void set_minsky_state_4(int minsky_state_4);
int get_minsky_state_4();
void set_minsky_state_5(int minsky_state_5);
int get_minsky_state_5();
void set_minsky_state_20(int minsky_state_20);
int get_minsky_state_20();
void set_minsky_state_21(int minsky_state_21);
int get_minsky_state_21();
void set_minsky_state_22(int minsky_state_22);
int get_minsky_state_22();
void set_minsky_state_23(int minsky_state_23);
int get_minsky_state_23();
void set_minsky_state_30(int minsky_state_30);
int get_minsky_state_30();
void set_minsky_state_31(int minsky_state_31);
int get_minsky_state_31();
void set_minsky_state_32(int minsky_state_32);
int get_minsky_state_32();
void set_minsky_state_33(int minsky_state_33);
int get_minsky_state_33();
void set_minsky_state_40(int minsky_state_40);
int get_minsky_state_40();
void set_minsky_state_41(int minsky_state_41);
int get_minsky_state_41();
void set_minsky_state_42(int minsky_state_42);
int get_minsky_state_42();
void set_minsky_state_43(int minsky_state_43);
int get_minsky_state_43();
void set_age_at_bankruptcy(int age_at_bankruptcy);
int get_age_at_bankruptcy();
void set_debt_at_bankruptcy(double debt_at_bankruptcy);
double get_debt_at_bankruptcy();
void set_equity_at_bankruptcy(double equity_at_bankruptcy);
double get_equity_at_bankruptcy();
void set_no_employees_at_bankruptcy(int no_employees_at_bankruptcy);
int get_no_employees_at_bankruptcy();
void set_equity_asset_ratio(double equity_asset_ratio);
double get_equity_asset_ratio();
void set_profit_asset_ratio(double profit_asset_ratio);
double get_profit_asset_ratio();
void set_sales_asset_ratio(double sales_asset_ratio);
double get_sales_asset_ratio();
void set_investment_asset_ratio(double investment_asset_ratio);
double get_investment_asset_ratio();
void set_total_income(double total_income);
double get_total_income();
void set_total_liabilities(double total_liabilities);
double get_total_liabilities();
void set_total_expenses(double total_expenses);
double get_total_expenses();
void set_current_shares_outstanding(int current_shares_outstanding);
int get_current_shares_outstanding();
employee_array * get_employees();
employee_array * get_r_and_d_employees();
void set_wage_offer(double wage_offer);
double get_wage_offer();
void set_technology(double technology);
double get_technology();
void set_no_employees(int no_employees);
int get_no_employees();
void set_no_employees_skill_1(int no_employees_skill_1);
int get_no_employees_skill_1();
void set_no_employees_skill_2(int no_employees_skill_2);
int get_no_employees_skill_2();
void set_no_employees_skill_3(int no_employees_skill_3);
int get_no_employees_skill_3();
void set_no_employees_skill_4(int no_employees_skill_4);
int get_no_employees_skill_4();
void set_no_employees_skill_5(int no_employees_skill_5);
int get_no_employees_skill_5();
void set_no_employees_subsidized(int no_employees_subsidized);
int get_no_employees_subsidized();
void set_fraction_employees_subsidized(double fraction_employees_subsidized);
double get_fraction_employees_subsidized();
void set_vacancies(int vacancies);
int get_vacancies();
void set_no_redundancies(int no_redundancies);
int get_no_redundancies();
void set_no_applications_round_1(int no_applications_round_1);
int get_no_applications_round_1();
void set_no_applications_round_2(int no_applications_round_2);
int get_no_applications_round_2();
void set_no_redundancies_r_and_d_employees(int no_redundancies_r_and_d_employees);
int get_no_redundancies_r_and_d_employees();
void set_vacancies_r_and_d_employees(int vacancies_r_and_d_employees);
int get_vacancies_r_and_d_employees();
void set_posted_vacancies(int posted_vacancies);
int get_posted_vacancies();
void set_posted_vacancies_r_and_d_employees(int posted_vacancies_r_and_d_employees);
int get_posted_vacancies_r_and_d_employees();
void set_average_g_skill(double average_g_skill);
double get_average_g_skill();
void set_average_adaptation_speed_specific_skills(double average_adaptation_speed_specific_skills);
double get_average_adaptation_speed_specific_skills();
adt_list_adaptation_speed_array * get_list_adaptation_speed_per_skill_group();
void set_average_s_skill_of_1(double average_s_skill_of_1);
double get_average_s_skill_of_1();
void set_average_s_skill_of_2(double average_s_skill_of_2);
double get_average_s_skill_of_2();
void set_average_s_skill_of_3(double average_s_skill_of_3);
double get_average_s_skill_of_3();
void set_average_s_skill_of_4(double average_s_skill_of_4);
double get_average_s_skill_of_4();
void set_average_s_skill_of_5(double average_s_skill_of_5);
double get_average_s_skill_of_5();
void set_wage_offer_for_skill_1(double wage_offer_for_skill_1);
double get_wage_offer_for_skill_1();
void set_wage_offer_for_skill_2(double wage_offer_for_skill_2);
double get_wage_offer_for_skill_2();
void set_wage_offer_for_skill_3(double wage_offer_for_skill_3);
double get_wage_offer_for_skill_3();
void set_wage_offer_for_skill_4(double wage_offer_for_skill_4);
double get_wage_offer_for_skill_4();
void set_wage_offer_for_skill_5(double wage_offer_for_skill_5);
double get_wage_offer_for_skill_5();
void set_wage_offer_for_r_and_d_employees(double wage_offer_for_r_and_d_employees);
double get_wage_offer_for_r_and_d_employees();
void set_base_wage_offer_r_and_d(double base_wage_offer_r_and_d);
double get_base_wage_offer_r_and_d();
void set_employees_needed(int employees_needed);
int get_employees_needed();
firm_balance_sheet_adt * get_firm_balance_sheet_calendar();
firm_stocks_adt * get_firm_stocks_calendar();
firm_outflows_adt * get_firm_outflows_calendar();
firm_inflows_adt * get_firm_inflows_calendar();
void set_age(int age);
int get_age();
void set_transfer_payment(double transfer_payment);
double get_transfer_payment();
void set_subsidy_pct(double subsidy_pct);
double get_subsidy_pct();
void set_active(int active);
int get_active();
void set_inactive(int inactive);
int get_inactive();
void set_zero_output(int zero_output);
int get_zero_output();
void set_bankruptcy_idle_counter(int bankruptcy_idle_counter);
int get_bankruptcy_idle_counter();
void set_bankruptcy_state(int bankruptcy_state);
int get_bankruptcy_state();
void set_bankruptcy_insolvency_state(int bankruptcy_insolvency_state);
int get_bankruptcy_insolvency_state();
void set_bankruptcy_illiquidity_state(int bankruptcy_illiquidity_state);
int get_bankruptcy_illiquidity_state();
void set_financial_crisis_state(int financial_crisis_state);
int get_financial_crisis_state();
void set_vacancy_filling_rate(double vacancy_filling_rate);
double get_vacancy_filling_rate();
void set_average_s_skill_from_eurostat(double average_s_skill_from_eurostat);
double get_average_s_skill_from_eurostat();
void set_average_technology_from_eurostat(double average_technology_from_eurostat);
double get_average_technology_from_eurostat();
void set_average_wage_offer_from_eurostat(double average_wage_offer_from_eurostat);
double get_average_wage_offer_from_eurostat();
void set_average_output_from_eurostat(double average_output_from_eurostat);
double get_average_output_from_eurostat();
price_quality_pair_array * get_quality_price_competitors();
void set_subsidy_payment(double subsidy_payment);
double get_subsidy_payment();
void set_current_price_index(double current_price_index);
double get_current_price_index();
void set_current_quality_index(double current_quality_index);
double get_current_quality_index();
void set_minimum_wage(double minimum_wage);
double get_minimum_wage();
void set_no_competitors(int no_competitors);
int get_no_competitors();
void set_indicator_earnings(int indicator_earnings);
int get_indicator_earnings();
void set_indicator_capital_costs(int indicator_capital_costs);
int get_indicator_capital_costs();
void set_agg_vacancy_filling_rate(double agg_vacancy_filling_rate);
double get_agg_vacancy_filling_rate();
void set_market_research_sample_size(int market_research_sample_size);
int get_market_research_sample_size();
void set_product_innovation(int product_innovation);
int get_product_innovation();
void set_regional_analysis(int regional_analysis);
int get_regional_analysis();
void set_day_of_year_market_research(int day_of_year_market_research);
int get_day_of_year_market_research();
void set_day_of_month_price_was_set(int day_of_month_price_was_set);
int get_day_of_month_price_was_set();
void set_actual_sample_size(int actual_sample_size);
int get_actual_sample_size();
dt_total_and_regional_market_size_array * get_last_market_sizes();
dt_price_range * get_price_range_pricing();
void set_estimated_variance_market_share(double estimated_variance_market_share);
double get_estimated_variance_market_share();
price_quality_pair * get_estimated_coefficients();
dt_price_range * get_price_range_innovation();
int * get_price_quality_counts();
price_quality_pair * get_price_quality_inno();
void set_new_product_released(int new_product_released);
int get_new_product_released();
dt_prospective_variables_array * get_prospective_variables();
void set_price_at_questionnaire(double price_at_questionnaire);
double get_price_at_questionnaire();
void set_price_index_at_questionnaire(double price_index_at_questionnaire);
double get_price_index_at_questionnaire();
dt_best_price_strategies_array * get_best_pricing_strategies();
void set_intermediate_quality(double intermediate_quality);
double get_intermediate_quality();
void set_no_employees_product_innovation_fundable(int no_employees_product_innovation_fundable);
int get_no_employees_product_innovation_fundable();
void set_r_and_d_probability_for_incremental_success(double r_and_d_probability_for_incremental_success);
double get_r_and_d_probability_for_incremental_success();
void set_day_of_year_price_setting(int day_of_year_price_setting);
int get_day_of_year_price_setting();
void set_market_research_active(int market_research_active);
int get_market_research_active();
void set_innovation_successful(int innovation_successful);
int get_innovation_successful();
void set_actual_market_share(double actual_market_share);
double get_actual_market_share();
void set_market_size(double market_size);
double get_market_size();
void set_market_size_reg1(double market_size_reg1);
double get_market_size_reg1();
void set_market_size_reg2(double market_size_reg2);
double get_market_size_reg2();
void set_estimated_market_size(double estimated_market_size);
double get_estimated_market_size();
estimators_linear_regression_array * get_linear_regression_market_size();
void set_counter_month_since_last_price_setting(int counter_month_since_last_price_setting);
int get_counter_month_since_last_price_setting();
dt_demand_function * get_demand_function_pricing();
dt_demand_function_array * get_demand_functions_product_innovation();
void set_market_research_delayed(int market_research_delayed);
int get_market_research_delayed();
dt_market_research_price_array * get_market_research_data_pricing();
dt_market_research_qualities_array * get_market_research_data_product_innovation();
void set_expected_earnings_per_month(double expected_earnings_per_month);
double get_expected_earnings_per_month();
double_array * get_expected_price_choices();
void set_no_considered_qualities(double no_considered_qualities);
double get_no_considered_qualities();
void set_last_interest_rate_for_loans(double last_interest_rate_for_loans);
double get_last_interest_rate_for_loans();
void set_cum_earnings_last_r_d_project(double cum_earnings_last_r_d_project);
double get_cum_earnings_last_r_d_project();
void set_cum_r_d_investments(double cum_r_d_investments);
double get_cum_r_d_investments();
void set_r_d_investments_last_project(double r_d_investments_last_project);
double get_r_d_investments_last_project();
void set_total_person_months(int total_person_months);
int get_total_person_months();
void set_cum_person_months(int cum_person_months);
int get_cum_person_months();
void set_actual_r_and_d_success_probability(double actual_r_and_d_success_probability);
double get_actual_r_and_d_success_probability();
void set_last_quality(double last_quality);
double get_last_quality();
void set_quality_change(double quality_change);
double get_quality_change();
void set_expected_sold_quantity_per_month(double expected_sold_quantity_per_month);
double get_expected_sold_quantity_per_month();
void set_estimated_market_share(double estimated_market_share);
double get_estimated_market_share();
void set_estimated_yearly_earnings(double estimated_yearly_earnings);
double get_estimated_yearly_earnings();
dt_monthly_estimations * get_expected_earnings_and_costs_over_year();
void set_expected_output_in_current_month(double expected_output_in_current_month);
double get_expected_output_in_current_month();
void set_expected_profit_in_current_month(double expected_profit_in_current_month);
double get_expected_profit_in_current_month();
void set_expected_labor_costs_in_current_month(double expected_labor_costs_in_current_month);
double get_expected_labor_costs_in_current_month();
void set_expected_capital_costs_in_current_month(double expected_capital_costs_in_current_month);
double get_expected_capital_costs_in_current_month();
void set_expected_interests_in_current_month(double expected_interests_in_current_month);
double get_expected_interests_in_current_month();
void set_expected_output_in_previous_month(double expected_output_in_previous_month);
double get_expected_output_in_previous_month();
void set_expected_actual_sold_quantity_in_previous_month(double expected_actual_sold_quantity_in_previous_month);
double get_expected_actual_sold_quantity_in_previous_month();
void set_expected_actual_sold_quantity_in_current_month(double expected_actual_sold_quantity_in_current_month);
double get_expected_actual_sold_quantity_in_current_month();
void set_expected_labor_costs_in_previous_month(double expected_labor_costs_in_previous_month);
double get_expected_labor_costs_in_previous_month();
void set_expected_capital_costs_in_previous_month(double expected_capital_costs_in_previous_month);
double get_expected_capital_costs_in_previous_month();
void set_expected_interests_in_previous_month(double expected_interests_in_previous_month);
double get_expected_interests_in_previous_month();
void set_expected_profit_in_previous_month(double expected_profit_in_previous_month);
double get_expected_profit_in_previous_month();
void set_expected_wage_in_current_month(double expected_wage_in_current_month);
double get_expected_wage_in_current_month();
void set_expected_wage_in_previous_month(double expected_wage_in_previous_month);
double get_expected_wage_in_previous_month();
void set_expected_mean_specific_skills_in_current_month(double expected_mean_specific_skills_in_current_month);
double get_expected_mean_specific_skills_in_current_month();
void set_expected_mean_specific_skills_in_previous_month(double expected_mean_specific_skills_in_previous_month);
double get_expected_mean_specific_skills_in_previous_month();
void set_expected_average_productivity_in_current_month(double expected_average_productivity_in_current_month);
double get_expected_average_productivity_in_current_month();
void set_expected_investment_nominal_in_current_month(double expected_investment_nominal_in_current_month);
double get_expected_investment_nominal_in_current_month();
void set_expected_investment_nominal_in_previous_month(double expected_investment_nominal_in_previous_month);
double get_expected_investment_nominal_in_previous_month();
void set_expected_average_productivity_in_previous_month(double expected_average_productivity_in_previous_month);
double get_expected_average_productivity_in_previous_month();
void set_earnings_while_last_pricing_period(double earnings_while_last_pricing_period);
double get_earnings_while_last_pricing_period();
void set_sum_earnings_since_price_change(double sum_earnings_since_price_change);
double get_sum_earnings_since_price_change();
dt_variables_changed_array * get_variables_last_year();
void set_innovation_month_counter(int innovation_month_counter);
int get_innovation_month_counter();
void set_periods_output_zero_counter(int periods_output_zero_counter);
int get_periods_output_zero_counter();
dt_variables_changed * get_variables_change();
void set_r_and_d_investments_per_month(double r_and_d_investments_per_month);
double get_r_and_d_investments_per_month();
void set_innovation_flag(int innovation_flag);
int get_innovation_flag();
void set_innovation_employees_needed(int innovation_employees_needed);
int get_innovation_employees_needed();
void set_no_employees_innovation(int no_employees_innovation);
int get_no_employees_innovation();
void set_employees_needed_innovation(int employees_needed_innovation);
int get_employees_needed_innovation();
void set_optimal_employees_needed_innovation(int optimal_employees_needed_innovation);
int get_optimal_employees_needed_innovation();
void set_total_no_periods_for_product_development(int total_no_periods_for_product_development);
int get_total_no_periods_for_product_development();
void set_ratio_project_value_established_product(double ratio_project_value_established_product);
double get_ratio_project_value_established_product();
void set_vintage_choice_already_taken(int vintage_choice_already_taken);
int get_vintage_choice_already_taken();
void set_change_due_to_last_innovation(double change_due_to_last_innovation);
double get_change_due_to_last_innovation();
void set_remaining_periods_to_complete_product_development(int remaining_periods_to_complete_product_development);
int get_remaining_periods_to_complete_product_development();
void set_planned_quality(double planned_quality);
double get_planned_quality();
void set_product_development_completed(double product_development_completed);
double get_product_development_completed();
void set_price_just_set_flag(double price_just_set_flag);
double get_price_just_set_flag();
dt_value_lattice_years_array * get_value_lattice();
void set_combined_variance_demand_function(double combined_variance_demand_function);
double get_combined_variance_demand_function();
int_array * get_neighboring_region_ids();
void set_new_agent(int new_agent);
int get_new_agent();
void set_migration_status(int migration_status);
int get_migration_status();
void set_consumption_budget(double consumption_budget);
double get_consumption_budget();
void set_consumption_budget_in_month(double consumption_budget_in_month);
double get_consumption_budget_in_month();
void set_week_of_month(int week_of_month);
int get_week_of_month();
void set_weekly_budget(double weekly_budget);
double get_weekly_budget();
void set_rationed(int rationed);
int get_rationed();
void set_mall_completely_sold_out(int mall_completely_sold_out);
int get_mall_completely_sold_out();
ordered_quantity * get_order_quantity();
received_quantities * get_received_quantity();
void set_day_of_week_to_act(int day_of_week_to_act);
int get_day_of_week_to_act();
void set_day_of_month_receive_income(int day_of_month_receive_income);
int get_day_of_month_receive_income();
void set_current_productivity_employer(double current_productivity_employer);
double get_current_productivity_employer();
void set_current_mean_specific_skills_employer(double current_mean_specific_skills_employer);
double get_current_mean_specific_skills_employer();
void set_cum_total_dividends(double cum_total_dividends);
double get_cum_total_dividends();
void set_tax_rate_hh_capital(double tax_rate_hh_capital);
double get_tax_rate_hh_capital();
void set_tax_rate_hh_labour(double tax_rate_hh_labour);
double get_tax_rate_hh_labour();
void set_price_index(double price_index);
double get_price_index();
void set_price_index_base_period(double price_index_base_period);
double get_price_index_base_period();
void set_commuting_costs_price_level_weight(double commuting_costs_price_level_weight);
double get_commuting_costs_price_level_weight();
void set_expenditures(double expenditures);
double get_expenditures();
void set_received_dividend(double received_dividend);
double get_received_dividend();
void set_received_dividend_in_calendar_month(double received_dividend_in_calendar_month);
double get_received_dividend_in_calendar_month();
void set_flag_consumption_shifting(int flag_consumption_shifting);
int get_flag_consumption_shifting();
void set_excess_weekly_budget(double excess_weekly_budget);
double get_excess_weekly_budget();
void set_wealth_income_ratio_actual(double wealth_income_ratio_actual);
double get_wealth_income_ratio_actual();
void set_wealth_income_ratio_target(double wealth_income_ratio_target);
double get_wealth_income_ratio_target();
void set_last_weekly_budget(double last_weekly_budget);
double get_last_weekly_budget();
void set_risk_free_rate(double risk_free_rate);
double get_risk_free_rate();
void set_wealth(double wealth);
double get_wealth();
Belief * get_beliefs();
index_portfolio * get_assetsowned();
void set_logit_beta(double logit_beta);
double get_logit_beta();
void set_wage(double wage);
double get_wage();
void set_wage_reservation(double wage_reservation);
double get_wage_reservation();
void set_general_skill(int general_skill);
int get_general_skill();
adt_list_adaptation_speed_array * get_list_adaptation_speed_per_general_skill_group();
void set_on_the_job_search(int on_the_job_search);
int get_on_the_job_search();
void set_search_today(int search_today);
int get_search_today();
void set_last_labour_income(double last_labour_income);
double get_last_labour_income();
void set_specific_skill(double specific_skill);
double get_specific_skill();
void set_employee_firm_id(int employee_firm_id);
int get_employee_firm_id();
void set_hh_applications_per_day(int hh_applications_per_day);
int get_hh_applications_per_day();
void set_just_employed(int just_employed);
int get_just_employed();
void set_just_unemployed(int just_unemployed);
int get_just_unemployed();
void set_start_unemployed(int start_unemployed);
int get_start_unemployed();
void set_start_employed(int start_employed);
int get_start_employed();
void set_unemployed_duration(int unemployed_duration);
int get_unemployed_duration();
void set_enter_matching(int enter_matching);
int get_enter_matching();
void set_employer_region_id(int employer_region_id);
int get_employer_region_id();
void set_employer_igfirm(int employer_igfirm);
int get_employer_igfirm();
void set_day_of_month_receive_benefit(int day_of_month_receive_benefit);
int get_day_of_month_receive_benefit();
void set_unemployment_payment(double unemployment_payment);
double get_unemployment_payment();
void set_region_wide_mean_wage(double region_wide_mean_wage);
double get_region_wide_mean_wage();
void set_basic_security_benefits(double basic_security_benefits);
double get_basic_security_benefits();
double_array * get_last_net_income();
void set_mean_net_income(double mean_net_income);
double get_mean_net_income();
household_balance_sheet_adt * get_household_balance_sheet_calendar();
household_stocks_adt * get_household_stocks_calendar();
household_outflows_adt * get_household_outflows_calendar();
household_inflows_adt * get_household_inflows_calendar();
void set_unemployment_benefit_pct(double unemployment_benefit_pct);
double get_unemployment_benefit_pct();
void set_monthly_interest_income(double monthly_interest_income);
double get_monthly_interest_income();
void set_monthly_consumption_expenditure(double monthly_consumption_expenditure);
double get_monthly_consumption_expenditure();
void set_monthly_bond_interest_income(double monthly_bond_interest_income);
double get_monthly_bond_interest_income();
void set_region_mean_wage(double region_mean_wage);
double get_region_mean_wage();
void set_human_capital_policy_flag(int human_capital_policy_flag);
int get_human_capital_policy_flag();
void set_questionnaire_attending_propability(double questionnaire_attending_propability);
double get_questionnaire_attending_propability();
void set_willingness_to_attend(int willingness_to_attend);
int get_willingness_to_attend();
void set_interviewer_id(int interviewer_id);
int get_interviewer_id();
void set_random_no_test(int random_no_test);
int get_random_no_test();
int * get_questionnaire();
consumption_goods_offer_array * get_current_price_quality_list();
mall_stock_array * get_current_stock();
sales_in_mall_array * get_firm_revenues();
void set_sales_per_month(double sales_per_month);
double get_sales_per_month();
double * get_export_volume_matrix();
double * get_export_value_matrix();
double * get_export_previous_value_matrix();
void set_productivity(double productivity);
double get_productivity();
void set_capital_good_price(double capital_good_price);
double get_capital_good_price();
vintage_array * get_vintages();
adt_sales_per_vintage_array * get_sales_per_vintage();
void set_mean_productivity_of_sales(double mean_productivity_of_sales);
double get_mean_productivity_of_sales();
void set_ratio_sold_productivity_best_practice(double ratio_sold_productivity_best_practice);
double get_ratio_sold_productivity_best_practice();
void set_igfirm_endogenous_innovation_probability(double igfirm_endogenous_innovation_probability);
double get_igfirm_endogenous_innovation_probability();
void set_net_profit(double net_profit);
double get_net_profit();
void set_energy_price_markup(double energy_price_markup);
double get_energy_price_markup();
void set_energy_costs_per_day(double energy_costs_per_day);
double get_energy_costs_per_day();
void set_earnings_per_day(double earnings_per_day);
double get_earnings_per_day();
void set_cum_energy_costs(double cum_energy_costs);
double get_cum_energy_costs();
double_array * get_last_net_profits();
void set_mean_sales_last_months(double mean_sales_last_months);
double get_mean_sales_last_months();
double_array * get_last_sales();
void set_dividend_payment(double dividend_payment);
double get_dividend_payment();
void set_duration_until_next_innovation(int duration_until_next_innovation);
int get_duration_until_next_innovation();
void set_sales(double sales);
double get_sales();
void set_capital_good_demand(double capital_good_demand);
double get_capital_good_demand();
void set_capital_good_demand_last_month(double capital_good_demand_last_month);
double get_capital_good_demand_last_month();
void set_sales_last_month(double sales_last_month);
double get_sales_last_month();
void set_cum_revenue_last_month(double cum_revenue_last_month);
double get_cum_revenue_last_month();
int_array * get_innovation_sheme_low_progress();
int_array * get_innovation_sheme_medium_progress();
int_array * get_innovation_sheme_high_progress();
void set_mean_general_skills(double mean_general_skills);
double get_mean_general_skills();
void set_mean_adaptation_speed(double mean_adaptation_speed);
double get_mean_adaptation_speed();
adt_list_adaptation_speed_array * get_list_adaptation_speed();
void set_productivity_progress_in_economy(double productivity_progress_in_economy);
double get_productivity_progress_in_economy();
void set_economy_wide_capital_stock(double economy_wide_capital_stock);
double get_economy_wide_capital_stock();
void set_dividend_buffer(double dividend_buffer);
double get_dividend_buffer();
void set_dividend_target(double dividend_target);
double get_dividend_target();
igfirm_balance_sheet_adt * get_igfirm_balance_sheet_calendar();
igfirm_stocks_adt * get_igfirm_stocks_calendar();
igfirm_outflows_adt * get_igfirm_outflows_calendar();
igfirm_inflows_adt * get_igfirm_inflows_calendar();
void set_economy_wide_general_skills_in_firms(double economy_wide_general_skills_in_firms);
double get_economy_wide_general_skills_in_firms();
void set_economy_wide_specific_skills_in_firms(double economy_wide_specific_skills_in_firms);
double get_economy_wide_specific_skills_in_firms();
void set_switch_datastorage(int switch_datastorage);
int get_switch_datastorage();
void set_num_households(int num_households);
int get_num_households();
void set_no_households_skill_1(int no_households_skill_1);
int get_no_households_skill_1();
void set_no_households_skill_2(int no_households_skill_2);
int get_no_households_skill_2();
void set_no_households_skill_3(int no_households_skill_3);
int get_no_households_skill_3();
void set_no_households_skill_4(int no_households_skill_4);
int get_no_households_skill_4();
void set_no_households_skill_5(int no_households_skill_5);
int get_no_households_skill_5();
void set_employed(int employed);
int get_employed();
void set_employed_skill_1(int employed_skill_1);
int get_employed_skill_1();
void set_employed_skill_2(int employed_skill_2);
int get_employed_skill_2();
void set_employed_skill_3(int employed_skill_3);
int get_employed_skill_3();
void set_employed_skill_4(int employed_skill_4);
int get_employed_skill_4();
void set_employed_skill_5(int employed_skill_5);
int get_employed_skill_5();
void set_average_unit_labor_costs_reg_1(double average_unit_labor_costs_reg_1);
double get_average_unit_labor_costs_reg_1();
void set_average_unit_labor_costs_reg_2(double average_unit_labor_costs_reg_2);
double get_average_unit_labor_costs_reg_2();
void set_unemployed(int unemployed);
int get_unemployed();
void set_unemployment_rate(double unemployment_rate);
double get_unemployment_rate();
void set_employment_rate(double employment_rate);
double get_employment_rate();
void set_unemployment_rate_skill_1(double unemployment_rate_skill_1);
double get_unemployment_rate_skill_1();
void set_unemployment_rate_skill_2(double unemployment_rate_skill_2);
double get_unemployment_rate_skill_2();
void set_unemployment_rate_skill_3(double unemployment_rate_skill_3);
double get_unemployment_rate_skill_3();
void set_unemployment_rate_skill_4(double unemployment_rate_skill_4);
double get_unemployment_rate_skill_4();
void set_unemployment_rate_skill_5(double unemployment_rate_skill_5);
double get_unemployment_rate_skill_5();
void set_unemployed_reg1(int unemployed_reg1);
int get_unemployed_reg1();
void set_unemployed_reg2(int unemployed_reg2);
int get_unemployed_reg2();
void set_unemployment_rate_reg1(double unemployment_rate_reg1);
double get_unemployment_rate_reg1();
void set_unemployment_rate_reg2(double unemployment_rate_reg2);
double get_unemployment_rate_reg2();
void set_v_u_ratio_reg1(double v_u_ratio_reg1);
double get_v_u_ratio_reg1();
void set_v_u_ratio_reg2(double v_u_ratio_reg2);
double get_v_u_ratio_reg2();
void set_average_wage(double average_wage);
double get_average_wage();
void set_average_wage_reservation(double average_wage_reservation);
double get_average_wage_reservation();
void set_average_wage_reservation_region_1(double average_wage_reservation_region_1);
double get_average_wage_reservation_region_1();
void set_average_wage_reservation_region_2(double average_wage_reservation_region_2);
double get_average_wage_reservation_region_2();
void set_average_wage_skill_1(double average_wage_skill_1);
double get_average_wage_skill_1();
void set_average_wage_skill_2(double average_wage_skill_2);
double get_average_wage_skill_2();
void set_average_wage_skill_3(double average_wage_skill_3);
double get_average_wage_skill_3();
void set_average_wage_skill_4(double average_wage_skill_4);
double get_average_wage_skill_4();
void set_average_wage_skill_5(double average_wage_skill_5);
double get_average_wage_skill_5();
void set_sd_wage(double sd_wage);
double get_sd_wage();
void set_sd_income(double sd_income);
double get_sd_income();
void set_sd_wealth(double sd_wealth);
double get_sd_wealth();
void set_sd_specific_skills(double sd_specific_skills);
double get_sd_specific_skills();
void set_sd_wage_reg_1(double sd_wage_reg_1);
double get_sd_wage_reg_1();
void set_sd_income_reg_1(double sd_income_reg_1);
double get_sd_income_reg_1();
void set_sd_wealth_reg_1(double sd_wealth_reg_1);
double get_sd_wealth_reg_1();
void set_sd_specific_skills_reg_1(double sd_specific_skills_reg_1);
double get_sd_specific_skills_reg_1();
void set_sd_wage_reg_2(double sd_wage_reg_2);
double get_sd_wage_reg_2();
void set_sd_income_reg_2(double sd_income_reg_2);
double get_sd_income_reg_2();
void set_sd_wealth_reg_2(double sd_wealth_reg_2);
double get_sd_wealth_reg_2();
void set_sd_specific_skills_reg_2(double sd_specific_skills_reg_2);
double get_sd_specific_skills_reg_2();
void set_total_output_reg_2(double total_output_reg_2);
double get_total_output_reg_2();
void set_total_output_reg_1(double total_output_reg_1);
double get_total_output_reg_1();
void set_per_capita_output_reg_2(double per_capita_output_reg_2);
double get_per_capita_output_reg_2();
void set_per_capita_output_reg_1(double per_capita_output_reg_1);
double get_per_capita_output_reg_1();
void set_mean_price_reg_1(double mean_price_reg_1);
double get_mean_price_reg_1();
void set_mean_price_reg_2(double mean_price_reg_2);
double get_mean_price_reg_2();
void set_mean_technology_reg_1(double mean_technology_reg_1);
double get_mean_technology_reg_1();
void set_mean_technology_reg_2(double mean_technology_reg_2);
double get_mean_technology_reg_2();
void set_exports_reg1(double exports_reg1);
double get_exports_reg1();
void set_exports_reg2(double exports_reg2);
double get_exports_reg2();
void set_imports_reg1(double imports_reg1);
double get_imports_reg1();
void set_trade_balance_reg1(double trade_balance_reg1);
double get_trade_balance_reg1();
void set_trade_balance_reg2(double trade_balance_reg2);
double get_trade_balance_reg2();
void set_imports_reg2(double imports_reg2);
double get_imports_reg2();
void set_export_quota_reg1(double export_quota_reg1);
double get_export_quota_reg1();
void set_export_quota_reg2(double export_quota_reg2);
double get_export_quota_reg2();
void set_import_quota_reg1(double import_quota_reg1);
double get_import_quota_reg1();
void set_import_quota_reg2(double import_quota_reg2);
double get_import_quota_reg2();
void set_trade_balance_quota_reg1(double trade_balance_quota_reg1);
double get_trade_balance_quota_reg1();
void set_trade_balance_quota_reg2(double trade_balance_quota_reg2);
double get_trade_balance_quota_reg2();
void set_mean_wage_reg_1(double mean_wage_reg_1);
double get_mean_wage_reg_1();
void set_mean_wage_reg_2(double mean_wage_reg_2);
double get_mean_wage_reg_2();
void set_mean_wage_offer_reg_1(double mean_wage_offer_reg_1);
double get_mean_wage_offer_reg_1();
void set_mean_wage_offer_reg_2(double mean_wage_offer_reg_2);
double get_mean_wage_offer_reg_2();
void set_mean_s_skills_reg_1(double mean_s_skills_reg_1);
double get_mean_s_skills_reg_1();
void set_mean_s_skills_reg_2(double mean_s_skills_reg_2);
double get_mean_s_skills_reg_2();
void set_mean_mark_up_reg_1(double mean_mark_up_reg_1);
double get_mean_mark_up_reg_1();
void set_mean_mark_up_reg_2(double mean_mark_up_reg_2);
double get_mean_mark_up_reg_2();
void set_relative_price(double relative_price);
double get_relative_price();
void set_relative_reservation_wage(double relative_reservation_wage);
double get_relative_reservation_wage();
void set_relative_mark_up(double relative_mark_up);
double get_relative_mark_up();
void set_relative_wage(double relative_wage);
double get_relative_wage();
void set_relative_wage_offer(double relative_wage_offer);
double get_relative_wage_offer();
void set_relative_technology(double relative_technology);
double get_relative_technology();
void set_relative_s_skills(double relative_s_skills);
double get_relative_s_skills();
void set_relative_output(double relative_output);
double get_relative_output();
void set_government_consumption(double government_consumption);
double get_government_consumption();
void set_gini_wage(double gini_wage);
double get_gini_wage();
void set_gini_income(double gini_income);
double get_gini_income();
void set_gini_wealth(double gini_wealth);
double get_gini_wealth();
void set_gini_specific_skills(double gini_specific_skills);
double get_gini_specific_skills();
void set_gini_wage_reg_1(double gini_wage_reg_1);
double get_gini_wage_reg_1();
void set_gini_income_reg_1(double gini_income_reg_1);
double get_gini_income_reg_1();
void set_gini_wealth_reg_1(double gini_wealth_reg_1);
double get_gini_wealth_reg_1();
void set_gini_specific_skills_reg_1(double gini_specific_skills_reg_1);
double get_gini_specific_skills_reg_1();
void set_gini_wage_reg_2(double gini_wage_reg_2);
double get_gini_wage_reg_2();
void set_gini_income_reg_2(double gini_income_reg_2);
double get_gini_income_reg_2();
void set_gini_wealth_reg_2(double gini_wealth_reg_2);
double get_gini_wealth_reg_2();
void set_gini_specific_skills_reg_2(double gini_specific_skills_reg_2);
double get_gini_specific_skills_reg_2();
void set_labor_income_reg_1(double labor_income_reg_1);
double get_labor_income_reg_1();
void set_labor_income_reg_2(double labor_income_reg_2);
double get_labor_income_reg_2();
void set_dividend_income_reg_1(double dividend_income_reg_1);
double get_dividend_income_reg_1();
void set_dividend_income_reg_2(double dividend_income_reg_2);
double get_dividend_income_reg_2();
void set_interest_income_reg_1(double interest_income_reg_1);
double get_interest_income_reg_1();
void set_interest_income_reg_2(double interest_income_reg_2);
double get_interest_income_reg_2();
void set_financial_market_net_revenue_reg_1(double financial_market_net_revenue_reg_1);
double get_financial_market_net_revenue_reg_1();
void set_financial_market_net_revenue_reg_2(double financial_market_net_revenue_reg_2);
double get_financial_market_net_revenue_reg_2();
void set_average_s_skill(double average_s_skill);
double get_average_s_skill();
void set_average_s_skill_1(double average_s_skill_1);
double get_average_s_skill_1();
void set_average_s_skill_2(double average_s_skill_2);
double get_average_s_skill_2();
void set_average_s_skill_3(double average_s_skill_3);
double get_average_s_skill_3();
void set_average_s_skill_4(double average_s_skill_4);
double get_average_s_skill_4();
void set_average_s_skill_5(double average_s_skill_5);
double get_average_s_skill_5();
void set_total_consumption_budget(double total_consumption_budget);
double get_total_consumption_budget();
void set_no_firms(int no_firms);
int get_no_firms();
void set_no_active_firms(int no_active_firms);
int get_no_active_firms();
void set_no_vacancies(int no_vacancies);
int get_no_vacancies();
void set_no_posted_vacancies(int no_posted_vacancies);
int get_no_posted_vacancies();
void set_no_employees_r_and_d(int no_employees_r_and_d);
int get_no_employees_r_and_d();
price_quality_pair_array * get_price_quality_combination();
void set_firm_average_wage(double firm_average_wage);
double get_firm_average_wage();
void set_firm_average_production_wage(double firm_average_production_wage);
double get_firm_average_production_wage();
void set_firm_average_r_and_d_wage(double firm_average_r_and_d_wage);
double get_firm_average_r_and_d_wage();
void set_firm_average_wage_skill_1(double firm_average_wage_skill_1);
double get_firm_average_wage_skill_1();
void set_firm_average_wage_skill_2(double firm_average_wage_skill_2);
double get_firm_average_wage_skill_2();
void set_firm_average_wage_skill_3(double firm_average_wage_skill_3);
double get_firm_average_wage_skill_3();
void set_firm_average_wage_skill_4(double firm_average_wage_skill_4);
double get_firm_average_wage_skill_4();
void set_firm_average_wage_skill_5(double firm_average_wage_skill_5);
double get_firm_average_wage_skill_5();
void set_firm_average_g_skill(double firm_average_g_skill);
double get_firm_average_g_skill();
void set_firm_average_s_skill(double firm_average_s_skill);
double get_firm_average_s_skill();
void set_firm_average_s_skill_1(double firm_average_s_skill_1);
double get_firm_average_s_skill_1();
void set_firm_average_s_skill_2(double firm_average_s_skill_2);
double get_firm_average_s_skill_2();
void set_firm_average_s_skill_3(double firm_average_s_skill_3);
double get_firm_average_s_skill_3();
void set_firm_average_s_skill_4(double firm_average_s_skill_4);
double get_firm_average_s_skill_4();
void set_firm_average_s_skill_5(double firm_average_s_skill_5);
double get_firm_average_s_skill_5();
void set_firm_average_quality(double firm_average_quality);
double get_firm_average_quality();
void set_firm_average_price(double firm_average_price);
double get_firm_average_price();
firm_data_array * get_region_firm_data();
household_data_array * get_region_household_data();
government_data_array * get_region_government_data();
void set_total_earnings(double total_earnings);
double get_total_earnings();
void set_total_equity(double total_equity);
double get_total_equity();
void set_average_debt_earnings_ratio(double average_debt_earnings_ratio);
double get_average_debt_earnings_ratio();
void set_average_debt_equity_ratio(double average_debt_equity_ratio);
double get_average_debt_equity_ratio();
void set_labour_share_ratio(double labour_share_ratio);
double get_labour_share_ratio();
void set_hpi(double hpi);
double get_hpi();
adt_subsidies_per_government_array * get_subsidies_per_government();
adt_subsidies_per_government_array * get_subsidies_balanced();
void set_gdp(double gdp);
double get_gdp();
void set_monthly_investment_value(double monthly_investment_value);
double get_monthly_investment_value();
void set_monthly_sold_quantity(double monthly_sold_quantity);
double get_monthly_sold_quantity();
void set_herfindahl_index(double herfindahl_index);
double get_herfindahl_index();
void set_monthly_output(double monthly_output);
double get_monthly_output();
void set_monthly_revenue(double monthly_revenue);
double get_monthly_revenue();
void set_monthly_planned_output(double monthly_planned_output);
double get_monthly_planned_output();
history_item * get_history_monthly();
history_item * get_history_quarterly();
history_item * get_monthly_growth_rates();
history_item * get_quarterly_growth_rates();
history_item * get_annual_growth_rates_monthly();
history_item * get_annual_growth_rates_quarterly();
void set_no_firm_births(int no_firm_births);
int get_no_firm_births();
void set_no_firm_deaths(int no_firm_deaths);
int get_no_firm_deaths();
int * get_firm_age_distribution();
int * get_firm_age_distribution_multiperiod();
int * get_firm_age_distribution_1_period_lag();
int * get_firm_age_distribution_2_period_lag();
void set_firm_birth_rate(double firm_birth_rate);
double get_firm_birth_rate();
void set_firm_death_rate(double firm_death_rate);
double get_firm_death_rate();
double * get_survival_rate();
double * get_survival_rate_multiperiod_1();
double * get_survival_rate_multiperiod_2();
double * get_survival_rate_multiperiod();
void set_max_firm_creation(int max_firm_creation);
int get_max_firm_creation();
void set_recession_started(int recession_started);
int get_recession_started();
void set_recession_duration(int recession_duration);
int get_recession_duration();
double * get_region_export_volume();
double * get_region_import_volume();
double * get_region_export_value();
double * get_region_import_value();
double * get_region_import_previous_value();
void set_firm_average_productivity_progress(double firm_average_productivity_progress);
double get_firm_average_productivity_progress();
void set_firm_average_productivity(double firm_average_productivity);
double get_firm_average_productivity();
void set_investment_gdp_ratio(double investment_gdp_ratio);
double get_investment_gdp_ratio();
void set_total_capital_stock_units(double total_capital_stock_units);
double get_total_capital_stock_units();
void set_total_value_mall_inventories(double total_value_mall_inventories);
double get_total_value_mall_inventories();
void set_total_dividends(double total_dividends);
double get_total_dividends();
void set_base_wage_offer(double base_wage_offer);
double get_base_wage_offer();
int_array * get_all_region_ids();
int_array * get_all_gov_ids();
void set_job_seperation_rate(double job_seperation_rate);
double get_job_seperation_rate();
void set_job_finding_rate(double job_finding_rate);
double get_job_finding_rate();
void set_v_u_ratio(double v_u_ratio);
double get_v_u_ratio();
void set_matching_rate(double matching_rate);
double get_matching_rate();
void set_hh_payment_account(double hh_payment_account);
double get_hh_payment_account();
void set_cash(double cash);
double get_cash();
void set_total_credit(double total_credit);
double get_total_credit();
void set_ecb_debt(double ecb_debt);
double get_ecb_debt();
void set_value_at_risk(double value_at_risk);
double get_value_at_risk();
void set_deposit_interest_rate(double deposit_interest_rate);
double get_deposit_interest_rate();
double * get_bank_gamma();
double * get_profits();
void set_bank_dividend_rate(double bank_dividend_rate);
double get_bank_dividend_rate();
void set_debt_period(double debt_period);
double get_debt_period();
void set_loan_request_message_found(int loan_request_message_found);
int get_loan_request_message_found();
void set_deposits(double deposits);
double get_deposits();
void set_firm_loan_installments(double firm_loan_installments);
double get_firm_loan_installments();
void set_firm_loan_installments_in_calendar_month(double firm_loan_installments_in_calendar_month);
double get_firm_loan_installments_in_calendar_month();
void set_firm_interest_payments(double firm_interest_payments);
double get_firm_interest_payments();
void set_firm_interest_payments_in_calendar_month(double firm_interest_payments_in_calendar_month);
double get_firm_interest_payments_in_calendar_month();
void set_firm_loan_issues(double firm_loan_issues);
double get_firm_loan_issues();
void set_ecb_interest_payment(double ecb_interest_payment);
double get_ecb_interest_payment();
void set_total_dividends_in_calendar_month(double total_dividends_in_calendar_month);
double get_total_dividends_in_calendar_month();
void set_taxes(double taxes);
double get_taxes();
void set_dividend_per_share(double dividend_per_share);
double get_dividend_per_share();
void set_leverage_ratio(double leverage_ratio);
double get_leverage_ratio();
void set_cash_deposit_ratio(double cash_deposit_ratio);
double get_cash_deposit_ratio();
void set_mean_interest_rate(double mean_interest_rate);
double get_mean_interest_rate();
void set_sum_new_interest_rates_in_calendar_month(double sum_new_interest_rates_in_calendar_month);
double get_sum_new_interest_rates_in_calendar_month();
void set_no_new_loans_in_calendar_month(int no_new_loans_in_calendar_month);
int get_no_new_loans_in_calendar_month();
void set_paid_interest_daily(double paid_interest_daily);
double get_paid_interest_daily();
void set_paid_interest_in_calendar_month(double paid_interest_in_calendar_month);
double get_paid_interest_in_calendar_month();
void set_excess_var(double excess_var);
double get_excess_var();
void set_excess_liquidity(double excess_liquidity);
double get_excess_liquidity();
void set_total_bad_debt_calendar_month(double total_bad_debt_calendar_month);
double get_total_bad_debt_calendar_month();
bank_balance_sheet_adt * get_bank_balance_sheet_calendar();
bank_stocks_adt * get_bank_stocks_calendar();
bank_outflows_adt * get_bank_outflows_calendar();
bank_inflows_adt * get_bank_inflows_calendar();
int_array * get_list_of_regions();
void set_gdp_fraction_consumption(double gdp_fraction_consumption);
double get_gdp_fraction_consumption();
void set_gdp_fraction_investment(double gdp_fraction_investment);
double get_gdp_fraction_investment();
void set_monthly_tax_revenues(double monthly_tax_revenues);
double get_monthly_tax_revenues();
void set_yearly_tax_revenues(double yearly_tax_revenues);
double get_yearly_tax_revenues();
void set_debt_gdp_ratio(double debt_gdp_ratio);
double get_debt_gdp_ratio();
adt_gov_inflows_outflows_array * get_gov_inflows_outflows();
void set_monthly_benefit_payment(double monthly_benefit_payment);
double get_monthly_benefit_payment();
void set_minimum_wage_pct(double minimum_wage_pct);
double get_minimum_wage_pct();
void set_gov_monthly_consumption_budget(double gov_monthly_consumption_budget);
double get_gov_monthly_consumption_budget();
void set_yearly_benefit_payment(double yearly_benefit_payment);
double get_yearly_benefit_payment();
void set_hh_transfer_payment(double hh_transfer_payment);
double get_hh_transfer_payment();
void set_firm_transfer_payment(double firm_transfer_payment);
double get_firm_transfer_payment();
void set_monthly_transfer_payment(double monthly_transfer_payment);
double get_monthly_transfer_payment();
void set_yearly_transfer_payment(double yearly_transfer_payment);
double get_yearly_transfer_payment();
void set_hh_subsidy_pct(double hh_subsidy_pct);
double get_hh_subsidy_pct();
void set_firm_subsidy_pct(double firm_subsidy_pct);
double get_firm_subsidy_pct();
void set_regional_firm_subsidy(int regional_firm_subsidy);
int get_regional_firm_subsidy();
void set_subsidy_flag(int subsidy_flag);
int get_subsidy_flag();
void set_gov_interest_rate(double gov_interest_rate);
double get_gov_interest_rate();
void set_monthly_bond_interest_payment(double monthly_bond_interest_payment);
double get_monthly_bond_interest_payment();
void set_monthly_subsidy_payment(double monthly_subsidy_payment);
double get_monthly_subsidy_payment();
void set_monthly_subsidy_payment_to_households(double monthly_subsidy_payment_to_households);
double get_monthly_subsidy_payment_to_households();
void set_monthly_subsidy_payment_to_firms(double monthly_subsidy_payment_to_firms);
double get_monthly_subsidy_payment_to_firms();
void set_austerity_phase(int austerity_phase);
int get_austerity_phase();
void set_foreign_debt(double foreign_debt);
double get_foreign_debt();
void set_add_foreign_debt(double add_foreign_debt);
double get_add_foreign_debt();
void set_foreign_debt_installment(double foreign_debt_installment);
double get_foreign_debt_installment();
void set_monthly_investment_expenditure(double monthly_investment_expenditure);
double get_monthly_investment_expenditure();
void set_monthly_budget_balance(double monthly_budget_balance);
double get_monthly_budget_balance();
void set_monthly_gdp(double monthly_gdp);
double get_monthly_gdp();
double_array * get_last_monthly_gdps();
void set_monthly_budget_balance_gdp_fraction(double monthly_budget_balance_gdp_fraction);
double get_monthly_budget_balance_gdp_fraction();
void set_monthly_consumption_budget(double monthly_consumption_budget);
double get_monthly_consumption_budget();
void set_monthly_investment_budget(double monthly_investment_budget);
double get_monthly_investment_budget();
void set_monthly_income(double monthly_income);
double get_monthly_income();
void set_monthly_expenditure(double monthly_expenditure);
double get_monthly_expenditure();
void set_yearly_subsidy_payment(double yearly_subsidy_payment);
double get_yearly_subsidy_payment();
void set_yearly_bond_interest_payment(double yearly_bond_interest_payment);
double get_yearly_bond_interest_payment();
void set_yearly_investment_expenditure(double yearly_investment_expenditure);
double get_yearly_investment_expenditure();
void set_yearly_consumption_expenditure(double yearly_consumption_expenditure);
double get_yearly_consumption_expenditure();
void set_yearly_income(double yearly_income);
double get_yearly_income();
void set_yearly_expenditure(double yearly_expenditure);
double get_yearly_expenditure();
void set_subsidy_transfer_received(double subsidy_transfer_received);
double get_subsidy_transfer_received();
void set_yearly_budget_balance(double yearly_budget_balance);
double get_yearly_budget_balance();
void set_total_money_financing(double total_money_financing);
double get_total_money_financing();
void set_total_bond_financing(double total_bond_financing);
double get_total_bond_financing();
void set_country_wide_mean_wage(double country_wide_mean_wage);
double get_country_wide_mean_wage();
void set_num_unemployed(int num_unemployed);
int get_num_unemployed();
void set_yearly_gdp(double yearly_gdp);
double get_yearly_gdp();
void set_previous_year_gdp(double previous_year_gdp);
double get_previous_year_gdp();
void set_subsidy_reported_to_eurostat(double subsidy_reported_to_eurostat);
double get_subsidy_reported_to_eurostat();
void set_gdp_growth(double gdp_growth);
double get_gdp_growth();
void set_gdp_forecast(double gdp_forecast);
double get_gdp_forecast();
void set_yearly_income_forecast(double yearly_income_forecast);
double get_yearly_income_forecast();
void set_yearly_expenditure_budget(double yearly_expenditure_budget);
double get_yearly_expenditure_budget();
void set_budget_balance_forecast(double budget_balance_forecast);
double get_budget_balance_forecast();
ordered_quantity_array * get_ordered_quantities();
received_quantities_array * get_gov_received_quantities();
double_array * get_consumption_budgets_per_capita();
void set_av_consumption_budget_per_capita(double av_consumption_budget_per_capita);
double get_av_consumption_budget_per_capita();
double_array * get_consumption_quotas_rel_to_reg1();
void set_av_consumption_quota_rel_to_reg1(double av_consumption_quota_rel_to_reg1);
double get_av_consumption_quota_rel_to_reg1();
void set_yearly_consumption_budget(double yearly_consumption_budget);
double get_yearly_consumption_budget();
void set_yearly_investment_budget(double yearly_investment_budget);
double get_yearly_investment_budget();
void set_yearly_budget_balance_gdp_fraction(double yearly_budget_balance_gdp_fraction);
double get_yearly_budget_balance_gdp_fraction();
void set_cumulated_deficit(double cumulated_deficit);
double get_cumulated_deficit();
void set_inflation_rate(double inflation_rate);
double get_inflation_rate();
void set_human_capital_policy_installation_date_in_years(int human_capital_policy_installation_date_in_years);
int get_human_capital_policy_installation_date_in_years();
void set_basic_security_benefits_pct(double basic_security_benefits_pct);
double get_basic_security_benefits_pct();
adt_skill_distribution_array * get_new_skill_distribution();
gov_balance_sheet_adt * get_gov_balance_sheet_calendar();
gov_stocks_adt * get_gov_stocks_calendar();
gov_outflows_adt * get_gov_outflows_calendar();
gov_inflows_adt * get_gov_inflows_calendar();
void set_fiat_money(double fiat_money);
double get_fiat_money();
void set_fiat_money_banks(double fiat_money_banks);
double get_fiat_money_banks();
void set_ecb_deposits(double ecb_deposits);
double get_ecb_deposits();
account_item_array * get_accounts_banks();
account_item_array * get_accounts_govs();
account_item_array * get_government_national_accounts();
ecb_balance_sheet_adt * get_ecb_balance_sheet_calendar();
ecb_stocks_adt * get_ecb_stocks_calendar();
ecb_outflows_adt * get_ecb_outflows_calendar();
ecb_inflows_adt * get_ecb_inflows_calendar();
void set_bond_holdings_value(double bond_holdings_value);
double get_bond_holdings_value();
void set_nr_gov_bonds(int nr_gov_bonds);
int get_nr_gov_bonds();
void set_fiat_money_govs(double fiat_money_govs);
double get_fiat_money_govs();
void set_fiat_money_bond_govs(double fiat_money_bond_govs);
double get_fiat_money_bond_govs();
void set_bank_interest(double bank_interest);
double get_bank_interest();
void set_gov_interest(double gov_interest);
double get_gov_interest();
void set_gov_bond_purchase(double gov_bond_purchase);
double get_gov_bond_purchase();
order_array * get_pending_orders();
order_array * get_processed_orders();
index_adt * get_stock_index();
void set_dsratio(double dsratio);
double get_dsratio();
double_array * get_random_numbers_normal();
void set_monthly_counter_total_dividend(double monthly_counter_total_dividend);
double get_monthly_counter_total_dividend();
void set_stock_index_price(double stock_index_price);
double get_stock_index_price();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[], int partitions, int partition_method);

/* messageboard.c */
m_bank_account_update * get_next_message_bank_account_update_in_range(m_bank_account_update * current);
m_bank_to_central_bank_account_update * get_next_message_bank_to_central_bank_account_update_in_range(m_bank_to_central_bank_account_update * current);
m_gov_to_central_bank_account_update * get_next_message_gov_to_central_bank_account_update_in_range(m_gov_to_central_bank_account_update * current);
m_wage_payment * get_next_message_wage_payment_in_range(m_wage_payment * current);
m_quality_price_info_1 * get_next_message_quality_price_info_1_in_range(m_quality_price_info_1 * current);
m_quality_price_info_2 * get_next_message_quality_price_info_2_in_range(m_quality_price_info_2 * current);
m_update_mall_stock * get_next_message_update_mall_stock_in_range(m_update_mall_stock * current);
m_consumption_request_1 * get_next_message_consumption_request_1_in_range(m_consumption_request_1 * current);
m_consumption_request_2 * get_next_message_consumption_request_2_in_range(m_consumption_request_2 * current);
m_accepted_consumption_1 * get_next_message_accepted_consumption_1_in_range(m_accepted_consumption_1 * current);
m_accepted_consumption_2 * get_next_message_accepted_consumption_2_in_range(m_accepted_consumption_2 * current);
m_sales * get_next_message_sales_in_range(m_sales * current);
m_specific_skill_update * get_next_message_specific_skill_update_in_range(m_specific_skill_update * current);
m_policy_rate * get_next_message_policy_rate_in_range(m_policy_rate * current);
m_bank_identity * get_next_message_bank_identity_in_range(m_bank_identity * current);
m_loan_request * get_next_message_loan_request_in_range(m_loan_request * current);
m_loan_request_ranked * get_next_message_loan_request_ranked_in_range(m_loan_request_ranked * current);
m_loan_conditions * get_next_message_loan_conditions_in_range(m_loan_conditions * current);
m_loan_acceptance * get_next_message_loan_acceptance_in_range(m_loan_acceptance * current);
m_installment * get_next_message_installment_in_range(m_installment * current);
m_bankruptcy * get_next_message_bankruptcy_in_range(m_bankruptcy * current);
m_bank_interest_payment * get_next_message_bank_interest_payment_in_range(m_bank_interest_payment * current);
m_account_interest * get_next_message_account_interest_in_range(m_account_interest * current);
m_ecb_dividend * get_next_message_ecb_dividend_in_range(m_ecb_dividend * current);
m_credit_var_update * get_next_message_credit_var_update_in_range(m_credit_var_update * current);
m_bankruptcy_illiquidity * get_next_message_bankruptcy_illiquidity_in_range(m_bankruptcy_illiquidity * current);
m_bankruptcy_insolvency * get_next_message_bankruptcy_insolvency_in_range(m_bankruptcy_insolvency * current);
m_index_info * get_next_message_index_info_in_range(m_index_info * current);
m_index_price * get_next_message_index_price_in_range(m_index_price * current);
m_order * get_next_message_order_in_range(m_order * current);
m_order_status * get_next_message_order_status_in_range(m_order_status * current);
m_dividend_info * get_next_message_dividend_info_in_range(m_dividend_info * current);
m_productivity * get_next_message_productivity_in_range(m_productivity * current);
m_capital_good_request * get_next_message_capital_good_request_in_range(m_capital_good_request * current);
m_capital_good_delivery * get_next_message_capital_good_delivery_in_range(m_capital_good_delivery * current);
m_pay_capital_goods * get_next_message_pay_capital_goods_in_range(m_pay_capital_goods * current);
m_vacancies * get_next_message_vacancies_in_range(m_vacancies * current);
m_vacancies2 * get_next_message_vacancies2_in_range(m_vacancies2 * current);
m_vacancies_r_and_d_employees * get_next_message_vacancies_r_and_d_employees_in_range(m_vacancies_r_and_d_employees * current);
m_vacancies_r_and_d_employees2 * get_next_message_vacancies_r_and_d_employees2_in_range(m_vacancies_r_and_d_employees2 * current);
m_firing * get_next_message_firing_in_range(m_firing * current);
m_job_application * get_next_message_job_application_in_range(m_job_application * current);
m_job_application2 * get_next_message_job_application2_in_range(m_job_application2 * current);
m_job_offer * get_next_message_job_offer_in_range(m_job_offer * current);
m_job_offer2 * get_next_message_job_offer2_in_range(m_job_offer2 * current);
m_job_acceptance * get_next_message_job_acceptance_in_range(m_job_acceptance * current);
m_job_acceptance2 * get_next_message_job_acceptance2_in_range(m_job_acceptance2 * current);
m_quitting * get_next_message_quitting_in_range(m_quitting * current);
m_quitting2 * get_next_message_quitting2_in_range(m_quitting2 * current);
m_unemployment_notification * get_next_message_unemployment_notification_in_range(m_unemployment_notification * current);
m_policy_announcement * get_next_message_policy_announcement_in_range(m_policy_announcement * current);
m_tax_payment * get_next_message_tax_payment_in_range(m_tax_payment * current);
m_unemployment_benefit_restitution * get_next_message_unemployment_benefit_restitution_in_range(m_unemployment_benefit_restitution * current);
m_hh_transfer_notification * get_next_message_hh_transfer_notification_in_range(m_hh_transfer_notification * current);
m_hh_subsidy_notification * get_next_message_hh_subsidy_notification_in_range(m_hh_subsidy_notification * current);
m_human_capital_policy_announcement * get_next_message_human_capital_policy_announcement_in_range(m_human_capital_policy_announcement * current);
m_firm_transfer_notification * get_next_message_firm_transfer_notification_in_range(m_firm_transfer_notification * current);
m_firm_subsidy_notification * get_next_message_firm_subsidy_notification_in_range(m_firm_subsidy_notification * current);
m_request_fiat_money * get_next_message_request_fiat_money_in_range(m_request_fiat_money * current);
m_human_capital_policy_general_skill_information * get_next_message_human_capital_policy_general_skill_information_in_range(m_human_capital_policy_general_skill_information * current);
m_human_capital_policy_new_general_skill_notification * get_next_message_human_capital_policy_new_general_skill_notification_in_range(m_human_capital_policy_new_general_skill_notification * current);
m_firm_send_data * get_next_message_firm_send_data_in_range(m_firm_send_data * current);
m_government_send_data * get_next_message_government_send_data_in_range(m_government_send_data * current);
m_household_send_data * get_next_message_household_send_data_in_range(m_household_send_data * current);
m_mall_data * get_next_message_mall_data_in_range(m_mall_data * current);
m_eurostat_send_specific_skills * get_next_message_eurostat_send_specific_skills_in_range(m_eurostat_send_specific_skills * current);
m_data_for_government * get_next_message_data_for_government_in_range(m_data_for_government * current);
m_eurostat_send_macrodata * get_next_message_eurostat_send_macrodata_in_range(m_eurostat_send_macrodata * current);
m_msg_firm_id_to_malls * get_next_message_msg_firm_id_to_malls_in_range(m_msg_firm_id_to_malls * current);
m_msg_mall_id_to_firms * get_next_message_msg_mall_id_to_firms_in_range(m_msg_mall_id_to_firms * current);
m_msg_skills_eurostat_to_igfirm * get_next_message_msg_skills_eurostat_to_igfirm_in_range(m_msg_skills_eurostat_to_igfirm * current);
m_msg_market_sizes * get_next_message_msg_market_sizes_in_range(m_msg_market_sizes * current);
m_total_subsidies * get_next_message_total_subsidies_in_range(m_total_subsidies * current);
m_redistributed_subsidies * get_next_message_redistributed_subsidies_in_range(m_redistributed_subsidies * current);
m_quality_price * get_next_message_quality_price_in_range(m_quality_price * current);
m_interview_request * get_next_message_interview_request_in_range(m_interview_request * current);
m_interview_positive_response * get_next_message_interview_positive_response_in_range(m_interview_positive_response * current);
m_questionnaire_innovation * get_next_message_questionnaire_innovation_in_range(m_questionnaire_innovation * current);
m_filled_out_questionnaire_product_innovation * get_next_message_filled_out_questionnaire_product_innovation_in_range(m_filled_out_questionnaire_product_innovation * current);

/* memory.c */
xmachine * add_xmachine(void);
int FLAME_get_environment_variable_total_regions();
int FLAME_get_environment_variable_id_debug_probe();
int FLAME_get_environment_variable_print_log();
int FLAME_get_environment_variable_print_debug_bankruptcy();
int FLAME_get_environment_variable_print_debug_eurostat();
int FLAME_get_environment_variable_print_debug_ch();
int FLAME_get_environment_variable_print_debug_afm();
int FLAME_get_environment_variable_print_debug_afm_ch();
int FLAME_get_environment_variable_print_debug_exp1();
int FLAME_get_environment_variable_print_debug_file_exp1();
int FLAME_get_environment_variable_print_debug_file_exp2();
int FLAME_get_environment_variable_policy_exp1();
int FLAME_get_environment_variable_print_debug_gov();
int FLAME_get_environment_variable_print_debug_household();
int FLAME_get_environment_variable_print_debug_credit();
int FLAME_get_environment_variable_print_debug_consumption();
int FLAME_get_environment_variable_print_debug_finman();
int FLAME_get_environment_variable_print_debug_production();
int FLAME_get_environment_variable_print_debug();
int FLAME_get_environment_variable_print_debug_market_research();
int FLAME_get_environment_variable_policy_exp_energy_shock();
int FLAME_get_environment_variable_policy_exp_stabilization_subsidy();
int FLAME_get_environment_variable_policy_exp_stabilization_tax();
int FLAME_get_environment_variable_const_bankruptcy_idle_period();
int FLAME_get_environment_variable_days_per_month();
int FLAME_get_environment_variable_xml_cloned();
int FLAME_get_environment_variable_individual_learning();
double FLAME_get_environment_variable_const_wage_wealth_ratio();
double FLAME_get_environment_variable_const_income_tax_rate();
double FLAME_get_environment_variable_gamma_const();
double FLAME_get_environment_variable_gamma_quality();
double FLAME_get_environment_variable_initial_price();
double FLAME_get_environment_variable_depreciation_rate();
double FLAME_get_environment_variable_discont_rate();
double FLAME_get_environment_variable_mark_up();
double FLAME_get_environment_variable_lambda();
double FLAME_get_environment_variable_target_savings_rate();
double FLAME_get_environment_variable_carrol_consumption_parameter();
double FLAME_get_environment_variable_quantil_normal_distribution();
int FLAME_get_environment_variable_firm_planning_horizon();
double FLAME_get_environment_variable_initial_stock_up();
int FLAME_get_environment_variable_initial_price_adjustment();
double FLAME_get_environment_variable_adaption_delivery_volume();
double FLAME_get_environment_variable_inv_inertia();
int FLAME_get_environment_variable_planning_horizon_vintage_choice();
double FLAME_get_environment_variable_gamma_logit_vintage_choice();
double FLAME_get_environment_variable_delta_logit_vintage_choice();
int FLAME_get_environment_variable_number_of_banks_to_apply();
int FLAME_get_environment_variable_const_number_of_banks();
int FLAME_get_environment_variable_const_installment_periods();
double FLAME_get_environment_variable_bank_lambda();
double FLAME_get_environment_variable_ecb_interest_rate();
double FLAME_get_environment_variable_ecb_interest_rate_markdown();
double FLAME_get_environment_variable_alfa();
double FLAME_get_environment_variable_min_cash_reserve_ratio();
double FLAME_get_environment_variable_const_firm_leverage();
double FLAME_get_environment_variable_debt_rescaling_factor();
double FLAME_get_environment_variable_target_leverage_ratio();
double FLAME_get_environment_variable_target_liquidity_ratio();
double FLAME_get_environment_variable_const_dividend_earnings_ratio();
double FLAME_get_environment_variable_const_dividend_treshold_full_payout();
int FLAME_get_environment_variable_igfirm_dividend_payout_stretching_month();
double FLAME_get_environment_variable_index_price_adj();
double FLAME_get_environment_variable_index_price_adj_max();
double FLAME_get_environment_variable_index_price_adj_min();
int FLAME_get_environment_variable_trading_activity();
int FLAME_get_environment_variable_trading_random();
int FLAME_get_environment_variable_igfirm_fin_man_debug();
double FLAME_get_environment_variable_const_igfirm_dividend_target_pct();
double FLAME_get_environment_variable_const_igfirm_dividend_adjustment_parameter();
int FLAME_get_environment_variable_switch_igfirm_endogenous_innovation_probability();
double FLAME_get_environment_variable_igfirm_exogenous_innovation_probability();
double FLAME_get_environment_variable_power_of_end_probability_function();
int FLAME_get_environment_variable_igfirm_producer_debug();
double FLAME_get_environment_variable_igfirm_exogenous_productivity_progress();
int FLAME_get_environment_variable_symmetric_shock();
int FLAME_get_environment_variable_energy_shock_start();
int FLAME_get_environment_variable_energy_shock_end();
double FLAME_get_environment_variable_const_energy_shock_intensity();
int FLAME_get_environment_variable_energy_shock_frequency();
int FLAME_get_environment_variable_transition_phase();
int FLAME_get_environment_variable_innovation_by_random();
int FLAME_get_environment_variable_ig_good_limited_offer();
int FLAME_get_environment_variable_max_offer_ig_good();
double FLAME_get_environment_variable_initial_frontier_firm_transition_phase();
double FLAME_get_environment_variable_initial_productivity_firm();
double FLAME_get_environment_variable_initial_specific_skills();
int FLAME_get_environment_variable_strenght_of_tech_progress();
double FLAME_get_environment_variable_linear_combination_pricing_ig_good();
double FLAME_get_environment_variable_initial_capital_price_wage_ratio();
double FLAME_get_environment_variable_union_strength();
int FLAME_get_environment_variable_reg_diff_union_strength();
double FLAME_get_environment_variable_reg2_factor_union_strength();
double FLAME_get_environment_variable_wage_update();
int FLAME_get_environment_variable_min_vacancy();
double FLAME_get_environment_variable_wage_reservation_update();
double FLAME_get_environment_variable_region_cost();
double FLAME_get_environment_variable_delivery_prob_if_critical_stock_0();
int FLAME_get_environment_variable_labormarket_scenario_reg2();
int FLAME_get_environment_variable_number_applications();
int FLAME_get_environment_variable_applications_per_day();
int FLAME_get_environment_variable_lower_bound_firing();
int FLAME_get_environment_variable_upper_bound_firing();
double FLAME_get_environment_variable_logit_parameter_specific_skills();
double FLAME_get_environment_variable_logit_parameter_worker_preselection();
double FLAME_get_environment_variable_logit_parameter_general_skills();
int FLAME_get_environment_variable_skill_update_acc_to_formula();
int FLAME_get_environment_variable_rnd_seed();
double FLAME_get_environment_variable_gov_policy_unemployment_benefit_pct();
double FLAME_get_environment_variable_gamma_gov();
int FLAME_get_environment_variable_joe_scenario();
int FLAME_get_environment_variable_gov_expenditures_and_unemp_benefits_redistributed();
double FLAME_get_environment_variable_gov_policy_money_financing_fraction();
int FLAME_get_environment_variable_adaptive_tax_rates();
int FLAME_get_environment_variable_gov_2_relaxed_budget_rule();
double FLAME_get_environment_variable_gov_2_expenditures_covered();
double FLAME_get_environment_variable_gov_2_consumption_ratio();
int FLAME_get_environment_variable_gov_regional_consumption_scenario();
double FLAME_get_environment_variable_reg2_markup_factor();
int FLAME_get_environment_variable_migration_region_id();
double FLAME_get_environment_variable_migration_allocation_quota();
int FLAME_get_environment_variable_migration_allocation_policy();
int FLAME_get_environment_variable_migration_experiment();
int FLAME_get_environment_variable_minimum_wage_policy();
double FLAME_get_environment_variable_minimum_wage_policy_target_minimum_wage();
int FLAME_get_environment_variable_policy_migration_top_up_benefits();
int FLAME_get_environment_variable_policy_migration_wage_subsidies();
int FLAME_get_environment_variable_policy_migration_wage_subsidies_targeted();
double FLAME_get_environment_variable_migration_top_up_benefit();
int FLAME_get_environment_variable_migration_date();
double FLAME_get_environment_variable_gov_policy_gdp_fraction_consumption();
int FLAME_get_environment_variable_exp_firm_subsidy_scenario();
int FLAME_get_environment_variable_austerity_policy();
int FLAME_get_environment_variable_austerity_policy_scenario();
int FLAME_get_environment_variable_austerity_repay_scenario();
double FLAME_get_environment_variable_austerity_consumption_threshold();
double FLAME_get_environment_variable_austerity_debt_threshold();
int FLAME_get_environment_variable_austerity_repayment_period();
double FLAME_get_environment_variable_gov_policy_gdp_fraction_investment();
int FLAME_get_environment_variable_no_regions_per_gov();
int FLAME_get_environment_variable_flexibility_policy();
int FLAME_get_environment_variable_gov_budgeting_horizon();
double FLAME_get_environment_variable_subsidy_trigger_on();
double FLAME_get_environment_variable_subsidy_trigger_off();
int FLAME_get_environment_variable_policy_starting_at_iteration();
int FLAME_get_environment_variable_gov_policy_swith_quantitative_easing();
int FLAME_get_environment_variable_gov_policy_switch_human_capital_improvement();
int FLAME_get_environment_variable_subsidy_redistribution();
int FLAME_get_environment_variable_tech_policy_effectiveness_switch();
double FLAME_get_environment_variable_probability_tech_policy_effectiveness();
int FLAME_get_environment_variable_policy_exp_best_technology_subsidy();
double FLAME_get_environment_variable_subsidy_redistribution_parameter();
int FLAME_get_environment_variable_policy_exp_all_technologies_subsidy();
int FLAME_get_environment_variable_regional_policy_technology_subsidy();
double FLAME_get_environment_variable_best_technology_subsidy_pct();
int FLAME_get_environment_variable_innovation_switched_on();
double FLAME_get_environment_variable_mr_start_price();
double FLAME_get_environment_variable_mr_end_price();
double FLAME_get_environment_variable_mr_price_increment();
int FLAME_get_environment_variable_max_no_employees_product_innovation();


/* rules.c */
int FLAME_integer_in_array(int a, int * b, int size);

/* timing.c */
double get_time(void);

int Firm_calc_production_quantity(void);
int FLAME_condition_Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01(xmachine_memory_Firm *a);
int Firm_set_quantities_zero(void);
int FLAME_condition_Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b(xmachine_memory_Firm *a);
int Firm_calc_input_demands(void);
int FLAME_sort_Firm_Firm_calc_input_demands_01_02_productivity();
int Firm_calc_production_quantity_2(void);
int Firm_send_capital_demand(void);
int Firm_receive_capital_goods(void);
int FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery(const void *msg, const void *params);
int Firm_execute_production(void);
int Firm_calc_pay_costs(void);
int Firm_send_goods_to_mall(void);
int Firm_calc_revenue(void);
int FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales(const void *msg, const void *params);

int FLAME_condition_Firm_idle_14_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a);
int Firm_compute_sales_statistics(void);
int FLAME_condition_Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a);
int Firm_update_specific_skills_of_workers(void);
int FLAME_condition_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14(xmachine_memory_Firm *a);
int FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update(const void *msg, const void *params);

int FLAME_condition_Firm_idle_Firm_End_Seller_Role_14(xmachine_memory_Firm *a);
int Firm_receive_account_interest(void);
int Firm_ask_loan(void);
int FLAME_condition_Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02(xmachine_memory_Firm *a);
int Firm_get_loan(void);
int FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions(const void *msg, const void *params);
int FLAME_sort_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions();
int Firm_compute_financial_payments(void);
int Firm_compute_income_statement(void);
int Firm_compute_dividends(void);
int Firm_compute_total_financial_payments(void);
int Firm_compute_balance_sheet(void);
int Firm_set_bankruptcy_insolvency(void);
int FLAME_condition_Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_variables_reset(xmachine_memory_Firm *a);
int Firm_bankruptcy_reset_immediately(void);

int FLAME_condition_Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a);
int Firm_compute_total_liquidity_needs(void);
int Firm_check_financial_and_bankruptcy_state(void);
int FLAME_condition_Firm_Firm_check_financial_and_bankruptcy_state_Firm_End_Credit_Role_Firm_bankruptcy_checked(xmachine_memory_Firm *a);
int Firm_set_bankruptcy_illiquidity(void);
int FLAME_condition_Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_variables_reset2(xmachine_memory_Firm *a);
int Firm_bankruptcy_reset_immediately(void);
int Firm_set_minsky_state_crisis(void);
int FLAME_condition_Firm_Firm_set_minsky_state_crisis_Firm_checks_financial_crisis_Firm_resolve_financial_crisis(xmachine_memory_Firm *a);
int Firm_in_financial_crisis(void);
int Firm_not_in_bankruptcy(void);
int FLAME_condition_Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a);
int Firm_execute_financial_payments(void);
int Firm_send_subsidy_notification(void);
int Firm_send_transfer_notification(void);
int Firm_bankruptcy_generic_procedure(void);
int FLAME_condition_Firm_Firm_bankruptcy_generic_procedure_Firm_not_active_Firm_bankruptcy_state_0(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_not_active_Firm_bankruptcy_state_0(xmachine_memory_Firm *a);
int Firm_bankruptcy_rescale_loans(void);
int Firm_bankruptcy_reset_delayed(void);
int FLAME_condition_Firm_Firm_bankruptcy_reset_delayed_Firm_bankruptcy_state_01_Firm_bankruptcy_state_1(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_bankruptcy_state_01_Firm_bankruptcy_state_1(xmachine_memory_Firm *a);
int Firm_bankruptcy_idle_counter(void);
int FLAME_condition_Firm_Firm_bankruptcy_idle_counter_Firm_checks_if_active_Firm_not_active(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_checks_if_active_Firm_is_active(xmachine_memory_Firm *a);
int Firm_remains_in_bankruptcy(void);
int FLAME_condition_Firm_Firm_remains_in_bankruptcy_Firm_bankruptcy_state_1_Firm_bankruptcy_state_4(xmachine_memory_Firm *a);
int Firm_reset_bankruptcy_flags(void);
int FLAME_condition_Firm_Firm_reset_bankruptcy_flags_Firm_bankruptcy_state_4_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_bankruptcy_state_4_Firm_End_Branches(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_bankruptcy_state_1_Firm_bankruptcy_state_4(xmachine_memory_Firm *a);
int Firm_check_minsky_class(void);
int Firm_set_minsky_state_bankruptcy(void);
int Firm_set_labour_market_actions(void);
int Firm_calculate_specific_skills_and_wage_offer(void);
int Firm_send_vacancies(void);
int FLAME_condition_Firm_Firm_send_vacancies_04ccc_03(xmachine_memory_Firm *a);
int Firm_send_redundancies(void);
int FLAME_condition_Firm_Firm_send_redundancies_011_03ccc(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_011_03ccc(xmachine_memory_Firm *a);
int Firm_read_job_applications_send_job_offer_or_rejection(void);
int FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_03_04_job_application(const void *msg, const void *params);
int Firm_read_job_responses(void);
int FLAME_filter_Firm_Firm_read_job_responses_04_05a_job_acceptance(const void *msg, const void *params);
int Firm_read_job_quitting(void);
int Firm_read_job_quitting(void);
int Firm_read_job_quitting(void);
int Firm_start_labour_market(void);
int Firm_finish_labour_market_first_round(void);
int FLAME_condition_Firm_Firm_finish_labour_market_first_round_05b_09a(xmachine_memory_Firm *a);
int Firm_update_wage_offer(void);
int FLAME_condition_Firm_Firm_update_wage_offer_05b_06(xmachine_memory_Firm *a);
int Firm_send_vacancies_2(void);
int Firm_read_job_applications_send_job_offer_or_rejection_2(void);
int FLAME_filter_Firm_Firm_read_job_applications_send_job_offer_or_rejection_2_07_08_job_application2(const void *msg, const void *params);
int Firm_read_job_responses_2(void);
int FLAME_filter_Firm_Firm_read_job_responses_2_08_09a_job_acceptance2(const void *msg, const void *params);
int Firm_read_job_quitting_2(void);
int Firm_read_job_quitting_2(void);
int Firm_update_wage_offer_2(void);
int FLAME_condition_Firm_Firm_update_wage_offer_2_09b_10(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_09b_10(xmachine_memory_Firm *a);
int Firm_compute_mean_wage_specific_skills(void);
int Firm_send_random_redundancies(void);

int FLAME_condition_Firm_idle_04ccc_03c(xmachine_memory_Firm *a);
int Firm_send_id_to_malls(void);
int FLAME_condition_Firm_Firm_send_id_to_malls_start_Firm_Firm_initialize(xmachine_memory_Firm *a);
int Firm_initialize_mall_arrays(void);

int FLAME_condition_Firm_idle_start_Firm_Firm_reset(xmachine_memory_Firm *a);
int Firm_reset_variables(void);
int FLAME_condition_Firm_Firm_reset_variables_Firm_reset_Firm_init_01(xmachine_memory_Firm *a);

int FLAME_condition_Firm_idle_Firm_reset_Firm_interest(xmachine_memory_Firm *a);
int Firm_receive_data(void);
int FLAME_condition_Firm_Firm_receive_data_Firm_init_01_Firm_interest(xmachine_memory_Firm *a);
int FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_eurostat_send_specific_skills(const void *msg, const void *params);
int FLAME_filter_Firm_Firm_receive_data_Firm_init_01_Firm_interest_policy_announcement(const void *msg, const void *params);


int Firm_send_data_to_Eurostat(void);
int FLAME_condition_Firm_Firm_send_data_to_Eurostat_Firm_End_Branches_Firm_Send_Data(xmachine_memory_Firm *a);
int Firm_compute_stock_flows(void);

int FLAME_condition_Firm_idle_Firm_End_Branches_15(xmachine_memory_Firm *a);
int Firm_send_payments_to_bank(void);
int Firm_draw_sample(void);
int Firm_send_questionnaire(void);
int FLAME_filter_Firm_Firm_send_questionnaire_MR_1_MR_2_interview_positive_response(const void *msg, const void *params);
int Firm_analyze_questionnaire(void);
int FLAME_condition_Firm_Firm_analyze_questionnaire_MR_3_MR_4(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_MR_3_MR_4(xmachine_memory_Firm *a);
int Firm_prepone_vintage_choice(void);
int FLAME_condition_Firm_Firm_prepone_vintage_choice_MR_4_MR_4a(xmachine_memory_Firm *a);
int Firm_set_price(void);
int Firm_decide_product_innovation(void);
int FLAME_condition_Firm_Firm_decide_product_innovation_MR_5_MR_6(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_MR_5_MR_6(xmachine_memory_Firm *a);
int Firm_clean_up_arrays(void);
int Firm_set_market_research_data_pricing(void);
int FLAME_condition_Firm_Firm_set_market_research_data_pricing_MR_02_MR_03(xmachine_memory_Firm *a);
int Firm_bypass_setting_if_delayed(void);
int FLAME_condition_Firm_Firm_bypass_setting_if_delayed_MR_02_MR_0(xmachine_memory_Firm *a);
int Firm_set_market_research_data_innovation(void);
int FLAME_condition_Firm_Firm_set_market_research_data_innovation_MR_03_MR_0(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_MR_03_MR_0(xmachine_memory_Firm *a);
int Firm_release_new_product(void);
int FLAME_condition_Firm_Firm_release_new_product_MR_01_MR_02(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_Firm_Start_Market_Research_Role_MR_3(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_Firm_Start_Market_Research_Role_MR_01(xmachine_memory_Firm *a);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_MR_01_MR_02(xmachine_memory_Firm *a);
int Firm_count_questionnaire(void);
int FLAME_filter_Firm_Firm_count_questionnaire_MR_2_MR_3_filled_out_questionnaire_product_innovation(const void *msg, const void *params);
int Firm_idle(void);
int FLAME_condition_Firm_Firm_idle_MR_4_Firm_Start_Producer_Role(xmachine_memory_Firm *a);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_09_15(xmachine_memory_Household *a);
int Household_rank_and_buy_goods_1(void);
int FLAME_condition_Household_Household_rank_and_buy_goods_1_09_10(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_rank_and_buy_goods_1_09_10_quality_price_info_1(const void *msg, const void *params);
int Household_receive_goods_read_rationing(void);
int FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1(const void *msg, const void *params);
int Household_set_values_zero(void);
int FLAME_condition_Household_Household_set_values_zero_11_14(xmachine_memory_Household *a);
int Household_rank_and_buy_goods_2(void);
int FLAME_condition_Household_Household_rank_and_buy_goods_2_11_12(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2(const void *msg, const void *params);
int Household_receive_goods_read_rationing_2(void);
int FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2(const void *msg, const void *params);
int Household_handle_leftover_budget(void);
int Household_send_account_update(void);
int Household_receive_index_info(void);
int FLAME_condition_Household_Household_receive_index_info_Household_Start_Financial_Market_Role_AFM_000(xmachine_memory_Household *a);

int FLAME_condition_Household_idle_Household_Start_Financial_Market_Role_AFM_000(xmachine_memory_Household *a);
int Household_receive_index_price(void);
int FLAME_condition_Household_Household_receive_index_price_AFM_000_AFM_001(xmachine_memory_Household *a);
int Household_revises_expected_portfolio(void);
int Household_update_portfolio(void);
int FLAME_filter_Household_Household_update_portfolio_AFM_002_Household_Start_Labour_Role_order_status(const void *msg, const void *params);

int FLAME_condition_Household_idle_AFM_000_Household_Start_Labour_Role(xmachine_memory_Household *a);
int Household_read_firing_messages(void);
int FLAME_condition_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing(const void *msg, const void *params);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_01d_01a(xmachine_memory_Household *a);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_Household_Start_Labour_Role_01a(xmachine_memory_Household *a);
int Household_UNEMPLOYED_read_job_vacancies_and_send_applications(void);
int FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_01a_01_vacancies_r_and_d_employees(const void *msg, const void *params);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_01d_06(xmachine_memory_Household *a);
int Household_read_job_offers_send_response(void);
int FLAME_filter_Household_Household_read_job_offers_send_response_01_02_job_offer(const void *msg, const void *params);
int Household_finish_labour_market(void);
int FLAME_condition_Household_Household_finish_labour_market_02_06(xmachine_memory_Household *a);
int Household_read_application_rejection_update_wage_reservation(void);
int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_02_03(xmachine_memory_Household *a);
int Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2(void);
int FLAME_filter_Household_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2_03_04_vacancies_r_and_d_employees2(const void *msg, const void *params);
int Household_read_job_offers_send_response_2(void);
int FLAME_filter_Household_Household_read_job_offers_send_response_2_04_05_job_offer2(const void *msg, const void *params);
int Household_read_application_rejection_update_wage_reservation_2(void);
int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_2_05_06(xmachine_memory_Household *a);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_05_06(xmachine_memory_Household *a);
int Household_receive_dividends_dummy(void);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_06b_09(xmachine_memory_Household *a);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_06b_06c(xmachine_memory_Household *a);
int Household_send_subsidy_notification(void);
int Household_send_transfer_notification(void);
int Household_receive_wage(void);
int FLAME_condition_Household_Household_receive_wage_06e_07(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment(const void *msg, const void *params);
int Household_update_specific_skills(void);
int Household_send_unemployment_benefit_notification(void);
int FLAME_condition_Household_Household_send_unemployment_benefit_notification_06e_08(xmachine_memory_Household *a);
int Household_send_tax_payment(void);
int Household_determine_consumption_budget(void);
int Household_reset_variables(void);
int FLAME_condition_Household_Household_reset_variables_start_Household_Household_initialize(xmachine_memory_Household *a);

int FLAME_condition_Household_idle_start_Household_Household_initialize(xmachine_memory_Household *a);
int Household_initialization(void);
int FLAME_condition_Household_Household_initialization_Household_initialize_Household_Start_Yearly_Loop_Top(xmachine_memory_Household *a);

int FLAME_condition_Household_idle_Household_initialize_Household_Start_Yearly_Loop_Top(xmachine_memory_Household *a);
int Household_read_policy_announcements(void);
int FLAME_condition_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_policy_announcement(const void *msg, const void *params);
int FLAME_filter_Household_Household_read_policy_announcements_Household_Start_Yearly_Loop_Top_Pol_01_human_capital_policy_announcement(const void *msg, const void *params);
int Household_human_capital_policy(void);
int FLAME_condition_Household_Household_human_capital_policy_Pol_01_Household_Start_Policy_Data(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_human_capital_policy_Pol_01_Household_Start_Policy_Data_human_capital_policy_new_general_skill_notification(const void *msg, const void *params);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_Pol_01_Household_Start_Policy_Data(xmachine_memory_Household *a);

int FLAME_condition_Household_idle_Household_Start_Yearly_Loop_Top_Household_Start_Policy_Data(xmachine_memory_Household *a);
int Household_receive_account_interest(void);
int Household_send_data_to_Eurostat(void);
int FLAME_condition_Household_Household_send_data_to_Eurostat_16_17(xmachine_memory_Household *a);

int FLAME_condition_Household_idle_16_17(xmachine_memory_Household *a);

int FLAME_condition_Household_idle_17_end_Household(xmachine_memory_Household *a);
int Household_read_data_from_Eurostat(void);
int FLAME_condition_Household_Household_read_data_from_Eurostat_17_end_Household(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_read_data_from_Eurostat_17_end_Household_data_for_government(const void *msg, const void *params);
int Household_decide_to_attend_interview(void);
int Household_idle(void);
int FLAME_condition_Household_Household_idle_HH_MR_1_Household_Start_Financial_Market_Role(xmachine_memory_Household *a);
int Household_respond(void);
int FLAME_condition_Household_Household_respond_HH_MR_1_HH_MR_2(xmachine_memory_Household *a);
int FLAME_filter_Household_Household_respond_HH_MR_1_HH_MR_2_interview_request(const void *msg, const void *params);
int Household_respond_questionnaire(void);
int FLAME_filter_Household_Household_respond_questionnaire_HH_MR_2_Household_Start_Financial_Market_Role_questionnaire_innovation(const void *msg, const void *params);
int Mall_reset_export_data(void);
int FLAME_condition_Mall_Mall_reset_export_data_001_01(xmachine_memory_Mall *a);

int FLAME_condition_Mall_idle_001_01(xmachine_memory_Mall *a);
int Mall_update_mall_stock(void);
int Mall_send_quality_price_info_1(void);
int Mall_update_mall_stocks_sales_rationing_1(void);
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1(const void *msg, const void *params);
int Mall_update_mall_stocks_sales_rationing_2(void);
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2(const void *msg, const void *params);
int Mall_pay_firm(void);
int Mall_send_export_data(void);
int FLAME_condition_Mall_Mall_send_export_data_06_end_Mall(xmachine_memory_Mall *a);

int FLAME_condition_Mall_idle_06_end_Mall(xmachine_memory_Mall *a);
int Mall_read_insolvency_bankruptcy(void);
int Mall_send_id_to_firms(void);
int FLAME_condition_Mall_Mall_send_id_to_firms_start_Mall_Mall_initialize(xmachine_memory_Mall *a);
int Mall_initialize_firm_arrays(void);

int FLAME_condition_Mall_idle_start_Mall_001(xmachine_memory_Mall *a);
int IGFirm_receive_account_interest(void);

int IGFirm_execute_financial_payments(void);
int FLAME_condition_IGFirm_IGFirm_execute_financial_payments_01kk_IGFirm_End_Financial_Management(xmachine_memory_IGFirm *a);
int IGFirm_idle(void);
int FLAME_condition_IGFirm_IGFirm_idle_IGFirm_Start_Financial_Management_Role_IGFirm_End_Financial_Management_Role(xmachine_memory_IGFirm *a);
int IGFirm_send_subsidy_notification(void);
int FLAME_condition_IGFirm_IGFirm_send_subsidy_notification_IGFirm_Start_Financial_Management_Role_05(xmachine_memory_IGFirm *a);
int IGFirm_send_transfer_notification(void);
int IGFirm_compute_income_statement(void);
int IGFirm_compute_dividends(void);
int IGFirm_compute_total_financial_payments(void);
int IGFirm_compute_balance_sheet(void);
int IGFirm_receive_stock_info_dummy(void);
int IGFirm_initialize_variables(void);
int FLAME_condition_IGFirm_IGFirm_initialize_variables_Start_IGFirm_Productivity_01a(xmachine_memory_IGFirm *a);

int FLAME_condition_IGFirm_idle_Start_IGFirm_Productivity_01a(xmachine_memory_IGFirm *a);
int IGFirm_innovation_process(void);
int FLAME_condition_IGFirm_IGFirm_innovation_process_01a_01(xmachine_memory_IGFirm *a);
int IGFirm_idle(void);
int FLAME_condition_IGFirm_IGFirm_idle_01a_01(xmachine_memory_IGFirm *a);
int IGFirm_set_price_send_info(void);
int IGFirm_idle(void);
int FLAME_condition_IGFirm_IGFirm_idle_01kk_02(xmachine_memory_IGFirm *a);
int IGFirm_receive_order_delivers_capital_goods(void);
int IGFirm_calc_revenue(void);
int IGFirm_reset_variables(void);
int FLAME_condition_IGFirm_IGFirm_reset_variables_IGFirm_start_IGFirm_init_01(xmachine_memory_IGFirm *a);

int FLAME_condition_IGFirm_idle_IGFirm_start_IGFirm_interest(xmachine_memory_IGFirm *a);
int IGFirm_receive_data(void);
int FLAME_condition_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest(xmachine_memory_IGFirm *a);
int FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_eurostat_send_specific_skills(const void *msg, const void *params);
int FLAME_filter_IGFirm_IGFirm_receive_data_IGFirm_init_01_IGFirm_interest_policy_announcement(const void *msg, const void *params);


int IGFirm_send_data_to_Eurostat(void);
int FLAME_condition_IGFirm_IGFirm_send_data_to_Eurostat_IGFirm_End_Branches_IGFirm_Send_Data(xmachine_memory_IGFirm *a);
int IGFirm_compute_stock_flows(void);

int FLAME_condition_IGFirm_idle_IGFirm_End_Branches_06(xmachine_memory_IGFirm *a);
int IGFirm_send_payments_to_bank(void);
int IGFirm_idle(void);
int Eurostat_send_data(void);
int FLAME_condition_Eurostat_Eurostat_send_data_00_01(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int FLAME_condition_Eurostat_Eurostat_idle_00_01(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int FLAME_condition_Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a);
int Eurostat_calculate_data(void);
int FLAME_condition_Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a);
int Eurostat_store_history_monthly(void);
int FLAME_condition_Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02(xmachine_memory_Eurostat *a);
int Eurostat_compute_growth_rates_monthly(void);
int Eurostat_idle(void);
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop(xmachine_memory_Eurostat *a);
int Eurostat_store_history_quarterly(void);
int FLAME_condition_Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04(xmachine_memory_Eurostat *a);
int Eurostat_compute_growth_rates_quarterly(void);
int Eurostat_measure_recession(void);
int Eurostat_idle(void);
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat(xmachine_memory_Eurostat *a);

int FLAME_condition_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat(xmachine_memory_Eurostat *a);
int Eurostat_initialization(void);
int FLAME_condition_Eurostat_Eurostat_initialization_start_Eurostat_00(xmachine_memory_Eurostat *a);

int FLAME_condition_Eurostat_idle_start_Eurostat_00(xmachine_memory_Eurostat *a);
int Bank_read_policy_rate(void);
int FLAME_condition_Bank_Bank_read_policy_rate_Bank_update_policy_rate_Bank_start_credit_market_role(xmachine_memory_Bank *a);

int FLAME_condition_Bank_idle_Bank_update_policy_rate_Bank_start_credit_market_role(xmachine_memory_Bank *a);
int Bank_communicate_identity(void);
int Bank_send_dividend_payment(void);
int FLAME_condition_Bank_Bank_send_dividend_payment_Bank_01_Bank_01b(xmachine_memory_Bank *a);
int Bank_set_quantities_zero(void);
int FLAME_condition_Bank_Bank_set_quantities_zero_Bank_01_Bank_01b(xmachine_memory_Bank *a);
int Bank_send_account_interest(void);
int Bank_rank_credit_requests(void);
int FLAME_condition_Bank_Bank_rank_credit_requests_Bank_02_Bank_021(xmachine_memory_Bank *a);
int FLAME_filter_Bank_Bank_rank_credit_requests_Bank_02_Bank_021_loan_request(const void *msg, const void *params);
int Bank_decide_credit_conditions(void);
int FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_021_Bank_03_loan_request_ranked(const void *msg, const void *params);
int FLAME_sort_Bank_Bank_decide_credit_conditions_Bank_021_Bank_03_loan_request_ranked();
int Bank_give_loan(void);
int FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance(const void *msg, const void *params);

int FLAME_condition_Bank_idle_Bank_02_Bank_04(xmachine_memory_Bank *a);
int Bank_receive_installment(void);
int Bank_account_update_deposits(void);
int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update(const void *msg, const void *params);
int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_credit_var_update(const void *msg, const void *params);
int Bank_accounting(void);
int FLAME_condition_Bank_Bank_accounting_Bank_06_Bank_07(xmachine_memory_Bank *a);
int Bank_idle(void);
int FLAME_condition_Bank_Bank_idle_Bank_06_Bank_07(xmachine_memory_Bank *a);
int Bank_update_ecb_account(void);
int Bank_stocks_and_flows(void);

int FLAME_condition_Bank_idle_start_Bank_Bank_update_policy_rate(xmachine_memory_Bank *a);
int Bank_read_policy_announcements(void);
int FLAME_condition_Bank_Bank_read_policy_announcements_start_Bank_Bank_reset(xmachine_memory_Bank *a);
int FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_reset_policy_announcement(const void *msg, const void *params);
int Bank_reset_variables(void);
int Government_bond_market_dummy(void);
int Government_initialization(void);
int FLAME_condition_Government_Government_initialization_start_Government_Government_Start_Monthly_Loop_Top(xmachine_memory_Government *a);

int FLAME_condition_Government_idle_start_Government_Government_Start_Monthly_Loop_Top(xmachine_memory_Government *a);
int Government_monthly_resetting(void);
int FLAME_condition_Government_Government_monthly_resetting_Government_Start_Monthly_Loop_Top_001(xmachine_memory_Government *a);
int Government_read_data_from_Eurostat(void);
int FLAME_filter_Government_Government_read_data_from_Eurostat_001_Government_Start_Yearly_Loop_Top_redistributed_subsidies(const void *msg, const void *params);

int FLAME_condition_Government_idle_Government_Start_Monthly_Loop_Top_Government_Start_Yearly_Loop_Top(xmachine_memory_Government *a);
int Government_set_policy(void);
int FLAME_condition_Government_Government_set_policy_Government_Start_Yearly_Loop_Top_002(xmachine_memory_Government *a);
int Government_send_policy_announcements(void);
int Government_install_human_capital_policy(void);
int FLAME_condition_Government_Government_install_human_capital_policy_003_003a(xmachine_memory_Government *a);
int FLAME_filter_Government_Government_install_human_capital_policy_003_003a_human_capital_policy_general_skill_information(const void *msg, const void *params);
int Government_idle(void);
int FLAME_condition_Government_Government_idle_003_003a(xmachine_memory_Government *a);
int Government_yearly_resetting(void);
int Government_migration(void);
int FLAME_condition_Government_Government_migration_003b_Gov_Start_Bond_Market(xmachine_memory_Government *a);

int FLAME_condition_Government_idle_003b_Gov_Start_Bond_Market(xmachine_memory_Government *a);

int FLAME_condition_Government_idle_Government_Start_Yearly_Loop_Top_003b(xmachine_memory_Government *a);

int FLAME_condition_Government_idle_Start_Gov_Consumer_Role_Gov_Cons_1(xmachine_memory_Government *a);
int Government_determine_consumption_budget(void);
int FLAME_condition_Government_Government_determine_consumption_budget_Start_Gov_Consumer_Role_Gov_Cons_1(xmachine_memory_Government *a);
int Government_rank_and_buy_goods_1(void);
int FLAME_filter_Government_Government_rank_and_buy_goods_1_Gov_Cons_1_Gov_Cons_2_quality_price_info_1(const void *msg, const void *params);
int Government_receive_goods_read_rationing(void);
int FLAME_filter_Government_Government_receive_goods_read_rationing_Gov_Cons_2_Gov_Cons_3_accepted_consumption_1(const void *msg, const void *params);
int Government_rank_and_buy_goods_2(void);
int FLAME_filter_Government_Government_rank_and_buy_goods_2_Gov_Cons_3_Gov_Cons_4_quality_price_info_2(const void *msg, const void *params);
int Government_receive_goods_read_rationing_2(void);
int FLAME_filter_Government_Government_receive_goods_read_rationing_2_Gov_Cons_4_Gov_Cons_5_accepted_consumption_2(const void *msg, const void *params);
int Government_handle_leftover_budget(void);
int Government_read_tax_payments(void);
int FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_tax_payment(const void *msg, const void *params);
int FLAME_filter_Government_Government_read_tax_payments_End_Gov_Consumer_Role_02_unemployment_benefit_restitution(const void *msg, const void *params);
int Government_read_subsidy_notifications(void);
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification(const void *msg, const void *params);
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification(const void *msg, const void *params);
int Government_read_transfer_notifications(void);
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification(const void *msg, const void *params);
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification(const void *msg, const void *params);
int Government_read_unemployment_benefit_notifications(void);
int FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_Gov_Start_Monthly_Loop_unemployment_notification(const void *msg, const void *params);

int FLAME_condition_Government_idle_Gov_Start_Monthly_Loop_06(xmachine_memory_Government *a);
int Government_resolve_unsold_bonds_dummy(void);
int FLAME_condition_Government_Government_resolve_unsold_bonds_dummy_Gov_Start_Monthly_Loop_05a(xmachine_memory_Government *a);
int Government_monthly_budget_accounting(void);
int Government_bonds_issuing_decision_dummy(void);
int FLAME_condition_Government_Government_bonds_issuing_decision_dummy_Gov_bonds_decision_06(xmachine_memory_Government *a);

int FLAME_condition_Government_idle_Gov_bonds_decision_06(xmachine_memory_Government *a);
int Government_send_account_update(void);
int Government_compute_balance_sheet(void);
int FLAME_filter_Government_Government_compute_balance_sheet_07_08_ecb_dividend(const void *msg, const void *params);
int Government_send_data_to_Eurostat(void);
int FLAME_condition_Government_Government_send_data_to_Eurostat_08_Gov_Start_Yearly_Loop(xmachine_memory_Government *a);

int FLAME_condition_Government_idle_08_Gov_Start_Yearly_Loop(xmachine_memory_Government *a);

int FLAME_condition_Government_idle_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a);
int Government_yearly_budget_accounting(void);
int FLAME_condition_Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a);
int Central_Bank_read_account_update(void);
int Central_Bank_reset_variables(void);
int FLAME_condition_CentralBank_Central_Bank_reset_variables_start_Central_Bank_CB_reset(xmachine_memory_CentralBank *a);
int Central_Bank_monetary_policy(void);
int FLAME_condition_CentralBank_Central_Bank_monetary_policy_CB_reset_CB_market_operations(xmachine_memory_CentralBank *a);

int FLAME_condition_CentralBank_idle_start_Central_Bank_CB_market_operations(xmachine_memory_CentralBank *a);
int Central_Bank_read_fiat_money_requests(void);
int FLAME_condition_CentralBank_Central_Bank_read_fiat_money_requests_CB_financial_operations_end_00(xmachine_memory_CentralBank *a);

int FLAME_condition_CentralBank_idle_CB_financial_operations_end_00(xmachine_memory_CentralBank *a);
int Central_Bank_dummy(void);
int ClearingHouse_send_index_info(void);
int FLAME_condition_ClearingHouse_ClearingHouse_send_index_info_start_Clearinghouse_AFM_00(xmachine_memory_ClearingHouse *a);

int FLAME_condition_ClearingHouse_idle_start_Clearinghouse_AFM_00(xmachine_memory_ClearingHouse *a);
int ClearingHouse_send_index_price(void);
int ClearingHouse_receive_orders(void);
int ClearingHouse_compute_transactions(void);
int ClearingHouse_send_transaction_info(void);
int ClearingHouse_receive_dividend_info(void);
int ClearingHouse_update_price(void);
#endif
