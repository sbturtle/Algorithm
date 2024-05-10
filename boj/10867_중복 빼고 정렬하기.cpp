// 오름차순으로 정렬한 결과에 같은 수는 1회만 출력하는 문제
// n개의 정수를 담은 배열을 만들어 정렬 후 같은 수는 1회 출력하는 식으로 생각하다,
// 수의 범위도 2000 정도이고, 1회 출력이면 카운팅 정렬을 사용하는 편이 더
// 좋아보여 해당 방식으로 코딩 진행
// 절대값의 범위이기에 1000을 더해 주고 빼는 방식을 채택함

#include <iostream>
#include <algorithm>
using namespace std;

bool a[2001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num += 1000;
		a[num] = true;
	}

	for (int i = 0; i < 2001; i++)
	{
		if (a[i]) {
			cout << i - 1000 << ' ';
		}
	}

	return 0;
}