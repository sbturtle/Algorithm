#include <iostream>
using namespace std;

int dp[101][10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n;

	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}

			dp[i][j] %= 1'000'000'000;
		}
	}
	int result = 0;
	for (int i = 0; i <= 9; i++)
		result = (result + dp[n][i]) % 1'000'000'000;

	cout << result;

	return 0;
}