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
		int ar[n];
		vector<int> res(3, 0);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			res[ar[i] % 3]++;
		}
		int obj = n/3;
		int mn = 0;
		int j = 0;
		for (int i = 0; i < 3; i++) {
			if (res[i] > mn) {
				j = i;
				mn = res[i];
			}
		}
		int sol = 0;
		for (int k = 0; k < 2; k++) {
			int pos = (j + k) % 3;
			if (k == 0) {
				res[(pos + 1) % 3] += res[pos] - obj;
				sol += res[pos] - obj;
			} else {
				if (res[pos] > obj) {
					sol += res[pos] - obj;
				} else if (res[pos] < obj) {
					sol += 2 * (obj - res[pos]);
				}
			}
		}
		cout << sol << '\n';
	}
}
