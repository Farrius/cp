#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n);
		int sol = 0;
		int ar = n - 1, ben = n - 1;
		while(ar >= 0 && ben >= 0){
			if(a[ar] > b[ben]){
				sol++;
				ar--;
				ben--;
			}else{
				ben--;
			}
		}
		cout << sol << '\n';
	}
}
