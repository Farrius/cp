#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, pair<string, int>>> v(n);
	for(auto &x: v){
		int num;
		string cur, sign;
		cin >> num >> cur >> sign;
		x.first = num;
		x.second.first = cur;
		if(sign[0] == '-'){
			x.second.second = -((int)sign[1] - '0');
		}else{
			x.second.second = ((int)sign[1] - '0');
		}
	}

	sort(v.begin(), v.end());
	vector<int> previa = {1, 1, 1};
	map<string, int> mp;
	int sol = 0;
	mp["Bessie"] = 7;
	mp["Mildred"] = 7;
	mp["Elsie"] = 7;
	for(auto x: v){
		mp[x.second.first] += x.second.second;
		vector<int> cur_cmp = previa;
		if(mp["Bessie"] == mp["Mildred"] && mp["Bessie"] == mp["Elsie"]){
			cur_cmp = {1, 1, 1};
		}else if(mp["Bessie"] > mp["Mildred"] && mp["Bessie"] > mp["Elsie"]){
			cur_cmp = {1, 0, 0};
		}else if(mp["Mildred"] > mp["Bessie"] && mp["Mildred"] > mp["Elsie"]){
			cur_cmp = {0, 1, 0};
		}else if(mp["Elsie"] > mp["Bessie"] && mp["Elsie"] > mp["Mildred"]){
			cur_cmp = {0, 0, 1};
		}else if(mp["Bessie"] > mp["Elsie"] && mp["Mildred"] > mp["Elsie"]){
			cur_cmp = {1, 1, 0};
		}else if(mp["Bessie"] > mp["Mildred"] && mp["Elsie"] > mp["Mildred"]){
			cur_cmp = {1, 0, 1};
		}else{
			cur_cmp = {0, 1, 1};
		}
		bool canvio = (cur_cmp == previa);
		if(!canvio) sol++;
		previa = cur_cmp;
	}
	cout << sol << '\n';
}
