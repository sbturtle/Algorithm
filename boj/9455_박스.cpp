#include <iostream>
#include <vector>
using namespace std;
#define y first
#define x second

int arr[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int m, n;
		cin >> m >> n;
		vector<pair<int, int>> vec;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					vec.push_back({ i,j });
			}
		}

		int result = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			auto cur = vec[i];
			for (int j = cur.y + 1; j < m; j++)
			{
				if (arr[j][cur.x] == 0)
					result++;
			}
		}
		cout << result << '\n';
	}
	return 0;
}