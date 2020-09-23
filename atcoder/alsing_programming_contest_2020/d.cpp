#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 2e5 + 1;

ll pw[maxN];

int ciclos(int x){
	if(x == 0) return 0;
	int bits = __builtin_popcount(x);
	return 1 + ciclos(x % bits);
}

int main(){
	int n;
	string s;
	cin >> n >> s;
	reverse(s.begin(), s.end());
	int unos = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1') unos++;
	}
	ll mod = unos + 1;
	if(unos - 1 > 0) mod *= (unos - 1);
	pw[0] = 1;
	for(int i = 1; i < n; i++) pw[i] = (pw[i - 1] * 2) % mod;
	ll tot = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			tot = (tot + pw[i]) % mod;
		}
	}

	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '1'){
			if(unos == 1){
				cout << 0 << '\n';
			}else{
				int queda = (tot - pw[i] + mod) % (unos - 1);
				cout << 1 + ciclos(queda) << '\n';
			}
		}else{
			int queda = (tot + pw[i]) % (unos + 1);
			cout << 1 + ciclos(queda) << '\n';
		}
	}
}
