#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	int ssn, ssm;
	cin >> ssn >> ssm;
	int sn = ssn * n, sm = ssm * m;
	int ma[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
		}
	}
	//cout << sn << ' ' << sm << '\n';
	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sm; j++) {
			int y = i/ssn;
			int x = j/ssm;
			//cout << y << ' ' << x << '\n';
			cout << ma[y][x] << ' ';
		}
		cout << '\n';
	}
}
