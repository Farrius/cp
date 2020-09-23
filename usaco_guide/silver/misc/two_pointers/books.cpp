#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, t;
	cin >> n >> t;

	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int sol = 0, cur = 0;
	int r = 0;
	queue<int> q;

	while (r < n) {
		if (cur < t) {
			if (r >= n) break;
			if (cur + ar[r] > t) {
				if (ar[r] > t) {
					queue<int> q1;
					q = q1;
					cur = 0;
					r++;
				} else {
					cur -= q.front();
					q.pop();
				}
			} else {
				cur += ar[r];
				q.push(ar[r]);
				r++;
			}
		} else {
			cur -= q.front();
			q.pop();
		}
		sol = max(sol, (int) q.size());
	}

	cout << sol << '\n';
}
