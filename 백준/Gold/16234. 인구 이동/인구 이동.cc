#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int n, l, r;
int map[51][51];
bool isvis[51][51];
queue<pair<int, int>> q;

bool c = false;

void bfs(int x, int y) {
	vector<pair<int, int>> vec;
	q.push({ x,y });
	isvis[x][y] = true;

	int sum = map[x][y];
	vec.push_back({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (isvis[nx][ny])
				continue;
			int sub = abs(map[cur.X][cur.Y] - map[nx][ny]);
			if (sub < l || r < sub)
				continue;

			isvis[nx][ny] = true;

			sum += map[nx][ny];
			vec.push_back({ nx,ny });

			q.push({ nx,ny });
		}
	}

	if (vec.size() != 1)
		c = true;
	else
		return;
	

	int div = sum / vec.size();
	for (int i = 0; i < vec.size(); i++) {
		auto v = vec[i];
		map[v.X][v.Y] = div;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int result = 0;

	while (true) {
		c = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isvis[i][j])
					continue;
				bfs(i, j);
			}
		}
		if (!c)
			break;

		for (int i = 0; i < n; i++)
			fill(isvis[i], isvis[i] + n, false);

		result++;
	}

	cout << result;

	return 0;
}