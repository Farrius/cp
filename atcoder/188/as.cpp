#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int x, y;
	cin >> x >> y;
	if (x > y) swap(x, y);
	if (x + 3 > y) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
