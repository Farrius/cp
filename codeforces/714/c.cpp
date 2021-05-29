#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 50;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> dp(MX);
	deque<int> cur;
	cur.push_back(1);
	for (int i = 0; i < 9; i++) {
		cur.push_back(0);
	}
	int tot = 1;
	dp[0] = tot;
	for (int i = 1; i < MX; i++) {
		//actualizar tot
		int atras = cur.back();
		cur.pop_back();
		tot = (tot + atras) % MOD;
		dp[i] = tot;
		//sumar zeros que seran unos
		int unos = cur.front();
		cur.pop_front();
		unos = (unos + atras) % MOD;
		cur.push_front(unos);
		cur.push_front(atras);
	}
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int sol = 0;
		while (n) {
			int dig = n % 10;
			sol = (sol + dp[dig + m]) % MOD;
			n /= 10;
		}
		cout << sol << '\n';
	}
}

