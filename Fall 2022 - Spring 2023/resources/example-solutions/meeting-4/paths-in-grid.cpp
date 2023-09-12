#include <bits/stdc++.h>
using namespace std;

int n, a[1005][1005], dp[1005][1005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    cout << dp[n][n] << '\n';
    

}
