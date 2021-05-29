#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct rmq {
	vector<int> v;
	vector<vector<int>> jmp;

	int comb (int a, int b) {
		if (v[a] == v[b]) {
			return min(a, b);
		} else {
			return v[a] < v[b] ? a : b;
		}
	}

	void init (vector<int>& _v) {
		v = _v;
		int m = (int) v.size();
		jmp = {vector<int>(m)};
		iota(jmp[0].begin(), jmp[0].end(), 0);
		for (int j = 1; (1<<j) <= m; j++) {
			jmp.push_back(vector<int>(m - (1<<j) + 1));
			for (int i = 0; i < m; i++) {
				jmp[j][i] = comb(jmp[j - 1][i], jmp[j - 1][i + (1<<(j -1))]);
			}
		}
	}

	int level (int x) {return 31 - __builtin_clz(x);}
	
	int index (int l, int r) {
		int d = level(r - l + 1);
		return comb(jmp[d][l], jmp[d][r - (1<<d) + 1]);
	}

	int query (int l, int r) {
		return v[index(l, r)];
	}
};

int main () {
	int n, q;
	cin >> n >> q;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	rmq rm;
	rm.init(ar);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << rm.query(l, r - 1) << '\n';
	}
}
