#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> k >> n;
	int op[k], visto[n];
	for (int i = 0; i < k; i++) {
		cin >> op[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> visto[i];
	}

	set<int> sol;

	int cur = visto[0];

	set<int> soluciones;
	for (int j = 0; j < k; j++) {
		int con = -op[j];
		cur += con;
		soluciones.insert(cur);
	}
			
	for (auto x: soluciones) {
		bool ok = true;
		int base = x;
		set<int> tiene;
		for (int j = 0; j < k; j++) {
			base += op[j];
			tiene.insert(base);
		}

		for (auto y: visto) {
			if (!tiene.count(y)) ok = false;
		}

		if (ok) sol.insert(x);
	}


	cout << (int) sol.size() << '\n';
}
