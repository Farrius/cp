#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ar(n), br(n);
		int tota = 0, totb = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tota += ar[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> br[i];
			totb += br[i];
		}
		if (tota != totb) {
			cout << -1 << '\n';
			continue;
		}

		vector<pair<int, int>> sol;
		for (int i = 0; i < n; i++) {
			if (ar[i] > br[i]) {
				for (int j = i + 1; j < n && ar[i] > br[i]; j++) {
					while (ar[j] < br[j] && ar[i] > br[i]) {
						ar[j]++;
						ar[i]--;
						sol.push_back(make_pair(i + 1, j + 1));
					}
				}
			}

			if (ar[i] < br[i]) {
				for (int j = i + 1; j < n && ar[i] < br[i]; j++) {
					while (ar[j] > br[j] && ar[i] < br[i]) {
						ar[j]--;
						ar[i]++;
						sol.push_back(make_pair(j + 1, i + 1));
					}
				}
			}

		}

		cout << (int) sol.size() << '\n';
		for (auto x : sol) {
			cout << x.first << ' ' << x.second << '\n';
		}
	}
}
