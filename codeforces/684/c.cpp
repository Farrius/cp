#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ma[n][m];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				ma[i][j] = s[j] - '0';
			}
		}
		vector<vector<int>> sol;
		bool parai = false;
		for (int i = 0; i < n; i += 2) {
			if (i == n - 1) break;
			for (int j = 0; j < m; j += 2) {
				if (j == m - 1) break;
				while (true) {
					int unos = 0;
					vector<pair<int, int>> coord;
					vector<bool> ok(4, false);
					vector<int> cur_sol;
					for (int i2 = 0; i2 < 2; i2++) {
						for (int j2 = 0; j2 < 2; j2++) {
							if (ma[i + i2][j + j2] == 1) unos++;
							coord.push_back(make_pair(i + i2, j + j2));
						}
					}
					if (unos == 0) {
						break;
					} else if (unos == 1) {
						int fijo = -1, cnt = 1;
						for (int k = 0; k < 4; k++) {
							int cur_i = coord[k].first, cur_j = coord[k].second;
							if (ma[cur_i][cur_j] == 1) {
								ok[k] = true;
								fijo = k;
							}
						}
						for (int k = 0; k < 4; k++) {
							if (ok[k]) continue;
							if (cnt < 3) {
								ok[k] = true;
								cnt++;
							}
						}
						for (int k = 0; k < 4; k++) {
							if (ok[k]) {
								cur_sol.push_back(coord[k].first);
								cur_sol.push_back(coord[k].second);
								ma[coord[k].first][coord[k].second] ^= 1;
							}
						}
					} else if (unos == 2) {
						bool puesto = false;
						for (int k = 0; k < 4; k++) {
							int cur_i = coord[k].first, cur_j = coord[k].second;
							if (ma[cur_i][cur_j] == 0) {
								ok[k] = true;
							} else {
								if (!puesto) {
									ok[k] = true;
									puesto = true;
								}
							}
						}
						for (int k = 0; k < 4; k++) {
							if (ok[k]) {
								cur_sol.push_back(coord[k].first);
								cur_sol.push_back(coord[k].second);
								ma[coord[k].first][coord[k].second] ^= 1;
							}
						}
					} else if (unos == 3) {
						for (int k = 0; k < 4; k++) {
							int cur_i = coord[k].first, cur_j = coord[k].second;
							if (ma[cur_i][cur_j] == 1) ok[k] = true;
						}
						for (int k = 0; k < 4; k++) {
							if (ok[k]) {
								cur_sol.push_back(coord[k].first);
								cur_sol.push_back(coord[k].second);
								ma[coord[k].first][coord[k].second] ^= 1;
							}
						}
					} else {
						for (int k = 0; k < 3; k++) {
							cur_sol.push_back(coord[k].first);
							cur_sol.push_back(coord[k].second);
							ma[coord[k].first][coord[k].second] ^= 1;
						}
					}
					sol.push_back(cur_sol);
				}
			}
		}
		cout << (int) sol.size() << '\n';
		for (auto vec : sol) {
			for (int i = 0; i < (int) vec.size(); i++) {
				cout << vec[i] + 1 << (i == (int) vec.size() - 1 ? '\n' : ' ');
			}
		}
	}
}
