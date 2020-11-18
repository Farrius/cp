#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		string s;
		cin >> s;
		int n = (int) s.size();
		ll sol = 0;
		vector<int> pref(n + 1);
		for (int i = n - 1; i >= 0; i--) {
			pref[i] = pref[i + 1];
			if (s[i] == 'S' && s.substr(i, 5) == "START") pref[i]++;
		}

		for (int i = 0; i < n; i++) {
			if (s[i] == 'K' && s.substr(i, 4) == "KICK") {
				sol += pref[i];
			}
		}
		
		cout << "Case #" << test << ": " << sol << '\n';
	}
}
