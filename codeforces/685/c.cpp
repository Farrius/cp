#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
using ld = long double;
int main () { 
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		vector<int> cnta(26), cntb(26);
		for (int i = 0; i < n; i++) {
			cnta[a[i] - 'a']++;
			cntb[b[i] - 'a']++;
		}
		bool ok = true;
		for (int i = 25; i >= 0 && ok; i--) {
			int obj = cntb[i];
			int cur = 0;
			for (int j = i; j >= 0 && cur < obj && ok; j--) {
				if (j == i) {
					cur += cnta[j];
					cnta[j] = 0;
					continue;
				}
				while (cur < obj && cnta[j] >= k) {
					cur += k;
					cnta[j] -= k;
				}
			}
			if (cur != obj) ok = false;
		}

		if (ok) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}
