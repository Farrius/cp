#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, p;
	cin >> n >> p;
	int a[n], maxi = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		maxi = max(maxi, a[i] - i);
	}
	int b = 0;
	for(int i = 0; i < n; i++){
		if(i >= p - 1){
			b = max(b, min(maxi - (a[i] - i), i));
		}
	}
	b = max(0, p - b - 1);

	cout << b << '\n';
	for(int i = 0; i < b; i++){
		cout << maxi + i << (i == b - 1 ? '\n' : ' ');
	}

}
