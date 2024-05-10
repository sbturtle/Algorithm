#include <iostream>
using namespace std;

int tile[1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	// 초기식
	tile[1] = 1;
	tile[2] = 3;

	// 점화식
	for (int i = 3; i <= n; i++)
	{
		// 1×2, 2×1과 2×2 타일로 채우는 방법
		//	   2×1			   1×2			   2×2
		//	tile[i - 1] +	tile[i - 2]	+	tile[i - 2] 
		tile[i] = (tile[i - 1] + tile[i - 2] + tile[i - 2]) % 10007;
	}
	cout << tile[n];
	return 0;
}