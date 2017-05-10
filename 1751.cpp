#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define MAX 1500

using namespace std;

struct point {
  int x;
  int y;
} P[MAX];

struct edge {
  int x;
  int y;
  double len;
} E[MAX*MAX];

int casenum, edgecnt, N, M, in1, in2;
int disjoint[MAX];
bool found;

void init();
bool Union(edge A);
void Join(int x, int y);
int Find(int x);
bool cmp(edge A, edge B);

int main () {
  int i, j;

  while(scanf("%d", &N) == 1) {
    for (i = 1; i <= N; ++i) {
      scanf("%d %d", &P[i].x, &P[i].y);
    }

    init();

    for (i = 1; i <= N; ++i) {
      for (j = i + 1; j <= N; ++j) {
        E[edgecnt].x = i;
        E[edgecnt].y = j;
        E[edgecnt++].len = sqrt(pow(P[i].x - P[j].x, 2) + pow(P[i].y - P[j].y, 2));
      }
    }

    sort(E, E+edgecnt, cmp);

    scanf("%d", &M);

    for (i = 0; i < M; ++i) {
      scanf("%d %d", &in1, &in2);
      Join(in1, in2);
    }

    for (i = 0; i < edgecnt; ++i) {
      if(Union(E[i])) {
        found = true;
        printf("%d %d\n", E[i].x, E[i].y);
      }
    }

    if(!found) {
      printf("no highways need\n");
    }
  }
  return 0;
}

void init() {
  int i;
  
  edgecnt = 0;
  found = false;

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

void Join(int x, int y) {
  int X, Y;

  X = Find(x);
  Y = Find(y);

  if (X != Y) {
    disjoint[X] = Y;
  }
}
