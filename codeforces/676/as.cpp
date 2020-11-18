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
		int sol = 0;
		for (int i = 0; i < 32; i++) {
			if ((a>>i) & 1 && (b>>i) & 1) sol += (1<<i);
		}
		cout << (a^sol) + (b^sol) << '\n';
	}
}
