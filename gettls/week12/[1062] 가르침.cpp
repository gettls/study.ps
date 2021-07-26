#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int n, k, used[26];
int ans;
vector<string> arr;


void dfs(int cnt, int index) {
	if (cnt == k) {
		int ret = 0;
		for (int i = 0; i < arr.size(); i++) {
			int c = 0;
			for (int j = 0; j < arr[i].size(); j++) {
				if (used[arr[i][j]-'a'] == 0) {
					c = 1;
					break;
				}
			}
			if (!c) 
				ret++;
		}
		if (ret > ans) ans = ret;
		return;
	}

	for (int i = index; i < 26; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(cnt + 1, i+1);
		used[i] = 0;
	}
}

int main() {
	cin.tie(0);
	cin >> n >> k;
	//a,n,t,i,c
	used['a' - 'a'] = used['n' - 'a'] = 1;
	used['t' - 'a'] = used['i' - 'a'] = used['c' - 'a'] = 1;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		string str;
		cin >> str;
		arr.push_back(str);
	}

	if (k >= 5) dfs(5, 0);
	cout << ans;
}   