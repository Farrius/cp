#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n;
	cin >> n;
	pair<int, int> a[n];
	for(int i = 0; i < n; i++){
		int a1, a2;
		cin >> a1 >> a2;
		a[i] = make_pair(a1, a2);
	}
	
	int sol = 0;

	for(int i1 = 0; i1 < n; i1++){
		for(int i2 = i1 + 1; i2 < n; i2++){
			for(int i3 = i2 + 1; i3 < n; i3++){
				pair<int, int> i = a[i1];
				pair<int, int> j = a[i2];
				pair<int, int> k = a[i3];
				if(i.first == j.first && j.first == k.first) continue;
				if(i.second == j.second && j.second == k.second) continue;
				int b = 0, h = 0;
				if(i.first == j.first){
					b = abs(j.second - i.second);
					if(i.second == k.second){
						h = abs(i.first - k.first);
					}else if(j.second == k.second){
						h = abs(j.first - k.first);
					}
				}else if(i.first == k.first){
					b = abs(i.second - k.second);
					if(i.second == j.second){
						h = abs(i.first - j.first);
					}else if(k.second == j.second){
						h = abs(k.first - j.first);
					}
				}else if(j.first == k.first){
					b = abs(k.second - j.second);
					if(j.second == i.second){
						h = abs(j.first - i.first);
					}else if(k.second == i.second){
						h = abs(k.first - i.first);
					}
				}
				sol = max(sol, b * h);
			}
		}
	}

	cout << sol << '\n';
}
