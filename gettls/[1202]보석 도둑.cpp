#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int n, k;
vector<pair<int, int>> jewerly; 
vector<long long> bag;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jewerly.push_back({ m,v });
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.push_back(c);
	}

	sort(jewerly.begin(), jewerly.end());
	sort(bag.begin(), bag.end());

	priority_queue<long long> pq;
	long long result = 0;
	for (int i = 0, j = 0 ; i < k; i++) {
		while (j<n && bag[i]>=jewerly[j].first) {
			pq.push(jewerly[j++].second);
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;
} 