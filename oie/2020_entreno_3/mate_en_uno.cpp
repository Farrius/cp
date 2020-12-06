#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

string obj;
int n;
string mate;

int llega[8][8];
bool protect[8][8];
char table[8][8];

int obji, objj;
vector<pair<int, int>> torres, reinas, alfiles, caballos, rey;

//ver si las coordeanadas son validas para mover
bool ok (int i, int j) {
	return i >= 0 && i < 8 && j >= 0 && j < 8 && table[i][j] == '.';
}
//ver si las coordenadas son validas
bool ok2 (int i, int j) {
	return i >= 0 && i < 8 && j >= 0 && j < 8;
}
//mirar si hay mate
bool f_rey (int i, int j) {
	bool safe = false;
	for (int ki = -1; ki <= 1; ki++) {
		for (int kj = -1; kj <= 1; kj++) {
			if (!ok2(i + ki, j + kj)) continue;
			if (llega[i + ki][j + kj] == 0) safe = true;
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
		} else {
			mate = ">1";
		}
	}
}
//update de llega con movimiento vertical i horizontal
void vertical_upd (int y, int x) {
	for (int i = -1; i > -8; i--) {
		if (!ok2(y + i, x)) break;
		llega[y + i][x]++;
		if (table[y + i][x] != '.') break;
	}
	for (int i = 1; i < 8; i++) {
		if (!ok2(y + i, x)) break;
		llega[y + i][x]++;
		if (table[y + i][x] != '.') break;
	}
	for (int j = -1; j > -8; j--) {
		if(!ok2(y, x + j)) break;
		llega[y][x + j]++;
		if (table[y][x + j] != '.') break;
	}
	for (int j = 1; j < 8; j++) {
		if(!ok2(y, x + j)) break;
		llega[y][x + j]++;
		if (table[y][x + j] != '.') break;
	}
}
//update de llega con movimiento diagonal
void dig_upd (int y, int x) {
	for (int i = 1, j = 1; i < 8; i++, j++) {
		if (!ok2(y + i, x + j)) break;
		llega[y + i][x + j]++;
		if (table[y + i][x + j] != '.') break;
	}
	for (int i = 1, j = -1; i < 8; i++, j--) {
		if (!ok2(y + i, x + j)) break;
		llega[y + i][x + j]++;
		if (table[y + i][x + j] != '.') break;
	}
	for (int i = -1, j = 1; i > -8; i--, j++) {
		if(!ok2(y + i, x + j)) break;
		llega[y + i][x + j]++;
		if (table[y + i][x + j] != '.') break;
	}
	for (int i = -1, j = -1; i > -8; i--, j--) {
		if(!ok2(y + i, x + j)) break;
		llega[y + i][x + j]++;
		if (table[y + i][x + j] != '.') break;
	}
}
//update del move del caballo
void caballo_upd (int y, int x) {
	for (int k = -2; k <= 2; k++) {
		if (k == 0) continue;
		if (abs(k) == 2) {
			if (ok2(y + k, x + 1)) llega[y + k][x + 1]++;
			if (ok2(y + k, x - 1)) llega[y + k][x - 1]++;
		} else {
			if (ok2(y + k, x + 2)) llega[y + k][x + 2]++;
			if (ok2(y + k, x - 2)) llega[y + k][x - 2]++;
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
				if (ok2(i + y, j + x)) {
					llega[i + y][j + x]++;
				}
			}
		}
	}
	//amenaza por torres
	for (auto torre : torres) {
		tie(y, x) = torre;
		vertical_upd(y, x);
	}
	//amenaza por reinas
	for (auto reina : reinas) {
		tie(y, x) = reina;
		dig_upd(y, x);
		vertical_upd(y, x);
	}
	//amenaza por alfiles
	for (auto alfil : alfiles) {
		tie(y, x) = alfil;
		dig_upd(y, x);
	}
	for (auto caballo : caballos) {
		tie(y, x) = caballo;
		caballo_upd(y, x);
	}
	return f_rey(obji, objj);
}
//tansforma las coordenadas en idioma del chess
string to_move (string cur, int i, int j) {
	i = 8 - i;
	string number = to_string(i);
	cur += number;
	cur += number;
	char col = 'a';
	col = (char) (col + j);
	cur[1] = col;
	return cur;
}
//checkear la sol
void check (string piece, int i, int j) {
	table[i][j] = piece[0];
	if (gg()) upd_sol(to_move(piece, i, j));
	table[i][j] = '.';
}
//movimiento vertical
void vertical_move (string piece, int y, int x, int ind, vector<pair<int, int>>& ar) {
	for (int i = -1; i > -8; i--) {
		if (!ok(y + i, x)) break;
		ar[ind].first = y + i;
		check(piece, y + i, x);
	}
	for (int i = 1; i < 8; i++) {
		if (!ok(y + i, x)) break;
		ar[ind].first = y + i;
		check(piece, y + i, x);
	}
	ar[ind].first = y;
	for (int j = -1; j > -8; j--) {
		if(!ok(y, x + j)) break;
		ar[ind].second = x + j;
		check(piece, y, x + j);
	}
	for (int j = 1; j < 8; j++) {
		if(!ok(y, x + j)) break;
		ar[ind].second = x + j;
		check(piece, y, x + j);
	}
	ar[ind].second = x;
}
//movimiento diagonal
void dig_move (string piece, int y, int x, int ind, vector<pair<int, int>>& ar) {
	for (int i = -1, j = -1; i > -8; i--, j--) {
		if (!ok(y + i, x + j)) break;
		ar[ind].first = y + i;
		ar[ind].second = x + j;
		check(piece, y + i, x + j);
	}
	for (int i = 1, j = 1; i < 8; i++, j++) {
		if (!ok(y + i, x + j)) break;
		ar[ind].first = y + i;
		ar[ind].second = x + j;
		check(piece, y + i, x + j);
	}
	for (int j = -1, i = 1; j > -8; j--, i++) {
		if(!ok(y + i, x + j)) break;
		ar[ind].first = y + i;
		ar[ind].second = x + j;
		check(piece, y + i, x + j);
	}
	for (int j = 1, i = -1; j < 8; j++, i--) {
		if(!ok(y + i, x + j)) break;
		ar[ind].first = y + i;
		ar[ind].second = x + j;
		check(piece, y + i, x + j);
	}
	ar[ind].first = y;
	ar[ind].second = x;
}
//colocar caballo
void colocar_caballo (int ind, int i, int j, vector<pair<int, int>>& ar) {
	ar[ind].first = i;
	ar[ind].second = j;
	check("C", i, j);
}
//movimiento del caballo
void caballos_move (int y, int x, int ind, vector<pair<int, int>>& ar) {
	for (int k = -2; k <= 2; k++) {
		if (k == 0) continue;
		if (abs(k) == 2) {
			if (ok(y + k, x + 1)) colocar_caballo(ind, y + k, x + 1, ar);
			if (ok(y + k, x - 1)) colocar_caballo(ind, y + k, x - 1, ar);
		} else {
			if (ok(y + k, x + 2)) colocar_caballo(ind, y + k, x + 2, ar);
			if (ok(y + k, x - 2)) colocar_caballo(ind, y + k, x - 2, ar);
		}
	}
	ar[ind].first = y;
	ar[ind].second = x;
}
//simular el movimiento de todas las piezas
void mover_piezas () {
	int y, x;
	//mover rey
	for (auto &rei : rey) {
		tie(y, x) = rei;
		table[y][x] = '.';
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;
				if (ok(i + y, j + x) && !protect[i + y][j + x]) {
					rei.first = i + y;
					rei.second = j + x;
					table[i + y][j + x] = 'R';
					check("R", i + y, j + x);
					table[i + y][j + x] = '.';
					rei.first = y;
					rei.second = x;
				}
			}
		}
		table[y][x] = 'R';
	}
	//mover torres
	for (int i = 0; i < (int) torres.size(); i++) {
		tie(y, x) = torres[i];
		table[y][x] = '.';
		vertical_move("T", y, x, i, torres);
		table[y][x] = 'T';
	}
	//mover reinas
	for (int i = 0; i < (int) reinas.size(); i++) {
		tie(y, x) = reinas[i];
		table[y][x] = '.';
		dig_move("D", y, x, i, reinas);
		vertical_move("D", y, x, i, reinas);
		table[y][x] = 'D';
	}
	//mover alfiles
	for (int i = 0; i < (int) alfiles.size(); i++) {
		tie(y, x) = alfiles[i];
		table[y][x] = '.';
		dig_move("A", y, x, i, alfiles);
		table[y][x] = 'A';
	}
	//mover caballos
	for (int i = 0; i < (int) caballos.size(); i++) {
		tie(y, x) = caballos[i];
		table[y][x] = '.';
		caballos_move(y, x, i, caballos);
		table[y][x] = 'C';
	}
}

void init () {
	//reiniciar las var
	mate = "NO";
	//reiniciamos las piezas y tablero
	torres.clear();
	reinas.clear();
	alfiles.clear();
	caballos.clear();
	rey.clear();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			llega[i][j] = 0;
			protect[i][j] = false;
			table[i][j] = '.';
		}
	}
	//poner coordenadas del rei negro
	objj = (obj[1] - 'a');
	obji = (obj[2] - '1');
	obji = 7 - obji;
	//tabla con las casillas que no puede ir el rei blanco
	no_tocar(obji, objj);
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
			row = 7 - row;
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
			table[row][col] = pieza[0];
		}
		//probar mover todas las piezas
		mover_piezas();
		//cout de la solucion
		cout << mate << '\n';
	}
}
