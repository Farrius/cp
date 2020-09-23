#include <bits/stdc++.h>

using namespace std;

const int MX = 1e4 + 4;

int sol[MX];

int query (int& a, int& b) {
	cout << "? " << a << ' ' << b << '\n';
	int x;
	cin >> x;
	return x;
}

int main () {
	int n;
	cin >> n;
	memset(sol, -1, sizeof(sol));
	int ok = 1;

	int j = 1;

	for (int i = 2; i <= n; i++) {
		int q1 = query (i, j);
		int q2 = query (j, i);

		if (q1 < q2) {
			sol[j] = q2;
			j = i;
		} else {
			sol[i] = q1;
		}
	}

	cout.flush() << "! ";
	for (int i = 1; i <= n; i++) {
		if (sol[i] == -1) cout.flush() << n << (i == n ? '\n' : ' ');
		else cout.flush() << sol[i] << (i == n ? '\n' : ' ');
	}
}
