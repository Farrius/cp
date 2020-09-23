#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = (int) s.size();
		int resta = 0;
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				int countI = 0, countJ = 0;
				for(auto &ch : s){
					int d = ch - '0';
					if(countI <= countJ){
						if(d == i)
							countI++;
					}else{
						if(d == j)
							countJ++;
					}
				}
				resta = max(resta, (i == j ? countI + countJ : countJ * 2));
			}
		}
		cout << n - resta << '\n';
	}
}
