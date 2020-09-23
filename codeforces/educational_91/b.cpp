#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(pair<char, int> &a, pair<char, int> &b){
	return a.second > b.second;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<pair<char, int>> a;
		map<char, int> mp;
		for(char x : s){
			mp[x]++;
		}
		pair<char, int> sol = {'.', 0};
		for(auto x: mp){
			if(x.second > sol.second){
				sol = {x.first, x.second};
			}
		}
		char result;
		if(sol.first == 'P') result = 'S';
		else if(sol.first == 'S') result = 'R';
		else result = 'P';
		string res(s.size(), result);
		cout << res << '\n';
	}
}
