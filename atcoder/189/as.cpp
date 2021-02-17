#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	if (s[0] == s[1] && s[0] == s[2] && s[2] == s[1]) cout << "Won" << '\n';
	else cout << "Lost" << '\n';
}
