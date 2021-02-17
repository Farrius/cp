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
		if (n % k == 0) {
			cout << 1 << '\n';
			continue;
		} else {
			int x = k - (n % k);
			cout << 1 + (x + n - 1)/n << '\n';
		}
	}
}
