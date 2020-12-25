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
		for (int i = 1; i < n; i++) {
			int arriba = 0, abajo = 0;
			if (ar[i] > ar[i - 1]) {
				abajo = ar[i] % ar[i - 1];
				arriba = (ar[i - 1] - abajo);
			} else {
				abajo = ar[i - 1] % ar[i];
				arriba = (ar[i] - abajo);
			}
			if (arriba > abajo) {
				ar[i] += arriba;
			} else {
				ar[i] -= abajo;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ar[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
