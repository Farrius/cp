#include <bits/stdc++.h>

using namespace std;

int position (double x, const vector<double>&v, int left, int right) {
	if (left > right) return -1;
	auto it = lower_bound(v.begin() + left, v.begin() + right, x);
	if (it == v.end() || *it != x) return -1;
	else return (it - v.begin());
}
