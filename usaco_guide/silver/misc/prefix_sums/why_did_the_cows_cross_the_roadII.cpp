#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);

	int n, k, b;
	cin >> n >> k >> b;

	if (k == 0) {
		cout << 0 << '\n';
		return 0;
	}

	int intervals[n + 1];
	vector<int> segments = {1};

	for (int i = 0; i < b; i++) {
		int cur;
		cin >> cur;
		segments.push_back(cur);
	}

	segments.push_back(n);

	sort(segments.begin(), segments.end());
	vector<int> distancias;

	for (int i = 1; i < (int) segments.size(); i++) {
		distancias.push_back(segments[i] - segments[i - 1]);
	}

	queue<int> q;
	int sol = INT_MAX;	
	int suma = 0;
	int i = 0;
	while (i < (int) distancias.size() || suma >= k) {
		if (suma >= k) {
			sol = min(sol, (int) q.size() - 1);
			suma -= q.front();
			q.pop();
		} else {
			suma += distancias[i];
			q.push(distancias[i]);
			i++;
		}
	}

	cout << sol << '\n';
}
