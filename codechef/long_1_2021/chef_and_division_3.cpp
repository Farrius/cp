#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n, k, d;
		cin >> n >> k >> d;
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			tot += x;
		}
		tot /= k;
		cout << min(d, tot) << '\n';
	}
}
