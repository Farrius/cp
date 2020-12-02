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
		for (int i = n; i >= 1; i--) {
			if (n % 2) {
				if (i == (n + 1)/2) cout << 1 << ' ';
				else if (i == 1) cout << (n + 1)/2;
				else cout << i << ' ';
			} else {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}
