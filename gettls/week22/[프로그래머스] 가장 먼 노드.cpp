#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> d;
vector<vector<pair<int, int>>> v;
int m = -1;
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    d[start] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if (d[cur] < dist) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextDist = v[cur][i].second + dist;
            if (nextDist < d[next]) {
                d[next] = nextDist;
                if (d[next] > m) m = d[next];
                pq.push({ -nextDist,next });
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    d.resize(n + 1);
    v.resize(n + 1);
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        v[a].push_back({ b,1 });
        v[b].push_back({ a,1 });
    }
    for (int i = 1; i <= n; i++) d[i] = 987654321;
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        if (d[i] == m) answer++;
    }

    return answer;
}

int main() {
    vector<vector<int>> e{ {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} };

    solution(6, e);
}