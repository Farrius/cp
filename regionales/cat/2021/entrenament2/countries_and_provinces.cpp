#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Province {
         string name;
         string capital;
         int population;
         int area;
         double gdp;
     };

struct Country {
         string name;
         string capital;
         vector<Province> provs;
     };

typedef vector<Country> Countries;

int population (const Countries& p, double x) {
	int sol = 0;
	for (auto c : p) {
		int okis = 0, cur = 0;
		for (auto y : c.provs) {
			if (y.gdp <= x) okis++;
			cur += y.population;
		}
		if (okis >= 2) sol += cur;
	}
	return sol;
}
