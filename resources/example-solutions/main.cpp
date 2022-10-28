#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
queue<int> q;
bool visited[100005];
int dist[100005];


void bfs(int x) {
    visited[x] = true;
    dist[x] = 0;
    q.push(x);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for(int u : adj[s]) {
            if(visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s] + 1;
            q.push(u);
        }
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

    bfs(1);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << ' ';
    }
    cout << '\n';

    

}