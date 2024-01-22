#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define pb push_back
#define fs first
#define sc second
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const double EPS = 1e-9;

double d(double a, double b) {
    return sqrt((a * a) + b*b);
}

int main() {
    cin.sync_with_stdio(false);
    int s;
    cin >> s;
    double lo = 0, hi = 1'000'000;
    rep(i,0,50) {
        double mid = (lo+hi)/2;
        ll total = 0;
        for(int j = (int)mid+2; j >= 1; j--) {

            if(j > mid) continue;
            int l1 = 0, h1 = mid+1;
            int bst = 0;
            while(l1 <= h1) {
                int p1 = (l1+h1)/2;
                double D = d(j, p1);
                if(D <= mid) {
                    bst = p1;
                    l1 = p1 + 1;
                } else {
                    h1 = p1 - 1;
                }
            }
            total += (bst);
        }
        total *= 4;
        if(total > s) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << setprecision(10) << fixed << lo << endl;
}

