#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m, l;
vector<int> v, arr;

int main() {

	cin >> n >> m >> l;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	v.push_back(0); v.push_back(l);
	sort(v.begin(), v.end());
	int s = 1, e = l - 1;
	int res = 1e9;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 0;
		
		for (int i = 1; i < n + 2; i++) {
			int dist = v[i] - v[i - 1] - 1;
			cnt += dist / mid;
		}

		if (cnt > m) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	printf("%d", s);
}