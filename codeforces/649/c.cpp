#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n];
	set<int> hacer;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		hacer.insert(a[i]);
	}
	int mex = 0;
	vector<int> res;
	auto it = hacer.begin();
	int last = 0;
	for(int i = 0; i < n; i++){
		int next_mex;
		if(i != 0 && a[i] != a[i - 1]){
			next_mex = *it;
			it++;
		}else{
			for(int j = last; ; j++){
				if(!hacer.count(j)){
					next_mex = j;
					last = j + 1;
					break;
				}
			}
		}
		res.push_back(next_mex);
	}
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << (i == n - 1 ? '\n' : ' ' );
	}
}
