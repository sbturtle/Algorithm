#include <iostream>
using namespace std;
int arr[100001];	// 가로수 위치	0번째 인덱스
int dis[100001];	// 사이 거리	1번째 인덱스 시작

// 유클리드 호제법 ? 최대 공약수 구하는 공식
int func(int a, int b) {
	if (!b) return a;
	return func(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0) {
			int tmp = arr[i] - arr[i - 1];
			dis[i] = tmp;
		}
	}

	int t = dis[1];
	for (int i = 2; i < n; i++)
	{
		t = func(t, dis[i]);
	}

	int result = 0;
	for (int d : dis) {
		result += d / t - 1;
	}
	cout << result;

	return 0;
}