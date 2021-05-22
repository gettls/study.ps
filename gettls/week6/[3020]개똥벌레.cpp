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
          // 1~h 까지의 구간(i)을 탐색한다
          // i 번째 구간에서 걸리는 장애물의 개수를 count 하는데
          // h = 5 일 때, 
          // 석순의 경우 i 의 길이와 같거나 더 큰 석순의 개수를 센다. 예를 들어  i가 3이면, 길이가 3,4,5인 석순의 개수를 세는 식
          // 종유석의 경우 h - i의 길이보다 큰 종유석의 개수를 세야 한다. 즉, i가 3이면 종유석은 4,5 인 종유석의 개수
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