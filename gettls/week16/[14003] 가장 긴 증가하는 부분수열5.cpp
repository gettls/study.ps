#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int index[1000000];
int num[1000000];
int main() {
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(1e9);
	vector<int>::iterator p;

	int max_idx = -1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num[i] = x;
		if (v.back() < x) {
			v.push_back(x);
			index[i] = v.size() - 1;
		}
		else {
			p = lower_bound(v.begin(), v.end(), x);
			*p = x;
			index[i] = p - v.begin();
		}
		if (max_idx < index[i]) max_idx = index[i];
	}
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		if (index[i] == max_idx) {
			s.push(num[i]);
			max_idx--;
		}
	}
	printf("%d\n", s.size());
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}

}