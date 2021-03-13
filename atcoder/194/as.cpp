#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b;
	cin >> a >> b;
	int f = b, s = a + b;
	if (s >= 15 && f >= 8) cout << 1 << '\n';
	else if (s >= 10 && f >= 3) cout << 2 << '\n';
	else if (s >= 3) cout << 3 << '\n';
	else cout << 4 << '\n';
}
