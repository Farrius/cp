#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MX = 1e6 + 6;
const int MOD = 998244353;
 
vector<int> kids[MX], cnt(MX), inv(MX);
 
int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res = (res * 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}
	return res;
}
 
int main () {
	int n;
	cin >> n;
 
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			kids[i].push_back(x);
			cnt[x]++;
		}
	}
	
	for (int i = 1; i < MX; i++) {
		inv[i] = power(i, MOD - 2);
	}
 
	int sol = 0;
 
	for (int i = 1; i <= n; i++) {
		for (auto y: kids[i]) {
			int suma = (((inv[n] * 1LL * inv[(int) kids[i].size()]) % MOD) * 1LL * ((inv[n] * 1LL * cnt[y]) % MOD)) % MOD;
			sol = (sol + 0LL + suma) % MOD;
		}	
	}
	
	cout << sol << '\n';
}	

