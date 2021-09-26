#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll pw (int n) {
	return n * 1LL * n;
}

ll q (int x, int y, int z) {
	return pw(x - y) + pw(x - z) + pw(y - z);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vector<int> ar(n1), br(n2), cr(n3);
		for (int i = 0; i < n1; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n2; i++) {
			cin >> br[i];
		}
		for (int i = 0; i < n3; i++) {
			cin >> cr[i];
		}

		sort(ar.begin(), ar.end());
		sort(br.begin(), br.end());
		sort(cr.begin(), cr.end());

		ll sol = 5e18;
		for (auto x : ar) {
			int in = lower_bound(br.begin(), br.end(), x) - br.begin();
			int in1 = lower_bound(cr.begin(), cr.end(), br[in]) - cr.begin();
			if (in == n2) in--;
			if (in1 == n3) in1--;
			sol = min(sol, q(x, br[in], cr[in1]));
			if (in1 > 0) sol = min(sol, q(x, br[in], cr[in1 - 1]));
			in1 = lower_bound(cr.begin(), cr.end(), x) - cr.begin();
			if (in == n2) in--;
			if (in1 == n3) in1--;
			sol = min(sol, q(x, br[in], cr[in1]));
			if (in1 > 0) sol = min(sol, q(x, br[in], cr[in1 - 1]));
			if (in > 0) {
				in1 = lower_bound(cr.begin(), cr.end(), br[in - 1]) - cr.begin();
				if (in == n2) in--;
				if (in1 == n3) in1--;
				sol = min(sol, q(x, br[in - 1], cr[in1]));
				if (in1 > 0) sol = min(sol, q(x, br[in - 1], cr[in1 - 1]));
				in1 = lower_bound(cr.begin(), cr.end(), x) - cr.begin();
				if (in == n2) in--;
				if (in1 == n3) in1--;
				sol = min(sol, q(x, br[in - 1], cr[in1]));
				if (in1 > 0) sol = min(sol, q(x, br[in - 1], cr[in1 - 1]));
			}
		}
		for (auto x : br) {
			int in = lower_bound(ar.begin(), ar.end(), x) - ar.begin();
			int in1 = lower_bound(cr.begin(), cr.end(), ar[in]) - cr.begin();
			if (in == n1) in--;
			if (in1 == n3) in1--;
			sol = min(sol, q(x, ar[in], cr[in1]));
			if (in1 > 0) sol = min(sol, q(x, ar[in], cr[in1 - 1]));
			in1 = lower_bound(cr.begin(), cr.end(), x) - cr.begin();
			if (in == n1) in--;
			if (in1 == n3) in1--;
			sol = min(sol, q(x, ar[in], cr[in1]));
			if (in1 > 0) sol = min(sol, q(x, ar[in], cr[in1 - 1]));
			if (in > 0) {
				in1 = lower_bound(cr.begin(), cr.end(), ar[in - 1]) - cr.begin();
				if (in == n1) in--;
				if (in1 == n3) in1--;
				sol = min(sol, q(x, ar[in - 1], cr[in1]));
				if (in1 > 0) sol = min(sol, q(x, ar[in - 1], cr[in1 - 1]));
				in1 = lower_bound(cr.begin(), cr.end(), x) - cr.begin();
				if (in == n1) in--;
				if (in1 == n3) in1--;
				sol = min(sol, q(x, ar[in - 1], cr[in1]));
				if (in1 > 0) sol = min(sol, q(x, ar[in - 1], cr[in1 - 1]));
			}
		}
		for (auto x : cr) {
			int in = lower_bound(br.begin(), br.end(), x) - br.begin();
			int in1 = lower_bound(ar.begin(), ar.end(), br[in]) - ar.begin();
			if (in == n2) in--;
			if (in1 == n1) in1--;
			sol = min(sol, q(x, br[in], ar[in1]));
			if (in1 > 0) sol = min(sol, q(x, br[in], ar[in1 - 1]));
			in1 = lower_bound(ar.begin(), ar.end(), x) - ar.begin();
			if (in == n2) in--;
			if (in1 == n1) in1--;
			sol = min(sol, q(x, br[in], ar[in1]));
			if (in1 > 0) sol = min(sol, q(x, br[in], ar[in1 - 1]));
			if (in > 0) {
				in1 = lower_bound(ar.begin(), ar.end(), br[in - 1]) - ar.begin();
				if (in == n2) in--;
				if (in1 == n1) in1--;
				sol = min(sol, q(x, br[in - 1], ar[in1]));
				if (in1 > 0) sol = min(sol, q(x, br[in - 1], ar[in1 - 1]));
				in1 = lower_bound(ar.begin(), ar.end(), x) - ar.begin();
				if (in == n2) in--;
				if (in1 == n1) in1--;
				sol = min(sol, q(x, br[in - 1], ar[in1]));
				if (in1 > 0) sol = min(sol, q(x, br[in - 1], ar[in1 - 1]));
			}
		}
		cout << sol << '\n';
	}
}
