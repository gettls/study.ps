#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;

int n;
vector<long long> v,e;
int main() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		long long x;
		cin >> x;
		e.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}
	long long result = v[0] * e[0];
	long long last = v[0];
	for (int i = 1; i < e.size(); i++) {
		if (last > v[i]) last = v[i];
		result += last * e[i];
	}
	cout << result;
} 