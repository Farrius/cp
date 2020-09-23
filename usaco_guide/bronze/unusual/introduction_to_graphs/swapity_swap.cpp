#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> sol;
	vector<int> base(n);
	for(int i = 1; i <= n; i++){
		base[i - 1] = i;
	}
	sol.push_back(base);

	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	a1--;
	a2--;
	b1--;
	b2--;
	int ciclos = 0, ai = a2 - a1, bi = b2 - b1;

	vector<int> new_arr(n);
	new_arr = base;

	while(true){
		vector<int> past_arr(n);
		past_arr = new_arr;

		for(int i = 0; i <= ai; i++){
			new_arr[a1 + i] = past_arr[a2 - i];
		}

		past_arr = new_arr;

		for (int i = 0; i <= bi; i++) {
			new_arr[b1 + i] = past_arr[b2 - i];
		}
		
		ciclos++;
		if(new_arr == base) break;
		sol.push_back(new_arr);
	}

	for(int i = 0; i < n; i++){
		cout << sol[(k % ciclos)][i] << '\n';
	}
}
