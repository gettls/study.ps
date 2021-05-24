#include<algorithm>
#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
long long n, m;
vector<long long> v;
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	long long s = 0, e = v[n - 1], res = 0;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < v[i]) sum += v[i] - mid;
		}
		if (sum >= m) {
			res = max(res, mid);
			s = mid + 1;
		}
		else if(sum<=m){
			e = mid - 1;
		}
	}
	cout << res;
}