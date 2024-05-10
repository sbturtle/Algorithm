#include <iostream>
using namespace std;

int map[501][501];
int route[501][501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) {
			cin >> map[i][j];
			// 초기식
			// i+1의 값을 참조함으로, 초기값을 삼각형의 맨 밑의 값인
			// i가 n 일 때의 값들을 정의
			if (i == n) {
				route[i][j] = map[i][j];
			}
		}

	// 점화식
	// top to bottom으로 생각하면 n개의 결과 중 최대값을 찾아야 함
	// bottom to top으로 생각하면 결과는 최적의 경로 1개만 나오게 됨
	// bottom to top을 채택
	// 
	// map[i][j]의 값은 map[i+1]의 값들 중 
	// 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있기에
	// [i+1][j] 또는 [i+1][j+1]만 선택할 수 있음
	// 따라서 해당 값 중 최대값을 구하며 [1][1]까지 올라가면,
	// 최대값을 구할 수 있음

	for (int i = n - 1; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			route[i][j] = max(route[i + 1][j + 1], route[i + 1][j]) + map[i][j];
		}
	}
	
	cout << route[1][1];
	return 0;
}
