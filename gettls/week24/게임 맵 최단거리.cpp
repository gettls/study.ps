#include<vector>
#include<queue>
using namespace std;
int n, m;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int d[100][100];
vector<vector<int>> arr;
void dfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = 1e9;
        }
    }
    d[0][0] = 1;
    q.push({ 0,0 });

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 0) continue;
            if (d[nx][ny] > d[x][y] + 1) {
                q.push({ nx,ny });
                d[nx][ny] = d[x][y] + 1;
            }
        }
    }

}

int solution(vector<vector<int> > maps)
{
    arr = maps;
    n = maps.size(), m = maps[0].size();
    int answer = 0;
    dfs();
    if (d[n - 1][m - 1] == 1e9) d[n - 1][m - 1] = -1;
    return d[n - 1][m - 1];
}


int main() {
    solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} });
}