#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	
	vector<int> sinks, sources;

	for (int i = 0; i < n; i++) {
		int u = true, d = true;
		for (int j = 0; j < n; j++) {
			if (mat[i][j]) u = false;
			if (mat[j][i]) d = false;
		}
		if (u) sinks.push_back(i);
		if (d) sources.push_back(i);
	}

	for (auto x : sources) {
		cout << x + 1 << ' ';
	}
	cout << '\n';
	for (auto x : sinks) {
		cout << x + 1 << ' ';
	}
	cout << '\n';
}
