#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	priority_queue<pair<int, int>> pq;
	for (int i = 2; i <= 1000; i++) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (ar[j] % i == 0) cur++;
		}
		pq.push({cur, i});
	}
	cout << pq.top().second << '\n';
}
