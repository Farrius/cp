#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	ld x;
	cin >> n >> x;
	ld cur = 0;
	for (int i = 0; i < n; i++) {
		ld v, p;
		cin >> v >> p;
		cur += v * (p/100);
		if (cur - x > 0.001) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}
