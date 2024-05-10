#include <iostream>
using namespace std;

// 0~n까지의 숫자들의 최솟값을 저장
int arr[1000004];
int route[1000004];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	// 초기식
	arr[1] = 0;
	route[1] = 0;
	// 점화식
	// 최적의 최소값을 구할 경우 해당 연산의 결과 값을 저장
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		route[i] = i - 1;
		if (i % 2 == 0) {
			int c = arr[i / 2] + 1;
			if (c < arr[i]) {
				arr[i] = c;
				route[i] = i / 2;
			}		}

		if (i % 3 == 0) {
			int c = arr[i / 3] + 1;
			if (c < arr[i]) {
				arr[i] = c;
				route[i] = i / 3;
			}
		}
	}

	cout << arr[n] << '\n';

	int i = n;
	while (i != 0) {
		cout << i << ' ';
		i = route[i];
	}

	return 0;
}