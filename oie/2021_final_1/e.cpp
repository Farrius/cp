#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<pair<ll, ll>> ar;
	int a[n], b[n];
	map<int, int> id;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		id[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		ar.push_back(make_pair(a[i], b[i]));
	}
	sort(ar.begin(), ar.end());
	vector<ll> pref(n + 1), suff(n + 1), mul_pref(n + 1), mul_suff(n + 1);
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + ar[i - 1].second;
		mul_pref[i] = mul_pref[i - 1] + ar[i - 1].first * ar[i - 1].second;
	}
	for (int i = n - 1; i >= 0; i--) {
		suff[i] = suff[i + 1] + ar[i].second;
		mul_suff[i] = mul_suff[i + 1] + ar[i].first * ar[i].second;
	}

	ll mn = 1e18;
	int sol = 1e9;
	for (int i = 0; i < n; i++) {
		ll pos, p;
		tie(pos, p) = ar[i];
		//delante
		ll delante = mul_suff[i + 1] - suff[i + 1] * pos;
		//detras 
		ll detras = pref[i] * pos - mul_pref[i];
		ll cur = delante + detras;
		if (cur <= mn) {
			if (cur < mn) {
				mn = cur;
				sol = id[pos];
			} else {
				sol = min(sol, id[pos]);
			}
		}
	}
	cout << sol << '\n';
}
