#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

#define MAX 110

using namespace std;

int n, m, k, x, y, out;
bool used[MAX];
int llink[MAX], rlink[MAX];
vector <int> edge[MAX];

bool DFS(int r);
int Bipartite(int nL, int nR);

int main () {
  int i, j;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      break;
    }

    memset(used, false, sizeof(used));

    for (i = 0; i < MAX; ++i) {
      edge[i].clear();
    }

    scanf("%d %d", &m, &k);
    
    for (i = 1; i <= k; ++i) {
      scanf("%d %d %d", &j, &x, &y);
      if (!x || !y) {
        continue;
      } else {
        edge[x].push_back(y);
      }
    }

    out = Bipartite(n,m);
    printf("%d\n", out);
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
