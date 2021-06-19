#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

set<string> sol;
string s;
int ar[505];
int n;

void fn (int i, string cur) {
	if (i == n) {
		sol.insert(cur);
		return;
	}
	if (ar[i] == 0) return;
	char c = (char) ((ar[i] - 1) + 'A');
	string u = cur + c;
	fn(i + 1, u);
	if (i < n - 1 && ar[i] * 10 + (ar[i + 1] - 1) < 26) {
		c = (char) ((ar[i] * 10 + (ar[i + 1] - 1)) + 'A');
		string d = cur + c;
		fn(i + 2, d);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> s) {
		sol.clear();
		n = (int) s.size();
		for (int i = 0; i < n; i++) {
			ar[i] = s[i] - '0';
		}
		string ex;
		fn(0, ex);
		for (auto x : sol) cout << x << '\n';
		cout << "----------" << '\n';
	}
}
