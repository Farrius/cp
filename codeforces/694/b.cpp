#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int ar[n];
		int cnt = 32, pos = n - 1;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			int k = ar[i];
			int c_cnt = 0;
			while (c_cnt <= cnt) {
				c_cnt++;
				if (k % x) break;
				k /= x;
			}
			if (cnt == c_cnt) {
				pos = min(pos, i);
			} else if (c_cnt < cnt) {
				cnt = c_cnt;
				pos = i;
			}
		}
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			int k = ar[i];
			int j = 0;
			int copi = 1;
			while (j <= cnt) {
				if (j == cnt && i > pos) break;
				tot += k * copi;
				if (k % x) break;
				k /= x;
				copi *= x;
				j++;
			}
		}
		cout << tot << '\n';
	}
}
