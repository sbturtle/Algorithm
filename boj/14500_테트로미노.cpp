#include <iostream>
using namespace std;

#define X first
#define Y second

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int n, m;
int result = -1;
int map[501][501];
bool isvis[501][501];
// 6,400,000

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		result = max(result, sum);
		return;
		if (sum == 23)
			cout << sum;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (isvis[nx][ny])
			continue;
		isvis[nx][ny] = true;
		dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
		isvis[nx][ny] = false;
	}
}
void RotateT(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		int sum = map[x][y];
		for (int j = 0; j < 4; j++)
		{
			if (i == j)		// 3방향만 필요 ㅗ ㅏ ㅜ ㅓ
				continue;

			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			sum += map[nx][ny];
		}
		result = max(result, sum);
			
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			dfs(i, j, 0, 0);
			RotateT(i, j);
		}

	cout << result;

	return 0;
}