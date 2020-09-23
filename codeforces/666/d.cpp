#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const int PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		int maxi = *max_element(ar.begin(), ar.end());
		int tot = accumulate(ar.begin(), ar.end(), 0);	

		if (tot % 2 || maxi > tot - maxi) cout << "T" << '\n';
		else cout << "HL" << '\n';
	}
}
