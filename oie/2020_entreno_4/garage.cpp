#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int n, m;
	cin >> n >> m;
	set<int> parking;
	int c[n], w[m];
	vector<int> ocupa(m);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		parking.insert(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	ll sol = 0;
	queue<int> q;
	for (int i = 0; i < m * 2; i++) {
		int x;
		cin >> x;
		while (!q.empty() && !parking.empty()) {
			int car = q.front();
			int park = *parking.begin();
			sol += w[car] * c[park];
			ocupa[car] = park;
			parking.erase(park);
			q.pop();
		}
		if (x > 0) {
			x--;
			q.push(x);
		} else {
			x = -x;
			x--;
			parking.insert(ocupa[x]);
		}
	}
	cout << sol << '\n';
}
