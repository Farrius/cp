#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second

#define len(x) (int)x.size()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);
	
	int n;
	cin >> n;
	int time = 0;
	pair<int, int> a[n];
	for(auto &x: a){
		cin >> x.f >> x.s;
	}
	sort(a, a + n);
	for(auto x: a){
		if(time >= x.f){
			time += x.s;
		}else{
			time += x.f - time;
			time += x.s;
		}
	}
	cout << time << '\n';
}
