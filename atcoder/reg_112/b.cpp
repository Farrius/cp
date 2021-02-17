#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll b, c;
	cin >> b >> c;
	ll sol = c/2;
	ll tabajo = b - c/2;
	if (b > 0) {
		sol += (c - 1)/2;
	} else {
		sol += min((-b - b), (c - 1)/2);
		sol += (c - 1)/2;
	}
	
	cout << sol << '\n';
}
