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
  
  ll a, b, c;
  cin >> a >> b >> c;
  vector<int> ycoords(a), xcoords(b);
  FOR(i,a) cin >> ycoords[i];
  FOR(i,b) cin >> xcoords[i];
  sort(ycoords.begin(), ycoords.end());
  sort(xcoords.begin(), xcoords.end());
  ll total = (a + 1) * (b + 1), blue = total/2, red = total - blue;
  FOR(i,c) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    auto xit = lower_bound(xcoords.begin(), xcoords.end(), x1);
    auto yit = lower_bound(ycoords.begin(), ycoords.end(), y1);
    ll width = upper_bound(xcoords.begin(), xcoords.end(), x2) - xit + 1;
    ll height = upper_bound(ycoords.begin(), ycoords.end(), y2) - yit + 1;
    assert(width >= 2 && height >= 2);
    ll inwidth = width - 2, inheight = height - 2;
    bool cred = ((xit - xcoords.begin()) + (yit - ycoords.begin())) % 2 == 0;
    ll addred = (width * height)/2, addblue = (width * height) - addred;
    ll inblue = (inwidth * inheight)/2, inred = (inwidth * inheight) - inblue;
    if(!cred) {
      swap(addblue, addred);
      swap(inblue, inred);
    }
    blue += addblue - inblue;
    red += addred - inred;
  }
  cout << "2 " << min(blue, red) << ' ' << max(blue, red) << '\n';
}
