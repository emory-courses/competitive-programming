#include <bits/stdc++.h>
using namespace std;

int n, a[100005], nse[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    stack<int> s;
    for(int i = 1; i <= n; i++){
        while(s.size() > 0 && s.top() > a[i]) s.pop();
        if(s.size() > 0) nse[i] = s.top();
        else nse[i] = -1;
        s.push(a[i]);
    }
    for(int i = 1; i <= n; i++) cout << nse[i] << ' ';
    cout << '\n';

}


