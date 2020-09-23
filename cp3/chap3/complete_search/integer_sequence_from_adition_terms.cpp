#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		cout << "lloop" << '\n';
		int grade;
		cin >> grade;
		int poli[grade];
		for(int i = 0; i <= grade; i++){
			cin >> poli[i];
		}
		int d, k;
		cin >> d >> k;
		cout << d << ' ' << k << '\n';
		int n = 1;
		ll acc = 0;
		while(true){
			ll cur = 0;
			for(int i = 0; i < grade; i++){
				cur += (n<<i) * poli[i];
			}
			int tmp = cur * d;
			acc += tmp;
			if(acc >= k){
				cout << cur << '\n';
				break;
			}
			n++;
		}
	}
}
