#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, t, q;

vector<int> ar(3);

void upd (int i, int x) {
	vector<int> br = ar;
	br.push_back(x);
	if (i == (int) ar.size()) {
		ar = br;
		return;
	}
	br[i] = x;
	for (int j = i; j < (int) ar.size(); j++) {
		br[j + 1] = ar[j];
	}
	ar = br;
	return;
}

int qry;

void ask (int a, int b, int c) {
	cout.flush() << ar[a] << ' ' << ar[b] << ' ' << c << '\n';
	cin >> qry;
}

int main () {
	cin >> t >> n >> q;
	while (t--) {
		ar = vector<int>(3);
		iota(ar.begin(), ar.end(), 1);
		ask(0, 1, 3);
		if (qry == 1) swap(ar[0], ar[1]);
		if (qry == 3) swap(ar[1], ar[2]);
		for (int i = 4; i <= n; i++) {
			int lo = 0, hi = (int) ar.size() - 1;
			while (true) {
				int mid = (lo + hi)/2;
				if (hi - lo == 1) {
					ask(lo, lo + 1, i);
					if (qry == ar[lo]) upd(lo, i);
					else if (qry == i) upd(lo + 1, i);
					else upd(lo + 2, i);
					break;
				}
				ask(lo, mid, i);
				if (qry == ar[lo]) {
					upd(lo, i);
					break;
				} else if (qry == i) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout.flush() << ar[i] << (i == n - 1 ? '\n' : ' ');
		}
		cin >> qry;
		if (qry == -1) break;
	}
}
