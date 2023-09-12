#include <bits/stdc++.h>
using namespace std;

string sa, sb;
int a[100005];
vector<int> v;
set<int> s;
multiset<int> ms;
map<string,int> m;


int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    sa = "ABC";
    sb = sa + "abc" + 'z';
    cout << sb << '\n';
    sb[3] = 'F';
    cout << sb << "\n\n";

    for(int i=0;i<5;i++) a[i] = 10 - i;
    for(int i=0;i<5;i++) cout << a[i] << ' ';
    cout << '\n';
    sort(a, a + 5);
    for(int i=0;i<5;i++) cout << a[i] << ' ';
    cout << "\n\n";

    for(int i=1;i<=5;i++) a[i] = i;
    for(int i=1;i<=5;i++) cout << a[i] << ' ';
    cout << '\n';
    sort(a + 1, a + 6, greater<int>());
    for(int i=1;i<=5;i++) cout << a[i] << ' ';
    cout << "\n\n";

	for(int i=0;i<5;i++) v.push_back(10 - i);
    for(int i=0;i<v.size();i++) cout << v[i] << ' ';
    cout << '\n';
    sort(v.begin(), v.end());
    v.pop_back();
    for(int i : v) cout << i << ' ';
    cout << "\n\n";

	for(int i=0;i<5;i++) s.insert(10 - i);
	for(int i=0;i<5;i++) s.insert(10 - i);
    for(int i : s) cout << i << ' ';
    cout << '\n';
	s.erase(6);
	for(int i : s) cout << i << ' ';
    cout << '\n';
    cout << s.size() << ' ' << (*(s.begin())) << ' ' << (*(s.rbegin())) << "\n\n";

    for(int i=0;i<5;i++) ms.insert(10 - i);
	for(int i=0;i<5;i++) ms.insert(10 - i);
    for(int i : ms) cout << i << ' ';
    cout << '\n';
	ms.erase(6);
	ms.erase(ms.find(7));
	for(int i : ms) cout << i << ' ';
    cout << '\n';
    cout << ms.size() << ' ' << (*(ms.begin())) << ' ' << (*(ms.rbegin())) << "\n\n";

    m[sa] = 10;
    m[sb] = 5;
    cout << m[sa] << ' ' << m[sb] << ' ' << m["hello"] << '\n';
    for(pair<string,int> x : m){
    	cout << x.first << " -> " << x.second << '\n';
    }
    cout << '\n';


}
