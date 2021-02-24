#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	while (cin >> s) {
		cout << "le ";
		int n = (int) s.size(); 
		for (int i = 0; i < n; i++) {
			string cmp = "";
			if (i < n - 1) {
				cmp += s[i];
				cmp += s[i + 1];
			}
			if (s[i] == 'r') {
				cout << "rg";
			} else if (i < n - 1 && cmp == "oi") {
				cout << "ua";
				i++;		
			} else if (s[i] == 'n' && i == n - 2 && s[i + 1] == 't') {
				cout << "ng";
				i++;
			} else {
				cout << s[i];
			}
		}
		cout << '\n';
	}
}
