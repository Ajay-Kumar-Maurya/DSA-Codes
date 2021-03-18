#include <stdio.h>

int main()
{
  int c, d, swap;

  int array[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(array)/sizeof(array[0]);

  for (c = 0 ; c <= n - 1; c++)
  {
    for (d = 0 ; d <= n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use '<' instead of '>' */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++)
     printf("%d\n", array[c]);

  return 0;
}
