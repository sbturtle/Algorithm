#include <iostream>
using namespace std;

int arr[200001];
int isVis[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int st = 0, ed = 0;
	int result = 0;
	while (ed < n) {
		if (isVis[arr[ed]] != k) {
			isVis[arr[ed]]++;
			ed++;

			result = max(result, ed - st);
		}
		else {
			isVis[arr[st++]]--;
		}
	}

	cout << result;
	return 0;
}