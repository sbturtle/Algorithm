#include <iostream>
using namespace std;

int wine[10001];
int map[10001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> wine[i];

	// 초기식
	// 처음을 선택하지 않을 수도 있기 때문에 1번째 선택하는 경우
	// 2번째를 처음 선택하는 경우 까지 고려해서 초기식 작성이 필요할 듯
	map[0][1] = wine[0];	// 1번째를 처음 선택하는 경우
	map[1][2] = map[1 - 1][1] + wine[1];

	map[1][1] = wine[1];	// 2번째를 처음 선택하는 경우
	// 선택하지 않았을 경우 직전의 최대값을 갖게 됨
	map[1][0] = max(map[1 - 1][1], map[1 - 1][2]);

	int result = max(max(map[0][1], map[1][1]), map[1][2]);
	// 점화식
	// map[i][0] = max(map[i-2][0],map[i-2][1]) + wine[i]
	// map[i][1] = map[i-1][0] + wine[i]
	for (int i = 2; i < n; i++)
	{
		// i 번째를 선택하지 않았을 경우 직전의 최대값을 갖게 됨
		map[i][0] = max(map[i - 1][0], max(map[i - 1][1], map[i - 1][2]));

		// i 번째가 1회 연속일 경우 2칸 전의 1회 또는 2회 연속 중 최대값(선택하지 않았을 경우의 최대값)을 더함
		map[i][1] = map[i - 1][0] + wine[i];
		// i 번째가 2회 연속일 경우 직전 값을 더함
		map[i][2] = map[i - 1][1] + wine[i];

		int tmp = max(map[i][1], map[i][2]);
		if (result < tmp)
			result = tmp;
	}

	cout << result;

	return 0;
}