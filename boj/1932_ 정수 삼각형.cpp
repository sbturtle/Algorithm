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
			// �ʱ��
			// i+1�� ���� ����������, �ʱⰪ�� �ﰢ���� �� ���� ����
			// i�� n �� ���� ������ ����
			if (i == n) {
				route[i][j] = map[i][j];
			}
		}

	// ��ȭ��
	// top to bottom���� �����ϸ� n���� ��� �� �ִ밪�� ã�ƾ� ��
	// bottom to top���� �����ϸ� ����� ������ ��� 1���� ������ ��
	// bottom to top�� ä��
	// 
	// map[i][j]�� ���� map[i+1]�� ���� �� 
	// �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ֱ⿡
	// [i+1][j] �Ǵ� [i+1][j+1]�� ������ �� ����
	// ���� �ش� �� �� �ִ밪�� ���ϸ� [1][1]���� �ö󰡸�,
	// �ִ밪�� ���� �� ����

	for (int i = n - 1; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			route[i][j] = max(route[i + 1][j + 1], route[i + 1][j]) + map[i][j];
		}
	}
	
	cout << route[1][1];
	return 0;
}
