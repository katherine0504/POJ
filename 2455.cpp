#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 210
#define INF 1000000000

using namespace std;

struct Edge{
  int x;
  int y;
  int len;
} edge[MAX*MAX];

int N, P, T, c, maxEdge, left, right, mid;
int cap[MAX][MAX], flow[MAX][MAX], bottleneck[MAX], pre[MAX];
queue <int> Q;

void init();
int BFS(int len, int N, int P);

int main() {
  int i, in1, in2, bandwidth;

  while(scanf("%d %d %d", &N, &P, &T) == 3) {

    init();
    
    for (i = 0; i < P; ++i) {
      scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].len);
      if(edge[i].len > maxEdge) {
        maxEdge = edge[i].len;
      }
    }

    right = maxEdge;

    while(left != right) {
      mid = (left + right) / 2;
      if (BFS(mid, N, P) >= T) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    printf("%d\n", left);
  }
  return 0;
}

void init() {
  int i;

  maxEdge = 0;
  left = 0;
  
  memset(pre, 0, sizeof(int)*MAX);

  return;
}

int BFS (int len, int N, int P) {
  int result = 0;
  int i, nxt, cur;

  memset(cap, 0, sizeof(cap));
  memset(flow, 0, sizeof(flow));

  for(i = 0; i < P; ++i) {
    if(len >= edge[i].len) {
      cap[edge[i].y][edge[i].x]++;
      cap[edge[i].x][edge[i].y]++;
    }
  }

  while(1) {
    while(!Q.empty()) {
      Q.pop();
    }

    memset(bottleneck, 0, sizeof(int)*N+2);
    Q.push(1);
    bottleneck[1] = INF;

    while(!Q.empty() && !bottleneck[N]) {
      cur = Q.front();
      Q.pop();

      for(nxt = 1; nxt <= N; ++nxt) {
        if (!bottleneck[nxt] && cap[cur][nxt] > flow[cur][nxt]) {
          Q.push(nxt);
          pre[nxt] = cur;
          if((cap[cur][nxt] - flow[cur][nxt]) < bottleneck[cur]) {
            bottleneck[nxt] = cap[cur][nxt] - flow[cur][nxt];
          } else {
            bottleneck[nxt] = bottleneck[cur];
          }
        }
      }
    }

    if(!bottleneck[N]) {
      break;
    }

    for (cur = N; cur != 1; cur = pre[cur]) {
      flow[pre[cur]][cur] = flow[pre[cur]][cur] + bottleneck[N];
      flow[cur][pre[cur]] = flow[cur][pre[cur]] - bottleneck[N];
    }

    result = result + bottleneck[N];
  }
  return result;
}
