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
		int a, b;
		cin >> a >> b;
		if (b > a) swap(a, b);
		int diff = a - b;
		int sol = MOD;
		for (int i = 1; i <= 10; i++) {
			sol = min (sol, (diff + (i - 1))/i);
		}
		cout << sol << '\n';
	}
}
