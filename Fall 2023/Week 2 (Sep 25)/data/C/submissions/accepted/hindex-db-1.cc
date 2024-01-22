#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;

  vector<int> A(n);
  for(auto& x : A) cin >> x;

  sort(begin(A), end(A));
  
  int ans = 0;
  for(int i=n-1;i>=0;i--)
    if(A[i] >= n-i)
      ans = n-i;
  
  cout << ans << endl;
}
