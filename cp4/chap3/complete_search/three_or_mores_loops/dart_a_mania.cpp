#include <bits/stdc++.h>

using namespace std;

int main () {
	vector<int> ar(21);
	iota(ar.begin(), ar.end(), 0);
	int m = 21;
	for (int i = 0; i < m; i++) {
		 ar.push_back(ar[i] * 2);
		 ar.push_back(ar[i] * 3);
	}
	ar.push_back(50);
	int n;
	m = (int) ar.size();

	while (cin >> n) {
		if (n <= 0) break;
		set<pair<int, pair<int, int>>> st, st2;
		int perm = 0, combi = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					if (ar[i] + ar[j] + ar[k] == n) {
						int u = ar[i] , d = ar[j], t = ar[k];
						st2.insert(make_pair(u, make_pair(d, t)));
						if (u > d) swap(u, d);
						if (u > t) swap(u, t);
						if (d > t) swap(d, t);
						st.insert(make_pair(u, make_pair(d, t)));
					}
				}
			}
		}
		combi = (int) st.size();
		perm = (int) st2.size();
		if (perm == 0) {
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << '\n';
		} else {
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combi << '.' << '\n';
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << '.' << '\n';
		}
		cout << "**********************************************************************" << '\n';
	}
	cout << "END OF OUTPUT" << '\n';
}
