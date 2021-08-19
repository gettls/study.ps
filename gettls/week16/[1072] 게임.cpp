#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;

int main() {
	ll x, y;
	cin >> x >> y;
	ll z = y * 100 / x;
	ll ans = -1;
	ll s = 1, e = x;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll rate = ((y + mid) * 100) / (x + mid);
		if (rate - z >= 1) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans;
}