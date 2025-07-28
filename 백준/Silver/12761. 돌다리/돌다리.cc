#include <iostream>
#include <queue>
using namespace std;

int map[100'004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n, m;

	cin >> a >> b >> n >> m;

	fill(map, map + 100'004, -1);

	int dx[] = { 1,-1,a,b,-a,-b };

	queue<int> q;
	q.push(n);
	map[n] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = cur;
			if (i == 6)
				nx *= a;
			else if (i == 7)
				nx *= b;
			else
				nx += dx[i];

			if (nx < 0 || nx > 100'000)
				continue;
			if (map[nx] != -1)
				continue;

			map[nx] = map[cur] + 1;

			if (nx == m)
				goto label;

			q.push(nx);
		}
	}

label:
	cout << map[m];

	return 0;
}
