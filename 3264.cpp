#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define INF 1000000000
#define MAX 1000005

struct Node {
  int valmax, valmin;
  Node *l, *r;

  void update (int v) {
    valmin = v;
    valmax = v;
  }

  void pull () {
    valmax = max(l->valmax, r->valmax);
    valmin = min(l->valmin, r->valmin);
  }
};

int ptr, valmin, valmax, N, Q;
int s[MAX];

Node* build (int L, int R);
int querymax (Node* now, int L, int R, int x, int y, bool isMax);

int main() {
  int i, j, x, y, mx, mn;
  ptr = 0;

  scanf("%d %d", &N, &Q);

  for (i = 0; i < N; ++i) {
    scanf("%d", &s[i]);
  }

  Node *now = build(0, N-1);

  for (i = 0; i < Q; ++i) {
    scanf("%d %d", &x, &y);
    if (x == y) {
      printf("0\n");
    } else {
      mx = querymax(now, 0, N-1, x-1, y-1, true);
      mn = querymax(now, 0, N-1, x-1, y-1, false);
      printf("%d\n", mx-mn);
    }
  }

  return 0;
}

Node* build (int L, int R) {
  Node* now = new Node();

  if (L == R) {
    now->update(s[L]);
    return now;
  }

  int mid = (L+R) >> 1;

  now->l = build(L, mid);
  now->r = build(mid+1, R);
  now->pull();

  return now;
}

int querymax (Node* now, int L, int R, int x, int y, bool isMax) {
  if (x > R || y < L) {
    if (isMax) {
      return -INF;
    } else {
      return INF;
    }
  }

  if (x <= L && y >= R) {
    if (isMax) {
      return now->valmax;
    } else {
      return now->valmin;
    }
    
  }

  int mid = (L+R) >> 1;
  if (isMax) {
    return max(querymax(now->l, L, mid, x, y, isMax), querymax(now->r, mid+1, R, x, y, isMax));
  } else {
    return min(querymax(now->l, L, mid, x, y, isMax), querymax(now->r, mid+1, R, x, y, isMax));
  }
}
