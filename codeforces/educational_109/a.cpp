#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int res = 100;
		if (n % 4 == 0) {
			n /= 4;
			res /= 4;
		} else if (n % 2 == 0) {
			n /= 2;
			res /= 2;
		} 
		if (n % 25 == 0) {
			n /= 25;
			res /= 25;
		} else if (n % 5 == 0) {
			n /= 5;
			res /= 5;
		}
		cout << res << '\n';
	}
}
