#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

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
		if(k % 2) res = (res* 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}
	return res;
}

int inverse(int n){
	return power(n, MOD - 2);
}

int cnr(int n, int k){
	int top = fact(n);
	int low = fact(k);
	int other_low = fact(n - k);
	int inverse_low = inverse(low), inverse_other = inverse(other_low);
	top = (top * 1LL * inverse_low) % MOD;
	top = (top * 1LL * inverse_other) % MOD;
	return top;
}
int main(){
	int n, m;
	cin >> n >> m;
	int fact_maxi = fact(m);
	int choos_mini = cnr(m,n);
	int sol = (fact_maxi * 1LL * choos_mini) % MOD;
	cout << sol << '\n';
}
