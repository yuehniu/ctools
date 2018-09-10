/*
  Desc:
    This function is to find solution of a equation using 
    Bisection method.
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef double Dtype;

Dtype f(Dtype n)
{
  //return n * log10(n);
  return pow(2, n);
}

int main(int argc, char * argv[])
{
  assert(argc > 1); 
  
  Dtype lower_lim = 1;
  Dtype upper_lim = 0;
  sscanf(argv[1], "%lf", &upper_lim);
  Dtype obj_val = upper_lim;

  printf("Lower limit: %lf; Upeer limit: %lf\n", lower_lim, upper_lim);
  while ( (upper_lim - lower_lim) > 1.0){
    //Dtype lower_val = f(lower_lim);
    //Dtype upper_val = f(upper_lim);
    Dtype mid_pos = (lower_lim + upper_lim) / 2;
    Dtype mid_val = f(mid_pos);

    if ( mid_val == obj_val) 
      break;
    else if (mid_val < obj_val) 
      lower_lim = mid_pos;
    else
      upper_lim = mid_pos;
  }

  printf("The solution is: %lf\n", floor(upper_lim));
  return 0;
}

