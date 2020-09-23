#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	int n = (int) s.size();
	if (s[n - 1] == 's') {
		cout << s << "es" << '\n';
	} else {
		cout << s << 's' << '\n';
	}
}
