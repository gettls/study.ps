#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(1e9);
	vector<int>::iterator p;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (v.back() < x) {
			v.push_back(x);
		}
		else {
			p = lower_bound(v.begin(), v.end(), x);
			*p = x;
		}
	}
	cout << v.size();
}