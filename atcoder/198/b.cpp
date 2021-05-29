#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	int n = (int) s.size();
	int i = 0, j = n - 1;
	while (i < n && s[i] == '0') i++;
	while (j >= 0 && s[j] == '0') j--;
	bool ok = true;
	while (i < j) {
		if (s[i] != s[j]) ok = false;
		i++;
		j--;
	}
	if (ok) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
