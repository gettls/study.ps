#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <string.h>
#include <set>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int N, M, B;
vector<int> list;

int stablize(int level) {
	int ret = 0;
	int cnt = B;
	bool flag = true;

	for (auto i : list) {

		if (i > level) { // 제거
			ret += (i - level) * 2;
			cnt += (i - level);
		}

		if (i < level) {
			if (cnt - (level - i) < 0) {
				flag = false;
				break;
			}
			ret += (level - i);
			cnt -= (level - i);
		}
	}


	if (flag) return ret;
	else return 1e9;
}

int main() {
	cin >> N >> M >> B;
	set<int> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x;
			cin >> x;
			list.push_back(x);
		}
	}
	sort(list.begin(), list.end(), greater<>());
	int cnt = 1e9, height = 0;
	for (int i = 0; i <= 256; i++) {
		int t = stablize(i);
		if (cnt > t) {
			cnt = t;
			height = i;
		}
		else if (cnt == t && height < i) height = i;
	}

	printf("%d %d", cnt, height);
}