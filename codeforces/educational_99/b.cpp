#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int cur = 0;
		int i = 1, sol = 0;
		while (true) {
			cur += i;
			if (cur >= x) {
				sol = (x + 1 == cur ? i + 1 : i);
				break;
			}
			i++;
		}
		cout << sol << '\n';
	}
}
