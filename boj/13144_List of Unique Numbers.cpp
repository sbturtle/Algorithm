#include <iostream>
using namespace std;

int arr[100001];		// ����
bool isVis[100001];		// �湮 ����
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
		// �ش� ���� �湮�ߴ��� �˻�
		if (!isVis[arr[ed]]) {
			isVis[arr[ed]] = true;
			ed++;
			result += (long long)ed - st;
		}
		// �湮�ߴٸ� ���� ���� ����
		else {
			isVis[arr[st++]] = false;
		}
	}
	cout << result;
	return 0;
}