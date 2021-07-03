#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
int arr[10000];

bool cmp(int a, int b) {
	if (a <= 0 && b <= 0) return a < b;
	else return a > b;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, cmp);

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) {
			if (arr[i] < 0 && arr[i + 1] == 0) {
				i++;
			}
			else if (arr[i] * arr[i + 1] > arr[i] && arr[i] * arr[i + 1] > arr[i+1]) {
				res += arr[i] * arr[i + 1];
				i++;
			}
			else res += arr[i];
		}
		else res += arr[i];
	}
	cout << res;

}