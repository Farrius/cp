#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

ll trans(ll key){
	if(key < 8) return key;
	key -= 8;
	ll prefix = key % 9;
	key -= key % 9;
	while(key){
		prefix *= 10;
		prefix += min(key, (ll)9);
		key -= min(key, (ll)9);
	}
	prefix = prefix * 10 + 8;
	return prefix;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		ll sol = INF, p = 1;
		for(int i = 0; i < 17; i++){
			p = p * 10;
			for(int d = 0; d < 10; d++){
				ll type1 = min(10 - d, k + 1);
				ll c = n - i * 9 * type1 - (k + 1 - type1);
				for(int p = 0; p <= k; p++){
					c -= (d + p) % 10;
				}
				if(c >= 0 && c % (k + 1) == 0){
					c /= (k + 1);
					sol = min(sol, p * trans(c) + p - 10 + d);
				}
			}
		}
		if(sol == INF) cout << -1 << '\n';
		else cout << sol << '\n';
	}
}
