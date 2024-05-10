#include <iostream>
using namespace std;
int r[1004];
int g[1004];
int b[1004];

// r로 칠한 경우, g로 칠한 경우, b로 칠한 경우를 모두 생각
// 따라서 1000개의 집의 3가지 경우 [1001][4]으로 생각(1을 시작 인덱스로 사용)
int arr[1001][4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> r[i] >> g[i] >> b[i];

	// 초기식
	// 이전의 색에 따라 점화식이 진행되기에 1번째 인덱스만 초기 정의
	arr[1][1] = r[1];
	arr[1][2] = g[1];
	arr[1][3] = b[1];

	// 점화식
	// 만약 i번째를 R로 칠하려면 i-1번째는 R이 아닌 다른 색으로 칠해야 함.
	// 다른 색 모두 동일.
	// 3가지의 경우를 모두 구현
	for (int i = 2; i <= n; i++)
	{
		arr[i][1] = min(arr[i - 1][2], arr[i - 1][3]) + r[i];
		arr[i][2] = min(arr[i - 1][1], arr[i - 1][3]) + g[i];
		arr[i][3] = min(arr[i - 1][1], arr[i - 1][2]) + b[i];
	}

	// 각 색깔의 값 중 최솟값 출력
	cout << min(arr[n][1], min(arr[n][2], arr[n][3]));

	return 0;
}