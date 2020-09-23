#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1e7 + 1;
int main(){
	int n;
	cin >> n;
	ll sol = 1;
	vector<int> sieve(maxN, 2);
	for(int i = 2; i <= n; i++){
		sol += i * sieve[i];
		for(int j = i + i; j <= n; j += i){
			sieve[j]++;
		}
	}
	cout << sol << '\n';
}
