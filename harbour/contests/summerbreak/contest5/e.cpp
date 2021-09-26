#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct seg {
	int sz = 1;
	vector<int> seg;

	void init (int n) {
		while (sz < n) {
			sz *= 2;
		}
		seg.assign(2 * sz, 1e9);
	}

	void put (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) {
			put(i, v, 2 * x + 1, lx, m);
		} else {
			put(i, v, 2 * x + 2, m, rx);
		}
		seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
	}

	void put (int i, int v) {
		put(i, v, 0, 0, sz);
	}

	int qry (int k, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return x - sz + 1;
		}
		int m = (lx + rx)/2;
		if (k >= seg[2 * x + 2]) {
			return qry(k, 2 * x + 2, m, rx);
		} else {
			return qry(k, 2 * x + 1, lx, m);
		}
	}

	int qry (int k) {
		return qry(k, 0, 0, sz);
	}
};

vector<ll> fn (vector<int> ar) {
	int n = (int) ar.size() - 1;
	vector<ll> dp(n + 1);
	seg st;
	st.init(n + 1);
	st.put(0, 0);
	for (int i = 1; i <= n; i++) {
		int j = st.qry(ar[i]);
		dp[i] = dp[j] + (i - j) * 1LL * ar[i];
		st.put(i, ar[i]);
	}
	return dp;
}

int main () {
	int n;
	cin >> n;
	vector<int> ar(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}

	vector<ll> dp = fn(ar);
	for (int i = 0; i < n; i++) {
		swap(ar[i], ar[i + 1]);
	}
	reverse(ar.begin(), ar.end());
	vector<ll> dp1 = fn(ar);
	for (int i = 0; i < n; i++) {
		swap(ar[i], ar[i + 1]);
	}
	reverse(ar.begin(), ar.end());
	//coger mejor
	ll best = 0;
	int in = -1;
	for (int i = 1; i <= n; i++) {
		if (dp[i] + dp1[n - i + 1] - ar[i] > best) {
			best = dp[i] + dp1[n - i + 1] - ar[i];
			in = i;
		}
	}
	//cout sol
	vector<int> sol(n + 1);
	sol[in] = ar[in];
	for (int i = in - 1; i >= 1; i--) {
		sol[i] = min(sol[i + 1], ar[i]);
	}
	for (int i = in + 1; i <= n; i++) {
		sol[i] = min(sol[i - 1], ar[i]);
	}
	for (int i = 1; i <= n; i++) cout << sol[i] << ' ';
	cout << '\n';
}
