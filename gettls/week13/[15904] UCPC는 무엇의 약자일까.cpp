#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
#pragma warning (disable:4996)
int main() {

	string str;
	getline(cin, str);
	string arr = "UCPC";
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == arr[j]) j++;
	}
	if (j == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
}