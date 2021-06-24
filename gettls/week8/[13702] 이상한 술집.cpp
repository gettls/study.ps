#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
int n, k;
vector<ll> arr;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		ll x; 
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	ll s = 0, e = arr[n - 1], res=0;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += arr[i] / mid;			
		}	
		if (cnt >= k) {
			res = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	printf("%d", res);
}