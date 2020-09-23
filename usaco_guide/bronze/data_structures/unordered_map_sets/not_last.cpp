#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
	int n;
	cin >> n;
	map<string, int> mp;
	for(int i = 0; i < n; i++){
		string cur;
		int x;
		cin >> cur >> x;
		mp[cur] += x;
	}
	map<int, string> ref;
	vector<int> litros;
	for(auto x: mp){
		ref[x.second] = x.first;
		litros.push_back(x.second);
	}
	int nlitro = (int)litros.size();
	sort(litros.begin(), litros.end());
	int buscar = (nlitro == 7 ? litros[0] : 0);
	auto it = upper_bound(litros.begin(), litros.end(), buscar);
	if(it == litros.end()){
		cout << "Tie" << '\n';
	}else{
		auto con = it;
		con++;
		if(con == litros.end()){
			cout << ref[*it] << '\n';
		}else{
			if(ref[*it] == ref[*con]){
				cout << "Tie" << '\n';
			}else{
				cout << ref[*it] << '\n';
			}
		}
	}
}
