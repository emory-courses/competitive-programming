#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(c.rbegin(), c.rend());
  int ans = 0;
  for (int i = 0; i < c.size(); i++) {
    if (c[i] >= i+1) ans = i+1;
  }
  cout << ans << endl;
  return 0;
}
