#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool fn (int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (fn(n) && fn(n + 2)) cout << "tiene gemelo mayor" << '\n';
		else cout << "no tiene gemelo mayor" << '\n';
	}
}
