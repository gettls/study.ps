#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
int n;


int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		string str = to_string(i);		
		int c = 1, diff;
		for (int j = 0; j < str.size()-1; j++) {
			if (j == 0) diff = str[j+1] - str[j];
			if (diff != str[j + 1] - str[j]) {
				c = 0;
				break;
			}
		}
		if (c) cnt++;
	}
	cout << cnt;
}
