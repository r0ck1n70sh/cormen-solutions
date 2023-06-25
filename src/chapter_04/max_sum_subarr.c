#include <stdlib.h>
#include <limits.h>
#include <chapter_04/max_sum_subarr.h>

#define max(a, b) a > b ? a : b

int * brute_force_max_sum_subarr (int arr [], int len) {
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

int * recursive_max_sum_subarr (int arr [], int len) {
  int * res_arr = (int *) malloc (3 * sizeof(int));

  if (len == 0) {
    res_arr [0] = 0;
    res_arr [1] = 0;
    res_arr [2] = INT_MIN;
    return res_arr;
  }
  
  if (len == 1) {
    res_arr [0] = 0;
    res_arr [1] = 0;
    res_arr [2] = arr [0];
    return res_arr;
  }

  int * left_res,
      * right_res,
      mid = len / 2,
      left_max_sum,
      right_max_sum,
      sub_arr_max_sum,
      sub_arr_l,
      sub_arr_r,
      i,
      j,
      l,
      r,
      mid_max_sum,
      curr_sum,
      * subarr_sum;

  left_res = recursive_max_sum_subarr (arr, mid);
  right_res = recursive_max_sum_subarr (arr + mid, len - mid);

  left_max_sum = left_res [2];
  right_max_sum = right_res [2];

  sub_arr_max_sum = max(left_max_sum, right_max_sum);
  sub_arr_l = left_max_sum > right_max_sum ? left_res [0] : right_res [0] + mid;
  sub_arr_r = left_max_sum > right_max_sum ? left_res [1] : right_res [1] + mid;

  subarr_sum = (int *) malloc (len * sizeof(int));
  subarr_sum [0] = arr [0];

  for (i = 1; i < len; i++) {
    subarr_sum [i] = subarr_sum [i - 1] + arr [i];
  }

  mid_max_sum = arr[mid], l = mid, r = mid, curr_sum = arr[mid];
  for (i = mid - 1; i >= 0; i--) {
    curr_sum += arr [i];
    if (sub_arr_max_sum > curr_sum) continue;

    mid_max_sum = curr_sum;
    l = i;
  }

  curr_sum = mid_max_sum;
  for (i = mid + 1; i < len; i++) {
    curr_sum += arr [i];
    if (sub_arr_max_sum > curr_sum) continue;

    mid_max_sum = curr_sum;
    r = i;
  }

  free (left_res);
  free (right_res);
  free (subarr_sum);

  res_arr [0] = sub_arr_l;
  res_arr [1] = sub_arr_r;
  res_arr [2] = sub_arr_max_sum;

  return res_arr;
}
