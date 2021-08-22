#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#pragma warning (disable : 4996)
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> a, b;

		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			a.push_back(x);
		}

		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end());
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			vector<int>::iterator it = upper_bound(a.begin(), a.end(), b[i]);
			if (it != a.end()) cnt += a.end() - it;
		}
		cout << cnt << "\n";
	}
}