#include <bits/stdc++.h>
using namespace std;

int n, m, parent[100005], set_size[100005];
struct edge{
    int x, y, w;
};
vector<edge> edges;

bool comp(edge a, edge b){
    return a.w < b.w;
}

int FindParent(int node){
    if(parent[node] == parent[parent[node]]) return parent[node];
    return parent[node] = FindParent(parent[node]);
}

void Unite(int x, int y){
    x = FindParent(x);
    y = FindParent(y);
    if(set_size[x] < set_size[y]) swap(x,y);
    parent[y] = x;
    set_size[x] += set_size[y];
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    int a,b,c;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    for(int i = 1; i <= n; i++) parent[i] = i, set_size[i] = 1;
    int mst_sum = 0;
    sort(edges.begin(), edges.end(), comp);
    for(edge e : edges){
        if(FindParent(e.x) != FindParent(e.y)){
            mst_sum += e.w;
            Unite(e.x, e.y);
        }
    }

    cout << mst_sum << '\n';
    

}