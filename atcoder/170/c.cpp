#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int x, n;
	cin >> x >> n;
	set<int> st;
	for(int i = 0; i < n; i++){
		int cur;
		cin >> cur;
		st.insert(cur);
	}
	int sol = INT_MAX;
	for(int i = x; i <= 101; i++){
		if(st.count(i)) continue;
		sol = min(sol, abs(x - i));
	}
	for(int i = x; i >= 0; i--){
		if(st.count(i)) continue;
		sol = min(sol, abs(x - i));
	}
	if(st.count(x - sol)) cout << x + sol << '\n';
	else cout << x - sol << '\n';
}
