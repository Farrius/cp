#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct pueblo {
	int diff;
	int a;
	int b;
	bool operator<(pueblo y) {
		return diff > y.diff;
	}
};

void res (int x, int y) {
	cout.flush() << "! " << x + 1 << ' ' << y + 1 << '\n';
}

void qry (int x, int y) {
	cout.flush() << "? " << x + 1 << ' ' << y + 1 << '\n';
}

int main () {
	int n;
	cin >> n;
	int kas[n];
	vector<pair<int, int>> ar;
	int zeros = 0;
	for (int i = 0; i < n; i++) {
		cin >> kas[i];
		ar.push_back(make_pair(kas[i], i));
	}
	sort(ar.begin(), ar.end());
	vector<pueblo> diffs;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int ii, jj, x, y;
			tie(x, ii) = ar[i];
			tie(y, jj) = ar[j];
			pueblo cur;
			cur.diff = y - x;
			cur.a = ii;
			cur.b = jj;
			diffs.push_back(cur);
		}
	}
	sort(diffs.begin(), diffs.end());
	for (auto cur : diffs) {
		string llega;
		qry(cur.b, cur.a);
		cin >> llega;
		if (llega == "Yes") {
			res(cur.a, cur.b);
			return 0;
		}
	}
	res(-1, -1);
}
