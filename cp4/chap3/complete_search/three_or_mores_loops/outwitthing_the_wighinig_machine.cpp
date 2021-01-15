#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int n = 10;
		int ar[n], cur[n];
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		tot = tot/4;
		sort(ar, ar + n);
		cur[0] = ar[0];
		cur[9] = ar[9];
		int c = tot - ar[0]- ar[9];
		bool ok =  true;
		for (int i = 1; i <= 8 && ok; i++) {
			for (int j = i + 1; j <= 8 && ok; j++) {
				for (int k = j + 1; k <= 8 && ok; k++) {
					for (int u = k + 1; u <= 8 && ok; u++) {
						int a = ar[i] - c;
						int b = ar[j] - c;
						int d = ar[k] - c;
						int e = ar[u] - c;
						cur[0] = a + b;
						cur[1] = a + c;
						cur[2] = a + d;
						cur[3] = a + e;
						cur[4] = b + c;
						cur[5] = b + d;
						cur[6] = b + e;
						cur[7] = d + c;
						cur[8] = d + e;
						cur[9] = e + c;
						sort(cur, cur + n);
						bool good = true;
						for (int in = 0; in < n; in++) {
							f (cur[in] != ar[in]) good = false;
						}
						if (!good) continue;
						ok = false;
						cout << "Case " << test << ": " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
					}
				}
			}
		}
	}
}
