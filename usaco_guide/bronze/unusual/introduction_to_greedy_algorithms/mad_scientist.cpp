#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int sol = 0;
	bool mal = false;
	for(int i = 0; i < n; i++){
		if(s1[i] == s2[i]){
			mal = false;
			continue;
		}
		if(!mal){
			sol++;
			mal = true;
		}
	}

	cout << sol << '\n';
}
