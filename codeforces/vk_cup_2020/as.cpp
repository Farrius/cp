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
		int num = 4 * n;
		for (int i = 0; i < n; i++) {
			cout << num << (i == n - 1 ? '\n' : ' ');
			num -= 2;
		}
	}
}
