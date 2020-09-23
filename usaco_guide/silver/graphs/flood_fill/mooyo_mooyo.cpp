#include <bits/stdc++.h>

using namespace std;

const int MX = 1e2;

bool vis[MX][10], curVis[MX][10];
int ma[MX][10], di[4] = {0, 0, -1, 1}, dj[4] = {1, -1, 0, 0};
vector<pair<int, int>> region, deleteRegion;
int n, k, cur, total;

void ff (int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= 10 || curVis[i][j] || ma[i][j] != cur) return;

	curVis[i][j] = true;
	region.push_back(make_pair(i, j));
	total++;

	for (int k = 0; k < 4; k++) {
		ff (i + di[k], j + dj[k]);
	}
}

bool ok (int i, int j) {
	region.clear();
	cur = ma[i][j];
	total = 0;

	ff (i, j);

	return (total >= k);
}

int main () {
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			char x;
			cin >> x;
			int cur = x - '0';
			vis[i][j] = (cur == 0);
			ma[i][j] = cur;
		}
	}

	while (true) {
		bool change = false;
		deleteRegion.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				curVis[i][j] = vis[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (curVis[i][j]) continue;
				if (ok (i, j)) {
					change = true;
					for (auto x: region) {
						deleteRegion.push_back(x);
					}
				}
			}
		}

		if (!change) break;

		for (auto x: deleteRegion) {
			ma[x.first][x.second] = 0;
		}

		for (int j = 0; j < 10; j++) {
			int haybale = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				if (ma[i][j] != 0) {
					int cur = ma[i][j];
					ma[i][j] = 0;
					ma[haybale][j] = cur;
					haybale--;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				vis[i][j] = (ma[i][j] == 0);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << ma[i][j];
		}
		cout << '\n';
	}

}
