#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> ar(n), cp_ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	cp_ar = ar;
	sort(cp_ar.begin(), cp_ar.end());
	int sol = 0;
	for (int i = 0; i < n; i++) {
		int x = ar[i];
		int obj = upper_bound(cp_ar.begin(), cp_ar.end(), x) - cp_ar.begin();
		if (obj != n - 1 && obj > 0) obj--;
		if (obj >= i) continue;
		sol = max(sol, i - obj);
	}
	cout << sol + 1 << '\n';
}
