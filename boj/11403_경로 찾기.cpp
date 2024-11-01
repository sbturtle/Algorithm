#include <iostream>
using namespace std;

int n;

int map[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (map[i][j]) {
				
			}

		}
	}

	return 0;
}