#include <bits/stdc++.h>
using namespace std;

int n, x, a[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0, j = 0;
    for(int i = 1; i <= n; i++){
        while(j < n && sum + a[j + 1] <= x) j++, sum += a[j];
        if(sum == x){
            cout << i << ' ' << j << '\n';
            return 0;
        }
        sum -= a[i];
    }
    cout << "No solution\n";

}


