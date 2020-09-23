#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int cc[MX], p[MX], pos[MX], sol[MX], l[100], r[100], n, m, k;
vector<int> ar[MX];
int main () {
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}

	for (int i = 0; i < n; i++) {
		p[i] = i;
		for (int j = 0; j < m; j++) {
			if (p[i] >= l[j] && p[i] <= r[j]) {
				p[i] = l[j] + r[j] - p[i];
			}
		}
	}
	
	int c = 1;

	for (int i = 0; i < n; i++) {
		if (cc[i]) continue;
		cc[i] = c;
		ar[c].push_back(i);

		int j = p[i];
		if (i != j) pos[j] = 1;

		while (i != j) {
			cc[j] = c;
			ar[c].push_back(j);
			if (p[j] != i) pos[p[j]] = pos[j] + 1;
			j = p[j];
		}
		
		c++;
	}

	for (int i = 0; i < n; i++) {
		sol[ar[cc[i]][(pos[i] + k) % (int) ar[cc[i]].size()]] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << sol[i] + 1 << '\n';
	}
}
