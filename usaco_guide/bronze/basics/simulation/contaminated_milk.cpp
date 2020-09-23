#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);

	int n, m, d, s;
	cin >> n >> m >> d >> s;
	vector<vector<vector<int>>> por_persona(50, vector<vector<int>>(100, vector<int>(50, -1)));
	vector<set<int>> leches(50);
	for (int i = 0; i < d; i++) {
		int p, m, t;
		cin >> p >> m >> t;
		m--;
		t--;
		p--;
		por_persona[p][t].push_back(m);
		leches[m].insert(p);
	}
	
	set<int> la_leche = {-1};
	for (int i = 0; i < s; i++) {
		set<int> new_leche = {-1};
		int p, t;
		cin >> p >> t;
		p--; t--;

		for (int j = 0; j < t; j++) {
			if (i == 0) {
				for (int k = 0; k < (int) por_persona[p][j].size(); k++) {
					new_leche.insert(por_persona[p][j][k]);
				}
			} else {
				for (int k = 0; k < (int) por_persona[p][j].size(); k++) {
					if (la_leche.count(por_persona[p][j][k])) {
						new_leche.insert(por_persona[p][j][k]);
					}
				}
			}
		}
		la_leche = new_leche;
	}
	
	la_leche.erase(-1);
		
	int sol = 0;
	
	for (auto x: la_leche) {
		sol = max(sol, (int) leches[x].size());
	}
	
	cout << sol << '\n';
}
