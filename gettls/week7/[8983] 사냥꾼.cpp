#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main() {
	long long n, m, l;
	cin >> m >> n >> l;
	vector<int> ss;
	vector<pair<int, int>> ani;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		ss.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		ani.push_back({ x,y });
	}
	sort(ss.begin(), ss.end());
	sort(ani.begin(), ani.end());

    // 가장 가까운 사대의 위치를 이분탐색으로 찾아냄
	int cnt = 0;
	for (int i = 0; i < ani.size(); i++) {
		int s = 0, e = m-1;
		while (s <= e) {
			int m = (s + e) / 2;
			int mid = ss[m];
			int dist = abs(ani[i].first - mid) + ani[i].second;
			if (dist <= l) {
				cnt++;
				break;
			}
			else {
				if (ani[i].first > mid) s = m + 1;
				else e = m - 1;
			}
		}
	}
	cout << cnt;
}