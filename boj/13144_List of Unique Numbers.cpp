#include <iostream>
using namespace std;

int arr[100001];		// 수열
bool isVis[100001];		// 방문 여부
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	long long result = 0;
	int st = 0;
	int ed = 0;

	while (ed < n) {
		// 해당 수를 방문했는지 검사
		if (!isVis[arr[ed]]) {
			isVis[arr[ed]] = true;
			ed++;
			result += (long long)ed - st;
		}
		// 방문했다면 앞의 값을 제거
		else {
			isVis[arr[st++]] = false;
		}
	}
	cout << result;
	return 0;
}