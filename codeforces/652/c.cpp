#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<ll> ar(n), amigos(k);
		for(int i = 0; i < n; i++){
			cin >> ar[i];
		}
		for(int i = 0; i < k; i++){
			cin >> amigos[i];
		}
		int pos_mas = n - 1, pos_neg = 0;
		ll sol = 0;
		sort(ar.begin(), ar.end());
		sort(amigos.begin(), amigos.end(), greater<int>());
		int last_index = 0;
		for(int i = k - 1; i >= 0; i--){
			if(amigos[i] != 1){
				last_index = i + 1;
				break;
			}
			sol += (ar[pos_mas] * 2);
			pos_mas--;
		}
		for(int i = 0; i < last_index; i++){
			int w = amigos[i];
			sol += ar[pos_mas];
			w--;
			if(w > 0){
				sol += ar[pos_neg];
				pos_neg += w;
			}else{
				sol += ar[pos_mas];
			}
			pos_mas--;
		}
		cout << sol << '\n';
	}
}
