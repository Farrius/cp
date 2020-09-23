#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int fact(int n){
	int res = 1;
	for(int i = 2; i <= n; i++){
		res = (res * 1LL * i) % MOD;
	}
	return res;
}

int power(int n, int k){
	int res = 1;
	while(k){
		if(k % 2) res = (res * 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}
	return res;
}

int inverse(int n){
	return power(n, MOD - 2);
}

int ncr(int n, int k){
	if(k > n) return 0;
	int fact_n = fact(n);
	int inverse_k = inverse(k);
	int inverse_k2 = inverse(n - k);
	fact_n = (fact_n * 1LL * inverse_k) % MOD;
	fact_n = (fact_n * 1LL * inverse_k2) % MOD;
	return fact_n;
}

int main(){
	int n;
	cin >> n;
	map<pair<int,int>, map<int, int>> mp;
	int sol = power(2, n) - 2;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		pair<int, int> key = {min(abs(a), abs(b)), max(abs(a), abs(b))};
		int negs = 0;
		if(a < 0) negs++;
		if(b < 0) negs++;
		mp[key][negs]++;
	}
	int zeros = mp[make_pair(0, 0)].size();
	int zres = ncr(zeros, 2);
	sol = (((sol - zres) % MOD) + MOD) % MOD;
	cout << sol << '\n';
	auto it = mp.begin();
	while(it != mp.end()){
		if(it -> first == make_pair(0, 0)){
			it++;
			continue;
		}
		int res1 = (ll)(it -> second)[0] * (it -> second)[1];
		int res2 = (ll)(it -> second)[2] * (it -> second)[1];
		res1 = (ll)(res1 + res2) % MOD;
		sol = (((sol - res1) % MOD) + MOD) % MOD;
		it++;
	}
	cout << sol << '\n';
}











