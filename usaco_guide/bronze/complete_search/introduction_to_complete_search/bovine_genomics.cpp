#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	string spoty[n], plain[n];
	for(int i = 0; i < n; i++){
		cin >> spoty[i];
 	}
	for(int i = 0; i < n; i++){
		cin >> plain[i];
	}
	int sol = 0;
	for(int i = 0; i < m; i++){
		bool puede = true;
		set<char> st;
		for(int j = 0; j < n; j++){
			st.insert(spoty[j][i]);
		}
		for(int j = 0; j < n; j++){
			if(st.count(plain[j][i])) puede = false;
		}
		if(puede) sol++;
	}
	cout << sol << '\n';
}
