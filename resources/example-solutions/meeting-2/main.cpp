#include <bits/stdc++.h>
using namespace std;

int n, a[100005], s[100005], q, l, r;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
    	s[i] = s[i - 1] + a[i];
    }

    cin >> q;
    for(int i = 1; i <= q; i++){
    	cin >> l >> r;
    	cout << a[r] - a[l - 1] << '\n';
    }
    

}