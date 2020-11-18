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
		bool busca = false;
		int sol = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			int x; 
			cin >> x;
			if (x == 1) {
				busca = true;
				sol += cnt;
				cnt = 0;
			} else {
				if (busca) cnt++;
			}
		}

		cout << sol << '\n';
	}
}
