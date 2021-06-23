#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning (disable:4996)
using namespace std;

vector<int> a, b;

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int s = 0, e = n - 1;
		int flag = 1;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (b[i] == a[mid]) {
				printf("1\n");
				flag = 0;
				break;
			}
			else if (b[i] > a[mid]) s = mid + 1;
			else e = mid - 1;
		}
		if (flag) printf("0\n");
	}

}