#include <bits/stdc++.h>

using namespace std;


int main(){
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

	int n;
	cin >> n;
	int sorted[n];
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		sorted[i] = i;
		cin >> v[i];
		v[i]--;
	}
	int sol = 0;
	while(true){
		bool para = true;
		for(int i = 0; i < n; i++){
			if(v[i] != sorted[i]){
				para = false;
				break;
			}
		}
		if(para) break;
		vector<int> new_arr(n);
		int seqIndex = n - 1;
		int comp = 100;

		while(v[seqIndex] > v[0] && comp > v[seqIndex]){
			comp = v[seqIndex];
			seqIndex--;
		}

		for(int i = 0; i < seqIndex; i++){
			new_arr[i] = v[i + 1];
		}
		new_arr[seqIndex] = v[0];
		for(int i = seqIndex + 1; i < n; i++){
				new_arr[i] = v[i];
		}
		v = new_arr;
		sol++;
	}

	cout << sol << '\n';
}
