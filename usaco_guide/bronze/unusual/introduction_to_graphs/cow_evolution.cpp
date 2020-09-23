#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> mutaciones[25];
vector<string> todas_mutaciones;


bool cruzan(int a, int b) {
	int as = 0, bs = 0, abs = 0;
	for (int i = 0; i < n; i++) {
		bool estaA = false, estaB = false;
		for (int j = 0; j < (int) mutaciones[i].size(); j++) {
			if(todas_mutaciones[a] == mutaciones[i][j]) estaA = true;
			if(todas_mutaciones[b] == mutaciones[i][j]) estaB = true;
		}

		if(estaA && estaB) abs++;
		else if (estaA) as++;
		else if (estaB) bs++;
	}

	return as > 0 && bs > 0 && abs > 0;
}

int main() {
	freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			string cur;
			cin >> cur;
			mutaciones[i].push_back(cur);
			bool esta = false;
			for (int p = 0; p < (int) todas_mutaciones.size(); p++) {
				if(todas_mutaciones[p] == cur) esta = true;
			}
			if (!esta) todas_mutaciones.push_back(cur);
		}
	}

	bool si = true;
	int m = (int) todas_mutaciones.size();
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < m; b++) {
			if(cruzan(a, b)) si = false;
		}
	}

	cout << (si ? "yes" : "no") << '\n';
}
