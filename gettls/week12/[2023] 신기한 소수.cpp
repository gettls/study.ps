#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)


int n;
string str;

bool check() {
	for (int i = 0; i < str.size(); i++) {
		string tmp = str.substr(0, str.size() - i);
		int x = stoi(tmp);
		if (x == 1) return false;
		for (int j = 2; j < x; j++) {
			if (x % j == 0) return false;
		}
	}
	return true;
}

void dfs(int cnt, int index) {
	if (cnt == n){
		cout << str << "\n";
		return;
	}

	for (int i = 1; i <= 9; i ++) {
		str.push_back('0' + i);
		if(check()) 
			dfs(cnt + 1, index + 1);
		str.pop_back();
	}
}

int main() {
	cin >> n;
	dfs(0, 0);
}