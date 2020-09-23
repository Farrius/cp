#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main(){
	ll n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	if(a[n - 1] == 0 && k % 2){
		cout << 0 << '\n';
		return 0;
	}
	int sol = 1;
	if(a[n - 1] <= 0 && k % 2){
		for(int i = n - 1;  i >= n - k; i--){
			sol = (sol * 1LL * a[i] + MOD) % MOD;
		}
		cout << sol << '\n';
		return 0;
	}

	ll i = 0, j = n - 1;
	if(k % 2){
		sol = (sol * 1LL *  a[j]) % MOD;
		j--;
		k--;
	}
	k /= 2;
	for(int p = 0; p < k; p++){
		ll neg = (a[i] * 1LL * a[i + 1]);
		ll pos = (a[j] * 1LL * a[j - 1]);
		if(neg >= pos){
			sol = (sol * 1LL * ((neg + MOD) % MOD)) % MOD;
			i += 2;
		}else{
			sol = (sol * 1LL * ((pos  + MOD) % MOD)) % MOD;
			j -= 2;
		}
	}
	cout << sol << '\n';
}
