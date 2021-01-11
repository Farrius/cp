#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string ar;
		cin >> ar;
		int n = (int) ar.size();
		int sol = n/2;
		for (int i = 0; i < n - 1; i++) {
			if (i % 2 == 0) {
				if (ar[i] == ar[i + 1]) sol++;
			}
		}
		cout << sol << '\n';
	}
}
