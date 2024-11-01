#include <iostream>
using namespace std;

//	1	2
//	3	4

int dx[] = { -1,2,-1,2 };
int dy[] = { -1,-1,2,2 };

int n;
int map[129][129];

int b, w;			// ÆÄ¶õ»ö Ä­ ¼ö, ÇÏ¾á»ö Ä­ ¼ö

int check(int x, int y, int s) {
	int c = map[x][y];
	for (int i = x; i < x + s; i++)
		for (int j = y; j < y + s; j++)
			if (c != map[i][j])				return -1;

	return c;
}

void func(int x, int y, int s) {
	int r = check(x, y, s);

	if (r == -1) {
		for (int i = 0; i < 4; i++)
		{
			int nx = x + (s / dx[i]);
			int ny = y + (s / dy[i]);

			nx = nx < x ? x : nx;
			ny = ny < y ? y : ny;

			func(nx, ny, s / 2);
		}
	}
	else if (r == 1)	b++;
	else if (r == 0)	w++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	func(0, 0, n);

	cout << w << '\n' << b;
	return 0;
}