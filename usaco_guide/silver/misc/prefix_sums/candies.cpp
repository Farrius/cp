#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;

int n, q;
int ar[maxN];
vector<long long> ipsEven(maxN), ipsOdd(maxN),  psEven(maxN), psOdd(maxN);

void updatePrefix (int j) {
	for (int i = j; i < n; i++) {
		if ((i + 1) % 2 == 0) {
			psEven[i + 1] = psEven[i] + ar[i];
			ipsEven[i + 1] = ipsEven[i] + ar[i] * (i + 1);
			psOdd[i + 1] = psOdd[i];
			ipsOdd[i + 1] = ipsOdd[i];
		} else {
			psOdd[i + 1] = psOdd[i] + ar[i];
			ipsOdd[i + 1] = ipsOdd[i] + ar[i] * (i + 1);
			psEven[i + 1] = psEven[i];
			ipsEven[i + 1] = ipsEven[i];
		}
	}
}

int main () {
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {

		cin >> n >> q;
		
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		
		updatePrefix(0);

		long long sol = 0;

		while (q--) {
			char tipo;
			cin >> tipo;

			if (tipo == 'Q') {
				int l, r;
				cin >> l >> r;
				long long resta, suma, cur = 0;
				if (l % 2 == 0) {
					cur += ipsEven[r] - ipsEven[l - 1];
					cur -= ipsOdd[r] - ipsOdd[l - 1];
					cur -= (psEven[r] - psEven[l - 1]) * (l - 1);
					cur += (psOdd[r] - psOdd[l - 1]) * (l - 1);
				} else {
					cur -= ipsEven[r] - ipsEven[l - 1];
					cur += ipsOdd[r] - ipsOdd[l - 1];
					cur += (psEven[r] - psEven[l - 1]) * (l - 1);
					cur -= (psOdd[r] - psOdd[l - 1]) * (l - 1);
				}

				sol += cur;
			} else {
				int u, v;
				cin >> u >> v;
				u--;
				ar[u] = v;

				updatePrefix(u);
			}
		}

		cout << "Case #" << tt << ": "<< sol << '\n';
	}
}
