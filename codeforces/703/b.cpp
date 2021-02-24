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
		int x[n], y[n];
		vector<int> xs, ys;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			xs.push_back(x[i]);
			ys.push_back(y[i]);
		}
		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());
		int m = (int) xs.size();
		ll u = 1, d = 1;
		if (m % 2 == 0) u = xs[m/2] - xs[m/2 - 1] + 1;
		m = (int) ys.size();
		if (m % 2 == 0) d = ys[m/2] - ys[m/2 - 1] + 1;
		cout << u * d << '\n';
	}
}
