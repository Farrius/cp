#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	map<int, int> un, dos, tres;
	int n = (int) s.size();
	for (int i = 0; i < n; i++) {
		int cur = s[i] - '0';
		un[cur]++;
		dos[cur]++;
		tres[cur]++;
	}
	
	if (n <= 2) {
		int cur = stoi(s, nullptr, 10);
		string rs = s;
		reverse(rs.begin(), rs.end());
		int rcur = stoi(rs, nullptr, 10);
		if (cur % 8 == 0 || rcur % 8 == 0) cout << "Yes" << '\n';
		else cout << "No" << '\n';
		return 0;
	}

	for (auto unit : un) {
		for (auto diez : dos) {
			for (auto cien : tres) {
				if ((unit.first == diez.first || unit.first == cien.first) && unit.second <= 1) continue;
				if (diez.first == cien.first && diez.second <= 1) continue;
				if (unit.first == diez.first && unit.first == cien.first && unit.second <= 2) continue;
				int u = unit.first % 8;
				int d = (diez.first * 2) % 8;
				int t = (cien.first * 4) % 8;
				if ((u + d + t) % 8 == 0) {
					cout << "Yes" << '\n';
					return 0;
				}
			}
		}
	}

	cout << "No" << '\n';
}
