#include <iostream>
using namespace std;

int ap[15][15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1층 및 0호 라인 정리
	for (int i = 1; i <= 14; i++) {
		ap[0][i] = i;
		ap[i][1] = 1;
	}

	// 14층까지 정리
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			ap[i][j] = ap[i-1][j] + ap[i][j - 1];
		}
	}

	int t;		cin >> t;

	while (t--) {
		int k, n;	cin >> k >> n;

		cout << ap[k][n] << '\n';
	}

	return 0;
}