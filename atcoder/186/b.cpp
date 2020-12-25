#include <bits/stdc++.h>

using namespace std;

int main () {
	int h, w;
	cin >> h >> w;
	int ma[h][w], mn = 101;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> ma[i][j];
			mn = min(mn, ma[i][j]);
		}
	}
	int sol = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			sol += ma[i][j] - mn;
		}
	}
	cout << sol << '\n';
}
