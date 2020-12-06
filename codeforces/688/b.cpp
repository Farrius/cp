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
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (i > 0) tot += abs(ar[i] - ar[i - 1]);
		}
		int take = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) take = max(take, abs(ar[i] - ar[i + 1]));
			else if (i == n - 1) take = max(take, abs(ar[i] - ar[i - 1]));
			else take = max(take, abs(ar[i] - ar[i + 1]) + abs(ar[i] - ar[i - 1]) - abs(ar[i + 1] - ar[i - 1]));
		}
		cout << tot - take << '\n';
	}
}
