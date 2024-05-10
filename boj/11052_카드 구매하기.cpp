#include <iostream>
using namespace std;

int n;
int cards[1001];
int map[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> cards[i];

	// 백트래킹이 옳은 판단일까? n^n XXXXX

	map[1] = cards[1];
	map[2] = max(cards[2], map[1] * 2);

	for (int i = 3; i <= n; i++)
	{
		// i개가 들어있는 카드팩을 고른 경우
		int v = 0;

		// i보다 작은 수의 조합의 카드팩들을 고른 경우
		for (int j = 1; j <= i; j++) {
			for (int k = j; k <= i; k++) {
				if (j + k == i) {						// i는 현재 구하려는 최대금액에 매칭되는 카드의 개수
					int tmp = map[j] + map[k];
					v = max(tmp, v);
				}
			}
		}
		map[i] = v;
	}

	cout << map[n];

	return 0;
}
