#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;



int main() {
	string str;
	stack<char> s;
	getline(cin, str);

	int c = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << str[i];
			c = 1;
		}
		else if (str[i] == '>') {
			cout << str[i];
			c = 0;
		}
		else if (c) {
			cout << str[i];
		}
		else {
			if (str[i] == ' ') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << str[i];
			}
			else {
				s.push(str[i]);
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}
