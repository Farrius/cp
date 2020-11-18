#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int sol = 1;
		int queda = 1, next = 0;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (i == 0) continue;
			if (ar[i] < ar[i - 1]) queda--;
			if (queda == 0) {
				sol++;
				queda = next;
				next = 1;
			} else {
				next++;
			}
		}
		cout << sol << '\n';
	}
}
