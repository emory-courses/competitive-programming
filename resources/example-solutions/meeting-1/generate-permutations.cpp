#include <bits/stdc++.h>
using namespace std;

int n;

int a[20], visited[20];
void GeneratePermutations(int p){
	if(p == n){
		for(int i = 0; i < n; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			a[p] = i;
			visited[i] = 1;
			GeneratePermutations(p + 1);
			visited[i] = 0;
		}
	}
}


int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;

    GeneratePermutations(0);


}
