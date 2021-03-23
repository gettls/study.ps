#include <iostream>
#include <string>
#include <queue>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int t, n;
//R :: 뒤집기 , D 삭제
int main() {
	scanf("%d", &t);
	while (t--) {
		string num, p;
		deque<int> dq;
		cin >> p >> n >> num;
		string temp;

		for (int i = 0; i < num.size(); i++) {
			if (num[i] == '[' || num[i] == ']' || num[i] == ',') {
				if (temp.size() != 0) {
					dq.push_back(atoi(temp.c_str()));
				}
				temp = "";
			}
			else {
				temp += num[i];
			}
		}

		int reverse = 1; // -1 : 뒤집힌 상태, 0 : error
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {//뒤집기
				reverse *= -1;
			}
			else if (p[i] == 'D') {//삭제
				if (dq.size() == 0) {
					reverse = 0;
					break;
				}
				if (reverse == 1)dq.pop_front(); //뒤집히지 않은 상태
				else dq.pop_back(); //뒤집힌 상태
			}
		}

		if (reverse == 1) {
			printf("[");
			for (int i = 0; i < dq.size(); i++) {
				printf("%d", dq[i]);
				if (i != dq.size() - 1) printf(",");
			}
			printf("]\n");
		}
		else if (reverse == -1) {
			printf("[");
			for (int i = dq.size() - 1; i >= 0; i--) {
				printf("%d", dq[i]);
				if (i != 0) printf(",");
			}
			printf("]\n");
		}
		else printf("error\n");
	}
}