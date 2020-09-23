#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ld;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, l;
		cin >> n >> k >> l;
		int a[n];
		vector<int> seg = {-1};
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] + k <= l){
				seg.push_back(i);
			}
		}
		seg.push_back(n);
		bool puede = true;
		for(int i = 1; i < (int)seg.size() && puede; i++){
			bool abajo = true;
			int tide = k;
			for(int j = seg[i - 1] + 1; j < seg[i]; j++){
				tide += abajo ? -1 : +1;
				if(abajo) tide -= max(0, a[j] + tide - l);
				if(tide < 0 || tide + a[j] > l){
					puede = false;
					break;
				}
				if(tide == 0) abajo = false;
			}
		}
		if(puede) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}
