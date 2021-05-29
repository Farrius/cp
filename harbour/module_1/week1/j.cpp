#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool comp (pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main () {
	int n;
	cin >> n;
	pair<int, int> ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}
	sort(ar, ar + n, comp);
	for (int i = 0; i < n; i++) {
		cout << ar[i].first << ' ' << ar[i].second << '\n';
	}
}
