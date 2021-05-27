#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int n, res=0;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string s;
		vector<char> v;
		cin >> s;
		int cnt = 0;
		bool c = true;
		for (int j = 0; j < s.size(); j++) {
			if (j > 0 && s[j] != s[j - 1]) {
				for (int k = 0; k < v.size(); k++) {
					if (v[k] == s[j]) {
						c = false;
						break;
					}
				}
			}
			v.push_back(s[j]);
		}
		if (c) res++;
	}
	cout << res;
}