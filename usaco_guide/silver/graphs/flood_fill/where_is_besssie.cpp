#include <bits/stdc++.h>

using namespace std;

int n, di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
string ma[20];
struct PCL { int i1,j1,i2,j2; };
vector<PCL> sols;
bool vis[20][20];

void ff (int i, int j, char cur, int i1, int j1, int i2, int j2) {
	if (i < i1 || j < j1 || i > i2 || j > j2 || vis[i][j] || ma[i][j] != cur) return;
	vis[i][j] = true;

	for (int k = 0; k < 4; k++) {
		ff (i + di[k], j + dj[k], cur, i1, j1, i2, j2);
	}
}

bool is_PCL(int i1, int j1, int i2, int j2) {
	int colors = 0;
  	int colorsArr[26] = {0};
	
	for (int i = i1; i <= i2; i++) {
		for (int j = j1; j <= j2; j++) {
			vis[i][j] = false;
		}
	}

  	for (int i = i1; i <= i2; i++) {
    		for (int j = j1; j <= j2; j++) {
      			if (vis[i][j]) continue;

			int c = ma[i][j] - 'A';
			if (colorsArr[c] == 0) colors++;
			colorsArr[c]++;

			for (int k = 0; k < 4; k++) {
				ff (i + di[k], j + dj[k], ma[i][j], i1, j1, i2, j2);
			}
		}
	}

	if (colors != 2) return false;

  	bool one = false, more = false;
  	for (int i = 0; i < 26; i++) {
    		if (colorsArr[i] == 1) one = true;
    		if (colorsArr[i] > 1) more = true;
  	}

  	return one && more;
}

bool PCL_in_PCL(int x, int y) {
  	return sols[x].i1 >= sols[y].i1 && sols[x].i2 <= sols[y].i2 && sols[x].j1 >= sols[y].j1 && sols[x].j2 <= sols[y].j2;
}

bool PCL_maximal(int x) {
	for (int i = 0; i < (int) sols.size(); i++) {
	  if (i != x && PCL_in_PCL(x,i)) return false; 
	}

  	return true;
}

int main() {
	freopen("where.in", "r", stdin);
	freopen("where.out", "w",stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ma[i];
	}

  	for (int i1 = 0; i1 < n; i1++) {
    		for (int j1 = 0; j1 < n; j1++) {
      			for (int i2 = i1; i2 < n; i2++) {
				for (int j2 = j1; j2 < n; j2++) {
	  				if (is_PCL(i1,j1,i2,j2)) {
	    					PCL p = {i1,j1,i2,j2};
	    					sols.push_back(p);
	  				}
				}
			}
		}
	}

  	int sol = 0;
  	for (int i = 0; i < (int) sols.size(); i++) {
    		if (PCL_maximal(i)) sol++;
	}
	cout << sol << '\n';
}
