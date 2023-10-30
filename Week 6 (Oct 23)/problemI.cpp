#include <bits/stdc++.h>
using namespace std;
 
#define FOR(x,n) for(int x=0;x<n;x++)
#define FORR(x,a,b) for(int x=a;x<=b;x++)
using ll = long long;
using ii = pair<ll,ll>;
 
const string PHEBE = "PHEBE", RYAN = "RYAN";
 
string solve(ll k, ll tot_ct, ll tot_sum, set<ii>& pa) {
  string stall_winner = (tot_ct & 1 ? PHEBE : RYAN);
  if(tot_sum < k) return stall_winner;
  else if(tot_sum == k) return (tot_ct & 1 ? RYAN : PHEBE); 
  auto [ct_i, i] = *pa.rbegin();
  assert(ct_i > 0);
  if((tot_sum - k) % i != 0) return stall_winner;
  ll d = (tot_sum - k)/i, rem = ct_i - d;
  if(rem <= 0) return stall_winner;
  if((rem + tot_ct - ct_i) & 1) return (rem > tot_ct - ct_i) ? RYAN : stall_winner;
  else {
    if(tot_ct - ct_i > 0) return (rem > tot_ct - ct_i - 1) ? PHEBE : stall_winner;
    else {
      assert(rem >= 2 && rem % 2 == 0);
      return PHEBE;
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  int n, q;
  ll tot_ct = 0, tot_sum = 0;
  cin >> n >> q;
  vector<ll> a(n + 1);
  set<ii> pa;
  FORR(i,1,n) {
    cin >> a[i];
    pa.insert({a[i], i});
    tot_ct += a[i];
    tot_sum += a[i] * i;
  }
  while(q--) {
    string t;
    ll i, x, k;
    cin >> t;
    if(t == "SET") {
      cin >> i >> x; 
      pa.erase({a[i], i});
      tot_ct -= a[i];
      tot_sum -= a[i] * i;
      a[i] = x;
      pa.insert({a[i], i});
      tot_ct += a[i];
      tot_sum += a[i] * i;
    }
    else {
      assert(t == "?");
      cin >> k;
      cout << solve(k, tot_ct, tot_sum, pa) << '\n';
    }
  }
}
