#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define len(x) (int) x.size()
using namespace std;
using ll = long long;
using ld = long double;

char ma[8][8];
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
vector<vector<string>> steps(64, vector<string>(64, string(1e4, 'a')));
bool vis[8][8];

bool ok (int i, int j) {
	return i >= 0 && i < 8 && j >= 0 && j < 8 && ma[i][j] != 'C';
}

string step (int i, int j, int k, int dir) {
	string tostep = "";
	if (dir == 0) {
		if (k == 1) {
			tostep += "RR";
		} else if (k == 2) {
			tostep += "R";
		} else if (k == 3) {
			tostep += "L";
		}
	} else if (dir == 1) {
		if (k == 0) {
			tostep += "RR";
		} else if (k == 2) {
			tostep += "L";
		} else if (k == 3) {
			tostep += "R";
		}
	} else if (dir == 2) {
		if (k == 0) {
			tostep += "L";
		} else if (k == 1) {
			tostep += "R";
		} else if (k == 3) {
			tostep += "RR";
		}
	} else {
		if (k == 0) {
			tostep += "R";
		} else if (k == 1) {
			tostep += "L";
		} else if (k == 2) {
			tostep += "RR";
		}
	}
	if (ma[i][j] == 'I') tostep += "X";
	tostep += "F";
	return tostep;
}

int main () {
	int startx = -1, starty = -1, endx = -1, endy = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ma[i][j];
			if (ma[i][j] == 'D') {
				endx = j;
				endy = i;
			} else if (ma[i][j] == 'T'){
				startx = j;
				starty = i;
			}
		}
	}
	priority_queue<pair<int, pair<int, pair<int, int>>>> pq;
	pq.push(mp(0, mp(0, mp(starty, startx))));
	steps[starty][startx] = "";
	while (!pq.empty()) {
		int i = pq.top().s.s.f;
		int j = pq.top().s.s.s;
		int dir = pq.top().s.f;
		pq.pop();
		if (vis[i][j]) continue;
		vis[i][j] = true;
		for (int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ok(ni, nj)) {
				string nxtstep = step(ni, nj, k, dir);
				if (len(steps[ni][nj]) > len(steps[i][j]) + len(nxtstep)) {
					steps[ni][nj] = steps[i][j] + nxtstep;
					pq.push(mp(-len(steps[ni][nj]), mp(k, mp(ni, nj))));
				}
			}
		}
	}
	if (!vis[endy][endx]) cout << "no solution" << '\n';
	else cout << steps[endy][endx] << '\n';
}
