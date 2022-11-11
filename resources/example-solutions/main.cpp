#include <bits/stdc++.h>
using namespace std;

int n, m, visited[100005];
vector<pair<int,int>> g[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    int a,b,c;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    int mst_sum = 0;
    set<pair<int,int>> s;
    // element (a, b) in s means we can add node b to our mst through an edge of weight a
    // the set automatically sorts pairs increasingly by the first element
    // so the first element in the set will be the one with minimum edge weight a
    s.insert({0, 1});
    while(s.size()){
        pair<int,int> best = *(s.begin());
        s.erase(s.begin());
        if(!visited[best.second]){
            visited[best.second] = 1;
            mst_sum += best.first;
            for(pair<int,int> u : g[best.second]){
                if(!visited[u.first]){
                    s.insert({u.second, u.first});
                }
            }
        }
    }

    cout << mst_sum << '\n';
    

}