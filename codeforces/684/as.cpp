#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, c1, c2, h;
		cin >> n >> c1 >> c2 >> h;
		string s;
		cin >> s;
		int unos = 0, dos = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') unos++;
			else dos++;
		}
		int sol = 0;
		if (c1 > h + c2) {
			unos += dos;
			sol += dos * h;
			dos = 0;
		}
		if (c2 > h + c1) {
			dos += unos;
			sol += unos * h;
			unos = 0;
		}
		sol += unos * c2 + dos * c1;
		cout << sol << '\n';
	}
}
