#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, k;
	cin >> n >> k;
	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	int l = 1;
	int r = 1e9;
	int ans;
	while(l <= r){
		int mid = l + (r - l)/2;
		bool puede = false;
		int inpares = 0;
		bool found = false;
		bool first = true;
		for(int i = 0; i < n; i++){
			if(i % 2 == 0){
				if(found){
					found = true;
					inpares++;
				}
				continue;
			}
			if(ar[i] <= mid){
				found = true;
				inpares++;
				if(first){
					inpares++;
					first = false;
				}
			}
		}
		if(inpares >= k){
			puede = true;
			ans = mid;
		}
		if(puede){
			r = mid - 1;
			continue;
		}
		inpares = 0;
		found = false;
		first = true;
		for(int i = 0; i < n; i++){
			if(i % 2){
				if(found){
					found = false;
					inpares++;
				}
				continue;
			}
			if(ar[i] <= mid){
				found = true;
				inpares++;
				if(first){
					if(i != 0) inpares++;
					first = false;
				}
			}
		}
		if(inpares >= k){
			puede = true;
			ans = mid;
		}
		if(puede) r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
}

