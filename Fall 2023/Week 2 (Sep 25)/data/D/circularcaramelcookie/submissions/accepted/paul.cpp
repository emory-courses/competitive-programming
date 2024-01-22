#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int count_squares(double r) {
	int res = 0;
	for (int x = 1; x <= r; x++) {
		res += int(sqrt(r*r-x*x));
	}
	return 4*res;
}

int main() {
	int s; cin >> s;

	double lo = 0, hi = 18000;
	for (int k = 0; k < 100; k++) {
		double md = (lo+hi)/2;
		(count_squares(md) > s ? hi : lo) = md;
	}
	cout << fixed << setprecision(20) << lo << '\n';
}
