#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main() {
	int n;
	cin >> n;
	char ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int l = 0, r = n - 1;
	int sol = 0;

	while (l < r) {
		if(ar[l] != ar[r] && ar[l] == 'W') {
			swap(ar[l], ar[r]);
			sol++;
			l++;
			r--;
			continue;
		}
		
		if(ar[l] == 'R') {
			l++;
		}

		if(ar[r] == 'W') {
			r--;
		}
	}

	cout << sol << '\n';
}
