#include <cstdio>
#include <cstdlib>

#define INF 1000000000
#define MAX 5000

int T, N, dis[MAX];

struct Edge{
  int x;
  int y;
  int len;
} edge[MAX];

void init();
void BellmanFord();

int main() {
  int i, x, y, tmp;
  scanf("%d %d", &T, &N);
  init();
  for (i = 0; i < T; ++i) {
    scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].len);
  }

  BellmanFord();

  printf("%d\n", dis[1]);

  return 0;
}

void init() {
  int i, j;
  dis[N] = 0;
  for(i = 0; i < N; ++i) {
    dis[i] = INF;
  }
  return;
}

void BellmanFord() {
  int i, j, k;
  bool changed;

  for (i = 0; i < N-1; ++i) {
    changed = false;
    for (j = 0; j < T; j++) {
      if (dis[edge[j].x] + edge[j].len < dis[edge[j].y]) {
        dis[edge[j].y] = dis[edge[j].x] + edge[j].len;
        changed = true;
      }
      if (dis[edge[j].y] + edge[j].len < dis[edge[j].x]) {
        dis[edge[j].x] = dis[edge[j].y] + edge[j].len;
        changed = true;
      }
    }
    if (!changed) {
      return;
    }
  }
  return;
}
