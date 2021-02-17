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
		int sol = 0;
		for (int i = 0; i < n - 1; i++) {
			int mn = min(ar[i], ar[i + 1]);
			int mx = max(ar[i], ar[i + 1]);
			while (mn * 2 < mx) {
				mn *= 2;
				sol++;
			}
		}
		cout << sol << '\n';
	}
}
