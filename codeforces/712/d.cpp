#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void print (int b, int i, int j) {
	cout.flush() << b << ' ' << i + 1 << ' ' << j +  1 << '\n';
}

int main () {
	int n;
	cin >> n;
	vector<pair<int, int>> blocks;
	vector<pair<int, int>> digs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2) blocks.push_back(make_pair(i, j));
			else digs.push_back(make_pair(i, j));
		}
	}
	int ib = 0, id = 0;
	int nb = (int) blocks.size();
	int nd = (int) digs.size();
	for (int t = 0; t < n * n; t++) {
		int a, b = 2;
		cin >> a;
		if (ib == nb) {
			if (a == 1) b = 3;
			else b = 1;
			print(b, digs[id].first, digs[id].second);
			id++;
			continue;
		}
		if (id == nd) {
			if (a == 2) b = 3;
			print(b, blocks[ib].first, blocks[ib].second);
			ib++;
			continue;
		}
		if (a == 1 || a == 3) {
			print(b, blocks[ib].first, blocks[ib].second);
			ib++;
		} else {
			b = 1;
			print(b, digs[id].first, digs[id].second);
			id++;
		}
	}
}
