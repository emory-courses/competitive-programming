#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
bool visited[100005];


void dfs(int s) {
    if(visited[s]) return;
    visited[s] = true;
    for(int u : adj[s]) {
        dfs(u);
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    int a, b;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            answer++;
            dfs(i);
        }
    }
    cout << answer << '\n';

    

}
