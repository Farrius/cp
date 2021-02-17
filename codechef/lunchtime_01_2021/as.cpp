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
		if ((int) s.size() < 10) {
			cout << "NO" << '\n';
			continue;
		}
		bool numm = false, lett = false, blett = false, espp = false;
		set<char> num, let, blet, esp;
		esp.insert('@');
		esp.insert('#');
		esp.insert('%');
		esp.insert('&');
		esp.insert('?');
		for (char c = '0'; c <= '9'; c++) {
			num.insert(c);
		}
		for (char c = 'a'; c <= 'z'; c++) {
			let.insert(c);
		}
		for (char c = 'A'; c <= 'Z'; c++) {
			blet.insert(c);
		}
		for (int i = 0; i < (int) s.size(); i++) {
			if (let.count(s[i])) lett = true;
			if (i == 0 || i == (int) s.size() - 1) continue;
			if (num.count(s[i])) numm = true;
			if (blet.count(s[i])) blett = true;
			if (esp.count(s[i])) espp = true;
		}
		if (numm && lett && blett && espp) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
