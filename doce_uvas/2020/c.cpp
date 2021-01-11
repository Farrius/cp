#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


void fn (ld hora, ld min) {
	hora += 0.001;
	min += 0.001;
	int h = hora/1, m = min/1;
	if (h < 10) cout << 0;
	cout << h;
	cout << ":";
	if (m < 10) cout << 0;
	cout << m;
	cout << '\n';
}

void calc (ld hour_ang, ld min_ang) {
	ld min = min_ang/6;
	ld hour = (hour_ang/0.5 - min)/60;
	fn(hour, min);
}


int main () {
	int t;
	cin >> t;
	while (t--) {
		ld a, b;
		cin >> a >> b;
		ld c = a/30, d = b/30;
		c -= (int) c;
		d -= (int) d;
		ld dif = 0.00000001;
		if (abs(c * 360 - b) <= 0.001) {
			calc(a, b);
		} else if (abs(d * 360 - a) <= 0.001){
			calc(b, a);
		} else {
			cout << "ERROR" << '\n';
		}
	}
}
