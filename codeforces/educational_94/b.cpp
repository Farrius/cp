#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		int p, f;
		cin >> p >> f;
		int cntS, cntW;
		cin >> cntS >> cntW;
		int s, w;
		cin >> s >> w;
		int sol = 0;

		if (s > w) {
			swap(s, w);
			swap(cntS, cntW);
		}

		for (int i = 0; i <= cntS; i++) {
			int cojoEspada = min (i, p/s);
			int cojoHacha = min (cntW, (p - (cojoEspada * s))/w);
			int yo = cojoEspada + cojoHacha;

			int cogeEspada = min (cntS - cojoEspada, f/s);
			int cogeHacha = min(cntW - cojoHacha, (f - (cogeEspada * s))/w);
			int el = cogeEspada + cogeHacha;

			sol = max(sol, yo + el);
		}

		cout << sol << '\n';
	}
}
