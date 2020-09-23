#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}
int main() {
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);

	int n, m, r;
	cin >> n >> m >> r;

	vector<int> produccion(n);

	for (int i = 0; i < n; i++) {
		cin >> produccion[i];
	}

	vector<pair<int, int>> tiendas(m);

	for (int i = 0; i < m; i++) {
		cin >> tiendas[i].second >> tiendas[i].first;
	}
	vector<int> alquilar(r);

	for (int i = 0; i < r; i++) {
		cin >> alquilar[i];
	}

	sort(alquilar.begin(), alquilar.end(), greater<int>());
	sort(tiendas.begin(), tiendas.end(), cmp);
	sort(produccion.begin(), produccion.end(), greater<int>());
	
	int iTienda = 0;
	int iAlqui = 0;
	int i = 0;
	ll sol = 0;
	while (i < n) {
		int litros = produccion[i];
		int parnerT = 0, curI = iTienda;
		int termina = 0;
		while (curI < m) {
			int resta = min(litros, tiendas[curI].second);
			parnerT += tiendas[curI].first * resta;
			litros -= resta;

			if (litros == 0) {
				termina = resta;
				break;
			} else {
				curI++;
			}
		}

		if (iAlqui >= r || parnerT > alquilar[iAlqui]) {
			sol += parnerT;
			iTienda = curI;
			if (iTienda < m) tiendas[iTienda].second -= termina;
			i++;
		} else {
			sol += alquilar[iAlqui];
			n--;
			iAlqui++;
		}
	}

	cout << sol << '\n';
}
