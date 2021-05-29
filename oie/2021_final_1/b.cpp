#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<string> dic;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		dic.push_back(s);
	}
	vector<int> cnt(26);
	for (int i = 0; i < 7; i++) {
		char x;
		cin >> x;
		cnt[x - 'A']++;
	}
	int sol = 0;
	for (auto palabra : dic) {
		vector<int> ccnt = cnt;
		bool ok = true;
		for (auto c : palabra) {
			int in = c - 'A';
			if (ccnt[in] == 0) ok = false;
			ccnt[in]--;
		}
		if (ok) {
			int sz = (int) palabra.size();
			if (sz <= 3) {
				sol = max(sol, sz);
			} else {
				sol = max(sol, sz * 2);
			}
		}
	}
	cout << sol << '\n';
}
