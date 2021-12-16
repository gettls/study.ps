#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int> pq;
    queue<int> q;
    queue<int> idx;

    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push(priorities[i]);
        idx.push(i);
    }
    while (!pq.empty()) {
        int cur = q.front();
        int i = idx.front();
        while (cur != pq.top()) {
            q.push(q.front());
            idx.push(idx.front());
            q.pop();
            idx.pop();
            cur = q.front();
            i = idx.front();
        }
        pq.pop();
        q.pop();
        idx.pop();
        answer++;
        if (i == location) break;
    }


    return answer;
}