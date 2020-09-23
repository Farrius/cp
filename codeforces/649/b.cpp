#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> res;
		for(int i = 0; i < n; i++){
			if(i == 0 || i == n - 1 || (a[i - 1] < a[i] != a[i] < a[i + 1]))
				res.push_back(a[i]);
		}
		cout << res.size() << '\n';
		for(int i = 0; i < res.size(); i++){
			cout << res[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
