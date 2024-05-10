#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int isVis[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// ��ã�� ��� -1
	fill(isVis, isVis + 101, -1);

	// a���� ����Ͽ� b�� ����
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	while (c--)		// map ��� ����
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