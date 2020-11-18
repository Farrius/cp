#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	ld x[n], y[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int u = 0; u < n; u++) {
				if (i == j || i == u || j == u) continue;
				if ((y[i] - y[j])/(x[i] - x[j]) == (y[i] - y[u])/(x[i] - x[u])) {
					cout << "Yes" << '\n';
					return 0;
				}
			}
		}
	}
	cout << "No" << '\n';
}

