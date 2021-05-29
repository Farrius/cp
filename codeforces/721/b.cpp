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
		string s;
		cin >> s;
		int zer = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') zer++;
		}
		if (zer % 2) {
			if (zer == 1) cout << "BOB" << '\n';
			else cout << "ALICE" << '\n';
		} else {
			cout << "BOB" << '\n';
		}
	}
}
