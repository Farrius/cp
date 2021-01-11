#include <bits/stdc++.h>

using namespace std;

int main () {
	int m, q;
	cin >> m >> q;
	string data[m];
	for (int i = 0; i < m; i++) {
		cin >> data[i];
	}
	while (q--) {
		string s;
		cin >> s;
		int in = 0, mx = 0;
		int n = s.size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j + n <= (int) data[i].size(); j++) {
				string comp = data[i].substr(j, n);
				int cur_mx = 0;
				for (int i = 0; i < n; i++) {
					if (comp[i] == s[i]) cur_mx++;
				}
				if (cur_mx > mx) {
					mx = cur_mx;
					in = i + 1;
				}
			}
		}
		cout << in << '\n';
	}
}
