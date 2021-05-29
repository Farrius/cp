#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n);
		int p;
		cin >> p;
		int lo = 1, hi = 1e9 + 7;
		int sol = hi;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			int i = 0, k = p;
			int fins = 0;
			while (i < n && k >= 0) {
				if (fins < ar[i]) {
					fins = ar[i] + mid - 1;
					k--;
				}
				if (k < 0) break;
				i++;
			}
			if (i == n) {
				sol = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << p * 1LL * sol << '\n';
	}
}
