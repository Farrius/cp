#include <bits/stdc++.h>

using namespace std;

string vacas[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

vector<string> perm;

int used[8];
bool ok = false;
vector<vector<string>> lados(8);
map<string, int> mp;

void search(int i){
	if(ok) return;
	if(i == 8){
		bool nopuede = false;
		for(int j = 0; j < 8; j++){
			auto curAr = lados[mp[perm[j]]];
			for(int k = 0; k < (int) curAr.size(); k++){
				if((j != 0 && curAr[k] == perm[j - 1]) || (j != 7 && curAr[k] == perm[j + 1])) continue;
				nopuede = true;
			}
		}
		if(nopuede) return;
		for(int j = 0; j < 8; j++){
			cout << perm[j] << '\n';
		}
		ok = true;
		return;
	}
	for(int j = 0; j < 8; j++){
		if(used[j]) continue;
		used[j] = 1;
		perm.push_back(vacas[j]);
		search(i + 1);
		used[j] = 0;
		perm.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	for(int i = 0; i < 8; i++){
		mp[vacas[i]] = i;
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		string u;
		for(int i = 0; i < 5; i++){
			cin >> u;
		}
		lados[mp[s]].push_back(u);
	}

	search(0);
}
