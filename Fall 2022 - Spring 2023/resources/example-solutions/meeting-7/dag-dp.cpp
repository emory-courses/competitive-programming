#include <bits/stdc++.h>
using namespace std;

int n, m, indegree[100005], dp[100005];
vector<pair<int,int>> g[100005];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    int a,b,c;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        indegree[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(q.size()){
        int node = q.front();
        q.pop();
        for(pair<int,int> u : g[node]){
            indegree[u.first]--;
            dp[u.first] = max(dp[u.first], dp[node] + u.second);
            if(indegree[u.first] == 0){
                q.push(u.first);
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        answer = max(answer, dp[i]);
    }
    cout << answer << '\n';

    
    

}
