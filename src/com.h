/*============================
* created by Wen Huang
* introduction: h file for common types and functions
*
* date: 08.01.2023
*
*============================*/
#include <time.h>

typedef struct t_time
{
	time_t time;			//epoch time
	double fsec;			//float part of second
} t_time;