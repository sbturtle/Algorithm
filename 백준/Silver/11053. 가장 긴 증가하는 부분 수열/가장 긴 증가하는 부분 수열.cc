#include <iostream>
#include <vector>
using namespace std;

int n;
int result;
int dp[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> vec(n);

	for (size_t i = 0; i < n; i++) {
		cin >> vec[i];
		int mx = 0;
		for (int j = 1; j < vec[i]; j++) {
			if (dp[j] > mx)
				mx = dp[j];
		}
		dp[vec[i]] = ++mx;
		result = max(result, mx);
	}

	cout << result;

	return 0;
}