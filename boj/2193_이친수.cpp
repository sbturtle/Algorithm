#include <iostream>

// 5씩 점차 증가시켜 실행하다 보면 
// 대략 49에서 int의 범위를 벗어나게 됨
long long pn[91][2];

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;

	// 초기식
	pn[1][0] = 0;	// 0으로 시작하지 않음
	pn[1][1] = 1;
	
	// 점화식
	// i번째가 0일 경우 이전의 값이 0 또는 1이여도 됨
	// i번째가 1일 경우 이전에는 0이어야 함
	for (int i = 2; i <= n; i++)
	{
		pn[i][0] = pn[i-1][0] + pn[i-1][1];
		pn[i][1] = pn[i-1][0];
	}
	long long result = pn[n][0] + pn[n][1];

	std::cout << result;
	return 0;
}