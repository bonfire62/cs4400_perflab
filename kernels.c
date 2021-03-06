/*******************************************
 * Solutions for the CS:APP Performance Lab
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following student struct 
 */
student_t student = {
  "Kenneth Bonar",     /* Full name */
  "kenbonar@gmail.com",  /* Email address */

};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_pinwheel - The naive baseline version of pinwheel 
 */
char naive_pinwheel_descr[] = "naive_pinwheel: Naive baseline implementation";
void naive_pinwheel(int dim, pixel *src, pixel *dest)
{
  int i, j;

  int dim_div = dim/2;

  for (i = 0; i < dim_div; i+=16)
    for (j = 0; j < dim_div; j++){
      dest[RIDX(dim_div - 1 - j, i, dim)] = src[RIDX(i, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+1, dim)] = src[RIDX(i+1, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+2, dim)] = src[RIDX(i+2, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+3, dim)] = src[RIDX(i+3, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+4, dim)] = src[RIDX(i+4, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+5, dim)] = src[RIDX(i+5, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+6, dim)] = src[RIDX(i+6, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+7, dim)] = src[RIDX(i+7, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+8, dim)] = src[RIDX(i+8, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+9, dim)] = src[RIDX(i+9, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+10, dim)] = src[RIDX(i+10, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+11, dim)] = src[RIDX(i+11, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+12, dim)] = src[RIDX(i+12, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+13, dim)] = src[RIDX(i+13, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+14, dim)] = src[RIDX(i+14, j, dim)];
      dest[RIDX(dim_div - 1 - j, i+15, dim)] = src[RIDX(i+15, j, dim)];
    }
   
  for (i = 0; i < dim_div; i+=16)
    for (j = 0; j < dim_div; j++){
      dest[RIDX(dim_div - 1 - j, dim_div + i, dim)] = src[RIDX(i, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+1, dim)] = src[RIDX(i+1, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+2, dim)] = src[RIDX(i+2, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+3, dim)] = src[RIDX(i+3, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+4, dim)] = src[RIDX(i+4, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+5, dim)] = src[RIDX(i+5, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+6, dim)] = src[RIDX(i+6, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+7, dim)] = src[RIDX(i+7, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+8, dim)] = src[RIDX(i+8, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+9, dim)] = src[RIDX(i+9, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+10, dim)] = src[RIDX(i+10, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+11, dim)] = src[RIDX(i+11, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+12, dim)] = src[RIDX(i+12, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+13, dim)] = src[RIDX(i+13, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+14, dim)] = src[RIDX(i+14, dim_div + j, dim)];
      dest[RIDX(dim_div - 1 - j, dim_div + i+15, dim)] = src[RIDX(i+15, dim_div + j, dim)];
    }

  for (i = 0; i < dim_div; i+=16)
    for (j = 0; j < dim_div; j++){
      dest[RIDX(dim - 1 - j, i, dim)] = src[RIDX(dim_div + i, j, dim)];
      dest[RIDX(dim - 1 - j, i+1, dim)] = src[RIDX(dim_div + i+1, j, dim)];
      dest[RIDX(dim - 1 - j, i+2, dim)] = src[RIDX(dim_div + i+2, j, dim)];
      dest[RIDX(dim - 1 - j, i+3, dim)] = src[RIDX(dim_div + i+3, j, dim)];
      dest[RIDX(dim - 1 - j, i+4, dim)] = src[RIDX(dim_div + i+4, j, dim)];
      dest[RIDX(dim - 1 - j, i+5, dim)] = src[RIDX(dim_div + i+5, j, dim)];
      dest[RIDX(dim - 1 - j, i+6, dim)] = src[RIDX(dim_div + i+6, j, dim)];
      dest[RIDX(dim - 1 - j, i+7, dim)] = src[RIDX(dim_div + i+7, j, dim)];
      dest[RIDX(dim - 1 - j, i+8, dim)] = src[RIDX(dim_div + i+8, j, dim)];
      dest[RIDX(dim - 1 - j, i+9, dim)] = src[RIDX(dim_div + i+9, j, dim)];
      dest[RIDX(dim - 1 - j, i+10, dim)] = src[RIDX(dim_div + i+10, j, dim)];
      dest[RIDX(dim - 1 - j, i+11, dim)] = src[RIDX(dim_div + i+11, j, dim)];
      dest[RIDX(dim - 1 - j, i+12, dim)] = src[RIDX(dim_div + i+12, j, dim)];
      dest[RIDX(dim - 1 - j, i+13, dim)] = src[RIDX(dim_div + i+13, j, dim)];
      dest[RIDX(dim - 1 - j, i+14, dim)] = src[RIDX(dim_div + i+14, j, dim)];
      dest[RIDX(dim - 1 - j, i+15, dim)] = src[RIDX(dim_div + i+15, j, dim)];
    }

  for (i = 0; i < dim_div; i+=16)
    for (j = 0; j < dim_div; j++){
       dest[RIDX(dim - 1 - j, dim_div + i, dim)] = src[RIDX(dim_div + i, dim_div + j, dim)];  
       dest[RIDX(dim - 1 - j, dim_div + i+1, dim)] = src[RIDX(dim_div + i+1, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+2, dim)] = src[RIDX(dim_div + i+2, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+3, dim)] = src[RIDX(dim_div + i+3, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+4, dim)] = src[RIDX(dim_div + i+4, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+5, dim)] = src[RIDX(dim_div + i+5, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+6, dim)] = src[RIDX(dim_div + i+6, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+7, dim)] = src[RIDX(dim_div + i+7, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+8, dim)] = src[RIDX(dim_div + i+8, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+9, dim)] = src[RIDX(dim_div + i+9, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+10, dim)] = src[RIDX(dim_div + i+10, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+11, dim)] = src[RIDX(dim_div + i+11, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+12, dim)] = src[RIDX(dim_div + i+12, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+13, dim)] = src[RIDX(dim_div + i+13, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+14, dim)] = src[RIDX(dim_div + i+14, dim_div + j, dim)];
       dest[RIDX(dim - 1 - j, dim_div + i+15, dim)] = src[RIDX(dim_div + i+15, dim_div + j, dim)];
    }
}

