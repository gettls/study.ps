#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;


vector<char> alpha;
vector<int> index;

/*
	index : 조합 계산을 위한 배열
	alpha : 입력받은 문자 저장해서 index 배열로 접근
	==> {a,b,c,d}
	==> {0,0,1,1}, {0,1,0,1}, {0,1,1,0}, ....
*/

int main() {
	int l, c;

	scanf("%d%d", &l, &c);

	index.resize(c);
	for (int i = l; i < c; i++) index[i] = 1;
	// next_permutation 수행을 위한 오름차순 준비 

	for (int i = 0; i < c; i++) {
		char x;
		cin >> x;
		alpha.push_back(x);
	}
	// c 개의 알파벳 입력 받음

	sort(alpha.begin(), alpha.end());
	// 알파벳 순으로 정렬
	do {
		int a = 0, b = 0; // 자음, 모음
		string str;
		for (int i = 0; i < c; i++) {
			if (index[i] == 0) {
				if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i'
					|| alpha[i] == 'o' || alpha[i] == 'u') b++;
				else a++;
				str += alpha[i];
			}
		}
		// 모음과 자음의 조건이 부합하면 출력
		if (a >= 2 && b >= 1) cout << str << "\n";
	} while (next_permutation(index.begin(), index.end()));
}