#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		set<int> CDs;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			CDs.insert(cur);
		}
		int sol = 0;
		for(int i = 0; i < m; i++){
			int cur;
			cin >> cur;
			if(CDs.count(cur)) sol++;
		}
		cout << sol << '\n';
	}
}
