#include <iostream>
#include <queue>
using namespace std;

int trucks[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, l;		// n은 트럭의 수, w는 다리의 길이,
	cin >> n >> w >> l;	// l은 다리의 최대하중

	int timer = 0;

	for (int i = 1; i <= n; i++)
		cin >> trucks[i];

	int nowL = l;
	queue<int> rT;
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			if (rT.size() >= w)
			{
				nowL += rT.front();
				rT.pop();
			}
			if (trucks[i] <= nowL) break;

			rT.push(0);
			timer++;

		}
		rT.push(trucks[i]);
		nowL -= trucks[i];
		timer++;

	}

	cout << timer + w;
	return 0;
}