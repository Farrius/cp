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
		ll ar[n];
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		sort(ar, ar + n);
		ll cur = tot + (((n - 1) - (tot % (n - 1))) % (n - 1));
		if (cur / (n - 1) < ar[n - 1]) cur = ar[n - 1] * (n - 1); 
		cur = cur + (((n - 1) - (cur % (n - 1))) % (n - 1));
		cout << cur - tot << '\n';
	}
}
