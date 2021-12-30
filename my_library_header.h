/**
 * \file  my_library_header.h
 * \brief Header for user created library functions.
 */

#define DAY iteration_loop
#define MONTH 20

int random_int(int min,int max);
double random_unif();
double random_unif_interval(double a, double b);
double max(double a, double b);
double min(double a, double b);
int round_double_to_int(double x);
double abs_double(double x);
double normal_distributed_double();
double price_of_vintage(int index, int subsidy_type, adt_technology_vintages_array vintages, double subsidy_pct,double frontier_productivity);
