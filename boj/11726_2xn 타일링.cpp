#include <iostream>
using namespace std;

int arr[1001];


int main() {

	int n;
	cin >> n;
	// 초기식
	arr[1] = 1;
	arr[2] = 2;

	// 점화식
	for (int i = 3; i <= n; i++)
	{
		// 왼쪽 위(0,0)를 기준으로
		// 움직일 수 있는건 수평 또는 수직

		// arr[i-1]은 수직으로 0,-1 좌표로 연결하는 블럭을 두었을 때
		// 전체 크기를 기준으로는 -1 만큼 줄은 상태임으로
		// arr[i-2]는 수평으로 1,0 좌표로 연결하는 블록을 두었을 때
		// 그 밑에 (0,-1) (1,-1)에 블록을 두게 되면 
		// 전체 크기를 기준으로는 -2 만큼 줄은 상태임으로
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	cout << arr[n];
	return 0;
}