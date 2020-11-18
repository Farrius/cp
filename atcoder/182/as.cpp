#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll a, b;
	cin >> a >> b;
	cout << max(0LL, 2LL * a + 100 - b) << '\n';
}
