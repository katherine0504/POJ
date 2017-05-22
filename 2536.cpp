#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

#define MAX 110

using namespace std;

struct point {
  double x;
  double y;
};

int n, m, s, v, out;
double dis;
bool used[MAX];
int llink[MAX], rlink[MAX];
point gopher[MAX], hole[MAX];
vector <int> edge[MAX];

bool DFS(int r);
int Bipartite(int nL, int nR);

int main () {
  int i, j;
  while (scanf("%d %d %d %d", &n, &m, &s, &v) == 4) {
    memset(gopher, 0, sizeof(gopher));
    memset(hole, 0, sizeof(hole));
    memset(used, false, sizeof(used));

    for (i = 0; i < MAX; ++i) {
      edge[i].clear();
    }
    for (i = 1; i <= n; ++i) {
      scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
    }

    for (i = 1; i <= m; ++i) {
      scanf("%lf %lf", &hole[i].x, &hole[i].y);
    }

    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) {
        dis = sqrt(pow(gopher[i].x - hole[j].x, 2) + pow(gopher[i].y - hole[j].y, 2));
        
        if(dis/v <= s) {
          edge[i].push_back(j);
        } 
      }
    }
    out = Bipartite(n,m);
    printf("%d\n", n-out);
  }

  return 0;
}

bool DFS(int r) {
  int i, nxt;

  for(i = 0; i < (int)edge[r].size(); ++i) {
    nxt = edge[r][i];

    if(!used[nxt]) {
      used[nxt] = true;

      if(!rlink[nxt] || DFS(rlink[nxt])) {
        llink[r] = nxt;
        rlink[nxt] = r;
        return true;
      }
    }
  }
  return false;
}

int Bipartite(int nL, int nR) {
  int i, ans = 0;

  memset(llink, 0, (nL+1)*sizeof(int));
  memset(rlink, 0, (nR+1)*sizeof(int));

  for(i = 1; i <= nL; ++i) {
    memset(used, false, (nR+1)*sizeof(bool));
    
    if(DFS(i)) {
      ++ans;
    }
  }
  return ans;
}
