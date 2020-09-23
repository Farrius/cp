#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int ma[2000][2000];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	for(int i = 0; i < 3; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 1000;
		y1 += 1000;
		x2 += 1000;
		y2 += 1000;
		for(int y = y1; y < y2; y++){
			for(int x = x1; x < x2; x++){
				if(i == 2) ma[y][x] = 0;
				else ma[y][x] = 1;
			}
		}
	}
	int sol = 0;
	for(int i = 0; i < 2000; i++){
		for(int j = 0; j < 2000; j++){
			sol += ma[i][j];
		}
	}

	cout << sol << '\n';
}
