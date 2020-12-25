#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int div = j - i + 1, tot = 0;
			bool ok = true;
			set<int> st;
			for (int k = i; k <= j; k++) {
				st.insert(ar[k]);
				tot += ar[k];
			}
			if (tot % div) {
				ok = false;
			} else {
				if (!st.count(tot/div)) ok = false;
			}
			if (ok) sol++;
		}
	}
	cout << sol << '\n';
}
