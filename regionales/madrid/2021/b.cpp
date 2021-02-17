#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	while (cin >> s) {
		int n = (int) s.size();
		int cnt = 0;
		vector<char> sol;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '.') {
				cnt++;
			} else {
				if (cnt >= 2) {
					sol.push_back(s[i]);
				}
				cnt = 0;
			}
		}
		for (int i = (int) sol.size() - 1; i >= 0; i--) {
			cout << sol[i];
		}
		cout << '\n';
	}
}
