#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	while(n--){
		int b, sg, sb;
		cin >> b >> sg >> sb;
		multiset<int> green, blue;
		for(int i = 0; i < sg; i++){
			int cur;
			cin >> cur;
			green.insert(cur);
		}
		for(int i = 0; i < sb; i++){
			int cur;
			cin >> cur;
			blue.insert(cur);
		}
		while(true){
			if(green.empty() || blue.empty()) break;
			int battle = b;
			vector<int> res_b, res_g;
			while(battle && !green.empty() && !blue.empty()){
				int g_cur = *green.rbegin();
				int b_cur = *blue.rbegin();
				green.erase(green.lower_bound(g_cur));
				blue.erase(blue.lower_bound(b_cur));
				if(g_cur - b_cur > 0){
					res_g.push_back(g_cur - b_cur);
				}else if(b_cur - g_cur > 0){
					res_b.push_back(b_cur - g_cur);
				}
				battle--;
			}
			for(int x: res_b){
				blue.insert(x);
			}
			for(int x: res_g){
				green.insert(x);
			}
		}
		multiset<int>::reverse_iterator rit;
		if(green.empty() && blue.empty()){
			cout << "green and blue died" << '\n';
		}else if(green.empty()){
			cout << "blue wins" << '\n';
			rit = blue.rbegin();
			while(rit != blue.rend()){
				cout << *rit << '\n';
				rit++;
			}
		}else{
			cout << "green wins" << '\n';
			rit = green.rbegin();
			while(rit != green.rend()){
				cout << *rit << '\n';
				rit++;
			}
		}
		if(n != 0)cout << '\n';
	}
}
