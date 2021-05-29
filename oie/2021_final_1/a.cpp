#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int lo = 1, hi = 40000;
	int sol;

	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		cout.flush() << "? " << mid << ' ' << mid << '\n';
		string s;
		cin >> s;
		if (s == "SI") {
			sol = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	cout.flush() << "! " << sol << '\n';
}
