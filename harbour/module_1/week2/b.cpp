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
	bool undi = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j]) {
				if (!mat[j][i]) undi = false;
			}
		}
	}
	if (undi) cout << "NO" << '\n';
	else cout << "YES" << '\n';
}
