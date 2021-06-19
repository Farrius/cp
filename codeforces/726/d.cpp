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
		if (n % 2) {
			cout << "Bob" << '\n';
		} else {
			int k = 0;
			while (n % 2 == 0) {
				n /= 2;
				k++;
			}
			if (n != 1 || k % 2 == 0) cout << "Alice" << '\n';
			else cout << "Bob" << '\n';
		}
	}
}
