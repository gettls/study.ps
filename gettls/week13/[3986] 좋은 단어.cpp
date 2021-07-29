#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		stack<char> s;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (s.empty()) {
				s.push(str[i]); continue;
			}

			if (s.top() == str[i]) s.pop();
			else s.push(str[i]);
		}

		if (s.empty()) cnt++;

	}
	cout << cnt;
}