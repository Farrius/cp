#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, z;
		cin >> n >> k >> z;
		k++;
		int a[k];
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			if(i < k) a[i] = cur;
		}
		ll pref[k + 1] = {0};
		for(int i = 1; i <= k; i++){
			pref[i] = pref[i - 1] + a[i - 1];
		}
		ll sol = 0;
		for(int i = k; i >= 2; i--){
			ll cur = pref[i];
			int curZ = z;
			int queda = k - i;
			bool bajar = true;
			for(int j = 0;; j++){
				if(queda == 0 || (curZ == 0 && bajar == true)) break;
				if(bajar){
					cur += a[i - 2];
					bajar = false;
					curZ--;
				}else{
					cur += a[i - 1];
					bajar = true;
				}
				queda--;
			}
			cur += pref[i + queda] - pref[i];
			sol = max(sol, cur);
		}
		cout << sol << '\n';
	}
}
