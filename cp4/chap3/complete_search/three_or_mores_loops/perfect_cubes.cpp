#include <bits/stdc++.h>

using namespace std;

int fn (int n) {
	if (n <= 0) return -1;
	for (int i = 1; i * i * i<= n; i++) {
		if (i * i * i == n) return i;
	}
	return -1;
}

int main () {
	set<pair<int, pair<int, int>>> st;
	for (int a = 6; a <= 200; a++) {
		int obj = a * a * a;
		for (int b = 2; b < a; b++) {
			for (int c = b + 1; c < a; c++) {
				int d = fn(obj - b * b * b - c * c * c);
				if (d == 1 || d == -1 || d == c || d == a || d == b) continue;
				int di = d, ci = c, bi = b;
				if (ci > di) swap(ci, di);
				if (bi > ci) swap(bi, ci);
				if (st.count(make_pair(bi, make_pair(ci, di)))) continue;
				st.insert(make_pair(bi, make_pair(ci, di)));
				cout << "Cube = " << a << ", Triple = (" << bi << "," << ci << ',' << di << ")" << '\n';
			}
		}
	}
}
