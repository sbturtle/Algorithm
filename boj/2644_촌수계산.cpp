#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int isVis[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 못찾을 경우 -1
	fill(isVis, isVis + 101, -1);

	// a에서 출발하여 b로 도착
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	while (c--)		// map 경로 설정
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	queue<int> q;
	q.push(a);
	isVis[a] = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[cur][i] && isVis[i] == -1) {
				isVis[i] = isVis[cur] + 1;
				q.push(i);
			}
		}
	}

	cout << isVis[b];
	return 0;
}