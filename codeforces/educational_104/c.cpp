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
		int m = n * (n - 1)/2;
		vector<bool> empat(n);
		int obj = (m * 3)/n;
		if ((m * 3) % n != 0) {
			for (int i = 0; i < n; i++) {
				empat[i] = true;
			}
		}
		vector<int> win(n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (empat[i]) {
					cout << 0 << ' ';
					empat[i] = false;
					empat[j] = false;
					win[i]++;
					win[j]++;
				} else {
					vector<pair<int, int>> ar;
					for (int k = j; k < n; k++) {
						ar.push_back(make_pair(win[k], k));
					}
					bool ganar[n];
					memset(ganar, false, sizeof(ganar));
					sort(ar.begin(), ar.end(), greater<pair<int, int>>());
					for (auto cur : ar) {
						if (win[i] == obj) break;
						win[i] += 3;
						ganar[cur.second] = true;
					}
					for (int k = j; k < n; k++) {
						if (ganar[k]) {
						       	cout << -1 << ' ';
						} else {
						       	cout << 1 << ' ';
							win[k] += 3;
						}
					}
					break;
				}
			}
		}
		cout << '\n';
	}
}
