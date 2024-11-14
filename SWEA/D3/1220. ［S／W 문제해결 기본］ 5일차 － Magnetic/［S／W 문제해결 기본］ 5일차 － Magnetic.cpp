#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	//freopen("input.txt", "r", stdin);

    // 1은 N극, 2는 S극
    // 테이블의 윗부분에 N극, 아래부분에 S극
    int mp[101][101];
	for(test_case = 1; test_case <= T; ++test_case)
	{
        stack<int> st[101];
		int n; cin >> n;
        int result = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                cin >> mp[i][j];
        
         for(int j = 0; j < n; j++) {
            int sum = 0;
            bool isn = false;
            for(int i = 0; i < n; i++) {
                if(mp[i][j] == 1) 
                    isn = true;
                else if(mp[i][j] == 2 && isn) {
                    isn = false;
                    sum++;
                }
            }               
            result += sum;
        }
	
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}