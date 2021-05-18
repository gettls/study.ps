#include<iostream>
#include<queue>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

int N[500000];
int M[500000];
int n, m;
int binarySearch(int target) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (N[mid] > target) end = mid - 1;
		else if (N[mid] < target) start = mid + 1;
		else if(N[mid] == target) return 1;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &N[i]);
	sort(N, N + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &M[i]);
		printf("%d ", binarySearch(M[i]));
	}
}
