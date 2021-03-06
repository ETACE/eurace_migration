/**
 * \file  my_library_functions.c
 * \brief Holds user created library functions.
 */
#include <gsl/gsl_rng.h>
#include "header.h"
#include "my_library_header.h"


extern gsl_rng * FLAME_GSL_RNG;  /* global GSL random generator */

int FLAME_GSL_GEN_NO;

/** \fn int random_int(int min,int max)
 * \brief Returns an integer between and including min and max
 * \param min The minimum integer.
 * \param max The maximum integer.
 * \return The random integer.
 */
int random_int(int min,int max)
{
FLAME_GSL_GEN_NO++;
	double random_number = gsl_rng_uniform(FLAME_GSL_RNG)*(max - min + 1) + min;
	return (int)random_number;
    //return min + rand() % (max - min + 1);
}

double max(double a, double b)
{
    return (a >= b) ? a : b; 
}

double min(double a, double b)
{
    return (a <= b) ? a : b; 
}


/** \fn double random_unif()
 * \brief Uniformly distributed random numbers, chosen from
 *   a uniform distribution on the closed interval (0.0,1.0).
 */
double random_unif()
{
	FLAME_GSL_GEN_NO++;

    return gsl_rng_uniform(FLAME_GSL_RNG);
    //return ((double)rand()/(double)RAND_MAX);
}

/** \fn double random_unif_interval(double a, double b)
 * \brief Uniformly distributed random numbers, chosen from
 *   a uniform distribution on the closed interval (a,b).
 */
double random_unif_interval(double a, double b)
{
	return (a + (b-a)*random_unif());
}
/** \fn round_double_to_int(double x)
 * \brief Rounds a double to the closest integer.
 */
int round_double_to_int(double x)
{
  if(x>0) return (int)(x + 0.5);

  return (int)(x - 0.5);
}

double abs_double(double x)
{
  if(x<0) return ((-1)*x);

  return x;
}

/** \fn normal_distributed_double()
 * \brief returns a standard normal distributed random number (Polar method)
 */
double normal_distributed_double()
{
	double x_1,x_2;
	double q=1.1;	
	while(q>1-1e-6)
	{
	x_1 = random_unif_interval(0, 2) - 1;

	x_2 = random_unif_interval(0, 2) - 1;

	q = pow(x_1,2) + pow(x_2,2);
	}

	double p = pow(-2*log(q)/q,0.5)	;

	x_1 = p * x_1; 

	return x_1;

}



double price_of_vintage(int index, int subsidy_type, adt_technology_vintages_array vintages, double subsidy_pct,double frontier_productivity)
{

	double price;



	if(subsidy_type==1){

		if(fabs(frontier_productivity-vintages.array[index].productivity)<1e-5){

				price = vintages.array[index].price*(1-subsidy_pct);

		}else{

				price = vintages.array[index].price;
		}

	}else if(subsidy_type==2){

		price = vintages.array[index].price*(1-subsidy_pct);

	}else{

			price = vintages.array[index].price;
	}


	return price;

}
