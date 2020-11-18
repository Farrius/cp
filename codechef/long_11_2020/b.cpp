#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define len(x) (int) x.size()
using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n], sol[n];
		int cur = 4e6;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			ar[i]--;
			if (ar[i] == i) {
				sol[i] = cur;
				cur--;
			}
		}
		for (int i = 0; i < n; i++) {
			if (ar[i] != i) {
				sol[i] = sol[ar[i]];
			}
		}
		for (int i = 0; i < n; i++) {
			cout << sol[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
