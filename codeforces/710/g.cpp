#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int distinct(string s) {
  sort(s.begin(), s.end());
  return unique(s.begin(), s.end()) - s.begin();
}

string filter (string& s, char c) {
	bool first = false;
	string t;
	for (auto cur : s) {
		if (cur != c && first) {
			t += cur;
		} else if (cur == c) {
			first = true;
		}
	}
	return t;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int m = distinct(s);
		set<char> used(s.begin(), s.end());
		string t;
		while (m) {
			char mx_c = -1;
			for (auto cur : used) {
				if (distinct(filter(s, cur)) == m - 1) {
					mx_c = cur;
				}
			}
			t += mx_c;
			used.erase(mx_c);
			s = filter(s, mx_c);
			m--;
		}
		cout << t << '\n';
	}
}
