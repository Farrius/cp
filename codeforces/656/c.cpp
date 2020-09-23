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
		if(n == 1 || n == 2){
			cout << 0 << '\n';
			continue;
		}

		bool deq = (a[n - 1] > a[n - 2]);
		bool full = true;
		for(int i = n - 2; i >= 1; i--){
			if(deq){
				if(a[i] < a[i - 1]){
					cout << i << '\n';
					full = false;
					break;
				}
			}else{
				if(a[i] > a[i - 1]) deq = true;
			}
		}	

		if(full) cout << 0 << '\n';
	}
}
