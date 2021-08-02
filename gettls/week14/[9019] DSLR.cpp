#include <string>
#include <set>
#include <vector>
#include<cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int in, out;

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> in >> out;
		queue<pair<int, string>> q; // num, cmd
		int v[10000];
		memset(v, 0, sizeof(v));
		v[in] = 1;
		q.push({ in, "" });
		while (!q.empty()) {
			int tmp = q.front().first;
			string cmd = q.front().second;
			if (tmp == out) {
				cout << cmd << "\n";
				break;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (i == 0) { // D
					int next = tmp * 2 % 10000;
					if (v[next]) continue;
					q.push({ next,cmd+'D' });
					v[next] = 1;
				}
				if (i == 1) { // S
					int next = tmp - 1;
					if (next < 0) next = 9999;
					if (v[next]) continue;
					q.push({ next,cmd+'S' });
					v[next] = 1;
				}
				if (i == 2) { // L
					int next = tmp % 1000 * 10 + tmp / 1000;
					if (v[next]) continue;
					q.push({ next,cmd+'L' });
					v[next] = 1;
				}
				if (i == 3) { // R
					int next = tmp % 10 * 1000 + tmp / 10;
					if (v[next]) continue;
					q.push({ next,cmd+'R' });
					v[next] = 1;
				}
			}

		}
	}

}

/*
아래는 백트래킹을 이용한 방법 (처음 생각했던 방법)
백트래킹을 이용하면 TLE가 나오는데
사용한 숫자를 다음에도 계산하기 떄문임
한번 지나간 숫자는 최솟값을 지나쳐왔기 때문에
한번 쓴 숫자는 다시 조회할 필요가 없음
*/
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

string in, out;
string arr = "DSLR";
vector<char> cmd;
string D(string str) {
	int tmp = stoi(str);
	tmp *= 2;
	if (tmp >= 10000) tmp %= 10000;
	str = to_string(tmp);
	return str;
}
string S(string str) {
	int tmp = stoi(str);
	tmp -= 1;
	if (tmp < 0) tmp = 9999;
	str = to_string(tmp);
	return str;
}
string L(string str) {
	deque<char> dq;
	string ret;
	for (int i = 0; i < 4 - str.size(); i++) dq.push_back('0');
	for (int i = 0; i < str.size(); i++) dq.push_back(str[i]);
	dq.push_back(dq.front());
	dq.pop_front();
	while (!dq.empty()) {
		ret += dq.front();
		dq.pop_front();
	}
	return to_string(stoi(ret));
}
string R(string str) {
	deque<char> dq;
	string ret;
	for (int i = 0; i < 4 - str.size(); i++) dq.push_back('0');
	for (int i = 0; i < str.size(); i++) dq.push_back(str[i]);
	dq.push_front(dq.back());
	dq.pop_back();
	while (!dq.empty()) {
		ret += dq.front();
		dq.pop_front();
	}
	return to_string(stoi(ret));
}


int dfs(int ans, int cnt) {
	if (ans == cnt) {
		string t = in;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'D') t=D(t);
			if (cmd[i] == 'S') t=S(t);
			if (cmd[i] == 'L') t=L(t);
			if (cmd[i] == 'R') t=R(t);
		}
		if (t == out) 
			return 1;
		else return 0;
	}

	for (int i = 0; i < 4; i++) {
		cmd.push_back(arr[i]);
		if (dfs(ans, cnt + 1)) return 1;
		cmd.pop_back();
	}

	return 0;
}


int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> in >> out;

		int cnt = 0;
		while (1) {
			vector<char> x;
			x.swap(cmd);
			if (dfs(cnt, 0)) {
				for (int i = 0; i < cmd.size(); i++) cout << cmd[i];
				cout << "\n";
				break;
			}
			cnt++;
		}
	}
}