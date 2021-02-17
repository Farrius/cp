#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}
	vector<int> posi[n], ind(n, 0);
	for (int i = 0; i < n; i++) {
		posi[ar[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		posi[i].push_back(1e9);
	}
	int x = -1, y = -1, sol = 0;
	for (int i = 0; i < n; i++) {
		int z = ar[i];
		if (z == x || z == y) continue;
		int cur_x = x < 0 ? n : *lower_bound(posi[x].begin(), posi[x].end(), i);
		int cur_y = y < 0 ? n : *lower_bound(posi[y].begin(), posi[y].end(), i);
		if (cur_x > cur_y) {
			x = z;
		} else {
			y = z;
		}
		sol++;
	}
	cout << sol << '\n';
}
