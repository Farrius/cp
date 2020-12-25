#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ar(n), br(n), or_ar(n), or_br(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i] >> br[i];
		}
		or_ar = ar, or_br = br;
		sort(or_ar.begin(), or_ar.end());
		sort(or_br.begin(), or_br.end());
		
		int sol = n - 1;
		for (int i = 0; i < n; i++) {
			int cur = lower_bound(or_br.begin(), or_br.end(), ar[i]) - or_br.begin();
			cur += n - (upper_bound(or_ar.begin(), or_ar.end(), br[i]) - or_ar.begin());
			sol = min(sol, cur);
		}
		cout << sol << '\n';
	}
}
