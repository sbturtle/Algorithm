#include <iostream>
#include <algorithm>
// #include <vector>
using namespace std;

// ����� �ּҰ��� �ִ밪�� ���� ���ϸ� ���ϴ� ���� ����

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int max = 0;
	int min = 1000000000;
	// vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (max < num)			max = num;

		if (min > num)			min = num;

		// vec.push_back(num);
	}

	// max = *max_element(vec.begin(), vec.end());
	// min = *min_element(vec.begin(), vec.end());

	cout << max * min;


	return 0;
}