#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000010

char in[MAX];
int KMP[MAX], len, k;

int find_KMP(char *c);

int main() {
  int i, j;

  while (gets(in)) {
    if (in[0] == '.' || in[0] == '\0') {
      break;
    }
    
    len = strlen(in);
    k = find_KMP(in);
    
    if (len%(len-k-1) == 0) {
      printf("%d\n", len/(len-k-1));
    } else {
      printf("1\n");
    }
  }
  return 0;
}

int find_KMP(char *B) {
  int i, cur_pos;
  int P[MAX];
  P[0] = -1;
  i = 1;
  cur_pos = -1;
  for (i = 1; i < len; i++) {
    while (cur_pos >= 0 && B[i] != B[cur_pos+1]) {
      cur_pos = P[cur_pos];
    }
    if (B[i] == B[cur_pos+1]) {
      cur_pos++;
    }
    P[i] = cur_pos;
  }
  return cur_pos;
}
