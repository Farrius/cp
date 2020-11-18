#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	while (cin >> n >> m) {
		map<int, int> toppings;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			for (int j = 0; j < p; j++) {
				int t;
				cin >> t;
				toppings[t]++;
				toppings[t] %= 8;
			}
		}
		bool ok = true;
		for (auto cur : toppings) {
			if (cur.second != 0) ok = false;
		}
		if (ok) cout << "SI" << '\n';
		else cout << "NO" << '\n';
	}
}
