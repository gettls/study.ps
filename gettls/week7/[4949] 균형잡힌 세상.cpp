#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#pragma warning (disable:4996)
using namespace std;

// no 의 조건
// 1. 여는 괄호 후에 짝이 안맞는 닫는 괄호 발견
// 2. 여는 괄호와 닫는 괄호의 개수가 다른 경우
int main() {
	string s;
	while (1) {
		stack<char> stack;
		bool c = true;
		getline(cin, s);
		if (s.front() == '.') break;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				stack.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']') {
				if (stack.empty()) {
					c = false;
					break;
				}
				char ch = stack.top();
				if ((ch == '(' && s[i] == ']')
					|| (ch == '[' && s[i] == ')')) {
					c = false;
					break;
				}
				stack.pop();
			}
		}
		if (!stack.empty()) c = false;
		if (c) cout << "yes" << endl;
		else cout << "no" << endl;
	}

}