#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			if (i == 0) cout << 9;
			else cout << (7 + i) % 10;
		}
		cout << '\n';
	}
}
