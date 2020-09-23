#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n == 1){
			cout << 0 << '\n';
			continue;
		}
		int treses = 0, doses = 0;
		bool est = false;
		while(n % 2 == 0){
			doses++;
			n /= 2;
		}
		while(n % 3 == 0){
			treses++;
			n /= 3;
			est = true;
		}
		if(n != 1 || !est || treses < doses){
			cout << -1 << '\n';
		}else{
			int top = max(treses, doses);
			int plus = treses - doses;
			cout << top + plus << '\n';
		}
	}
}
