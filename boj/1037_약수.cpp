#include <iostream>
#include <algorithm>
// #include <vector>
using namespace std;

// 약수의 최소값과 최대값을 서로 곱하면 원하는 수가 나옴

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