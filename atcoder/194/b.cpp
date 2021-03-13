#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n], br[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i] >> br[i];
	}
	int sol = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) sol = min(sol, ar[i] + br[j]);
			else sol = min(sol, max(ar[i], br[j]));
		}
	}
	cout << sol << '\n';
}
