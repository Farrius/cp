#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int prin = 0, fin = n - 1;
		bool canvio = false;
		vector<int> ans;
		for(int i = n - 1; i >= 0; i--){
			if((canvio ? (a[fin]^1) : a[prin]) == b[i]){
				ans.push_back(1);
			}
			ans.push_back(i + 1);
			if(canvio){
				fin--;
			}else{
				prin++;
			}
			canvio ^= 1;
		}
		cout << ans.size() << ' ';
		for(auto x: ans) cout << x << ' ';
		cout << '\n';
	}
}
