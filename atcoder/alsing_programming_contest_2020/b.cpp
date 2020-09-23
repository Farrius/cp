#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int sol = 0;
	for(int i = 1; i <= n; i += 2){
		if(a[i] % 2)sol++;
	}
	cout << sol <<'\n';
}
