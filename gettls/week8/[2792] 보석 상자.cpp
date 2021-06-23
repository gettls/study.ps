#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning (disable:4996)
using namespace std;

vector<long long> arr;

int main() {
	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	long long s = 1, e = arr[m - 1];
	long long res = arr[m-1];
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += arr[i] / mid;
			if (arr[i] % mid > 0) cnt++;
		}

		if (cnt > n) {
			s = mid + 1;
		}
		else {
			if (mid < res) res = mid;
			e = mid - 1;
		}
	}
	printf("%d", res);
}