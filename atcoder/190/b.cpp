#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, s, d;
	cin >> n >> s >> d;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < s && y > d) ok = true;
	}
	if (ok) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
