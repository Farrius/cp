#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 105;

vector<pair<int, int>> station[MX][MX];

struct P {
	int x, y, con, cos;
	bool operator<(P a) const {
		return con < a.con;
	}
};

int main () {
	//coger input
	int xs, ys, xd, yd;
	cin >> xs >> ys >> xd >> yd;
	int b;
	cin >> b;
	int co;
	cin >> co;
	int t;
	cin >> t;
	vector<int> c(t + 1);
	c[0] = co;
	for (int i = 1; i <= t; i++) {
		cin >> c[i];
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		for (int j = 0; j < l; j++) {
			int va, trans;
			cin >> va >> trans;
			station[y][x].push_back(make_pair(va, c[trans]));
		}
	}
	
	vector<vector<pair<int, int>>> d(MX, vector<pair<int, int>>(MX, 1e9));
	priority_queue<P> pq;
	P sale;
	sale.x = xs;
	sale.y = ys;
	d[ys][xs] = 0;
}
