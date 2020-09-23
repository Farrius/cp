#include <bits/stdc++.h>

using namespace std;

const int MX = 250;

bool vis[MX][MX];
int ma[MX][MX];
int n, di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0}, alone = 0, group = 0, one, two, curAlone = 0, curGroup = 0;

void ff1 (int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || (ma[i][j] != one && ma[i][j] != two)) return;

	vis[i][j] = true;
	curGroup++;

	for (int k = 0; k < 4; k++) {
		ff1 (i + di[k], j + dj[k]);
	}
}

void ff (int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || ma[i][j] != one) return;

	vis[i][j] = true;
	curAlone++;

	for (int k = 0; k < 4; k++) {
		ff (i + di[k], j + dj[k]);
	}
}

int main () {
	freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);

	cin >> n;
	set<int> numbers;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ma[i][j];
			if (!numbers.count(ma[i][j])) {
				nums.push_back(ma[i][j]);
				numbers.insert(ma[i][j]);
			}
		}
	}

	int oneCow = 0, twoCows = 0;

	for (int i = 0; i < (int) nums.size(); i++) {
		alone = 0;
		one = nums[i];
		memset(vis, false, sizeof(vis));
		
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (vis[y][x]) continue;
				curAlone = 0;
				ff (y, x);
				alone = max (alone, curAlone);
			}
		}

		oneCow = max (oneCow, alone);

		for (int j = i + 1; j < (int) nums.size(); j++) {
			group = 0;
			two = nums[j];
			memset(vis, false, sizeof(vis));

			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (vis[y][x]) continue;
					curGroup = 0;
					ff1 (y, x);
					group = max (group, curGroup);
				}
			}

			twoCows = max (twoCows, group);
		}
	}

	cout << oneCow << '\n';
	cout << twoCows << '\n';
}
