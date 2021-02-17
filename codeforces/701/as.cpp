#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int sol = 100;
		for (int i = 0; i < 32; i++) {
			if (i + b <= 1) continue;
			int k = a, cur = 0;
			while (k) {
				k /= (b + i);
				cur++;
			}
			sol = min(sol, i + cur);
		}
		cout << sol << '\n';
	}
}
