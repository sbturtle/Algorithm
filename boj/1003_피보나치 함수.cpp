#include <iostream>
using namespace std;

int arr[41][2];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	// 초기식
	// 점화식이 n-2까지의 수가 필요하기 때문에
	// 1까지 초기식을 정의
	arr[0][0] = 1;
	arr[0][1] = 0;	// 0으로 초기화 되지만, 이해하기 쉽게 작성
	arr[1][0] = 0;
	arr[1][1] = 1;

	// 점화식
	// 피보나치 재귀함수의 마지막 구문을 보면
	// return fibonacci(n‐1) + fibonacci(n‐2);
	// 동일하게 n-1의 0과1의 값과 n-2의 0가 1의 값을 구하면 됨
	for (int i = 2; i <= 40; i++)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}

	while (t--) {
		int n;
		cin >> n;
		cout << arr[n][0] << ' ' << arr[n][1] << '\n';
	}
	return 0;
}