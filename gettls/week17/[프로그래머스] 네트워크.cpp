#include <string>
#include <vector>
#include <queue>
using namespace std;
int check[200];

void bfs(int x, vector<vector<int>> v) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size();i++) {
            if (!check[i] && v[cur][i] == 1) {
                check[i] = 1;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            bfs(i, computers);
            answer++;
        }
    }

    return answer;
}
