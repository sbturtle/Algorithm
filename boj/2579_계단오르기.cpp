#include <iostream>
using namespace std;

// 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
// 라는 조건때문에 2차원 배열로 정의
int arr[304][3];
int score[304];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}
	// 초기식
	// 한계단 전, 두 계단 전의 값을 알고 있어야 함으로
	// 두 계단 전의 처음 경우, 연속 경우 모두 정의
	arr[1][1] = score[1];
	arr[1][2] = 0;			// 원래 0이지만, 익숙해질 때까지만 정의
	arr[2][1] = score[2];
	arr[2][2] = score[1] + score[2];

	// 점화식
	for (int i = 3; i <= n; i++)
	{
		// 처음 밟은 경우
		// 두 계단을 올라온 것으로 
		// 두 칸전의 1회, 2회 연속의 값 중 큰 값
		// + 해당 계단의 값을 더함.
		arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + score[i];
		// 연속해서 밟은 경우
		// 한 계단을 올라온 것으로 
		// 한 칸 전의 처음 밟은 값 + 해당 계단의 값을 더함
		arr[i][2] = arr[i - 1][1] + score[i];
	}

	cout << max(arr[n][1], arr[n][2]);

	return 0;
}