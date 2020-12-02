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
		if (n % 4 == 0) {
			cout << "Draw" << '\n';
		} else if (n % 2 == 0) {
			cout << "Alice" << '\n';
		} else {
			cout << "Bob" << '\n';
		}
	}
}
