#include <bits/stdc++.h>
using namespace std;
 
#define FOR(x,n) for(int x=0;x<n;x++)
#define FORR(x,a,b) for(int x=a;x<=b;x++)
using ll = long long;
using ii = pair<int,int>;
 
const ll MOD = 998244353;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  ll n, q;
  cin >> n >> q;
  vector<vector<pair<ll,ll>>> update_ranges;
  vector<ll> update_xs;
  FOR(i,q) {
    string ty;
    cin >> ty; 
    vector<pair<ll,ll>> ranges(n);
    FOR(i,n) cin >> ranges[i].first >> ranges[i].second;
    if(ty == "SUM") {
      if(n > 100) cout << "0\n";
      else {
        ll ans = 0;
        FOR(i,(int)update_ranges.size()) {
          ll contr = update_xs[i];
          FOR(j,n) {
            auto [l, r] = ranges[j];
            auto [ul, ur] = update_ranges[i][j];
            ll len = max((ll)0, min(r, ur) - max(l, ul) + 1);
            contr = (contr * len) % MOD;
          }
          ans = (ans + contr) % MOD;
        }
        cout << ans << '\n';
      }
    }
    else {
      assert(ty == "ADD");
      ll x;
      cin >> x;
      if(n <= 100) {
        update_ranges.push_back(ranges);
        update_xs.push_back(x);
      }
    }
  }
}

