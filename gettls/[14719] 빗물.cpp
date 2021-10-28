#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int H, W;
int arr[500][500];

int main() {
	cin >> H >> W;

	for (int i = 0; i < W; i++) {
		int x; cin >> x;
		for (int j = H - x; j < H; j++) {
			arr[j][i] = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < H; i++) {
		int cnt = 0;
		int flag = 0;
		for (int j = 0; j < W; j++) {
			if (arr[i][j] == 1) {
				if (cnt == 0) {
					flag = 1;
				}
				else if (cnt > 0 && flag == 0) {
					cnt = 0;
					flag = 1;
				}
				else if (cnt > 0 && flag == 1) {
					sum += cnt;
					flag = 1, cnt = 0;
				}
			}
			else {
				cnt++;
			}
		}
	}

	cout << sum;
}