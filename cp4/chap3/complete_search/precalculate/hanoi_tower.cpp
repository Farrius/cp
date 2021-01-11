#include <bits/stdc++.h>

using namespace std;

vector<stack<int>> ar(55, stack<int>());
int n, sol = 0;

bool check (int k) {
	for (int i = 1; i * i <= k; i++) {
		if (i * i == k) return true;
	}
	return false;
}

void fn (int i) {
	bool ok = false;
	for (int j = 0; j < n && !ok; j++) {
		if (!ar[j].empty() && check(i + ar[j].top())) {
			ok = true;
			ar[j].push(i);
			fn(i + 1);
		} else if (ar[j].empty()) {
			ok = true;
			ar[j].push(i);
			fn(i + 1);
		}
	}
	if (!ok) return;
	sol = max(sol, i);
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			while (!ar[i].empty()) ar[i].pop();
		}
		sol = 0;
		fn(1);
		cout << sol << '\n';
	}
}
