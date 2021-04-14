#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;

int n;
vector<string> v;
int alpha[26];
int result = 0;
void sol() {
	for (int i = 0; i < v.size(); i++) {
		int cnt = v[i].size() - 1;
		for (int j = 0; j < v[i].size(); j++) {
			alpha[v[i][j] - 'A'] += pow(10, cnt--);
		}
	}
	sort(alpha, alpha + 26, greater<int>());
	int cnt = 9;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) break;
		result += alpha[i] * (cnt--);
	}
}

int main() {
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		v.push_back(s);
	}
	sol();
	printf("%d", result);
}