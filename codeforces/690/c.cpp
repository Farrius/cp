#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	vector<string> res(50, "-1");
	res[0] = "";
	for (int y = 1; y <= 9; y++) {
		string cur = to_string(y);
		for (int tot = 45; tot >= y; tot--) {
			if (res[tot - y] != "-1") {
				if (res[tot] == "-1") {
					res[tot] = (res[tot - y] + to_string(y));
				} else {
					int actual = stoi(res[tot]);
					string newone = res[tot - y];
					newone += to_string(y);
					int new_int = stoi(newone);
					if (new_int < actual) res[tot] = newone;
				}
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x >= 50) cout << -1 << '\n';
		else cout << res[x] << '\n';
	}
}
