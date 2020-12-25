#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool ok = false;
		if (s.substr(0, 3) == "202" && s[n - 1] == '0') ok = true;
		if (s.substr(n - 3, 3) == "020" && s[0] == '2') ok = true;
		if (s.substr(0, 2) == "20" && s.substr(n - 2, 2) == "20") ok = true;
		if (s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020") ok = true;
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
