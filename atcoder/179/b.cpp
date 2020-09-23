#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int racha = 0;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) racha++;
		else racha = 0;
		if (racha >= 3) ok = true;
	}

	cout << (ok ? "Yes" : "No") << '\n';
}
