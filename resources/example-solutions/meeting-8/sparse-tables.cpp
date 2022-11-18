#include <bits/stdc++.h>
using namespace std;

int n, q, a[100005], s[20][100005], lg[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int k = 20; //log n

    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;


    for(int i = 1; i <= n; i++) s[0][i] = a[i];
    for(int j = 1; j < k; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            s[j][i] = max(s[j - 1][i], s[j - 1][i + (1 << (j-1))]);
        }
    }

    int l, r, answer;
    cin >> q;
    while(q--){
        cin >> l >> r;
        int t = lg[r - l + 1];
        answer = max(s[t][l], s[t][r - (1 << t) + 1]);
        cout << answer << '\n';
    }

}
