#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int l, r, d;
	cin >> l >> r >> d;
	int sol = 0;
	for(int i = l; i <= r; i++){
		if(i % d == 0) sol++;
	}
	cout << sol << '\n';
}
