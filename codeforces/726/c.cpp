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
		vector<int> ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		int mn = 1e9, x, y;
		sort(ar.begin(), ar.end());
		for (int i = 0; i < n - 1; i++) {
			if (ar[i + 1] - ar[i] < mn) {
				mn = ar[i + 1] - ar[i];
				x = i;
				y = i + 1;
			}
		}
		cout << ar[x] << ' ';
		for (int i = y + 1; i < n; i++) {
			cout << ar[i] << ' ';
		}
		for (int i = 0; i < x; i++) {
			cout << ar[i] << ' ';
		}
		cout << ar[y] << '\n';
	}
}
