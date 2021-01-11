#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	pair<int, int> ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ld x = ar[j].first - ar[i].first, y = ar[j].second - ar[i].second;
			ld un = 1;
			if (-un <= y/x && y/x <= un) sol++;
		}
	}
	cout << sol << '\n';
}
