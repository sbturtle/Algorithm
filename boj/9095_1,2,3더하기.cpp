#include <iostream>
using namespace std;

// 1을 시작 인덱스로 사용하기 위해 최대 범위(11) + 1
int a[12];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 초기식
	// 1을 더하는 경우, 2를 더하는 경우, 3을 더하는 경우를 기본값으로 하기에
	// 3까지의 초기식을 정의해야 함

	// ex)	4의 경우
	// 1 + 1 + 1 + 1 / 1 + 2 + 1 /  2 + 1 + 1 / 3 + 1	3의 방법의 수 + 1
	// 1 + 1 + 2 / 2 + 2								2의 방법의 수 + 2
	// 1 + 3											1의 방법의 수 + 3

	a[1] = 1;
	a[2] = 2;
	a[3] = 4;

	for (int i = 4; i <= 11; i++) {
		//점화식
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << a[n] << '\n';
	}

	return 0;
}