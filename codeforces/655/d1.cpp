#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int64_t> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int64_t> pref = a;
	vector<int64_t> suff = a;
	for(int i = 0; i + 2 < n; i++){
		pref[i + 2] += pref[i];
	}
	for(int i = n - 1; i >= 2; i--){
		suff[i - 2] += suff[i]; 	
	}
	int64_t sol = pref[n - 1];
	for(int i = 0; i + 1 < n; i++){
		sol = max(sol, pref[i] + suff[i + 1]);
	}
	cout << sol << '\n';
}
