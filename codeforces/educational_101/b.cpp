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
		int m;
		cin >> m;
		int ab[m];
		for (int i = 0; i < m; i++) {
			cin >> ab[i];
		}
		int tot = 0;
		int mx_ar = 0;
		for (int i = 0; i < n; i++) {
			tot += ar[i];
			mx_ar = max(mx_ar, tot);
		}
		tot = 0;
		int mx_br = 0;
		for (int i = 0; i < m; i++) {
			tot += ab[i];
			mx_br = max(mx_br, tot);
		}
		cout << mx_br + mx_ar << '\n';
	}
}
