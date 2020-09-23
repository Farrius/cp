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
		ll l, r;
		cin >> l >> r;
		ll res = l * 2;
		if(res > r){
			cout << -1 << ' ' << -1 << '\n';
		}else{
			cout << l << ' ' << l * 2 << '\n';
		}
	}
}
