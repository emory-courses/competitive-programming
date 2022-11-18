#include <bits/stdc++.h>
using namespace std;

int n, q, a[100005], sg[400005];

void Build(int node, int l, int r){
    if(l == r){
        sg[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    Build(2 * node, l, mid);
    Build(2 * node + 1, mid + 1, r);

    sg[node] = sg[2 * node] + sg[2 * node + 1]; // Or max
}

void Update(int node, int l, int r, int p, int x){
    if(l > p || r < p) return;
    if(l == r){ // Then also l == p
        sg[node] = x;
        return;
    }

    int mid = (l + r) / 2;
    Update(2 * node, l, mid, p, x);
    Update(2 * node + 1, mid + 1, r, p, x);

    sg[node] = sg[2 * node] + sg[2 * node + 1]; // Or max
}

int Query(int node, int l, int r, int lquery, int rquery){
    if(l > rquery || r < lquery) return 0;
    if(l >= lquery && r <= rquery) return sg[node];

    int mid = (l + r) / 2;
    return Query(2 * node, l, mid, lquery, rquery) +
        Query(2 * node + 1, mid + 1, r, lquery, rquery);  // Or max
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    Build(1, 1, n);

    int type, l, r, p, x, answer;
    cin >> q;
    while(q--){
        cin >> type;
        if(type == 0){ // Update Query
            cin >> p >> x;
            Update(1, 1, n, p, x);
        }
        else{ // Answer Query
            cin >> l >> r;
            answer = Query(1, 1, n, l, r);
            cout << answer << '\n';
        }
    }

}