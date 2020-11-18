#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
		sort(ar, ar + n);
		bool para = false;
		ll sol = 0;
		for (int i = 0; i < n && !para; i++) {
			if (ar[i] - 1 > sol) para = true;
			else sol += ar[i];
		}
		cout << sol + 1 << '\n';
	}
}
