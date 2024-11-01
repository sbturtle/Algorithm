#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int map[65][65];
bool isvis[65][65];
// 64 * 64 * 64 = 262,144
// 1,073,741,824

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1,0 };

int n, m;
int epCount;
int result = -1;
vector<pair<int, int>> ep;
vector<pair<int, int>> virus;

int SafePlace() {
	int sp = 0;
	for (auto p : ep) {
		if (map[p.X][p.Y] == 0 && !isvis[p.X][p.Y])
			sp++;
	}

	return sp;
}

void init() {
	for (int i = 0; i < n; i++)
		fill(isvis[i], isvis[i] + m, false);
}

void Bfs() {
	queue<pair<int, int>> q;
	for (auto v : virus)
		q.push(v);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (isvis[nx][ny] || map[nx][ny] != 0)
				continue;
			isvis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	result = max(result, SafePlace());
	if (result == 32)
	{
		cout << '\n';
	}
	init();

}

void WallGenerator() {
	for (int i = 0; i < epCount; i++)
	{
		map[ep[i].X][ep[i].Y] = 1;

		for (int j = i + 1; j < epCount; j++)
		{
			map[ep[j].X][ep[j].Y] = 1;

			for (int k = j + 1; k < epCount; k++)
			{
				map[ep[k].X][ep[k].Y] = 1;
				Bfs();
				map[ep[k].X][ep[k].Y] = 0;
			}
			map[ep[j].X][ep[j].Y] = 0;
		}
		map[ep[i].X][ep[i].Y] = 0;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				ep.push_back({ i,j });
			else if (map[i][j] == 2)
				virus.push_back({ i,j });
		}
	}

	epCount = ep.size();
	WallGenerator();

	cout << result;
	return 0;
}