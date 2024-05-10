#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	// unique 함수는 중복되지 않는 원소들을 앞에서부터 채워 줌
	// 남은 뒷부분은 그대로 뒤에 존재
	// 중복되지 않은 원소가 끝난 다음 지점의 이터레이터를 반환
	
	// 정렬되어있어야만 사용 가능
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int num : vec)
		cout << num << ' ';

	return 0;
}