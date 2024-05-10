#include <iostream>
#include <algorithm>
using namespace std;

int p[101][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, W;
	int n;
	cin >> H >> W >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i][0] >> p[i][1];


	int result = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{

			// 전체 다 돌아보면서 
			// 둘다 가로, 세로로 돌 수 있음.
			for (int x = 0; x < 2; x++)
			{
				for (int y = 0; y < 2; y++)
				{
					int w = p[i][x] + p[j][y];
					int h = max(p[i][(x + 1) % 2], p[j][(y + 1) % 2]);

					if (H >= h && W >= w) {
						int s1 = p[i][x] * p[i][(x + 1) % 2];
						int s2 = p[j][y] * p[j][(y + 1) % 2];
						result = max(result, s1 + s2);
						continue;
					}

					if (H >= w && W >= h) {
						int s1 = p[i][x] * p[i][(x + 1) % 2];
						int s2 = p[j][y] * p[j][(y + 1) % 2];
						result = max(result, s1 + s2);
					}

				}
			}


		}
	}

	std::cout << result;

	return 0;
}