#include <bits/stdc++.h>
#define f(i, s, k, l) for (int i = s; i < k; i += l)
#define for0(i, k) f(i, 0, k, 1)
#define pb push_back
#define sz(x) (ll)(x).size()

using namespace std;
using pl = pair<long long, long long>;
using ll = long long;
using ld = long double;
using vl = vector<long long>;
using vi = vector<int>;

int main() {
    ll s;
    cin >> s;

    s++;

    ld l = 0;
    ld r = 100000;
    for0(i, 200) {
        ld mid = (l + r) / 2;
        ll sum = 0;
        for0(j, (ll) mid) sum += (ll) sqrt((mid * mid - ((j + 1) * (j + 1))));
        if(4 * sum >= s) r = mid;
        else l = mid;
    }

    cout << fixed << setprecision(10) << r << endl;
}