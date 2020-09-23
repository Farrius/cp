#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	long double a, b, h, m;
	cin >> a >> b >> h >> m;
	long double deg_m = m * 6;
	long double deg_h = h * 30 + m/2;
	long double deg = min(360 - abs(deg_m - deg_h),abs(deg_m - deg_h));
	deg = deg/180 * M_PI;
	long double rsq= a * a + b * b - 2 * a * b * cos(deg);
	cout<<fixed<<setprecision(9)<<sqrt(rsq)<<endl;
}
