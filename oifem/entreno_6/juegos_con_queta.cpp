#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int pos[MX], ar[MX], state[MX];

bool cmp (const int& a, const int& b) {
	return pos[a] < pos[b];
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m1, m2;
		cin >> n >> m1 >> m2;
		for (int i = 0; i < n; i++) {
			cin >> pos[i];
			ar[i] = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> state[i];
		}
		sort(ar, ar + n, cmp);
		stack<int> stck;
		int sol = 0;
		for (int i = 0; i < n; i++) {
			if (state[ar[i]] == 2) {
				stck.push(1);
			} else {
				if (stck.empty()) sol++;
				else stck.pop();
			}
		}
		cout << sol + (int) stck.size() << '\n';
	}
}
