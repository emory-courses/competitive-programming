#include <bits/stdc++.h>
using namespace std;

int n, a[100005], k, l, r, t;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    cin >> k;

    // First element >= k
    l = 0, r = n - 1;
    while(l != r){
    	int mid = (l + r) / 2;
    	if(a[mid] < k) l = mid + 1;
    	else r = mid;
    }
    if(a[l] < k) cout << "No answer\n";
    else cout << a[l] << '\n';


    // Last element <= k
    l = 0, r = n - 1;
    while(l != r){
    	int mid = (l + r + 1) / 2;
    	if(a[mid] <= k) l = mid;
    	else r = mid - 1;
    }
    if(a[l] > k) cout << "No answer\n";
    else cout << a[l] << '\n';


    // First element >= k
    t = n - 1;
    for(int i = 20; i >= 0; i--){
    	if(t - (1 << i) >= 0 && a[t - (1 << i)] >= k) t -= (1 << i);
    }
    if(a[t] < k) cout << "No answer\n";
    else cout << a[t] << '\n';


    // Last element <= k
    t = 0;
    for(int i = 20; i >= 0; i--){
    	if(t + (1 << i) < n && a[t + (1 << i)] <= k) t += (1 << i);
    }
    if(a[t] > k) cout << "No answer\n";
    else cout << a[t] << '\n';

}
