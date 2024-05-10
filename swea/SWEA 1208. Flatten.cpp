#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    T = 10;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int d;
        cin >> d;
        vector<int> vec;

        int t = 100;
        while(t--){
            int temp; cin >> temp;
            vec.push_back(temp);
        }

        sort(vec.begin(), vec.end());
        int result = abs(vec.front() - vec.back());

        while (d--) {
            if (result == 0 || result == 1) break;
            vec.back()--; vec.front()++;

            // 재정렬 (오름차순)
            for (int i = 0; i < 99; i++) {
                if (vec[i] < vec[i + 1])	break;
                swap(vec[i], vec[i + 1]);
            }
            // 재정렬 (내림차순)
            for (int i = 99; i >= 0; i--) {
                if (vec[i] > vec[i - 1])	break;
                swap(vec[i], vec[i - 1]);
            }
            result = abs(vec.front() - vec.back());
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}