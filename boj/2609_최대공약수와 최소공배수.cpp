#include <iostream>
using namespace std;

// ��Ŭ���� ȣ����
// a > b�� �� �ڿ��� a, b�� ���ؼ�
// a�� b�� ���� ������, �� a % b�� r�̶�� ���� ��, 
// a�� b�� �ִ������� b�� r�� �ִ������� ����.
// �� ������ ��� �ݺ��Ͽ� ������(r)�� 0�� �Ǿ��� ��,
// �� ���� ������ ��(b)�� a�� b�� �ִ������� �ȴ�.

// ���� https://velog.io/@shasha/C-%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C-%ED%98%B8%EC%A0%9C%EB%B2%95-%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98-%EA%B5%AC%ED%95%98%EA%B8%B0
// �ּҰ������ a * b / (�ִ�����)

// ��ͷ� ǥ��
int func(int mx, int mn) {
	if(mn == 0)
	return mx;

	return func(mn, mx % mn);
}

int main() {
	int n1, n2;

	cin >> n1 >> n2;
	int res = func(max(n1, n2), min(n1, n2));
	cout << res << '\n';
	cout << n1 * n2 / res;

	return 0;
}