#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	// unique �Լ��� �ߺ����� �ʴ� ���ҵ��� �տ������� ä�� ��
	// ���� �޺κ��� �״�� �ڿ� ����
	// �ߺ����� ���� ���Ұ� ���� ���� ������ ���ͷ����͸� ��ȯ
	
	// ���ĵǾ��־�߸� ��� ����
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int num : vec)
		cout << num << ' ';

	return 0;
}