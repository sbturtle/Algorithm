#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int result = 0;
        string bit;
        cin >> bit;
        char isBool = '0';
        for (int i = 0; i < bit.length(); i++) {
            if (bit[i] == isBool)
                continue;
            
            isBool = (isBool == '0' ? '1' : '0');
            result++;
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}