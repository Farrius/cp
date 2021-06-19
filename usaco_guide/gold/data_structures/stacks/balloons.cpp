#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	stack<pair<ld, ld>> radios;
	for (int i = 0; i < n; i++) {
		ld x, r;
		cin >> x >> r;
		while (!radios.empty()) {
			ld x1, r1;
			tie(x1, r1) = radios.top();
			r = min(r, (x - x1) * (x - x1)/(4 * r1));
			if (r >= r1) radios.pop();
			else break;
		}
		radios.push(make_pair(x, r));
		cout << fixed << setprecision(6) << r << '\n';
	}
}
