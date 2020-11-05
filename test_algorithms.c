#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "linear_congruential_generator.h"
#include "quadratic_congruential_generator.h"
#include "fibonacci_number_generator.h"
#include "reverse_congruential_generator.h"
#include "union_method_generator.h"
#include "simga_3_normal_distribution_generator.h"
#include "polar_coordinates_normal_distribution_generator.h"
#include "ratio_method_generator.h"
#include "log_method_for_exponential_distribution_generator.h"
#include "arensa_method_for_gamma_distribution_generator.h"
#include "ratio_method_generator.h"


void clean_window (void) {
  printf("\e[1;1H\e[2J");
}

void draw_distribution_table_for(int generator_number) {
double (*generator_function) (void);
unsigned char distribution_limits = 0; // 0 - [0, 1], 1 - [-3, 3], 2 - [0, 100]
unsigned int distribution[10] = { 0 };
int number_of_tries = 90000;

switch ( generator_number )
{
  case 1:
   generator_function = &lcg_rand_norm;
   break;
  case 2:
   generator_function = &qcg_rand_norm;
   break;
  case 3:
   generator_function = &fib_next_num_norm;
   break;
  case 4:
   generator_function = &rcg_rand_norm;
   break;
  case 5:
   generator_function = &un_rand_norm;
   break;
  case 6:
   generator_function = &sig_3_n_rand;
   distribution_limits = 1;
   break;
  case 7:
   distribution_limits = 1;
   break;
  case 8:
   generator_function = &rat_rand;
   distribution_limits = 1;
   break;
  case 9:
   generator_function = &log_exp_rand;
   distribution_limits = 2;
   break;
  case 10:
   generator_function = &arensa_gamma_rand;
   distribution_limits = 2;
   break;
  }

if ( generator_number == 7 ) {
  double x_n[2];
  int i, j;

  for (i=1;i<=number_of_tries / 2;i++) {
    pol_coord_n_rand(&x_n[0], &x_n[1]);
    for (j=0;j<2;j++) {
      double do_some_math = (int)((x_n[j] / 3) * 10); // a in [-10, 10]
      if (do_some_math > 10) { do_some_math = 9.9; } // a in (-10, 10)
      if (do_some_math < -10) { do_some_math = -9.9; } // a in (-10, 10)
      do_some_math = do_some_math / 2; // a in (-5, 5)
      if (do_some_math > 0) { distribution[(int)do_some_math + 5]++;}
      if (do_some_math < 0) { distribution[4 + ((int)do_some_math)]++; }

    }
  }
}

else if ( distribution_limits == 0 ) { // a in [0, 1]
  int i;
  double rand_num = 0;
  for (i=1;i<=number_of_tries;i++) {
    rand_num = generator_function();
    if (rand_num == 1) { rand_num = 0.99; }
    distribution[(int)(rand_num * 10)]++;
    /* printf("%d # %f | ", rand_num, (int)(rand_num * 10)); */
  }

}

else if ( distribution_limits == 1 ) { // a in [-3, 3]
  int i;
  double rand_num;
  for (i=1;i<=number_of_tries;i++) {
    rand_num = generator_function();
    double do_some_math = (int)((rand_num / 3) * 10); // a in [-10, 10]
      if (do_some_math > 10) { do_some_math = 9.9; } // a in (-10, 10)
      if (do_some_math < -10) { do_some_math = -9.9; } // a in (-10, 10)
      do_some_math = do_some_math / 2; // a in (-5, 5)
      if (do_some_math > 0) { distribution[(int)do_some_math + 5]++;}
      if (do_some_math < 0) { distribution[4 + ((int)do_some_math)]++; }
      /* printf("%d # %f | ", rand_num, (int)(rand_num * 10)); */
  }
}

else if ( distribution_limits == 2 ) { // a in [0, 100]
  int i;
  double rand_num;
  for (i=1;i<=number_of_tries;i++) {
    rand_num = generator_function();
    if (rand_num >= 100) { rand_num = 99; }
    if (rand_num < 0) { rand_num = 0; }
    distribution[(int)(rand_num / 10)]++;
    /* printf("%d # %f | ", rand_num, (int)(rand_num / 10)); */
  }

}

printf("\n");


switch ( distribution_limits )
  {
  double start_interval;
  double interval_step;
  int i;

  case 0:
    start_interval = 0;
    interval_step = 0.1;
    printf("%10s\t%15s\n", "Interval", "Frequency");
    for (i=0;i<10;i++)
    {
      printf("[%- 4.1f, %- 4.1f]\t\t%.2f\n", start_interval, start_interval + interval_step, ((double)distribution[i] / (double)number_of_tries));
      start_interval += interval_step;
    }
    break;

  case 1:
    start_interval = -3;
    interval_step = 0.6;
    
    printf("%10s\t%15s\n", "Interval", "Frequency");
    for (i=0;i<10;i++)
    {
      printf("[%- 4.1f, %- 4.1f]\t\t%.2f\n", start_interval, start_interval + interval_step, ((double)distribution[i] / (double)number_of_tries));
      start_interval += interval_step;
    }
    break;
  case 2:
    start_interval = 0;
    interval_step = 10;
    printf("%9s\t%15s\n", "Interval", "Frequency");
    for (i=0;i<10;i++)
    {
      printf("[%- 3d, %3d]\t\t%.2f\n", (int)start_interval, (int)(start_interval + interval_step), ((double)distribution[i] / (double)number_of_tries));
      start_interval += interval_step;
    }
    break;
  }

}

