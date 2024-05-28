#include <iostream>
using namespace std;
bool map[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 0; t < 4; t++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				map[i][j] = true;
	}

	int result = 0;

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (map[i][j]) result++;


	cout << result;
	return 0;
}