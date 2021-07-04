#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;

char res[1000001];

int main() {
	string arr, bomb;
	cin >> arr >> bomb;
	int index = 0;
	for (int i = 0; i < arr.size(); i++) {
		res[index++] = arr[i];
		if (arr[i] == bomb[bomb.size() - 1]
			&& index >= bomb.size()) {
			int c = 1;
			for (int j = 0; j < bomb.size(); j++) {
				if (res[index - 1- j] != bomb[bomb.size() - 1 - j]) {
					c = 0;
					break;
				}
			}
			if (c) { // 일치 한다면
				index -= bomb.size();
			}
		}
	}
	res[index] = '\0';
	if (index == 0) cout << "FRULA";
	else cout << res;
}