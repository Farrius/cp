#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		set<int> st;
		multiset<int> res;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			st.insert(ar[i]);
			res.insert(ar[i]);
		}
		for (auto x : st) {
			cout << x << ' ';
			res.erase(res.find(x));
		}
		for (auto x : res) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}
