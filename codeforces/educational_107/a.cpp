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
		int sol = 0;
		for (int i = 0; i < n; i++) {
			int r;
			cin >> r;
			if (r == 1 || r == 3) sol++;
		}
		cout << sol << '\n';
	}
}
