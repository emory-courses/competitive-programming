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

ll count(ll rs) {
	ll l = isqrt(rs / 2);
	ll res = 0;
	for (ll i = l + 1; i*i <= rs; i++) {
		res += isqrt(rs - i*i);
	}
	return res * 8 + l * l * 4;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;

	n++;

	ll l = 0;
	ll r = 1'000'000'000;
	while (l + 1 < r) {
		ll m = (l + r) / 2;
		if (count(m) >= n) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << fixed << setprecision(10) << sqrt(r) << endl;
}
