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
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll a = 0, b = 0;
		sort(ar, ar + n, greater<int>());
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0 && ar[i] % 2 == 0) a += ar[i];
			if (i % 2 && ar[i] % 2) b += ar[i];
		}
		if (a == b) cout << "Tie" << '\n';
		else if (a > b) cout << "Alice" << '\n';
		else cout << "Bob" << '\n';
	}
}
