#include <iostream>
#include <vector>
using namespace std;

bool isVis[4000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec;
	for (int i = 2; i <= 2000; i++)
		if (!isVis[i]) {
			for (int j = i * i; j <= 4000000; j += i) {
				isVis[j] = true;
			}
		}
	for (int i = 2; i < 4000000; i++)
	{
		if (!isVis[i])
			vec.push_back(i);
	}

	int size = vec.size();

	int n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (vec[i] > n)
			break;
		int sum = 0;
		for (int j = i; j < size; j++)
		{
			sum += vec[j];
			if (sum == n) {
				result++;
				break;
			}
			if (sum > n) break;
		}
	}

	cout << result;

	return 0;
}