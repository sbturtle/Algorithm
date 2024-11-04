#include <iostream>
#include <vector>
using namespace std;

#define W first
#define V second
int n, k;

int dp[101][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	vector<pair<int, int>> p(n + 1);

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;
		p[i] = { w,v };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= p[i].W)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i].W] + p[i].V);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}


	cout << dp[n][k];


	return 0;
}