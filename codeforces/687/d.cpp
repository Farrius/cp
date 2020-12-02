#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int pref[n + 1] = {0};
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] ^ ar[i];
	}
	for (int seq = 3; seq <= n; seq++) {
		for (int i = 0, j = seq; j <= n; i++, j++) {
			for (int k = i + 1; k < j; k++) {
				if ((pref[k] ^ pref[i]) > (pref[j] & pref[k])) {
					cout << seq - 2 << '\n';
					exit(0);
				}
			}
		}
	}
	cout << -1 << '\n';
}
