#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

map<string, int> m;

int main() {
	int cnt = 0;
	while (1) {
		string str;
		getline(cin, str);
		if (cin.eof() == true) break;
		auto it = m.find(str);
		if (it != m.end()) m[str]++;
		else m.insert({ str,1 });
		cnt++;
	}
	for (auto iter : m) {
		cout << iter.first << " ";
		printf("%.4f\n", (double)iter.second * 100 / cnt);
	}

}