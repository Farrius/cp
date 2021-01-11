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
		int i = 0, a = 0, b = 0;
		sort(ar, ar + n, greater<int>());
		while (i < n) {
			if (a > b) swap(a, b);
			a += ar[i];
			i++;
		}
		cout << (a == b ? "YES" : "NO") << '\n';
	}
}
