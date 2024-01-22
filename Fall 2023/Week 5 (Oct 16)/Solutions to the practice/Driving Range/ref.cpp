#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MP make_pair
#define A first
#define B second

#define PB push_back
#define FR(i, a, b) for(int i=(a); i<(b); i++)
#define FOR(i, n) FR(i, 0, n)
#define RF(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define ROF(i, n) RF(i, 0, n)
#define EACH(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end(); ++it)

const int MAXNM = 1000100;

pair<int, pair<int, int> > elis[MAXNM];
int n, m, ans, cou;

int pre[MAXNM];

int getp(int p){ return (pre[p] == pre[pre[p]]) ? pre[p] : (pre[p] = getp(pre[p]));}

int main() {
  scanf("%d%d", &n, &m);
  while(n != 0 || m != 0) {
    for(int i = 0; i < m; ++i) {
      scanf("%d%d%d", &elis[i].B.A, &elis[i].B.B, &elis[i].A);
    }
    sort(elis, elis + m);
    for(int i = 0; i < n; ++i) pre[i] = i;
    ans = -1; cou = 0;
    for(int i = 0; i < m; ++i) {
      int a = getp(elis[i].B.A);
      int b = getp(elis[i].B.B);
      if(a != b) {
        pre[b] = a;
        cou++;
        ans = elis[i].A;
      }
    }
    if(cou != n - 1) puts("IMPOSSIBLE");
    else printf("%d\n", ans);
    scanf("%d%d", &n, &m);
  }
  return 0;
}

