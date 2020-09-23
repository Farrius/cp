#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		int k;
		cin >> s >> k;
		int n = (int) s.size();
		int numSum = 0;

		for (int i = 0; i < n; i++) {
			numSum += (s[i] - '0');
		}

		ll quita = numSum - k;
		ll sol = 0;
		ll lleva = 0;
		ll diez = 1;
		for (int i = n - 1; i >= 0 && quita > 0; i--) {
			ll cur = (s[i] - '0') + lleva;
			quita -= (cur - 1);
			sol += (diez * 10) - (cur * diez);
			diez *= 10;
			lleva = 1;
		}

		cout << sol << '\n';
	}
}
