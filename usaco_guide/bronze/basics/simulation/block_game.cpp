#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> v(26);
	for(int i = 0; i < n; i++){:x
		for(int un = 0; un < 2; un++){
			string s1, s2;
			cin >> s1 >> s2;
			vector<int> freq1(26), freq2(26);
			for(char x: s1){
				freq1[x - 'a']++;
			}
			for(char x: s2){
				freq2[x - 'a']++;
			}
			for(int j = 0; j < 26; j++){
				if(freq1[j] > freq2[j]){
					v[j].push_back(freq1[j]);
				}else{
					v[j].push_back(freq2[j]);
				}
			}
		}
	}
	for(auto arr: v){
		int cur = 0;
		sort(arr.rbegin(), arr.rend());
		for(int i = 0; i < n && i < len(arr); i++){
			cur += arr[i];
		}
		cout << cur << '\n';
	}
}
