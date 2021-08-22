#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int n, m, tc;
int C[30][30];
int main() {
	cin >> tc;

	for (int i = 1; i < 30; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 2; i < 30; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	while (tc--) { // ==> mCn 
		cin >> n >> m;

		cout << C[m][n];

	}
}
