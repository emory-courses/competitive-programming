#include <bits/stdc++.h>
using namespace std;

int n;

int a[20];
void GenerateSubsetsArray(int p){
	if(p == n){
		for(int i = 0; i < n; i++){
			if(a[i]) cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	a[p] = 0;
	GenerateSubsetsArray(p + 1);
	a[p] = 1;
	GenerateSubsetsArray(p + 1);
}

vector<int> v;
void GenerateSubsetsVector(int p){
	if(p == n){
		for(int i : v){
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	GenerateSubsetsVector(p + 1);
	v.push_back(p);
	GenerateSubsetsVector(p + 1);
	v.pop_back();
}



int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;

    cout << "Array:\n";
    GenerateSubsetsArray(0);
    cout << "\n\n\n";

    cout << "Vector:\n";
    GenerateSubsetsVector(0);


}
