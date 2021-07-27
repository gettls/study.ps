#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
vector<string> a;
set<string> b;
int n, m;
int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		string tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin.ignore();
		string tmp;
		cin >> tmp;
		b.insert(tmp);
	}
	vector<string> ret;
	for (int i = 0; i < n; i++) {
		string str = a[i];
		// 없음
		if (b.find(a[i]) != b.end()) ret.push_back(a[i]);
	}
	sort(ret.begin(), ret.end());
	printf("%d\n", ret.size());
	for (auto it : ret) cout << it << "\n";
}