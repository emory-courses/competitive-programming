#include <bits/stdc++.h>
using namespace std;

// Find all occurrences of t in s
string s, t;
long long hashs[100005], hasht, base_power[100005], inv_base_power[100005];

long long mod = 1000000007;

long long pwr(long long a, long long p){
    long long ans = 1;
    while(p > 0){
        if(p & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return ans;
}

long long base = 37, inv_base = pwr(base, mod - 2);

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> s >> t;
    int n = s.length(), m = t.length();

    base_power[0] = 1;
    inv_base_power[0] = 1;
    for(int i = 1; i < max(n, m); i++){
        base_power[i] = (base_power[i - 1] * base) % mod;
        inv_base_power[i] = (inv_base_power[i - 1] * inv_base) % mod;
    }

    hashs[0] = s[0];
    for(int i = 1; i < n; i++){
        hashs[i] = (hashs[i - 1] + s[i] * base_power[i]) % mod;
    }

    hasht = t[0];
    for(int i = 1; i < m; i++){
        hasht = (hasht + t[i] * base_power[i]) % mod;
    }

    if(hashs[m - 1] == hasht) cout << 0 << ' ';
    for(int i = m; i < n; i++){
        if(((hashs[i] - hashs[i - m] + mod) * inv_base_power[i - m + 1]) % mod == hasht)
            cout << i - m << ' ';
    }
    cout << '\n';




}
