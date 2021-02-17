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
		if (n % 2021 == 0 || n % 2020 == 0) {
			cout << "YES" << '\n';
			continue;
		}
		int res = n % 2020;
		int restar = n/2021;
		if (res <= restar) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		
	}
}
