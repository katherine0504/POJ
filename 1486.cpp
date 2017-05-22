#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

#define MAX 1000

using namespace std;

int n, x, y, out, casecnt = 1;
bool found;
bool used[MAX];
int llink[MAX], rlink[MAX], Xmin[MAX], Xmax[MAX], Ymin[MAX], Ymax[MAX], ans[MAX];
vector <int> edge[MAX];

bool DFS(int r, int u, int v);
int Bipartite(int nL, int nR);

int main () {
  int i, j;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      break;
    }

    found = false;
    memset(used, false, sizeof(used));
    memset(Xmax, 0, sizeof(Xmax));
    memset(Xmin, 0, sizeof(Xmin));
    memset(Ymax, 0, sizeof(Ymax));
    memset(Ymin, 0, sizeof(Ymin));

    for (i = 0; i < MAX; ++i) {
      edge[i].clear();
    }

    
    for (i = 0; i < n; ++i) {
      scanf("%d %d %d %d", &Xmin[i], &Xmax[i], &Ymin[i], &Ymax[i]);
    }

    for (i = 0; i < n; ++i) {
      scanf("%d %d", &x, &y);
      for(j = 0; j < n; ++j) {
        if (Xmin[j] <= x && Xmax[j] >= x && Ymin[j] <= y && Ymax[j] >= y) {
          edge[j].push_back(i);
        }
      }
    }

    out = Bipartite(n,-1);

    for(i = 0; i < n; ++i) {
      ans[i] = llink[i];
    }

    printf("Heap %d\n", casecnt++);

    for(i = 0; i < n; ++i) {
      if (Bipartite(i, ans[i]) < out) {
        if (found) {
          printf(" ");
        }
        printf("(%c,%d)", (i+'A'), ans[i]+1);
        found = true;
      }
    }

    if(!found) {
      printf("none");
    }
    printf("\n\n");
  }

  return 0;
}

bool DFS(int r, int u , int v) {
  int i, nxt;

  for(i = 0; i < (int)edge[r].size(); ++i) {
    nxt = edge[r][i];

    if(used[nxt] || (r == u && nxt == v)) {
      continue;
    } else {
      used[nxt] = true;

      if(rlink[nxt] == -1 || DFS(rlink[nxt], u , v)) {
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

  memset(llink, -1, (n)*sizeof(int));
  memset(rlink, -1, (n)*sizeof(int));

  for(i = 0; i < n; ++i) {
    memset(used, false, (n)*sizeof(bool));
    
    if(DFS(i, nL, nR)) {
      ++ans;
    }
  }
  return ans;
}
