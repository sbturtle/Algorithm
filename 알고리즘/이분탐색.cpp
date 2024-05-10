#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 10;
// ´ÜÀÏ Å½»ö
// vector<int> vec = { 5,12,17,32,1,8,15,9,35,4 };

// º¹¼ö Å½»ö
vector<int> vec = { 16,4,32,10,16,6,10,30,16,2 };

bool binarySearch(int tg) {
	int st = 0;
	int ed = n - 1;
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		if (vec[mid] == tg)
			return true;
		else if (vec[mid] < tg)
			st = mid + 1;
		else if (vec[mid] > tg)
			ed = mid - 1;
	}
	return false;
}

int lower_idx(int tg, int len) {
	int st = 0;
	int ed = len;

	while (st < ed) {
		int mid = (st + ed) / 2;
		if (vec[mid] >= tg) ed = mid;
		else st = mid + 1;
	}
	return st;
}

int upper_idx(int tg, int len) {
	int st = 0;
	int ed = len;

	while (st < ed) {
		int mid = (st + ed) / 2;
		if (vec[mid] > tg) ed = mid;
		else st = mid + 1;
	}
	return st;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());

	int tg;
	cin >> tg;

	//cout << "Yame : " << binarySearch(tg) << '\n';
	// #include <algorithm> STL Function
	//cout << "STL : " << binary_search(vec.begin(), vec.end(), tg) << '\n';

	cout << upper_idx(tg, n) - lower_idx(tg, n);
	cout << upper_bound(vec.begin(), vec.end(), tg) - lower_bound(vec.begin(), vec.end(), tg);
	return 0;
}