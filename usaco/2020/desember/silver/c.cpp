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
	//le hace parar
	vector<int> para(n);
	for (int i = 0; i < n; i++) {
		para[i] = i;
	}
	//maximo que llega
	point c;
	c.x = INF; c.y = INF;
	vector<point> mx_llega(n, c);
	//array con id i point
	vector<pair<int, point>> norte, este;
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
	//mirar por orden de este para ver quien para a quien
	for (auto cur : este) {
		int id_cur;
		point p;
		tie(id_cur, p) = cur;
		for (auto block : norte) {
			int id_block;
			point p_block;
			tie(id_block, p_block) = block;
			//si esta antes o mas arriba o no llega pasamos
			if (p_block.x < p.x || p_block.y > p.y || mx_llega[id_block].y < p.y) continue;
			int tarda = p.y - p_block.y;
			int llegamos = p_block.x - p.x;
			//miramos quien ha parado a quien
			if (tarda < llegamos) {
				para[id_cur] = id_block;
				break;
			} else if (tarda != llegamos) {
				mx_llega[id_block].y = p.y;
				para[id_block] = id_cur;
			}
		}
	}
	//mirar los parents para hace la sol
	vector<int> sol(n);
	for (int i = 0; i < n; i++) {
		int j = i;
		while (para[j] != j) {
			j = para[j];
			sol[j]++;
		}
	}
	//hacer cout de la sol
	for (int i = 0; i < n; i++) {
		cout << sol[i] << '\n';
	}
}
