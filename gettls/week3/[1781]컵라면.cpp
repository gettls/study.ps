#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int n, day;
vector<pair<int, long long>> v;//<데드라인, 컵라면개수>
bool cmp(pair<int,int> a, pair<int, int> b) {
	return a.first > b.first;
}
int main() {
	vector<int> deadline;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	priority_queue<int> pq;
	int result = 0;
	int day = v[0].first;
	for (int i = 0, j = 0; i < v[0].first; i++) {
		while (j < n && v[j].first >= day) {
			pq.push(v[j++].second);
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
		day--;
	}
	cout << result;
} 