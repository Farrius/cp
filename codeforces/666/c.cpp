#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const int PI = acos((ld) - 1);
 
int main () {
	int n;
	cin >> n;
	ll ar[n];
 
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

 	if (n == 1) {
		cout << 1 << ' ' << 1 << '\n';
		cout << -ar[0] << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n';
		return 0;
	}

	for (int k = 1; k <= 3; k++) {
		if (k == 1) {
			cout << 1 << ' ' << n - 1 << '\n';
			for (int i = 0; i < n - 1; i++) {
				cout << ar[i] % n * (n - 1) << (i == n - 2 ? '\n' : ' ');
				ar[i] += (ar[i] % n) * (n - 1);
			}
 
		} else if (k == 2) {
			cout << n << ' ' << n << '\n';
			cout << -ar[n - 1] << '\n';
			ar[n - 1] = 0;
		} else {
			cout << 1 << ' ' << n << '\n';
			for (int i = 0; i < n; i++) {
				cout << -ar[i] << (i == n - 1 ? '\n' : ' ');
			}
		}
	}
}
