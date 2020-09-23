#include <bits/stdc++.h>

using namespace std;

bool checkear_esquina(int x, int y, int x1, int y1, int x2, int y2){
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int esquinas = 0;
	if(checkear_esquina(x1, y1, x3, y3, x4, y4)) esquinas++;
	if(checkear_esquina(x1, y2, x3, y3, x4, y4)) esquinas++;
	if(checkear_esquina(x2, y1, x3, y3, x4, y4)) esquinas++;
	if(checkear_esquina(x2, y2, x3, y3, x4, y4)) esquinas++;
	
	if(esquinas == 4){
		cout << 0 << '\n';
	}else if(esquinas < 2){
		cout << (x2 - x1) * (y2 - y1) << '\n';
	}else{
		cout << (x2 - x1) * (y2 - y1) - (max(0, min(x2, x4) - max(x1, x3))) * (max(0, min(y2, y4) - max(y1, y3)));
	}
}
