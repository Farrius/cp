#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

//estructura point
struct point {
	int x;
	int y;
};
//ordenar por y
bool cmp_y (const pair<int, point> a, const pair<int, point> b) {
	return a.second.y < b.second.y;
}
//ordenar por x
bool cmp_x (const pair<int, point> a, const pair<int, point> b) {
	return a.second.x < b.second.x;
}

int main () {
	//coger el input
	int n;
	cin >> n;
	char tipo[n];
	//array con id i point
	vector<pair<int, point>> norte, este;
	//el maximo donde puede llegar una vaca
	point example;
	example.x = INF; example.y = INF;
	vector<point>  mx_llega(n, example);
	for (int i = 0; i < n; i++) {
		int cur_x, cur_y;
		point cur;
		cin >> tipo[i];
		cin >> cur.x >> cur.y;
		if (tipo[i] == 'E') este.push_back(make_pair(i, cur));
		else norte.push_back(make_pair(i, cur));
	}
	//ordenar las arrays
	sort(este.begin(), este.end(), cmp_y);
	sort(norte.begin(), norte.end(), cmp_x);
	//mirar por orden de este para ver los bloqueos
	for (auto cur : este) {
		int id_cur;
		point p;
		tie(id_cur, p) = cur;
		for (auto block : norte) {
			int id_block;
			point p_block;
			tie(id_block, p_block) = block;
			//si esta antes o mas arriba pasamos
			if (p_block.x < p.x || p_block.y > p.y) continue;
			//si ya tiene un block de uno previo no podra llega
			if (mx_llega[id_block].y < p.y) continue;
			int tarda = p.y - p_block.y;
			int llegamos = p_block.x - p.x;
			//si el otro va mas rapido guardamos su max y nos vamos
			if (tarda < llegamos) {
				mx_llega[id_cur].x = p_block.x;
				break;
			} else if (tarda != llegamos) {
				mx_llega[id_block].y = p.y;
			}
		}
	}
	//crear la array con la sol
	vector<int> sol(n);
	for (auto cur : este) {
		int id = cur.first;
		if (mx_llega[id].x == INF) sol[id] = INF;
		else sol[id] = mx_llega[id].x - cur.second.x;
	}
	for (auto cur : norte) {
		int id = cur.first;
		if (mx_llega[id].y == INF) sol[id] = INF;
		else sol[id] = mx_llega[id].y - cur.second.y;
	}
	//cout de la sol
	for (int i = 0; i < n; i++) {
		if (tipo[i] == 'E') {
			if (sol[i] == INF) cout << "Infinity" << '\n';
			else cout << sol[i] << '\n';
		} else {
			if (sol[i] == INF) cout << "Infinity" << '\n';
			else cout << sol[i] << '\n';;
		}
	}
}
