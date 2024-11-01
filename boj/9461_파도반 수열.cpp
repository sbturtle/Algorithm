#include <iostream>
using namespace std;

// 최대 값이 888,855,064,897이기에 int 범위를 벗어남
long long tr[101];
// DP로 해결
// 점화식은 tr[i] = tr[i - 2] + tr[i - 3];
// 따라서 초기식을 0부터 2까지 세팅함
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	tr[0] = 0;
	tr[1] = 1;
	tr[2] = 1;

	for (int i = 3; i <= 100; i++)	{
		tr[i] = tr[i - 2] + tr[i - 3];
	}


	while (T--) {
		int n; cin >> n;
		cout << tr[n] << '\n';	
	}

	return 0;
}
