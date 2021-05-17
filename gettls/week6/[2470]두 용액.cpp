#include<iostream>
#include<queue>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int n, a,b;
vector<long long> arr;
long long res;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	
	int s = 0, e = n - 1;	
	int res = 2e9;
	while (s < e) {
		int p = arr[s] + arr[e];
		if (p == 0) {
			a = s, b = e;
			break;
		}
		if (abs(res) > abs(p)) {
			a = s, b = e;
			res = p;
		}
		if (p > 0) {
			e--;
		}
		else if (p < 0) {
			s++;
		}
	}
	cout << arr[a] << " " << arr[b];
}
