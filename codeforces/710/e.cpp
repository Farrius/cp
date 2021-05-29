#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void fn (vector<int>& ar) {
	int n = (int) ar.size();
	for (int i = 0; i < n; i++) {
		cout << ar[i] << (i == n - 1 ? '\n' : ' ');
	}
}

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
		vector<int> sol(n);
		set<int> candi;
		for (int i = 1; i <= n; i++) {
			candi.insert(i);
		}
		int mx = 0;
		for (int i = 0; i < n; i++) {
			if (ar[i] > mx) {
				mx = ar[i];
				sol[i] = mx;
				candi.erase(mx);
			} else {
				sol[i] = *candi.begin();
				candi.erase(*candi.begin());
			}
		}
		fn(sol);
		mx = 0;
		for (int i = 0; i < n; i++) {
			if (ar[i] > mx) {
				for (int j = ar[i] - 1; j > mx; j--) {
					candi.insert(j);
				}
				mx = ar[i];
				sol[i] = mx;
			} else {
				sol[i] = *candi.rbegin();
				candi.erase(*candi.rbegin());
			}
		}
		fn(sol);
	}
}
