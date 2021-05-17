#include<iostream>
#include<queue>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

int arr[1000], d[1000];

int main() {
	int n, max_index, res = 1;
	scanf("%d", &n);
	fill(d, d + n, 1);
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) d[i] = max(d[i], d[j] + 1);
		}
		res = max(res, d[i]);
	}
	cout << res;
}
