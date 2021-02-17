#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		bool cnt = false;
		int sol = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0' && cnt) cur++;
			if (s[i] == '1' && cnt) {
				sol += cur;
				cur = 0;
			}
			if (s[i] == '1' && !cnt) {
				cnt = true;
			}
		}
		cout << sol << '\n';
	}
}
