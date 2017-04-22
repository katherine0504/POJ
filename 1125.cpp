#include <cstdio>
#include <cstdlib>

#define INF 1000000000

using namespace std;

int num, mn, id, maxL;
int dis[110][110];
bool notFound, reached;

int main () {
  int i, j, k, a, b, t;
  while (scanf("%d", &num) != EOF) {
    if (num == 0) {
      break;
    }
    
    mn = INF;
    notFound = true;
    
    for (i = 1; i <= num; ++i) {
      for (j = 1; j <= num; ++j) {
        dis[i][j] = INF;
      }
      dis[i][i] = 0;
    }

    for (i = 1; i <= num; ++i) {
      scanf("%d", &t);
      for (j = 0; j < t; ++j) {
        scanf("%d %d", &a, &b);
        dis[i][a] = b;
      }
    }

    for (i = 1; i <= num; ++i) {
      for (j = 1; j <= num; ++j) {
        for (k = 1; k <= num; ++k) {
          if (dis[j][i] + dis[i][k] < dis[j][k]) {
            dis[j][k] = dis[j][i] + dis[i][k];
          }
        }
      }
    }
    
    for (i = 1; i <= num; ++i) {
      maxL = 0;
      reached = true;
      for (j = 1; j <= num; ++j) {
        if (dis[i][j] == INF) {
          reached = false;
          break;
        } else {
          if (dis[i][j] > maxL) {
            maxL = dis[i][j];
          } 
        }
      }
      if (reached) {
        notFound = false;
        if (maxL < mn) {
          mn = maxL;
          id = i;
        }
      }
    }
    if (notFound) {
      printf("disjoint\n");
    } else {
      printf("%d %d\n", id, mn);
    }
  }
  return 0;
}
