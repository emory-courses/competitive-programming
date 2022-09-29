#include <bits/stdc++.h>
using namespace std;

int n, a[100005], k;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    cin >> k;

    // First element >= k
    int l = 0, r = n - 1;
    while(l != r){
    	int mid = (l + r) / 2;
    	if(a[mid] < k) l = mid + 1;
    	else r = mid;
    }
    if(a[l] < k) cout << "No answer\n";
    else cout << a[l] << '\n';

    // First element <= k
    l = 0, r = n - 1;
    while(l != r){
    	int mid = (l + r + 1) / 2;
    	if(a[mid] <= k) l = mid;
    	else r = mid - 1;
    }
    if(a[l] > k) cout << "No answer\n";
    else cout << a[l] << '\n';


}