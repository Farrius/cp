#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	int rain = 0;
	bool seq = false;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'R') rain++;
		if (i == 1 && (s[i] == s[i - 1] || s[i] == s[i + 1])) seq = true;
	}
	if (rain == 3) {
		cout << rain << '\n';
	} else if (rain == 2 && seq) {
		cout << rain << '\n';
	} else {
		if (rain == 2) cout << rain - 1 << '\n';
		else cout << rain << '\n';
	}
}
