#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

string map[601];
bool isvis[601][601];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	queue<pair<int, int>> q;



	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
		int isI = map[i].find('I');
		if (isI != -1) {
			q.push({ i,isI });
			isvis[i][isI] = true;
		}
	}

	int friends = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + cur.first;
			int ny = dy[i] + cur.second;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] == 'X' || isvis[nx][ny])
				continue;

			if (map[nx][ny] == 'P')
				friends++;

			isvis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	if (friends == 0)
		cout << "TT";
	else
		cout << friends;

	return 0;
}