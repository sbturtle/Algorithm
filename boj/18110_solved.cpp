#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	vec = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());
	int avg = (int)round((n * (.3)) / 2);
	int top = avg, btm = n - avg;

	int sum = 0;
	int m = 0;
	for (int i = top; i < btm; i++)	{
		sum += vec[i];
		m++;
	}
	
	cout << round((float)sum / m);

	return 0;
}