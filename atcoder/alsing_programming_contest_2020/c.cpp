#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1e4 + 1;
int main(){
	int a[maxN] = {0};
	bool para = false;
	for(int x = 1; x < 100; x++){
		for(int y = 1; y < 100; y++){
			for(int z = 1; z < 100; z++){
				int cur = x * x + y * y + z * z + x * y + y * z + z * x;
				if(cur < maxN) a[cur]++;
			}
		}
	}
	int n; 
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << a[i] << '\n';
	}
}
