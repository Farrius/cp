#include <bits/stdc++.h>

using namespace std;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main () {
	int n;
	cin >>n;
	pair<int, int> ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}

	sort (ar, ar + n, cmp);
	long long t = 0;
	long long sol = 0;

	for (auto x: ar) {
		t += x.first;
		sol += x.second - t;
	}

	cout << sol << '\n';
}
