#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	map<string, int> freq;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		freq[s]++;
	}
	string res;
	int sol = 0;
	for (auto x : freq) {
		if (x.second > sol) {
			sol = x.second;
			res = x.first;
		}
	}
	cout << res << '\n';
}
