#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		vector<int> ar(n);
		m--;
		ar[m] = 1;
		int a, b;
		while (cin >> a >> b) {
			if (a == 0 && b == 0) break;
			a--; b--;
			swap(ar[a], ar[b]);
		}
		for (int i = 0; i < n; i++) {
			if (ar[i]) cout << i + 1 << '\n';
		}
	}
}
