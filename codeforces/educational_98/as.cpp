#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
int main () {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		int sol = x + y;
		int diff = abs(x - y);
		diff--;
		sol += max(diff, 0);
		cout << sol << '\n';
	}
}
