#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int a[1000], n;
set<int> used;
bool ok = false;

void search(int i){
	if(ok) return;
	if(i == n - 1){
		for(int j = 0; j < n; j++){
			cout << ans[j] << (j == n - 1 ? '\n' : ' ');
		}
		ok = true;
		return;
	}
	if(!used.count(abs(a[i] - ans[i])) && a[i] != ans[i]){
		used.insert(abs(a[i] - ans[i]));
		ans.push_back(abs(a[i] - ans[i]));
		search(i + 1);
		used.erase(abs(a[i] - ans[i]));
		ans.pop_back();
	}
}
int main(){
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);

	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> a[i];
	}
	
	for(int x = 1; x < a[0]; x++){
		ans.push_back(x);
		used.insert(x);
		search(0);
		ans.pop_back();
		used.erase(x);
	}
}
