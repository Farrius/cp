#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int find_subset (int l, int u, int w[], int n, int result[]) {
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; i++) {
		ar[i].first = w[i];
		ar[i].second = i;
	}
	sort(ar.begin(), ar.end());
	ll cur = 0;
	for (int i = 0, j = 0; i < n; i++) {
		cur += ar[i].first;
		while (cur > u) {
			cur -= ar[j].first;
			j++;
		}
		if (cur >= l) {
			for (int k = j; k <= i; k++) {
				result[k - j] = ar[k].second;
			}
			return i - j + 1;
		}
	}
	return 0;
}
