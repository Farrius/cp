#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second

#define len(x) (int)x.size()

const int INF = 1e9;

int ma[2002][2002];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	for(int i = 0; i < 2002; i++){
		for(int j = 0; j < 2002; j++){
			ma[i][j] = INF;
		}
	}

	int sol = INF;
	bool esta = false;
	int t = 0;
	int y = 1000, x = 1000;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		char direc;
		int move;
		cin >> direc >> move;
		if(direc == 'N'){
			for(int sum = 1; sum <= move; sum++){
				t++;
				y--;
				if(ma[y][x] != INF){
					esta = true;
					sol = min(sol, t - ma[y][x]);
				}
				ma[y][x] = t;
			}
		}else if(direc == 'E'){
			for(int sum = 1; sum <= move; sum++){
				t++;
				x++;
				if(ma[y][x] != INF){
					esta = true;
					sol = min(sol, t - ma[y][x]);
				}
				ma[y][x] = t;
			}
		}else if(direc == 'W'){
			for(int sum = 1; sum <= move; sum++){
				t++;
				x--;
				if(ma[y][x] != INF){
					esta = true;
					sol = min(sol, t - ma[y][x]);
				}
				ma[y][x] = t;
			}
		}else{
			for(int sum = 1; sum <= move; sum++){
				t++;
				y++;
				if(ma[y][x] != INF){
					esta = true;
					sol = min(sol, t - ma[y][x]);

				}
				ma[y][x] = t;
			}

	}
	}
	if(!esta) cout << -1 << '\n';
	else cout << sol << '\n';
}
