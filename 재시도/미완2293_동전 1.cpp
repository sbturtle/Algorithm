#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int coin;
		cin >> coin;

		if (coin <= k)
			vec.push_back(coin);
	}

	sort(vec.begin(), vec.end());

	long long result = 0;
	// 초기식

	// 점화식

	cout << result;
	return 0;
}