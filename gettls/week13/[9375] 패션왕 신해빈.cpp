#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
vector<pair<string, int>> v;
int tc, n, ret;

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			string cloth, kind;
			cin >> cloth >> kind;
			if (m.find(kind) != m.end()) {
				m[kind] ++;
			}
			else {
				m.insert({ kind, 1 });
			}
		}
		vector<pair<string, int>> t;
		v.swap(t);
		for (auto i : m)	v.push_back({ i.first, i.second });
		ret = 1;

		for (int i = 0; i < v.size(); i++) {
			ret *= (v[i].second + 1);
		}

		ret--;
		cout << ret << "\n";
	}
}