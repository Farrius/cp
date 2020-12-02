#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

string obj;
int n;
string mate;

char table[8][8];
int llega[8][8];
bool protect[8][8];

bool end;
int obji, objj;
vector<pair<int, int>> torres, reinas, alfiles, caballos, rey;

//ver si las coordeanadas son validas
bool ok (int i, int j) {
	return i >= 0 && i < 8 && j >= 0 && j < 8 && table[i][j] == '.';
}
//mirar si hay mate
bool f_rey (int i, int j) {
	bool safe = false;
	for (int ki = -1; ki <= 1; ki++) {
		for (int kj = -1; kj <= 1; kj++) {
			if ((ki == 0 && kj == 0)|| !ok(i + ki, j + kj)) continue;
			if (llega[i + ki][j + kj] <= 1) safe = true;
		}
	}
	return !safe;
}
//funcion para marcar las casillas que el rey blanco no puede ir;
void no_tocar (int i, int j) {
	for (int ki = -1; ki <= 1; ki++) {
		for (int kj = -1; kj <= 1; kj++) {
			if ((ki == 0 && kj == 0) || !ok(i + ki, j + kj)) continue;
			protect[i + ki][j + kj] = true;
		}
	}
}
//hacer update de la solucion
void upd_sol (string res) {
	if (res != "NO") {
		if (mate == "NO") {
			mate = res;
		} else{
			mate = ">1";
			end = true;
		}
	}
}
//crear tabla con las amenazas en cada posi y ver si hay mate
bool gg () {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			llega[i][j] = 0;
		}
	}
	int y, x;
	//amenaza por rey
	for (auto rei : rey) {
		tie(y, x) = rei;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;
				if (ok(i + y, j + x)) {
					llega[i + y][j + x]++;
				}
			}
		}
	}
	//amenaza por torres
	for (auto torre : torres) {
		tie(y, x) = torre;
		for (int i = -8; i < 8; i++) {
			if (i == 0) continue;
			if (ok(y + i), x) llega[y + i][x]++;
			if (ok(x + i, y)) llega[y][x + i]++;
		}
	}
	//amenaza por reina
	for (auto reinas : reinas) {
		tie(y, x) = reina;
		for (int i = -8; i < 8; i++) {
			for (int j = -8; j < 8; j++) {
				if (i == 0 && j == 0) continue;
				if (i == 0 || j == 0 || abs(i) == abs(j)) {
					if (ok(i + y, j + x)) {
						llega[i + y][j + x]++;
					}
				}
			}
		}
	}
	//amenaza por alfil
	for (auto alfil : alfiles) {
		tie(y, x) = alfil;
		for (int i = -8; i < 8; i++) {
			for (int j = -8; j < 8; j++) {
				if (i == 0 && j == 0) continue;
				if (abs(i) != abs(j)) continue;
				if (ok(i + y, j + x)) {
					llega[i + y][j + x]++;
				}
			}
		}
	}
	//amenaza por caballo
	for (auto caballo : caballos) {
		tie(y, x) caballo;
		for (int i = -2; i <= 2; i++) {
			if (i == 0) continue;
			if (abs(i) == 2) {
				if (ok(y + i, x + 1)) llega[i + y][x + 1]++;
				if (ok(y + i, x - 1)) llega[i + y][x - 1]++;
			} else {
				if (ok(y + 1, i)) llega[y + 1][i]++;
				if (ok(y - 1, i)) llega[y - 1][i]++;
			}
		}
	}
	return f_rey(obji, objj);
}
//tansforma las coordenadas en idioma del chess
string to_move (string cur, int i, int j) {
	i++;
	string number = to_string(i);
	cur += number;
	cur += number;
	char col = 'a';
	col = (char) (col + j);
	cur[2] = col;
	return cur;
}
//simular el movimiento de todas las piezas
void mover_piezas () {
	int y, x;
	//mover rey
	for (auto &rei : rey) {
		tie(y, x) = rei;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;
				if (ok(i + y, j + x) && !protect[i + y][j + x]) {
					rei.first = i + y;
					rei.second = j + x;
					if (gg()) {
						upd_sol(to_move("R", rei.first, rei.second));
					}
					rei.first = y;
					rei.second = x;
				}
			}
		}
	}
	//amenaza por torres
	for (auto torre : torres) {
		tie(y, x) = torre;
		for (int i = -8; i < 8; i++) {
			if (i == 0) continue;
			if (ok(y + i), x) llega[y + i][x]++;
			if (ok(x + i, y)) llega[y][x + i]++;
		}
	}
	//amenaza por reina
	for (auto reinas : reinas) {
		tie(y, x) = reina;
		for (int i = -8; i < 8; i++) {
			for (int j = -8; j < 8; j++) {
				if (i == 0 && j == 0) continue;
				if (i == 0 || j == 0 || abs(i) == abs(j)) {
					if (ok(i + y, j + x)) {
						llega[i + y][j + x]++;
					}
				}
			}
		}
	}
	//amenaza por alfil
	for (auto alfil : alfiles) {
		tie(y, x) = alfil;
		for (int i = -8; i < 8; i++) {
			for (int j = -8; j < 8; j++) {
				if (i == 0 && j == 0) continue;
				if (abs(i) != abs(j)) continue;
				if (ok(i + y, j + x)) {
					llega[i + y][j + x]++;
				}
			}
		}
	}
	//amenaza por caballo
	for (auto caballo : caballos) {
		tie(y, x) caballo;
		for (int i = -2; i <= 2; i++) {
			if (i == 0) continue;
			if (abs(i) == 2) {
				if (ok(y + i, x + 1)) llega[i + y][x + 1]++;
				if (ok(y + i, x - 1)) llega[i + y][x - 1]++;
			} else {
				if (ok(y + 1, i)) llega[y + 1][i]++;
				if (ok(y - 1, i)) llega[y - 1][i]++;
			}
		}
	}
}

void init () {
	//reiniciar las var
	end = false;
	mate = "NO";
	//reiniciamos las piezas y tablero
	torres.clear();
	reinas.clear();
	alfiles.clear();
	caballos.clear();
	rey.clear();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			table[i][j] = '.';
			llega[i][j] = 0;
			protect[i][j] = false;
		}
	}
	//poner coordenadas del rei negro
	objj = (obj[1] - 'a');
	obji = (obj[2] - '1');
	//tabla con las casillas que no puede ir el rei blanco
	no_tocar();
}

int main () {
	while (cin >> obj) {
		//reiniciar las arrays
		init();
		//coger el input
		cin >> n;
		for (int i = 0; i < n; i++) {
			string pieza;
			cin >> pieza;
			int col = (pieza[1] - 'a');
			int row = (pieza[2] - '1');
			if (pieza[0] == 'R') {
				rey.emplace_back(row, col);
			} else if (pieza[0] == 'T') {
				torres.emplace_back(row, col);
			} else if (pieza[0] == 'D') {
				reinas.emplace_back(row, col);
			} else if (pieza[0] == 'A') {
				alfiles.emplace_back(row, col);
			} else if (pieza[0] == 'C') {
				caballos.emplace_back(row, col);
			}
		}
		//probar mover todas las piezas
		mover_piezas();
		//cout de la solucion
		cout << mate << '\n';
	}
}
