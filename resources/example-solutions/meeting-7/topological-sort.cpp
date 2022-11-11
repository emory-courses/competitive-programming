#include <bits/stdc++.h>
using namespace std;

int n, m, indegree[100005];
vector<int> g[100005], topological_sort;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    int a,b;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(q.size()){
        int node = q.front();
        q.pop();
        topological_sort.push_back(node);
        for(int u : g[node]){
            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
    }

    for(int i : topological_sort){
        cout << i << ' ';
    }
    cout << '\n';

    
    

}
