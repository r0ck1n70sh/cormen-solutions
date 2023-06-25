#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include <chapter_04/max_sum_subarr.h>

int64_t curr_time_in_ms () {
  struct timeval now;
  gettimeofday(&now, NULL);

  int64_t s = (int64_t) (now.tv_sec) * 1000;
  int64_t u = now.tv_usec / 1000;

  return s + u;
}

int * make_random_arr (int len) {
  int idx, r, s;
  int * arr = (int *) malloc (len * sizeof(int));

  for (idx = 0; idx < len; idx++) {
    s = (rand () % 4) - 1;
    arr [idx] = s * rand();
  }

  return arr;
}

int main () {
  int * brute_force_res, * recursive_res, * arr;
  unsigned int len;
  int64_t brute_force_time, recursive_time, init_time, diff = 0;

  for (len = 2; len < (1 << 18); len = len << 1) {
    arr = make_random_arr (len);

    init_time = curr_time_in_ms ();
    brute_force_res = brute_force_max_sum_subarr (arr, len);
    brute_force_time = curr_time_in_ms () - init_time;

    /* printf ("max_sum: %d -> (%d, %d) : (%d, %d) \n", */
    /*     brute_force_res [2], */
    /*     brute_force_res [0], */
    /*     brute_force_res [1], */
    /*     arr [brute_force_res [0]], */
    /*     arr [brute_force_res [1]]); */

    init_time = curr_time_in_ms ();
    recursive_res = recursive_max_sum_subarr (arr, len);
    recursive_time = curr_time_in_ms () - init_time;

    /* printf ("max_sum: %d -> (%d, %d) : (%d, %d) \n", */
    /*     brute_force_res [2], */
    /*     brute_force_res [0], */
    /*     brute_force_res [1], */
    /*     arr [brute_force_res [0]], */
    /*     arr [brute_force_res [1]]); */

    diff = recursive_time - brute_force_time;
    printf ("len: %u, diff: %ld\n", len, diff);

    free (brute_force_res);
    free (recursive_res);
  }

  return 0;
}
