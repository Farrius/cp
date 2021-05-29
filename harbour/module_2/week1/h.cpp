#include <bits/stdc++.h>

using namespace std;

int dist[10][10][10][10];
int par[10][10][10][10];

int num (int a, int b, int c, int d) {
	return a * 1000 + b * 100 + c * 10 + d * 1;
}

int main () {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				for (int p = 1; p <= 9; p++) {
					dist[i][j][k][p] = 1e9;
					par[i][j][k][p] = -1;
				}
			}
		}
	}
	int emp, fin;
	cin >> emp >> fin;
	int a, b, c, d;
	auto upd = [&] (int x) {
		a = x/1000;
		x = x % 1000;
		b = x/100;
		x = x % 100;
		c = x/10;
		x = x % 10;
		d = x/1;
	};
	upd(emp);
	dist[a][b][c][d] = 0;
	queue<int> q;
	q.push(emp);
	int dis, u;
	auto meter = [&] (int aa, int bb, int cc, int dd) {
		if (dist[aa][bb][cc][dd] == 1e9) {
			dist[aa][bb][cc][dd] = dis;
			par[aa][bb][cc][dd] = u;
			q.push(num(aa, bb, cc, dd));
		}
	};
	while (!q.empty()) {
		u = q.front();
		q.pop();
		upd(u);
		dis = dist[a][b][c][d];
		meter(b, c, d, a);
		meter(d, a, b, c);

		if (a < 9) meter(a + 1, b, c, d);

		if (d > 1) meter(a, b, c, d - 1);
	}

	vector<int> sol;
	while (fin != -1) {
		sol.push_back(fin);
		upd(fin);
		fin = par[a][b][c][d];
	}

	reverse(sol.begin(), sol.end());
	cout << (int) sol.size() << '\n';
	for (auto x : sol) {
		cout << x << '\n';
	}
}
