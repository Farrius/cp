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
		int ar[n * k];
		for (int i = 0; i < n * k; i++) {
			cin >> ar[i];
		}
		ll sol = 0;
		int delante = n - ((n + 1)/2);
		int j = n * k - 1;
		for (int cnt = 0; cnt < k; cnt++) {
			j -= delante;
			sol += ar[j];
			j--;
		}
		cout << sol << '\n';
	}
}
