#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n);
	priority_queue<int> segments;
	int sol = n;
	for (int i = 1; i < n; i++) {
		int cur = ar[i] - ar[i - 1] - 1;
		segments.push(cur);
		sol += cur;
	}
	k--;
	while (k-- && !segments.empty()) {
		sol -= segments.top();
		segments.pop();
	}
	cout << sol << '\n';
}
