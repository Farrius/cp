#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	map<string, int> freq;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		freq[s]++;
	}
	vector<pair<int, string>> ar;
	for (auto x : freq) {
		ar.push_back(make_pair(x.second, x.first));
	}
	sort(ar.begin(), ar.end(), greater<pair<int, string>>());
	int cnt = 5, prev = -1;
	cout << 5 << ' ';
	for (auto x : ar) {
		if (cnt == 0) break;
		//cout << x.first << ' ' << x.second << '\n';
		//for (int i = 0; i < min(cnt, x.first); i++) {
		//	cout << ' ' << x.second;
		//}
		cout << x.second << ' ';
		cnt--;
	}
	cout << '\n';
}
