#include <bits/stdc++.h>

using namespace std;

void qry (vector<int>& ar, int b) {
	cout.flush() << (int) ar.size() << ' ' << 1 << ' ';
	for (auto x : ar) cout.flush() << x << ' ';
	cout.flush() << b << '\n';
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ar;
		for (int i = 1; i < n; i++) {
			ar.push_back(i);
		}
		int d;
		qry(ar, n);
		cin >> d;
		int pd = d;
		while ((int) ar.size() > 1) {
			vector<int> br, cr;
			for (int i = 0; i < (int) ar.size(); i++) {
				if (i < (int) ar.size()/2) br.push_back(ar[i]);
				else cr.push_back(ar[i]);
			}
			qry(br, n);
			cin >> d;
			if (d == pd) {
				ar = br;
			} else {
				ar = cr;
			}
		}
		int a = ar[0];
		ar.clear();
		for (int i = 1; i <= n; i++) {
			if (i == a) continue;
			ar.push_back(i);
		}
		qry(ar, a);
		cin >> d;
		cout.flush() << -1 << ' ' << d << '\n';
	}
}
