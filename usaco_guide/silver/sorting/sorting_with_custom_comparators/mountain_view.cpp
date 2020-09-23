#include <bits/stdc++.h>

using namespace std;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}

	return a.first < b.first;
}

int main() {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);

	int n;
	cin >> n;
	pair<int, int> ar[n];

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ar[i].first = x - y;
		ar[i].second = x + y;
	}
	
	sort(ar, ar + n, cmp);
	
	int tope = -1;
	int sol = 0;

	for (auto x: ar) {
		if (x.second > tope) {
			sol++;
			tope = x.second;
		}
	}

	cout << sol << '\n';
}

