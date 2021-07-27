#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int n, m;
int cache[4001][4001];

int main() {
	cin.tie(0);
	cout.tie(0);
	string a, b;
	getline(cin, a);
	getline(cin, b);
	memset(cache, 0, sizeof(cache));
	int ans = 0;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				cache[i][j] = cache[i - 1][j - 1] + 1;
				if (cache[i][j] > ans) ans = cache[i][j];
			}
		}
	}
	cout << ans;
}