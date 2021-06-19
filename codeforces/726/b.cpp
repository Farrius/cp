#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void fn (pair<int, int> a, pair<int, int> b) {
	cout << a.first << ' ' << a.second << ' ';
	cout << b.first << ' ' << b.second << '\n';
}

ll d (pair<int, int> a, pair<int, int> b, int i, int j) {
	 return abs(a.first - i) + 0LL + abs(b.first - i) + abs(a.second - j) + abs(b.second - j); 
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int i, j;
		cin >> i >> j;
		//esquinas
		pair<int, int> uu = {1, 1};
		pair<int, int> dd = {1, m};
		pair<int, int> tt = {n, m};
		pair<int, int> qq = {n, 1};
		if (d(uu, tt, i, j) > d(dd, qq, i, j)) {
			fn(uu, tt);
		} else {
			fn(dd, qq);
		}
	}
}
