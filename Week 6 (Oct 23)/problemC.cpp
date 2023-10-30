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
  
  string s;
  cin >> s;
  int n = (int)s.length(), precs = 0, sufothers = 0;
  for(char c : s) if(c != 'c') sufothers++;
  if(precs == sufothers) {
    cout << "1\n1\n";
    exit(0);
  }
  int bk = -1;
  FOR(i,n) {
    if(s[i] == 'c') precs++;
    else sufothers--;
    if(precs == sufothers) {
      bk = i;
      break;
    }
  }
  assert(bk != -1);
  vector<int> ans;
  FOR(i,bk+1) if(s[i] == 'c') ans.push_back(i + 1);
  FORR(i,bk+1,n-1) if(s[i] != 'c') ans.push_back(i + 1);
  if((int)ans.size() == 0) ans.push_back(1);
  cout << (int)ans.size() << '\n';
  for(int v : ans) cout << v << ' ';
  cout << '\n';
}
