#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	vector<ld> ar;
	int n;
	ld w;
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		ld a, b;
		cin >> a >> b;
		ar.push_back(a/b);
	}
	sort(ar.begin(), ar.end(), greater<ld>());
	cout << fixed << setprecision(8) << ar[0] * w << '\n';
}
