#include<iostream>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int n;
	cin >> n;
	long long dp_0[91], dp_1[91];
	dp_0[1] = 0, dp_1[1] = 1;
    //dp_0[n] : n 자리가 0 으로 끝나는 수의 개수
    //dp_1[n] : n 자리가 1 으로 끝나는 수의 개수 
	for (int i = 2; i <= n; i++) {
		dp_0[i] = dp_1[i - 1] + dp_0[i - 1];
		dp_1[i] = dp_0[i - 1];
	}
    //dp_0[n] : n-1 의 자리에 오는 수가 0, 1 둘 다 가능 
    //dp_1[n] : n-1 의 자리에 오는 수가 0 만 가능
	cout << dp_0[n] + dp_1[n];
}