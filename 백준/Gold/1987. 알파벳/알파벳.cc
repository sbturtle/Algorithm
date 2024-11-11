#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


bool alpha[30];
string map[21];
int isvis[21][21];

int r, c;
int result = 1;

void func(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			continue;
		int alphaIdx = map[nx][ny] - 'A';
		if (alpha[alphaIdx] || isvis[nx][ny] != 0)
			continue;

		alpha[alphaIdx] = true;
		isvis[nx][ny] = isvis[x][y] + 1;

		result = max(result, isvis[nx][ny]);

		func(nx, ny);

		alpha[alphaIdx] = false;
		isvis[nx][ny] =0;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> map[i];

	isvis[0][0] = 1;
	alpha[map[0][0] - 'A'] = true;

	func(0, 0);

	cout << result;

	return 0;
}