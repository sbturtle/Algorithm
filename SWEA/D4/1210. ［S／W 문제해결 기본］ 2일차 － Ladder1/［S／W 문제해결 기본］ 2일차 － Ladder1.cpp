#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define VB vector<bool>

// 역으로 도착지인 2에서부터 출발하여 시작지점을 찾으려 함

// 사다리게임에서는 수평이동이 수직이동보다 우선순위를 갖기 때문에,
// dy의 값을 우선으로 찾고, 수직이동은 단반향이기에 위로 올라가는 것만 체크

// 전체 탐색을 할 필요 없이, 단 하나의 길만 찾으면 되기에 DFS 깊이 우선 탐색을 진행함

int dx[] = {0, 0, -1};
int dy[] = {1, -1, 0};

int map[101][101];
vector<VB> isvis(101, VB(101, false));
int result = -1;

int func(int x, int y) {
     if(x == 0) {
         return y;
     }

    for(int i = 0; i < 3; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if(nx < 0 || ny < 0 || ny > 100)
            continue;
        if(map[nx][ny] == 0 || isvis[nx][ny])
            continue;

        isvis[nx][ny] = true;
        return func(nx, ny);
    }
    
    return -1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	// cin>>T;
    T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int testNum;	cin >> testNum;
        int result = -1;
        for(int i = 0; i < 100; i++)
            fill(isvis[i].begin(), isvis[i].end(), false);        
    
		pair<int, int> ed;
        
        for(int i = 0; i < 100; i++) {
        	for(int j = 0; j < 100; j++) {
            	cin >> map[i][j];
                if(map[i][j] == 2) {
                    ed = { i, j };
                    isvis[i][j] = true;
                }
            }
        }
        result = func(ed.first, ed.second);
        
		cout << '#' << testNum << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}