#include <iostream>
#include <cmath>
using namespace std;

int m, n;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	// 에라토스테네스의 체
	// 참고 https://donggoolosori.github.io/2020/10/16/eratos/
	// 최대 범위 수의 제곱근까지의 값들의 배수를 제외하면
	// 남은 수들은 소수

	for (int i = 2; i <= n; i++)
		arr[i] = i;

	// 2부터 최대 값의 제곱근까지
	for (int i = 2; i <= sqrt(n); i++)
	{
		// 0이면 이미 소수가 아님
		if (!arr[i])	continue;

		// 배수들을 제외.
		for (int j = i * i; j <= n; j += i)
			arr[j] = 0;
	}

	for (int i = m; i <= n; i++)
	{
		// 0이면 소수가 아님
		if (!arr[i])	continue;

		cout << arr[i] << '\n';
	}
	return 0;
}