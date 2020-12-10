#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	while (cin >> s) {
		vector<int> cnt(10);
		int n = (int) s.size();
		for (int i = 0; i < n; i++) {
			cnt[(s[i] - '0')]++;
		}
		bool normal = true;
		int sub = -1;
		for (int x : cnt) {
			if (sub != -1 && x != sub) normal = false;
			sub = x;
		}
		if (normal && n >= 9) cout << "subnormal" << '\n';
		else cout << "no subnormal" << '\n';
	}
}
