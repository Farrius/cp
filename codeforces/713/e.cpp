#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		vector<int> res;
		int dist = r - l + 1;
		int mx = 0, cur = 0;
		vector<bool> vis(n + 1);
		for (int i = 0; i < dist; i++) {
			mx += n - i;
			cur += i + 1;
			res.push_back(i + 1);
			vis[i + 1] = true;
		}
		if (s > mx || s < cur) {
			cout << -1 << '\n';
			continue;
		}
		int i = 0, j = 0;
		while (s > cur) {
			int diff = s - cur;
			j = n;
			while (j >= 1 && (j - res[i] > diff || vis[j])) {
				j--;
			}
			if (j == 0) {
				i++;
				continue;
			}
			vis[res[i]] = false;
			cur -= res[i];
			cur += j;
			res[i] = j;
			vis[j] = true;
			j--;
			i++;
		}
		//imprimir la respuesta
		vector<int> resto;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) resto.push_back(i);
		}
		j = 0;
		for (int i = 0; i < l - 1; i++) {
			cout << resto[j] << ' ';
			j++;
		}
		for (auto x : res) cout << x << ' ';
		for (int i = r; i < n; i++) {
			cout << resto[j] << ' ';
			j++;
		}
		cout << '\n';
	}
}
