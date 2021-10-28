#include <string>
#include <vector>
#include <iostream>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

int N, M, H, a, b;
// 세로선, 가로선, 개수
int c[11]; // 설치 가능 개수
int ladder[31][11];
int ans = 1e9;

bool isDirected(int num) {
	int target = num;
	for (int i = 1; i <= H; i++) {
		if (ladder[i][num] == 1) num++;
		else if (ladder[i][num] == -1) num--;
	}
	if (num == target) return true;
	else return false;
}

void dfs(int cnt,int idx) {
  	if (cnt <= 3) {
		int flag = 0;
        // 연결 확인
		for (int i = 1; i <= N; i++) {  
			if (!isDirected(i)) {
				flag = 1;
				break;
			}
		}
        // 이동 불가 시 다리 설치
		if (flag) {
			if (cnt != 3) {
				for (int i = idx + 1; i <= N * H; i++) {
					int x = i / N + 1;
					int y = i % N;
					if (y == 0) continue;

					if (ladder[x][y] == 0 && ladder[x][y + 1] == 0
						&& c[y] > 0 && c[y + 1] > 0) {
                        //설치
						ladder[x][y] = 1;
						ladder[x][y + 1] = -1;
						c[y]--; c[y + 1]--;
						dfs(cnt + 1, i);
                        //철거
						ladder[x][y] = 0;
						ladder[x][y + 1] = 0;
						c[y]++; c[y + 1]++;
					}
				}
			}
		}
        // 이동 가능 시 ans 최솟값으로 갱신
		else {
			ans = min(ans, cnt);
		}
	}
}
int main() {
	cin >> N >> M >> H;

	fill(c, c + N + 1, H); // 연결 가능 개수

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		ladder[a][b] = 1; // 우 방향
		ladder[a][b + 1] = -1; // 좌 방향
		c[b]--; c[b + 1]--; 
	}

	dfs(0, 0);

	if (ans == 1e9) ans = -1;
	cout << ans;
}