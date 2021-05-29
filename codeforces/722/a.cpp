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
		int ar[n], mn = 100;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			mn = min(mn, ar[i]);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (ar[i] == mn) cnt++;
		}
		cout << n - cnt << '\n';
	}
}
