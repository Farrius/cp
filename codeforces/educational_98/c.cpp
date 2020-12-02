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
		stack<int> par, clau;
		int sol = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == ')') {
				if (!par.empty()) {
					int last = par.top();
					par.pop();
					sol++;
				}
			} else if (s[i] == ']') {
				if (!clau.empty()) {
					int last = clau.top();
					clau.pop();
					sol++;
				}
			} else if (s[i] == '(') {
				par.push(i);
			} else {
				clau.push(i);
			}
		}
		cout << sol << '\n';
	}
}
