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
		vector<int> ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		int sol = 0;
		while (!is_sorted(ar.begin(), ar.end())) {
			int ind = -1;
			for (int i = 0; i < n; i++) {
				if (ar[i] > x) {
					ind = i;
					swap(ar[i], x);
					break;
				}
			}
			if (ind == -1) break;
			sol++;
		}

		if (is_sorted(ar.begin(), ar.end())) cout << sol << '\n';
		else cout << -1 << '\n';
	}
}
