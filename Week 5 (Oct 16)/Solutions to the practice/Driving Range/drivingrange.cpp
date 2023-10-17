#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

struct Edge {
    int frm;
    int to;
    int v;

    Edge(int frm, int to, int v): frm(frm), to(to), v(v) {}
};

bool operator<(const Edge &a, const Edge &b) {
    return a.v < b.v;
}

int find(int x, vector<int>& father) {
    if (father[x] != x) {
        father[x] = find(father[x], father);
    }
    return father[x];
}

vector<pair<int, int>> kruskal(vector<Edge>& edges, int n) {
    vector<int> father(n+1);
    for(int i = 0; i <= n; i++) {
        father[i] = i;
    }

    sort(edges.begin(), edges.end());

    int res = 0;
    vector<pair<int, int>> result;
    for (int i = 0; i < edges.size(); i++) {
        if (res == n - 1) {
            break;
        }
        int fx = find(edges[i].frm, father);
        int fy = find(edges[i].to, father);
        if (fx != fy) {
            father[fy] = fx;
            result.push_back({edges[i].frm, edges[i].to});
            res += 1;
        }
    }
    return result;
}

int main() {
    map<pair<int, int>, int> maps;
    unordered_map<int, unordered_map<int, int>> G;
    vector<Edge> edges;

    int vertex, e;
    cin >> vertex >> e;

    if (e == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) {
            swap(a, b);
        }

        if (maps.find({a, b}) == maps.end()) {
            maps[{a, b}] = c;
            edges.push_back(Edge(a, b, c));
            G[a][b] = c;
        } else {
            if (c <= maps[{a, b}]) {
                G[a][b] = c;
            }
        }
    }

    auto result = kruskal(edges, vertex);

    if (result.size() != vertex - 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int l = -1;
        for (auto i: result) {
            if (G[i.first][i.second] > l) {
                l = G[i.first][i.second];
            }
        }
        cout << l << endl;
    }

    return 0;
}
