#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
       	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<queue<int>> let(26);
		for (int i = 0; i < n; i++) {
			int cur = s[i] - 'a';
			let[cur].push(i);
		}
		int m = 0, seg = -1;
		while (m < k) {
			for (int c = 0; c < 26; c++) {
				while (!let[c].empty() && (let[c].front() <= seg)) let[c].pop();
				if (let[c].empty() || let[c].front() + (k - m) > n) continue;
				cout << (char) ('a' + c);
				seg = let[c].front();
				let[c].pop();
				break;
			}
			m++;
		}
		cout << '\n';
	}
}
