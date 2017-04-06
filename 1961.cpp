#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX 1000010

char in[MAX];
int p[MAX];
int len, caseNum = 1;

int main() {
  int i, cur_pos;
  while(scanf("%d", &len) != EOF && len != 0) {
    gets(in);
    gets(in);
    p[0] = -1;
    cur_pos = -1;
    printf("Test case #%d\n", caseNum++);
    for (i = 1; i < len; i++) {
      while(cur_pos >= 0 && in[i] != in[cur_pos+1]) {
        cur_pos = p[cur_pos];
      }
      if (in[i] == in[cur_pos+1]) {
        cur_pos++;
      }
      p[i] = cur_pos;
      if (cur_pos >= 0 && (i+1)%(i-cur_pos) == 0) {
        printf("%d %d\n", i+1, (i+1)/(i-cur_pos));
      }
    }
    printf("\n");
  }
  return 0;
}
