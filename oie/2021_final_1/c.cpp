#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;
string s;
bool ok = false;

void fn (int msk) {
	vector<int> ar;
	for (int i = 0; i < n; i++) {

	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int i = 0; i < (1<<n); i++) {
			if (ok) break;
			fn(i);
		}
		if (!ok) cout << "NO" << '\n';
	}
}
