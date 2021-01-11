#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ar[n], w[m];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			ar[i]--;
		}
		for (int i = 0; i < m; i++) {
			cin >> w[i];
		}
		sort(ar, ar + n, greater<int>());
		ll tot = 0;
		int j = 0, i = 0;
		while (i < n && j < m && j <= ar[i]) {
			tot += w[j];
			j++;
			i++;
		}
		for (int k = i; k < n; k++) {
			tot += w[ar[k]];
		}
		cout << tot << '\n';
	}
}
