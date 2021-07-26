#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int n, m;
int arr[9];
vector<int> v;
void dfs(int cnt, int index) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i]) continue;
		arr[i] = 1;
		v.push_back(i);
		dfs(cnt + 1, index);
		v.pop_back();
		arr[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);

}