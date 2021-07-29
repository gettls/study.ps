#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
set<string> s;
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (b == "enter") 
			s.insert(a);
		else 
			s.erase(a);
	}
	vector<string> v(s.begin(), s.end());
	sort(v.begin(), v.end(), greater<>());
	for (auto i : v) cout << i << "\n";

}