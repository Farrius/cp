#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool fn (string& s) {
	int n = (int) s.size();
	int i = 0, j = n - 1;
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		string u = s + "a";
		string d = "a" + s;
		if (n % 2 == 0 && !fn(s)) {
			cout << "YES" << '\n';
			for (int i = 0; i < n/2; i++) {
				cout << s[i];
			}
			cout << 'a';
			for (int i = n/2; i < n; i++) {
				cout << s[i];
			}
			cout << '\n';
			continue;
		} else if (!fn(u)) {
			cout << "YES" << '\n';
			cout << u << '\n';
		} else if (!fn(d)) {
			cout << "YES" << '\n';
			cout << d << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}
