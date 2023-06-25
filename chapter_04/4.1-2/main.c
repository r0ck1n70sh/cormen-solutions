#include <stdio.h>
#include <stdlib.h>


// brute force solution
int * max_sum_sub_arr (int arr [], int len) {
  int * res_arr, l, r, i, j, max_sum = 0, sum;

  for (i = 0; i < len; i++) {
    sum = 0;
    for (j = i; j < len; j++) {
      sum += arr [j];

      if (max_sum > sum) continue;
      max_sum = sum;
      l = i;
      r = j;
    }
  }

  res_arr = (int *) malloc (3 * sizeof(int));

  res_arr [0] = l;
  res_arr [1] = r;
  res_arr [2] = max_sum;

  return res_arr;
}

int main () {
  int arr [] = { 2 , 0, -1, 4, -2 };
  int * res, len = 5, l, r, max_sum;

  res = max_sum_sub_arr (arr, len);
  l = res [0];
  r = res [1];
  max_sum = res [2];

  printf ("max_sum: %d -> (%d, %d) : (%d, %d)\n", max_sum, l, r, arr[l], arr[r]);

  return 0;
}
