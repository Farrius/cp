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
		string prev = s;
		s[0] += 1;
		for (int i = 1; i < n; i++) {
			if (s[i] + 1 != s[i - 1]) s[i]++;
		}
		for (int i = 0; i < n; i++) {
			cout << (int) (s[i] - prev[i]);
		}
		cout << '\n';
	}
}
