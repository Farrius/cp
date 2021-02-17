#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		int n;
		cin >> n >> s;
		vector<int> pref(n + 1), suf(n + 1);
		deque<char> dq;
		for (int i = n - 1; i >= 0; i--) {
			if (!dq.empty() && dq.front() == s[i]) {
				dq.clear();
			}
			dq.push_front(s[i]);
			if (!dq.empty() && dq.front() == 'R') suf[i] = (int) dq.size();
		}
		dq.clear();
		for (int i = 1; i <= n; i++) {
			if (!dq.empty() && dq.back() == s[i - 1]) {
				dq.clear();
			}
			dq.push_back(s[i - 1]);
			if (!dq.empty() && dq.back() == 'L') pref[i] = (int) dq.size();
		}
		for (int i = 0; i <= n; i++) {
			cout << pref[i] + suf[i] + 1 << (i == n ? '\n' : ' ');
		}
	}
}
