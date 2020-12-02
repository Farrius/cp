#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll a, s;
	cin >> a >> s;
	ll obj = s - a;
	string num = to_string(a), obj_s = to_string(obj);
	bool ok = true;
	int n = (int) obj_s.size();
	int m = (int) num.size();
	if (n != m) ok = false;
	vector<bool> vis(n);
	for (int i = 0; i < n; i++) {
		char cur = obj_s[i];
		char take = 'z';
		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;
			if (cur == num[j]) {
				take = num[j];
				vis[j] = true;
				break;
			}
		}
		if (take != cur) ok = false;
	}
	if (ok) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
