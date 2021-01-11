#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main () {
	int n;
	ll c;
	cin >> n >> c;
	vector<pair<int, int>> events;
	for (int i = 0; i < n; i++) {
		int a, b, ci;
		cin >> a >> b >> ci;
		b++;
		events.push_back({a, ci});
		events.push_back({b, -ci});
	}
	sort(events.begin(), events.end(), cmp);
	ll tot = 0, cur = 0;
	int last_day = -1e9;
	int m = (int) events.size();
	for (int i = 0; i < m; i++) {
		int days = events[i].first - last_day;
		last_day = events[i].first;
		tot += min(cur, c) * 1LL * days;
		cur += events[i].second;
	}
	cout << tot << '\n';
}
