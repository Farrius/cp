#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6;
int main(){
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	int ans = 0, spuede = 0, tpuede = 0, es10 = 0, es01 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1' && t[i] == '0'){
			spuede++;
			if(es01){
				es01--;
			}else{
				ans++;
			}
			es10++;
		}else if(s[i] == '0' && t[i] == '1'){
			tpuede++;
			if(es10){
				es10--;
			}else{
				ans++;
			}
			es01++;
		}
	}
	if(spuede != tpuede) cout << -1 << '\n';
	else cout << ans << '\n';
}
