#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll x;
	while (cin >> x) {
		if (x == 0) break;
		ll k = x;
		string cur;
		while (x) {
			if (x % 2) cur += "1";
			else cur += "0";
			x /= 2;
		}
		int n = (int) cur.size();
		int i = 0, j = n - 1;
		while (i < n && cur[i] != '1') i++;
		while (j >= 0 && cur[j] != '1') j--;
		bool ok = true;
		while (i < j) {
			if (cur[i] != cur[j]) ok = false;
			i++;
			j--;
		}
		if (ok) cout << "SI" << '\n';
		else cout << "NO" << '\n';
	}
}
