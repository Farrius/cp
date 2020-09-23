#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	vector<int> a(4);
	for(int i = 0; i < 4; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[3] - a[0] << ' ' << a[3] - a[1] << ' ' << a[3] - a[2] << '\n';
}
