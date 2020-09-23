#include <bits/stdc++.h>

using namespace std;

bool contaminadas[101];
int n, t, cowx[251], cowy[251];

bool ok (int zero, int k) {
	int manos_k[101] = {0};
	bool infectados[101] = {false};
	
	infectados[zero] = true;
	for (int i = 0; i <= 251; i++) {
		int x = cowx[i], y = cowy[i];
		if (x <= 0) continue;
		if (infectados[x]) manos_k[x]++;
		if (infectados[y]) manos_k[y]++;
		if (infectados[x] && manos_k[x] <= k) infectados[y] = true;
		if (infectados[y] && manos_k[y] <= k) infectados[x] = true;
	}

	for (int i = 1; i <= n; i++) {
		if(contaminadas[i] != infectados[i]) return false;
	}

	return true;

}
int main() {
	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);

	cin >> n >> t;
	string s;
	cin >> s;
		
	for (int i = 1; i <= n; i++) contaminadas[i] = s[i - 1] == '1';
	for (int i = 0; i < t; i++) {
		int q, x, y;
		cin >> q >> x >> y;
		cowx[q] = x;
		cowy[q] = y;
	}

	int x = 0, maxi = -1, mini = 251;
	for (int zero = 1; zero <= n; zero++) {
		bool hecho = true;
		for (int k = 0; k <= 251; k++) {
			if (ok(zero, k)) {
				if (hecho) {
					x++;
					hecho = false;
				}
				maxi = max(maxi, k);
				mini = min(mini, k);
			}
		}
	}
	
	cout << x << ' ' << mini << ' ';
	if (maxi == 251) cout << "Infinity" << '\n';
	else cout << maxi << '\n';
}
