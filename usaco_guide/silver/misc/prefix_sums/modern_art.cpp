#include <bits/stdc++.h>

using namespace std;

const int maxN = 1001;
const int maxC = maxN * maxN;

int topC[maxC + 1], botC[maxC + 1], leftC[maxC + 1], rightC[maxC + 1], cnt[maxC + 1];
int ma[maxN + 1][maxN + 1], ma2[maxN + 1][maxN + 1], pref[maxN + 1][maxN + 1];

int main () {
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);

	int n, vistos = 0;
	cin >> n;
	
	for (int i = 1; i <= n * n; i++) {
		topC[i] = leftC[i] = n;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ma[i][j];
		}
	}
	//coger las coordenadas
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c = ma[i][j];
			if (c == 0) continue;
			if (cnt[c] == 0) vistos++;
			cnt[c]++;
			topC[c] = min(topC[c], i + 1);
			botC[c] = i + 1;
			leftC[c] = min(leftC[c], j + 1);
			rightC[c] = max(rightC[c], j + 1);
		}
	}
	if (vistos == 1) {
		cout << (n == 1 ? 0 : n * n - 1) << '\n';
		return 0;
	}

	int sol = n * n - vistos;

	//montar los limites
	for (int c = 1; c <= n * n; c++) {
		if (cnt[c] == 0) continue;
		ma2[botC[c]][rightC[c]]++;
		ma2[botC[c]][leftC[c]-1]--;
		ma2[topC[c]-1][rightC[c]]--;
		ma2[topC[c]-1][leftC[c]-1]++;
	}

	//montar el prefix sum
	for (int i = n; i > 0; i--) {
           	for (int j = n; j > 0; j--) {
		    	pref[i][j] = pref[i + 1][j] + pref[i][j + 1] - pref[i + 1][j + 1] + ma2[i][j];
		}
	}

	//ajustar los que no pueden ir primero
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int c = ma[y - 1][x - 1];
			if (cnt[c] > 0 && pref[y][x] >= 2) cnt[c] = 0;
		}
	}

	for (int c = 1; c <= n * n; c++) {
		if (cnt[c] > 0) sol++;
	}

	cout << sol << '\n';
}

