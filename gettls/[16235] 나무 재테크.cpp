#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
// 초기 양분은 5
// 봄: 나이만큼 양분 -, 나이 +1, 나이가 어린 나무부터 먹음, 못먹으면 죽음
// 여름: 봄에 죽은 나무가 양분으로 변함, 양분 = 죽은 나무의 나이/2
// 가을: 나이가 5의 배수인 나무들 번식, 인접한 칸에 나이가 1인 나무 생김
// 겨울: S2D2가 양분 추가


int N, M, K;
int arr[10][10], nutrient[10][10];
int dx[] = { 0,-1,-1,-1,0,1,1,1 }, dy[] = { -1,-1,0,1,1,1,0,-1 };
vector<int> tree[10][10];


void nourish(int x, int y, int n) {
	nutrient[x][y] -= n;
}

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tree[i][j].size() > 1) sort(tree[i][j].begin(), tree[i][j].end());
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (nutrient[i][j] >= age && age > 0) { // 먹을 수 있는 경우
					nourish(i, j, age);
					tree[i][j][k]++;
				}
				else if (nutrient[i][j] < age) { // 못먹으면 죽음
					tree[i][j][k] = -age;
				}
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] < 0) {
					nourish(i, j, (tree[i][j][k] / 2));
					tree[i][j].erase(tree[i][j].begin() + k);
					k--;
				}
			}
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						int nx = i + dx[l], ny = j + dy[l];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nutrient[i][j] += arr[i][j];
		}
	}
}
int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			nutrient[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}

	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tree[i][j].size() > 0)  cnt += tree[i][j].size();
		}
	}

	cout << cnt;
}