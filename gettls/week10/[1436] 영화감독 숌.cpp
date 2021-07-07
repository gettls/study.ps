#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;


int n;
int main() {
	cin >> n;
	int x = 666;
	while (1) {
		string str = to_string(x);
		for (int i = 2; i < str.length(); i++) {
			if (str[i - 2] == '6' && str[i - 1] == '6' && str[i] == '6') {
				n--;
				break;
			}  
		}
		if (n == 0) break;
		x++;
	}
	cout << x;
}