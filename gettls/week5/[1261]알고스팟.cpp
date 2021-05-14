#include<stdio.h>
#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
 
int n, m;
int arr[101][101], d[101][101];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };


void sol() {
	priority_queue<pair<int,pair<int, int>>> q;
	q.push({ 0,{0,0} });

	while (!q.empty()){
		int x = q.top().second.first;
		int y = q.top().second.second;
		int dist = -q.top().first;
		if (x == m - 1 && y == n - 1) return;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nextDist = dist + arr[nx][ny];
			if (nx < 0 || ny < 0 || nx >= m  || ny >= n ) continue;
			if (nextDist < d[nx][ny]) {
				q.push({ -nextDist,{nx,ny} });
				d[nx][ny] = nextDist;
			}			
		}
	}
}



int main(){
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		fill(d[i], d[i] + n, 1e9);
	}
	d[0][0] = 0;
	sol();
	cout << d[m - 1][n - 1];
}