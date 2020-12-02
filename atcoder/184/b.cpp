#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') x--;
		else x++;
		x = max(x, 0);
	}
	cout << x << '\n';
}
