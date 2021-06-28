#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning (disable:4996)
using namespace std;

vector<long long> arr;
int main() {
	int n, k;

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		long long x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	long long s = 1, e = arr[k - 1];
	int res = 1;
	while (s <= e) {
		long long mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (arr[i] / mid);
		}

		if (cnt >= n) {
			s = mid + 1;
			if (mid > res) res = mid;
		}
		else e = mid - 1;
	}

	printf("%d", res);
}