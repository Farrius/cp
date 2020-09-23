#include <bits/stdc++.h>

using namespace std;

bool check_esquina(int x, int y, int x1, int y1, int x2, int y2){
	return x <= x2 && x >= x1 && y >= y1 && y <= y2;
}

int main(){
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int queda = -1;
	for(int i = 0; i < 2; i++){
		int esquinas = 0;
		int x3, y3, x4, y4;
		cin >> x3 >> y3 >> x4 >> y4;
		if(queda == 0) break;
		if(check_esquina(x1, y1, x3, y3, x4, y4)) esquinas++;
		if(check_esquina(x1, y2, x3, y3, x4, y4)) esquinas++;
		if(check_esquina(x2, y1, x3, y3, x4, y4)) esquinas++;
		if(check_esquina(x2, y2, x3, y3, x4, y4)) esquinas++;
		if(esquinas == 4){
			queda = 0;
		}else if(esquinas < 2){
			continue;
		}else{
			if(i == 1) break;
			if(check_esquina(x1, y1, x3, y3, x4, y4) && check_esquina(x1, y2, x3, y3, x4, y4)) x1 = x4;
			if(check_esquina(x1, y2, x3, y3, x4, y4) && check_esquina(x2, y2, x3, y3, x4, y4)) y2 = y3;
			if(check_esquina(x2, y2, x3, y3, x4, y4) && check_esquina(x2, y1, x3, y3, x4, y4)) x2 = x3;
			if(check_esquina(x1, y1, x3, y3, x4, y4) && check_esquina(x2, y1, x3, y3, x4, y4)) y1 = y4;
		}
	}
	if(queda == -1) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
