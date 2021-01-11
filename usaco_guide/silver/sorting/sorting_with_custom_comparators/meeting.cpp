#include <bits/stdc++.h>

using namespace std;

int main () {
	//coger el input
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	int n, l;
	cin >> n >> l;
	vector<int> x(n), d(n), w(n), xc, dc, wc;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> x[i] >> d[i];
	}
	//sortear por x
	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&] (int a, int b) {return x[a] < x[b];});
	for (int t : ind) {
		xc.push_back(x[t]);
		dc.push_back(d[t]);
		wc.push_back(w[t]);
	}
	swap(x, xc); swap(w, wc); swap(d, dc);
	//ordenamos por distancia hasta llegar un barn
	int tot_t = 0;
	vector<int> left, right;
	for (int i = 0; i < n; i++) {
		if (d[i] == -1) left.push_back(x[i]);
		else right.push_back(x[i]);
		tot_t += w[i];
	}
	vector<pair<int, int>> ar;
	for (int i = 0; i < (int) left.size(); i++) {
		ar.push_back({left[i], w[i]});
	}
	for (int i = 0; i < (int) right.size(); i++) {
		ar.push_back({l - right[i], w[(int) left.size() + i]});
	}
	sort(ar.begin(), ar.end());
	//vemos cuantos pasos se pueden dar hasta que lleguen a un barn
	int t = -1;
	for (auto cur : ar) {
		tot_t -= cur.second * 2;
		if (tot_t <= 0) {
			t = cur.first;
			break;
		}
	}
	//mirar si se cruzan
	queue<int> rig;
	int sol = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == -1) {
			while (rig.size() && rig.front() + 2 * t < x[i]) rig.pop();
			sol += rig.size();
		} else {
			rig.push(x[i]);
		}
	}
	cout << sol << '\n';
}
