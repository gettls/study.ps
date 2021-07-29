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


int main() {
	string str;
	stack<char> s;
	cin >> str;

	for (int i = 0; i < str.size(); i++) s.push(str[i]);
	int cnt = 0;
	while (!s.empty()) {
		char c = s.top();
		s.pop();
		if (c == '=') {
			char a = s.top();
			s.pop();
			if (a == 'z') { // z=
				if (s.empty()) {
					cnt++;
					break;
				}
				char b = s.top();
				if (b == 'd') { // dz=
					s.pop();
					cnt++;
				}
				else cnt++; // z=
			}
			else if (a == 'c' || a == 's')  //c=, s=
				cnt++;
		}
		else if (c == '-') {
			char a = s.top();
			s.pop();
			// d-, c-
			cnt++;
		}
		else if (c == 'j') {
			if (s.empty()) {
				cnt++;
				break;
			}
			char a = s.top();
			if (a == 'l' || a == 'n') {// nj, lj
				s.pop();
				cnt++;
			}
			else cnt++;
		}
		else {
			cnt++;
		}
	}
	cout << cnt;
}