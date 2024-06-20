#include <iostream>
using namespace std;

int main() {
	int n;           // 돌의 개수
	int map[1000];    // 게임과정의 횟수

	cin >> n;

	map[0] = 0;
	map[1] = 1;
	map[2] = 2;

	for (int i = 3; i <= n; i++) {
		map[i] = min(map[i - 1] + 1, map[i - 3] + 1);
	}

	// 게임 과정 횟수의 홀짝에 따라 승패 결정
	if (map[n] % 2 == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}