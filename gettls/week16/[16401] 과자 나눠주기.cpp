#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int main() {
	int m, n, e = 0;
	cin >> m >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		v.push_back(x);
		if (x > e) e = x;
	}
	int s = 0, ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 0;
		if (mid != 0) {
			for (int i = 0; i < n; i++) {
				cnt += v[i] / mid;
			}
		}
		if (cnt >= m) {
			s = mid + 1;
			ans = mid;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans;
}