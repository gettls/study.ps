#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
// 1234567890
// 상하좌우 : -3,+3,-1,+1
// idx 가 012, 345, 678
int arr[9];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
string str;
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		str += arr[i] + '0';
	}
	int ans = -1;
	set<string> st;
	queue<pair<string, int>> q; // array, count
	q.push({ str, 0 });
	st.insert(str);
	while (!q.empty()) {
		string s = q.front().first;
		if (s == "123456780") {
			ans = q.front().second;
			break;
		}
		int cnt = q.front().second;
		int idx = s.find('0');
		int x = idx / 3, y = idx % 3;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			string tmp = s;
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			int nextIdx = nx * 3 + ny;
			char t = tmp[idx];
			tmp[idx] = tmp[nextIdx];
			tmp[nextIdx] = t;
			if (st.find(tmp) != st.end()) continue;
			q.push({ tmp, cnt + 1 });
			st.insert(tmp);
		}
	}
	cout << ans;
}
// 1 0 3 4 2 5 7 8 6