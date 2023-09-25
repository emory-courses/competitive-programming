#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

using ll = long long;
using ld = long double;

ll isqrt(ll x) {
	//return sqrtl(x); is probably fine too...
	ll l = 0;
	ll r = 1'000'000'001;
	while (l + 1 < r) {
		ll m = (l + r) / 2;
		if (m*m <= x) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

ll count(ll rs, ll lim) {
	ll res = -isqrt(rs);
	for (ll i = 0; i < 100000 && 4 * res < lim; i++) {
		res += rs / (4 * i + 1);
		res -= rs / (4 * i + 3);
	}
	return res * 4;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;

	ll l = 0;
	ll r = 1'000'000'000;
	while (l + 1 < r) {
		ll m = (l + r) / 2;
		if (count(m, n) >= n) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << fixed << setprecision(10) << sqrt(r) << endl;
}
