#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mem;
int mx, sol;

void my_ask (int i) {
	if (mem[i][0] == -1) mem[i] = ask(i);
}

void solve (int l, int r, int q) {
	if (q == 0) return;
	if (r - l == q) {
		for (int i = l + 1; i <= r; i++) {
			my_ask(i);
			if (mem[i][0] + mem[i][1] == 0) sol = i;
		}
		return;
	}
	int mid = (l + r)/2, lollipop = -1;
	for (int i = mid; i <= r; i++) {
		my_ask(i);
		if (mem[i][0] + mem[i][1] == 0) {
			sol = i;
			return;
		}
		if (mem[i][0] + mem[i][1] == mx) {
			lollipop = i;
			break;
		}
	}
	if (lollipop == -1) {
		solve(l, mid - 1, q - (r - mid + 1));
	} else {
		solve(l, mid - 1, mem[lollipop][0] - mem[l][0] - (lollipop - mid));
		solve(lollipop, r, q - mem[lollipop][0] + mem[l][0]);
	}
}

int find_best (int n) {
	mem = vector<vector<int>>(n, vector<int>(2, -1));
	mx = 0;
	int ind = 0;
	for (int i = 0; i < min(n, 473); i++) {
		my_ask(i);
		if (mem[i][0] + mem[i][1] == 0) return i;
		if (mem[i][0] + mem[i][1] > mx) {
			mx = mem[i][0] + mem[i][1];
			ind = i;
		}
		if (mx >= 26) break;
	}
	solve(ind, n - 1, mem[ind][1]);
	return sol;
}	
