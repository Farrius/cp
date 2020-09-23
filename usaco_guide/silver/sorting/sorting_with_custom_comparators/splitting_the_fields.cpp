#include <bits/stdc++.h>

using namespace std;
const int MX = 5e4;
int n, x[MX], y[MX], ar[MX];

bool cmp (const int& a, const int& b) {
	if (x[a] == x[b]) return y[a] < y[b];

	return x[a] < x[b];
}

bool cmp1 (const int& a, const int &b) {
	if (y[a] == y[b]) return x[a] < x[b];

	return y[a] < y[b];
}

int main () {
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);

	cin >> n;
	multiset<int> allX, allY, leftX, leftY, rightX, rightY;
	for (int i = 0; i < n; i++) {
		ar[i] = i;
		cin >> x[i] >> y[i];
		allX.insert(x[i]);
		allY.insert(y[i]);
	}

	sort (ar, ar + n, cmp);

	int x1 = *allX.rbegin(), x2 = *allX.begin(), y1 = *allY.rbegin(), y2 = *allY.begin();
	long long area = (x1 - x2) * 1LL * (y1 - y2);
	long long sol = 0;
	int j;
	
	for (int k = 0; k <= 1; k++) {
		rightX = allX;
		rightY = allY;
		leftX.clear();
		leftY.clear();
		for (int i = 0; i < n; i++) {
			j = ar[i];
			long long areaL = 0, areaR = 0;

			leftX.insert(x[j]);
			leftY.insert(y[j]);
			rightX.erase(rightX.find(x[j]));
			rightY.erase(rightY.find(y[j]));

			x1 = *leftX.begin();
			y1 = *leftY.begin();
			x2 = *leftX.rbegin();
			y2 = *leftY.rbegin();
			areaL = (x2 - x1) * 1LL * (y2 - y1);
			if (!rightX.empty()) {
				x1 = *rightX.begin();
				y1 = *rightY.begin();
				x2 = *rightX.rbegin();
				y2 = *rightY.rbegin();
				areaR = (x2 - x1) * 1LL * (y2 - y1);
			}
			sol = max (sol, area - (areaR + areaL));
		}
		sort (ar, ar + n, cmp1);
	}

	cout << sol << '\n';
}
