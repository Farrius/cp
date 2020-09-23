#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> freq;

		int ar[n];

		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		sort(ar, ar + n);

		int al = 100, ba = 0;
		int sol = -1;

		for (int mid = 2; mid <= 100; mid++) {
			int l = 0, r = n - 1;
			int curSol = 0;
			while (l < r) {
				if (ar[l] + ar[r] == mid) {
					curSol++;
					l++;
					r--;
					continue;
				}

				if (ar[l] + ar[r] < mid) {
					l++;
					continue;
				}

				if (ar[l] + ar[r] > mid) {
					r--;
					continue;
				}

			}
			sol = max(sol, curSol); 
		}

		cout << sol << '\n';

	}
}
