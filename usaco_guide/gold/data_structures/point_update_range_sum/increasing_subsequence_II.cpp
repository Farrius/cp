#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

int bit[MX];
int n;

void upd (int i, int val) {
	for (; i <= n; i += (i & (-i))) {
		bit[i] = (bit[i] + val) % MOD;
	}
}

int query (int i) {
	int res = 0;
	for (; i; i -= (i & (-i))) {
		res = (res + bit[i]) % MOD;
	}
	return res;
}

int main () {
	cin >> n;
	map<int, int> m;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		m[ar[i]]++;
	}
	int co = 0;
	for (auto &cur : m) {
		cur.second = ++co;
	}
	for (int &x : ar) {
		x = m[x];
	}
	int sol = 0;
	for (int x : ar) {
		int subseq = 1 + query(x - 1);
		sol = (sol + subseq) % MOD;
		upd(x, subseq);
	}
	cout << sol << '\n';
}
