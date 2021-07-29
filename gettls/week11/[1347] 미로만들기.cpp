#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;

//동 남 서 북
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
char arr[101][101];
int dir = 1;
int main() {
	int n, x, y;
	int lx, rx, ly, ry;
	x = y = lx = rx = ly = ry = 50;
	cin >> n;
	cin.ignore();
	memset(arr, '#', sizeof(arr));
	arr[x][y] = '.';
	for (int i = 0; i < n; i++) {
		char cmd;
		scanf("%c", &cmd);
		switch (cmd) {
		case 'R': dir = (dir + 1) % 4; break;
		case 'L': dir = (dir + 3) % 4; break;
		case 'F': 
			x += dx[dir];
			y += dy[dir];
			if (lx > x) lx = x;
			if (ly < y) ly = y;
			if (rx < x) rx = x;
			if (ry > y) ry = y;
			arr[y][x] = '.';
			break;
		}
	}
	for (int i = min(ry,ly); i <= max(ry,ly); i++) {
		for (int j = min(rx,lx); j <= max(rx,lx); j++)
			cout << arr[i][j];
		cout << "\n";
	}

}