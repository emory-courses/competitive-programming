#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 0; i < (1 << n) - 1; i++){
    	for(int j = 0; j < n; j++){
    		if(i & (1 << j)) cout << j << ' ';
    	}
    	cout << '\n';
    }

}
