#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	string s, t;
	cin >> s >> t;
	int m = (int) t.size();
	int sol = m;
	int n = (int) s.size();
	for (int i = 0; i + (int) t.size() <= n; i++) {
		string cur = s.substr(i, m);
		int com = 0;
		for (int j = 0; j < m; j++) {
			if (cur[j] == t[j]) com++;
		}
		sol = min(sol, m - com);
	}
	
	cout << sol << '\n';
}
