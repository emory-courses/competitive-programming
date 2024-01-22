#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
 
const int mx=32;
const int mx2=2e5+7;
vector<vector<int>> cumul(mx2,vector<int>(mx,0));
vector<int> cumul2(mx2,0);
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n,k,q; cin>>n>>k>>q;
  vector<int> a(n+1,0);
  for (int i=1; i<=n; i++) cin>>a[i];
  for (int i=1; i<=n; i++) {
    for (int j=0; j<mx; j++) {
      if((a[i]&(1LL<<j))&&((a[i]&k)==k)) cumul[i][j]++;
      cumul[i][j]+=cumul[i-1][j];
    }
    if((a[i]&k)==k) cumul2[i]++;
    cumul2[i]+=cumul2[i-1];
  }
  while(q--) {
    int l,r; cin>>l>>r;
    bool ok=true;
    for (int i=0; i<mx; i++) {
      bool x=(cumul[r][i]-cumul[l-1][i]==cumul2[r]-cumul2[l-1]);
      bool y=k&(1<<i);
      if(x!=y) ok=false;
    }
    cout<<(ok?"YES":"NO")<<"\n";
  }
  return 0;
}

