#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int n, m;
int cache[101][101][101];

// 2개의 문자열을 비교하는 문제의
// cache를 단순히 2차원에서 3차원으로 변경했다.
int main() {
	cin.tie(0);
	cout.tie(0);
	string a, b, c;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	memset(cache, 0, sizeof(cache));
	int ans = 0;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			for (int k = 1; k <= c.size(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					cache[i][j][k] = cache[i - 1][j - 1][k - 1] + 1;
				}
				else cache[i][j][k] = max(cache[i - 1][j][k], max(cache[i][j - 1][k], cache[i][j][k - 1]));
			}
		}
	}
	cout << cache[a.size() - 1][b.size() - 1][c.size() - 1];
}