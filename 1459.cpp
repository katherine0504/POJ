#include <cstdio>
#include <cstring>
#include <queue>

#define INF 999999999

using namespace std;

int cap[210][210], flow[210][210], bottleneck[210], pre[210];
int n, np, nc, m, u, v, z, ans;
queue <int> Q;

int BFS(int N, int S, int T);

int main() {
  int i;
	while (scanf("%d %d %d %d", &n, &np, &nc, &m) == 4){
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		
		for (i = 0; i < m; ++i){
			scanf(" (%d,%d)%d", &u, &v, &z);
			if(u == v){
        continue;
      }
			cap[u+2][v+2] = cap[u+2][v+2] + z;
		}
    
		for (i = 0; i < np; ++i){
			scanf(" (%d)%d", &u, &z);
			cap[1][u+2] = cap[1][u+2] + z;
		}

		for (i = 0; i < nc; ++i){
			scanf(" (%d)%d", &u, &z);
			cap[u+2][n+2] = cap[u+2][n+2] + z;
		}
    
    ans = BFS(n+2, 1, n+2);

		printf("%d\n", ans);
	}
	return 0;
}

int BFS(int N, int S, int T) {
	int i, cur, nxt, result = 0;
	
  while (1) {
    while(!Q.empty()) {
      Q.pop();
    }

    memset(bottleneck, 0, sizeof(int)*(N+2));
		Q.push(S);
		bottleneck[S] = INF;
		
		while (!Q.empty() && !bottleneck[T]) {
			cur = Q.front();
			Q.pop();
			
      for (nxt = 1; nxt <= N; ++nxt) {
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

		if (!bottleneck[T]) {
      break;
    }
		
		for (cur = T; cur != S; cur = pre[cur]) {
			flow[pre[cur]][cur] = flow[pre[cur]][cur] + bottleneck[T];
      flow[cur][pre[cur]] = flow[cur][pre[cur]] - bottleneck[T];
		}
		result += bottleneck[T];
	}
	return result;
}
