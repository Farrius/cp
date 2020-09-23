#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int a[m], b[m], col[n];
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		if(a[i] > b[i]) swap(a[i], b[i]);
	}
	
	for (int i = 0; i < n; i++) {
		int g;
		for (g = 1; g <= 4; g++) {
			bool ok = true;
			for (int j = 0; j < m; j++){
				if (b[j] == i && col[a[j]] == g) ok = false;
			}
			if (ok) break;
		}
		col[i] = g;
		cout << g;
	}
	cout << '\n';
}
