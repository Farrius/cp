include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int x, y;
	cin >> x >> y;
	if(x * 4 >= y && y >= x * 2 && y % 2 == 0) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
