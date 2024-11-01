#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c;

int dx[] = { 0, 0, 1, 1 };
int dy[] = { 0, 1, 0, 1 };

long long result = 0;

void func(size_t x, size_t y, int s) {
	if (x == r && y == c) {
		cout << result;
		return;

	}

	if (x <= r && r < x + s && y <= c && c < y + s) {
		for (size_t i = 0; i < 4; i++)
		{
			int ts = s / 2;
			int nx = x + (dx[i] * ts);
			int ny = y + (dy[i] * ts);

			func(nx, ny, ts);
		}
	}
	else {
		result += (long long)s * s;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c;
	int s = (int)pow(2, n);

	func(0, 0, s);
	return 0;
}