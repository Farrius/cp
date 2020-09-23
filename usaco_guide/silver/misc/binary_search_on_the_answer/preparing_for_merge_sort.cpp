#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;

	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	vector<vector<int>> sol(n);
	vector<int> last(n, -1);

	for (int i = 0; i < n; i++) {
		int k = upper_bound(last.begin(), last.end(), ar[i], greater<int>()) - last.begin();
		sol[k].push_back(ar[i]);
		last[k] = ar[i];
	}

	for (int i = 0; i < n; i++) {
		if (last[i] == -1) continue;
		for (int j = 0; j < (int) sol[i].size(); j++) {
			cout << sol[i][j] << (j == (int) sol[i].size() - 1 ? '\n' : ' ');
		}
	}
}
