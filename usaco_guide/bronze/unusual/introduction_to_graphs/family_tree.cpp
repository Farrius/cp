#include <bits/stdc++.h>

using namespace std;

const int MX = 1e2;
int n;

string hijos[MX], padres[MX];

string madre_de(string vaca){
	for(int i = 0; i < n; i++){
		if(hijos[i] == vaca) return padres[i];
	}
	return "no";
}

int parientes(string hijo, string madre){
	int generaciones = 0;
	while(madre != "no"){
		if(hijo == madre) return generaciones;
		madre = madre_de(madre);
		generaciones++;
	}
	return -1;
}
int main(){
	freopen("family.in", "r", stdin);
	freopen("family.out", "w", stdout);

	cin >> n;
	string bessie, elsie;
	cin >> bessie >> elsie;
	for(int i = 0; i < n; i++){
		cin >> padres[i] >> hijos[i];
	}

	int b = 0;
	string vaca = bessie;

	while(vaca != "no"){
		if(parientes(vaca, elsie) != -1) break;
		b++;
		vaca = madre_de(vaca);
	}
	if(vaca == "no"){
		cout << "NOT RELATED" << '\n';
		return 0;
	}
	int a = parientes(vaca, elsie);
	if(a == 1 && b == 1) cout << "SIBLINGS" << '\n';
	else if (a > 1 && b > 1) cout << "COUSINS" << '\n';
	else{
		if(a > b){
			swap(elsie, bessie);
			swap(a, b);
		}
		cout << elsie << " is the ";
		for(int i = 0; i < b - 2; i++) cout << "great-";
		if(b > 1 && a == 0) cout << "grand-";
		if(a == 0) cout << "mother";
		else cout << "aunt";
		cout << " of " << bessie << '\n';
	}
}
