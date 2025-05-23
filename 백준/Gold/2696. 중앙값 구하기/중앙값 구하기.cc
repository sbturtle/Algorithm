#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using  namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;
        priority_queue<int> max_heap;       // 작은 값들이 위로 (최대 힙)
        priority_queue<int, vector<int>, greater<int>> min_heap; // 큰 값들이 위로 (최소 힙)
        vector<int> medians;

        for (int i = 0; i < M; ++i) {
            int num;
            cin >> num;

            if (max_heap.empty() || num <= max_heap.top()) {
                max_heap.push(num);
            }
            else {
                min_heap.push(num);
            }

            // 힙 크기 균형 맞추기
            if (max_heap.size() > min_heap.size() + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else if (min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }

            if ((i + 1) % 2 != 0) {
                medians.push_back(max_heap.top());
            }
        }

        cout << medians.size() << '\n';
        for (int i = 0; i < medians.size(); ++i) {
            cout << medians[i] << (i == medians.size() - 1 || (i + 1) % 10 == 0 ? '\n' : ' ');
        }
    }
    return 0;
}