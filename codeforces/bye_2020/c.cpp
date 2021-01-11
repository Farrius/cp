#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		vector<bool> vis(n);
		for (int i = 1; i < n - 1; i++) {
			if (s[i - 1] == s[i + 1] && !vis[i - 1] && !vis[i + 1]) vis[i + 1] = true;
			if (s[i] == s[i - 1] && !vis[i - 1] && !vis[i]) vis[i] = true;
		}
		if (n >= 2 && s[n - 1] == s[n - 2] && !vis[n - 1] && !vis[n - 2]) vis[n - 1] = true;
		int sol = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i]) sol++;
		}
		cout << sol << '\n';
	}
}
