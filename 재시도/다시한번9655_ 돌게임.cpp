#include <iostream>
using namespace std;

int main() {
	int n;           // ���� ����
	int map[1000];    // ���Ӱ����� Ƚ��

	cin >> n;

	map[0] = 0;
	map[1] = 1;
	map[2] = 2;

	for (int i = 3; i <= n; i++) {
		map[i] = min(map[i - 1] + 1, map[i - 3] + 1);
	}

	// ���� ���� Ƚ���� Ȧ¦�� ���� ���� ����
	if (map[n] % 2 == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}