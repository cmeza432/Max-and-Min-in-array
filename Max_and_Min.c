#include <stdio.h>
#include <stdlib.h>

/* 
Carlos Meza
Print out 2d array and get Biggest and smallest number in array while giving first and last instance
where they were found.
*/

void process(int a[][10], int maxes[][2], int mins[][2], int* max, int* min)
{
	/* Values that help loop through size of 2d array */
  int row =0;
  int col;
  /* Variables set to row and columns of Max number in array */
  int rmax = 0;
  int cmax = 0;
  int rmax2 = 0;
  int cmax2 = 0;
  /* Variables set to row and column of minimum number in array */
  int rmin = 0;
  int cmin = 0;
  int cmin2 = 0;
  int rmin2 = 0;
  /* Sets both min and max equal to first number in array */
  int M = a[0][0];												
  int MN = a[0][0];
  for(row; row < 10;row++)
  {
	  /* Resets back to 0 everytime loop goes to new row */
	  col = 0;													
	  for(col; col < 10; col++)
	  {
		  /* Initializes M when a bigger number is found and marks position when its first found */
		  if(a[row][col] > M)									
		  {
			  M = a[row][col];
			  rmax = row;
			  cmax = col;
		  }	  
		  /* When a number equals max number it marks position to track last instance */
		  if(a[row][col] == M)								
		  {  
			  rmax2 = row;
			  cmax2 = col;  
		  }
		  /* Initializes minimum number and first position */
		  if(a[row][col] < MN)							
		  {
			  MN = a[row][col];
			  rmin = row;
			  cmin = col;
		  }
		  /* Marks last instance of minimum number found */
		  if(a[row][col] == MN )							
		  {
			  rmin2 = row;
			  cmin2 = col;			 
		  }
	  }
  }
  /* Initialize first and last positions Max and min are found into a 2d array */
  maxes[0][0] = rmax;
  maxes[0][1] = cmax;
  maxes[1][0] = rmax2;
  maxes[1][1] = cmax2;
  mins[0][0] = rmin;
  mins[0][1] = cmin;
  mins[1][0] = rmin2;
  mins[1][1] = cmin2;
  /* Change values where pointers are pointing at and not the actual address */
  *max = M;
  *min = MN;
}

void print_array(int a[][10])
{
  int r = 0;
  /* Loops through each value seperately in the 2d array */
  for(r; r < 10; r++)
  {
	  int c = 0;
	  for(c; c < 10; c++)
	  {
		  printf("%3d", a[r][c]);
	  }
	  printf("\n");
  }
}

int main(void)
{
  int row, col, a[10][10];
  
  /* Stores row, col of the first and last occurrences of the min and max array values */
  int maxes[2][2], mins[2][2];

  /* This is where your function will store the min and max values from the array */
  int max, min; 

  /* Generate an 10x10 array of random numbers from 0 to 99 */
  srand(12345); /* Seeds the random number generator. Change this to try other values */

  for (row = 0; row < 10; row++)
  {
    for (col = 0; col < 10; col++)
    {
      a[row][col] = rand() % 100;
    }
  }
  printf("Using array:\n\n");
  print_array(a);
  
  process(a, maxes, mins, &max, &min);
  
  printf("\nMax Value:%3d\n",  max);
  printf("First occurence:%2d,%2d\n", maxes[0][0], maxes[0][1]);
  printf("Last occurrence:%2d,%2d\n", maxes[1][0], maxes[1][1]);
  printf("\n");
  printf("Min Value:%3d\n",  min);
  printf("First occurence:%2d,%2d\n", mins[0][0], mins[0][1]);
  printf("Last occurrence:%2d,%2d\n", mins[1][0], mins[1][1]);
}
