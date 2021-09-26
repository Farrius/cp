#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b, c;
	while (cin >> a >> b >> c) {
		int mx = max(max(a, b), c);
		if (a + b + c == mx && mx != 1) {
			cout << "NO" << '\n';
			continue;
		}
		bool ok = false;
		if (abs(a - b) % 2) ok = true;
		if (abs(a - c) % 2) ok = true;
		if (abs(b - c) % 2) ok = true;
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
