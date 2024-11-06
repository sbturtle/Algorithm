#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dp[1001] = {};
	int n;
	cin >> n;
	vector<int> vec(n);
	int result = -1;

	for (int i = 0; i < n; i++) {
		int mx = 0;
		cin >> vec[i];
		for (int j = 1; j < vec[i]; j++) {
			if (dp[j] > mx)
				mx = dp[j];
		}
		mx += vec[i];
		dp[vec[i]] = mx;
		result = max(result, mx);
	}

	cout << result;

	return 0;
}