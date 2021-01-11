#include <bits/stdc++.h>

using namespace std;

string ma[3];
bool ok = true;

void fila (int i, char c, bool& state) {
	bool cur = ma[i][0] == c && ma[i][0] == ma[i][1] && ma[i][0] == ma[i][2];
	if (cur && state) ok = false;
	else if (!state) state = cur;
}

void col (int j, char c, bool& state) {
	bool cur = ma[0][j] == c && ma[0][j] == ma[1][j] && ma[0][j] == ma[2][j];
	if (cur && state) ok = false;
	else if (!state) state = cur;
}

void digs (char c, bool& state) {
	int res = 0;
	if (ma[0][0] == c && ma[0][0] == ma[1][1] && ma[0][0] == ma[2][2]) res++;
	if (ma[0][2] == c && ma[0][2] == ma[1][1] && ma[0][2] == ma[2][0]) res++;
	if (res > 1) ok = false;
	if (res == 1) state = true;
}

int main () {
	for (int i = 0; i < 3; i++) {
		cin >> ma[i];
	}
	bool fil_b = false, col_b = false, dig_b = false, fil_n = false, col_n = false, dig_n = false;
	for (int i = 0; i < 3; i++) {
		fila(i, 'B', fil_b);
		fila(i, 'N', fil_n);
	}
	for (int j = 0; j < 3; j++) {
		col(j, 'B', col_b);
		col(j, 'N', col_n);
	}
	digs('B', dig_b);
	digs('N', dig_n);
	int b = 0, n = 0;
	if (fil_b) b++;
	if (col_b) b++;
	if (dig_b) b++;
	if (fil_n) n++;
	if (col_n) n++;
	if (dig_n) n++;
	if (b > 2 || n > 2 || (b >= 1 && n >= 1)) ok = false;
	if (!ok) {
		cout << "imposible" << '\n';
	} else {
		int bes = 0, enes = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (ma[i][j] == '.') continue;
				else if (ma[i][j] == 'B') bes++;
				else enes++;
			}
		}
		if (abs(bes - enes) > 1 || enes > bes) cout << "imposible" << '\n';
		else if ((fil_n || col_n || dig_n) && bes > enes) cout << "imposible" << '\n';
		else if ((fil_b || col_b || dig_b) && bes == enes) cout << "imposible" << '\n';
		else cout << "posible" << '\n';
	}

}
