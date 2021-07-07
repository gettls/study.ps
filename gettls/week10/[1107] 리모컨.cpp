#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;

int broken[10];
vector<int> v;
int n, dist;
/*
* 초기 채널 100에서 n으로 가는 최소의 수를 찾는 경우의 수는 다음과 같다.
* 1. 100 에서 바로 n으로 가는 경우
* 2. 100 -> x -> n : 즉 x 번 입력 후 n으로 이동 
* => 고장나지 않은 번호들로 만들수 있는 수 x 를 완전탐색으로 서치
* => (2)번의 경우 (x의 자릿수) + (from x to n) 와 (from 100 to n) 비교
* => (2)번의 경우 x 의 값은 n/10 or n*10 의 자릿수에서 나온다.
*/

void sol(int x, int cnt) {
	// 완전탐색은 x 의 자릿수가 1 ~ n+1 의 범위 내에 있을때만 수행
	if (cnt > to_string(n).length() + 1) return;

	// from 100 to n 과 from x to n 비교
	// 주의: 후자의 경우 x 를 입력할 때의 횟수를 포함해야 함
	if (abs(100 - n) > abs(x - n) + to_string(x).size()) {
		int d = abs(x - n) + to_string(x).size();
		if (dist > d) dist = d;
	}

	for (int i = 0; i < v.size(); i++) {
		sol(10 * x + v[i], cnt + 1);
	}
}

int main() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = 1;
	}
	for (int i = 0; i < 10; i++) {
		if (broken[i] == 0)v.push_back(i);
	}

	// dist 의 초기값은 from 100 to n
	dist = abs(n - 100);
	for (int i = 0; i < v.size(); i++) {
		sol(v[i], 1);
	}
	cout << dist;
}