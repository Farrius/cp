#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string base;
	for (int i = n - 1; i >= 0; i--) {
		if (s.substr(i, n - i) >= s.substr(0, n - i)) {
			base = s.substr(0, i);
		}
	}
	string cur;
	while ((int)cur.size() < k) cur += base;
	cout << cur.substr(0, k) << '\n';
}
