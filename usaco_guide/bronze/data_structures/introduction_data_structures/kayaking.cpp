#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n * 2; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int sol = INT_MAX;
	for(int i = 0; i < n * 2; i++){
		for(int j = i + 1; j < n * 2; j++){
			int cur = 0;
			bool juntar = false;
			int last;
			for(int index = 0; index < n * 2; index++){
				if(index == i || index == j) continue;
				if(!juntar){
					last = a[index];
					juntar = true;
				}else{
					cur += abs(last - a[index]);
					juntar = false;
				}
			}
			sol = min(sol, cur);
		}
	}
	cout << sol << '\n';
}
