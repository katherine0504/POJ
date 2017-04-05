#include <cstdio>
#include <cstdlib>

#define MAX 1050

using namespace std;

int n, cnt, mx;
int num[MAX], lis[MAX];

void init ();

int main () {
  int i, j;
  while (scanf("%d", &n) != EOF) {
    cnt = 0;
    mx = 0;
    init();
    for (i = 0; i < n; i++) {
      scanf("%d", &num[i]);
      cnt++;
    }

    for (i = 0; i < cnt; i++) {
      lis[i] = 1;
      for (j = 0; j < i; j++) {
        if (num[j] < num[i] && lis[j]+1 > lis[i]) {
          lis[i] = lis[j] + 1;
        }
      }
      if (lis[i] > mx) {
        mx = lis[i];
      }
    }
    if (n == 0) {
      printf("1\n");
    } else { 
      printf("%d\n", mx);
    }
  }
  return 0;
}

void init () {
  int i;
  for (i = 0; i < MAX; i++) {
    num[i] = 0;
    lis[i] = 0;
  }
  return;
}
