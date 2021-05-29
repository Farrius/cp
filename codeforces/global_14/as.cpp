#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int ar[n], tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		if (tot == x) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			int acc = 0;
			sort(ar, ar + n);
			for (int i = 0; i < n; i++) {
				if (acc + ar[i] == x) {
					cout << ar[i + 1] << ' ';
					cout << ar[i] << ' ';
					acc += ar[i + 1] + ar[i];
					i++;
				} else {
					cout << ar[i] << ' ';
					acc += ar[i];
				}
			}
			cout << '\n';
		}
	}
}
