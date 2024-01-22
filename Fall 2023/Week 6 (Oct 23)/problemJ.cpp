#include <bits/stdc++.h>
using namespace std;
 
#define FOR(x,n) for(int x=0;x<n;x++)
#define FORR(x,a,b) for(int x=a;x<=b;x++)
using ll = long long;
using ii = pair<int,int>;
 
const int MX = 1520;
vector<int> adj[MX];
int dp[MX][2];
 
void dfs1(int cur, int prev) {
  dp[cur][1]++; 
  for(int v : adj[cur]) {
    if(v == prev) continue;
    dfs1(v, cur);
    dp[cur][0] += max(dp[v][0], dp[v][1]);
    dp[cur][1] += dp[v][0];
  }
}
 
void dfs2(int cur, int prev, int select, vector<int>& red, vector<int>& blue) {
  if(select == -1) select = dp[cur][0] > dp[cur][1] ? 0 : 1;
  if(select) red.push_back(cur);
  else blue.push_back(cur);
  for(int v : adj[cur]) {
    if(v == prev) continue; 
    if(select) dfs2(v, cur, 0, red, blue);
    else dfs2(v, cur, -1, red, blue);
  }
}
 
void print_op(vector<int>& blue1, vector<int>& blue2, int ex, int inc) {
  int sz = (int)blue1.size() + (int)blue2.size();
  if(ex != -1) sz--;
  if(inc != -1) sz++;
  cout << sz << ' ';
  for(int v : blue1) {
    if(v == ex) continue; 
    cout << v + 1 << ' ';
  }
  for(int v : blue2) {
    if(v == ex) continue;
    cout << v + 1 << ' ';
  }
  if(inc != -1) cout << inc + 1 << ' ';
  cout << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  int n, k;
  cin >> n >> k; 
  FOR(i,n-2) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> red1, blue1, red2, blue2;
  int root1 = -1, root2 = -1;
  FOR(i,n) {
    if(dp[i][1]) continue;
    dfs1(i, -1);
    if(red1.empty()) {
      root1 = i;
      dfs2(i, -1, -1, red1, blue1);
    }
    else {
      root2 = i;
      dfs2(i, -1, -1, red2, blue2);
    }
  }
  assert((int)red1.size() == max(dp[root1][0], dp[root1][1]));
  assert((int)red2.size() == max(dp[root2][0], dp[root2][1]));
  int kn = (int)blue1.size() + (int)blue2.size();
  assert(kn == n - (max(dp[root1][0], dp[root1][1]) + max(dp[root2][0], dp[root2][1])));
  if(kn > k) {
    cout << "NO\n";
    exit(0);
  }
  int leave1 = blue1[0], leave2 = blue2[0];
  cout << 2 * ((int)red1.size() + (int)red2.size()) + 3 << '\n';
  print_op(blue1, blue2, -1, -1);
  for(int r : red2) {
    print_op(blue1, blue2, leave1, -1);
    print_op(blue1, blue2, leave1, r);
  }
  print_op(blue1, blue2, -1, -1);
  for(int r : red1) {
    print_op(blue1, blue2, leave2, r);
    print_op(blue1, blue2, leave2, -1);
  }
  print_op(blue1, blue2, -1, -1);
}

