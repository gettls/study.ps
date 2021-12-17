#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int v[5][5];
char arr[5][5];

bool bfs(int a, int b) {
    int v[5][5] = { 0 };
    queue<pair<pair<int, int>, int>> q;
    q.push({ { a,b }, 0 });
    v[a][b] = 1;
    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (arr[nx][ny] == 'X' || v[nx][ny]) continue;
            v[nx][ny] = 1;
            if (arr[nx][ny] == 'P' && c + 1 <= 2) return false;
            q.push({ { nx,ny }, c + 1 });
        }
    }
    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    answer.resize(5);
    for (int i = 0; i < places.size(); i++) {

        for (int j = 0; j < places[i].size(); j++) {
            string str = places[i][j];
            for (int k = 0; k < 5; k++) arr[j][k] = str[k];
        }

        int c = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (arr[j][k] == 'P') {
                    if (!bfs(j, k)) {
                        answer[i] = 0;
                        c = 1;
                        break;
                    }
                }
            }
            if (c) break;
            else answer[i] = 1;
        }
    }
    return answer;
}