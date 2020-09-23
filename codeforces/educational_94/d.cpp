#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		vector<int> vistoL(n + 1);
		ll sol = 0;
		for (int l = 0; l < n; l++) {
			vector<int> vistoR(n + 1);
			for (int r = n - 1; r > l; r--) {
				sol += vistoL[ar[r]] * vistoR[ar[l]];
				vistoR[ar[r]]++;
			}
			vistoL[ar[l]]++;
		}
		
		cout << sol << '\n';
	}
}
