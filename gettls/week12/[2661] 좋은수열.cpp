#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int n;
string x;

bool check() {
	for (int i = 0; i < x.size() / 2; i++) {
		string tmp1 = x.substr(x.size() -1 - i, i + 1);
		string tmp2 = x.substr(x.size() - 1 - (2 * i + 1), i + 1);
		if (tmp1 == tmp2) return false;
	}
	return true;
}


void dfs(int cnt) {
	
	if (cnt == n) {
		cout << x;
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		x.push_back('0' + i);
		if(check())
			dfs(cnt + 1);
		x.pop_back();
	}

}

int main() {
	cin >> n;
	dfs(0);
}