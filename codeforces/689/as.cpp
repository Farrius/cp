#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s = "abc";
		string sol = "";
		int cnt = 0, i = 0;
		while (cnt < n) {
			if (i == 3) i = 0;
			sol += s[i];
			i++;
			cnt++;
		}
		cout << sol << '\n';
	}
}
