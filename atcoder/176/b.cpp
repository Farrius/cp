#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) -1);

int main () {
	string s;
	cin >> s;
	int cur  = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		cur += s[i] - '0';
		cur %= 9;
	}

	if (cur == 0) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
