#include <bits/stdc++.h>

#define mp make_pair
using namespace std;
using ll = long long;

const ll INF = 1e18;

int n;
ll t;
int ma[100][100];
vector<int> di1({0, 0, 1, -1}), dj1({1, -1, 0, 0});
vector<int> di2({2, -2, 0, 0, 1, 1, -1, -1}), dj2({0, 0, 2, -2, 1, -1, 1, -1});
vector<int> di3({3, -3, 0, 0, 2, 2, -2, -2, 1, 1, -1, -1}), dj3({0, 0, 3, -3, 1, -1, 1, -1, 2, -2, 2, -2});

ll d[100][100][3];
bool vis[100][100][3];

bool ok (int i, int j) {
	return i < n && i >= 0 && j < n && j >= 0;
}

int main () {
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);

	//take the input
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ma[i][j];
			d[i][j][0] = INF;
			d[i][j][1] = INF;
			d[i][j][2] = INF;
		}
	}
	//start the dijkstra
	d[0][0][0] = 0;
	priority_queue<pair<ll, pair<pair<int, int>, int>>> pq;
	pq.push(mp(0LL, mp(mp(0, 0), 0)));
	//dijkstra
	while (!pq.empty()) {
		int i, j, state;
		tie(i, j) = pq.top().second.first;
		state = pq.top().second.second;
		ll cur = -pq.top().first;
		pq.pop();
		if (vis[i][j][state]) continue;
		vis[i][j][state] = true;
		for (int moves = 1; moves <= 3; moves++) {
			if (state + moves > 3) continue;
			vector<int> di(moves * 4), dj(moves * 4);
			if (moves == 1) {
				di = di1;
				dj = dj1;
			} else if (moves == 2) {
				di = di2;
				dj = dj2;
			} else {
				di = di3;
				dj = dj3;
			}
			for (int k = 0; k < 4 * moves; k++) {
				if (ok(i + di[k], j + dj[k])) {
					ll next = d[i][j][state] + t * moves + ((state + moves) % 3 == 0 ? ma[i + di[k]][j + dj[k]] : 0);
					if (d[i + di[k]][j + dj[k]][(state + moves) % 3] > next) {
						d[i + di[k]][j + dj[k]][(state + moves) % 3] = next;
						pq.push(mp(-next, mp(mp(i + di[k], j + dj[k]), (state + moves) % 3)));
					}
				}
			}
		}
	}
	cout << min(d[n - 1][n - 1][0], min(d[n - 1][n - 1][1], d[n - 1][n - 1][2])) << '\n';
}
