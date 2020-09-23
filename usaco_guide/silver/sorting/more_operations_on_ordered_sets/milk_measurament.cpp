#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("measurement.in", "r", stdin);
  	freopen("measurement.out", "w", stdout);

	int n, g;
	cin >> n >> g;
	pair<int, pair<int, int>> data[n];

	for (int i = 0; i < n; i++) {
		int day, id, canvio;
		cin >> day >> id >> canvio;
		data[i] = {day, {id, canvio}};
	}

	sort(data, data + n);

	int sol = 0;
	map<int, int, greater<int>> leches;
	map<int, int> mp;
	leches[0] = n + 1;

	for (int i = 0; i < n; i++) {
		int vaca = data[i].second.first;
		int canvio = data[i].second.second;

		int lecheVaca = mp[vaca];

		bool eraGrande = lecheVaca == leches.begin() -> first;
		int pasado = leches[lecheVaca]--;

		if (pasado == 1) leches.erase(lecheVaca);

		mp[vaca] += canvio;

		int nuevo = ++leches[lecheVaca + canvio];

		bool esGrande = lecheVaca + canvio == leches.begin() -> first;
		
		if (eraGrande) {
			if (!esGrande || nuevo != 1 || pasado != 1) sol++;
		} else if (esGrande) {
			sol++;
		}
	}

	cout << sol << '\n';
}
