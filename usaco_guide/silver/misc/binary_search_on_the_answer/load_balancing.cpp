#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

int n;
vector<int> regions(4), x(MX), y(MX), sortedX(MX), sortedY(MX);

bool cmpX (const int& a, const int& b) {
	return x[a] < x[b];
}

bool cmpY (const int& a, const int& b) {
	return y[a] < y[b];
}

int mxIndex (int mid, vector<int>& ar, vector<int>& in) {
	int diff = 0;
	int i = 0;
	while (true) {
		if (i == 0 || ar[in[i]] != ar[in[i - 1]]) diff++;
		if (i == n - 1) break;
		else if ((diff == mid && ar[in[i + 1]] == ar[in[i]]) || diff < mid) i++;
		else break;
	}
	return i;
}

bool check (int mid, int xLine, int yLine) {
	fill(regions.begin(), regions.end(), 0);
	vector<int> prevLine;
	if (xLine == -1) {
		for (int i = 0; i < n; i++) {
			if (y[sortedY[i]] < yLine) prevLine.push_back(sortedY[i]);
			else break;
		}
		sort(prevLine.begin(), prevLine.end(), cmpX);
		xLine = x[prevLine[mxIndex(mid, x, prevLine)]] + 1;
	} else {
		for (int i = 0; i < n; i++) {
			if (x[sortedX[i]] < xLine) prevLine.push_back(sortedX[i]);
			else break;
		}
		sort(prevLine.begin(), prevLine.end(), cmpY);
		yLine = y[prevLine[mxIndex(mid, y, prevLine)]] + 1;
	}
	//check regions
	for (int i = 0; i < n; i++) {
		if (x[i] < xLine && y[i] < yLine) regions[0]++;
		else if (x[i] < xLine && y[i] > yLine) regions[1]++;
		else if (x[i] > xLine && y[i] < yLine) regions[2]++;
		else regions[3]++;
	}
	int m = *max_element(regions.begin(), regions.end());

	return m <= mid;
}

int main () {
	//freopen("balancing.in", "r", stdin);
	//freopen("balancing.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		sortedX[i] = sortedY[i] = i;
	}
	
	sort(sortedX.begin(), sortedX.end(), cmpX);
	sort(sortedY.begin(), sortedY.end(), cmpY);

	int lo = 1, hi = n, sol = n;
	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		if (check(mid, x[sortedX[mxIndex(mid, x, sortedX)]] + 1, -1) || check(mid, -1, y[sortedY[mxIndex(mid, y, sortedY)]] + 1)) {
			sol = min(sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << sol << '\n';
}
