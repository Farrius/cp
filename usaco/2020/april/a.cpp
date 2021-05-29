#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

ll bit[MX * 2];
int n;

void upd (int i, int val) {
	for (; i <= n; i += i&(-i)) {
		bit[i] += val;
	}
}

ll qry (int i) {
	ll res = 0;
	for (; i > 0; i -= i&(-i)) {
		res += bit[i];
	}
	return res;
}

int main () {
	cin >> n;
	vector<queue<int>> nxtt(n + 1);
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		nxtt[ar[i]].push(i);
	}

	for (int i = 1; i <= n; i++) {
		nxtt[i].push(n + 5);
	}
	vector<int> nxt(n), prev(n, -1);
	for (int i = 0; i < n; i++) {
		nxtt[ar[i]].pop();
		nxt[i] = nxtt[ar[i]].front();
		prev[nxt[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		upd(nxt[i], 1);
	}

	vector<pair<int, int>> q;
	for (int r = n - 1; r >= 1; r--) {
		pair<int, int> cur;
		cur.first = r;
		cur.second = 0;
		q.push_back(cur);
		if (prev[r] == -1) continue;
		cur.first = prev[r];
		cur.second = 1;
		q.push_back(cur);
	}
	sort(q.begin(), q.end(), greater<pair<int, int>>());
	ll sol = 0;
	for (int i = 0; i < (int) q.size(); i++) {
		int j = q[i].first;
		int k = j;
		if (q[i].second == 1) {
			k = nxt[k];
		}
		int c = qry(k);
		if (q[i].second == 0) {
			sol += j - c;
		} else {
			sol -= max(0, j + 1 - c);
		}
		if (q[i].second == 0 && (i == (int) q.size() || q[i + 1].second != j)) {
			upd(nxt[j], -1);
		}
	}
	cout << sol << '\n';
}
