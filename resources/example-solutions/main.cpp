#include <bits/stdc++.h>
using namespace std;

// O(sqrt n)
bool is_prime(int n){
	if(n < 2) return false;
	for(int x = 2; x * x <= n; x++){
		if(n % x == 0) return false;
	}
	return true;
}

// O(sqrt n)
vector<int> factors(int n){
	vector<int> f;
	for(int x = 2; x * x <= n; x++){
		while(n % x == 0){
			f.push_back(x);
			n /= x;
		}
	}
	if(n > 1) f.push_back(n);
	return f;
}


// O(n log log n)
int sieve[1000005];
void compute_sieve(int n){
	for(int x = 2; x <= n; x++){
		if(sieve[x]) continue;
		for(int u = 2 * x; u <= n; u += x){
			sieve[u] = x;
		}
	}
}

// O(log n)
vector<int> factors_from_sieve(int n){
	vector<int> f;
	while(sieve[n]){
		f.push_back(sieve[n]);
		n /= sieve[n];
	}
	if(n > 1) f.push_back(n);
	return f;
}

// O(log a)
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

// O(log n)
int modpow_recursive(int x, int n, int mod){
	if(n == 0) return 1;
	long long u = modpow(x, n/2, mod);
	u = (u * u) % mod;
	if(n % 2) u = (u * x) % mod;
	return u;
}

// O(log n)
int modpow_iterative(int x, int n, int mod){
	long long ans = 1, u = x;
	while(n > 0){
		if(n % 2){
			ans = (ans * y) % mod;
		}
		u = (u * u) % mod;
		n /= 2;
	}
	return ans;
}

// O(log n)
int modpow_iterative_bitmask(int x, int n, int mod){
	long long ans = 1, u = x;
	for(int i = 0; (1 << i) <= n; i++){
		if(n & i) ans = (ans * u) % mod;
		u = (u * u) % mod;
	}
	return ans;
}

// O(log mod)
int modular_inverse(int x, int mod){
	return modpow_recursive(x, mod - 2, mod);
}


// O(n)
long long factorial[1000005], inverse_factorial[1000005];
void compute_factorials(int n, int mod){
	factorial[0] = 1; inverse_factorial[0] = 1;
	for(int i = 1; i <= n; i++){
	    factorial[i] = (factorial[i-1] * i) % mod;
	    inverse_factorial[i] = modular_inverse(factorial[i], mod);
	}
}


// O(1)
int binomial(int a, int b, int mod){
    if(a < b || b < 0 || a < 0) return 0;
    return (((factorial[a] * inverse_factorial[b]) % mod) * inverse_factorial[a - b]) % mod;
}
