#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (s[i] == 'a') cout << 'b';
				else cout << 'a';
			} else {
				if (s[i] == 'z') cout << 'y';
				else cout << 'z';
			}
		}
		cout << '\n';
	}
}
