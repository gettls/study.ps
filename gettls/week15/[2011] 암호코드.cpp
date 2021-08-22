#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

long long d[5001][2];
int main() {
	int res = 0;
	bool c = false;
	string s;
	cin >> s;

	if (s[0] == '0') {
		cout << res;
	}

	else {
		d[1][0] = 1;
		for (int idx = 2; idx <= s.size(); idx++) {

			if (s[idx - 1] != '0') { // 1자릿수 0이 아닌 경우
				d[idx][0] = (d[idx - 1][0] + d[idx - 1][1]) % 1000000;
				if (d[idx][0] == 0) {
					c = true;
					break;
				}
			}

			string tmp = s.substr(idx - 2, 2); // 2자릿수
			if (stoi(tmp) >= 10 && stoi(tmp) <= 26) { // 2자릿수 범위안에 들어갈 경우 
				d[idx][1] = (d[idx - 2][0] + d[idx - 2][1]) % 1000000;
				if (d[idx][1] == 0) d[idx][1] = 1;
			}
			else if (stoi(tmp) == 0) { // 00 인 경우
				c = true;
				break;
			}
		}

		// 출력
		if (!c) res = (d[s.size()][0] + d[s.size()][1]) % 1000000;
		cout << res;
	}
}
