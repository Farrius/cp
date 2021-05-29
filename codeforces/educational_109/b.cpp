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
		int ar[n + 1];
		bool nada = true;
		for (int i = 1; i <= n; i++) {
			cin >> ar[i];
			if (ar[i] != i) nada = false;
		}
		if (nada) {
			cout << 0 << '\n';
		} else if (ar[1] == 1 || ar[n] == n) {
			cout << 1 << '\n';
		} else if (ar[1] == n && ar[n] == 1) {
			cout << 3 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}
