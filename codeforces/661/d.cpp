#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int tope = 0;
		vector<int> ans;
		stack<int> ar[2];

		for (int i = 0; i < n; i++) {
			int c = s[i] - '0';
			if (ar[!c].empty()) {
				tope++;
				ans.push_back(tope);
				ar[c].push(tope);
			} else {
				int cur = ar[!c].top();
				ar[!c].pop();
				ans.push_back(cur);
				ar[c].push(cur);
			}
		}
		cout << tope << '\n';

		for (int i = 0; i < n; i++) {
			cout << ans[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
