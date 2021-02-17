#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int h, w;
	cin >> h >> w;
	string ma[h];
	for (int i = 0; i < h; i++) {
		cin >> ma[i];
	}
	int sides = 0;
	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w - 1; j++) {
			int cur = 0;
			if (ma[i][j] == ma[i + 1][j + 1]) cur++;
			if (ma[i][j] == ma[i][j + 1]) cur++;
			if (ma[i][j] == ma[i + 1][j]) cur++;
			if (cur == 0 || cur == 2) sides++;
		}
	}
	cout << sides << '\n';
}
