// �׸��� �˰���
#include <iostream>
using namespace std;
#define LL long long 
int d[6];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL n;
	cin >> n;

	for (int i = 0; i < 6; i++)
		cin >> d[i];

	LL af = min(d[0], d[5]);
	LL be = min(d[1], d[4]);
	LL cd = min(d[2], d[3]);

	LL m3 = af + be + cd;
	LL m2 = m3 - max(max(af, be), cd);
	LL m1 = min(min(af, be), cd);

	LL result = 0;
	if (n == 1) {
		int max = 0;
		for (int i : d) {
			result += i;
			if (max < i) max = i;
		}
		result -= max;
	}
	else {
		result += m3 * 4;	// ����
		result += /* �� �Ѳ� */m2 * (n - 2) * 4 + /* ��� */m2 * (n - 1) * 4;
		result += m1 * (n - 2) * (n - 2) * 5;	// �߾�
		result += m1 * (n - 2) * 4;		// ������ �ٴ�
	}

	cout << result;
	return 0;
}