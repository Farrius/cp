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
		string s;
		cin >> s;
		queue<int> magnets, irons;
		int sol = 0;
		vector<int> pref(n);
		for (int i = 0; i < n; i++) {
			if (i > 0) pref[i] = pref[i - 1];
			if (s[i] == ':') pref[i]++;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == 'X') {
				queue<int> new_q;
				magnets = new_q;
				irons = new_q;
			} else if (s[i] == 'M') {
				bool take = true;
				while (!irons.empty()) {
					int pos = irons.front();
					int p = k + 1 - (abs(pos - i)) - (pref[i] - pref[pos]);
					irons.pop();
					if (p > 0) {
						sol++;
						take = false;
						break;
					}
				}
				if (take) magnets.push(i);
			} else if (s[i] == 'I') {
				bool take = true;
				while (!magnets.empty()) {
					int pos = magnets.front();
					int p = k + 1 - (abs(pos - i)) - (pref[i] - pref[pos]);
					magnets.pop();
					if (p > 0) {
						sol++;
						take = false;
						break;
					}
				}
				if (take) irons.push(i);
			}
		}
		cout << sol << '\n';
	}
}
