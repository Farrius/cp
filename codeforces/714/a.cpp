#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k == n/2 && n % 2 == 0) {
			cout << -1 << '\n';
		} else if (k > n/2) {
			cout << -1 << '\n';
		} else {
			int i = 1, cur = n, c = 0;
			vector<int> ar(n, -1);
			while (c < k) {
				ar[i] = cur;
				cur--;
				i += 2;
				c++;
			}
			cur = 1;
			for (i = 0; i < n; i++) {
				if (ar[i] != -1) continue;
				ar[i] = cur;
				cur++;
			}
			for (int i = 0; i < n; i++) {
				cout << ar[i] << (i == n - 1 ? '\n' : ' ');
			}
		}
	}
}
