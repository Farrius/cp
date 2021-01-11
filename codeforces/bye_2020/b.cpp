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
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n);
		for (int i = 0; i < n; i++) {
			int j = i;
			while (j < n - 1 && ar[j + 1] == ar[i]) j++;
			if (j > i) {
				ar[j]++;
				i = j - 1;
			} else {
				i = j;
			}
		}
		set<int> st;
		for (int i = 0; i < n; i++) {
			st.insert(ar[i]);
		}
		cout << (int) st.size() << '\n';
	}
}
