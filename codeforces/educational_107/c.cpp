#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	map<int, int> posi;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		posi[ar[i]] = i + 1;
	}
	vector<pair<int, int>> br;
	for (auto cur : posi) {
		br.push_back(make_pair(cur.second, cur.first));
	}
	sort(br.begin(), br.end());

	while (q--) {
		int t;
		cin >> t;
		int in = 0;
		for (int i = 0; i < (int) br.size(); i++) {
			if (br[i].second == t) {
				in = i;
				cout << br[i].first << ' ';
				br[i].first = 1;
				break;
			} else {
				br[i].first++;
			}
		}
		for (int i = in; i >= 1; i--) {
			swap(br[i], br[i - 1]);
		}
	}
	cout << '\n';
}
