#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	if (b == 0) return a;
	else return gcd (b, a % b);
}

int cur;

bool cmp (const int& a, const int& b) {
	if (gcd (cur, a) == gcd (cur, b)) return a < b;
	else return (gcd (cur, a)) < (gcd (cur, b));
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ar(n), sol(n), pref;

		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		for (int i = 0; i < n; i++) {
			int x = 0;

			for (auto k: pref) {
				x = gcd (x, k);
			}
			
			cur = x;
			sort (ar.begin(), ar.end(), cmp);
			sol[i] = ar[(int) ar.size() - 1];
			pref.push_back(sol[i]);
			ar.pop_back();
		}

		for (int i = 0; i < n; i++) {
			cout << sol[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
