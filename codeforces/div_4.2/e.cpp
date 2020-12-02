#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	string s, sub_s;
	cin >> s >> sub_s;
	ll sol = 0;
	int last_sub = 0;
	for (int i = 0; i < n - 1; i++) {
		string cur = s.substr(i, 2);
		if (cur == sub_s) {
			int dist = i - last_sub + 1;
			sol += dist * (n - i - 1);
			last_sub = i + 1;
		}

	}
	cout << sol << '\n';
}
