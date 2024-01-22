#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

const int N = 300009;

int bp(int a, int n) {
    int res = 1;
    while(n > 0) {
        if (n & 1)
            res = (res * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
        n >>= 1;
    }
    return res;
}

int n, m;
string s;
int inv[N];

void upd(int &res, int x) {
    res = (res * 1LL * x) % MOD;
}

int main() {
    inv[1] = 1;
    for (int i = 2; i < N; ++i){
	    inv[i] = bp(i, MOD - 2);
    }
    
    cin >> n >> m >> s;
    
    int res = 1, k = n;
    bool isZero = false;
    for (int i = 0; i < s.size(); ++i) 
        if (s[i] == '?') {
            if (i == 0) {
                isZero = true;
            } else {
                upd(res, i);
            }
        }
    
    cout << (isZero? 0 : res) << endl;
    
    for(int i = 0; i < m; ++i) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;
        
        if (s[pos] == '?' && (c == '<' || c == '>')) {
            if (pos == 0)
                isZero = false;
            else
                upd(res, inv[pos]);
        } else if ((s[pos] == '<' || s[pos] == '>') && c == '?') {
            if (pos == 0)
                isZero = true;
            else
                upd(res, pos);
        }
        
        s[pos] = c;
        cout << (isZero? 0 : res) << endl;
    }
    return 0;
}
