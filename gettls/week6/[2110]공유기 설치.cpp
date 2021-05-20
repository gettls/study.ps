#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

vector<int> v;

int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int min = 1, max = v[n - 1] - v[0];
	int res = 0;
	while (min <= max) {
		int mid = (min + max) / 2;
		int start = v[0];
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			int dist = v[i] - start;
			if( dist >= mid ) {
				start = v[i];
				cnt++;
			}
		}
		if (cnt >= c) { // 간격 넓히기
			min = mid + 1;
			res = mid;
		}
		else if (cnt < c) { // 간격 줄이기
			max = mid - 1;
		}
		
	}

	cout << res;
}
