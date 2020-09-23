#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	vector<ll> pref;
	ll cur = 1, dos = 2;
	pref.push_back(1);
	
	for (int i = 1; i < 32; i++) {
		pref.push_back(pref.back() * 2);
		pref.back() += dos * dos;
		dos *= 2;
	}
	
	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		int sol = 0;
		for (int i = 0; i < 32 && x > 0; i++) {
			sol++;
			x -= pref[i];
		}
		
		if (x != 0) sol--;
		
		cout << sol << '\n';
	}

}
