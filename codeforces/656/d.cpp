#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;

int fn(char cur, int l, int r){
	if(l + 1 == r){
		return (s[l] != cur);
	}
	int mid = l + (r - l)/2;
	int mid1 = 0, mid2 = 0;
	for(int i = l; i < mid; i++){
		if(s[i] != cur) mid1++;
	}
	for(int i = mid; i < r; i++){
		if(s[i] != cur) mid2++;
	}
	char nex_cur = cur + 1;
	return min(fn(nex_cur, l, mid) + mid2, fn(nex_cur, mid, r) + mid1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> s;
		int sol = fn('a', 0, n);
		cout << sol << '\n';
	}
}
