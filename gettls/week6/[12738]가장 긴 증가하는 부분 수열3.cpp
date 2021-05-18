#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;
int n;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (v.empty()) v.push_back(x);

		if (v.back() < x) {
			v.push_back(x);
		}
		else {
			vector<int>::iterator p;
			p = lower_bound(v.begin(), v.end(), x);
			*p = x;
		}
	}
	cout << v.size();
}