/* 
 * rotate - Your current working version of pinwheel
 * IMPORTANT: This is the version you will be graded on
 */
char pinwheel_descr[] = "pinwheel: Current working version";
void pinwheel(int dim, pixel *src, pixel *dest)
{
  naive_pinwheel(dim, src, dest);
}

/*********************************************************************
 * register_pinwheel_functions - Register all of your different versions
 *     of the pinwheel kernel with the driver by calling the
 *     add_pinwheel_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_pinwheel_functions() {
  add_pinwheel_function(&pinwheel, pinwheel_descr);
  add_pinwheel_function(&naive_pinwheel, naive_pinwheel_descr);
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
  int red;
  int green;
  int blue;
} pixel_sum;

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
  sum->red = sum->green = sum->blue = 0;
  return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_weighted_sum(pixel_sum *sum, pixel p, double weight) 
{
  sum->red += (int) p.red * weight;
  sum->green += (int) p.green * weight;
  sum->blue += (int) p.blue * weight;
  return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
  current_pixel->red = (unsigned short)sum.red;
  current_pixel->green = (unsigned short)sum.green;
  current_pixel->blue = (unsigned short)sum.blue;
  return;
}

/* 
 * weighted_combo - Returns new pixel value at (i,j) 
 */


/******************************************************
 * Your different versions of the motion kernel go here
 ******************************************************/

/*
 * naive_motion - The naive baseline version of motion 
 */
char naive_motion_descr[] = "naive_motion: Naive baseline implementation";
void naive_motion(int dim, pixel *src, pixel *dst) 
{
	int i, j;

	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
		{
			int ii, jj;
			pixel_sum sum;
			pixel current_pixel;
			double weights[3][3] = { { 0.50, 0.03125, 0.00 },
				{ 0.03125, 0.25, 0.03125 },
				{ 0.00, 0.03125, 0.125 } };

			initialize_pixel_sum(&sum);
			for(ii=0; ii < 3; ii++)
				for(jj=0; jj < 3; jj++) 
					if ((i + ii < dim) && (j + jj < dim))
						accumulate_weighted_sum(&sum,
								src[RIDX(i+ii,j+jj,dim)],
								weights[ii][jj]);

			assign_sum_to_pixel(&current_pixel, sum);

			dst[RIDX(i, j, dim)] = current_pixel;

		}
}


/*
 * motion - Your current working version of motion. 
 * IMPORTANT: This is the version you will be graded on
 */
char motion_descr[] = "motion: Current working version";
void motion(int dim, pixel *src, pixel *dst) 
{
  naive_motion(dim, src, dst);
}

/********************************************************************* 
 * register_motion_functions - Register all of your different versions
 *     of the motion kernel with the driver by calling the
 *     add_motion_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_motion_functions() {
  add_motion_function(&motion, motion_descr);
  add_motion_function(&naive_motion, naive_motion_descr);
}
