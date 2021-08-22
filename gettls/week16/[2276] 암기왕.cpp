#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int x;
            scanf("%d",&x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x;
            scanf("%d",&x);
			vector<int> ::iterator it;
			it = lower_bound(a.begin(), a.end(), x);
			if (it == a.end()) printf("0\n");
			else if (*it == x) printf("1\n");
			else printf("0\n");
		}

	}
}