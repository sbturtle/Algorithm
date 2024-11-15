#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int k;
int c[204];
int d[204][204];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + 1 + n, INF);		// 경로 초기화
		d[i][i] = 0;
	}

	while (m--) {
		int a, b, l;
		cin >> a >> b >> l;
		d[a][b] = l;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> c[i];

	for (int w = 1; w <= n; w++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][w] + d[w][j])
					d[i][j] = d[i][w] + d[w][j];

	int r[204] = {};	// 왕복시간
	int ms = 1200000000;
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		// 왕복 시간들의 최대값 구하기
		for (int j = 0; j < k; j++)
			if (mx < d[i][c[j]] + d[c[j]][i])
				mx = d[i][c[j]] + d[c[j]][i];	// 왕복 계산

		if (ms > mx)
			ms = mx;	// 최대의 왕복시간 중 최단시간

		r[i] = mx;
	}

	for (int i = 1; i <= n; i++)
		if (ms == r[i])
			cout << i << ' ';

	return 0;
}
