#include <iostream>
#include <algorithm>
using namespace std;

int l[100004];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];

	sort(l, l + n);

	int result = 0;
	// i는 루프의 사용 개수
	for (int i = 1; i <= n; i++)
	{
		result = max(result, l[n - i] * i);
	}

	cout << result;
	return 0;
}