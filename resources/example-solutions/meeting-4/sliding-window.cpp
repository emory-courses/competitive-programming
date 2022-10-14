#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005], minval[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    deque<pair<int,int>> q;
    for(int i = 1; i <= n; i++){
        while(q.size() > 0 && q.back().first >= a[i]) q.pop_back();
        q.push_back({a[i], i});
        if(i >= k){
            minval[i] = q.front().first;
            if(q.front().second == i - k + 1) q.pop_front();
        }
    }
    for(int i = k; i <= n; i++) cout << minval[i] << ' ';
    cout << '\n';

}


