#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k % 3) {
			if (n % 3 == 0) cout << "Bob" << '\n';
			else cout << "Alice" << '\n';
		} else {
			int res = n % (k + 1);
			if (res % 3 == 0 && res != k) cout << "Bob" << '\n';
			else cout << "Alice" << '\n';
		}
	}
}
