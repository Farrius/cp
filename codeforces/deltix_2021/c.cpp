#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


void fn (stack<int> lista) {
	vector<int> cur;
	while (!lista.empty()) {
		cur.push_back(lista.top());
		lista.pop();
	}
	reverse(cur.begin(), cur.end());
	for (int i = 0; i < (int) cur.size(); i++) {
		if (i > 0) cout << '.';
		cout << cur[i];
	}
	cout << '\n';
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		stack<int> lista;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x > 1) {
				while (!lista.empty() && lista.top() + 1 != x) lista.pop();
				lista.pop();
			}
			lista.push(x);
			stack<int> imp = lista;
			fn(imp);
		}
	}
}
