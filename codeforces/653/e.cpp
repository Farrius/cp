#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a, b, common;
	for(int i = 0; i < n; i++){
		int t, c, p;
		cin >> t >> c >> p;
		if(c == 1 && p == 1){
			common.push_back(t);
		}else if(c == 1){
			a.push_back(t);
		}else if(p == 1){
			b.push_back(t);
		}
	}
	if(a.size() + common.size() < k || b.size() + common.size() < k){
		cout << -1 << '\n';
		return 0;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(common.begin(), common.end());
	ll sol = 0;
	int alice = 0, bob = 0, ai = 0, bi = 0, comi = 0;
	bool aend = false, bend = false, cend = false;
	while(alice < k || bob < k ){
		if(ai >= a.size() || alice >= k) aend = true;
		if(bi >= b.size() || bob >= k) bend = true;
		if(comi >= common.size()) cend = true;
		if(aend){
			if(aend && alice < k){
				sol += common[comi];
				comi++;
				alice++;
				bob++;
			}else if(bend){
				sol += common[comi];
				comi++;
				alice++;
				bob++;
			}else{
				if(cend || common[comi] > b[bi]){
					sol += b[bi];
					bi++;
					alice++;
					bob++;
				}else{
					sol += common[comi];
					comi++;
					bob++;
					alice++;
				}
			}
		}else if(bend){
			if(bend && bob < k){
				sol += common[comi];
				comi++;
				alice++;
				bob++;
			}else if(aend){
				sol += common[comi];
				comi++;
				alice++;
				bob++;
			}else{
				if(cend || common[comi] > a[ai]){
					sol += a[ai];
					ai++;
					alice++;
				}else{
					sol += common[comi];
					comi++;
					bob++;
					alice++;
				}
			}
		}else if(cend){
			if(aend){
				sol += b[bi];
				bob++;
				bi++;
			}else if(bend){
				sol += a[ai];
				alice++;
				ai++;
			}else{
				sol += a[ai] + b[bi];
				ai++;
				bi++;
				alice++;
				bob++;
			}
		}else{
			if(common[comi] <= a[ai] + b[bi]){
				sol += common[comi];
				comi++;
			}else{
				sol += a[ai] + b[bi];
				ai++;
				bi++;
			}
			alice++;
			bob++;
		}
	}
	cout << sol << '\n';
}










