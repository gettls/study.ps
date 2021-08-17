#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#pragma warning (disable : 4996)
int main() {
	int n, m, max = 0;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
		if (x > max) max = x;
	}

	int s = max, e = max * n + 1, ans = 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 1, left = mid; // count withdrwal
		for (int i = 0; i < n; i++) {
			if (v[i] <= left) {
				left -= v[i];
			}
			else if (v[i] > left) {
				left = mid;
				left -= v[i];
				cnt++;
			}
		}
		if (cnt > m) {
			s = mid + 1;
		}
		else if (cnt <= m) {
			ans = mid;
			e = mid - 1;
		}
	}

	cout << ans;
}