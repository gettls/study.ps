#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int test_case;
	int x1, y1, r1, x2, y2, r2;
	cin >> test_case;

	while (test_case--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dist = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
		int result;

		// 무한개
		if (dist == 0 && r1 == r2) result = -1;
		// 0개 , 외접 || 내접
		else if ((r1 + r2) < dist || max(r1, r2) > min(r1, r2) + dist) result = 0;
		// 1개 , 외접 || 내접
		else if ((r1 + r2 == dist) || max(r1, r2) == min(r1, r2) + dist) result = 1;
		// 2개 , 외접 || 내접
		else if ((r1 + r2 > dist) || max(r1, r2) < min(r1, r2) + dist) result = 2;
		cout << result << "\n";		
	}
}