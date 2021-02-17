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
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n, greater<int>());
		int sol = 0;
		int i = 0;
		while (i < n && ar[i] >= k) i++;
		sol = i;
		int j = n - 1;
		while (i < j) {
			if (ar[i] + ar[j] >= k) {
				sol++;
				i++;
			}
			j--;
		}
		cout << sol << '\n';
	}
}
