#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;

int fn (vector<pair<int, int>>& ar) {
	if (ar.size() == 2) {
		if (ar[0].first < ar[1].first) swap(ar[0], ar[1]);
		return ar[1].second + 1;
	} else {
		vector<pair<int, int>> nw_ar;
		for (int i = 0; i < (int) ar.size(); i += 2) {
			if (ar[i].first < ar[i + 1].first) swap(ar[i], ar[i + 1]);
			nw_ar.push_back(ar[i]);
		}
		return fn(nw_ar);
	}
}

int main () {
	cin >> n;
	vector<pair<int, int>> ar((1<<n));
	for (int i = 0; i < (1<<n); i++) {
		cin >> ar[i].first;
		ar[i].second = i;
	}
	cout << fn(ar) << '\n';
}
