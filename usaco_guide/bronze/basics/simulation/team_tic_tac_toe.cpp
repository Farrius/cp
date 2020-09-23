#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second

#define len(x) (int)x.size();

char ma[3][3];
int uno = 0, dos = 0;
bool undos = false, todos = false;

void cmp(char a, char b, char c, char cur, char cur_con){
	if(a != b && a != c && b != c){
		return;
	}
	if((cur != a && cur_con != a) || (cur != b && cur_con != b) || (cur != c && cur_con != c)){
		return;
	}
	if(cur == cur_con){
		todos = true;
	}else{
		if(a != b || b != c || a != c) undos = true;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	
	set<char> usar;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> ma[i][j];
			usar.insert(ma[i][j]);
		}
	}
	
	for(char cur = 'A'; cur <= 'Z'; cur++){
		for(char cur_con = cur; cur_con <= 'Z'; cur_con++){
			if(!usar.count(cur) || !usar.count(cur_con)) continue;
			undos = false, todos = false;
			for(int i = 0; i < 3; i++){
				cmp(ma[i][0], ma[i][1], ma[i][2], cur, cur_con);
				cmp(ma[0][i], ma[1][i], ma[2][i], cur, cur_con);
			}
			cmp(ma[0][0], ma[1][1], ma[2][2], cur, cur_con);
			cmp(ma[0][2], ma[1][1], ma[2][0], cur, cur_con);
			if(undos) dos++;
			if(todos) uno++;
		}
	}
	cout << uno << '\n' << dos << '\n';
}








