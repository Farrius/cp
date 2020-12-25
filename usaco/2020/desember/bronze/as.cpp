#include <bits/stdc++.h>

using namespace std;

int main () {
	int ar[7];
	for (int i = 0; i < 7; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + 7);
	int a = ar[0], b = ar[1], i = 2;
	if (ar[2] == a + b) i++;
	cout << a << ' ' << b << ' ' << ar[i] << '\n';
}
