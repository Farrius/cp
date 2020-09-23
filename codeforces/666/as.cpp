#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const int PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int freq[26] = {0};
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < (int) s.size(); j++) {
				freq[s[j] - 'a']++;
			}
		}
		bool ok = true;
		for (auto x: freq) {
			if (x % n) ok = false;
		}

		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';

	}
}
