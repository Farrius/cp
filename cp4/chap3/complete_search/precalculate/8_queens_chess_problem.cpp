#include <bits/stdc++.h>

using namespace std;

const int n = 8;
bool row[n], dig1[n * 2 - 1], dig2[n * 2 - 1];
vector<vector<int>> sol;
vector<int> cur(n);
int y, x;

void fn (int j) {
	if (j == n) {
		sol.push_back(cur);
	} else if (j == x) {
		fn(j + 1);
	} else {
		for (int i = 0; i < n; i++) {
			if (row[i] || dig1[i + j] || dig2[j - i + n - 1]) continue;
			row[i] = dig1[i + j] = dig2[j - i + n - 1] = true;
			cur[j] = i;
			fn(j + 1);
			row[i] = dig1[i + j] = dig2[j - i + n - 1] = false;
		}
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		memset(row, false, sizeof(row));
		memset(dig1, false, sizeof(dig1));
		memset(dig2, false, sizeof(dig2));
		sol.clear();
		cin >> y >> x;
		y--; x--;
		row[y] = dig1[x + y] = dig2[x - y + n - 1] = true;
		cur[x] = y;
		fn(0);
		cout << "SOLN" << "       " << "COLUMN" << '\n';
		cout << " #" << "      " << "1 2 3 4 5 6 7 8" << '\n';
		cout << '\n';
		for (int i = 0; i < (int) sol.size(); i++) {
			if (i < 9) cout << ' ';
			cout << i + 1 << "      ";
			for (int j = 0; j < 8; j++) {
				cout << sol[i][j] + 1 << (j == 7 ? '\n' : ' ');
			}
		}
		if (t != 0) cout << '\n';
	}
}
