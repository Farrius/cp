#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		bool ok = true;
		if (x1 >= x2) ok = false;
		if (y1 >= y2) ok = false;
		if (z1 >= z2) ok = false;
		if (ok) cout << "SIRVE" << '\n';
		else cout << "NO SIRVE" << '\n';
	}
}
