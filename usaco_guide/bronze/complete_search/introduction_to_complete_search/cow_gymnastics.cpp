#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	
	int k, n;
	cin >> k >> n;
	int a[k][n];
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			int cur;
			cin >> cur;
			cur--;
			a[i][j] = cur;
		}
	}

	int sol = 0;

	for(int i = 0; i < n; i++){
		vector<int> freq(n);
		int cur = a[0][i];
		for(int dia = 0; dia < k; dia++){
			bool contar = false;
			for(int j = 0; j < n; j++){
				if(contar){
					freq[a[dia][j]]++;
				}
				if(a[dia][j] == cur) contar = true;
			}
		}
		for(int x: freq){
			if(x == k) sol++;
		}
	}

	cout << sol << '\n';
}

