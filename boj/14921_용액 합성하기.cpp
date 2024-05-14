#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int result = 200000001;
	int st = 0;
	int ed = n - 1;
	while (st != ed)
	{
		int sum = arr[st] + arr[ed];
		if (abs(result) > abs(sum))
		{
			result = sum;
			continue;
		}
		if (sum == 0)
			break;
		else if (sum < 0)
			st++;
		else
			ed--;

	}

	cout << result;
	return 0;
}