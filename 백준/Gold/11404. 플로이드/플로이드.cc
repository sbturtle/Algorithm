#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int d[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fill(d[i], d[i] + 1 + n, INF);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);		// 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
	}
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				// 시간 복잡도 상으로 생각했을 경우 대입보다 연산이 빠름
				// d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

				// 따라서 아래처럼 하는 것이 시간복잡도 상 유리
				// 특히 해당 문제처럼 대입이 많은 경우 
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) cout << "0 ";
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
