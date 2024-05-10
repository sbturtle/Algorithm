#include <iostream>
#include <cmath>
using namespace std;

// 좌표로 생각하자
// 앞뒤가 바뀌었을때의 값을 더해서 비슷한 값을 찾아
// 냅다 반반으로 나누고 해당 값을 반환하는데, 그 값끼리의 뺀 값의
// 절대값이 최소인 경우를 구해? 10! 아냐? -> 시간 초과
// 
// 중복 되는 경우가 있음
// ex) 12 34 -> 34 12
// 절대값으로 비교하기에 의미가 없음
// 따라서 인원 수가 n개일 때까지 말고 n/2일 때까지만 하자.
// 또한, 동일한 이유로 팀을 구성할 때에도 방문의 중복값을 줄이기 위해 start 변수 추가
// ex) 1111

int n;
int v[21][21];
bool isUsed[21];
int result = 1000000;

void func(int start, int k) {
	if (k == n / 2) {
		int st = 0;
		int li = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				// 방문한 팀
				if (isUsed[i] && isUsed[j])
					st += v[i][j];
				// 방문하지 않은 팀
				else if (!isUsed[i] && !isUsed[j])
					li += v[i][j];
			}

		if (result > abs(st - li))
			result = abs(st - li);
		return;
	}

	// 팀 구성 
	for (int i = start; i < n; i++)
	{
		if (!isUsed[i]) {
			isUsed[i] = true;
			func(i + 1, k + 1);
			isUsed[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	func(0, 0);

	cout << result;
	return 0;
}