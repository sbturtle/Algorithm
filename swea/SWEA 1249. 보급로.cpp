#include<iostream>
#include<queue>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

string map[101];
int isVis[101][101];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;	cin >> n;
		for (int i = 0; i < n; i++)
			fill(isVis[i], isVis[i] + n, -1);

		for (int i = 0; i < n; i++)
			cin >> map[i];

		// BFS로 넓이 우선 탐색 시작
		queue<pair<int, int>> Q;
		isVis[0][0] = map[0][0] - '0';
		Q.push({ 0,0 });

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + cur.X;
				int ny = dy[i] + cur.Y;

				if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;

				// 만약, 기존에 탐색한 장소라면,
				if (isVis[nx][ny] != -1) {
					// 기존 탐색 시간보다 현재 탐색 시간이 더 작다면
					if (isVis[nx][ny] > isVis[cur.X][cur.Y] + (map[nx][ny] - '0'))
					{
						isVis[nx][ny] = isVis[cur.X][cur.Y] + (map[nx][ny] - '0');
						Q.push({ nx,ny });
					}
					continue;
				}

				// 이전의 탐색 시간 + 현재의 탐색 시간
				isVis[nx][ny] = isVis[cur.X][cur.Y] + (map[nx][ny] - '0');
				Q.push({ nx,ny });
			}
		}

		cout << '#' << test_case << ' ' << isVis[n - 1][n - 1] << '\n';
	}
	return 0;
}