short int read_input(void) {
    long a;
    char buf[1024]; // use 1KiB just to be sure
    int success; // flag for successful conversion

    do
    {
        if (!fgets(buf, 1024, stdin))
        {
            // reading input failed:
            return 1;
        }

        // have some input, convert it to integer:
        char *endptr;

        errno = 0; // reset error number
        a = strtol(buf, &endptr, 10);
        if (errno == ERANGE)
        {
            success = 0;
        }
        else if (endptr == buf)
        {
            // no character was read
            success = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            // *endptr is neither end of string nor newline,
            // so we didn't convert the *whole* input
            success = 0;
        }
        else if ( (a < 1) || (a > 10)) 
        {
           // number not in [1, 10]
           success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success); // repeat until we got a valid number

    return a;
}

int get_generator_num (bool to_clear) {

char greeding_text[] = "Choose pseudorandom number generator to draw distribution table for.\n";
char geenrators_to_choose[] = "linear congrurental[1] | quadratic cogurantal[2] | fibonacci number[3] | reverse congrurental[4] | union method[5]\n        3 sigma [6] | polar coordinates[7] | ratio method[8] | logarithm method [9] | Arens method [10]\n\n";
char promt[] = "Enter number from 1 to 10: ";
int generator_number; 
char buf[1024]; // use 1KiB just to be sure
int success; // flag for successful conversion


do {
  if ( to_clear ) { clean_window(); }
  puts(greeding_text);
  puts(geenrators_to_choose);
  printf("%s", promt);
  if (!fgets(buf, 1024, stdin))
  {
      // reading input failed:
  }

   // have some input, convert it to integer:
   char *endptr;

   errno = 0; // reset error number
   generator_number = strtol(buf, &endptr, 10);
   if (errno == ERANGE)
   {
       success = 0;
   }
   else if (endptr == buf)
   {
       // no character was read
       success = 0;
   }
   else if (*endptr && *endptr != '\n')
   {
       // *endptr is neither end of string nor newline,
       // so we didn't convert the *whole* input
       success = 0;
   }
   else if ( (generator_number < 1) || (generator_number > 10)) 
   {
      // number not in [1, 10]
      success = 0;
   }
   else
   {
       success = 1;
   }
} while (!success); // repeat until we got a valid number

return generator_number;
}

int promt_to_continue_working(void)
{
  char *buffer = NULL;
  int read;
  long unsigned int len;

  puts("\nDo you want to check another algorithm?");
  puts("\nPress [q]uit to exit programm or any other button to do further work.");

  do {
  read = getline(&buffer, &len, stdin);
  } while ( strcmp(buffer, "") == 0 );

  if ( strcmp(buffer, "q\n") == 0 )
  {
    return 0;
  }
  else 
  {
    return 1;
  }
}

int main(void) {
  do {
    clean_window();
    draw_distribution_table_for(get_generator_num(true));
  } while ( promt_to_continue_working() );
  puts("\nProgram was made by Chomko Vasyl, student K-21.");
  return 1;
}

