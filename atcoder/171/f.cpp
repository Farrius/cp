#include <bits/stdc++.h>

using namespace std;

typedef  long long ll;

const ll MOD = 1e9 + 7;

const int maxN = 2 * 1e6 + 7;

int fact[maxN];

ll power(ll n, ll k){
	ll res = 1;
	while(k){
		if(k % 2) res = (res * n) % MOD;
		n = (n * n) % MOD;
		k /= 2;
	}
	return res;
}

ll inverse(ll n){
	return power(n, MOD - 2);
}

ll ncr(ll n, ll k){
	if(n < k) return 0;
	if(k == 0 || n == k) return 1;
	ll fact_n = fact[n];
	fact_n = (fact_n * inverse(fact[n - k])) % MOD;
	fact_n = (fact_n * inverse(fact[k])) % MOD;
	return fact_n;
}

int main(){
	int k;
	string s;
	cin >> k >> s;
	int size_s = s.size();
	int n = k + size_s;
	fact[0] = fact[1] = 1;
	for(int i = 2; i < maxN; i++){
		fact[i] = (fact[i - 1] * 1LL * i) % MOD;
	}
	int ans = 0;
	for(int i = size_s; i <= n; i++){
		int cur = (power(25, n - i) * 1LL *  ncr(n, i)) % MOD;
		ans = (ans + cur) % MOD;
	}
	cout << ans << '\n';
}
