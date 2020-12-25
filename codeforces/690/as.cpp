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
		int i = 0, j = n - 1;
		bool u = true;
		while (i <= j) {
			if (i == j) {
				cout << ar[i];
				break;
			} else {
				if (u) {
					cout << ar[i] << ' ';
					i++;
				} else {
					cout << ar[j] << ' ';
					j--;
				}
				u = !u;
			}
		}
		cout << '\n';
	}
}
