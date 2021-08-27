#include <string>
#include <vector>
#include <queue>
using namespace std;

// µ¿ ³² ¼­ ºÏ
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0,1,0,-1 };
int pay[25][25];

int bfs(vector<vector<int>> board, int d) {
    int n = board.size();
    for (int i = 0; i < n; i++)
        fill(pay[i], pay[i] + board.size(), 1e9);

    queue<pair<pair<int, int>, int>> q; // (x,y), dir
    q.push({ { 0,0 },d });
    pay[0][0] = 0;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ndir = (dir + i) % 4;
            int nx = x + dx[ndir], ny = y + dy[ndir];
            int cost;
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[ny][nx] == 1) continue;

            if (ndir == dir) cost = 100;
            else cost = 600;

            if (pay[ny][nx] >= pay[y][x] + cost) {
                pay[ny][nx] = pay[y][x] + cost;
                q.push({ {ny,nx}, ndir });
            }

        }
    }

    return pay[n - 1][n - 1];
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = min(bfs(board, 1), bfs(board, 0));
    return answer;
}