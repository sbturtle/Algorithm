#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define DIR	first
#define DIS	second
#define PP			pair<int, int>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 0 <= h,v, sc <= 100
	int h, v;	cin >> h >> v;
	int sc;     cin >> sc;
	vector<PP> store;
	// 1은 북쪽, 2는 남쪽, 3은 서쪽, 4는 동쪽
	for (int i = 0; i < sc; i++)
	{
		int dir, dis;
		cin >> dir >> dis;

		store.push_back({ dir,dis });
	}

	int dir, dis;
	cin >> dir >> dis;
	int sum = 0;
	for (PP s : store) {
		if (dir == s.DIR) {
			sum += abs(dis - s.DIS);
			continue;
		}

		// 둘다 가로상에 존재할 때
		if (dir < 3 && s.DIR < 3) {
			sum += v;
			sum += min((dis + s.DIS), (h * 2) - (dis + s.DIS));
		}
		// 둘다 세로상에 존재할 때
		else if (dir > 2 && s.DIR > 2) {
			sum += h;
			sum += min((dis + s.DIS), (v * 2) - (dis + s.DIS));
		}
		else {
			if (dir == 1) {
				sum += s.DIS;
				sum += s.DIR == 3 ? dis : h - dis;
			}
			else if (dir == 2) {
				sum += v - s.DIS;
				sum += s.DIR == 3 ? dis : h - dis;
			}
			else if (dir == 3) {
				sum += s.DIS;
				sum += s.DIR == 1 ? dis : v - dis;
			}
			else if (dir == 4) {
				sum += h - s.DIS;
				sum += s.DIR == 1 ? dis : v - dis;
			}
		}
	}

	cout << sum;

	return 0;
}
