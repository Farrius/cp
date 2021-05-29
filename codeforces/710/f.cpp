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
		vector<pair<int, int>> nodes;
		bool start = true;
		int ar[n], br[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> br[i];
		}
		for (int i = 0; i < n; i++) {
			if (ar[i] == 1 && br[i] == 1) start = false;
			nodes.push_back(make_pair(ar[i], br[i]));
		}
		if (start) {
			nodes.push_back(make_pair(1, 1));
		}
		sort(nodes.begin(), nodes.end());
		int sol = 0;
		for (int i = 0; i < (int) nodes.size() - 1; i++) {
			int r, c;
			tie(r, c) = nodes[i];
			int dist = nodes[i + 1].first - r;
			int nxt = dist + c;
			int sobra = nxt - nodes[i + 1].second;
			if (sobra == 0) {
				if ((r + c) % 2 == 0) {
					sol += dist;
				}
				continue;
			}
			if ((r + c) % 2 == 0) {
				r++;
			} 
			dist = nodes[i + 1].first - r;
			nxt = dist + c;
			sobra = nxt - nodes[i + 1].second;
			sol += (sobra + 1)/2;
		}
		cout << sol << '\n';
	}
}
