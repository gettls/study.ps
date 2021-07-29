#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;

int arr[20][20];

vector<int> index;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	} 
	index.resize(n);
	for (int i = n / 2; i < n; i++) index[i] = 1;
	// 팀 조합을 위한 index
	// 반은 a팀, 나머지 반은 b팀
	int res = 1e9;
	do {
		vector<int> a, b;
		int x=0, y=0;
		for (int i = 0; i < n; i++) {
			if (index[i] == 1) a.push_back(i);
			if (index[i] == 0) b.push_back(i);
		}
		a.push_back(a[0]); b.push_back(b[0]);
		
		for (int i = 0; i < n/2; i++) {
			for (int j = 1; j <= n/2; j++) {
				x += arr[a[i]][a[j]];
				y += arr[b[i]][b[j]];
			}
		}
		res = min(abs(x - y), res);
	} while (next_permutation(index.begin(), index.end()));
	cout << res;
}