#include <bits/stdc++.h>

using namespace std;


int dp[31][31][31], n, tope;

int fn (int turn, int mana, vector<int>& ar, vector<int>& cr, int rival) {
	if (dp[turn][mana][rival] != -1) return dp[turn][mana][rival];
	if (rival <= 0) {
		return dp[turn][mana][rival] = turn;
	} else {
		int res = fn(turn + 1, min(tope, mana + 5), ar, cr, max(0, rival - 1));
		for (int i = 0; i < n; i++) {
			if (cr[i] <= mana) {
				res = min(res, fn(turn + 1, mana - cr[i], ar, cr, max(0, rival - ar[i])));
			}
		}
		return dp[turn][mana][rival] = res;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b;
	int ah, am, bh, bm, an, bn;
	while (cin >> a >> ah >> am) {
		cin >> b >> bh >> bm;
		cin >> an;
		vector<int> ar(an), ac(an);
		for (int i = 0; i < an; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < an; i++) {
			cin >> ac[i];
		}
		cin >> bn;
		vector<int> br(bn), bc(bn);
		for (int i = 0; i < bn; i++) {
			cin >> br[i];
		}
		for (int i = 0; i < bn; i++) {
			cin >> bc[i];
		}

		memset(dp, -1, sizeof(dp));
		n = (int) ar.size();
		tope = am;
		int u = fn(0, am, ar, ac, bh);
		memset(dp, -1, sizeof(dp));
		n = (int) br.size();
		tope = bm;
		int d = fn(0, bm, br, bc, ah);

		if (u <= d) cout << a << '\n';
		else cout << b << '\n';
	}
}
