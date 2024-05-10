#include <iostream>
using namespace std;

// 0~n까지의 숫자들의 최솟값을 저장
int arr[1000004];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	// 초기식
	arr[1] = 0;
	// 점화식
	// 2부터 n까지의 숫자들의 최솟값을 구해
	// n의 최솟값을 출력

	// 각 연산을 하면 1회씩 증가하게 되는 성질을 이용
	// 연산을 하고 난 후 이전의 수를 마주치게 될테니 해당 수의 +1을 하면
	// 연산한 수의 최솟값이 되게 됨.
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);

		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	cout << arr[n];

	return 0;
}