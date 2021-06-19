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
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			tot += x;
		}
		if (n > tot) {
			cout << 1 << '\n';
		} else {
			cout << tot - n << '\n';
		}
	}
}
