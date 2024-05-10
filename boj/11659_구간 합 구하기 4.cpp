#include <iostream>
using namespace std;

int s[100001];
int r[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];

	// 초기식
	r[1] = s[1];

	// 점화식
	// 각 구간별 총합 값을 미리 구해놓고 
	// i부터 j까지의 수를 (i까지의 총합) - (j-1까지의 총합) j값은 포함되어야 함
	// 으로 연산하여 구함
	for (int i = 2; i <= n; i++)
	{
		r[i] = r[i - 1] + s[i];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		int result = r[j] - r[i - 1];
		cout << result << '\n';
	}

	return 0;
}