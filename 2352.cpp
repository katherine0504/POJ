#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 32050

using namespace std;

int N, X, Y;
int level[MAX], c[MAX];

int lowbit (int in);
void modify (int index, int delta);
int query (int n);

int main () {
  int i;

  scanf("%d", &N);

  memset(c, 0, sizeof(c));
  memset(level, 0, sizeof(level));

  for (i = 0; i < N; ++i) {
    scanf("%d %d", &X, &Y);
    level[query(X+1)]++;
    modify(X+1, 1);
  }

  for (i = 0; i < N; ++i) {
    printf("%d\n", level[i]);
  }

  return 0;
}

int lowbit (int in) {
  return in&(-in);
}

void modify (int index, int delta) {
  int i;

  for(i = index; i < MAX; i = i + lowbit(i)) {
    c[i] = c[i] + delta;
  }
}

int query (int n) {
  int sum = 0;

  while (n > 0) {
    sum = sum + c[n];
    n = n - lowbit(n);
  }

  return sum;
}
