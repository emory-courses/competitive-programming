#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n; cin>>n;
  for (int i=1; i<=n; i++) {
    if(i>1) cout<<" ";
    cout<<i;
  }
  cout<<"\n";
  return 0;
}
