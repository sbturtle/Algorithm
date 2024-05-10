#include <iostream>
using namespace std;
int map[101][101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int result = 0;
	// 가로줄 검사
	for (int i = 0; i < n; i++)
	{
		bool isAll = true;
		for (int j = 1; j < n; j++)
		{
			// 모두 같은지
			if (map[i][j] == map[i][j - 1]) continue;

			isAll = false;

			// 두 수의 차이가 2이상 나게 되면 무조건 불가능
			if (abs(map[i][j] - map[i][j - 1]) > 1)
				break;


			// 다를 경우 어디가 큰 수인지,
			// 어디가 작고 길이가 어느정도인지

			// 지나간 값이 더 큰 경우
			if (map[i][j] < map[i][j - 1]) {
				for (int k = 1; k < l; k++) {
					int idx = j + k;
					if (idx >= n || map[i][idx - 1] != map[i][idx])					
						goto ASD;					
				}

				// 경사로를 만들었을 경우
				j += l - 1;
				continue;
			}

			// 지나간 값이 더 작은 경우
			if (map[i][j] > map[i][j - 1]) {
				for (int k = 1; k <= l; k++) {
					int idx = j - k;
					if (idx < 0 || map[i][idx]!= map[i][idx - 1])
						goto ASD;
				}

				// 경사로를 만들었을 경우
				j += l - 1;
				continue;
			}
		}

	ASD:
		if (isAll)
			result++;
	}

	return 0;
}