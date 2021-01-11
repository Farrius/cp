#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		ll mid = (a + b)/2;
		cout << (a - mid) * 100LL /mid<< '\n';
	}
}
