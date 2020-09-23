#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	int x1, x2, y1, y2;
	int x3, x4, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	int x = max(x2, x4) - min(x1, x3);
	int y = max(y4, y2) - min(y1, y3);
	int res = max(x, y);
	cout << res * res << '\n';
}
