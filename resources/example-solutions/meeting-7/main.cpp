#include <bits/stdc++.h>
using namespace std;

int n, m, first[100005], second[100005];
vector<pair<int,int>> g[100005];

void DFS(int node, int parent){ 
    for(pair<int,int> u : g[node]){
        if(u.first == parent) continue;
        DFS(u.first, node);
        int path_val = first[u.first] + u.second;
        if(path_val > first[node]) second[node] = first[node], first[node] = path_val;
        else if(path_val > second[node]) second[node] = path_val;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    int a,b,c;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    DFS(1, -1);

    int answer = 0;
    for(int i = 1; i <= n; i++){
        answer = max(answer, first[i] + second[i]);
    }
    cout << answer << '\n';

    
    

}