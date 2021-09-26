#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	vector<ll> pd, pc;
	ll cur = 2;
	while (cur < 1e18) {
		pd.push_back(cur);
		cur *= 2;
	}
	cur = 5;
	while (cur < 1e18) {
		pc.push_back(cur);
		cur *= 5;
	}
	ll a, b;
	cin >> a >> b;
	int dos = 0;
	for (int i = 0; i < (int) pd.size(); i++) {
		ll mod = b % pd[i];
		if (pd[i] > b) break;
		if (b - mod < a) {
			break;
		} else {
			dos++;
		}
	}
	int cinc = 0;
	for (int i = 0; i < (int) pc.size(); i++) {
		ll mod = b % pc[i];
		if (pc[i] > b) break;
		if (b - mod < a) {
			break;
		} else {
			cinc++;
		}
	}
	cout << min(dos, cinc) << '\n';
}
