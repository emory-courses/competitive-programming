#include <bits/stdc++.h>
using namespace std;

int n, q, a[100005], s[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }

    int l, r, answer;
    cin >> q;
    while(q--){
        cin >> l >> r;
        answer = s[r] - s[l - 1];
        cout << answer << '\n';
    }

}
