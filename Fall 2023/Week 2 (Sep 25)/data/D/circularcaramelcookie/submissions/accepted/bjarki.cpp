#include <bits/stdc++.h>
using namespace std;

int main() {
	int s;
	cin >> s;
	double lo = 0.0,
	       hi = 1e5,
	       res;
	for (int it = 0; it < 100; it++) {
		double r = (lo+hi)/2.0;
		long long cnt = 0;
		for (int y = 1; y <= r; y++) {
			cnt += 4*(int)sqrt(r*r - y*y);
		}
		if (cnt <= s) {
			lo = r;
		} else {
			hi = r;
			res = r;
		}
	}
	cout << setprecision(12) << res << endl;
	return 0;
}
