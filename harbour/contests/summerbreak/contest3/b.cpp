#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int main () {
	int q;
	cin >> q;
	int l = 0, r = 0;
	vector<int> cnt(MX), prefr(q), prefl(q), par(MX);
	vector<bool> tipo(MX);
	for (int i = 0; i < q; i++) {
		if (i > 0) {
			prefr[i] = prefr[i - 1];
			prefl[i] = prefl[i - 1];
		}
		char c;
		int id;
		cin >> c >> id;	
		if (c == 'L') {
			cnt[id] = l + r;
			l++;
			prefl[i]++;
			tipo[id] = true;
			par[id] = i;
		} else if (c == 'R') {
			cnt[id] = l + r;
			r++;
			prefr[i]++;
			par[id] = i;
		} else {
			int otro = cnt[id];
			if (tipo[id]) otro += prefr[i] - prefr[par[id]];
			else otro += prefl[i] - prefl[par[id]];
			cout << min(otro, r + l - otro - 1) << '\n';
	 	}
	}
}
