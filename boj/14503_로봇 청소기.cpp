#include<iostream>
#include<queue>
using namespace std;

#define X first
#define Y second

// 0인 경우 북쪽, 1인 경우 동쪽, 2인 경우 남쪽, 3인 경우 서쪽
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int n, m;
int room[51][51];
bool isvis[51][51];

bool isClean(int x, int y) {
	bool isc = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 바깥인 경우
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		// 벽이거나 이미 청소한 곳이면
		if (!room[nx][ny] && !isvis[nx][ny]) {
			isc = false;
			break;
		}
	}
	return isc;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int r, c, dir;
	
	cin >> r >> c >> dir;

	queue<pair<int, int>> q;

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			cin >> room[i][j];

	q.push({ r,c });
	int result = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (!room[cur.X][cur.Y] && !isvis[cur.X][cur.Y]) {
			isvis[cur.X][cur.Y] = true;
			result++;
		}
		bool isc = isClean(cur.X, cur.Y);
		// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
		if (isc) {
			int d = (dir + 2) % 4;
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];

			// 방 바깥이거나, 벽인 경우
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || room[nx][ny])
				break;

			q.push({ nx,ny });
		}
		else {
			for (int i = 3; i >= 0; i--) {
				int d = (dir + i) % 4;

				int nx = cur.X + dx[d];
				int ny = cur.Y + dy[d];

				// 방 바깥이거나, 벽인 경우
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || room[nx][ny])
					continue;
				// 이미 청소한 곳인 경우
				if (isvis[nx][ny])
					continue;

				dir = d;
				q.push({ nx,ny });
				break;
			}
		}
	}

	cout << result;

	return 0;
}