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
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = n - 1; i >= 0;) {
			if (s[i] == ')') {
				cnt++;
				i--;
			} else {
				break;
			}
		}
		if (cnt > n/2) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}
