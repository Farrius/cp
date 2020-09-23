#include <bits/stdc++.h>

using namespace std;

multiset<int> tank1, tank2;
set<int> sol;

void search(int day, int cur, multiset<int> &t1, multiset<int> &t2){
	multiset<int> temp1, temp2;
	temp1 = t1;
	temp2 = t2;
	if(day == 4){
		sol.insert(cur);
		return;
	}
	if(day % 2 == 0){
		for(auto x: t1){
			temp2.insert(x);
			temp1.erase(temp1.lower_bound(x));
			search(day + 1, cur - x, temp1, temp2);
			temp2.erase(temp2.lower_bound(x));
			temp1.insert(x);
		}
	}else{
		for(auto x: t2){
			temp1.insert(x);
			temp2.erase(temp2.lower_bound(x));
			search(day + 1, cur + x, temp1, temp2);
			temp1.erase(temp1.lower_bound(x));
			temp2.insert(x);
		}
	}
	return;
}
int main(){
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

	for(int i = 0; i < 10; i++){
		int cur;
		cin >> cur;
		tank1.insert(cur);
	}

	for(int i = 0; i < 10; i++){
		int cur; 
		cin >> cur;
		tank2.insert(cur);
	}
	search(0, 1000, tank1, tank2);
	cout << (int) sol.size() << '\n';
}
