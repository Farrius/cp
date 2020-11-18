#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<int> ops(n * 2);
	vector<int> last;
	for (int i = 0; i < n * 2; i++) {
		char cur;
		cin >> cur;
		if (cur == '+') {
			last.push_back(i);
		} else {
			cin >> ops[i];
			if (last.empty()) {
				cout << "NO" << '\n';
				return 0;
			}
			ops[last.back()] = -ops[i];
			last.pop_back();
		}
	}

	set<int> st;
	for (int i = 0; i < n * 2; i++) {
		if (ops[i] < 0) {
			st.insert(-ops[i]);
		} else {
			if (st.empty() || *st.begin() != ops[i]) {
				cout << "NO" << '\n';
				return 0;
			}
			st.erase(st.begin());
		}
	}

	cout << "YES" << '\n';
	for (int i = 0; i < n * 2; i++) {
		if (ops[i] < 0) cout << -ops[i] << ' ';
	}
	cout << '\n';
}
