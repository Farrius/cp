#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("cowjog.in", "r", stdin);
	freopen("cojog.out", "w", stdout);

	int n, t;
	cin >> n >> t;
	vector<int> ar;
	for (int i = 0; i < n; i++) {
		int en, st;
		cin >> st >> en;
		int x = -(st + en * t);
		int j = upper_bound(ar.begin(), ar.end(), x) - ar.begin();
		if (j == (int) ar.size()) ar.push_back(x);
		else ar[j]= x;
	}

	cout << (int) ar.size() << '\n';
}
