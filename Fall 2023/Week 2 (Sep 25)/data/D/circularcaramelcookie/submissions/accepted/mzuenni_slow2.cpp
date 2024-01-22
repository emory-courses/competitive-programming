#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

using ll = long long;
using ld = long double;

ll isqrt(ll x) {
	return sqrtl(x);
}

ll count(ll rs) {
	ll res = 0;
	for (ll i = 1; i*i <= rs; i++) {
		res += isqrt(rs - i*i);
	}
	return res * 4;
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
