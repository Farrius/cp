#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	map<string, int> mp;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string cur;
		cin >> cur;
		mp[cur]++;
	}
	cout << "AC x " << mp["AC"] << '\n';
	cout << "WA x " << mp["WA"] << '\n';
	cout << "TLE x " << mp["TLE"] << '\n';
	cout << "RE x " << mp["RE"] << '\n';
}
