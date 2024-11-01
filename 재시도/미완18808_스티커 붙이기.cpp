#include <iostream>
using namespace std;

#define X first
#define Y second

int map[41][41];
pair<int, int> s[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		s[i] = { x,y };
	}
	// 스티커 붙이기
	for (int i = 0; i < k; i++)
	{

	}
}