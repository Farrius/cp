#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

//estructura point
struct point {
	int y;
	int x;
};
//ordenar por x 
bool comp_x (const point& a, const point& b) {
	return a.x < b.x;
}
//ordenar por y
bool comp_y (const point& a, const point& b) {
	return a.y < b.y;
}

int main () {
	//coger input
	int n;
	cin >> n;
	vector<point> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i].x >> ar[i].y;
	}
	//power del 2
	ll sol = n + 1;
	for (int grupo = 2; grupo <= n; grupo++) {
		for (int iz = 0; iz < n; iz++) {
			for (int dr = 0; dr < n; dr++) {
				int cur_grup = 0;
				//miramos los bordes
				int mn_x = INF, mn_y = INF, mx_x = -1, mx_y = -1;
				//esquina iz
				mn_x = min(mn_x, ar[iz].x);
				mn_y = min(mn_y, ar[iz].y);
				mx_x = max(mx_x, ar[iz].x);
				mx_y = max(mx_y, ar[iz].y);
				//esquina dr
				mn_x = min(mn_x, ar[dr].x);
				mn_y = min(mn_y, ar[dr].y);
	mx_x = max(mx_x, ar[dr].x);
			mx_y = max(mx_y, ar[dr].y);
				//si esta en el rec pero no en el sub f
				for (int j = 0; j < n; j++) {
					if (ar[j].x <= mx_x && ar[j].x >= mn_x && ar[j].y <= mx_y && ar[j].x >= mn_y) cur_grup++;
				}
				if (cur_grup == grupo) sol++;
			}
		}
	}
	cout << sol << '\n';
}


