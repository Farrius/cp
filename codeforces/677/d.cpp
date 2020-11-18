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
		
		int connection = -1;
		for (int i = 1; i < n; i++) {
			if (ar[i] != ar[i - 1]) {
				connection = i;
				break;
			}
		}

		if (connection == -1) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			int una = connection + 1, dos = connection;
			cout << una << ' ' << dos << '\n';
			for (int i = 0; i < n; i++) {
				if (i == una - 1 || i == dos - 1) continue;
				if (ar[i] == ar[una - 1]) {
					cout << i + 1 << ' ' << dos << '\n';
				} else {
					cout << i + 1 << ' ' << una << '\n';
				}
			}
		}
	}
}
