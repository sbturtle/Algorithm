#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char arr[16];
bool isVis[16];

bool isCheck() {
	int j = 0, m = 0;
	for (int i = 0; i < c; i++)
	{
		if (isVis[i]) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				m++;
			else
				j++;
		}		
	}

	if (j > 1 && m > 0)
		return true;
	else
		return false;

}
void func(int start, int count) {
	if (count == l && isCheck()) {
		for (int i = 0; i < c; i++)
		{
			if (isVis[i]) {
				cout << arr[i];
			}
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < c; i++)
	{
		isVis[i] = true;
		func(i + 1, count + 1);
		isVis[i] = false;
	}
}

// 최소 한 개의 모음(a, e, i, o, u)과 
// 최소 두 개의 자음으로 구성되어 있다
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;

	for (int i = 0; i < c; i++)
		cin >> arr[i];

	sort(arr, arr + c);

	func(0, 0);

	return 0;
}