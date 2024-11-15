#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, r;
int d[102][102];
int t[101];		// 각 구역에 있는 아이템의 수
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + 1 + n, INF);		// 경로 초기화
		d[i][i] = 0;

		cin >> t[i];
	}

	while (r--) {
		int a, b, l;
		cin >> a >> b >> l;
		d[a][b] = l;
		d[b][a] = l;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	int result = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j] <= m)
				sum += t[j];
		}
		result = max(result, sum);
	}
	cout << result;

	return 0;
}
