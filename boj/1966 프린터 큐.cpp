#include <iostream>
#include <queue>
using namespace std;


// 중요도 숫자가 겹칠 수 있기 때문에 카운팅배열을 생성
// 큐에 인덱스 번호, 중요도를 담음
// 카운팅 배열의 최대값이 원하는 인덱스일때까지 무한 루프
// 원하는 인덱스일 경우 돌았던 횟수 반환 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int ip[10] = { 0, };
		int n, qt;
		queue<pair<int, int>> q;
		cin >> n >> qt;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			ip[x]++;
			q.push({ i,x });
		}

		int c = 1;
		while (true) {
			// 최고의 중요도 찾기
			int max = 0;
			for (int i = 9; i > 0; i--)
			{
				if (ip[i] != 0)
				{
					max = i;
					break;
				}
			}

			pair<int, int> temp = q.front(); q.pop();

			// 최고의 중요도라면
			if (temp.second == max) {
				// 최고 중요도 인쇄
				ip[max]--;

				// 인덱스 찾음.
				if (qt == temp.first)
					break;
				c++;
			}
			else {	// 아니라면 뒤로 넘김
				q.push(temp);
			}
		}
		cout << c << '\n';
	}

	return 0;
}