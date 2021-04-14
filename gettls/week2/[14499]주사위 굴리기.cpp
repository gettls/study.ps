#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
deque<int> dice_h, dice_v;
int n, m, pos_x, pos_y, x, y, k;
int arr[20][20];
//동서북남
int dx[4] = { 0,0,-1,1 }; //열
int dy[4] = { 1,-1,0,0 };//행
//dice_v
void move_north() {
	int bottom = dice_v.back();
	dice_v.pop_back();
	dice_v.push_front(bottom);
}
void move_south() {
	int x = dice_v.front();
	dice_v.pop_front();
	dice_v.push_back(x);
}
void syncHorizontal() {
	// vertical 2번째 원소 동기화
	dice_h.erase(dice_h.begin() + 1);
	dice_h.insert(dice_h.begin() + 1, dice_v[1]);
}

//dice_h.back-1 == dice_v.back
//dice_h
void move_east() {
	int bottom = dice_v.back();
	dice_v.pop_back();
	int x = dice_h.front();
	dice_h.pop_front();
	dice_h.push_back(bottom);
	dice_v.push_back(x);
}
void move_west() {
	int bottom = dice_v.back();
	dice_v.pop_back();
	int x = dice_h.back();
	dice_h.pop_back();
	dice_h.push_front(bottom);
	dice_v.push_back(x);
}
void syncVertical() {
	// horizontal 2번째 원소 동기화
	dice_v.erase(dice_v.begin() + 1);
	dice_v.insert(dice_v.begin() + 1, dice_h[1]);
}

bool move(int com) {
	int nx = pos_x + dx[com - 1], ny = pos_y + dy[com - 1];
	if (nx >= n || ny >= m || nx < 0 || ny < 0) return false;

	switch (com) {
	case 1:move_east(); syncVertical(); break;
	case 2:move_west(); syncVertical(); break;
	case 3:move_north(); syncHorizontal(); break;
	case 4:move_south(); syncHorizontal(); break;
	}

	// 칸이 0 인 경우
	if (arr[nx][ny] == 0) {
		arr[nx][ny] = dice_v.back();
	}

	// 칸이 0이 아닌 경우
	else {
		dice_v.pop_back();
		dice_v.push_back(arr[nx][ny]);
		arr[nx][ny] = 0;
	}
	pos_x = nx, pos_y = ny;
	return true;
}
// dice's bottom = deque_vertical's back
int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	pos_x = x, pos_y = y;
	for (int i = 0; i < 4; i++) {
		if (i != 0) dice_h.push_back(0); // 3개
		dice_v.push_back(0); //4개
	}
	for (int i = 0; i < k; i++) {
		int com;
		cin >> com;
		if(move(com))printf("%d\n", dice_h[1]);
	}
}