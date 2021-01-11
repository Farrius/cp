#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		mp[x]++;
	}
	for (auto cur : mp) {
		string x = "!" + cur.first;
		if (mp[x]) {
			cout << cur.first << '\n';
			return 0;
		}
	}
	cout << "satisfiable" << '\n';
}
