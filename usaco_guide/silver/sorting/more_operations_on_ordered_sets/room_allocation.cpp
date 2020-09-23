#include <bits/stdc++.h>

using namespace std;


bool cmp (const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	return a.second.first < b.second.first;
}

int main() {
	int n;
	cin >> n;
	pair<int, pair<int, int>> ar[n];
	
	for (int i = 0; i < n; i++) {
		ar[i].first = i;
		cin >> ar[i].second.first >> ar[i].second.second;
	}

	sort(ar, ar + n, cmp);

	priority_queue<pair<int, int>> pq;
	vector<pair<int, int>> ans;
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		int habita;
		if (!pq.empty() && ar[i].second.first > -pq.top().first) {
			habita = pq.top().second;
			pq.pop();
		} else {
			habita = (int) pq.size() + 1;
		}
		pq.push(make_pair(-ar[i].second.second, habita));
		maxi = max(maxi, habita);
		ans.push_back(make_pair(ar[i].first, habita));
	}
	
	sort(ans.begin(), ans.end());
	cout << maxi << '\n';

	for (int i = 0; i < n; i++) {
		cout << ans[i].second << (i == n - 1 ? '\n' : ' ');
	}
}
