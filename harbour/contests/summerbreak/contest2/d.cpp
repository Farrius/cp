#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int sol = 0;
	if (n%2 && s1[n/2] != s2[n/2]) sol++;
	for (int i = 0; i < n/2; i++) {
		set<char> tots;
		tots.insert(s1[i]);
		tots.insert(s2[i]);
		tots.insert(s1[n - i - 1]);
		tots.insert(s2[n - i - 1]);
		int m = (int) tots.size();
		if (m == 4) {
			sol += 2;
		} else if (m == 3) {
			sol++;
			if (s1[i] == s1[n - i - 1]) sol++;
		} else if (m == 2) {
			int ig = 0;
			if (s1[i] == s2[i]) ig++;
			if (s1[i] == s1[n - i - 1]) ig++;
			if (s1[i] == s2[n - i - 1]) ig++;
			
			if (ig == 2 || ig == 0) sol++;
		}
	}
	cout << sol << '\n';
}
