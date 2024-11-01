#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define X first
#define Y second

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> isvis(n, vector<int>(m, -1));
	queue<pair<int, int>> q;

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 1) {
				if (map[i][j] == 2)
					q.push({ i,j });
				isvis[i][j] = 0;
			}
		}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (0 > nx || nx >= n || 0 > ny || ny >= m)
				continue;
			if (isvis[nx][ny] != -1)
				continue;

			isvis[nx][ny] = isvis[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++)
			cout << isvis[i][j] << ' ';

		cout << '\n';
	}

	return 0;
}