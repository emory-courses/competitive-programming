#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  
  vector<int> A(n);
  for(auto& x : A) cin >> x;
  
  int lo = 0, hi = n+1;
  while(hi > lo + 1){
    int mid = (lo+hi)/2;
    int ctr = count_if(begin(A), end(A), [&](int x){ return x >= mid; });
    (ctr >= mid ? lo : hi) = mid;
  }
  cout << lo << endl;
}
