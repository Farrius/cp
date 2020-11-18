#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	ll sol = 0, pref = 0, tot = 0, mxpref = 0;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		pref += ar[i];
		mxpref = max(mxpref, pref);
		sol = max(sol, tot + mxpref);
		tot += pref;
	}
	cout << sol << '\n';
}
