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
		string s1, s2;
		cin >> s1 >> s2;
		int red = 0, blue = 0;
		for (int i = 0; i < n; i++) {
			if (s1[i] > s2[i]) red++;
			else if (s2[i] > s1[i]) blue++;
		}
		if (red > blue) cout << "RED" << '\n';
		else if (blue > red) cout << "BLUE" << '\n';
		else cout << "EQUAL" << '\n';
	}
}
