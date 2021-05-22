#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


int n, h;
vector<int> a,b;
int main() {
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (i % 2 == 0) a.push_back(x);
		else b.push_back(x);
	}
	
	sort(a.begin(), a.end()); // 석순
	sort(b.begin(), b.end()); // 종유석
	int res = 1e9, res_cnt = 1;

  	for (int i = 1; i <= h; i++) {

		int cnt = a.end() - lower_bound(a.begin(), a.end(), i);
		cnt += b.end() - upper_bound(b.begin(), b.end(), h - i);

		
		if (cnt < res) {
			res = cnt;
			res_cnt = 1;
		}
		else if (cnt == res) {
			res_cnt++;
		}
	}
	cout << res << " " << res_cnt;
}