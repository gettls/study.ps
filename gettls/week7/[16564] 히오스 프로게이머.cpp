#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main() {
	long long n, k;
	vector <long long> v;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		long long  x;
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	long long s = v[0], e = v[n - 1] + k;
	long long res = v[0];
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] < mid)  sum += mid - v[i];
		}

		if (sum > k) e = mid - 1;
		else {
			s = mid + 1;
			res = mid;
		}
	}
	cout << res;
}