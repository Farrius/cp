#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	bool par = true, inp = true;
	for (int i = 0; i < (int) s.size(); i++) {
		if (i % 2 == 0 && s[i] < 'a') par = false;
		else if (i % 2 && s[i] > 'Z') inp = false;
	}
	if (par && inp) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
