#include <bits/stdc++.h>
using namespace std;

int n, a[100005], dp[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
    	dp[i] = 0;
    	for(int j = 0; j < i; j++){
    		if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
    	}
    }

    int answer = 0;
    for(int i = 1; i <= n; i++) answer = max(answer, dp[i]);
    cout << answer << '\n';
    

}
