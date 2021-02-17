#include <bits/stdc++.h>

using namespace std;

struct Point {
	int x1, x2;
};
bool cmp (const Point& a, const Point& b) {
	return a.x1 < b.x1;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		vector<Point> far(m);
		for (int i = 0; i < m; i++) {
			int x, r;
			cin >> x >> r;
			far[i].x1 = x - r;
			far[i].x2 = x + r;
		}
		sort(far.begin(), far.end(), cmp);
		sort(ar, ar + n);
		bool ok = true;
		int sol = 0;
		int j = 0;
		for (int i = 0; i < n; i++, j++, sol++) {
			if (far[j].x1 > ar[i]) {
				ok = false;
				break;
			}
			int mx_x2 = far[j].x2;
			while (j < m - 1 && far[j + 1].x1 <= ar[i]) {
				mx_x2 = max(mx_x2, far[j + 1].x2);
				j++;
			}
			if (mx_x2 < ar[i]) {
				ok = false;
				break;
			}
			while (i < n - 1 && ar[i + 1] <= mx_x2) i++;
		}
		if (!ok) cout << "imposible" << '\n';
		else cout << sol << '\n';
	}
}
