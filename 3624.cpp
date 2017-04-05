#include <cstdio>
#include <cstdlib>

#define MAX 3500

int m, n, ans, arr[MAX][2], dp[14000];

void init();

int main() {
  int i, j, tmp;
  scanf("%d %d", &n, &m);
  init();
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }

  for (i = 1; i <= n; i++) {
    for (j = m; j >= arr[i][0]; j--) {
      tmp = dp[j - arr[i][0]] + arr[i][1];
      if ( tmp > dp[j] ) {
        dp[j] = tmp;
      }
    }
  }

  printf("%d\n", dp[m]);
  return 0;
}

void init() {
  int i;

  for (i = 0; i< MAX; i++) {
    arr[MAX][0] = 0;
    arr[MAX][1] = 0;
    dp[i] = 0;
  }
  for (i = MAX; i < 14000; i++) {
    dp[i] = 0;
  }
  ans = 0;
  return;
}
