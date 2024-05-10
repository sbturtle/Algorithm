//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//#define X first
//#define Y second
//
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//int map[1002][1002];
//int vis[1002][1002];
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//
//	// �湮 ������ ���
//	vector<pair<int, int>> vec;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> map[i][j];
//
//			// �ܰ��� ���
//			if (i == 1 || m == 1 || i == n || j == m) {
//				vec.push_back({ i,j });
//			}
//		}
//	}
//
//	int k;		// ��Ȯ�ؾ��ϴ� Ƚ��
//	cin >> k;
//
//	queue<pair<int, int>> q;
//	queue<pair<int, int>> result;
//
//	while (k--) {
//		int max = 0;
//		for (auto cur : vec)
//		{
//			if (max < map[cur.X][cur.Y] && !vis[cur.X][cur.Y]) {
//				max = map[cur.X][cur.Y];
//				if (!q.empty()) q.pop();
//				q.push(cur);
//			}
//		}
//		// ���� ��ġ ���� ������ ��ġ
//		auto cur = q.front(); q.pop();
//		vec.erase(remove(vec.begin(), vec.end(), cur), vec.end());
//
//		vis[cur.X][cur.Y] = 1;
//		result.push(cur);
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = cur.X + dx[i];
//			int ny = cur.Y + dy[i];
//			// �ܰ��̰ų�, ���� �ٱ��� ���
//			if (nx < 2 || ny < 2 || nx > n - 1 || ny > m - 1)
//				continue;
//			// �̹� �湮�� ����� ���
//			if (vis[nx][ny])
//				continue;
//			vec.push_back({ nx,ny });
//		}
//	}
//
//	// ���
//	while (!result.empty()) {
//		auto cur = result.front(); result.pop();
//
//		cout << cur.X << ' ' << cur.Y << '\n';
//	}
//
//	return 0;
//}