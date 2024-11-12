#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

// c는 가로, r은 세로
int c, r, k;
vector<vector<bool>> isvis;
pair<int, int> result = { -1,-1 };

int map[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> r >> k;
	isvis = vector<vector<bool>>(r + 1, vector<bool>(c + 1, false));

	if (c * r < k) {
		cout << 0;
		return 0;
	}

	stack<pair<int, int>> st;
	st.push({ 0,0 });
	isvis[0][0] = true;
	map[0][0] = 1;
	int cnt = 1;

	int i = 0;

	while (!st.empty()) {
		auto cur = st.top(); st.pop();
		if (cnt == k) {
			result = cur;
			break;
		}
		int d = 0;
		while (st.empty()) {
			if (d > 4)				break;

			i %= 4;
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				i++; d++;
				continue;
			}

			if (isvis[nx][ny]) {
				i++; d++;
				continue;
			}

			isvis[nx][ny] = true;
			st.push({ nx,ny });
			cnt++;
			map[nx][ny] = cnt;
		}
	}

	cout << result.second + 1 << ' ' << result.first + 1;

	return 0;
}