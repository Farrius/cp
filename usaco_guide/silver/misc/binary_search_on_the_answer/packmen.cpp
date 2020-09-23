#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> comida, pack;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') pack.push_back(i);
		else if (s[i] == '*') comida.push_back(i);
	}

	int lo = 0, hi = 2e5 + 5;
	int sol = hi;
	
	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		bool ok = true;
		int j = 0;

		for (int x: pack) {
			if (j == (int) comida.size()) break;

			int coge = x;
			if (comida[j] < x) {
				if (comida[j] + mid < x) {
					ok = false;
					break;
				} else {
					coge = comida[j];
				}
			}
			
			while (j < (int) comida.size() && comida[j] <= x) j++;

			int izquierda = x - coge;
			int derecha = 0;

			while (j < (int) comida.size() && min(izquierda, comida[j] - x) * 2 + max(izquierda, comida[j] - x) <= mid) j++;
		}

		if (ok) ok = (j == (int) comida.size());

		if (ok) {
			sol = min (sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << sol << '\n';
}
