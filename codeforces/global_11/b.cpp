#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long k;
		cin >> n >> k;
		vector<int> base(n);
		vector<int> otra(n);
		k--;
		int maxi = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> base[i];
			maxi = max(maxi, base[i]);
		}
		int otroMax = INT_MIN;
		for (int i = 0; i < n; i++) {
			base[i] = maxi - base[i];
			otroMax = max(otroMax, base[i]);
		}

		for (int i = 0; i < n; i++) {
			otra[i] = otroMax - base[i];
		}

		if (k % 2LL == 0LL) {
			for (int i = 0; i < n; i++) {
				cout << base[i] << (i == n - 1 ? '\n' : ' ');
			}
		} else {
			for (int i = 0; i < n; i++) {
				cout << otra[i] << (i == n - 1 ? '\n' : ' ');
			}
		}
	}
}
