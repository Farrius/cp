    #include <bits/stdc++.h>
     
    using namespace std;
    using ll = long long;
    using ld = long double;
     
    const int MOD = 1e9 + 7;
    const int MX = 2e5 + 5;
     
    int fact[MX];
    int power (int n, int k) {
    	int res = 1;
    	while (k) {
    		if (k % 2) res = (res * 1LL * n) % MOD;
    		n = (n * 1LL * n) % MOD;
    		k /= 2;
    	}
    	return res;
    }
     
    int ncr (int n, int k) {
    	if (k > n) return 0;
    	int div = (fact[k] * 1LL * fact[n - k]) % MOD;
    	div = power(div, MOD - 2);
    	int res = (fact[n] * 1LL * div) % MOD;
    	return res;
    }
     
    int main () {
    	fact[0] = 1;
    	for (int i = 1; i < MX; i++) {
    		fact[i] = (fact[i - 1] * 1LL * i) % MOD;
    	}
    	int t;
    	cin >> t;
    	while (t--) {
    		int n, m, k;
    		cin >> n >> m >> k;
    		vector<int> freq(n + 1), pref(n + 1);
    		for (int i = 0; i < n; i++) {
    			int x;
    			cin >> x;
    			freq[x]++;
    		}
    		for (int i = 1; i <= n; i++) {
    			pref[i] = pref[i - 1] + freq[i];
    		}
    		int sol = 0;
    		for (int i = 1; i <= n; i++) {
    			for (int j = 1; j <= min(freq[i], m); j++) {
    				int sum = (ncr(freq[i], j) * 1LL * ncr(pref[i - 1] - pref[max(0, i - k - 1)], m - j)) % MOD;
    				sol = (sol + 0LL + sum) % MOD;
    			}
    		}
    		cout << sol << '\n';
    	}
    }
