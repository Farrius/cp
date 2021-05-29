#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	set<int> oca;
	int cur = 0;
	for (int i = 0; ; i++) {
		if (cur >= 59) break;
		if (i % 2 == 0) cur += 5;
		else cur += 4;
		oca.insert(cur);
	}
	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		a += 2;
		vector<int> wins(a), posi(a, 1);
		int tira, turno = 0;
		while (cin >> tira) {
			if (tira == -1) break;
			posi[turno] += tira;
			if (posi[turno] < 59 && oca.count(posi[turno])) {
				posi[turno] = *oca.upper_bound(posi[turno]);
			}
			if (posi[turno] > 63) posi[turno] = 63 - (posi[turno] - 63);
			if (posi[turno] == 63) {
				wins[turno]++;
				fill(posi.begin(), posi.end(), 1);
			} else if (posi[turno] == 58) {
				posi[turno] = 1;
			} else if (posi[turno] == 42) {
				posi[turno] = 30;
			} else if (posi[turno] == 26 || posi[turno] == 53) {
				continue;
			}
			turno++;
			turno %= a;
		}
		int mx = 1;
		vector<int> winner;
		for (int i = 0; i < a; i++) {
			if (wins[i] >= mx) {
				if (wins[i] > mx) {
					winner.clear();
				}
				mx = wins[i];
				winner.push_back(i + 1);
			}
		}
		if ((int) winner.size() != 1) cout << 0 << '\n';
		else cout << winner[0] << '\n';
	}
}
