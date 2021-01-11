#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		int groups = (n + 1)/2;
		vector<ll> sol(groups);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ll x;
				cin >> x;
				int arriba = i, abajo = n - i - 1;
				int der = n - j - 1, iz = j;
				int a = min(arriba, abajo);
				int b = min(der, iz);
				int pos = min(a, b);
				sol[pos] += x;
			}
		}
		for (int i = groups - 1; i >= 0; i--) {
			cout << sol[i] << (i == 0 ? '\n' : ' ');
		}
	}
}
