#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1e6;
int ar[maxN];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll sol = 0, extra = 0;
		for(int i = 0; i < n; i++){
			cin >> ar[i];
			if(i % 2 == 0) sol += ar[i];
		}
		ll pref = 0;
		for(int i = 0; i + 1 < n; i += 2){
			pref = pref - ar[i] + ar[i + 1];
			extra = max(extra, pref);
			pref = max(pref, 0LL);
		}
		pref = 0;
		for(int i = 1; i + 1 < n; i += 2){
			pref = pref + ar[i] - ar[i + 1];
			extra = max(extra, pref);
			pref = max(pref, 0LL);
		}
		cout << sol + extra << '\n';
	}
}
