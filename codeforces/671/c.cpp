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
		bool igual = true, traidor = false;
		int diff = 0;
		for (int i = 0; i < n; i++) {
			int cur;
			cin >> cur;
			if (cur == x) {
				traidor = true;
				continue;
			}
			igual = false;
			if (cur < x) diff += x - cur;
			else diff -= cur - x;
		}

		if (igual) cout << 0 << '\n';
		else if (diff == 0 || traidor) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
}
