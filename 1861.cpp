#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX 10000

using namespace std;

struct edge {
  int x;
  int y;
  int len;
} E[MAX*MAX];

int N, M, edgecnt, cnt, len;
int disjoint[MAX];
vector <edge> ans;

void init();
bool Union(edge A);
int Find(int x);
bool cmp(edge A, edge B);

int main () {
  int i, j;
  
  while(scanf("%d %d", &N, &M) != EOF) {
    init();

    for (i = 0; i < M; ++i) {
      scanf("%d %d %d", &E[i].x, &E[i].y, &E[i].len);
    }

    sort(E, E+M, cmp);

    for (i = 0; cnt != N-1; ++i) {
      if(Union(E[i])) {
        ++cnt;
        ans.push_back(E[i]);
      }
    }
    
    printf("%d\n%d\n", ans[cnt-1].len, cnt);

    for(i = 0; i < cnt; ++i) {
      printf("%d %d\n", ans[i].x, ans[i].y);
    }
  }

  return 0;
}

void init() {
  int i;
  
  ans.clear();
  cnt = 0;

  for (i = 1; i <= N; ++i) {
    disjoint[i] = i;
  }
  return;
}

int Find(int x) {
  if(x == disjoint[x]) {
    return x;
  } else {
    return disjoint[x] = Find(disjoint[x]);
  }
}

bool Union(edge A) {
  int x = Find(A.x);
  int y = Find(A.y);

  if (x != y) {
    disjoint[x] = y;
    return true;
  } else {
    return false;
  }
}

bool cmp (edge A, edge B) {
  return A.len < B.len;
}
