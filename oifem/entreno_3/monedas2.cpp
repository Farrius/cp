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
		set<int> sol = {0};
		int ar[n], tot = 0;
		for (int i  = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		for (int i = 0; i < n; i++) {
			for (int x = tot; x >= ar[i]; x--) {
				if (sol.count(x - ar[i])) sol.insert(x);
			}
		}
		cout << (int) sol.size() - 1 << '\n';
	}
}
