#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int n, t;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		
		sort(v.begin(), v.end());
		int c = 0;
		for (int i = 0; i < n - 1; i++) {
			string now = v[i];
			string next = v[i + 1];
			if (now.length() > next.length()) continue;
			if (next.substr(0, now.size()) == now) {
				c = 1;
			}
		}
		if (c) printf("NO\n");
		else printf("YES\n");
	}
}