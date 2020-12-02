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
		int cur = ar[0];
		int i = 1, sol = 0;
		while (cur > 0 && i < n) {
			cur--;
			cur += ar[i];
			i++;
			sol++;
		}
		sol += cur;
		cout << sol << '\n';
	}
}
