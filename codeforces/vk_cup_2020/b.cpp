#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		int a, b;
		cin >> a >> b;
		cin >> s;
		int n = (int) s.size();
		ll sol = 0;
		int poner = 0;
		bool peto = false;
		for (int i = 0; i < n;) {
			if (s[i] == '1') {
				if (!peto) {
					sol += a;
					peto = true;
				}
				while (i < n && s[i] == '1') i++;
				poner = 0;
				while (i < n && s[i] == '0') {
					i++;
					poner++;
				}
				if (i >= n || poner * b > a) {
					peto = false;
				} else {
					sol += poner * b;
				}
			} else {
				while(i < n && s[i] == '0') i++;
			}
		}
		cout << sol << '\n';
	}
}
