#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> divs(n);
		int tot = 1;
		for (int i = 0; i < n/2 + (n % 2); i++) {
			int cur = s[i] - 'a';
			cur++;
			divs[i] = cur;
			tot *= cur;
		}

		int sol = 0;
		for (int i = 0; i < n/2 + (n % 2); i++) {
			int k = tot;
			k /= divs[i];
			k *= (divs[i] - 1);
			sol += k;
		}
		cout << sol << '\n';
	}
}
