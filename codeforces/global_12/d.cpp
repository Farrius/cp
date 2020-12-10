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
		int ar[n];
		vector<int> freq(n + 1);
		int hasta = n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			freq[ar[i]]++;
			if (freq[ar[i]] > 1) {
				hasta = min(hasta, ar[i]);
			}
		}
		int i = 0, j = n - 1, fins = 0;
		string sol;
		for (int obj = 1; obj <= hasta; obj++) {
			if (ar[i] < obj || ar[j] < obj) break;
			if (ar[i] == obj) {
				i++;
				sol += "1";
			} else if (ar[j] == obj) {
				j--;
				sol += "1";
			} else {
				bool ok = false;
				for (int k = i + 1; k < j; k++) {
					if (ar[k] == obj) ok = true;
				}
				if (ok) {
					sol += "1";
					fins = obj;
				}
				break;
			}
			fins = obj;
		}
		for (int k = fins; k < n - 1; k++) {
			sol += "0";
		}
		sort(ar, ar + n);
		if (fins < n) {
			bool perm = (ar[0] == 1);
			for (int i = 0; i < n - 1; i++) {
				if (ar[i + 1] != ar[i] + 1) perm = false;
			}
			if (perm) sol += "1";
			else sol += "0";
		}
		reverse(sol.begin(), sol.end());
		cout << sol << '\n';
	}
}
