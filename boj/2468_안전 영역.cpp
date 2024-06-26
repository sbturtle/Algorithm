#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int graph[102][102];
int graph[102][102];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> Q;
	cin >> N;
	int h = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];

		}
	int count = 0;
	int c = -1;

	while (c != 0)
	{
		for (int i = 0; i < N; i++)	fill(graph[i], graph[i] + N, 0);
		int num = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (graph[i][j] <= h || graph[i][j] != 0) continue;
				graph[i][j] = 1;
				Q.push({ i,j });
				num++;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (graph[nx][ny] <= h || graph[nx][ny] != 0) continue;
						graph[nx][ny] = 1;

						Q.push({ nx,ny });
					}
				}		// while
			}		// for
		h++;
		c = num;
		if (count < num) count = num;
	}		// while
	cout << count;
}