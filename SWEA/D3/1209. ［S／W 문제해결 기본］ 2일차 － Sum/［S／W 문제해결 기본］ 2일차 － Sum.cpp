#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	while(T--)
	{
       cin >> test_case;
        int map[100][100];
		int result = 0;
        int s[100] = {0,};
        int l = 0, r = 0;
        
        for(int i = 0; i < 100; i++) {
            int sum = 0;
        	for(int j = 0; j < 100; j++) {
            	int n;	cin >> n;
                map[i][j] = n;
                sum += n;		// 가로
                s[j] += n;		  // 세로
                if(i == j)                    
                    l += n;	// 좌상 우하 대각선
        	}            
            result = max(result, sum);	// 가로 검사
        }        
        result = max(result, l); 	// 좌상-우하 대각선 검사

        for(int i = 0; i < 100; i++) {
            r+= map[99-i][i];
            result = max(result, s[i]); // 세로 검사
        }
        result = max(result, r);	// 우상-좌하 대각선 검사
        
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}