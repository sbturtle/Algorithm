#include <iostream>

// 5�� ���� �������� �����ϴ� ���� 
// �뷫 49���� int�� ������ ����� ��
long long pn[91][2];

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;

	// �ʱ��
	pn[1][0] = 0;	// 0���� �������� ����
	pn[1][1] = 1;
	
	// ��ȭ��
	// i��°�� 0�� ��� ������ ���� 0 �Ǵ� 1�̿��� ��
	// i��°�� 1�� ��� �������� 0�̾�� ��
	for (int i = 2; i <= n; i++)
	{
		pn[i][0] = pn[i-1][0] + pn[i-1][1];
		pn[i][1] = pn[i-1][0];
	}
	long long result = pn[n][0] + pn[n][1];

	std::cout << result;
	return 0;
}