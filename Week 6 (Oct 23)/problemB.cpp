#include <bits/stdc++.h>
using namespace std;
 
#define FOR(x,n) for(int x=0;x<n;x++)
#define FORR(x,a,b) for(int x=a;x<=b;x++)
using ll = long long;
using ii = pair<int,int>;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  ll n, h, cur = 0, t = 0;
  cin >> n >> h;
  vector<ll> a(n + 1);
  FORR(i,1,n) cin >> a[i];
  FORR(i,1,n) {
    if(cur != 0 && a[i]) {
      if(h % 2 == 0) {
        t += h - 2; 
        h = 2;
      }
      else {
        t += h - 1;
        h = 1;
      }
    }
    cur++;
    if(a[i]) h += a[i] + t;
    h--; t++;
    if(h >= 1e6) {
      cout << "YES\n";
      exit(0);
    }
    if(h == 0) {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n";
}
