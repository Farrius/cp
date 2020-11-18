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
		int ar[n], sol[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		int i = 0, j = n - 1;
		while (i < j) {
			sol[i] = ar[j];
			sol[j] = -ar[i];
			i++; j--;
		}
		for (int i = 0; i < n; i++) {
			cout << sol[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
