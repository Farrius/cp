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
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		set<int> sol;
		sort(ar, ar + n);
		int i = 0, j = n - 1;
		while (i < j) {
			sol.insert(ar[i] + ar[j]);
			i++;
			j--;
		}
		if ((int) sol.size() == 1) cout << "SI" << '\n';
		else cout << "NO" << '\n';
	}
}
