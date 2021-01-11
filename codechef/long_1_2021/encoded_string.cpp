#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		for (int i = 0; i < n; i += 4) {
			string cur = s.substr(i, 4);
			int num = 0;
			if (cur[0] == '1') num += 8;
			if (cur[1] == '1') num += 4;
			if (cur[2] == '1') num += 2;
			if (cur[3] == '1') num += 1;
			char sol = (char) (num + 'a');
			cout << sol;
		}
		cout << '\n';
	}
}
