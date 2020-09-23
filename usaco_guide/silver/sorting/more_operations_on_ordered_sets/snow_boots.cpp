#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5;

int prof[MX], nieve[MX], salto[MX];

bool cmp_d (const int& a, const int& b) {
	return prof[a] < prof[b];
}

bool cmp_b (const int& a, const int& b) {
	return nieve[a] < nieve[b];
}

int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

	int n, b;
	cin >> n >> b;
	int dId[n], bId[b];

	for (int i = 0; i < n; i++) {
		cin >> prof[i];
		dId[i] = i;
	}

	for (int i = 0; i < b; i++) {
		cin >> nieve[i] >> salto[i];
		bId[i] = i;
	}

	sort(dId, dId + n, cmp_d);
	sort(bId, bId + b, cmp_b);

	int nxt[n], prv[n];

	for (int i = 0; i < n; i++) {
		nxt[i] = i + 1;
		prv[i] = i - 1;
	}

	int j = n - 1;
	int maxSalto = 1;
	int ans[b];
	for (int i = b - 1; i >= 0; i--) {
		int bota = bId[i];

		while(j > 0 && prof[dId[j]] > nieve[bota]) {
			int cur = dId[j];
			nxt[prv[cur]] = nxt[cur];
			prv[nxt[cur]] = prv[cur];
			maxSalto = max(maxSalto, nxt[cur] - prv[cur]);
			j--;
		}

		ans[bota] = (salto[bota] >= maxSalto);
	}

	for (int i = 0; i < b; i++) {
		cout << ans[i] << '\n';
	}
}
