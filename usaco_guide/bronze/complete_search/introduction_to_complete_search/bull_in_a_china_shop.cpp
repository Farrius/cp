#include <bits/stdc++.h>

using namespace std;

int k, n;
int ma[8][8];
int mas[10][8][8];

bool esta_gucci(int y, int x, int matrix[][8]){
	return y >= 0 && y < n && x >= 0 && x < n && matrix[y][x];
}

int main(){
	freopen("bcs.in", "r", stdin);
	freopen("bcs.out", "w", stdout);

	cin >> n >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char cur;
			cin >> cur;
			ma[i][j] = (cur == '#');
		}
	}
	for(int i = 0; i < k; i++){
		for(int y = 0; y < n; y++){
			for(int x = 0; x < n; x++){
				char cur;
				cin >> cur;
				mas[i][y][x] = (cur == '#');
			}
		}
	}
	for(int i = 0; i < k; i++){
		for(int j = i + 1; j < k; j++){
			for(int iy = -n + 1; iy < n; iy++){
				for(int ix = -n + 1; ix < n; ix++){
					for(int jy = -n + 1; jy < n; jy++){
						for(int jx = -n + 1; jx < n; jx++){
							bool si = true;
							for(int y = 0; y < n && si; y++){
								for(int x = 0; x < n && si; x++){
									bool iGucci = esta_gucci(iy + y, ix + x, mas[i]);
									bool jGucci = esta_gucci(jy + y, jx + x, mas[j]);
									if(iGucci && jGucci){
										si = false;
									}
									if(ma[y][x] != (iGucci || jGucci)){
										si = false;
									}
								}
							}
							if(si){
								cout << i + 1 << ' ' << j + 1 << '\n';
								return 0;
							}
						}
					}
				}
			}
		}
	}
}
