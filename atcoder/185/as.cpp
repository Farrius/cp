#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min(min(a, b), min(c, d)) << '\n';
}
