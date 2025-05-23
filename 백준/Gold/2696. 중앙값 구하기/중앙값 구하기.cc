#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int M;
		cin >> M;
		vector<int> numbers;
		vector<int> medians;
		for (int i = 0; i < M; ++i) {
			int num;
			cin >> num;
			numbers.push_back(num);
			if ((i + 1) % 2 != 0) {
				vector<int> temp = numbers;
				sort(temp.begin(), temp.end());
				medians.push_back(temp[temp.size() / 2]);
			}
		}

		cout << medians.size() << '\n';
		for (int i = 0; i < medians.size(); ++i) {
			cout << medians[i] << (i == medians.size() - 1 || (i + 1) % 10 == 0 ? '\n' : ' ');
		}
	}
	return 0;
}