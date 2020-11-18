#include <bits/stdc++.h>

using namespace std;

bool open (int res, int i) {
	return (res == -1 || res > i);
}

void exploreCave(int n) {
	int ok[n], par[n];
	vector<bool> skip(n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (skip[j]) continue;
			ok[j] = 1;
		}
		int res = tryCombination(ok);
		bool state = open(res, i);
		int lo = 0, hi = n - 1;
		int sol = hi;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			for (int j = lo; j <= mid; j++) {
				if (skip[j]) continue;
				ok[j] ^= 1;
			}
			int cur = tryCombination(ok);
			bool cur_state = open(cur, i);
			if (state != cur_state) {
				hi = mid - 1;
				sol = mid;
			} else {
				lo = mid + 1;
			}
			state = cur_state;
		}
		par[sol] = i;
		if (!state) ok[sol] ^= 1;
		skip[sol] = true;
	}
	answer(ok, par);
}


